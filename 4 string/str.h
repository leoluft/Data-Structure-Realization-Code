#include<iostream>
using namespace std;
#define MaxLen 1000 // 定长顺序存储字符串最大长度
#define InitSize 100 // 堆分配存储字符串初始长度
#define Increment 100 // 堆分配存储字符串单次增量

// 定长顺序存储字符串
typedef struct{
    char ch[MaxLen]; // 每个分量存储一个字符
    int length; // 串的实际长度
}SString;
// 定长顺序存储字符串的基本操作实现
bool StrAssign(SString &T,char *chars){ // 赋值操作，把串T赋值为chars
    int i;
    for(i=0;chars[i]!='\0';i++){ // 赋值
        T.ch[i] = chars[i];
        if(i>=MaxLen){
            return false; // 串长度超出最大容量
        }
    }
    T.length = i; // 串长度为i
    return true;
}
bool StrCopy(SString &T,SString S){ // 复制操作，由串S复制得到串T
    for(int i=0;i<S.length;i++){ // 逐个字符复制
        T.ch[i] = S.ch[i];
    }
    return true;
}
bool StrEmpty(SString S){ // 判空操作
    if(S.length == 0)return true;
    else return false;
}
int StrCompare(SString S,SString T){ // 比较操作，若S大于T，则返回值大于0，反之返回值小于0，只在相等时返回0
    int mlen; // 保存两个字符串长度最小值
    if(S.length>T.length) mlen = T.length;
    else mlen = S.length;
    for(int i=0;i<mlen;i++){
        if(S.ch[i]>T.ch[i])return 1;
        if(S.ch[i]<T.ch[i])return -1;
    }
    if(S.length>T.length) return 1;
    if(S.length<T.length) return -1;
    return 0;
}
int StrLength(SString S){ // 求串长，返回串S的元素个数
    return S.length;
}
bool SubString(SString &Sub,SString S,int pos,int len){ // 求子串，用sub返回串S第pos个字符起长度为len的字串
    for(int i=0;i<len;i++){
        if(i+pos>S.length){
            Sub.length = i;
            return false; // 请求越界，截断处理
        }
        Sub.ch[i] = S.ch[i+pos-1];
    }
    Sub.length = len;
    return true;
}
bool Concat(SString &T,SString S1,SString S2){ // 串联接，用T返回由S1和S2联接而成的新串
    for(int i=0;i<S1.length;i++){
        T.ch[i] = S1.ch[i];
    }
    for(int i=0;i<S2.length;i++){
        if(i+S1.length+1>MaxLen){
            T.length = S1.length+i;
            return false; // 串超长，截断处理
        }
        T.ch[i+S1.length] = S2.ch[i];
    }
    T.length = S1.length+S2.length;
    return true;
}
int Index(SString S,SString T){ // 定位操作，若主串S中存在与T值相同的字串，则返回它在主串中第一次出现的位置，否则返回0
    return 0;
}
void ClearString(SString &S){ // 清空操作，将S清为空串
    S.length = 0;
}
void DestroyString(SString &S){ // 销毁操作，将串S销毁
}

// 堆分配存储字符串


