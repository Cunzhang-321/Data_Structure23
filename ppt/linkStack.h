class outOfBound
{
};
template <class elemType>
class linkStack;

template <class elemType>
class Node
{
    friend class linkStack<elemType>;

private:
    elemType data;
    Node *next;

public:
    Node() { next = NULL; }
    Node(const elemType &x, Node *p = NULL)
    {
        data = x;
        next = p;
    }
};
template <class elemType>
class linkStack
{
private:
    Node<elemType> *Top;

public:
    linkStack() { Top = NULL; };              // 初始化栈，使其为空栈
    bool isEmpty() { return (Top == NULL); }; // 栈为空返回true，否则返回bool isFullO{ return false; }; //栈满true，否则 false。结点空间不连续，elemType top);
    void push(const elemType &e);
    void pop();
    elemType top();
    ~linkStack();
};
template <class elemType>
elemType linkStack<elemType>::top()
{
    if (!Top)
        throw outOfBound0; // 栈空
    return Top->data;
}
template <class elemType>
void linkStack<elemType>::push(const elemType &e)
{
    Top = new Node<elemType>(e, Top);
}

template <class elemType>
void linkStack<elemType>::pop()
{
    Node<elemType> *tmp;
    if (!Top)
        throw outOfBound(); // 栈空
    tmp - Top; // 用tmp 记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; // 实际将栈顶结点弹出栈
    delete tmp; // 释放原栈顶结点空间
}
template <class elemType>
linkStack<elemType>::~linkStack()
{
    Node<elemType> *tmp;
    while(Top)
    {
        tmp=Top;
        Top=Top->next;
        delete tmp;
    }
}