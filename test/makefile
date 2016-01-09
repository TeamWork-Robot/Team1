PROJ = test-point

CC = gcc
OBJS = $(SRCS:.cpp=.o)
APP = $(PROJ)
CFLAGS = -c -g -Wall -I/opt/local/include
LDFLAGS = -L/opt/local/lib
LIBS = -lcppunit -ldl

all: $(APP)

$(APP): testmain.o Point.o test_point.o
	$(CC) $(LDFLAGS) testmain.o test_point.o Point.o -o $(APP) $(LIBS)

testmain.o: testmain.cpp 
	$(CC) $(CFLAGS) $< -o $@

Point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) $< -o $@
         
test_point.o: test_point.cpp test_point.h 
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(APP)
