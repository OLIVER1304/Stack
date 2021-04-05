#include <stdio.h>
#include <stdlib.h>
#include "hfile.cpp"
#define SIZE 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkStack *s=(LinkStack *)malloc(sizeof(LinkStack));
	int flag=0;
	while(1) {
		printf("[1]初始化栈                     [2]判断栈是否为空\n");
		printf("[3]入栈                         [4]出栈\n");
		printf("[5]得到栈顶元素                 [6]清空栈\n");
		printf("[7]销毁栈                       [8]检测栈长度\n");
		if(flag==1) {
			printStack(s);
		} else {
			printf("\n未初始化栈\n");
		}
		int chk_data(char *num);
		char str[SIZE];
		printf("\n请输入要执行的操作对应的数字:");
		scanf("%s", &str);
		while (chk_data(str) == 0) {
			printf("输入数据错误，请重新输入:");
			scanf("%s", &str);
			continue;
		}
		int k=atoi(str);
		if(k<=0||k>=9) {
			printf("\n没有对应的操作\n");
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
					printf("\n未初始化栈\n");
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
					printf("请输入数据:");
					scanf("%s", &str);
					while (chk_data(str) == 0) {
						printf("输入数据错误，请重新输入:");
						scanf("%s", &str);
						continue;
					}
					ElemType data=atoi(str);
					pushLStack(s,data);
					printStack(s);
				} else {
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
					printf("\n未初始化栈\n");
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
