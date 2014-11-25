#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int Months;
  double dollarsContributedSpent;
  double rateOfReturns;
};
typedef struct _retire_info retire_info;

double monthChange(double rateOfReturns, double contribution, double initial){
  double interest = initial * rateOfReturns;
  double newTotal = initial + interest + contribution;
  return newTotal;
}

void retirement (int startAge,
		 double initial,
		 retire_info working,
		 retire_info retired){
  int years;
  int remainingMonths;
  for (int i=1; i < working.Months+1; i++){
    years = (startAge +(i-1))/12;
    remainingMonths = (startAge +(i-1)) % 12;
    printf("Age %3d month %2d you have $%.2f\n",years,remainingMonths,initial);
    initial = monthChange(working.rateOfReturns, working.dollarsContributedSpent, initial);
  }
  startAge = years*12+remainingMonths+1;
  for (int i=1; i < retired.Months+1; i++){
    years = (startAge +(i-1))/12;
    remainingMonths = (startAge +(i-1)) % 12;
    printf("Age %3d month %2d you have $%.2f\n",years,remainingMonths,initial);
    initial = monthChange(retired.rateOfReturns, retired.dollarsContributedSpent, initial);
  }
  return;
}

int main(void){
  retire_info working;
  working.Months = 489;
  working.dollarsContributedSpent = 1000;
  working.rateOfReturns = 0.045/12;
  retire_info retired;
  retired.Months = 384;
  retired.dollarsContributedSpent = -4000;
  retired.rateOfReturns = 0.01/12;
  int startAge = 327;
  double initial = 21345;
  retirement(startAge, initial, working, retired);
  return EXIT_SUCCESS;
}
