#include <stdio.h>
#include <stdlib.h>  //malloc时用
#include <ctype.h>   //isdigit时用
#include <stdbool.h> //使用bool值

//测试数据1.2 1.3 + 2 4.2 * -

#define MAXOP 100           //操作数可能的最大长度
#define INFINITY 1e9        //代表正无穷
#define ERROR -1e9          //代表正常栈元素取不到的值
typedef double ElementType; //将堆栈元素类型具体化
typedef enum { num, opr, end } Type;
//默认内部赋值为0,1,2。。。 依次对应运算数、运算符、字符串结尾
// typedef enum { false, true } bool;

//堆栈的实现
typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode {
    ElementType* Data; //存储元素的数组
    Position Top;      //栈顶指针
    int MaxSize;       //堆栈最大容量
};
typedef PtrToSNode Stack;
//顺序栈的创建
Stack CreateStack(int MaxSize) {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
//顺序栈的入栈操作
bool IsFull(Stack S) {
    return (S->Top == S->MaxSize - 1);
}
bool Push(Stack S, ElementType X) {
    if (IsFull(S)) {
        printf("Stack is full!");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}
//顺序栈的出栈操作
bool IsEmpty(Stack S) {
    return (S->Top == -1);
}
ElementType Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Stack is empty!");
        return ERROR;
    }
    else
        return (S->Data[(S->Top)--]);
}

Type GetOp(char* Expr, int* start, char* str) {              //从start开始读入一个对象，存在字符串str中
    int i = 0; //跳过表达式前的空格
    while ((str[0] = Expr[(*start)++]) == ' ');
    while (str[i] != ' ' && str[i] != '\0')
        str[++i] = Expr[(*start)++];
    if (str[i] == '\0') // 如果读到输入的结尾
        (*start)--;     //*start指向结束符
    str[i] = '\0';      //结束一个对象的获取
    if (i == 0)
        return end;                              //读到了结束
    else if (isdigit(str[0]) || isdigit(str[1])) //如果str[0]是数字、或者符号跟数字
        return num;                              //表示此str中存的是数字
    else                                         //如果str中不是空串也不是数字
        return opr;                              //表示此时str中为一个运算符
}

ElementType PostfixExp(char* Expr) {
    Stack S;
    Type T;
    ElementType Op1, Op2;
    char str[MAXOP];
    int start = 0;
    S = CreateStack(MAXOP);
    Op1 = Op2 = 0;
    while ((T = GetOp(Expr, &start, str)) != end) { //当读到输入结束时
        if (T == num)
            Push(S, atof(str));
        else {
            if (!IsEmpty(S))
                Op2 = Pop(S);
            else
                Op2 = INFINITY;
            if (!IsEmpty(S))
                Op1 = Pop(S);
            else
                Op2 = INFINITY;
            switch (str[0]) {
                case '+':
                    Push(S, Op1 + Op2);
                    break;
                case '-':
                    Push(S, Op1 - Op2);
                    break;
                case '*':
                    Push(S, Op1 * Op2);
                    break;
                case '/':
                    if (Op2 != 0.0) //检查除法的分母是否为零
                        Push(S, Op1 / Op2);
                    else {
                        printf("ERROR:The dividing denominator is zero!");
                        Op2 = INFINITY;
                    }
                    break;
                default:
                    printf("ERROR:Unknown operator %s\n", str);
                    Op2 = INFINITY;
                    break;
            }
            if (Op2 >= INFINITY)
                break;
        }
    }
    if (Op2 < INFINITY) { //如果处理完了表达式
        if (!IsEmpty(S))  //而此时堆栈正常
            Op2 = Pop(S); //记录计算结果
        else
            Op2 = INFINITY; //否则标记错误
    }

    free(S); //释放堆栈
    return Op2;
}

int main() {
    char Expr[MAXOP];
    ElementType f;
    gets(Expr);
    f = PostfixExp(Expr);
    if (f < INFINITY)
        printf("%.4f\n", f);
    else
        printf("Expression error");
    return 0;
}