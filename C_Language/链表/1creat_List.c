#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List
{
    int data;
    struct List *next;
}; //��������

void getInput(struct List *book)
{
    printf("�������ݣ�");
    scanf("%s", book->data);
}

void addData(struct List **head)
{
    struct List *list, *temp;
    list = (struct List *)malloc(sizeof(struct List));
    //��̬�����ڴ�
    //����ڴ��Ƿ����ʧ��
    if (list == NULL)
    {
        printf("�ڴ����ʧ����\n");
        exit(1);
    }

    getInput(list);

    if (*head != NULL)
    { //�ǿ��������
        temp = *head;
        *head = list;
        list->next = temp;
    }
    else
    { //���������
        *head = list;
        list->next = NULL;
    }
    return;
}

void printList(struct List * head)
{
    struct List * list;
    int count = 1;

    list = head; //��ͷָ�������

    while (list != NULL)
    {
        printf("id:%d", count);
        printf("data:%d\n", list->data);
        list = list->next; //��ֵΪ��һ���ڵ�
        count++; //��������һ
    }
}

int main()
{
    struct List *head;
    head = NULL;
    addData(&head);
    addData(&head);
    addData(&head);
    printList(head);
    return 0;
}