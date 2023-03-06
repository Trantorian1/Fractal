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
LIB_FLAGS = LIB_HASH.collect { |key, value| "-L#{key} -l#{value}" }.join(' ')

HEADERS  = ['./include', './vendor/libft', './vendor/minilibx-linux']
H_FLAGS = HEADERS.collect { |dir| "-I #{dir}" }.join(' ')

CC = 'clang'
C_FLAGS = "-Wall -Wextra -Werror #{H_FLAGS}"

SRC_FILES = Rake::FileList.new("#{SRC_DIR}/**/*.c") do |file|
  file.exclude { |f| "git ls-files #{f}".empty? }
end

OBJ_FILES = SRC_FILES.pathmap("#{OBJ_DIR}/%n.o")
DEP_FILES = SRC_FILES.pathmap("#{DEP_DIR}/%n.mf")

BIN = 'fractal'

# ==============================================================================
#                                      RULES
# ==============================================================================

task default: :build

task build: BIN

file BIN: OBJ_FILES do
  sh "#{CC} #{C_FLAGS} #{OBJ_FILES} -o #{BIN} #{LIB_FLAGS}"
end

rule '.o': [->(f) { source_obj(f) }, OBJ_DIR] do |task|
  sh "#{CC} #{C_FLAGS} -c #{task.source} -o #{task.name}"
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
    c_file.pathmap("%n") == o_file.pathmap("%n")
  end
end
