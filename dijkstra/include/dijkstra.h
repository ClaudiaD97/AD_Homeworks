#ifndef __DIJKSTRA__
#define __DIJKSTRA__

#include "node.h"
#include "binheap.h"

#include <stdio.h> 
#include <stdlib.h> 

/** @struct queue node
 *  @brief Try to implement the priority queue with a liked list
 */
typedef struct queue_type {
    node_type *nodes; //array of nodes
    size_t size;
    size_t max_size; 
} queue_type;

int is_empty(queue_type* Q);

queue_type *build_queue(graph_type* G);

node_type *extract_queue_min(queue_type *Q);

// DIJKSTRA


void init_sssp(graph_type *g);

void relax(node_type *node, node_type *neigh, float weight);

void dijkstra(graph_type *g, unsigned int s);

// needed to build the heap
int node_leq(void * a, void *b);

void heap_dijkstra(graph_type *g, unsigned int s);


#endif