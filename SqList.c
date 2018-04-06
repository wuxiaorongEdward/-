#include<stdio.h>
#include<stdlib.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Elemtype;
typedef struct  SqList{
	Elemtype data[MAXSIZE];
	int length;
}SqList;

//取列表中的元素 
Elemtype GetElem(SqList L, int i, Elemtype *e)
{
	if(L.length == 0 || i < 1 || i > L.length )
	      return ERROR;
	*e = L.data[i-1];
	return OK;
}
//在第pos位置插入num 
int InsertElem(SqList *l, int pos, int num)
{
	int j;
	if(l->length >= MAXSIZE)
	    return ERROR;
	if(pos < 1 || pos > l->length + 1)
	       return ERROR;
	for(j = l->length -1 ; j >= pos - 1; j--)
	    l->data[j+1] = l->data[j];
	l->data[pos - 1] = num;
	l->length += 1;
//	printf("%d\n", l.length );
	return OK;
}

int main()
{    
    int num = 55;
     SqList l;
	 int i;
	 for(i = 1; i <= 10; i++)
	      l.data[i-1] = i;
	 l.length = 10;
	int e;
	int ok;
	ok = GetElem(l, 10, &e);
	printf("number  %d\n", e);
	ok = InsertElem(&l, 5, num);
	printf("%d\n", l.length );
	for(i = 0; i < l.length; i++)
	  printf("%d\t", l.data[i]);
	printf("\n");
	return 0;
}
