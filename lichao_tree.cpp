/*
Maximum Li Chao tree implementation
This tree support 2 function
1)Addline(line) -> add line(mx+c) in set
2)Query(a) -> Answer maximum value at x=a
*/
#include<bits/stdc++.h>

#define int long long

using namespace std;

struct line{
    int m,c;

    line(){
        m=0;
        c=0;
    }

    line(int mm,int cc){
        m=mm;
        c=cc;
    }

    int cal(int x){
        return m*x+c;
    }
};

line seg[200005];

void addline(int l,int r,int i,line nline){
    if(l==r){
        if(nline.cal(l)>seg[i].cal(l))
            seg[i]=nline;
        return;
    }
    int mid=(l+r)/2;
    if(seg[i].m>nline.m)
        swap(seg[i],nline);
    //nline=larger slope one
    if(nline.cal(mid)>seg[i].cal(mid)){
        swap(seg[i],nline);
        addline(l,mid,2*i,nline);
    }
    else
        addline(mid+1,r,2*i+1,nline);
}

int query(int l,int r,int i,int x){
    if(l==r)
        return seg[i].cal(x);
    int m=(l+r)/2;
    if(x<=m)
        return max(seg[i].cal(x),query(l,m,2*i,x));
    else
        return max(seg[i].cal(x),query(m+1,r,2*i+1,x));
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
