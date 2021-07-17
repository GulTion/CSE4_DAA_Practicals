#include "./BFS_DFS.h"


int main()
{
    G *g = graph_init(6);
    add_edge(g, 0, 1, 0);
    add_edge(g, 2, 1, 0);
    add_edge(g, 2, 2, 0);
    add_edge(g, 0, 3, 0);
    add_edge(g, 4, 3, 0);
    add_edge(g, 4, 5, 0);


    // 2---1
    // |   |
    // 3---0
    // |
    // 4---5

    dfs(g, 0);

    return 0;
}