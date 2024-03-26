# CXX is set to "g++" and CXXFLAGS is set to
# "-O0 -g -Wall -std=c++11" in the Linux system

test.out: test.cpp BigInt.cpp
	@$(CXX) $(CXXFLAGS) $^ -o $@

test: test.out
	@valgrind --quiet --leak-check=full ./$< -tc="$(TC)" -sc="$(SC)"

check: BigInt.h
	@dos2unix $^ > /dev/null 2>&1
	@echo "Suggestions are for reference only ..."
	@cppcheck --language=c++ --enable=style,warning --suppress=copyCtorAndEqOperator $^

clean:
	@rm -f *.out
