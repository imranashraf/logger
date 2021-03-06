CC      = g++
LFLAGS  = -L. 
LIBS    = -lm
CFLAGS  = -g -O2 -MD
INCS    = -I.

SRCS	= test.cpp 
EXEC    = test
RUN_CMD	=./$(EXEC)
OBJS	=$(SRCS:%.cpp=%.o)

all: clean $(EXEC) run


$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LFLAGS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
	rm -f $*.d

-include *.P

format:
	astyle --style=allman *.h *.cpp
	rm -f *.orig

run: $(EXEC)
	$(RUN_CMD)

clean:
	rm -f $(EXEC) $(OBJS) *~ *.P

.PHONY: clean run all

