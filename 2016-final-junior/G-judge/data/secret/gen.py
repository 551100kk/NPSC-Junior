import re
import string

import itertools
from itertools import product
import subprocess
import os

import random
from random import randint

LEN_MAX = 2000
random.seed(0x514)

class Testcase:
    def __init__(self, s1, s2, name=None):
        #print len(s1), len(s2)
        assert len(s1) < LEN_MAX
        assert len(s2) < LEN_MAX

        n = s1.count('\n') + 1
        m = s2.count('\n') + 1

        self.n = n
        self.m = m
        self.s1 = s1
        self.s2 = s2

        self.name = 'n%d-m%d' % (n, m)
        if name:
            self.name += '-' + name

charset = string.digits + string.letters + '.e+-'
full_charset = charset + ' \n'

int_fmt = r'^[+-]?\d+$'
float_fmt = r'^[-+]?\d*(\.\d|\d\.|\d)\d*([eE][-+]?\d+)?$'

def is_int(s):
    return re.match(int_fmt, s)
def is_float(s):
    return re.match(float_fmt, s) and not is_int(s)

sign = ['+', '-', '']

def gen_samples():
    exps = []
    for a in ['e', 'E']:
        for b in sign + ['a']:
            for c in ['', '1', '0', '00', 'e']:
                exps.append(a + b + c)
    exps = list(set(exps))
    exps.sort()

    samples = []
    for a in sign + ['e']:
        for x in ['', '0', '1', '00']:
            for y in ['', '.']:
                for z in ['', '0', '1', '00']:
                    for e in [''] + exps:
                        samples.append(a + x + y + z + e)

    samples = list(set(samples) - set(''))
    samples.sort()

    floats = [s for s in samples if is_float(s)]
    ints = [s for s in samples if is_int(s)]
    strs = [s for s in samples if not is_float(s) and not is_int(s)]
    assert len(strs) + len(ints) + len(floats) == len(samples)

    return strs, ints, floats

strs, ints, floats = gen_samples()
alls = strs + ints + floats

qs = []
for s in alls:
    for xs in [strs, ints, floats]:
        qs.append((random.choice(xs), s))

random.shuffle(qs)


def gen_int(n=None):
    if n is None:
        n = random.randint(1, 10)

    s = random.choice(sign)
    while len(s) < n:
        s += random.choice(string.digits)
    return s

def gen_float():
    s1 = gen_int()
    s2 = ''
    s3 = ''

    n2 = random.randint(0, 5)
    if n2 > 0:
        s2 = '.'
        while len(s2) < n2:
            s2 += random.choice(string.digits)

    n3 = random.randint(0, 5)
    if n3 > 0:
        s3 = random.choice(['E', 'e'])
        s3 += gen_int(n3 - 1)
        s3 = s3[:n3]
    return s1 + s2 + s3

def gen_str(n=None):
    if n is None:
        n = random.randint(1, 10)
    s = [random.choice(charset) for _ in xrange(n)]
    s = ''.join(s)
    return s

def gen_token():
    f = random.choice([gen_str, gen_int, gen_float])
    res = f()
    #print f, res
    return res

def gen_pad():
    n = random.randint(1, 10)
    s = [random.choice(' \n') for _ in xrange(n)]
    s = ''.join(s)
    return s

def insert_garbage(s):
    idx = random.randint(0, len(s))
    c = random.choice(charset)
    return s[:idx] + c + s[idx:]

#print len(qs)


tests = []

st = ['e', 'E', '+', '-', '1', '0', '.']
for c in st:
    tests.extend([
        Testcase('', c * (LEN_MAX - 1), 'oneside-full-1-%x' % ord(c)),
        Testcase(c * (LEN_MAX - 1), '', 'oneside-full-2-%x' % ord(c)),
        Testcase('\n'.join([c] * 1000), '', 'onside-many-1-%x' % ord(c)),
        Testcase('', '\n'.join([c] * 1000), 'onside-many-2-%x' % ord(c)),
    ])

for b in st:
    for i in xrange(2):
        a = random.choice(st)
        tests.extend([
            Testcase(a * (LEN_MAX - 1), b * (LEN_MAX - 1), 'both-full-%x-%x' % (ord(a), ord(b))),
            Testcase('\n'.join([a] * 1000), '\n'.join([b] * 1000), 'both-many-%x-%x' % (ord(a), ord(b)))
        ])

