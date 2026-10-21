CC 	= gcc 
CFLAGS 	= -Wall
ROOTDIR = $(shell pwd)
CPROGS  = $(shell ls *.c)
OBJS  	= $(CPROGS:.c=.o)


main: $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $<
.PHONY:clean
clean:
	rm -f $(OBJS) main
