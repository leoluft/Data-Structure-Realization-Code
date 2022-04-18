#include<iostream>
#define MaxSize 1000 // 定义栈中元素最大个数
using namespace std;
typedef int ElemType; // 定义元素类型
// 顺序栈
typedef struct{
    ElemType data[MaxSize]; // 存放栈中元素
    int top; // 栈顶指针
}SqStack;
// 顺序栈的基本操作
bool InitStack(SqStack &S){ // 初始化一个空栈S
    S.top = -1;
    return true;
}
bool StackEmpty(SqStack S){ // 判断栈S是否为空，是返回true，否返回false
    if(S.top == -1)return true;
    else return false;
}
bool Push(SqStack &S,ElemType x){ // 进栈，若S未满，将x加入成为新栈顶
    if(S.top == MaxSize-1)
        return false; // 栈满
    S.top ++; // 栈顶指针加一
    S.data[S.top] = x; // 赋值
    return true;
}
bool Pop(SqStack &S,ElemType &x){ // 出栈，若S非空，弹出栈顶元素并用x返回
    if(S.top==-1)
        return false;
    x = S.data[S.top]; // 将栈顶元素赋给x
    S.top --; // 栈顶指针减一
    return true;
}
bool GetTop(SqStack &S,ElemType &x){ // 获取栈顶元素，若S非空，则用x返回栈顶元素
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
bool ClearStack(SqStack &S){ // 清空栈
    S.top = -1;
    return true;
}

// 链栈
typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
}*LinkStack;
// 链栈的基本操作
bool InitStack(LinkStack &S){ // 初始化一个链栈
    S = (LinkNode*)malloc(sizeof(LinkNode));
    S->next = NULL;
    return true;
}
bool StackEmpty(LinkStack &S){ // 判断链栈S是否为空，是返回true，否返回false
    if(S->next==NULL) return true;
    else return false;
}
bool Push(LinkStack &S,ElemType x){ // 进栈，将s放置在栈顶
    LinkNode *s;
    s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}
bool Pop(LinkStack &S,ElemType &x){ // 出栈，把栈顶元素弹出并用x返回
    if(S->next==NULL){
        x = NULL;
        return false;
    }
    LinkNode *s = S->next;
    x = s->data;
    S->next = s->next;
    free(s);
    return true;
}
bool GetTop(LinkStack S,ElemType &x){ // 获取栈顶元素并用x返回
    if(S->next==NULL){
        x = NULL;
        return false;
    }
    x = S->next->data;
    return true;
}
bool DestroyStack(LinkStack &S){ // 销毁链栈并释放所占内存空间
    LinkNode *s = S->next;
    while(s){
        S->next = s->next;
        free(s);
        s = S->next;
    }
    free(S);
    return true;
}

