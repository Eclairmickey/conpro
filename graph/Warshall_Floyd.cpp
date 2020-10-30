#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<vector<int>> Washall_Floyd(vector<vector<int>> d,int n){
    for(int k=0;k<n;k++){ //経由する点
        for(int i=0;i<n;i++){ //始点
            for(int j=0;j<n;j++){ //終点
                //現在の最短、頂点kのみを経由していい場合
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    /***
    cout<<"step:"<<k<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    ***/
    return d;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }

    dist = Washall_Floyd(dist,n);
    cout<<"Ans"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}