require_relative './gen_base'

class Test < TestBase
  def initialize(n, m)
    @n = n
    @m = m
  end

  def name
    "#{@n}_#{@m}"
  end

  def write_to(f)
    f.puts [@n, @m] * ' '
  end
end

sample, secret = [], []

1.upto(5) do |n|
  n.upto(6 * n) do |m|
    t = Test.new(n, m)
    if [n, m] == [2, 5] || [n, m] == [3, 5]
      sample << t
    else
      secret << t
    end
  end
end

sample.each.with_index(1) do |t, i|
  open("sample/s#{i}.in", 'w'){|f| t.write_to(f)}
end
secret.each(&:save)
make_ans
