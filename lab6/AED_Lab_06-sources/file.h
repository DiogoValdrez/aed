#ifndef File
#define File 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataStruct.h"

graph* read( char *file_name );
void write(char *file_name, graph *Graph);

#endif