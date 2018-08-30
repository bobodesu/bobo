/*
    线段树的基本运用
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
#define cini(x) scanf("%d",&x)
typedef long long ll;

struct nod{
    int l,r;
    int su;
    int mid(){return (l+r)/2;}
};
nod s[200000];
void init(int ro,int l,int r){
    s[ro].l=l;s[ro].r=r;s[ro].su=0;
    if(l!=r){
        init(ro*2+1,l,s[ro].mid());
        init(ro*2+2,s[ro].mid()+1,r);
    }
}
void change(int ro,int po,int va){
    s[ro].su+=va;
    if(s[ro].l==s[ro].r)return;
    if(po<=s[ro].mid()){
        change(ro*2+1,po,va);
    }else{
        change(ro*2+2,po,va);
    }
}
int queryva(int ro,int l,int r){
    int su=0;
    if(s[ro].l==l&&s[ro].r==r)return s[ro].su;
    if(r<=s[ro].mid())su=queryva(ro*2+1,l,r);
    else if(l>s[ro].mid())su=queryva(ro*2+2,l,r);
    else {
        su+=queryva(ro*2+1,l,s[ro].mid());
        su+=queryva(ro*2+2,s[ro].mid()+1,r);
    }
    return su;
}
int T,C,p;
char query[50];
int main(){
    cin>>T;
    C=1;
    while(T--){
        cin>>p;
        init(0,1,p);
        for(int i=1;i<=p;i++){
            int t;
            cini(t);
            change(0,i,t);
        }
        cout<<"Case "<<C++<<":"<<endl;
        while(1){
            scanf("%s",query);
            if(query[0]=='E')break;
            int a,b;
            cini(a);cini(b);
            if(query[0]=='Q'){
                cout<<queryva(0,a,b)<<endl;
            }else if(query[0]=='A'){
                change(0,a,b);
            }else if(query[0]=='S'){
                change(0,a,-b);
            }
        }
    }
}