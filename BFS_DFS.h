#include "./Graph.h"

void bfs(G *g, int src)
{
    L *queue = list_init();
    int *visted = (int *)malloc(g->V * sizeof(int));

    for (int i = 0; i < g->V; i++)
        visted[i] = 0;

    visted[src] = 1;
    push_back(queue, src);

    while (queue->size)
    {
        int t = pop_front(queue);
        printf("%d ", t);
        N * _p = g->list[t].head;
        while (_p != NULL)
        {
            // int node = pop_front(&g->list[t]);
            int node = _p->data;

            if (!visted[node])
            {
                visted[node] = 1;
                push_back(queue, node);
            }
            _p = _p->next;
        }
    }
    free(queue);
    free(visted);
}

void dfs_handler(G *g, int src, int *visited)
{
    visited[src] = 1;
    printf("%d ", src);
    N * _p=g->list[src].head;
    while (_p != NULL)
    {
        // int node = pop_front(&g->list[src]);
        int node = _p->data;
        if (!visited[node])
            dfs_handler(g, node, visited);
        _p = _p->next;
    }
}

void dfs(G *g, int src)
{
    int *visited = (int *)malloc(g->V * sizeof(int));
    
    for (int i = 0; i < g->V; i++) visited[i] = 0;

    dfs_handler(g, src, visited);
    free(visited);
}
