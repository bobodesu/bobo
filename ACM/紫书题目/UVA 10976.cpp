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
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef int cint;

vector<pair<int,int> > ve;
int gcd(int a,int b){
    int t;
    while(b){
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int lcm(int a,int b){return a*b/gcd(a,b);}
bool sor1(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
int main(){
    int t;
    while(cin>>t){
        ve.clear();
        int tt=t<<1;
        for(int i=t+1;i<=tt;i++){
            int l=lcm(t,i);
            int la=l/t,lb=l/i;
            int lc=la-lb;
            if(l%lc==0){
                ve.pb(mp(l/lc,i));
            }
        }
        sort(all(ve),sor1);
        printf("%d\n",ve.size());
        for(vector<pair<int,int> >::iterator vi=ve.begin();vi!=ve.end();vi++){
            printf("1/%d = 1/%d + 1/%d\n",t,vi->first,vi->second);
        }
    }
}