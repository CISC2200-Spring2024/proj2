# CXX is set to "g++" and CXXFLAGS is set to
# "-O0 -g -Wall -std=c++11" in the Linux system

test.out: test.o BigInt.o
	@$(CXX) $(CXXFLAGS) $^ -o $@

BigInt.o: BigInt.h

test.o: BigInt.h

test: test.out
	./test.out

clean:
	@rm -f *.out
