/**
 * Author: Matt Schlatter
 * Date: 2022/09/06
 *
 * This program computes income taxes based on adjusted
 * gross income and a child tax credit.
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  double agi = 0.0;
  char c = 'N';
  double tax = 0.0;
  double childCredit = 0.0;
  double totalTax = 0.0;
  int numChildren = 0;
  const double givenKidReduction = 2000.0;

  printf("Please enter your adjusted gross income (AGI): \n");
  scanf("%lf", &agi);
  getchar();

  printf("Do you have any children? (Y) or (N)? \n");
  c = getchar();

  if(c == 'y' || c == 'Y') {
    printf("How many children do you have? \n");
    scanf("%d", &numChildren);
  }

  childCredit = numChildren * givenKidReduction;

  if((agi > 0) && (agi < 19901)) {
    tax = (agi * 0.1);
  } else if((agi > 19900) && (agi < 81051)) {
    tax = 1990 + ((agi - 19900) * 0.12);
  } else if((agi > 81050) && (agi < 172751)) {
    tax = 9328 + ((agi - 81050) * 0.22);
  } else if((agi > 172750) && (agi < 329851)) {
    tax = 29502 + ((agi - 172750) * 0.24);
  } else if((agi > 329850) && (agi < 418851)) {
    tax = 67206 + ((agi - 329850) * 0.32);
  } else if((agi > 418850) && (agi < 628301)) {
    tax = 95686 + ((agi - 418850) * 0.35);
  } else {
    tax = 168933.50 + ((agi - 628300) * 0.37);
  }

  totalTax = ((tax) - (childCredit));

  if(totalTax < 0) {
    totalTax = 0.0;
  }

  printf("AGI:          $%10.2f\n", agi);
  printf("Tax:          $%10.2f\n", tax);
  printf("Child Credit: $%10.2f\n", childCredit);
  printf("Total Tax:    $%10.2f\n", totalTax);

  return 0;
}