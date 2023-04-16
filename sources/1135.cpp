#include <iostream>

#define MAXTREE 100
using namespace std;

struct Node
{
    char data=0;
    int left=-1, right=-1;
};
Node t1[MAXTREE],t2[MAXTREE];
int isIllegal =0;
void createTree(Node tree[],int n,int &root)
{
    string l,r; //保存左右节点编号
    const char* pl,*pr; //转换用
     
    int check[MAXTREE]={0};
    int i;
    for(i=0;i<n;i++)
    {
        cin>>(tree[i]).data>>l>>r;
        //cout<<l<<r;
        //if(l>26||r>26) {isIllegal=1; return;}
        if(l=="-")  (tree[i]).left=-1; //-1表示没孩子
        else
        {
            pl=l.c_str();
            (tree[i]).left = atoi(pl);//左右编号转换
            check[(tree[i]).left]=1;
        }
        if (r=="-")  (tree[i]).right = -1;
        else
        {
            pr=r.c_str();
            (tree[i]).right = atoi(pr);
            check[(tree[i]).right]=1;
        }
    }
    for(i=0;i<n;i++)
        if(!check[i]) break;
    root=i;
}
int isSame(int root1,int root2)
{
    if (root1 < 0 && root2 < 0) //树都为空
        return 1;
    else if ((root1 < 0 && root2 >= 0) || (root1 >= 0 && root2 < 0)) // 一棵树为空另一个不为
        return 0;
    else if (t1[root1].data != t2[root2].data) // 两树都不为空，但根节点值不等
        return 0;
    else if (isSame(t1[root1].left,t2[root2].left) &&(isSame(t1[root1].right,t2[root2].right) ) )// 左子都没有，只需看右子
        return 1;
    else if (isSame(t1[root1].left,t2[root2].right) &&(isSame(t1[root1].right,t2[root2].left) ))
        return 1;

    return 0;
}

int main()
{
    
    int num1,num2;
    int root1=-1,root2=-1;//两棵树根节点下标
    //scanf("%d" ,&num1);
    cin>>num1;
    if(num1>26) {cout<<"No\n"; return 0;}
    //Node t1[MAXTREE];
    createTree(t1,num1,root1);//创建二叉树，获得root下标
    if(isIllegal) {cout<<"No\n"; return 0;}

    cin>>num2;
    if(num2>26) {cout<<"No\n"; return 0;}
    if(num1==0&&num2==0){cout<<"Yes\n"; return 0;}
    if(num1!=num2) {cout<<"No\n"; return 0;}
    //Node t2[MAXTREE];
    createTree(t2,num2,root2);//创建二叉树，获得root下标
    if(isIllegal) {cout<<"No\n"; return 0;}

    if(isSame(root1,root2)) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}