DFLAGS = -DTEST_DELETETREENODE -DTEST_FREETREE -DTEST_PREORDERNODE -DTEST_PREORDER -DTEST_SEARCH -DTEST_BUILDUTIL -DTEST_BUILDTREE
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = $(CC) -std=c99 -g $(WARNING) $(ERROR) $(DFLAGS)
EXE = hw15
SRCS = tree.c main.c
OBJS = $(SRCS:%.c=%.o)
VAL = valgrind --leak-check=full --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose
run: testall
$(EXE): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE) #2> error.gccmessages
.c.o: 
	$(GCC) -c $*.c #2> error.gccmessages
testmemory: $(EXE)
	$(VAL) ./$(EXE) inputs/test3in inputs/test3post > output1
testall: test1 test2 test3 test4 test5 test6 testmemory
test1: $(EXE)
	./$(EXE) inputs/test1in inputs/test1post output1
	diff expected/expected1 output1
test2: $(EXE)
	./$(EXE) inputs/test2in inputs/test2post output2
	diff expected/expected2 output2
test3: $(EXE)
	./$(EXE) inputs/test3in inputs/test3post output3
	diff expected/expected3 output3
test4: $(EXE)
	./$(EXE) inputs/test4in inputs/test4post output4
	diff expected/expected4 output4
test5: $(EXE)
	./$(EXE) inputs/test5in inputs/test5post output5
	diff expected/expected5 output5
test6: $(EXE)
	./$(EXE) inputs/test6in inputs/test6post output6
	diff expected/expected6 output6
clean:
	rm -rf output* $(OBJS) $(EXE) error*
