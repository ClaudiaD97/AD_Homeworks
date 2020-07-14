#ifndef __NODE__
#define __NODE__

#include <stdio.h>

// NODE

/** @struct node_type
 *  @brief A class to represent nodes of a graph.
 */
typedef struct node_type {
    unsigned int key; // an identifier
    float d; // the distance
    struct node_type *pred; // pointer to predecessor
} node_type;

node_type *build_node(unsigned int key, float d, node_type *pred);
void delete_node(node_type * node);
node_type *copy_node(node_type *node);
//just to be faster
node_type *build_many_nodes(size_t n);
void swap_nodes(node_type *node1, node_type *node2);


// LIST

/** @struct list_type
 *  @brief A class to represent a list of nodes.
 * Will be used to represent the neighbours of each node 
 * useful to build adjacency list
 */

typedef struct list_type {
    node_type * node;
    //unsigned int node_key;
    float weight;
    struct list_type *next;
} list_type;


list_type *build_empty_adj_list(node_type *nodes, size_t n);
void add_element_to_list(list_type *list, node_type *node, float weight);
void delete_list(list_type *list);

// GRAPH

/** @struct graph_type
 *  @brief A class to represent graphs.
 */

typedef struct graph_type {
    unsigned int n; //number of nodes
    node_type * nodes;
    list_type *adj_list;
} graph_type;

graph_type * build_graph(size_t n);
void single_edge(graph_type *g, unsigned int a, unsigned int b, float weight);
void add_edges(graph_type *g, float prob);
void delete_graph(graph_type *G);

#endif