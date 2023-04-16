#include <iostream>
#include "seqStack.h"
#include "seqQueue.h"
using namespace std;

template <class elemType>
class BTree;

template <class elemType>
class Node{
    friend class BTree<elemType>;
    elemType data;
    Node *left,*right;
    public:
        Node(){left=NULL;right=NULL;}
        Node(const elemType &e, Node*L =NULL; Node* R=NULL;)
        {
            data=e;
            left=L;right=R;
        }
};

template<class elemType>
class BTree
{
    Node<elemType> *root; int stopflag;
    void delTree(Node<elemType> *t);
    void InOrder(Node<elemType> *t);
    void PostOrder(Node<elemType> *t);

    public:
        BTree(){root=NULL;}
        void createTree(const elemType &flag); //创建一棵树
        bool isEmpty(){return (root==NULL);}
        void delTree(); //删除树
        void InOrder(); //中序遍历
        void PostOrder(); //后序遍历
        
};

template<class elemType>
void BTree<elemType>::delTree(Node<elemType> *t)
{
    if(!t) return;
    delTree(t->left);
    delTree(t->right);
    delete t;
}

template <class elemType>
void BTree<elemType>::InOrder()
{
    if(!root) return;
    seqStack<Node<elemType>*> s1;
    seqStack<int> s2;
    Node<elemType> *p;
    int flag;
    p=root;
    s1.push(p);s2.push(0);
    while(!s1.isEmpty())
    {
        flag=s2.top();
        s2.pop();
        p=s1.top();
        if(flag==1)
        {
            s1.pop();
            cout<<p->data<<" ";
            if(!p->right) continue;
            s1.push(p->right);
            s2.push(0);

        }
        else{
            s2.push(1);
            if(p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
        }
    }
    cout<<"\n";
}
template <class elemType>
void BTree<elemType>::PostOrder()
{
    if(!root) return;
    seqStack<Node<elemType>*> s1;
    seqStack<int> s2;
    Node<elemType> *p;
    int flag;
    p=root;
    s1.push(p);s2.push(0);
    while(!s1.isEmpty())
    {
        flag=s2.top();
        s2.pop();
        p=s1.top();
        switch (flag)
        {
        case 2:
            s1.pop();
            cout<<p->data<<" ";
            break;
        case 1:
            s2.push(2);
            if(p->right)
            {
                s1.push(p->right);
                s2.push(0);
            }
            break;
        case 0:
            s2.push(1);
            if(p->left)
            {
                s1.push(p->left);
                s2.push(0);
            }
            break;
        }
       
    }
    cout<<"\n";
}