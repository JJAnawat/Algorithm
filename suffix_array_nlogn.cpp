#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    s+="$";
    int n=s.size();

    //Base
    //k=0
    vector<int> p(n+1),c(n+1);
    vector<pair<char,int>> a(n);
    for(int i=0;i<n;i++)
        a[i]={s[i],i};
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
        p[i]=a[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++){
        c[p[i]]=c[p[i-1]];
        if(a[i].first!=a[i-1].first)
            c[p[i]]++;
    }

    //Transition
    //k->(k+1)
    vector<int> pn(n+1),cn(n+1),cnt(n+1),pos(n+1);
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++)
            pn[i]=(p[i]-(1<<k)+n)%n;
        fill(cnt.begin(),cnt.end(),0);
        for(int i=0;i<n;i++)
            cnt[c[pn[i]]]++;
        pos[0]=0;
        for(int i=1;i<n;i++)
            pos[i]=pos[i-1]+cnt[i-1];

        for(int i=0;i<n;i++)
            p[pos[c[pn[i]]]++]=pn[i];
        cn[p[0]]=0;
        for(int i=1;i<n;i++){
            pair<int,int> cur={c[p[i  ]],c[(p[i  ]+(1<<k))%n]};
            pair<int,int> prv={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            cn[p[i]]=cn[p[i-1]];
            if(cur!=prv)
                cn[p[i]]++;
        }
        c=cn;
    }

    //lcp
    vector<int> lcp(n);
    int k=0;
    for(int i=0;i<n-1;i++){
        int pi=c[i];
        int j=p[pi-1];
        while(s[i+k]==s[j+k])
            k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }
    for(int i=0;i<n;i++){
        cout << p[i] << " " << lcp[i] << " " << s.substr(p[i],n-p[i]) << "\n";
    }
}
