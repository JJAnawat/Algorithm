#include<bits/stdc++.h>

using namespace std;

vector<int> g[200005];
int n,sub[200005];

void subsize(int u,int p){
    sub[u]=1;
    for(auto v:g[u]){
        if(v==p)
            continue;
        subsize(v,u);
        sub[u]+=sub[v];
    }
}

int centroid(int u,int p){
    for(auto v:g[u]){
        if(v==p)
            continue;
        if(sub[v]*2>n)
            return centroid(v,u);
    }
    return u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0,a,b;i<n-1;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    subsize(1,0);
    cout << centroid(1,0);
}
