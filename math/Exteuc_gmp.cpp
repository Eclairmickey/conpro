#include<iostream>
#include<gmpxx.h>
#include<tuple>
using namespace std;

tuple<mpz_class,mpz_class,mpz_class> Extgcd(mpz_class a,mpz_class b,mpz_class x,mpz_class y,mpz_class d){
    mpz_class u,v,q,tmp;
    x=1; y=0; u=0; v=1;
    cout<<"a \t x \t b\t y \n";

    while(b>0){
        q=a/b;
        //xを求める
        tmp=u;
        u=x - q*u;
        x=tmp;
        //yを求める
        tmp=v;
        v=y-q*v;
        y=tmp;
        //gcd(a,b)を求める
        tmp=b;
        b=a-q*b;
        a=tmp;

        //途中結果表示
        cout<<"-----------------------------------\n";
        cout<<a<<"\t"<<x<<"\t"<<b<<"\t"<<y<<endl;

    }
    d=a;

    return forward_as_tuple(x,y,d);
}

int main(){
    mpz_class a,b,x=0,y=0,d;
    cout<<"２つの数を入力して下さい\n";
    cin>>a>>b;

    tie(x,y,d)=Extgcd(a,b,x,y,d);

    cout<<"\n";
    cout<<"a \t x \t b \t y \t gcd(a,b)"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<a<<"\t"<<x<<"\t"<<b<<"\t"<<y<<"\t"<<d<<endl;

}