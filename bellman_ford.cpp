/*
given graph with n node and m edges
find shortest path from 1
*GRAPH CAN CONTAIN NEG WEIGHT CYCLE*
*/
#include<bits/stdc++.h>

using namespace std;

const int inf=1e9;
int n,m;
vector<tuple<int,int,int>> edge;
int dis[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        edge.push_back({u,v,w});
        edge.push_back({v,u,w});
    }

    for(int i=1;i<=n;i++)
        dis[i]=inf;

    dis[1]=0;
    bool chk=1,neg=0;
    int cnt=0;
    do{
        chk=0;
        for(auto [u,v,w]:edge){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                chk=1;
            }
        }
        cnt++;
        if(cnt>n-1&&chk){
            neg=1;
            break;
        }
    }while(chk);

    if(neg)
        cout << -1;
    else{
        for(int i=1;i<=n;i++)
            cout << i << " : " << dis[i] << "\n";
    }
}
