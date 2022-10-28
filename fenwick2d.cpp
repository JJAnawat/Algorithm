/*
given an array size n*n
ask q queries
each queries ask sum in square from (x1,y1) as upper-left corner and (x2,y2) as lower-right coner
*/
#include<bits/stdc++.h>

using namespace std;

long long fw[1005][1005];
int ar[1005][1005];

void upd(int x,int y,int val){
    for(int i=x;i<=1000;i+=i&-i)
        for(int j=y;j<=1000;j+=j&-j)
            fw[i][j]+=val;
}

long long qr(int x,int y){
    long long sum=0;
    for(int i=x;i>0;i-=i&-i)
        for(int j=y;j>0;j-=j&-j)
            sum+=fw[i][j];
    return sum;
}

long long ask(int x1,int y1,int x2,int y2){
    return qr(x2,y2)-qr(x1-1,y2)-qr(x2,y1-1)+qr(x1-1,y1-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> ar[i][j];
            upd(i,j,ar[i][j]);
        }
    }

    int q,x1,y1,x2,y2;
    cin >> q;
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ask(x1,y1,x2,y2) << '\n';
    }
}
