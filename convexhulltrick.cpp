/*
Convex hull trick implementation
Problem : Z - Frog 3
Link : https://atcoder.jp/contests/dp/tasks/dp_z
*/
#include<bits/stdc++.h>

#define int long long

using namespace std;

struct CHT{
    struct line{
        int m,c;

        line(int mm,int cc){
            m=mm;
            c=cc;
        }

        int cal(int x){
            return m*x+c;
        }

        double intersect(line l){
            return 1.0*(l.c-c)/(m-l.m);
        }
    };

    deque<pair<line,int>> dq;

    void insert(int m,int c){
        line nline(m,c);

        while(dq.size()>1&&dq.back().second>=dq.back().first.intersect(nline))
            dq.pop_back();

        if(dq.empty()){
            dq.push_back({nline,0});
            return;
        }

        dq.push_back({nline,dq.back().first.intersect(nline)});
    }

    int query(int x){//query are monotonicity
        while(dq.size()>1){
            if(dq[1].second<=x)
                dq.pop_front();
            else
                break;
        }

        return dq.front().first.cal(x);
    }

    /*
    case:query aren't monotonicity
    find the first line that has intersection point with prev line >=x
    in this problem intersect[i]>intersect[i+1]
    */
    int query2(int x){
        int l=0,r=dq.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(dq[m].second>=x)
                l=m;
            else
                r=m-1;
        }
        return dq[l].first.cal(x);
    }
};

int h[200005];
int dp[200005];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,c;
    cin >> n >> c;
    for(int i=1;i<=n;i++)
        cin >> h[i];
    CHT cht;
    dp[1]=0;
    cht.insert(-2*h[1],dp[1]+h[1]*h[1]);
    for(int i=2;i<=n;i++){
        dp[i]=cht.query(h[i])+c+h[i]*h[i];
        cht.insert(-2*h[i],dp[i]+h[i]*h[i]);
    }
    cout << dp[n];
}
