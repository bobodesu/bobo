## Dijkstra算法

作用：  
> 解决 **无负权边的带权有向图或无向图** 的单源最短路问题

* 贪心思想，若离源点s前k-1近的点已经被确定，构成点集P ，那么从s到离s第k近的点t的最短路径，{s,p1,p2…pi,t} 满足s,p1,p2…pi∈P。
* 否则假设pi∉P，则因为边权非负，pi到t的路径≥0，则 d[pi]≤d[t],pi才是第k近。将pi看作t，重复上面过程， 最终一定会有找不到pi的情况
* d[i]=min(d[pi]+cost(pi,i)),i∉P,pi∈P  
  d[t]=min(d[i]) ,i∉P   

* 初始令d[s]=0，d[i]=+∞，P=∅ 
* 找到点i∉P，且d[i]最小 
* 把i添入P，对于任意j∉P，若d[i]+cost(i,j)<d[j]，则更新 d[j] = d[i]+cost(i,j)。 

* 用邻接表，不优化，时间复杂度O(V2+E)
* Dijkstra+堆的时间复杂度 o(ElgV) 
* 用斐波那契堆可以做到O(VlogV+E) 
* 若要输出路径，则设置prev数组记录每个节点的前趋点，在d[i] 更新时更新prev[i] 


 