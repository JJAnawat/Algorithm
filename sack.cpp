/*
DSU on tree aka sack implementation
Problem : E. Lomsat gelral
Link : https://codeforces.com/contest/600/problem/E
*/
#include<bits/stdc++.h>

#define int long long

using namespace std;

bitset<100005> big(0);
int n;
int cl[100005],sz[100005];
vector<int> g[100005];
int ans[100005],cnt[100005];
int mxx,cur;

void szdfs(int u,int p){
    sz[u]=1;
    for(auto v:g[u]){
        if(v==p)
            continue;
        szdfs(v,u);
        sz[u]+=sz[v];
    }
}

void add(int u,int p,int x){
    cnt[cl[u]]+=x;
    if(cnt[cl[u]]>mxx){
        mxx=cnt[cl[u]];
        cur=cl[u];
    }
    else if(cnt[cl[u]]==mxx)
        cur+=cl[u];
    for(auto v:g[u]){
        if(v==p||big[v])
            continue;
        add(v,u,x);
    }
}

void dfs(int u,int p,bool k){
    int mx=-1,bc=-1;
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(sz[v]>mx){
            mx=sz[v];
            bc=v;
        }
    }
    for(auto v:g[u])
        if(v!=p&&v!=bc)
            dfs(v,u,0);
    if(bc!=-1){
        dfs(bc,u,1);
        big[bc]=1;
    }
    add(u,p,1);
    ans[u]=cur;
    if(bc!=-1)
        big[bc]=0;
    if(!k){
        add(u,p,-1);
        mxx=0;
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1,x;i<=n;i++)
        cin >> cl[i];
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    szdfs(1,1);
    dfs(1,1,1);
    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
}
