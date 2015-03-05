CXX = clang++
CXXFLAGS = -g -Wall

#TODO: remove the comments below when you are testing
# your linked list implementation

INCLUDES = frameNode.h movieList.h # movieLinkedList.h movie.h
OBJECTS = frameNode.o # movieLinkedList.o  movie.o
PROGRAMS = player testLinkedList

all: $(PROGRAMS)

player: $(INCLUDES) $(OBJECTS) player.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

testLinkedList:  $(INCLUDES) $(OBJECTS) testLinkedList.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean
