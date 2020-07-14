#include <binheap.h>
#include <string.h>
#include <stdio.h>

#define PARENT(node) ((node-1)/2)
#define LEFT_CHILD(node) (2*(node)+1)
#define RIGHT_CHILD(node) (2*(node+1))

#define VALID_NODE(H, node) ((H)->num_of_elem>(node))

#define ADDR(H, node) ((H)->A+(node)*(H)->key_size) //pointer to value stored in the node
#define INDEX_OF(H,addr) (((addr)-((H)->A))/((H)->key_size))

int is_heap_empty(const binheap_type *H)
{
    if (H->num_of_elem ==0){
        return 1;
    } else {
        return 0;
    }
}

// here I don't want to swap values in A 
void swap_keys(binheap_type *H,unsigned int n_a, unsigned int n_b){
    //instead of swapping in A I swap in key_pos
    unsigned int n_a_position = (H->key_pos)[n_a];
    unsigned int n_b_position = (H->key_pos)[n_b];

    // modify key_pos
    (H->key_pos)[n_a] = n_b_position;
    (H->key_pos)[n_b] = n_b_position;
    //modify rev_pos
    H->rev_pos[n_a_position] = n_b;
    H->rev_pos[n_b_position] = n_a;

}

void heapify(binheap_type *H, unsigned int node){
    unsigned int dst_node=node;
    // to check child I work on key_pos, so I need the position of the node
    unsigned int node_position;
    unsigned int child_position;

    do {
        node = dst_node;
        node_position = H->key_pos[node];

        child_position = RIGHT_CHILD(node_position);
        //but where I chech ADDR I need the node
        if (VALID_NODE(H,child_position) &&
                         H->leq(ADDR(H,H->rev_pos[child_position]),ADDR(H,node))){
            dst_node = H->rev_pos[child_position];
        }
        child_position = LEFT_CHILD(node_position);
        if (VALID_NODE(H,child_position) &&
                         H->leq(ADDR(H,H->rev_pos[child_position]),ADDR(H,node))){
            dst_node = H->rev_pos[child_position];
        }

    // if the minimum is not in node
        if (dst_node!=node){
            swap_keys(H,dst_node,node);
        }
    } while(dst_node!=node);
}

const void *find_the_max(void *A,const unsigned int num_of_elem,const size_t key_size, total_order_type leq){
    if (num_of_elem==0)
        return NULL;
    
    const void *max_value = A;
    // for all values in A
    for (const void *addr=A+key_size; addr!=A+(num_of_elem-1)*key_size;addr+=key_size){
        // if addr > max_value
        if (!leq(addr,max_value)){
            max_value=addr;
        }
    }
    return max_value;
}

const void *min_value(const binheap_type *H)
{
    if (is_heap_empty(H)){
        return NULL;
    }
    // the minimum is stored in the root a.k.a. A[0]
    return ADDR(H,0);    
}

const void *extract_min(binheap_type *H)
{
    if (is_heap_empty(H))
        return NULL;

    // no pass position but node in that position
    swap_keys(H,H->rev_pos[0],H->rev_pos[H->num_of_elem-1]);
    
    H->num_of_elem--;    
    // fix the heap property on the full heap
    heapify(H,0);
    
    //also here no position
    return ADDR(H,H->rev_pos[H->num_of_elem]);
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    binheap_type *H = (binheap_type *)malloc(sizeof(binheap_type));

    H->A=A;
    //at the beginning both ordered
    H->key_pos = (unsigned int *)malloc(max_size*sizeof(unsigned int));
    H->rev_pos = (unsigned int *)malloc(max_size*sizeof(unsigned int));

    for (size_t i=0; i<max_size; ++i){
        H->key_pos[i]=i;
        H->rev_pos[i]=i;   
    }
    H->num_of_elem=num_of_elem;
    H->max_size=max_size;
    H->key_size=key_size;
    H->leq=leq;
    H->max_order_value=malloc(key_size); //no typecast because void ptr

    if (num_of_elem==0){
        return H;
    }

    // pointer to a value which is the max one we want to store
    const void *value = find_the_max(A,num_of_elem,key_size,leq);

    memcpy(H->max_order_value,value,key_size);

    // fix the heap property
    for (unsigned int i=num_of_elem/2;i>=0; i--){
        heapify(H,H->rev_pos[i]);
    }
    // loop ends when i=0, I need one more call.
    // why don't change the condition in i>=0?
    //heapify(H,0);
    return H;
}

void delete_heap(binheap_type *H)
{
    free(H->max_order_value);
    free(H);
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    unsigned int node_idx = INDEX_OF(H,node);
    //need also position
    unsigned int node_position = H->key_pos[node_idx];

    // if node doesn't belong to H or value >= node_value
    if (!VALID_NODE(H,node_idx) || !(H->leq(value,node))){
        return NULL;
    }

    memcpy(node,value,H->key_size);
    
    //here I need to use position to get the parent and then get the node index
    unsigned int parent_position = PARENT(node_position);
    unsigned int parent_idx = H->rev_pos[parent_position];
    void *parent = ADDR(H,parent_idx);

    // while i reach the root and the value is smaller than the parent one
    while ((node_position!=0) && (!H->leq(parent,node))){
        swap_keys(H,parent_idx,node_idx);
        
       node_position = H->key_pos[node_idx];
       parent_idx = H->rev_pos[PARENT(node_position)];
       parent = ADDR(H,parent_idx);
    }

    return node;
}

const void *insert_value(binheap_type *H, const void *value)
{   
    //if heap already full
    if (H->max_size == H->num_of_elem)
        return NULL;

    //if empty or value greater then max value
    if (H->num_of_elem==0 || !H->leq(value,H->max_order_value)){
        memcpy(H->max_order_value,value,H->key_size);
    }

    //get new node position
    // not num_elem +1 because I've not incremented it yet
    void *new_node_addr= ADDR(H,H->rev_pos[H->num_of_elem]);
    memcpy(new_node_addr,H->max_order_value,H->key_size);

    // increase by 1 the size of the heap
    H->num_of_elem++;

    //decrease key of the new node
    return decrease_key(H,new_node_addr,value);
}

void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
    // store the index of the left-most node of the next level
    unsigned int next_level_node = 1;

    for (unsigned int node=0; node < (H->num_of_elem); node++){
        if (node==next_level_node){
            printf("\n");
            next_level_node=LEFT_CHILD(node);
        } else {
            printf("\t");
        }
    
        key_printer(ADDR(H,H->rev_pos[node]));
    }
    printf("\n");
    
}