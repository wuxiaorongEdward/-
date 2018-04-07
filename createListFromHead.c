//用头插入建立单链表，随机插入n个数 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define OK 1
#define ERROR 0 

typedef int Elemtype;
typedef struct LNode
{
	Elemtype data;
	struct LNode *next;
}LNode;
//create the list from head
LNode *CreateFromHeadWithHead(LNode *head, int n)
{
	int i, x;
	LNode *s, *p;
	srand(time(0));
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
   for(i = 1; i <= n; i++)
        {
       // x = rand() % 100 + 1;
		s = (LNode *)malloc(sizeof(LNode));
		s->data = rand() % 100 + 1 ;
	    s->next = head->next ;
     	head->next = s;	
		}
		return head;
}

//create the list from tail
LNode *CreateFromTailWtihHead(LNode *head, int n)
{
	int i;
	LNode *s, *r;
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	r = head;
	srand(time(0));
	for(i = 1; i <= n; ++i)
	   {
	   	s = (LNode *)malloc(sizeof(LNode));
	   	s->data = rand() % 100 + 1;
	   	r->next = s;
	   	r = s;
	   }
	   r->next = NULL;
	   return head;
}

//display the list
/*void Display(LNode *head)
{
	LNode *p;
	p = head->next; 
	printf("the list is : ");
	while(p)
	{
		printf("%d\t", p->data);
		p = p->next ;
	}
	printf("\n");
}*/

int ClearList(LNode *head)
{
	LNode *p, *q;
	p = head->next ;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;  
	 } 
	 head->next = NULL;
}

void Display(LNode *head)
{
	LNode *p;
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
	int ok;
	LNode *L;
//	L = CreateFromHeadWithHead(L, 10);
    L = CreateFromTailWtihHead(L, 10);
	Display(L);
	ok = ClearList(L);
	return 0;
}
