#include<iostream>
#include<cstdlib>
#define MaxSize 50000
using namespace std;
typedef int ElemType;

//单链表
typedef struct LNode{ // 定义单链表节点类型
    ElemType data; // 数据域
    LNode *next; // 指针域
}LNode,*LinkList;
//单链表基本操作的实现
LinkList List_HeadInsert(LinkList &L){ // 头插法建立单链表
    LNode *s;
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode)); // 创建头节点
    L->next = NULL; // 初始为空链表
    cin >> x;
    while(x!=9999){ // 9999表示结束
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}
LinkList List_TailInsert(LinkList &L){ // 尾插法建立单链表
    L = (LinkList)malloc(sizeof(LNode)); // 创建头节点
    LNode *s,*r=L;
    ElemType x;
    L->next = NULL; // 初始为空链表
    cin >> x;
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r=s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}
LNode* GetElem(LinkList L,int i){ // 按序号查找结点
    LNode *s = L;
    int j=0;
    if(i<0) return NULL; // 若i无效则返回NULL
    while(s){
        if(j==i){
            return s;
        }
        j++;
        s = s->next;
    }
    return NULL;
}
LNode* LocateElem(LinkList L,ElemType e){ // 按值查找结点
    LNode *s = L->next;
    while(s){
        if(s->data == e)
            return s; // 查找成功返回节点指针
        s = s->next;
    }
    return NULL; // 查找失败返回NULL
}
bool Insert(LinkList &L,int i,ElemType e){ // 在第i个位置插入元素e
    int j=0;
    LNode *s = L;
    while(s){
        if(j==i){
            LNode *r = (LNode*)malloc(sizeof(LNode));
            r->next = s->next;
            r->data = e;
            s->next = r;
            return true; // 插入成功
        }
        s = s->next;
        j++;
    }
    return false; // 插入失败
}
bool DeleteNode(LinkList &L,int i,ElemType &e){ // 删除第i个位置的元素，用e返回删除结点的数据
    LNode *r = L,*s = L->next;
    int j = 1;
    while(s){
        if(j==i){
            r->next = s->next;
            free(s);
            return true; // 查找成功
        }
        r = s;
        s = s->next;
        j++;
    }
    return false; // 查找失败
}
int Length(LinkList L){ // 求单链表长度
    int i=0;
    LNode *s = L;
    while(s->next){
        s = s->next;
        i++;
    }
    return i;
}
void PrintList(LinkList L){
    LNode *s = L->next;
    while(s){
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}

// 双链表
typedef struct DNode{ // 定义双链表结点类型
    ElemType data; // 数据域
    DNode *prior,*next; // 前驱和后继指针
}DNode,*DLinkList;
//双链表基本操作的实现
bool Insert(DLinkList &L,int i,ElemType e){ // 在第i个位置插入元素e
    DNode *s = L;
    int j=0;
    while(s){
        if(j==i){
            DNode *temp = (DNode*)malloc(sizeof(DNode));
            temp->next = s->next;
            temp->prior = s;
            s->next->prior = temp;
            s->next = temp;
            return true;
        }
        s = s->next;
        j++;
    }
    return false;
}
bool DeleteNode(DLinkList &L,int i,ElemType &e){ // 删除第i个位置的元素，用e返回删除结点的数据
    int j=1;
    DNode *s = L->next;
    while(s){
        if(j==i){
            s->next->prior = s->prior;
            s->prior->next = s->next;
            free(s);
            return true;
        }
        s = s->next;
        j++;
    }
    return false;
}

//静态链表
typedef struct{
    ElemType data;
    int next;
}SLinkList[MaxSize];







