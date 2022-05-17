#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define SIZE 1000    //Το μέγιστο μέγεθος συνδυασμού



typedef struct StackList     //Η στοίβα με τους συνδυασμούς
{
	int data[SIZE];
	struct StackList *nextS;
}Stack;





Stack *pushStack (Stack *head, int *arr);     //Προσθέτει νέο πίνακα με τον συνδυασμό στην στοίβα
Stack *popStack (Stack *head, int *arrptr);   //Αφαιρεί συνδυασμό από την στοίβα



int main (void)
{
	Stack *head=NULL, *tmp=NULL;
	int arr[SIZE]={0}, arrptr[SIZE]={0};
	int n, i, j, k, l, pl=1;
	
	
	
	printf("Give a number to find the compositions of: ");
	scanf("%d", &n);
	printf("\n\n");
	
	
	printf("The compositons of %d are:\n\n", n);
	
	
	
	arr[0]=n;
	head=pushStack(head, arr);
	
	printf("Composition %d\t:", pl);
	pl=pl+1;
	
	head=popStack(head, arrptr);		
	printf(" %d\n", arrptr[0]);
	
	
	
	for (i=arrptr[0]-1, j=1 ; i>=1 || j<=arrptr[0]-1 ; --i, ++j)  //Δημιουργεί τους αρχικούς, διψήφιους συνδυασμούς
	{
		printf("Composition %d\t:", pl);
		
		arr[0]=i;
		arr[1]=j;
		
		head=pushStack(head, arr);
		
		printf(" %d %d\n", head->data[0], head->data[1]);
		pl=pl+1;
	}	
	
	
	
	
	do
	{
		
		head=popStack(head, arrptr);   //Αφαιρεί συνδυασμό απο την στοίβα και τον ελέγχει
		
		
		for (i=arrptr[0]-1, j=1 ; i>=1 && j<=arrptr[0]-1 ; --i, ++j)  //Δημιουργεί τους νέους συνδυασμούς
		{
			printf("Composition %d\t:", pl);
			
			
			arr[0]=i;
			arr[1]=j;
			
			
			
			for (k=1 ; k<SIZE ; k++)
			{
				arr[k+1]=arrptr[k];
			}
			
			
			
			if (arr[0]==1)  //Αν ο συνδυασμός που δημιουργήθηκε αρχίζει με ένα, δεν μπαίνει καθόλου στην στοίβα και απλώς εκτυπώνεται
			{
				for (l=0 ; arr[l]!=0 ; l++)
				{
					printf(" %d", arr[l]);
				}
				printf("\n");
				pl=pl+1;
			}
			else
			{
				head=pushStack(head, arr);
				
				
				for (l=0 ; arr[l]!=0 ; l++)
				{
					printf(" %d", arr[l]);
				}
				printf("\n");	
				pl=pl+1;
			}

		}
		
		
		for (k=0 ; k<SIZE ; k++)
		{
			arrptr[k]=0;
		}
		
	}while(head!=NULL);
	
	
	
	
	
	return 0;
}







Stack *pushStack (Stack *head, int *arr)
{
	Stack *new;
	int p;
	
	new=(Stack *)malloc(sizeof(Stack));
	if (new==NULL)
	{
		printf("Out of memory! Code:1\n");
		exit(1);
	}
	
	
	
	for (p=0 ; p<SIZE ; p++)
	{
		new->data[p]=arr[p];
	}
	
	
	new->nextS=head;
	
	return new;
	
	
}








Stack *popStack (Stack *head, int *arrptr)
{
	Stack *tmp;
	int p;
	
	if (head==NULL)
	{
		return  NULL;
	}
	else if (head->nextS==NULL)
	{
		for (p=0 ; p<(sizeof(head->data)/sizeof(head->data[0])) ; p++)
		{
			arrptr[p]=head->data[p];
		}
		
		free(head);
		return NULL;
	}
	else
	{
		for (p=0 ; p<(sizeof(head->data)/sizeof(head->data[0])) ; p++)
		{
			arrptr[p]=head->data[p];
		}
		
		tmp=head;
		head=head->nextS;
		free(tmp);
		return head;
		
	}
	
}

