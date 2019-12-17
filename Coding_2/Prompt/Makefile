CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

JSON=json.hpp

CREATE_DATA_SRC=createsortingdata.cxx createheapoperationdata.cxx buildheap.cxx heapsort.cxx
CREATE_DATA_EXE=$(CREATE_DATA_SRC:.cxx=.exe)
CREATE_DATA_O=priorityqueue.o

.PHONY: all
all: $(CREATE_DATA_O) $(CREATE_DATA_EXE)

$(CREATE_DATA_O): %.o: %.cpp $(JSON)
	$(CC) -c $(OPT) $< -o $@
$(CREATE_DATA_EXE): %.exe: %.cxx $(JSON) priorityqueue.o
	$(CC) $(OPT) $< -o $@ priorityqueue.o

# Build
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.o3
	rm -f *.exe
	rm -rf *.exe.dSYM

.PHONY: update
update:
	make clean
	make all
