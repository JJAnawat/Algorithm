/*
Things to check!!
1)QI
2)Monotone
w[y][z]<=w[x][u]
for all x<=y<=z<=u
*/
#include<bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int opk[1005][1005];
int n;

int cost(int i,int j){
    return 0;
    //return cost from i to j
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=1;i<=n;i++){
        dp[i][i]=cost(i,i);
        opk[i][i]=i;
        for(int j=i+1;j<=n;j++){
            for(int k=opk[i][j-1];k<=opk[i+1][j];k++){
                if(dp[i][j]>dp[i][k]+dp[k+1][j]+cost(i,j)){
                    dp[i][j]=dp[i][k]+dp[k+1][j]+cost(i,j);
                    opk[i][j]=k;
                }
            }
        }
    }

}
