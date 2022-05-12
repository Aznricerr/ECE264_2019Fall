# ***
# *** DO NOT modify this file
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o shuffle

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle inputs/input3 output3

testall: test8 test8 test11 pack

t4: shuffle
	./shuffle 4

test4: shuffle
	./shuffle 4 | sort > output4
	diff output4 expected/expected4 -w

t8: shuffle
	./shuffle 8 

test8: shuffle
	./shuffle 8 | sort > output8
	diff output8 expected/expected8 -w

test11: shuffle
	./shuffle 11 | sort > output11
	diff output11 expected/expected11 -w

clean: # remove all machine generated files
	rm -f shuffle *.o output? output??
