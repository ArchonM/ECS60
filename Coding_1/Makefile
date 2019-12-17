CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

SORTING_SOURCES=insertionsort.cpp mergesort.cpp quicksort.cpp
SORTING_HEADERS=$(SORTING_SOURCES:.cpp=.h)
SORTING_DEV_OBJ=$(SORTING_SOURCES:.cpp=.o)
SORTING_OPT_OBJ=$(SORTING_SOURCES:.cpp=.o3)

EXE_SOURCES=createdata.cxx consistentresultverification.cxx sortedverification.cxx
EXE=$(EXE_SOURCES:.cxx=.exe)

.PHONY: all
all: sorting_lib $(EXE)

# Sorting library
.PHONY: $(SORTING_LIB)
sorting_lib: $(SORTING_DEV_OBJ) $(SORTING_OPT_OBJ)

$(SORTING_DEV_OBJ): %.o: %.cpp %.h
	$(CC) $(DEV) -c $< -o $@

$(SORTING_OPT_OBJ): %.o3: %.cpp %.h
	$(CC) $(OPT) -c $< -o $@

# Executables
$(EXE): %.exe: %.cxx
	$(CC) $(DEV) -o $@ $<

# Build
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.o3
	rm -f *.exe

.PHONY: update
update:
	make clean
	make all
