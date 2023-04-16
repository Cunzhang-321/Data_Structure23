//#ifdef SEQSTACK_H
//#define SEQSTACK_H

//class illegalSize
//{};
//class outOfBound
//{};
template <class elemType>
class seqStack
{
private:
    elemType *array;
    int Top;
    int maxSize;
    void doubleSpace();

public:
    seqStack(int initSize = 100);                  // 初始化顺序栈
    int isEmpty() { return (Top == -1); };         // 栈空返回true，否则返回false
    int isFull() { return (Top == maxSize - 1); }; // 栈满返回true，否则返回false
    elemType top();                                // 返回栈顶元素的值
    void push(const elemType &e);                  // 压栈
    void pop();                                    // 弹栈
    ~seqStack() { delete[] array; };                // 释放栈占用的动态数组
};
template <class elemType>
seqStack<elemType>::seqStack(int initSize) // 初始化顺序栈
{
    array = new elemType[initSize];
    //if (!array)
        //throw illegalSize();
    Top = -1;
    maxSize = initSize;
}
template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp;

    int i;

    tmp = new elemType[maxSize * 2];

   // if (!tmp) throw illegalSize(O;

for(i= 0; i<=Top; i++)tmp[i]=array[i];//逐个复制结点

delete []array;

array=tmp;

maxSize=2*maxSize;
}
template <class elemType>

elemType seqStack<elemType>::top() // 返回栈顶元素的值，不改变栈顶
{
//if (isEmpty(0) throw outOfBound();

return array[Top];
}
template <class elemType>

void seqStack<elemType>::push(const elemType &e) // 压栈
{
if (isFull())
    doubleSpace(); // 栈满时重新分配2倍的空间，并拷入原空间内容将
array[++Top] = e;  // 新结点放入新的栈顶位置
}
template <class elemType>
void seqStack<elemType>::pop() // 弹栈
{
//if (Top == -1)
    //throw outOfBound();
Top--;
}
//#endif