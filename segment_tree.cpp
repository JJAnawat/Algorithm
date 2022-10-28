/*
given an array of size n
ask q queries
in each queries have 2 operation
1) update ar[x]+=val
2) ask min(ar[l],ar[l+1],...,ar[r-1],ar[r])
*/
#include<bits/stdc++.h>

using namespace std;

int ar[100005];
int seg[1<<18];

void build(int l,int r,int i){
    if(l==r){
        seg[i]=ar[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=min(seg[2*i],seg[2*i+1]);
}

void upd(int l,int r,int i,int x,int val){
    if(l>x||r<x)
        return;
    if(l==r){
        seg[i]+=val;
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,val);
    upd(m+1,r,2*i+1,x,val);
    seg[i]=min(seg[2*i],seg[2*i+1]);
}

int qr(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return INT_MAX;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return min(qr(l,m,2*i,x,y),qr(m+1,r,2*i+1,x,y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1,n,1);

    int q;
    cin >> q;
    int op,a,b;
    while(q--){
        cin >> op >> a >> b;
        if(op==1){
            upd(1,n,1,a,b);
        }
        else{
            cout << qr(1,n,1,a,b) << "\n";
        }
    }
}
