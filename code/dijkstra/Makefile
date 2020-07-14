HEAP=-l binheap -l common -L ../heaps

all: test

%.o: %.c
	gcc -c $< -o $@  -I include -I ../heaps/include $(HEAP)

src/node.o: include/node.h
src/dijkstra.o: include/dijkstra.h

main.o: src/node.o src/dijkstra.o 

test: main.o src/node.o src/dijkstra.o 
	gcc $^ -o $@ $(HEAP)

clean:
	rm -rf *.o src/*.o *.x test