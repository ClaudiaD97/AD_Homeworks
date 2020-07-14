#include "../include/node.h"

#include <stdlib.h>

// NODES

node_type *build_node(unsigned int key, float d, node_type *pred){
    node_type *node = (node_type *)malloc(sizeof(node_type));
    node->key = key;
    node->d = d;
    node->pred = pred;
    return node;
}


node_type *build_many_nodes(size_t n){

    node_type *nodes = (node_type *)malloc(n*sizeof(node_type));
    for (size_t i=0; i<n; ++i){
        (nodes+i)->key = i;
        (nodes+i)->d = 0;
        (nodes+i)->pred = NULL;
    }
    return nodes;
}

node_type *copy_node(node_type *node){
    node_type *tmp = (node_type *)malloc(sizeof(node_type));
    tmp->key = node->key;
    tmp->d = node->d;
    tmp->pred = node->pred;
    return tmp;
}

void swap_nodes(node_type *node1, node_type *node2){
    node_type *tmp = copy_node(node1);
    node1 = copy_node(node2);
    node2 = copy_node(tmp);
    free(tmp);
}


void delete_node(node_type * node){
    if (node->pred != NULL){
        delete_node(node->pred);
    }
    
    free(node->pred);
}


list_type *build_empty_adj_list(node_type *nodes, size_t n){
    list_type *adj_list = (list_type *)malloc(n*sizeof(list_type));
    for (size_t i=0; i<n; ++i){
        (adj_list+i)->node = nodes+i;
        (adj_list+i)->weight = 0;
        (adj_list+i)->next = NULL;
    }
    return adj_list;
}

//error when i=0 j=4
void add_element_to_list(list_type *list, node_type *node, float weight){
    //create the new element
    list_type *new_elem = (list_type *)malloc(sizeof(list_type));
    new_elem->node = node;
    new_elem->weight = weight;
    new_elem->next = NULL;
    // add at the end of the list
    list_type *tmp = list;
    while (tmp->next!=NULL){
        tmp = tmp->next;
    }
    tmp->next = new_elem;
}

// GRAPH

graph_type * build_graph(size_t n){
    graph_type *g = (graph_type *)malloc(sizeof(graph_type));
    g->nodes = build_many_nodes(n);
    g->n = n;
    g->adj_list = build_empty_adj_list(g->nodes,n);
}


void single_edge(graph_type *g, unsigned int a, unsigned int b, float weight){
    add_element_to_list((g->adj_list)+a,g->nodes+b,weight);
}


//between 2 nodes there can be 2 edges (different directions) with different weights
void add_edges(graph_type *g, float prob){
    for (size_t i=0; i<(g->n); ++i){
        for (size_t j=0; j<(g->n); ++j){
            //add an edge with probability prob
            float r = ((float) rand() / (RAND_MAX));
            // how can I choose weight? another random in 0,1?
            // if not 0,1 can be a very huge number
            float w = ((float) rand() / (RAND_MAX));
            if (r<prob){
                add_element_to_list((g->adj_list)+i,g->nodes+j,w);
            }
        }
    }
}

void delete_graph(graph_type *G){
    free(G->nodes);
    free(G->adj_list);
    free(G);
}