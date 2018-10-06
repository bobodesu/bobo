## SPFA算法

作用：  
> 快速求解 **含负权边 的 带权有向图** 的单源最短路径问题  

> 是Bellman-Ford算法的改进版，利用队列动态更新dist[] 

* 维护一个队列，里面存放所有需要进行迭代的点。初始时队列中只有一个 源点S。用一个布尔数组记录每个点是否处在队列中。   
* 每次迭代，取出队头的点v，依次枚举从v出发的边v->u，若 Dist[v]+len(v->u) 小于Dist[u]，则改进Dist[u]（可同时将u前驱记为v）。此时由于S到u的最短距离变小了，有可能u可以改进其它的点，所以若u不在 队列中，就将它放入队尾。这样一直迭代下去直到队列变空，也就是S到所 有节点的最短距离都确定下来，结束算法。 **若一个点最短路被改进的次数达到n，则有负权环(原因同B-F算法）** 。可以用spfa算法判断图有无负权环  
* 在平均情况下，SPFA算法的期望时间复杂度为O(E)。

```cpp
int F,N,M,W; 
const int INF = 1 << 30; 
struct Edge {  
    int e,w;  
    Edge(int ee,int ww):e(ee),w(ww) { }  
    Edge() { } 
}; 
vector<Edge> G[1000]; //整个有向图 
int updateTimes[1000]; //最短路的改进次数 
int dist[1000]; //dist[i]是源到i的目前最短路长度 
int Spfa(int v) {  
    for(int i = 1; i <= N; ++i)
        dist[i] = INF;  
    dist[v] = 0;  
    queue<int> que;  
    que.push(v);  
    memset(updateTimes,0,sizeof(updateTimes));
    while(!que.empty()) {   
        int s = que.front();   
        que.pop();   
        for(int i=0; i<G[s].size(); ++i) {
            int e = G[s][i].e;    
            if(dist[e] > dist[s] + G[s][i].w) {
                dist[e] = dist[s] + G[s][i].w;
                que.push(e); 
                //没判队列里是否已经有e,可能会慢一些
                ++updateTimes[e];     
                if( updateTimes[e] >= N) return true;
            }
        }
    }  
    return false;
} 
int main(){
    cin >> F;  
    while( F--) {
        cin >> N >> M >> W;
        for( int i = 1; i <1000; ++i)
            G[i].clear();
        int s,e,t;
        for( int i = 0; i < M; ++ i) {
            cin >> s >> e >> t;
            G[s].push_back(Edge(e,t));
            G[e].push_back(Edge(s,t));
        }
        for( int i = 0;i < W; ++i) {
            cin >> s >> e >> t;
            G[s].push_back(Edge(e,-t));
        }
        if( Spfa(1))
            cout << "YES" <<endl;
        else 
            cout << "NO" <<endl;
    }
} 
```