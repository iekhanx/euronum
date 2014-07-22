#
#   31/03/2014    @ik
#
#help:
#	echo -e "Usage: Make <ARCH=arm | ARCH=x86>"
#	echo -e "Make all"

ifdef ARCH 
  $(info ARCH defined) 
  CC		= arm-linux-gnueabi-g++
  CFLAGS	= -static
  MSG		= "***** Binary generated for ARM-9 compatible CPU ****"
  COMPILER      = "ARM-Linux-gnueabi-g++ compiler 4.6.4" 
 else
  $(info ARCH undefined)
  CC		= g++
  CFLAGS      	= -Wall -g -O2 -Wno-write-strings
  MSG		= "Binary generated for i386 compatible Intel CPU"
  COMPILER    	= "gcc version 4.6.3 20120306 (Red Hat 4.6.3-2) (GCC)"

endif
LDFLAGS     	= -g
PREFIX      	= $HOME/bin
#INCLUDES    	= -I$HOME/include -I../include
#CLDFLAGS    	= -L$HOME/lib -L../lib
#LIBS        	= -lncurses -lmenu -lmylib -lm

DEBUG_INFO      = "Debug info included in the binary executable"


#define source files.
SRCS        	= matrix.cpp

# define an object files.
OBJS        	= $(SRCS:.c=.o)

# define main target build binary executable
ifdef ARCH
  MAIN        	= matrix_arm 
else
  MAIN		= matrix_i386
endif
# define clean 
.PHONY:		depend clean


all:  		$(MAIN)
		@echo Program compiled with $(COMPILER)
		@echo with OS $(shell uname -s -r -o -m)
		@echo $(DEBUG_INFO)
		@echo $(MSG)

$(MAIN):	$(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

# define suffix replacement rules for building o from c
.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo Cleaning up object and binary files....
		$(RM) *.o *~ $(MAIN)


install:
		@echo COPYING file from ....
		cp -v $(MAIN) $(PRFIX)

depend:		$(SRCS)
		makedepend $(INCLUDES)
# Do not delete this line. 
    
