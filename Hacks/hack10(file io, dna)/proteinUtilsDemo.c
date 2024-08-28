/**
 * This is a program that demonstrates the usage
 * of the the protein utility library.  You can
 * provide an RNA trigram as a command line argument
 * and the corresponding protein will be printed.
 */
#include <stdlib.h>
#include <stdio.h>

#include "protein_utils.h"

int main(int argc, char **argv) {

  if(argc != 2) {
    fprintf(stderr, "Usage: %s RNA\n", argv[0]);
    exit(1);
  }

  char prot = rnaToProtein(argv[1]);

  printf("%s -> %c\n", argv[1], prot);

  return 0;
}
