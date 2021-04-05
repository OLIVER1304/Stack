#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkStack *s=(LinkStack *)malloc(sizeof(LinkStack));
	int flag=0;
	while(1) {
		printf("[1]��ʼ��ջ                     [2]�ж�ջ�Ƿ�Ϊ��\n");
		printf("[3]��ջ                         [4]��ջ\n");
		printf("[5]�õ�ջ��Ԫ��                 [6]���ջ\n");
		printf("[7]����ջ                       [8]���ջ����\n");
		if(flag==1) {
			printStack(s);
		} else {
			printf("\nδ��ʼ��ջ\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n������Ҫִ�еĲ�����Ӧ������:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("�������ݴ�������������:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=9) {
			printf("\nû�ж�Ӧ�Ĳ���\n");
			printf("\n");
			system("pause");
			system("cls");
			continue;
		}
		switch(k) {
			case 1: {
				flag=1;
				initLStack(s);
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 2: {
				if(flag==1) {
					isEmptyLStack(s);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 3: {
				if(flag==1) {
					int chk_data(char *num);
					char str[SIZE];
					printf("����������:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("�������ݴ�������������:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					pushLStack(s,data);
					printStack(s);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 4: {
				if(flag==1) {
					ElemType *data=(ElemType*)malloc(sizeof(ElemType));
					popLStack(s,data);
					printStack(s);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 5: {
				if(flag==1) {
					ElemType *e=(ElemType*)malloc(sizeof(ElemType));
					getTopLStack(s,e);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
			case 6: {
				if(flag==1) {
					clearLStack(s);
				} else {
					printf("\nδ��ʼ��ջ\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 7: {
				if(flag==1) {
					destroyLStack(s);
					flag=0;
				} else {
					printf("\nδ��ʼ��ջ\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
			case 8: {
				if(flag==1) {
					int *length=(int *)malloc(sizeof(int));
					LStackLength(s,length);
				} else {
					printf("\nδ��ʼ��ջ\n");
					printf("\n");
				}
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 0;
}
