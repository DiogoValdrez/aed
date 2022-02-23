#include "file.h"

graph* read( char *file_name )
{
    int i, V, E;
    graph *Graph;
    edge Edge;

    FILE *fp = fopen(file_name , "r" );


    fscanf(fp, "%d", &V );
    Graph = newG(V);

    fscanf(fp, "%d", &E );

    for(i=0; i<E; i++) {
        fscanf( fp, "%d %d %d", &(Edge.ini), &(Edge.fin), &(Edge.peso));
        AddG(Graph, &Edge);
    }
    fclose(fp);
    return Graph;
}

void write(char *file_name, graph *Graph)
{
    char* extra;
    extra = &file_name[strlen(file_name)-4];
    *extra = '\0';
    strcat(file_name, "ladj");

    FILE *fp=fopen(file_name, "w");

    printG(Graph, fp);

    fclose(fp);
    freeG (Graph);
    return;
    }
