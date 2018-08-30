# 深度优先搜索


**基本模板代码**  
判断是否能寻找到终点，深搜代码一般由这个模板而加以改动  
```cpp
bool Dfs(V) {
    if( V == 终点 ) return true; 
    if( V == 旧点 ) return false; 
    将V点标记为旧点; 
    对和V相邻的每个节点U { 
        if( Dfs(U) == true) return true; 
    } 
    return false; 
}
int main() { 
    将所有点都标记为新点; 
    定义起点与终点;
    cout << Dfs(起点）;
} 
```
> !!!!!  
> 难点：深搜过程中进行剪枝优化  
> !!!!!

  


判断是否能寻找到终点，如果可以记录路径  
```cpp
Node path[MAX_LEN];  //MAX_LEN取节点总数即可 
int depth; 
bool Dfs(V) { 
    if( V为终点）{ 
        path[depth] = V; 
        return true; 
    } 
    if( V 为旧点) return false; 
    将V标记为旧点; 
    path[depth]=V; 
    ++depth;
    对和V相邻的每个节点U { 
        if( Dfs(U) == true) return true; 
    } 
    --depth; 
    return false;
} 
int main() { 
    将所有点都标记为新点; 
    depth = 0; 
    if(Dfs(起点)) { 
        for(int i = 0;i <= depth; ++ i)
            cout << path[i] << endl; 
    } 
}
```

利用深搜寻找最优（步数最少）路径  
```cpp
Node bestPath[MAX_LEN]; 
int minSteps = INFINITE; //最优路径步数
Node path[MAX_LEN];  //MAX_LEN取节点总数即可 
int depth; 
void Dfs(V) { 
    if( V为终点）{ 
        path[depth] = V; 
        if( depth < minSteps ) { 
            minSteps = depth; 
            拷贝path到bestPath; 
        } 
        return; 
    } 
    if( V 为旧点)  return; 
    if( depth >= minSteps ) return ; //最优性剪枝，这里非常重要 
    将V标记为旧点; 
    path[depth]=V; 
    ++depth; 
    对和V相邻的每个节点U { Dfs(U); } 
    --depth; 
    将V恢复为新点; //防止上级节点无法走其他路径，这里需要留意
} 
int main() { 
    将所有点都标记为新点; 
    depth = 0; 
    Dfs(起点); 
    if( minSteps != INFINITE) { 
        for(int i = 0;i <= minSteps; ++ i)
            cout << bestPath[i] << endl; 
    } 
}

```

遍历图上所有的节点  
*适用于求连通图的数量等等*
```cpp
Dfs(V) { 
    if( V是旧点) return; 
    将V标记为旧点; 
    对和V相邻的每个点 U { Dfs(U); }  
} 
int main() { 
    将所有点都标记为新点; 
    while(在图中能找到新点k) Dfs(k); 
}
```
