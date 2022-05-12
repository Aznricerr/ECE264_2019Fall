# ***
# *** DO NOT modify this file
# ***
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_DIVIDE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

shuffle: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o shuffle
.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: shuffle
	$(VAL) ./shuffle 5 2

testall: test4_3 test4_5 test5_2 test6_2 test7_3 test8_2 test11_2 pack

t43: shuffle
	./shuffle 4 3
timer: shuffle
	./shuffle 4 5 > timer.txt
	grep time timer.txt
test4_3: shuffle
	./shuffle 4 3 | sort | uniq > output4_3
	diff output4_3 expected/expected_4_3 -w
test4_5: shuffle
	./shuffle 4 5 | sort | uniq > output4_5
	diff output4_5 expected/expected_4_5 -w
test5_2: shuffle
	./shuffle 5 2 | sort | uniq > output5_2
	diff output5_2 expected/expected_5_2 -w
test6_2: shuffle
	./shuffle 6 2 | sort | uniq > output6_2
	diff output6_2 expected/expected_6_2 -w
test7_3: shuffle
	./shuffle 7 3 | sort | uniq > output7_3
	diff output7_3 expected/expected_7_3 -w
test8_2: shuffle
	./shuffle 8 2 | sort | uniq > output8_2
	diff output8_2 expected/expected_8_2 -w
test11_2: shuffle
	./shuffle 11 2 | sort | uniq > output11_2
	diff output11_2 expected/expected_11_2 -w

 
clean: #remove all machine generated files
	rm -f shuffle *.o output?? output??? timer timer.txt
