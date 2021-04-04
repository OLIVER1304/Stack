#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"

//检查输入的数据类型和长度是否正确
int chk_data(char *num) {
	int i;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] > '9' || num[i] < '0') {
			printf("\n传入值含有非数值\n");
			return 0;
		}
	}
	if (i > 10) {
		printf("\n超出了数字长度\n");
		return 0;
	}
	return 1;
}


//遍历打印栈
Status printStack(SqStack *s) {
	if(s->size==0) {
		printf("\n栈的大小为0\n");
		return ERROR;
	}
	if(s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return ERROR;
	}
	printf("\n");
	for(int i=0; i<=s->top; i++) {
		printf("|%d",s->elem[i]);
	}
	printf("\n");
	return SUCCESS;
};


//初始化栈
Status initStack(SqStack *s,int sizes) {
	if(sizes<=0) {
		printf("大小应该大于0\n");
		return ERROR;
	}
	s->top=-1;
	s->size=sizes;
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	printf("\n成功初始化一个大小为 %d 的栈\n", sizes);
	return SUCCESS;
};


//判断栈是否为空
Status isEmptyStack(SqStack *s) {
	if (s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return SUCCESS;
	}
	printf("\n栈不为空\n");
	return ERROR;
};


//入栈
Status pushStack(SqStack *s,ElemType data) {
	/*printf("size=%d\n",s->size);
	printf("top=%d\n",s->top);*/
	if (s->size<=s->top+1) {
		printf("\n栈已满\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	printf("\n成功使 %d 入栈\n", data);
	return SUCCESS;
};


//出栈
Status popStack(SqStack *s,ElemType *data) {
	if (s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	printf("\n成功使 %d 出栈\n",*data);
	return SUCCESS;
};


//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e) {
	if (s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return ERROR;
	}
	*e=s->elem[s->top];
	printf("\n栈顶元素为；%d\n",*e);
	return SUCCESS;
};


//清空栈
Status clearStack(SqStack *s) {
	if (s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return ERROR;
	}
	s->top=-1;
	printf("\n成功清空栈");
	return SUCCESS;
};


//销毁栈
Status destroyStack(SqStack *s) {
	if(s->elem==NULL) {
		printf("\n栈不存在\n");
		return ERROR;
	}
	free(s->elem);
	s->elem==NULL;
	printf("\n成功销毁栈\n");
	return SUCCESS;
};


//检测栈长度
Status stackLength(SqStack *s,int *length) {
	if (s==NULL||s->top==-1) {
		printf("\n栈为空\n");
		return ERROR;
	}
	*length=s->top+1;
	printf("\n栈的长度为: %d\n",*length);
};