tests.extend([
    Testcase(
        ''.join(random.choice([' ', '\n']) for i in xrange(LEN_MAX - 1)),
        '1',
        'onside-space-1'
    ),
    Testcase(
        '1',
        ''.join(random.choice([' ', '\n']) for i in xrange(LEN_MAX - 1)),
        'onside-space-2'
    ),
    Testcase(
        ''.join(random.choice([' ', '\n']) for i in xrange(LEN_MAX - 1)),
        ''.join(random.choice([' ', '\n']) for i in xrange(LEN_MAX - 1)),
        'both-space'
    ),
])

tests.extend([
    Testcase('+' + '1' * (LEN_MAX - 2), '-' + '1' * (LEN_MAX - 2), 'int-full-1'),
    Testcase('+.' + '1' * (LEN_MAX - 3), '-.' + '1' * (LEN_MAX - 3), 'int-full-2'),
    Testcase('+1.' + '1' * (LEN_MAX - 4), '-2.' + '1' * (LEN_MAX - 4), 'int-full-3'),
])

def gen_full_test_from_qs(qs, name):
    n = len(qs)
    l = 0
    tests = []
    while l < n:
        r = l
        # n^2
        xs, ys = [], []
        while r < n and len(' '.join(xs + [qs[r][0]])) < LEN_MAX and len(' '.join(ys + [qs[r][1]])) < LEN_MAX:
            xs.append(qs[r][0])
            ys.append(qs[r][1])
            r += 1

        assert [qs[i][0] for i in xrange(l,r)] == xs
        assert [qs[i][1] for i in xrange(l,r)] == ys

        l = r
        xs = random.choice(' \n').join(xs)
        ys = random.choice(' \n').join(ys)
        tests.append(Testcase(xs, ys, name))
    return tests


# all float with other
offset = 270
for i in xrange(0, len(qs), offset):
    sep = random.choice([' ', '\n'])

    end = min(len(qs), i + offset)
    s1 = [qs[j][0] for j in xrange(i, end)]
    s2 = [qs[j][1] for j in xrange(i, end)]

    s1 = sep.join(s1)
    s2 = sep.join(s2)
    tests.append(Testcase(s1, s2, 'all-floats'))


# full random
for i in xrange(10):
    s1 = ''
    s2 = ''
    while True:
        a = gen_pad() + gen_token()
        b = gen_pad() + gen_token()
        if len(s1) + len(a) >= LEN_MAX: break
        if len(s2) + len(b) >= LEN_MAX: break
        s1 += a
        s2 += b

    while len(s1) < LEN_MAX - 1:
        s1 = insert_garbage(s1)
    while len(s2) < LEN_MAX - 1:
        s2 = insert_garbage(s2)
    Testcase(s1, s2, 'full-random')

# short permutation

digits = lambda: random.choice("0123456789")
signs = lambda: random.choice("+-")
exps = lambda: random.choice("eE")
dots = lambda: "."

candis = [digits, signs, exps, dots]
for i in xrange(1, 5+1):
    qs = []
    for s in product(candis, repeat=i):
        s = map(lambda f: f(), s)
        s = ''.join(s)
        qs.append(('0', s))
    test = gen_full_test_from_qs(qs, "fullperm-%d" % i)
    tests.extend(test)

for i in xrange(6, 10+1):
    prod = product(candis, repeat=i)
    prod = list(prod)
    qs = []
    n = LEN_MAX / i
    n = (LEN_MAX - n) / i
    for s in random.sample(prod, n):
        s = map(lambda f: f(), s)
        s = ''.join(s)
        qs.append(('0', s))

    test = gen_full_test_from_qs(qs, "randomperm-%d" % i)
    tests.extend(test)

tests.extend([
    Testcase('', '', '0'),
    Testcase('\n'.join([
            '1.0', '2.0', '3.0', '4.0',
        ]), '\n'.join([
            'x1', 'x1.', 'x1.e-1.', 'x1.e-1x', '1.0'
        ]),
        'custom'
    ),
])

os.system("rm *.in *.ans")
for i, g in enumerate(tests):
    prefix = '%03d-' % (i)
    filename = prefix + g.name
    fin = filename + '.in'
    fout = filename + '.ans'

    print filename
    with open(fin, 'w')  as f:
        print >>f, g.n, g.m
        print >>f, g.s1
        print >>f, g.s2

    ret = subprocess.call("python ../../input_format_validators/check.py < %s" % fin, shell=True)
    assert ret == 42
    ret = os.system("python ../../submissions/accepted/sol.py < %s > %s" % (fin, fout))
    ret = os.system("../../submissions/accepted/sol < %s > /tmp/out && diff %s /tmp/out >/dev/null" % (fin, fout))
    assert ret == 0
