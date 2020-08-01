#include<math.h>
#include<iostream>

using namespace std; 

#define FNF(x) (x*x*x - 3*x*x + 9*x - 8)
#define FNG(x) (3*x*x - 6*x + 9) //fn'
#define limit 0.000001

int main(void){
    double x,xn;
    int k;

    //FNF(x) (x*x*x - 3*x*x + 9*x - 8)の根をニュートン法で求める
    //最初のxの値を入力する
    cin>>x;

    k=1;
    //回数、近似値、前の近似値との差
    /*********************************
     * 接線を求めて接線とx軸との交点を見つける
     * そして、新たな交点のx成分を元にまた同様のことを繰り返す
     *********************************/
    cout<<"count \t approximation \t approximation dif"<<endl;
    cout<<"1 \t"<<x<<endl;
    while(1){
        k=k+1;
        //漸化式
        xn=x-FNF(x)/FNG(x);
        cout<<k<<"\t"<<xn<<"\t"<<xn-x<<endl;
        if(fabs(xn-x)<limit){
            break;
        }
        x=xn;
    }

    cout<<"収束値="<<xn<<endl;
}

