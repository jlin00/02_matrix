#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *identity;
  struct matrix *rand;

  printf("\nEDGES MATRIX\n");
  edges = new_matrix(4, 4);
  add_edge(edges, 1, 2, 3, 4, 5, 6);
  print_matrix(edges);

  printf("\nIDENTITY MATRIX\n");
  identity = new_matrix(4, 4);
  ident(identity);
  print_matrix(identity);

  //printf("\nMULTIPLYING BY IDENT\n");
  //matrix_mult(identity, edges);
  //print_matrix(edges);

  printf("\nRANDOM MATRIX\n");
  rand = new_matrix(4, 4);
  add_edge(rand, 3, 4, 8, 1, 0, 7);
  add_edge(rand, 1, 0, 7, 9, 0, 7);
  //add_edge(rand, 1, 0, 0, 0, 0, 0);
  print_matrix(rand);

  printf("\nMULTIPLYING BY RAND\n");
  matrix_mult(rand, edges);
  print_matrix(edges);




  free_matrix( edges );
}
