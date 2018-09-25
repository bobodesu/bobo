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

bool isprime[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
bool usenum[20];
int t;
int num[20];
void solve(int deep){
    for(int i=2;i<=t;i++){
        if(usenum[i]==false && isprime[num[deep-1]+i]){
            num[deep]=i;
            if(deep==t){
                if(isprime[num[deep]+1]){
                    printf("%d",num[1]);
                    for(int c=2;c<=t;c++)printf(" %d",num[c]);
                    printf("\n");
                }
            }else{
                usenum[i]=true;
                num[deep]=i;
                solve(deep+1);
                usenum[i]=false;
            }
        }
    }
}
int main(){
    int TIMES=1;
    while(cin>>t){
        if(TIMES!=1)printf("\n");
        printf("Case %d:\n",TIMES++);
        memset(usenum,0,sizeof(usenum));
        usenum[1]=true;
        num[1]=1;
        solve(2);
    }
}