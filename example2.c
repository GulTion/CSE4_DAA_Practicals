#include "./BFS_DFS.h"

#define LINE printf("\n");

int main()
{

    //      8---6   7
    //          |   |
    //      0---1---5
    //      |   |
    //      2   3---4

    LINE;
    printf("    8---6   7\n");
    printf("        |   |\n");
    printf("    0---1---5\n");
    printf("    |   |    \n");
    printf("    2   3---4\n");
    LINE;
// ---------------------------------------------

    G *g = graph_init(9);


    add_edge(g, 0, 1, 0);   add_edge(g, 0, 2, 0);
    add_edge(g, 1, 3, 0);   add_edge(g, 4, 3, 0);   
    add_edge(g, 1, 5, 0);   add_edge(g, 7, 5, 0);
    add_edge(g, 1, 6, 0);   add_edge(g, 8, 6, 0);

    graph_print(g); LINE;

    printf("DFS: "); dfs(g,0);  LINE;
    printf("BFS: "); bfs(g,0);  LINE;


    free(g);


    return 0;
}