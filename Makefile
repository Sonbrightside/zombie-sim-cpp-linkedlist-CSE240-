
OBJS = hw5_son_hongju.o


CC = g++


DEBUG = -g




LFLAGS = -Wall $(DEBUG)


exe: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o exe
	

clean:
	\rm *.o *~ exe


