#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
#include<cstdio>
#include<map>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
using namespace std;
#define all(x) x.begin(),x.end()
#define cini(x) scanf("%d",&x)
#define forn(x) for(int i=0;i<x;i++)
typedef long long ll;
typedef int cint;

int y=1;
int solve(){
    int wl,dl,wr,dr;
    int weight;
    scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
    if(wl==0)wl=solve();
    if(wr==0)wr=solve();
    if(wl*dl!=wr*dr)y=0;
    return wl+wr;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        y=1;
        solve();
        if(y)printf("YES\n");
        else printf("NO\n");
        if(t!=0)printf("\n");
    }
}