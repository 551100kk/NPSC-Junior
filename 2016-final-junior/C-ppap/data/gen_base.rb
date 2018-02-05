require 'fileutils'
require 'stringio'

class TestBase
  @@name_count = Hash.new(0)
  @@test_id = 0

  def to_s
    io = StringIO.new
    self.write_to(io)
    io.string
  end

  def name
    @name ||= 'noname'
  end

  def save(name = nil)
    name ||= self.name
    @@name_count[name] += 1
    @@test_id += 1
    path = "secret/%03d-%s-%d.in" % [@@test_id, name, @@name_count[name]]
    puts "Saving #{path}"
    open(path, 'w'){|f| write_to(f)}
  end
end

def save_samples(samples)
  samples.each.with_index(1) do |t, i|
    open("sample/s#{i}.in", 'w'){|f| t.write_to(f)}
  end
end

def make_ans(show_stderr = false)
  max_used_time = 0
  sol_cpp = Dir.glob('../submissions/accepted/sol.cpp').first
  fail 'no sol' if sol_cpp.nil?

  sol = sol_cpp[0...-4]
  if !File.file?(sol) || File.mtime(sol) < File.mtime(sol_cpp)
    warn 'Compiling...'
    system("g++-6 -O2 -std=c++11 #{sol_cpp} -o #{sol}")
    fail 'CE' if $? != 0
  end

  fis = []
  fis += Dir.glob('sample/s[1-9].in').sort
  fis += Dir.glob('secret/*.in').sort
  max_len = fis.map(&:size).max
  fis.each do |fi|
    fo = fi.sub(/\.in$/, '.ans')
    print "Running #{fi.ljust(max_len)}"
    start_time = Time.now
    err = show_stderr ? :err : '/dev/null'
    pid = spawn(sol, in: fi, out: fo, err: err)
    Process.waitpid pid
    end_time = Time.now
    used_time = end_time - start_time
    puts "\t%2.2fs\texit %d" % [used_time, $?.to_i]
    max_used_time = [max_used_time, used_time].max
  end

  puts "max_used_time = %.2fs" % max_used_time
end

FileUtils.mkdir_p('sample')
FileUtils.mkdir_p('secret')

FileUtils.rm(Dir.glob('{sample,secret}/*.{in,ans}'))
srand(51450216)
