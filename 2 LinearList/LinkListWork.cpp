#include"LinkList.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdlib>
using namespace std;
//第一题
bool Delx(LinkList &L,ElemType x){
    LNode *s = L,*r;
    while(s){
        if(s->data == x){
            if(s==L){
                L = L->next;
                free(s);
            } else {
                r->next = s->next;
                free(s);
            }
            s = r;
        }
        r = s;
        s = s->next;
    }
    return true;
}
void work1(){
    LinkList L;
    List_HeadInsert(L);
    PrintList(L);
    Delx(L,10);
    PrintList(L);
}
//第三题
void f(LNode *x){
    if(x->next==NULL){
        cout << x->data << " ";
        return;
    }
    f(x->next);
    cout << x->data << " ";
}
void ReversePrint(LinkList L){
    f(L->next);
}
void work3(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    ReversePrint(L);
}
//第四题
bool DelMin(LinkList &L){
    LNode *pre=L,*p=pre->next,*premin=pre,*min=p;
    while(p){
        if(p->data < min->data){
            premin = pre;
            min = p;
        }
        pre = p;
        p = p->next;
    }
    premin->next = min->next;
    free(min);
    return true;
}
void work4(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    DelMin(L);
    PrintList(L);
}
// 第五题
void Reverse(LinkList &L){
    LNode *r = L->next,*s;
    L->next = NULL;
    while(r){
        s = r;
        r = r->next;
        s->next = L->next;
        L->next = s;
    }
}
void work5(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    Reverse(L);
    PrintList(L);
}
// 第六题
void BubbleSort(LinkList &L){
    for(LNode *prei = L,*i = L->next;i;prei = i,i = i->next){
        for(LNode *prej = prei,*j = i;j;prej = j,j = j->next){
            if(i->data>j->data){
                ElemType temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void work6(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    BubbleSort(L);
    PrintList(L);
}
//第七题
void DelXY(LinkList &L,ElemType x,ElemType y){
    if(x>=y)return;
    LNode *p = L->next,*pre = L;
    while(p){
        if(p->data < y&&p->data > x){
            pre->next = p->next;
            free(p);
            p = pre;
        }
        pre = p;
        p = p->next;
    }
}
void work7(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    DelXY(L,5,10);
    PrintList(L);
}
//第九题
void UpPrint(LinkList &L){
    ElemType temp;
    while(L->next){
        LNode *p = L->next,*pre = L,*min = p,*premin = pre;
        while(p){
            if(p->data < min->data){
                min = p;
                premin = pre;
            }
            pre = p;
            p = p->next;
        }
        premin->next = min->next;
        cout << min->data << " ";
        free(min);
    }
}
void work9(){
    LinkList L;
    List_TailInsert(L);
    PrintList(L);
    UpPrint(L);
}
//第十题
void Apart1(LinkList &A,LinkList &B){
    int i = 1;
    LNode *p = A->next,*pre = A;
    LNode *b = B,*preb;
    while(p){
        if(i%2==0){
            pre->next = p->next;
            p->next = b->next;
            b->next = p;
            b = b->next;
            p = pre;
        }
        i++;
        pre = p;
        p = p->next;
    }
}
void work10(){
    LinkList A,B;
    List_TailInsert(A);
    List_TailInsert(B);
    PrintList(A);
    PrintList(B);
    Apart1(A,B);
    PrintList(A);
    PrintList(B);
}
//第十一题
void Apart2(LinkList &A,LinkList &B){
    int i = 1;
    LNode *p = A->next,*pre = A;
    LNode *b = B,*preb;
    while(p){
        if(i%2==0){
            pre->next = p->next;
            p->next = B->next;
            B->next = p;
            p = pre;
        }
        i++;
        pre = p;
        p = p->next;
    }
}
void work11(){
    LinkList A,B;
    List_TailInsert(A);
    List_TailInsert(B);
    PrintList(A);
    PrintList(B);
    Apart2(A,B);
    PrintList(A);
    PrintList(B);
}
//第十二题
void Unique1(LinkList &L){
    for(LNode *i = L->next;i;i = i->next){
        for(LNode *j = i->next,*prej = i;j;prej = j,j = j->next){
            if(i->data == j->data){
                prej->next = j->next;
                free(j);
                j = prej;
            }
        }
    }
}
void Unique2(LinkList &L){
    bool pd[1000000] = {0};
    LNode *p = L->next,*pre = L;
    while(p){
        if(pd[p->data]==false){
            pd[p->data] = true;
        } else {
            pre->next = p->next;
            free(p);
            p = pre;
        }
        pre = p;
        p = p->next;
    }
}
void work12(){
    LinkList L1,L2;
    L1 = (LNode*)malloc(sizeof(LNode));
    L2 = (LNode*)malloc(sizeof(LNode));
    LNode *s,*r;
    L1->next = NULL;
    L2->next = NULL;
    srand(time(0));
    int i=100000;
    while(i--){
        int temp = rand()%1000000;
        s = (LNode*)malloc(sizeof(LNode));
        s->data = temp;
        s->next = L1->next;
        L1->next = s;
        r = (LNode*)malloc(sizeof(LNode));
        r->data = temp;
        r->next = L2->next;
        L2->next = r;
    }
    clock_t t1,t2,t3;
    t1 = clock();
    Unique1(L1);
    t2 = clock();
    Unique2(L2);
    t3 = clock();
    PrintList(L1);
    PrintList(L2);
    cout << "算法一耗时：" << t2-t1 << "ms" << endl;
    cout << "算法二耗时：" << t3-t2 << "ms" << endl;
}
//第十三题
LinkList Merge(LinkList &A,LinkList &B){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *a = A->next,*b = B->next,*temp;
    while(a&&b){
        if(a->data<b->data){
            temp = a;
            a = a->next;
            temp->next = L->next;
            L->next = temp;
        } else {
            temp = b;
            b = b->next;
            temp->next = L->next;
            L->next = temp;
        }
    }
    while(a){
        temp = a;
        a = a->next;
        temp->next = L->next;
        L->next = temp;
    }
    while(b){
        temp = b;
        b = b->next;
        temp->next = L->next;
        L->next = temp;
    }
    return L;
}
void work13(){
    LinkList A,B,L;
    List_TailInsert(A);
    List_TailInsert(B);
    PrintList(A);
    PrintList(B);
    L = Merge(A,B);
    PrintList(L);
}
//第十四题
LinkList Same(LinkList &A,LinkList &B){
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *a = A->next,*b = B->next,*pre = A;
    while(a&&b){
        if(a->data == b->data)break;
        if(a->data < b->data){
            pre = a;
            a=a->next;
        } 
        else {
            pre = b;
            b = b->next;
        }
    }
    L = pre;
    return L;
}
void work14(){
    LinkList A,B,L;
    List_TailInsert(A);
    List_TailInsert(B);
    PrintList(A);
    PrintList(B);
    L = Same(A,B);
    PrintList(L);    
}
//第十五题 *?
void SameSet(LinkList &A,LinkList &B){
    LNode *a = A->next,*b = B->next,*pre = A;
    while(a&&b){
        if(a->data == b->data){
            pre = a;
            a = a->next;
            b = b->next;
        } else if(a->data < b->data){
            pre->next = a->next;
            free(a);
            a = pre->next;
        } else {
            b = b->next;
        }
    }
    a = NULL;
}
void work15(){
    LinkList A,B;
    List_TailInsert(A);
    List_TailInsert(B);
    PrintList(A);
    PrintList(B);
    SameSet(A,B);
    PrintList(A);    
}


int main(){
    work15();
    return 0;
}