require_relative './gen_base'

class Test < TestBase
  def initialize(s)
    @s = s
  end

  def write_to(f)
    f.puts @s
  end
end

save_samples([
  'XQQBQQYPPAPPZ',
  'PENPINEAPPLEAPPLEPEN',
  # 'SHIKSOFAT',
  # 'TTTTTTT',
  'ABABYXABABXYAB'
].map{|s| Test.new(s)})

A = ('A'..'Z').to_a

def rs(n)
  n.times.map{A.sample}.join
end

def ppap(n)
  p = rs(n)
  a = rs(n)
  p + p + a + p
end

def gen_random_yes(n)
  s = rs(n)
  n.times do
    m = rand(1..n / 4)
    s[rand(0..n - 4 * m), 4 * m] = ppap(m)
  end
  Test.new(s).save("random_yes_#{n}")
end

def gen_random(n)
  Test.new(rs(n)).save("random_#{n}")
end

def gen_full(n)
  fail if n % 4 != 0
  Test.new(ppap(n / 4)).save("full_#{n}")
end

def gen_prob(n, p)
  c = A.sample
  s = n.times.map{rand < p ? c : A.sample}.join
  Test.new(s).save("prob_#{p}")
end

def gen_same_len(n, m)
  s = rs(n)
  n.times do
    s[rand(0..n - 4 * m), 4 * m] = ppap(m)
  end
  Test.new(s).save("same_len_#{n}_#{m}")
end

Test.new('BAAA').save('four')
Test.new('ABAA').save('four')
Test.new('AABA').save('four')
Test.new('AAAB').save('four')

4.upto(10){|n| gen_random_yes(n)}
9.times{gen_random_yes(rand(1..300))}
9.times{gen_random_yes(rand(295..300))}

1.upto(10){|n| gen_random(n)}
9.times{gen_random(rand(1..300))}
9.times{gen_random(rand(295..300))}

1.upto(5){|i| gen_full(4 * i)}
gen_full(300)

gen_prob(300, 0.9)
5.times{gen_prob(300, 0.99)}

1.upto(10){|i| gen_same_len(300, i)}
15.times.map{gen_same_len(rand(296..300), rand(11..40))}

Test.new(A.sample * 299).save("all_same")
Test.new(A.sample * 300).save("all_same")
Test.new('PPAP' * 75).save("ppap")
Test.new('B' * 296 + 'AAZA').save("manual")
Test.new(75.times.map{A.sample * 4}.join).save("manual")
Test.new((('A'..'Y').to_a * 12).join[0...-1]).save("manual")

make_ans
