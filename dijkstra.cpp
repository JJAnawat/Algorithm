/*
given graph with n node and m edges
find shortest path from 1
*/
#include<bits/stdc++.h>

#define pi pair<int,int>
#define pii tuple<int,int,int>

using namespace std;

const int inf=1e9;
int n,m;
vector<pi> g[1005];
bitset<1005> vis(0);
int dis[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++)
        dis[i]=inf;

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[1]=0;
    pq.push({0,1,1});
    while(!pq.empty()){
        auto [disu,u,p]=pq.top();
        pq.pop();

        if(vis[u])
            continue;
        vis[u]=1;

        for(auto [v,w]:g[u]){
            if(v==p)
                continue;
            if(vis[v])
                continue;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v,u});
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout << i << " : " << dis[i] << "\n";
}
