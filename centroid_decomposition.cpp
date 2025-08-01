#include<bits/stdc++.h>

using namespace std;

const int mxn=200005;

bitset<mxn> rm;
int sz[mxn],pa[mxn];
vector<int> g[mxn];

int dfs(int u,int p=0){
    sz[u]=1;
    for(auto v:g[u]){
        if(v==p||rm[v])
            continue;
        sz[u]+=dfs(v,u);
    }
    return sz[u];
}

int getcentroid(int u,int p,int ts){
    for(auto v:g[u]){
        if(v==p||rm[v])
            continue;
        if(sz[v]*2>ts)
            return getcentroid(v,u,ts);
    }
    return u;
}

void buildcentroid(int u,int p=0){
    u=getcentroid(u,0,dfs(u));
    rm[u]=1;
    pa[u]=p;
    for(auto v:g[u]){
        if(rm[v])
            continue;
        buildcentroid(v,u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //buildcentroid(1,0);
}
