#include<iostream>
#include<gmpxx.h>
using namespace std;

mpz_class Euclid(mpz_class a,mpz_class b){
    mpz_class temp,r,jud;
    if(b>a){
        swap(a,b);
    }


    if(a%b!=0){
        cout<<"a\tb\t余り\n";
        while(a%b!=0){
            r=a%b;
            cout<<a<<"\t"<<b<<"\t"<<r<<endl;
            cout<<"-------------------------"<<endl;
            a=b;
            b=r;
        }
    }else{
        cout<<"a\tb\t余り\n";
        cout<<"-------------------------"<<endl;
        cout<<a<<"\t"<<b<<"\t"<<a%b<<endl;
    }
    return b;
}

int main(){
    mpz_class a,b;
    cout<<"2つの数字を入力して下さい"<<endl;
    cin>>a>>b;
    

    cout<<"最大公約数"<<endl;
    cout<<Euclid(a,b)<<endl;

    return 0;
}

