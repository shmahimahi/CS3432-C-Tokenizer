OBJS = tokenizer.o ui.o history.o
CFLAGS=-g -O3
all: tokenizer
tokenizer: $(OBJS)
	cc  $(CFLAGS) -o $@ $^
tokenizer.o: tokenizer.c tokenizer.h
ui.o: ui.c tokenizer.h history.h
history.o: history.c history.h

run:tokenizer
	./tokenizer
clean:
	rm -f *.o tokenizer *~ \#*
