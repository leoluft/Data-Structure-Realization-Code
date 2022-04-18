#include"stack.h"
#include<iostream>
using namespace std;
string expression;
LinkStack stack;

bool isOp(char ch){
    char op[6] = {'+','-','*','/','(',')'};
    for(int i=0;i<=5;i++){
        if(ch == op[i])
            return true;
    }
    return false;
}

void PrifixWork(){

}

void InfixWork(){
    LinkStack num,op;
    string postfix_expression;
    InitStack(num);InitStack(op);
    for(int i=0;i<expression.length();i++){
        if(isOp(expression[i])){
            if(expression[i]=='(')Push(op,'(');
            else if(expression[i]==')'){
                while(1){
                    int ch;Pop(op,ch);
                    if(ch=='(')break;
                    postfix_expression.push_back(ch);
                }
            } else {
                if(expression[i]=='*'||expression[i]=='/'){
                    while(1){
                        int ch;GetTop(op,ch);
                        if(ch=='*'||ch=='/'){
                            Pop(op,ch);
                            postfix_expression.push_back(ch);
                        } else break;
                    }
                    Push(op,expression[i]);
                }
                if(expression[i]=='+'||expression[i]=='-'){
                    while(1){
                        int ch;GetTop(op,ch);
                        if(ch!='('&&!StackEmpty(op)){
                            Pop(op,ch);
                            postfix_expression.push_back(ch);
                        } else break;
                    }
                    Push(op,expression[i]);
                }
            }
            
        } else {
            postfix_expression.push_back(expression[i]);
        }
    }
    while(!StackEmpty(op)){
        int ch;Pop(op,ch);
        postfix_expression.push_back(ch);
    }
    cout << "后缀表达式为：" << postfix_expression << endl;
}

void PostfixWork(){
    InitStack(stack);
    for(int i=0;i<expression.length();){
        if(isOp(expression[i])){
            int a,b;
            Pop(stack,b);Pop(stack,a);
            switch (expression[i])
            {
                case '+': Push(stack,a+b);break;
                case '-': Push(stack,a-b);break;
                case '*': Push(stack,a*b);break;
                case '/': Push(stack,a/b);break;
            }
            i++;
        } else {
            int num = 0;
            while(!isOp(expression[i])&&expression[i]!=' '){
                num *= 10;
                num += expression[i]-'0';
                i++;
                if(expression[i]==' '||isOp(expression[i])){
                    Push(stack,num);
                    break;
                }
            }
            if(expression[i]==' ')i++;
        }
    }
    int value;
    Pop(stack,value);
    cout << "此后缀表达式值为：" << value << endl;
}

int main(){
    string s;
    cout << "请输入表达式类型:" << endl;
    cout << "1:前缀表达式 2:中缀表达式 3:后缀表达式" << endl;
    int type;cin >> type;
    getchar();
    cout << "请输入表达式:" << endl;
    char ch;
    while ((ch=getchar())!='\n')
    {
        expression.push_back(ch);
    }
    switch (type){
        case 1: PrifixWork();break;
        case 2: InfixWork();break;
        case 3: PostfixWork();break;
        default: cout << "请输入正确数据！" << endl;
    }
    return 0;
}