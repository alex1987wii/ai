TARGET=ai_test
INCLUDE=-I. -I./include
SRC=./src
ITEMS=$(patsubst %.c,%,./*.c)
ITEMS+=$(patsubst $(SRC)/%.c,%,$(SRC)/*.c)
OBJS=$(patsubst %.c,%.o,./*.c)
OBJS+=$(patsubst %.c,%.o,$(SRC)/*.c)
CFLAGS=-DDEBUG -Wall
LDFLAGS=

default:
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o:%.c *.h
	$(CC) -c -o $@ $< $(CFLAGS)
clean:
	$(RM) $(TARGET) $(OBJS)
.PHONY:default clean
