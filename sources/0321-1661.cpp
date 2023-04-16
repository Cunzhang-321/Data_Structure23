#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node():next(NULL){};
    node(const int &e, node *N=NULL)
    {  data = e; next = N; };
};
struct LinkedList {
    node *head;
    int len=0;
    // todo: some variables here
    void initialize() {
        int n;
        scanf("%d", &n);
        int *a = new int[n];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        // todo
        head = new node();
        head->next=new node(a[0],NULL);
        for(int i = 1; i < n; i++) this->insert(i,a[i]);
        delete[] a;
        len=n;
    }

    void insert(int i, int x) //在单链表第i个数后面插入一个数x
    {
        if (i<1) return;//下标越界
        int j=0; node *tmp,*p=head;
        while (p&&j<i)
        {  j++;
            p=p->next;
        }
        if (!p) return;//i后面没有
        tmp = new node(x, p->next);
        p->next = tmp;
        len++;
    }

    void erase(int i) //删除单链表第i 个数
    {
        if(i<1) return;//下标越界
        int j=0;
        node *tmp,*p=head;
        while (p&&j<i-1)
        {
            j++;
            p=p->next;
        }
        if (!p && !p->next) return; //后面为空
        tmp=p->next;
        p->next = tmp->next;
        delete tmp;
        len--;
    }

    void swap() {
        node *p, *q;
        if (len == 1 || len == 0) return;
        p = head;
        q = p->next;
        q = q->next;
            while (q && q->next) {
                (p->next)->next = q->next;
                q->next = p->next;
                p->next = q;

                p = q->next;
                q = p->next;
                q = q->next;
            }

        if (len % 2 == 0){
            //cout<<p->data<<q->data;
            //int x=0;
            q->next=p->next;
            (p->next)= q;
           ((q->next)->next)=NULL;
            //q->next=NULL;
        }
    }

    void moveback(int i, int x)//将单链表前i个数整体往后移动x位
    {
        // todo
        int j=0;
        node *tmp,*p=head,*q;
        while (p&&j<i)
        {
            j++;
            p=p->next;
        }
        q=tmp=p->next;
        for(int k=1;k<x;k++)
            tmp=tmp->next;
        p->next=tmp->next;
        tmp->next=head->next;
        head->next=q;
    }

    int query(int i) //输出单链表第  i 个数
    {
        if (i<1) return NULL ;
        int j=1;
        node *p = head->next;
        while (p&&j<i) {p=p->next; j++;}
        return p->data;
    }

    void printAll() {
        node *p=head->next;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    void ClearMemory() {
        node *p,*q;
        p=head->next;
        head->next=NULL;
        while (p)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }
    ~LinkedList()
    {
        delete head;
    }
};

int main() {
    LinkedList List;
    int m, op, i, x;
    List.initialize();
    scanf("%d", &m);
    while(m--) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d%d", &i, &x);
            List.insert(i, x);
        }
        else if(op == 2) {
            scanf("%d", &i);
            List.erase(i);
        }
        else if(op == 3) {
            List.swap();
        }
        else if(op == 4) {
            scanf("%d%d",&i, &x);
            List.moveback(i, x);
        }
        else if(op == 5) {
            scanf("%d", &i);
            printf("%d\n", List.query(i));
        }
        else if(op == 6) {
            List.printAll();
        }
    }
    List.ClearMemory();
    return 0;
}