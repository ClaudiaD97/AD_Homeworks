#include "node.h"
#include "dijkstra.h"

#include <stdio.h>
#include <time.h>

double test(void (*f)(graph_type *,unsigned int), graph_type *g, unsigned int k){
  struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = 10;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t i = 0; i < rep; i++) {
    f(g,k);
  }
  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  return accum / rep;
}


int main(){
    
    printf("n\t array_dijkstra\t heap_dijkstra\n");
    printf("\n");
    for (size_t i=1; i< (1<<13) ; i*=2){
        printf("%ld\t",i);
        // TEST ARRAY IMPLEMENTATION
        graph_type *G1 = build_graph(i);
        add_edges(G1,0.5);
        printf("%f\t",test(dijkstra,G1,0));
        delete_graph(G1);

        // TEST HEAP IMPLEMENTATION
        graph_type *G2 = build_graph(i);
        add_edges(G2,0.5);
        printf("%f\n",test(heap_dijkstra,G2,0));
        delete_graph(G2);
        
    }
    
    
    return 0;
}