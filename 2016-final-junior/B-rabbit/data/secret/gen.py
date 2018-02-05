import os
import random
from random import randint
import string

N_MAX = 50
M_MAX = 100

class Testcase:
    def __init__(self, data, name=None):
        n = len(data)
        assert 0 < n <= N_MAX
        assert all(0 <= x <= M_MAX for x in data)

        data = sorted(data)

        self.n = n
        self.data = data

        self.name = 'n%d' % n
        if name:
            self.name += '-' + name

random.seed(0x514)

tests = [
    Testcase([0], '0'),
    Testcase([50], '50'),
    Testcase([100], '100'),
    Testcase([0] * N_MAX, 'all-0'),
    Testcase([50] * N_MAX, 'all-50'),
    Testcase([100] * N_MAX, 'all-100'),
    Testcase([0, 100], '0-100'),
    Testcase([0] * 25 + [100] * 25, 'all0-100'),
    Testcase(xrange(1, M_MAX, 2), '1-3-5'),
    Testcase(xrange(0, 99, 2), '0-2-4'),
]

for nn in [5, 10, 25, 50]:
    tests.extend(
        [Testcase(random.sample(xrange(M_MAX), nn), 'random') for i in xrange(5)]
    )
    tests.extend(
        [Testcase([random.choice(xrange(M_MAX)) for k in xrange(nn)], 'random-replace') for i in xrange(5)]
    )


for i in xrange(10):
    tests.append(
        Testcase(random.sample(xrange(M_MAX), random.randint(1, 50)), 'random')
    )
    tests.append(
        Testcase([random.choice(xrange(M_MAX)) for k in xrange(random.randint(1, 50))], 'random-replace')
    )


for i, g in enumerate(tests):
    prefix = '%02d-' % (i)
    filename = prefix + g.name
    fin = filename + '.in'
    fout = filename + '.ans'

    print filename
    with open(fin, 'w')  as f:
        print >>f, g.n
        print >>f, ' '.join(map(str, g.data))

    os.system("../../submissions/accepted/sol < %s > %s" % (fin, fout))
