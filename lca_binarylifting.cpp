/*
given a rooted directed tree (root=1)
ask q queries about lca(a,b)
*/
#include<bits/stdc++.h>

using namespace std;

int n,dp[25][100005],lv[100005];
vector<int> g[100005];

void dfs(int u,int p,int l){
    dp[0][u]=p;
    lv[u]=l;
    for(auto v:g[u])
        if(v!=p)
            dfs(v,u,l+1);
}

int lca(int a,int b){
    if(lv[a]<lv[b])
        swap(a,b);
    for(int i=20;i>=0;i--)
        if(lv[dp[i][a]]>=lv[b])
            a=dp[i][a];
    if(a==b)
        return a;
    for(int i=20;i>=0;i--)
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    return dp[0][a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
    }

    dfs(1,1,1);

    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][dp[i-1][j]];

    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << '\n';
    }
}
