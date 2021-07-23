#include "./BFS_DFS.h"
#include "./FKnapscak.h"

#define LINE printf("\n");

int main()
{
    G *g = graph_init(6);
    // int a = 4

    //    2---1
    //    |   |
    //    3---0
    //    |
    //    4---5

    LINE;
    printf("    2---1\n");
    printf("    |   |\n");
    printf("    3---0\n");
    printf("    |    \n");
    printf("    4---5\n");
    LINE;


    add_edge(g, 0, 1, 0);   add_edge(g, 2, 1, 0);   
    add_edge(g, 2, 3, 0);   add_edge(g, 0, 3, 0);   
    add_edge(g, 4, 3, 0);   add_edge(g, 4, 5, 0);

    graph_print(g); LINE;

    printf("DFS: "); dfs(g,0);  LINE;
    printf("BFS: "); bfs(g,0);  LINE;


    free(g);


    return 0;
}