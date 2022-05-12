DFLAGS = -DTEST_READLIST -DTEST_ANALIZE -DTEST_DELETELIST -DTEST_ADDNODE -DTEST_DELETENODE -DTEST_CONVERT -DTEST_SIZE
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = $(CC) -std=c99 -g $(WARNING) $(ERROR) $(DFLAGS) 
EXE = calc1
SRCS = convert.c list.c main.c
OBJS = $(SRCS:%.c=%.o)
VAL = valgrind --leak-check=full --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose 
run: testall
$(EXE): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE) #2> error.gccmessages
.c.o: 
	$(GCC) -c $*.c #2> error.gccmessages
testmemory: $(EXE)
	$(VAL) ./$(EXE) inputs/test3 > output1
testall: test1 test2 test3 test4 test5 test6 testmemory
test1: $(EXE)
	./$(EXE) inputs/test1 > output1
	diff expected/expected1 output1
test2: $(EXE)
	./$(EXE) inputs/test2 > output2
	diff expected/expected2 output2
test3: $(EXE)
	./$(EXE) inputs/test3 > output3
	diff expected/expected3 output3
test4: $(EXE)
	./$(EXE) inputs/test4 > output4
	diff expected/expected4 output4
test5: $(EXE)
	./$(EXE) inputs/test5 > output5
	diff expected/expected5 output5
test6: $(EXE)
	./$(EXE) inputs/test6 > output6
	diff expected/expected6 output6
clean:
	rm -rf output* $(OBJS) $(EXE) error*
