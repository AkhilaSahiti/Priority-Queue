#include<stdio.h>
#include<stdlib.h>
typedef struct priorque
{
  int adata ;
  int bdata ;
  struct priorque *lnk;
}priorque;
priorque *frt,*rear,*tmp;
int xelm,yelm;
void enque();
void deque();
void display();
void peek();
void isempty();
void isfull();
main()
{
  int ch;
  while(1)
  {
    printf("\n1.Enqueue \n");
   printf("2.Deque \n");
  printf("3.Display \n");
  printf("4.Peek \n");
 printf("5.Is empty \n");
  printf("6.Is Full \n");
  printf("7.Exit \n");
  printf("Select ur choice ");
  scanf("%d",&ch);

  switch(ch)
  {
	case 1: enque();
		break;
	case 2: deque();
		break;
	case 3:
		printf("List is ");
		display();
		break;
	case 4: peek();
		break;
	case 5: isempty();
		break;
	case 6: isfull();
		break;
	case 7: exit(0);
	default:
		printf("Invalid choice \n");
    }
   }
 }

void enque()
{
	priorque *ptr;
    tmp=(priorque*)malloc(sizeof(priorque));
    if(tmp==NULL)
    {
     printf("Queue overflows");
     return;
    }
    printf("Priority");
    scanf("%d",&tmp->adata);
    printf("Data");
    scanf("%d",&tmp->bdata);
    tmp->lnk=NULL;
    if(frt==NULL)
	   {
	     frt=tmp;
	     rear=tmp;
	   }
	   else
	   {
			 rear->lnk=tmp;
	     	 rear=tmp;
		  
       }
	printf("%d inserted Successfully \n ",tmp->bdata);
	
}

void display()
{
	priorque *dsp, *ins, *ptr;
	priorque *node;
	dsp=(priorque*)malloc(sizeof(priorque));
	ins=(priorque*)malloc(sizeof(priorque));
	if(frt==NULL)
	{
		printf("Empty");
		return;
	}
	printf("Que is\n");
	ins->lnk=NULL;
	ins->adata=NULL;
	ptr=frt;
	while(ptr!=NULL)
	{
		node=frt;
		while(node!=rear)
		{
			if(node->adata>node->lnk->adata)
			{
				ins->adata=node->lnk->adata;
				node->lnk->adata=node->adata;
				node->adata=ins->adata;
				ins->bdata=node->lnk->bdata;
				node->lnk->bdata=node->bdata;
				node->bdata=ins->bdata;
			}
			
			node=node->lnk;
		}
		ptr=ptr->lnk;
	}
	dsp=frt;
	printf("Priority:\t");
	while(dsp!=NULL)
	{
		printf("%d\t",dsp->adata);
		dsp=dsp->lnk;
	}
	printf("\nData:\t\t");
	dsp=frt;
	while(dsp!=NULL)
	{
		printf("%d\t",dsp->bdata);
		dsp=dsp->lnk;
	}
	
}

void peek()
{
	if(frt==NULL)
	{
		printf("Empty");
		return;
	}
	printf("%d is the peek element",frt->bdata);
}
void isempty()
{
	if(frt==NULL)
	{
		printf("Empty Queue");
		return;
	}
	else
	{
		printf("Que is not empty");
	}
}
void isfull()
{
	tmp=(priorque*)malloc(sizeof(priorque));
	if(tmp==NULL)
	{
		printf("Full");
		return;
	}
	else
	{
		printf("Not full");
	}
}
void deque()
{
	priorque *ins, *node, *ptr, *del;
	del=(priorque*)malloc(sizeof(priorque));
	ins=(priorque*)malloc(sizeof(priorque));
	if(frt==NULL)
	{
		printf("Empty");
		return;
	}
	ins->lnk=NULL;
	ins->adata=NULL;
	ptr=frt;
	while(ptr!=NULL)
	{
		node=frt;
		while(node!=rear)
		{
			if(node->adata>node->lnk->adata)
			{
				ins->adata=node->lnk->adata;
				node->lnk->adata=node->adata;
				node->adata=ins->adata;
			}
		    node=node->lnk;
		}
		ptr=ptr->lnk;
	}
	del=frt;
	frt=del->lnk;
	xelm=del->bdata;
	free(del);
	printf("%d deleted",xelm);
}
