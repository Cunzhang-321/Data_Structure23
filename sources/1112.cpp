#include <iostream>
using namespace std;
#define MaxN 10005

struct Node {
    int target, next;
    Node(int tt = 0, int nn = 0) {
        target = tt;
        next = nn;
    }
} NodeT[MaxN << 1];
int head[MaxN];
int sum = 0, n;

int max(int,int);
void insert(int u, int v);

int size(int v, int s);

bool judge(int u) {
    int k = 0;
    for (int i = head[u]; i; i = NodeT[i].next)
        k = max(k, size(NodeT[i].target, u));
    return 2 * k <= n;
}

int main() {
    std::cin>>n;
    int u,v;
    for (int i = 1; i < n; ++i)
        {std::cin>>u>>v; insert(u, v); insert(v, u);}
    for (int i = 1; i <= n; ++i)
        if (judge(i))
            std::cout<<i<<std::endl;
    return 0;
}

inline int max(int x,int y)
{
    return x>y?x:y;
}
inline void insert(int u, int v) {
    NodeT[++sum] = Node(v, head[u]);
    head[u] = sum;
}
int size(int v, int s) {
    int r = 1;
    for (int i = head[v]; i; i = NodeT[i].next)
        if (NodeT[i].target != s)
            r += size(NodeT[i].target, v);
    return r;
}