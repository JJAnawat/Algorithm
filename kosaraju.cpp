#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> g[10005],rg[10005];
bitset<100005> vis(0);
stack<int> st;

void dfs(int u){
    if(vis[u])
        return;
    vis[u]=1;
    for(auto v:g[u])
        dfs(v);
    st.push(u);
}

void scc(int u){
    if(vis[u])
        return;
    vis[u]=1;
    cout << u << ' ';
    for(auto v:rg[u])
        scc(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0,u,v;i<m;i++){
        cin >> u >> v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    dfs(0);

    vis=0;

    while(!st.empty()){
        int u=st.top();
        st.pop();

        scc(u);

        cout << '\n';
    }
}
