/*
Heavy light decomposition implementation
Problem : Query on a tree
Link : https://www.spoj.com/problems/QTREE/
*/
#include<bits/stdc++.h>

//#define int long long

using namespace std;

vector<tuple<int,int,int>> g[10005];
int lv[10005],pa[10005],sz[10005],id[10005],hvc[10005],hd[10005];
int va[10005],vid[10005];
int cnt=0,n;
int seg[1<<15];

void build(int l,int r,int i){
    if(l==r){
        seg[i]=va[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    seg[i]=max(seg[2*i],seg[2*i+1]);
}

void upd(int l,int r,int i,int x,int v){
    if(l>x||r<x)
        return;
    if(l==r){
        seg[i]=v;
        return;
    }
    int m=(l+r)/2;
    upd(l,m,2*i,x,v);
    upd(m+1,r,2*i+1,x,v);
    seg[i]=max(seg[2*i],seg[2*i+1]);
}

int qr(int l,int r,int i,int x,int y){
    if(l>y||r<x)
        return 0;
    if(l>=x&&r<=y)
        return seg[i];
    int m=(l+r)/2;
    return max(qr(l,m,2*i,x,y),qr(m+1,r,2*i+1,x,y));
}

void dfs(int u,int p,int l){
    lv[u]=l;
    pa[u]=p;
    sz[u]=1;
    for(auto [v,w,i]:g[u]){
        if(v==p)
            continue;
        dfs(v,u,l+1);
        sz[u]+=sz[v];
    }
}

void hld(int u,int p,int h){
    id[u]=++cnt;
    hd[u]=h;
    int mx=-1,mxid=-1;
    for(auto [v,w,i]:g[u]){
        if(v==p){
            va[id[u]]=w;
            vid[i]=id[u];
            continue;
        }
        if(sz[v]>mx){
            mx=sz[v];
            mxid=v;
        }
    }
    if(mxid==-1)
        return;
    hld(mxid,u,h);
    for(auto [v,w,i]:g[u]){
        if(v==p||v==mxid)
            continue;
        hld(v,u,v);
    }
}

int qrup(int a,int b){
    int ans=0;
    while(hd[a]!=hd[b]){
        if(lv[hd[a]]<lv[hd[b]])
            swap(a,b);
        ans=max(ans,qr(1,n,1,id[hd[a]],id[a]));
        a=pa[hd[a]];
    }
    if(a==b)
        return ans;
    if(lv[a]>lv[b])
        swap(a,b);
    ans=max(ans,qr(1,n,1,id[a]+1,id[b]));
    return ans;
}

void sol(){
    cin >> n;
    for(int i=1;i<=n;i++)
        g[i].clear();
    for(int i=1,a,b,c;i<=n-1;i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c,i});
        g[b].push_back({a,c,i});
    }
    cnt=0;
    dfs(1,0,1);
    hld(1,0,1);
    build(1,n,1);
    string s;
    int x,y;
    while(1){
        cin >> s;
        if(s[0]=='D')
            return;
        if(s[0]=='C'){
            cin >> x >> y;
            upd(1,n,1,vid[x],y);
        }
        else{
            cin >> x >> y;
            cout << qrup(x,y) << '\n';
        }
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--)
        sol();
}
