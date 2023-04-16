#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE
    {
        int data;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init()
    {
        // TODO
        head = new NODE;
        head->data = -1;
        head->next = head;
    }
    NODE *move(int i)
    {
        NODE *p = head;
        for (int j = 0; j < i; j++)
        {
            p = p->next;
        }
        return p;
    }
    void insert(int i, int x)
    {
        NODE *a = move(i);
        NODE *b = new NODE;
        b->data = x;
        b->next = a->next;
        a->next = b;
        len++;
    }
    void remove(int i)
    {
        NODE *a = move(i);
        NODE *b;
        b = a->next;
        a->next = b->next;
        delete b;
        len--;
    }
    void remove_insert(int i)
    {
        NODE *p = move(i);
        int x = p->next->data;
        remove(i);
        insert(len, x);
    }
    void get_length()
    {
        cout << len << endl;
    }
    void query(int i)
    {
        if (i < 0 || i > len - 1)
            cout << -1 << endl;
        else
        {
            NODE *p = move(i);
            cout << p->next->data << endl;
        }
    }
    void get_max()
    {
        NODE *p = head;
        if (len > 0)
        {
            int max = p->data;
            while (p->next != head)
            {
                p = p->next;
                if (max < p->data)
                    max = p->data;
            }
            cout << max << endl;
        }
        else
            cout << -1 << endl;
    }
    void clear()
    {
        NODE *q = head;
        NODE *p;
        while (q->next != head)
        {
            p = q->next;
            delete q;
            q = p;
        }
        delete q;
    }
}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch (op)
        {
        case 0:
            LIST::get_length();
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            LIST::query(p);
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            cin >> p;
            LIST::remove_insert(p);
            break;
        case 5:
            LIST::get_max();
            break;
        }
    }
    LIST::clear();
    return 0;
}