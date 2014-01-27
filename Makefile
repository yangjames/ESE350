OBJ = test

test: testlist.o list.o
	gcc -Wall -g -o $@ $^

%.o: %.c
	gcc -Wall -g -c $^

.PHONY: clean

clean:
	rm *~ *.o $(OBJ)