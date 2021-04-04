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
Status printStack(LinkStack *s) {
	if(s==NULL||s->count==0) {
		printf("\n栈为空\n");
		return ERROR;
	}
	LinkStackPtr p=s->top;
	printf("\n");
	printf("head->");
	for(int i=0; i<s->count; i++) {
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL");
	printf("\n");
	return SUCCESS;
};


//初始化栈
Status initLStack(LinkStack *s) {
	s->count=0;
	s->top=NULL;
	printf("\n链栈初始化成功\n");
	return SUCCESS;
}


//判断栈是否为空
Status isEmptyLStack(LinkStack *s) {
	if(s->count==0) {
		printf("\n栈为空\n");
		return SUCCESS;
	}
	return ERROR;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data) {
	StackNode *node=(StackNode *)malloc(sizeof(StackNode));
	if(node==NULL) {
		printf("\n动态分配内存出错\n");
		return ERROR;
	}
	node->data=data;
	node->next=s->top;
	s->top=node;
	s->count++;
	return SUCCESS;
}


//出栈
Status popLStack(LinkStack *s,ElemType *data) {
	if (s==NULL||s->count==0) {
		printf("\n栈为空\n");
		return ERROR;
	}
	LinkStackPtr tem=s->top;
	s->top=s->top->next;
	free(tem);
	s->count--;
	return SUCCESS;
}


//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e) {
	if (s==NULL||s->count==0) {
		printf("\n栈为空\n");
		return ERROR;
	}
	*e=s->top->data;
	printf("\n栈顶元素为：%d\n",*e);
	return SUCCESS;
}


//清空栈
Status clearLStack(LinkStack *s) {
	if (s==NULL||s->count==0) {
		printf("\n栈为空\n");
		return ERROR;
	}
	while(s->top!=NULL) {
		LinkStackPtr p=s->top;
		s->top=s->top->next;
		free(p);
	}
	s->count=0;
	printf("\n成功清空栈\n");
	printf("\n");
	return SUCCESS;
}


//销毁栈
Status destroyLStack(LinkStack *s) {
	while(s->top!=NULL) {
		LinkStackPtr p=s->top;
		s->top=s->top->next;
		free(p);
		free(s->top);
		printf("\n成功销毁栈\n");
	}
}


//检测栈长度
Status LStackLength(LinkStack *s,int *length) {
	if (s==NULL||s->count==0) {
		printf("\n栈为空\n");
		return ERROR;
	}
	*length=s->count;
	printf("\n栈的长度为：%d\n",*length);
	printf("\n");
	return SUCCESS;
}



