#include<iostream>
#define InitSize 100 // 动态分配顺序表初始长度
#define Increment 100 // 动态顺序表的一次增量
using namespace std;
typedef int ElemType; //定义ElemType数据类型
bool ErrTrace = false; //是否显示错误信息

// //顺序表静态分配
//const int MaxSize = 500; // 静态分配顺序表最大长度
// typedef struct{
//     ElemType data[MaxSize]; // 顺序表的元素
//     int length; // 顺序表当前长度
// }SqList;

//顺序表动态分配
typedef struct{
    ElemType *data; // 顺序表的元素
    int MaxSize; // 顺序表最大长度
    int length; // 顺序表当前长度
}SqList;

// 顺序表基本操作的实现
bool InitList(SqList &L){ // 初始化动态分配顺序表
    L.data = new ElemType[InitSize];
    if(L.data == NULL){
        if(ErrTrace)
            cout << "线性表初始化失败"  << endl;
        return false; // 初始化失败
    }
    L.length = 0; // 线性表初始长度为0 
    L.MaxSize = InitSize; // 初始最大长度
    return true;
}
int Length(SqList L){ // 求表长，返回线性表L的长度，即L中元素个数
    return L.length; // 返回表长
}
int LocateElem(SqList L,ElemType e){ // 按值查找操作，返回元素位序，失败返回-1
    int len = Length(L);
    for(int i=0;i<=len;i++){
        if(L.data[i]==e)
            return i+1; // 查找成功返回元素位序
    }
    return -1; // 查找失败返回-1
}
ElemType GetElem(SqList L,int i){ // 按位查找操作，返回位序为i的元素
    int len = Length(L);
    if(i>len||i<1){
        if(ErrTrace)
            cout << "按位查找位序越界" << endl;
        return NULL; // 查找越界，返回空值
    }
    return L.data[i-1]; // 查找成功返回元素
}
bool ListInsert(SqList &L,int i,ElemType e){ // 插入操作，在L的第i个位置插入元素e
    int len = Length(L);
    if(i<1||i>len+1){
        if(ErrTrace)
            cout << "插入操作位序越界" << endl;
        return false;
    }
    if(len>=L.MaxSize){
        if(ErrTrace)
            cout << "表长达到最大值，无法插入元素" << endl;
        return false;
    }
    for(int j = len;j>=i;j--){ // 将i后所有元素后移一位
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e; // 在位置i处放入e
    L.length++; // 表长+1
    return true;
}
bool ListDelete(SqList &L,int i,ElemType &e){ // 删除操作，在L的第i个位置删除元素并用e返回
    int len = Length(L);
    if(i<1||i>len+1){
        if(ErrTrace)
            cout << "删除操作位序越界" << endl;
        return false;
    }
    e = L.data[i-1]; // 把要删除的元素赋值给e
    for(int j=i;j<len;j++){ // 第i个元素后所有元素前移一位
        L.data[j-1] = L.data[j];
    }
    L.length --; // 线性表长减一
    return true;
}
void PrintList(SqList L){ // 按前后顺序输出线性表L中的所有值
    int len = Length(L);
    for(int i=0;i<len;i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
}
bool Empty(SqList L){ // 判断表L是否为空，是返回true，否返回false
    if(L.length==0)
        return true;
    else return false;
}
void DestroyList(SqList &L){ // 销毁线性表L并释放所占空间
    free(L.data); // 释放空间
    L.length = 0; // 长度置零
}


