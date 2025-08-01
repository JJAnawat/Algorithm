#include<bits/stdc++.h>

using namespace std;

int ar[1000];
int tb[10][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        tb[0][i]=ar[i];
    }
    for(int k=1;k<=9;k++){
        for(int j=1;j+(1<<k)<=n+1;j++){
            tb[k][j]=min(tb[k-1][j],tb[k-1][j+(1<<(k-1))]);
        }
    }

    int qr;
    cin >> qr;
    while(qr--){
        int l,r;
        cin >> l >> r;
        int len=log2(r-l+1);
        cout << min(tb[len][l],tb[len][r-(1<<len)+1]) << "\n";
    }
}
