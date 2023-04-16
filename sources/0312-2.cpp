#include <iostream>
using namespace std;
template <class elemType>
class seqQueue
{
    private:
        elemType *array;
        int maxsize; //最大长度
        int front,rear; //队首和队尾
        int elemNum; //元素个数
        void doubleSpace();
    public:
        seqQueue(int size=10); //构造函数
        void enQueue(const elemType& x);//进队
        void deQueue();//出队
        int getHead(){return front;}  //输出队头下标
        bool isEmpty(){return front==rear;} //判断队列是否为空
        bool isFull(){return (rear+1)%maxsize==front;}
        ~seqQueue();
};
template <class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    array=new elemType[size];
    maxsize=size;
    front=rear=0;
    elemNum=0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete []array;
}
template <class elemType>
void seqQueue<elemType>::enQueue(const elemType& x)
{
    if(isFull()) doubleSpace();
    array[rear]=x;
    rear=(rear+1) % maxsize;
    elemNum++;
    std::cout<<rear<<" "<<elemNum<<std::endl;
}
template <class elemType>
void seqQueue<elemType>::deQueue()
{
    if(isEmpty()) 
    {
        std::cout<<front<<" "<<elemNum<<std::endl;
        return;
    }
    front=(front+1) % maxsize;
    elemNum--;
    std::cout<<front<<" "<<elemNum<<std::endl;
}
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *newArray;
    int i,j;
    newArray=new elemType[2*maxsize];
    for(i=0,j=front;j!=rear;i++,j=(j+1)%maxsize)
        newArray[i]=array[j];

    delete []array;
    array=newArray;
    front=0;rear=j;
    maxsize=2*maxsize;
}

int main() 
{
    int s,n;
    std::cin>>s>>n;
    seqQueue<int> que(s); //新建队列
    int op,x; //操作数
    for(int i=0;i<n;i++)
    {
        std::cin>>op;
        if(op==0)
        {
            std::cin>>x;
            que.enQueue(x);
        }
        else{
            que.deQueue();
        }
    }
    return 0;
}
