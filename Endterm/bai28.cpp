#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000],bMark[1000],res=0,tong=0;
void Try(int x){
    if(tong==k){
        res++;
        return;
    }
    for(int i=x;i<n;i++){
        if(tong+a[i]<=k){
            tong+=a[i];
            Try(i);
            tong-=a[i];
        }
        
    }

    return;
}
int main(int argc, char const *argv[])
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Try(0);
    cout<< res;
    return 0;
}
