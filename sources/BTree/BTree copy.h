//#ifdef BTREE_H
//#define BTREE_H
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
    Node(const elemType &e, Node*L =NULL, Node* R=NULL)
    {
        data=e;
        left=L;right=R;
    }
};

template<class elemType>
class BTree
{
private:
    int stopflag;
    void delTree(Node<elemType> *t);
    void InOrder(Node<elemType> *t);
    void PostOrder(Node<elemType> *t);

public:
    Node<elemType> *root;
    BTree(){root=NULL;}
    //void createTree(const elemType &flag); //创建一棵树
    bool isEmpty(){return (root==NULL);}
    void delTree(){ delTree(root);} //删除树
    void InOrder(){InOrder(root);} //中序遍历
    void PostOrder(){PostOrder(root);} //后序遍历
    void buildTree(Node<elemType> *p);
};

template<class elemType>
void BTree<elemType>::delTree(Node<elemType> *t)
{
    if(!t) return;
    delTree(t->left);
    delTree(t->right);
    delete t;
}

template<class elemType>
void BTree<elemType>::InOrder(Node<elemType> *t)
{
    if (!t) return;
    InOrder(t->left);
    cout << t->data<<" ";
    InOrder(t->right);
}
template<class elemType>
void BTree<elemType>::PostOrder(Node<elemType> *t)
{
    if (!t) return;
    PostOrder(t->left);
    PostOrder(t->right);
    cout << t->data<<" ";
}
/*template <class elemType>
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

}*/
template <class elemType>
void BTree<elemType>::buildTree(Node<elemType> *p)
{
    //Node<elemType> *pl,*pr;
    elemType e;
    cin>>e;
    if(e!='.')
    {
        p->data=e;
        //cout<<p->data;
        p->left=new Node<elemType>;
        buildTree(p->left);
        p->right=new Node<elemType>;
        buildTree(p->right);
    }
    else p= NULL;
}
//#endif