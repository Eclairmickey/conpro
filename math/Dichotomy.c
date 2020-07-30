#include<stdio.h>

#define FNF(x) (x*x*x-3*x*x+9*x-8)
#define limit 0.000001

int main(){
    double a,b,c;
    int k;
    char z,zz;
    while(1){
        printf("f(a)*f(b)<0となるa,b");
        //区間の始点
        printf("first section a= ?");
        scanf("%lf%c",&a,&zz);
        //区間の終点
        printf("second section b= ?");
        scanf("%lf%c",&b,&zz);
        //チェック
        printf("check (y/n)");
        scanf("%c%c",&z,&zz);

        if(z=='n') continue;
        if((z=='y')&&(a<b)&&(FNF(a)*FNF(b)<0)) break;
        else{
            printf("failed");
            scanf("%c",&z); continue;
        }
    }
    k=0;
    printf("count \t A \t B \t B-A\n");
    while(b-a>=limit){
        k=k+1;
        printf("%4d \t %8.5lf \t %8.5lf \t %8.5lf\n",k,a,b,b-a);
        c=(a+b)/2.0;
        //a,bどちらの更新をするか指定
        if(FNF(a)*FNF(c)>0){
            a=c;
        }else{
            b=c;
        }
    }

    printf("ans==%10.6lf\n",(a+b)/2.0);
    return 0;
}