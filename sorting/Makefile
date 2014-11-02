CFLAGS+=-std=c++11 -Wall -Werror -O3

CXX?=clang++
LDFLAGS=-lpthread

SRC=$(wildcard *.cc)

%.o: %.cc
	$(CXX) -c $(CFLAGS) -o $@ $^


sort: $(SRC:%.cc=%.o)
	$(CXX) $(CLFAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -fr *.o sort core*
