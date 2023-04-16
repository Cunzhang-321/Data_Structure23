#include <iostream>
using namespace std;
struct node
{
    int data; // 记录编号
    node *next;
    node() : next(NULL){};
    node(int a, node *N = NULL)
    {
        data = a;
        next = N;
    }
};
int main()
{
    int m;
    std::cin >> m;
    int *k = new int[m - 1]; // 保存报出的整数
    for (int j = 0; j < m - 1; j++)
    {
        std::cin >> k[j];
    }
    node *head = new node(0, NULL);
    node *tail = head; // 尾节点
    for (int i = 1; i < m; i++)
    {
        tail->next = new node(i, NULL);
        tail = tail->next;
    }
    tail->next = new node(m, head->next);
    tail = tail->next;
    int len = m;
    int index = 0;
    node *p = tail->next;
    //for (int j = 0; j < m - 1; j++)
    int j=0;
        while (p->next != p)
        {
            //cout<<p->data;
            if (index == k[j] -1)
            {
                p->next = (p->next)->next;
                index = 0;
                j++;
            }
            else index++;
            p=p->next;
        }
    
    std::cout<<p->data;
    return 0;
}