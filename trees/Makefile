CFLAGS+=-std=c++11 -Wall -Werror -g -O0

CXX?=clang++
LDFLAGS=-lpthread

SRC=$(wildcard *.cc)

%.o: %.cc
	$(CXX) -c $(CFLAGS) -o $@ $^


trees: $(SRC:%.cc=%.o)
	$(CXX) $(CLFAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -fr *.o trees core*
