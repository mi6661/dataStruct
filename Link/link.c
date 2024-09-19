#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Node {
    int id;
    char name[100];
    struct Node *next;
}node;




int main(){
    printf("Hello World");

    //头尾节点的申请
    node *head = (node *)malloc(sizeof(node));
    node *end = (node *)malloc(sizeof(node));
    node *fresh = (node *)malloc(sizeof(node));

    //判断内存申请是否成功，若不成功则终止程序
    if(head == NULL ||end == NULL || fresh == NULL) {
        printf("Error");
        exit(1);
    }
    end->id = -1;//id=-1作为循环的结束条件
    head->next = fresh;


    //设置需要存入链表的数据集合

    char name[5][100] = {"zhangsan","lisi","wangwu","zoumin","leijun"};


    //通过循环注入数据
    for(int i = 0; i < 5; i++) {
        node *temp = (node*)malloc(sizeof(node));
        if(temp == NULL) {
            printf("Error");
            exit(1);
        }
        temp->id = i;
        strcpy(temp->name,name[i]);

        fresh->next = temp;
        fresh = fresh->next;
    }

    fresh->next = end;

    //循环输出

    for(node *temp = head;temp->id!=-1;temp = temp->next) {
        printf("%d %s\n",temp->id,temp->name);
    }

    return 0;
 }