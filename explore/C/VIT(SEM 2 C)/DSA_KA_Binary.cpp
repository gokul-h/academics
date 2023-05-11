#include<iostream>
int main(){
std::cout<<"Hello world";
int primes[25]=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97],num;
std::cin>>num;
for (int i=0;i<strlen(primes);i++){
    if (num==prime[i]){
        std::cout<<primes[i];
    }
}
return 0;
}
