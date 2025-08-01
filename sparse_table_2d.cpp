#include<bits/stdc++.h>

using namespace std;

int ar[1000][1000];
int tb[10][1000][10][1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ar[i][j];
            tb[0][i][0][j]=ar[i][j];
        }
    }

    for(int ir=0;ir<n;ir++){
        for(int kc=1;kc<=log2(m);kc++){
            for(int ic=0;ic+(1<<kc)-1<m;ic++){
                tb[0][ir][kc][ic]=min(tb[0][ir][kc-1][ic+(1<<(kc-1))],tb[0][ir][kc-1][ic+(1<<(kc-1))]);
            }
        }
    }

    for(int kr=1;kr<=log2(n);kr++){
        for(int ir=0;ir+(1<<kr)-1<n;ir++){
            for(int kc=0;kc<=log2(m);kc++){
                for(int ic=0;ic+(1<<kc)-1<m;ic++){
                    tb[kr][ir][kc][ic]=min(tb[kr-1][ir+(1<<(kr-1))][kc][ic],tb[kr-1][ir][kc][ic]);
                }
            }
        }
    }

    int qr;
    cin >> qr;
    int a,b,c,d;
    while(qr--){
        cin >> a >> b >> c >> d;
        int lenr=c-a+1,lenc=d-b+1;
        int kr=log2(lenr),kc=log2(lenc);
        int mn1=min(tb[kr][a][kc][b],tb[kr][a][kc][d-(1<<kc)+1]);
        int mn2=min(tb[kr][c-(1<<kr)+1][kc][b],tb[kr][c-(1<<kr)+1][kc][d-(1<<kc)+1]);

        cout << min(mn1,mn2) << '\n';
    }
}
