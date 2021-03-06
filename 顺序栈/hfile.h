#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;


//基于数组的顺序栈
int chk_data(char *num);//检查输入的数据类型和长度是否正确
Status printStack(SqStack *s);//遍历打印栈
Status initStack(SqStack *s,int sizes);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status pushStack(SqStack *s,ElemType data);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度



#endif 
