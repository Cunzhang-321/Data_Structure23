#include <iostream>

using namespace std;

template<class elemType>
class seqStack {
private:
    elemType *array;
    int Top;//栈顶下标
    int maxsize;

    void doubleSpace();

public:
    //int Top;//栈顶下标
    seqStack(int size = 1000);
    bool isEmpty() { return (Top == -1); };
    bool isFull() { return (Top == maxsize - 1); };
    void printTop(); //输出栈顶元素（栈空则忽略此操作）
    elemType top(){return array[Top];};
    void push(const elemType &e);
    void pop();
    //bool isPair();
    ~seqStack() { delete[]array; }
};

/*template<class elemType>
bool seqStack<elemType>::isPair() {
    if(Top%2==0)
    return false;
    for(int j=0;j<=Top/2;j++)
    {
        if(array[j]=='(')
        {
            if(array[Top-j]==')') continue;
            else return false;
        }
    }
    return true;
}*/

template<class elemType>
seqStack<elemType>::seqStack(int size)
{
    array=new elemType[size];
    maxsize=size;
    Top=-1;
}

template<class elemType>
void seqStack<elemType>::doubleSpace() {
    elemType *tmp;
    int i;
    tmp = new elemType[maxsize * 2];
    for (i = 0; i <= Top; i++) tmp[i] = array[i];
    delete[]array;
    array = tmp;
    maxsize *= 2;
}
template<class elemType>
void seqStack<elemType>::printTop()
{
    if(isEmpty()) return;
    cout<< array[Top]<< endl;
}
template<class elemType>
void seqStack<elemType>::push(const elemType &e)
{
    if(isFull()) doubleSpace();
    Top++;
    array[Top]=e;
}
template<class elemType>
void seqStack<elemType>::pop()
{
    if(isEmpty()) return;
    Top--;
}
int main()
{
    int n;
    cin >> n;
    int op;//操作数
    char input;//入栈元素
    seqStack<char> s1(1000005);
    seqStack<char> s2(1000005);
    seqStack<bool> pair(1000005);
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        switch (op)
        {
            case 1:
                cin>>input;
                s1.push(input);
                if(input==')'&&(!s2.isEmpty())&&s2.top()=='(')
                {
                    s2.pop(); pair.push(true);
                }
                else if(input==']'&&(!s2.isEmpty())&&s2.top()=='[')
                {
                    s2.pop(); pair.push(true);
                }
                else if(input=='}'&&(!s2.isEmpty())&&s2.top()=='{')
                {
                    s2.pop(); pair.push(true);
                }
                else
                {s2.push(input); pair.push(false);}
                break;
            case 2:
                input=s1.top();
                if(pair.top())
                {
                    if(input==')')
                        s2.push('(');
                    else if(input==']')
                        s2.push('[');
                    else if(input=='}')
                        s2.push('{');
                }
                else
                    s2.pop();
                s1.pop();pair.pop();
                break;
            case 3:
                s1.printTop();
                break;
            case 4:
                if(s2.isEmpty())
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
                break;

        }
    }
    return 0;
}
