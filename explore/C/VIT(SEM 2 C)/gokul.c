#include <stdio.h>
#include<time.h>
#include<math.h>

int main(){
for(int j = 0;j<100000;j++)
    {
        int a = 100000;
        int array[100000];
        for (int i=0;i<a;i++)
        {
            array[i] = i+1;
        }
        int sum_1 = 0;
        for (int i;i<a;i++)
        {
            sum_1 = sum_1 + array[i];
        }
    }
return 0;
}