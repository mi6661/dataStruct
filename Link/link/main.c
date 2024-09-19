#include <math.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct List
{
    int number;
    struct List *next;
}list;


list* createList(int number[],int length);
list* merger(list* SA, list* SB);

int main(){
    int numbers1[]={1,3,34,39,55,67,77,100};
    int numbers2[]={2,6,12,19,33,78,99};
    list* SA = createList(numbers1,sizeof(numbers1)/sizeof(int))->next;
    list* SB = createList(numbers2,sizeof(numbers2)/sizeof(int))->next;
    list* head = merger(SA,SB)->next;
    while(head != NULL){
        printf("%d ",head->number);
        head = head->next;
    }
}

//将输入的数，抓换为线性表
list* createList(int numbers[],int length)
{
    list* head = (list*)malloc(sizeof(list));
    list* index = head;
    for(int i=0;i<length;i++)
    {
        list* new = (list*)malloc(sizeof(list));
        new->number = numbers[i];
        index->next = new;
        index = index->next;
    }
    index->next = NULL;
    return head;
}
//归并数据表
list* merger(list* SA, list* SB){
    list* head = (list*)malloc(sizeof(list));
    list* temp = head;
    while(SA!=NULL && SB!=NULL){
        if(SA->number < SB->number){
            list* new = (list*)malloc(sizeof(list));
            new->number = SA->number;
            temp->next=new;
            SA = SA->next;
            temp = temp->next;
        }else{
            list* new = (list*)malloc(sizeof(list));
            new->number = SB->number;
            temp ->next = new;
            temp = temp->next;
            SB = SB->next;
        }
    }
    if(SA!=NULL){
        temp->next = SA;
    }else{
        temp->next = SB;
    }
    return head;
}
