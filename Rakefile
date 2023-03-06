require 'rake/clean'
require 'rake/loaders/makefile'

SRC_DIR = './src'
BUILD_DIR = './build'
OBJ_DIR = "#{BUILD_DIR}/objs"
DEP_DIR = "#{BUILD_DIR}/deps"
BIN_DIR = './bin'

LIB_HASH = {
  './vendor/libft': 'ft',
  './vendor/minilibx-linux': 'mlx'
}
LIB_X11 = '-lX11 -lXext'
LIB_FLAGS = LIB_HASH.collect { |key, value| "-L#{key} -l#{value}" }.join(' ')

HEADERS  = ['./include', './vendor/libft', './vendor/minilibx-linux']
H_FLAGS = HEADERS.collect { |dir| "-I #{dir}" }.join(' ')

# ==============================================================================
#                                   COMPILATION
# ==============================================================================

CC = 'clang'
C_FLAGS = "-Wall -Wextra -Werror -O3 #{H_FLAGS}"
D_FLAGS = "#{H_FLAGS} -M -MP -MM"

SRC_FILES = Rake::FileList.new("#{SRC_DIR}/**/*.c") do |file|
  file.exclude { |f| "git ls-files #{f}".empty? }
end

OBJ_FILES = SRC_FILES.pathmap("#{OBJ_DIR}/%n.o")
DEP_FILES = SRC_FILES.pathmap("#{DEP_DIR}/%n.mf")

BIN = 'fractal'

CLEAN.include(OBJ_FILES, DEP_FILES)
CLOBBER.include("#{BIN_DIR}/**")

# ==============================================================================
#                                DEBUG COMPILATION
# ==============================================================================

OBJ_FILES_DEBUG = SRC_FILES.pathmap("#{OBJ_DIR}/debug/%n.o")
DEP_FILES_DEBUG = SRC_FILES.pathmap("#{OBJ_DIR}/debug/%n.mf")

CLEAN.include(OBJ_FILES_DEBUG, DEP_FILES_DEBUG)

# ==============================================================================
#                                   DIRECTORIES
# ==============================================================================

directory OBJ_DIR
directory DEP_DIR
directory "#{OBJ_DIR}/debug"
directory "#{DEP_DIR}/debug"
directory BIN_DIR

# ==============================================================================
#                                      RULES
# ==============================================================================

task default: :build

task build: :binary

file binary: [*OBJ_FILES, BIN_DIR] do
  sh "#{CC} #{C_FLAGS} #{OBJ_FILES} -o #{BIN_DIR}/#{BIN} #{LIB_X11} #{LIB_FLAGS}"
end

# ==============================================================================
#                                    DEBUG RULES
# ==============================================================================

task :debug do
  C_FLAGS << " -g3 -fsanitize=address"
  Rake::Task[:binary_debug].invoke
end

file binary_debug: [*OBJ_FILES_DEBUG, BIN_DIR] do
  sh "#{CC} #{C_FLAGS} #{OBJ_FILES_DEBUG} -o #{BIN_DIR}/#{BIN}_debug " +
     "#{LIB_X11} #{LIB_FLAGS}"
end

# ==============================================================================
#                                 DEPENDENCY RULES
# ==============================================================================

rule '.o' => [->(f) { source_obj(f) }, OBJ_DIR, "#{OBJ_DIR}/debug"] do |task|
  sh "#{CC} #{C_FLAGS} -c #{task.source} -o #{task.name}"
end

rule '.mf' => [->(f) { source_dep(f) }, DEP_DIR, "#{DEP_DIR}/debug"] do |task|
  cmd = "#{CC} #{D_FLAGS} #{task.source} -MT #{task.source.ext('.o')}"
  make_target = `#{cmd}`

  open(task.name.to_s, 'w') do |file|
    file.puts make_target.to_s
    file.puts make_target.sub('.o:', '.mf:').to_s
  end
end

# ==============================================================================
#                                   HELPER RULES
# ==============================================================================

task :info do
  puts '>> OBJECT FILES'
  puts OBJ_FILES
end

# ==============================================================================
#                                 HELPER FUNCTIONS
# ==============================================================================

def source_obj(o_file)
  SRC_FILES.detect do |c_file|
    c_file.pathmap('%n') == o_file.pathmap('%n')
  end
end

def source_dep(d_file)
  SRC_FILES.detect do |c_file|
    c_file.pathmap('%n') == d_file.pathmap('%n')
  end
end

# ==============================================================================
#                               DEPENDENCY INCLUSION
# ==============================================================================

DEP_FILES.each do |d_file|
  file d_file
  puts "importing #{d_file}"
  import d_file
end

DEP_FILES_DEBUG.each do |d_file|
  file d_file
  puts "importing #{d_file}"
  import d_file
end
