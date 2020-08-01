#include<iostream>
#include<math.h>

using namespace std;

#define N 8

int main(){
    int k,j,n;
    char z,zz;
    static double p,s,a[N][N+1],x[N];

    while(1){
        //行列のサイズ指定
        cout<<"input n"<<endl;
        cin>>n;

        if(n<=1 || n>=7) continue;
        //係数を入力
        cout<<"coefficient input"<<endl;

        for(k=1;k<=n;k++){
            for(j=k;j<=n+1;j++){
                cout<<"a "<<k<<" "<<j<<endl;
                cin>>a[k][j]; 
            }
        }
        cout<<"input is correct?"<<endl;
        cin>>z;
        if(z=='y') break;
    }

    //第k行を対応する対角成分で割る
    for(k=1;k<=n;k++){
        p=a[k][k];
        if(fabs(p)<1.0e-6){
            printf("Has no solution");
            exit(-1);
        }

        for(j=k;j<=n+1;j++){
            a[k][j]=a[k][j]/p;
        }
    }

    //逆進代入による計算
    for(k=n;k>=1;k--){
        s=0.0;
        //sigmaの部分
        for(j=k+1;j<=n;j++){
            s+=a[k][j]*x[j];
        }
        //a[k][n+1]は解の項
        //解の部分-sigma
        x[k]=a[k][n+1]-s;
    }

    cout<<"answer"<<endl;
    for(k=1;k<=n;k++){
        cout<<"x("<<k<<")="<<x[k]<<endl;
    }
    return 0;
}