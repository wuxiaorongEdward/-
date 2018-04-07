#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *next;
}LinkList;

//用尾插入法创建链表 
LinkList *CreateFromTail()
{
	int x;
	LinkList *p, *s,*L;
	L = (LinkList *)malloc(sizeof(LinkList));
	L->next = NULL;
	p = L;
	printf("Enter number -1 to exit : ");
	scanf("%d", &x);
	while(x != -1)
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = x;
		p->next = s;
		p = s;
	    scanf("%d", &x);
	}
	p->next = NULL;
	return L;
}

//取链表的第i个元素 
int GetElem(LinkList *L, int i, int *e)
{
	int j = 1;
	LinkList *p;
	p = L->next ;
	while(p)
	{
		if(j == i)
		{
			  *e = p->data ;
			  break;
		}
		++j; 
		p = p->next ;
	}
	if(!p)
	{
		printf("the number doesn't exist\n");
	}
	return OK;
}

//在第i个位置上插入元素e
void InsertElem(LinkList *head, int i, int *e)
{
	LinkList *p, *s;
	int j = 1;
	p = head;
	while(p && j < i)
	  {
	  	p = p->next;
		++j; 
	   }
	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = *e;
	s->next = p->next ;
	p->next = s;
 } 
 
//删除第i个节点
void DeletElem(LinkList *head, int i)
{
	int j = 1;
	LinkList *p, *temp;
	p = head;
	while(p && j < i)
	    {
	    	p = p->next ;
	    	++j;
		}
    if(p == NULL)
       {
       	printf("does not exist !\n");
	   }
	else{
		temp = p->next ;
		p->next = temp->next; 
	}
	free(temp);
 } 

//遍历单链表，该单链表是带头节点的
void Display(LinkList *head)
{
	LinkList *p;
	p = head->next ;
	while(p)
	{
		printf("%d\t", p->data);
	    p = p->next ;
	}
	printf("\n");
 } 
 
int main()
{
	int num, ok;
	int x = 100;
   LinkList *head;
   head = CreateFromTail();
   ok = GetElem(head, 5, &num);
   printf("%d\n", num);
   printf("the list is :");
   Display(head);	
   InsertElem(head, 1, &x);
   printf("the new list is : ");
   Display(head);
   DeletElem(head, 1);
   printf("the current list : ");
   Display(head);
   return 0;
}
