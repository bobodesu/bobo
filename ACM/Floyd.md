## 弗洛伊德算法

作用：
> 用于求每一对顶点之间的最短路径。有向图，无向图均可，也可以有负权边 


* 假设求从顶点vi到vj的最短路径。如果从vi到vj有边，则从vi到vj存在一条长 度为cost[i,j]的路径，该路径不一定是最短路径，尚需进行n次试探。   
* 考虑路径（ vi， v1 ，vj）是否存在（即判别弧（ vi， v1 ）和（ v1 ，vj ） 是否存在）。如果存在，则比较cost[i,j]和（ vi， v1 ，vj）的路径长度， 取长度较短者为从vi到vj的中间顶点的序号不大于1的最短路径，记为新的 cost[i,j]   
* 假如在路径上再增加一个顶点v2 ，如果（ vi，…， v2 ）和（ v2 ，…， vj ）分别是 **当前找到的中间顶点的序号不大于2的最短路径** ，那么（ vi，…， v2 ，… ， vj ）就有可能是从vi到 vj的中间顶点的序号不大于2的最短路径。 将它和已经得到的从vi到 vj的中间顶点的序号不大于1的最短路径相比较， 从中选出中间顶点的序号不大于2的最短路径之后，再增加一个顶点v3 ，继 续进行试探。依次类推。   
* **复杂度O(n3)**  

---

### 伪代码如下：
```cpp
/*
    vtxnum -> 节点数量
    cost[i][j] -> 点i到j的边权值
    dist[i][j] -> 两点间最短距离
    path[i,j] -> 路径
*/

for( int i = 1 ;i <= vtxnum; ++i )  
for( int j = 1; j <= vtxnum; ++j){   
    dist[i][j] = cost[i][j]; 
    // cost是边权值, dist是两点间最短距离   
    if( dist[i][j] < INFINITE) //i到j有边     
    path[i,j] = [i]+[j]; //path是路径  
} 
for( k = 1; k <= vtxnum; ++k) //每次求中间点标号不超过k的i到j最短路 
  for( int i = 1; i <= vtxnum; ++i)   
    for(int j = 1; j <= vtxnum ; ++j)    
        if( dist[i][k] + dist[k][j] < dist[i][j]) {       dist[i][j] = dist[i][k]+dist[k][j];     
            path[i,j] = path[i,k]+path[k,j];
        } 
```