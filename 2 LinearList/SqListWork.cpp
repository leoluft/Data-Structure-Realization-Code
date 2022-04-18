// 线性表作业
#include<iostream>
#include"SqList.h"
//第一题
bool DelMin(SqList &L,ElemType &e){
    if(Empty(L)){
        cout << "线性表为空，删除失败" << endl;
        return false;
    }
    ElemType min = GetElem(L,1);
    int index;
    for(int i=1;i<=Length(L);i++){
        if(GetElem(L,i)<min){
            min = GetElem(L,i);
            index = i;
        }
    }
    ElemType temp = GetElem(L,Length(L));
    ListDelete(L,index,e);
    ListInsert(L,index,temp);
    L.length --;
    return true;
}
void work1(){
    SqList L;
    InitList(L);
    ElemType e;
    for(int i=1;i<=10;i++){
        ListInsert(L,i,((i+3)*5)%8);
    }
    PrintList(L);
    DelMin(L,e);
    cout << "删除的元素为：" << e << endl;
    PrintList(L);
}
//第二题
bool Reverse(SqList &L){
    ElemType temp;
    for(int i=0;i<L.length/2;i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
    return true;
}
void work2(){
    SqList L;
    InitList(L);
    ElemType e;
    for(int i=1;i<=11;i++){
        ListInsert(L,i,((i+3)*5)%8);
    }
    PrintList(L);
    Reverse(L);
    PrintList(L);
}
//第三题
bool Delx(SqList &L,ElemType x){
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}
void work3(){
    SqList L;
    InitList(L);
    ElemType e;
    for(int i=1;i<=11;i++){
        ListInsert(L,i,((i+3)*5)%8);
    }
    PrintList(L);
    Delx(L,5);
    PrintList(L);
}
//第五题
bool DelST(SqList &L,int s,int t){
    if(s>=t){
        cout << "S,T值不合理" << endl;
        return false;
    }
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]<=s||L.data[i]>=t){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    return true;
}
void work5(){
    SqList L;
    InitList(L);
    ElemType e;
    for(int i=1;i<=11;i++){
        ListInsert(L,i,((i+3)*5)%8);
    }
    PrintList(L);
    DelST(L,3,8);
    PrintList(L);
}
//第六题
bool DelRep(SqList &L){
    int k=0;
    ElemType temp = L.data[0];
    for(int i=1;i<L.length;i++){
        if(L.data[i]!=temp){
            L.data[k] = L.data[i];
            k++;
            temp = L.data[i];
        }
    }
    L.length = k;
    return true;
}
void work6(){
    SqList L;
    InitList(L);
    ElemType e;
    for(int i=1;i<=100;i++){
        ListInsert(L,i,i/10*10);
    }
    PrintList(L);
    DelRep(L);
    PrintList(L);
}
//第七题 // ???
SqList Merge(SqList &L1,SqList &L2){
    int i=0,i1=0,i2=0;
    SqList L;
    while(i1<L1.length&&i2<L2.length){
        if(L1.data[i1]<=L2.data[i2]){
            L.data[i++] = L1.data[i1++];
        } else {
            L.data[i++] = L2.data[i2++];
        }
    }
    while(i1<L1.length)
        L.data[i++] = L1.data[i1++];
    while(i2<L2.length)
        L.data[i++] = L2.data[i2++];
    L.length = i;
    return L;
}
void work7(){
    SqList L,L1,L2;
    InitList(L);
    InitList(L1);
    InitList(L2);
    for(int i=1;i<=20;i++){
        ListInsert(L1,i,i);
        ListInsert(L2,i,i+1);
    }
    PrintList(L1);
    PrintList(L2);
    L = Merge(L1,L2);
    PrintList(L);
}
//第九题
bool Searchx(SqList &L,ElemType x){
    int l=0,r=L.length-1;
    while(l<r){
        int mid = l+r >> 1;
        if(L.data[mid]>=x)r=mid;
        else l=mid+1;
    }
    if(l==L.length-1)
        return false;
    if(L.data[l]==x){
        L.data[l] = L.data[l+1];
        L.data[l+1] = x;
    } else {
        for(int i=L.length;i>l;i--){
            L.data[i] = L.data[i-1];
        }
        L.data[l] = x;
        L.length ++;
    }
    return true;
}
void work9(){
    SqList L;
    InitList(L);
    for(int i=1;i<=50;i++){
        ListInsert(L,i,i);
    }
    L.data[9]=9;
    PrintList(L);
    Searchx(L,10);
    PrintList(L);
}



int main(){
    
    return 0;
}