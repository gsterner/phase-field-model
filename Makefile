# Makefile template for shared library

CC = clang # C compiler
CFLAGS = -fPIC -Wall -Wextra -O2 -g # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libphasefieldmodela.so # target lib

SRCDIR   = src
OBJDIR   = obj
#BINDIR   = bin


SRCS := $(wildcard $(SRCDIR)/*.c) # source files
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJS  := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@


.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} 

