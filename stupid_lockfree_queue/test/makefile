source = $(shell ls *.cpp)
target = $(patsubst %.cpp, %.out, $(source))
gcc_common_flags = -I.. -Wall -O0 -g3

%.out: %.cpp ../*.h
	g++ $(gcc_common_flags) -o $@ $<

.PHONY: all test clean

all : $(target)

clean:
	rm *.out
