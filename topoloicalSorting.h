#include "./Graph.h"
#define push(data) push_back(queue, data)
#define pop() pop_front(queue)

void topologicalSorting(G *g)
{

    int *indegree = indegreeCalculator(g); // return array

    L *queue = list_init();

    // push the vertices that have indegree 0
    loop(g->V) if (!indegree[i]) push(i);

    while (queue->size)
    {
        int node = pop();

        N *p = g->list[node].head;

        while (p != NULL)
        {

            indegree[p->data]--;
            if (!indegree[p->data])
                push(p->data);
            p = p->next;
        }
        printf("%d ", node);
    }

    free(queue);
    free(indegree);

    return;
}