/*
given an array of size n
ask q queries
in each queries have 2 operation
1) update ar[l]-ar[r]+=val
2) ask ar[l]+ar[l+1]+...+ar[r-1]+ar[r]
*/
#include<bits/stdc++.h>

using namespace std;

int ar[100005];
long long seg[1<<18],lz[1<<18];

void pushlz(int l,int r,int i){
    if(!lz[i])
        return;
    seg[i]+=lz[i]*(r-l+1);
    if(l!=r){
        lz[2*i]+=lz[i];
        lz[2*i+1]+=lz[i];
    }
    lz[i]=0;
}

void build(int l,int r,int i){
    if(l==r){
        seg[i]=ar[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=seg[2*i]+seg[2*i+1];
}

void upd(int l,int r,int i,int x,int y,int val){
    pushlz(l,r,i);
    if(l>y||r<x)
        return;
    if(l>=x&&r<=y){
        lz[i]+=val;
        pushlz(l,r,i);
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,y,val);
    upd(m+1,r,2*i+1,x,y,val);
    seg[i]=seg[2*i]+seg[2*i+1];
}

long long qr(int l,int r,int i,int x,int y){
    pushlz(l,r,i);
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return qr(l,m,2*i,x,y)+qr(m+1,r,2*i+1,x,y);
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
    int op,l,r,v;
    while(q--){
        cin >> op >> l >> r;
        if(op==1){
            cin >> v;
            upd(1,n,1,l,r,v);
        }
        else{
            cout << qr(1,n,1,l,r) << '\n';
        }
    }
}

