TARGET=ai_test
INCLUDE=-I. -I./include
SRCPATH=./src
ITEMS=$(patsubst %.c,%,./*.c)
ITEMS+=$(patsubst $(SRCPATH)/%.c,%,$(SRCPATH)/*.c)
OBJS=$(patsubst %.c,%.o,./*.c)
OBJS+=$(patsubst %.c,%.o,$(SRCPATH)/*.c)
SRC=$(wildcard *.c)
SRC+=$(wildcard $(SRCPATH)/*.c)
CFLAGS=-DDEBUG -Wall
LDFLAGS=

default:
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
%.o:%.c *.h
	$(CC) -c -o $@ $< $(CFLAGS)
syntax:
	$(CC) -fsyntax-only $(SRC)
help:
	@echo "******************************************************"
	@echo "options:[help] [syntax] [clean]"
	@echo "\thelp:display the help information."
	@echo "\tsyntax:check all the source file's syntax."
	@echo "\tclean:delete the target and .o file."
	@echo "******************************************************"
clean:
	$(RM) $(TARGET) $(OBJS)
.PHONY:default clean help check
