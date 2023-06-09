#MAC_OPTS=-isystem /opt/homebrew/include -I/opt/homebrew/include -L/opt/homebrew/lib
#ARCH = -arch arm64

CC = $(CLANG_PREFIX)clang++
LAB_OPTS = -I./src src/Arr_Student.cpp src/Student.cpp
TEST_OPTS = -I./test test/test_Arr_Student.cpp test/test_Student.cpp

DOCG = doxygen
DOC = Doxyfile

C_OPTS = $(MAC_OPTS) -std=c++14 -gdwarf-4 -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Werror=vla $(LAB_OPTS)

F_SANITIZ = -fsanitize=address

V_FLAGS = --tool=memcheck --leak-check=full --show-reachable=yes \
	--undef-value-errors=yes --track-origins=no --child-silent-after-fork=no \
	--trace-children=no --error-exitcode=1
V_LAGS = valgrind

#-------------------------------------------------------------#
                             #(basic)#
                             
main_all: clean prep compile
	./dist/main.bin ./assets/input.txt dist/text.txt

test_all: clean prep test.bin test

doxygen: clean_doxy Doxygen

#-------------------------------------------------------------#
                             #(lead-up)#
                             
clean:
	rm -rf dist

clean_doxy:
	rm -rf ./dist/html
	rm -rf ./dist/latex 
prep:
	mkdir dist

#-------------------------------------------------------------#
                             #(main)#
compile: main.bin

main.bin: src/main.cpp
	$(CC) $(F_SANITIZ) $(C_OPTS) $< -o ./dist/$@
	
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c  -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

#-------------------------------------------------------------#
                             #(doxygen)#
                             
Doxygen:
	$(DOCG) $(DOC)
	
#-------------------------------------------------------------#
                             #(test)#
                             
test_all: clean prep test.bin test

test.bin:
	 $(CC) $(C_OPTS) $(TEST_OPTS) $< $(ARCH) -fprofile-instr-generate -fcoverage-mapping -o ./dist/$@ -lgtest -lgtest_main
test: dist
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.cpp
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.cpp --format html > dist/coverage.html

#-------------------------------------------------------------#
                             #(code-coverage)#

leak-check_main1:src/main.cpp clean prep
	$(CC) $(C_OPTS) $< -o ./dist/main.bin
	$(V_LAGS) $(V_FLAGS) --log-file=dist/valgrind_main.log  ./dist/main.bin 
leak-check_main2: 
	$(V_LAGS) $(V_FLAGS) --xml-file=dist/valgrind_main.xml  --xml=yes cat ./assets/text.txt | ./dist/main.bin

leak-check_test2:
	$(V_LAGS)  $(V_FLAGS) --xml-file=dist/valgrind_test.xml  --xml=yes dist/test.bin
leak-check_test1:clean prep test.bin
	$(V_LAGS)  $(V_FLAGS)  --log-file=dist/valgrind_test.log  ./dist/test.bin 
	
#-------------------------------------------------------------#
