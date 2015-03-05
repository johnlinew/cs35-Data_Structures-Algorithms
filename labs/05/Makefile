CXX = clang++
CXXFLAGS = -g -Wall

# Add any new .h and -inl.h files to the INCLUDES definition below:
INCLUDES = list.h circularArrayList.h circularArrayList-inl.h stack.h arrayStack.h arrayStack-inl.h queue.h arrayQueue.h arrayQueue-inl.h

# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS = maze.o position.o

# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
# (similar to the solveMaze rule).
PROGRAMS = solveMaze testList testStackQueue

all: $(PROGRAMS)

solveMaze: $(INCLUDES) $(OBJECTS) solveMaze.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

testList: $(INCLUDES) $(OBJECTS) testList.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

testStackQueue: $(INCLUDES) $(OBJECTS) testStackQueue.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean
