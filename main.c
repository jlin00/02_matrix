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

  printf("\nEDGES MATRIX (1, 2, 3), (4, 5, 6)\n");
  edges = new_matrix(4, 4);
  add_edge(edges, 1, 2, 3, 4, 5, 6);
  print_matrix(edges);

  printf("\n4x4 IDENTITY MATRIX\n");
  identity = new_matrix(4, 4);
  ident(identity);
  print_matrix(identity);

  printf("\nMULTIPLYING IDENT BY EDGES\n");
  matrix_mult(identity, edges);
  print_matrix(edges);

  printf("\nRANDOM MATRIX (3, 4, 8), (1, 0, 7), (1, 0, 7), (9, 1, 2)\n");
  rand = new_matrix(4, 4);
  add_edge(rand, 3, 4, 8, 1, 0, 7);
  add_edge(rand, 1, 0, 7, 9, 1, 2);
  print_matrix(rand);

  printf("\nMULTIPLYING RAND BY EDGES\n");
  matrix_mult(rand, edges);
  print_matrix(edges);

  printf("\nADDING MORE EDGES (3, 3, 3), (4, 6, 8), (0, 0, 0), (9, 9, 9), (8, 8, 8), (1, 0, 2)\n");
  add_edge(edges, 3, 3, 3, 4, 6, 8);
  add_edge(edges, 0, 0, 0, 9, 9, 9);
  add_edge(edges, 8, 8, 8, 1, 0, 2);
  print_matrix(edges);

  free_matrix(edges);
  free_matrix(identity);
  free_matrix(rand);


}
