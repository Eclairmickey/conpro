#include<iostream>

void decompositPrime(long long int n){
  long long int a=2;
  while(n>=a*a){
    if(n%a==0){
      std::cout<<a<<" * ";
      n/=a;
    }else{
      a++;
    }
  }
  std::cout<<n<<std::endl;
}

int main(){
    long long int num;
    std::cin>>num;

    decompositPrime(num);
    return 0;
}