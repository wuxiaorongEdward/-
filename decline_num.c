/*
�������Ա�ֱ�洢�������������ݣ�����Ҫ������������Ա�������һ�𣬲��ҽ������У��洢��ԭ���Ŀռ����� 
*/ 
 #include<stdio.h>
 #include<stdlib.h>
 
 typedef struct LNode{
 	int data;
 	struct LNode * next;
 }LNode;
 
LNode *CreateL()
{
	LNode *head, *p, *r;
	int num;
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	r = head;
	while(1)
	  {
	  scanf("%d", &num);
	  if(num == 0)
	      break;
	  p = (LNode *)malloc(sizeof(LNode));
	  p->data = num;
	  r->next = p;
	  r = p;	
	  }
	  r->next = NULL;
	  return head;
 } 
 
 void DisplayL(LNode *head)
 {
 	LNode *p;
 	p = head->next ;
 	while(p)
 	  {
 	  	printf("%d\t", p->data );
 	  	p = p->next ;
	   }
	   printf("\n");
 }
 
 LNode * Decline(LNode *La, LNode*Lb)
 {
   LNode *r, *p, *q, *s;
   //r = La;
   s =  NULL;
   p = La->next;
   q = Lb->next; 
   La->next = NULL;
   while(q != NULL && p!= NULL)
        {
        	if(p->data < q->data)
        	   {
        	   	r = p->next ;
        	   	p->next  = La->next ;
        	   	La->next = p;
        	   	p = r;
			   }
			   else
			   {
			   	r = q->next ;
			     q->next = La->next ;
				 La->next = q;
				 q = r;  
			   }
			}
			while(p != NULL)
			   {
			   	r = p->next ;
        	   	p->next  = La->next ;
        	   	La->next = p;
        	   	p = r;
				   }
			while(q != NULL)
			   {
			   	r = q->next ;
			     q->next = La->next ;
				 La->next = q;
				 q = r;   
				   }
		 // La->next = s;
		  return La;	
 }
 
 int main()
 {
 	LNode *La, *Lb, *s;
 	La = CreateL();
 	Lb = CreateL();
 	DisplayL(La);
 	DisplayL(Lb);
    s = Decline(La, Lb);
    printf("the result is : ");
    DisplayL(s);
 	return 0;
 }
