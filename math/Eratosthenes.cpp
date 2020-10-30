#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

typedef long long int ll;

vector<ll> Eratosthenes(const int max){
    vector<bool> IsPrime(max+1,true);

    vector<ll> P;
    for(int i=2;i<max+1;i++){
        if(IsPrime[i]){
            for (int j = 2*i; j < max+1; j+=i){
                IsPrime[j]=false;
            }
            P.emplace_back(i);
        }
    }
    return P;
}