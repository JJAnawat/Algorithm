#include<bits/stdc++.h>

using namespace std;

struct node{
    int sz,val,prio;
    node *l,*r;
};

using pnode=node*;

int sz(pnode t){
    if(!t)
        return 0;
    return t->sz;
}

void upd_sz(pnode t){
    if(!t)
        return;
    t->sz=sz(t->l)+sz(t->r)+1;
}

void split(pnode t,pnode &l,pnode &r,int key){
    if(!t){
        l=r=NULL;
        return;
    }
    if(key>=t->val){
        split(t->r,t->r,r,key);
        l=t;
    }
    else{
        split(t->l,l,t->l,key);
        r=t;
    }
    upd_sz(t);
}

void merge(pnode &t,pnode l,pnode r){
    if(!l){
        t=r;
        return;
    }
    if(!r){
        t=l;
        return;
    }
    if(l->prio>r->prio){
        merge(l->r,l->r,r);
        t=l;
    }
    else{
        merge(r->l,l,r->l);
        t=r;
    }
    upd_sz(t);
}

void insert(pnode &t,pnode it){
    if(!t){
        t=it;
        return;
    }
    if(it->prio>t->prio){
        split(t,it->l,it->r,it->val);
        t=it;
    }
    else{
        if(it->val>t->val)
            insert(t->r,it);
        else
            insert(t->l,it);
    }
    upd_sz(t);
}

void erase(pnode &t,int key){
    if(!t)
        return;
    if(key==t->val){
        pnode tmp=t;
        merge(t,t->l,t->r);
        free(tmp);
    }
    else{
        if(key>t->val)
            erase(t->r,key);
        else
            erase(t->l,key);
    }
    upd_sz(t);
}

pnode init(int key){
    pnode res=new node;
    *res={1,key,rand(),NULL,NULL};
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(NULL));
}
