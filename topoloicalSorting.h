#include "./Graph.h"

void topologicalSorting(G *g){
    int * indegree = indegreeCalculator(g);// return array

    L * queue = list_init();
    // push the vertices that have indegree 0
    for(int i=0;i<g->V;i++) if(indegree[i]==0) push_back(queue, i);

    while (queue->size){
        int node = pop_front(queue);
        
        N * p = g->list[node].head;

        while(p!=NULL){
            indegree[p->data]--;
            if(indegree[p->data]==0) push_back(queue, p->data);
            p=p->next;
        }
        printf("%d ", node);
    }

    
    return;
}