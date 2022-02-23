#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataStruct.h"
#include "file.h"


int main ( int argc, char **argv )
{
  graph *Graph; 

  Graph = read(argv[1]);
  write(argv[1], Graph);
  return EXIT_SUCCESS;
}

