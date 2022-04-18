#include<iostream>
using namespace std;
#define MaxSize 10000;
typedef int ElemType;

// 循环队列
typedef struct{
    ElemType data[MaxSize]; // 存放队列元素
    int front,rear; // 队头，队尾指针
}SqQueue;
// 循环队列的基本操作
void InitQueue(SqQueue &Q){ // 初始化队列，构造一个空队列Q
    Q.front = Q.rear = 0;
}
bool QueueEmpty(SqQueue Q){ // 判队列空，为空返回true，否则返回false
    if (front == rear)
        return true;
    else return false;
}
bool EnQueue(SqQueue &Q,ElemType x){ // 入队，若Q未满，将x加入使之成为新的队尾
    if((Q.rear+1)%MaxSize == Q.front){
        return false; // 队满
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q,ElemType &x){ // 出队，若Q非空，删除队头元素并用x返回
    if(Q.rear == Q.front)
        return false; // 队空
    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    return true;
}
void GetHead(SqQueue Q,ElemType &x){ // 读队头元素，若队列Q非空，将队头元素赋给x
    if(Q.rear == Q.front)
        return false; // 队空
    x = Q.data[Q.front];
    return true;
}
int QueueLength(SqQueue Q){ // 获取队列长度，即队列中元素个数
    int len;
    len = (Q.rear-Q.front+MaxSize)%MaxSize;
    return len;
}

// 链式队列
typedef struct{ // 链式队列结点
    ElemType data;
    LinkNode *next;
}LinkNode;
typedef struct{ // 链式队列
    LinkNode *front,*rear; // 队列的队头和队尾指针
}LinkQueue;
// 链式队列的基本操作
void InitQueue(LinkQueue &Q){ // 初始化队列，构造一个空队列Q
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool QueueEmpty(LinkQueue Q){ // 判队列空，为空返回true，否则返回false
    if(Q.front->next == NULL)
        return true;
    else return false;
}
void EnQueue(LinkQueue &Q,ElemType x){ // 入队，将x加入使之成为新的队尾
    LinkNode *p;
    p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}
bool DeQueue(LinkQueue &Q,ElemType &x){ // 出队，若Q非空，删除队头元素并用x返回
    if(Q.front->next == NULL)
        return false; // 队空
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    free(p);
    return true;
}
void GetHead(LinkQueue Q,ElemType &x){ // 读队头元素，若队列Q非空，将队头元素赋给x
    if(Q.front->next == NULL)
        return false; // 队空
    LinkNode *p = Q.front->next;
    x = p->data;
    return true;
}
int QueueLength(LinkQueue Q){ // 获取队列长度，即队列中元素个数
    int len = 0;
    LinkNode *p = Q.front;
    while(p->next){
        p = p->next;
        len ++;
    }
    return len;
}
