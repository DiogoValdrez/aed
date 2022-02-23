#ifndef DataStruct
#define DataStruct

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct _edge{
    int peso;
    int ini;
    int fin;
}edge;
typedef struct _graph{
    int V;
    //int E;
    LinkedList **adj;
}graph;
typedef struct _itemG{
  int peso;
  int dest;
} itemG;


graph* newG(int V);
void AddG ( graph* , edge* );
void freeG (graph*);
void printG ( graph* , FILE*);
void printRec(LinkedList *, FILE *);

#endif