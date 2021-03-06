#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = 255;
  c.green = 192;
  c.blue = 203;

  clear_screen(s);

  struct matrix *m1;
  struct matrix *m2;
  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 4);

  printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix(m2);

  printf("\nTesting ident. m1 = \n");
  ident(m1);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 = \n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  printf("\nTesting Matrix mult. m1 = \n");
  m1 = new_matrix(4, 4);
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  print_matrix(m1);

  printf("\nTesting Matrix mult. m1 * m2 = \n");
  matrix_mult(m1, m2);
  print_matrix(m2);

  free_matrix(m1);
  free_matrix(m2);

  //code to draw a picture
  struct matrix *edges;
  edges = new_matrix(4, 4);
  FILE *fp = fopen("coord.txt", "r");
  char data[50];
  int x = 0;
  int y = 0;
  while (fgets(data, 50, fp)){
    sscanf(data, "%d %d", &x, &y);
    add_point(edges, XRES - x, YRES - y, 0);
  }
  fclose(fp);
  draw_lines(edges, s, c);
  free_matrix(edges);

  display(s);
  save_extension(s, "matrix.png");
}
