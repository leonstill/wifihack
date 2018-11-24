CC=gcc
LDFLAGS=-m32
SHLDFLAGS=
RM=rm -rf
CC_FLAGS=-m32 
TARGET=logtamper

.PHONY : all clean

all: static
	[ -d ../bin ] || mkdir ../bin 
	cp -f $(TARGET) ../bin

clean:
	$(RM) *.o $(TARGET)

%.o: %.c  
	$(CC) -c $(CC_FLAGS) -o $@ $<

logtamper:logtamper.o reserve_time.o str2time.o
	$(CC) $(LDFLAGS) -o $(TARGET) $^

static:logtamper.o reserve_time.o str2time.o
	$(CC) $(LDFLAGS) -static -o $(TARGET) $^

# static:logtamper.c reserve_time.c str2time.c
# 	$(CC) -m32 -static -o logtamper logtamper.c reserve_time.c str2time.c

