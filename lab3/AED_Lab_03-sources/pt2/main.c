/******************************************************************************
 * (c) 2010-2019 AED Team
 * Last modified: abl 2019-03-01
 *
 * NAME
 *   main.c
 *
 * DESCRIPTION
 *   Main program for unique word finding with lists
 *
 * COMMENTS
 *   Code variant for distribution
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "words.h"

#define DIM_MAX_PALAVRA 200


/******************************************************************************
 * Usage ()
 *
 * Arguments: nomeProg - name of executable
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: message function when arguments are missing
 *****************************************************************************/

void Usage(char *nomeProg)
{
  printf("Usage: %s [filename] [arguments options]\n", nomeProg);
  exit(1);
}


/******************************************************************************
 * main ()
 *
 * Arguments: argc - number of command-line arguments
 *            argv - table of pointers for string arguments
 * Returns: int status
 * Side-Effects: none
 *
 * Description: main Program
 *****************************************************************************/

int main(int argc, char *argv[])
{
  t_lista *lp, *aux;
  int numTotalPalavras = 0;
  int numPalavrasDiferentes;
  int mode;
  char extOut[] = ".palavras";
  char *nomeFicheiroIn, *nomeFicheiroOut;
  char novaPal[DIM_MAX_PALAVRA];
  FILE *fpIn,*fpOut;

  if(argc < 3)
    Usage(argv[0]);

  nomeFicheiroIn = argv[1];
  if(strcmp(argv[2], "INICIO")){
    mode = 1;
  }else if(strcmp(argv[2], "FIM")){
    mode = 0;
  }else{
    Usage(argv[0]);
  }
  nomeFicheiroOut = (char*)malloc(sizeof(char)*(strlen(nomeFicheiroIn)+strlen(".palavras")+1));
  if(nomeFicheiroOut == NULL){
      erroMemoria("Memory allocation for nomeFicheiroOut in main" );
  }
  strcpy(nomeFicheiroOut, nomeFicheiroIn);
  strcat(nomeFicheiroOut, extOut);

  /* open input file */
  fpIn  = fopen(nomeFicheiroIn,"r");
  if(fpIn == NULL) {
    printf("ERROR cannot read input file %s\n", nomeFicheiroIn);
    exit(2);
  }
  /* read input file, build word list */
  lp = iniLista();
  while(fscanf(fpIn, "%s", novaPal) == 1) {
    lp = testaPalavra(lp, novaPal);
    numTotalPalavras++;
  }

  /* open output file */
  fpOut = fopen (nomeFicheiroOut, "w");
  if(fpOut == NULL) {
    printf("ERROR cannot write output file %s\n", nomeFicheiroOut);
    exit(3);
  }
  /* write out words to output file */
  numPalavrasDiferentes = numItensNaLista(lp);
  aux = lp; 
  if(mode){
    while(aux != NULL) {
      escreveUmaPalavra((t_palavra*) getItemLista(aux), fpOut);//! modificar aqui para não começar no primeiro
      aux = getProxElementoLista(aux, mode, fpOut);
    }
  }else if(!mode){
    getProxElementoLista(lp, mode, fpOut);
    //escreveUmaPalavra((t_palavra*) getItemLista(aux), fpOut);
  }
  

  printf("Number of words = %d, Number of different words = %d\n",
         numTotalPalavras, numPalavrasDiferentes);

  /* free allocated memory for list of words */
  if(mode){
    libertaLista(lp, libertaItem);//!if opção for normal
  }
  /* -- CLOSE ALL OPEN FILES -- */
  fclose(fpIn);
  fclose(fpOut);

  /* -- FREE ANY OTHER MEMORY YOU HAVE ALLOCATED -- */ 
  //!falta este
  free(nomeFicheiroOut);

  exit(0);
}
