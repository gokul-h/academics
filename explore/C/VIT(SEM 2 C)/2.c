// ABC company Ltd. is interested to computerize the pay calculation of their employee
// in the form of Basic Pay, Dearness Allowance (DA) and House Rent Allowance (HRA).
// DA and HRA are calculated as certain % of Basic pay(For example, DA is 80% of Basic
// Pay, and HRA is 30% of Basic pay). They have the deduction in the salary as
// PF which is 12% of Basic pay. Propose a computerized solution for the above said problem.
// Input    : Basic Pay
// Process :  Calculate Salary
// ( Basic Pay  + ( Basic Pay * 0.8) +  ( Basic Pay * 0.3 - ( Basic Pay * 0.12)
//                         -----------allowances --------------     --- deductions----
//   Output  : Salary
#include<stdio.h>
int main(){
    float Basic_Pay ,Salary;
    scanf("%f",&Basic_Pay); 
    Salary = (Basic_Pay  + ( Basic_Pay * 0.8) +  ( Basic_Pay * 0.3) - ( Basic_Pay * 0.12));
    printf("Salary:-%f",Salary);
    return 0;
}


