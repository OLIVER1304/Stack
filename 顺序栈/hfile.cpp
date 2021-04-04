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
Status printStack(SqStack *s) {
	if(s->size==0) {
		printf("\nջ�Ĵ�СΪ0\n");
		return ERROR;
	}
	if(s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	printf("\n");
	for(int i=0; i<=s->top; i++) {
		printf("|%d",s->elem[i]);
	}
	printf("\n");
	return SUCCESS;
};


//��ʼ��ջ
Status initStack(SqStack *s,int sizes) {
	if(sizes<=0) {
		printf("��СӦ�ô���0\n");
		return ERROR;
	}
	s->top=-1;
	s->size=sizes;
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	printf("\n�ɹ���ʼ��һ����СΪ %d ��ջ\n", sizes);
	return SUCCESS;
};


//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s) {
	if (s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return SUCCESS;
	}
	printf("\nջ��Ϊ��\n");
	return ERROR;
};


//��ջ
Status pushStack(SqStack *s,ElemType data) {
	/*printf("size=%d\n",s->size);
	printf("top=%d\n",s->top);*/
	if (s->size<=s->top+1) {
		printf("\nջ����\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	printf("\n�ɹ�ʹ %d ��ջ\n", data);
	return SUCCESS;
};


//��ջ
Status popStack(SqStack *s,ElemType *data) {
	if (s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	printf("\n�ɹ�ʹ %d ��ջ\n",*data);
	return SUCCESS;
};


//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e) {
	if (s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	*e=s->elem[s->top];
	printf("\nջ��Ԫ��Ϊ��%d\n",*e);
	return SUCCESS;
};


//���ջ
Status clearStack(SqStack *s) {
	if (s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	s->top=-1;
	printf("\n�ɹ����ջ");
	return SUCCESS;
};


//����ջ
Status destroyStack(SqStack *s) {
	if(s->elem==NULL) {
		printf("\nջ������\n");
		return ERROR;
	}
	free(s->elem);
	s->elem==NULL;
	printf("\n�ɹ�����ջ\n");
	return SUCCESS;
};


//���ջ����
Status stackLength(SqStack *s,int *length) {
	if (s==NULL||s->top==-1) {
		printf("\nջΪ��\n");
		return ERROR;
	}
	*length=s->top+1;
	printf("\nջ�ĳ���Ϊ: %d\n",*length);
};



