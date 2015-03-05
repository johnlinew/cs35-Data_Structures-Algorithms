CXX = clang++
CXXFLAGS = -g

# Add any new .h and .inl files to the INCLUDES definition below:
INCLUDES = library/queue.h library/arrayQueue.h library/arrayQueue-inl.h \
	   library/list.h library/circularArrayList.h \
 	   library/circularArrayList-inl.h library/priorityQueue.h \
	   library/pair.h library/binaryHeap.h library/binaryHeap-inl.h \
	   hashTable.h hashTable-inl.h dictionary.h 


# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS = 


# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
PROGRAMS = testHash scrabbleCheat

all: $(PROGRAMS)

testHash: $(INCLUDES) $(OBJECTS) testHash.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

scrabbleCheat: $(INCLUDES) $(OBJECTS) scrabbleCheat.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean
