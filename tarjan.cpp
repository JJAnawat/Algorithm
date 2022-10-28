#include<bits/stdc++.h>

using namespace std;

int n,m;
bitset<10005> vis(0);
int disc[10005],low[10005];
int idx=0;
set<int> ap;
vector<int> g[10005];
set<pair<int,int>> bridge;

void dfs(int u,int p){
    vis[u]=1;
    low[u]=disc[u]=idx++;
    int ch=0;
    for(auto v:g[u]){
        if(!vis[v]){
            ch++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if((p!=-1&&low[v]>=disc[u])||(p==-1&&ch>1))
                ap.insert(u);
            if(low[v]>disc[u])
                bridge.insert({u,v});
        }
        else if(v!=p){
            low[u]=min(low[u],disc[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);

    cout << ap.size() << '\n';
    for(auto it:ap)
        cout << it << ' ';
    cout << "\n" << bridge.size() << "\n";
    for(auto [u,v]:bridge)
        cout << u << ' ' << v << '\n';
}

