
PROGRAMS = testQuickSort 
CXX = clang++
CXXFLAGS = -g

all: $(PROGRAMS)


testQuickSort: testQuickSort.cpp quickSort-inl.h quickSort.h
	$(CXX) $(CXXFLAGS) -o testQuickSort testQuickSort.cpp

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: clean all
