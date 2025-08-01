/*
Matrix exponentiation
Problem : Fibonacci Numbers
Link : https://cses.fi/problemset/task/1722
*/
#include<bits/stdc++.h>

#define int long long

using namespace std;

const int mod=1e9+7;

using mat=array<array<int,2>,2>;

mat mul(mat a,mat b){
    mat c={{{0,0},{0,0}}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    mat ans={{{1,0},{0,1}}};
    mat m={{{1,1},{1,0}}};
    for(;n>0;n/=2,m=mul(m,m)){
        if(n&1)
            ans=mul(ans,m);
    }
    cout << ans[0][1];
}
