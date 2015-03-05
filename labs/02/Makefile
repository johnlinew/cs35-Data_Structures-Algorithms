CXXFLAGS = -g
CXX = g++

OBJS = media.o picture.o #video.o book.o mediaLibrary.o

HDRS = media.h picture.h #video.h book.h mediaLibrary.h

PROGS = main testMedia

all: $(PROGS)

# This uses hideous Makefile shortcut variables.
# $@ - target, $^ names of all prerequisites. $(VAR) - value of VAR
#

testMedia: testMedia.cpp $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) testMedia.cpp $(OBJS) -o testMedia

main: main.cpp $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o main

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ 

clean:
	rm -f *.o testMedia main

.PHONY: clean all
