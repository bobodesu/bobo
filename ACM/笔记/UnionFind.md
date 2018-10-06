# 并查集

```cpp
//查询根节点
int uf_find(int x){
    if(x==s[x])return x;
    return s[x]=uf_find(s[x]);
}
//合并两棵树
void uf_union(int a,int b){
    if(uf_find(a)==uf_find(b))return;
    s[uf_find(a)]=uf_find(b);
}
```