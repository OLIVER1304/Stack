#include <stdio.h>
#include <stdlib.h>
#include "hfile.h"


//���������������ͺͳ����Ƿ���ȷ
int chk_data(char *num) {
	int i;
	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] > '9' || num[i] < '0') {
			printf("\n����ֵ���з���ֵ\n");
			return 0;
		}
	}
	if (i > 10) {
		printf("\n���������ֳ���\n");
		return 0;
	}
	return 1;
}


//������ӡջ
Status printStack(LinkStack *s) {
	if(s==NULL||s->count==0) {
		printf("\nջΪ��\n");
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


//��ʼ��ջ
Status initLStack(LinkStack *s) {
	s->count=0;
	s->top=NULL;
	printf("\n��ջ��ʼ���ɹ�\n");
	return SUCCESS;
}


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
	if(s->count==0) {
		printf("\nջΪ��\n");
		return SUCCESS;
	}
	return ERROR;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data) {
	StackNode *node=(StackNode *)malloc(sizeof(StackNode));
	if(node==NULL) {
		printf("\n��̬�����ڴ����\n");
		return ERROR;
	}
	node->data=data;
	node->next=s->top;
	s->top=node;
	s->count++;
	return SUCCESS;
}


//��ջ
Status popLStack(LinkStack *s,ElemType *data) {
	if (s==NULL||s->count==0) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	LinkStackPtr tem=s->top;
	s->top=s->top->next;
	free(tem);
	s->count--;
	return SUCCESS;
}


//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e) {
	if (s==NULL||s->count==0) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	*e=s->top->data;
	printf("\nջ��Ԫ��Ϊ��%d\n",*e);
	return SUCCESS;
}


//���ջ
Status clearLStack(LinkStack *s) {
	if (s==NULL||s->count==0) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	while(s->top!=NULL) {
		LinkStackPtr p=s->top;
		s->top=s->top->next;
		free(p);
	}
	s->count=0;
	printf("\n�ɹ����ջ\n");
	printf("\n");
	return SUCCESS;
}


//����ջ
Status destroyLStack(LinkStack *s) {
	while(s->top!=NULL) {
		LinkStackPtr p=s->top;
		s->top=s->top->next;
		free(p);
		free(s->top);
		printf("\n�ɹ�����ջ\n");
	}
}


//���ջ����
Status LStackLength(LinkStack *s,int *length) {
	if (s==NULL||s->count==0) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	*length=s->count;
	printf("\nջ�ĳ���Ϊ��%d\n",*length);
	printf("\n");
	return SUCCESS;
}



