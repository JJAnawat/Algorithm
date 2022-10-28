/*
given graph with n node and m edges
find all pair shortest path
*/
#include<bits/stdc++.h>

using namespace std;

const int inf=1e9;
int n,m;
int dis[1005][1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            dis[i][j]=inf;
        }
    }



    for(int i=0,u,v,w;i<m;i++){
        cin >> u >> v >> w;
        dis[u][v]=w;
        dis[v][u]=w;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout << i << " -> " << j << " : " << dis[i][j] << "\n";
        }
    }
}
