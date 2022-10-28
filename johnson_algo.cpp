/*
given graph with n node and m edges
find all pair shortest path
*GRAPH CAN CONTAIN NEG WEIGHT CYCLE*
*/
#include<bits/stdc++.h>

#define ti tuple<int,int,int>
#define pi pair<int,int>

using namespace std;

const int inf=1e9;
int n,m;
vector<pi> g[1005];
vector<ti> edge;
int ans[1005][1005];
bitset<1005> vis(0);

void dijkstra(int s){
    vis=0;
    priority_queue<ti,vector<ti>,greater<ti>> pq;
    ans[s][s]=0;
    pq.push({0,s,s});
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
            if(ans[s][v]>ans[s][u]+w){
                ans[s][v]=ans[s][u]+w;
                pq.push({ans[s][u]+w,v,u});
            }
        }
    }
}

bool bellman_ford(){
    ans[1][1]=0;
    bool chk=1,neg=0;
    int cnt=0;
    do{
        chk=0;
        for(auto [u,v,w]:edge){
            if(ans[1][v]>ans[1][u]+w){
                ans[1][v]=ans[1][u]+w;
                chk=1;
            }
        }
        cnt++;
        if(cnt>n-1&&chk){
            neg=1;
            break;
        }
    }while(chk);
    return neg;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edge.push_back({u,v,w});
        edge.push_back({v,u,w});
    }

    for(int i=1;i<=n;i++){
        ans[i][i]=0;
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            ans[i][j]=inf;
        }
    }

    bool neg=bellman_ford();
    if(neg){
        cout << "Found neg weight cycle!!";
        return 0;
    }
    for(int i=2;i<=n;i++)
        dijkstra(i);

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout << i << " -> " << j << " : " << ans[i][j] << "\n";
        }
    }
}

