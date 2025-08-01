/*
Persistent segment tree implementation
Problem : CSES-Range Queries and Copies
Link : https://cses.fi/problemset/task/1737/
*/

#include<bits/stdc++.h>

#define int long long

using namespace std;

int ar[200005];

struct node{
    int val;

    node* left, *right;

    node(node* l,node* r,int v){
        left=l;
        right=r;
        val=v;
    }
};

node* ver[200005];

void build(node* n,int l,int r){
    if(l==r){
        n->val = ar[l];
        return;
    }
    int m=(l+r)/2;
    n->left = new node(NULL,NULL,0);
    n->right = new node(NULL,NULL,0);
    build(n->left,l,m);
    build(n->right,m+1,r);
    n->val=n->left->val+n->right->val;
}

void upd(node* cur,node* prev,int l,int r,int x,int v){
    if(l==r){
        cur->val=v;
        return;
    }

    int m=(l+r)/2;
    if(x<=m){
        cur->left=new node(NULL,NULL,0);
        cur->right=prev->right;
        upd(cur->left,prev->left,l,m,x,v);
    }
    else{
        cur->left=prev->left;
        cur->right=new node(NULL,NULL,0);
        upd(cur->right,prev->right,m+1,r,x,v);
    }
    cur->val=cur->left->val+cur->right->val;
}

int qr(node* n,int l,int r,int a,int b){
    if(l>b||r<a)
        return 0;
    if(l>=a&&r<=b)
        return n->val;
    int m=(l+r)/2;
    return qr(n->left,l,m,a,b)+qr(n->right,m+1,r,a,b);
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }

    node* root=new node(NULL,NULL,0);
    build(root,0,n-1);
    ver[1]=root;

    int k,a,b,x,cnt=1;
    while(q--){
        int tp;
        cin >> tp;
        if(tp==1){
            cin >> k >> a >> x;
            --a;
            node* newroot=new node(NULL,NULL,0);
            upd(newroot,ver[k],0,n-1,a,x);
            ver[k]=newroot;
        }
        else if(tp==2){
            cin >> k >> a >> b;
            --a;
            --b;
            cout << qr(ver[k],0,n-1,a,b) << "\n";
        }
        else{
            cin >> k;
            node* root=new node(ver[k]->left,ver[k]->right,ver[k]->val);
            ver[++cnt]=root;
        }
    }
}
