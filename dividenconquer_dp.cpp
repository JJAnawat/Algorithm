/*
Things to check!!
1) Is recurrence in this form
dp[i][j] = min(k<j) of (dp[i-1][k] + cost(k+1,j))
2) Quadrangle in equality
for all x<=y<=z<=u
cost(x,u)+cost(y,z)>=cost(x,z)+cost(y,u)
*/
#include<bits/stdc++.h>

using namespace std;

const long long inf=INT_MAX;
vector<long long> dp_prev(1005),dp_now(1005);
int n,m;

long long cost(int i,int j){
    return 0;//return cost from i to j
}

void compute(int l,int r,int opl,int opr){
    if(l>r)
        return;
    int m=(l+r)/2;
    dp_now[m]=inf;
    int opk;
    for(int k=opl;k<=min(m,opr);k++){
        if(dp_now[m]>dp_prev[k]+cost(k+1,m)){
            dp_now[m]=dp_prev[k]+cost(k+1,m);
            opk=k;
        }
    }
    compute(l,m-1,opl,opk);
    compute(m+1,r,opk,opr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1;i<=n;i++)
        dp_prev[i]=cost(1,i);

    for(int i=1;i<=m;i++){
        compute(1,n,1,n);
        dp_prev=dp_now;
    }

    //cout << dp_prev[n];
    //equal to "dp[k][n]"
}
