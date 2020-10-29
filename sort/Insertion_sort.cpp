#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

vector<int> Insertion_sort(vector<int> vec){
    int n=vec.size();
    int mem,j;
    //2つ目の要素から1つずつ参照
    for(int i=1;i<n;i++){
        mem=vec[i];
        j=i-1;
        //参照した要素以下であるなら
        while(j>=0 && vec[j]>mem){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=mem;
        for(int k=0;k<n;k++) cout<<vec[k]<<" ";
        cout<<"\n";
    }
    return vec;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    v=Insertion_sort(v);
    for(int k=0;k<n;k++) cout<<v[k]<<" ";
    cout<<"\n";
}