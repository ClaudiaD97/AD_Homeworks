#include "dijkstra.h"

int is_empty(queue_type* Q){
    if (Q->size == 0){
        return 1;
    } else {
        return 0;
    }
}

queue_type *build_queue(graph_type* G){
    queue_type *tmp = (queue_type *)malloc(sizeof(queue_type));

    tmp->nodes = G->nodes; // i'm not creating a copy
    tmp->size = G->n;
    tmp->max_size = G->n; // I don't need more space

    return tmp;
}

node_type *extract_queue_min(queue_type *Q){
    //find the min, swap with last node, decrease size, return pointer
    node_type *tmp = Q->nodes;
    for (size_t i=0; i<Q->size; ++i){
        if ((Q->nodes+i)->d < tmp->d){
            tmp = Q->nodes+i;
        }
    }
    swap_nodes(tmp,Q->nodes+Q->size);
    Q->size = Q->size-1;
    return Q->nodes+Q->size;
}

void delete_queue(queue_type *Q){
    free(Q);
}

// DIJKSTRA


void init_sssp(graph_type *g){
    for (size_t i=0; i<g->n; ++i){
        float max_distance = 2*(g->n);
        ((g->adj_list+i)->node)->d = max_distance;
        // already NULL but to be sure
        ((g->adj_list+i)->node)->pred = NULL;
    }
}



void relax(node_type *node, node_type *neigh, float weight){
    if (node->d + weight < neigh->d){
        neigh->d = node->d + weight;
        neigh->pred = node;
    }
}

void dijkstra(graph_type *g, unsigned int s){
    init_sssp(g);
    ((g->nodes)+s)->d = 0;

    queue_type *q = build_queue(g);
    
    while (!is_empty(q)){
        node_type *u = extract_queue_min(q);

        list_type *tmp = (g->adj_list);
        while(tmp->node!=u){
            tmp = tmp+1;
        }
    
        //for each key-weight in the list of u
        while (tmp->next!=NULL){
            relax(u,(tmp->next)->node,(tmp->next)->weight);
            tmp = tmp->next;
        }

    }
    delete_queue(q);
}

// needed to build the heap
int node_leq(void * a, void *b){
    if (((node_type *)a)->d <= ((node_type *)b)->d){
        return 1;
    } else {
        return 0;
    }
}


void heap_dijkstra(graph_type *g, unsigned int s){
    init_sssp(g);
    ((g->nodes)+s)->d = 0;

    //build heap
    binheap_type *h = build_heap((void *)g->nodes,g->n,g->n,sizeof(node_type),node_leq);
    
    while (!is_heap_empty(h)){
        node_type *u = extract_min(h);

        //tmp at the beginning of the list with node u
        list_type *tmp = (g->adj_list);
        while(tmp->node!=u){
            tmp = tmp+1;
        }
        
        //for each key-weight in the list of u
        while (tmp->next!=NULL){
            relax(u,(tmp->next)->node,(tmp->next)->weight);
            tmp = tmp->next;
        }

    }
}