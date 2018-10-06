#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
#define forn(x) for(int i=0;i<x;i++)
#define pb push_back
#define mp make_pair
#define cini(x) scanf("%d",&x)
typedef long long ll;

struct nod{
    int x,y;
    int val;
    nod(){};
    nod(int x,int y,int v):x(x),y(y),val(v){};
}nods[1000];

bool operator<(nod a,nod b){
    return a.val>b.val;
}

int co;
int cou;
int guess;

typedef vector<pair<int,int> > ve_pa;

ve_pa ve[1000];
priority_queue<nod> pq;
int have[1000];


int main(){
    int line;
    while(cin>>line>>co){
        if(line==0)break;
        while(!pq.empty())pq.pop();
        for(int i=1;i<=co;i++)ve[i].clear();
        memset(have,0,sizeof(have));
        cou=0;
        guess=1;
        
        for(int i=1;i<=line;i++){
            int a,b,c;
            scanf("%d%d%d",&b,&c,&a);
            ve[b].pb(mp(c,a));
            ve[c].pb(mp(b,a));
        }

        have[1]=1;
        for(ve_pa::iterator vi=ve[1].begin();vi!=ve[1].end();vi++){
            pq.push(nod(1,vi->first,vi->second));

        }

        while(!pq.empty()){
            if(guess>=co)break;
            nod temp=pq.top();
            pq.pop();
            if(have[temp.y])continue;
            have[temp.y]=1;
            guess++;
            cou+=temp.val;
            for(ve_pa::iterator vi=ve[temp.y].begin();vi!=ve[temp.y].end();vi++){
                pq.push(nod(temp.y,vi->first,vi->second));
            }
        }

        if(guess!=co){
            cout<<"?"<<endl;
        }else{
            cout<<cou<<endl;
        }
    }
}