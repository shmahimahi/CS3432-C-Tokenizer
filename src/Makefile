OBJS = tokenizer.o ui.o
CFLAGS=-g -O3
all: tokenizer
tokenizer: $(OBJS)
	cc  $(CFLAGS) -o $@ $^
tokenizer.o: tokenizer.c tokenizer.h
ui.o: ui.c tokenizer.h 

run:tokenizer
	./tokenizer
clean:
	rm -f *.o tokenizer *~ \#*
