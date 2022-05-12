# ***
# *** DO NOT modify this file
# ***
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DDEBUG -DTEST_DELETENODE -DTEST_CALCULATE -DTEST_ADDNODE -DTEST_DELETELIST -DTEST_READLIST

SRCS = main.c list.c calculate.c
OBJS = $(SRCS:%.c=%.o)
hw13: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13
.c.o:
	$(GCC) $(TESTFALGS) -c $*.c
testmemory1: hw13
	$(VAL) ./hw13 inputs/test1 > memout
testmemory2: hw13
	$(VAL) ./hw13 inputs/test2 > memout
testmemory3: hw13
	$(VAL) ./hw13 inputs/test3 > memout
testmemory4: hw13
	$(VAL) ./hw13 inputs/test4 > memout
testmemory5: hw13
	$(VAL) ./hw13 inputs/test6 > memout
testmemory6: hw13
	$(VAL) ./hw13 inputs/test6 > memout

testall: test1 test2 test3 test4 test5 test6 pack
t: hw13
	./hw13 inputs/test$(var)
test1: hw13
	./hw13 inputs/test1 > output1
	diff output1 expected/expected1
test2: hw13
	./hw13 inputs/test2 > output2
	diff output2 expected/expected2
test3: hw13
	./hw13 inputs/test3 > output3
	diff output3 expected/expected3
test4: hw13
	./hw13 inputs/test4 > output4
	diff output4 expected/expected4
test5: hw13
	./hw13 inputs/test5 > output5
	diff output5 expected/expected5
test6: hw13
	./hw13 inputs/test6 > output6
	diff output6 expected/expected6
#pack: hw13
#    zip hw13.zip list.c calculate.c
clean: # remove all machine generated files
	rm -f hw13 *.o output?
