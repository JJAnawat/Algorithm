/*
given an array size n
ask q queries
each queries ask sum from 1-x
*/
#include<bits/stdc++.h>

using namespace std;

long long fw[100005];

void upd(int x,int val){
    for(int i=x;i<=100000;i+=i&-i)
        fw[i]+=val;
}

long long qr(int x){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1,x;i<=n;i++){
        cin >> x;
        upd(i,x);
    }

    int q,x;
    cin >> q;
    while(q--){
        cin >> x;
        cout << qr(x) << '\n';
    }
}
