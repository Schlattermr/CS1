#include <stdlib.h>

#include "student.h"

/**
 * Student structure demonstration program
 */
int main(int argc, char **argv) {
  Student *me = createStudent("Matt", "Schlatter", 42880117, "05/26/2004");
  printStudent(me);
}

