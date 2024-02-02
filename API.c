#include "API.h"

struct lib_t *head=NULL;

return_status_t ADD_BOOK(struct lib_t **head)
{
	struct lib_t *TempNode=NULL;
	return_status_t ret=R_NOK;
	
	if(NULL==(*head))
	{
		(*head)=(struct lib_t *)malloc(sizeof(struct lib_t));
		if(NULL==(*head))
		{
			ret=R_NOK;
			printf("ERROR! \n");
		}
		else
		{
			(*head)->borrow_flag=INACTIVE;
			(*head)->next=NULL;
			printf("Enter Book Name : ");
			fflush(stdin);
			gets( (*head)->book_name );
			ret=R_OK;
		}
	}
	else
	{
		TempNode=(*head);
		
		while(TempNode->next!=NULL)
		{
			TempNode=TempNode->next;
		}
		
		TempNode->next=(struct lib_t *)malloc(sizeof(struct lib_t));
		if(NULL==TempNode->next)
		{
			ret=R_NOK;
			printf("ERROR! \n");
		}
		else
		{
			TempNode=TempNode->next;
			
			(TempNode)->borrow_flag=INACTIVE;
			(TempNode)->next=NULL;
			printf("Enter Book Name : ");
			fflush(stdin);
			gets( (TempNode->book_name) );
			ret=R_OK;
		}
	}
	return ret;
}
/************************************************************/
return_status_t DELETE_BOOK(struct lib_t **head)
{
	return_status_t ret=R_NOK;
	struct lib_t *PrevNode=NULL;
	struct lib_t *TempNode=NULL;
	uint8_t scan_val[MAX_CHARACTERS];
	uint8_t indicator=INACTIVE;
	
	if(NULL==(*head))
	{
		printf("Library is Empty \n");
		ret=EMPTY;
	}
	else
	{
		PrevNode=(*head);
		
		printf("Enter Book Name : ");
		fflush(stdin);
		gets( scan_val );
		
		// 	 if book is at index (0)  OR  (book is at the head node)
		if(strcmp( PrevNode->book_name , scan_val) == ZERO)
		{
			// if library HAS ONLY 1 book
			if(PrevNode->next==NULL)
			{
				free(PrevNode);
				(*head)=NULL;
			}
			// if library has more than 1 book
			else
			{
				(*head)=PrevNode->next;
				free(PrevNode);
			}
			
			indicator=ACTIVE;
			ret=R_OK;
		}
		// 	 if book is NOT at index (0) 
		else
		{
			while(PrevNode->next!=NULL)
			{
				if( strcmp( (PrevNode->next)->book_name , scan_val) == ZERO )
				{
					TempNode=PrevNode->next;
					PrevNode->next=TempNode->next;
					free(TempNode);
					indicator=ACTIVE;
					break;
				}
				else
				{
					PrevNode=PrevNode->next;
				}
			}
		}
		
		if(indicator==ACTIVE) 	printf("Book Deleted Sucssefully \n");
		else printf("Book Not Found! \n");
		
		ret=R_OK;
	}
	
	return ret;
}
/************************************************************/
return_status_t SEARCH_BOOK(struct lib_t *head)
{
	return_status_t ret=R_NOK;
	struct lib_t *TempNode=NULL;
	uint8_t scan_val[MAX_CHARACTERS];
	uint8_t indicator=INACTIVE;
	
	if(head==NULL)
	{
		ret=EMPTY;
		printf("Library is Empty \n");
	}
	else
	{
		TempNode=head;
		
		printf("Enter Book Name : ");
		fflush(stdin);
		gets( scan_val );
		
		while(TempNode!=NULL)
		{
			if( strcmp( TempNode->book_name , scan_val) == ZERO )
			{
				printf("Book Found >> \n");
				printf("Book Name : %s \n",TempNode->book_name);
				if(TempNode->borrow_flag==ACTIVE)		
				{
					printf("Book is Borrowed : %s \n",TempNode->student_name);
				}
				else 
				{
					printf("Book is NOT Borrowed \n");
				}
				printf("-------------------------\n");
				indicator=ACTIVE;
				break;
			}
			else
			{
				TempNode=TempNode->next;
			}
		}
		if(indicator==INACTIVE) 	printf("Book Not Found! \n");
		
		ret=R_OK;
	}
	
	return ret;
}
/************************************************************/
return_status_t BORROW_BOOK(struct lib_t *head)
{
	return_status_t ret=R_NOK;
	struct lib_t *TempNode=NULL;
	uint8_t scan_val[MAX_CHARACTERS];
	uint8_t indicator=INACTIVE;
	
	if(head==NULL)
	{
		ret=EMPTY;
		printf("Library is Empty \n");
	}
	else
	{
		TempNode=head;
		
		printf("Enter Book Name : ");
		fflush(stdin);
		gets( scan_val );
		
		while(TempNode!=NULL)
		{
			if( strcmp( TempNode->book_name , scan_val) == ZERO )
			{
				if(TempNode->borrow_flag==INACTIVE)
				{
					printf("Enter Student Name : ");
					fflush(stdin);
					gets( TempNode->student_name );
					TempNode->borrow_flag=ACTIVE;
				}
				else
				{
					printf("Book is already Borrowed! \n");
				}
				indicator=ACTIVE;
				break;
			}
			else
			{
				TempNode=TempNode->next;
			}
		}
		if(indicator==INACTIVE) 	printf("Book Not Found! \n");
		
		ret=R_OK;
	}
	
	return ret;
}
/************************************************************/
return_status_t RETURN_BOOK(struct lib_t *head)
{
	return_status_t ret=R_NOK;
	struct lib_t *TempNode=NULL;
	uint8_t scan_val[MAX_CHARACTERS];
	uint8_t indicator=INACTIVE;
	
	if(head==NULL)
	{
		ret=EMPTY;
		printf("Library is Empty \n");
	}
	else
	{
		TempNode=head;
		
		printf("Enter Book Name : ");
		fflush(stdin);
		gets( scan_val );
		
		while(TempNode!=NULL)
		{
			if( strcmp( TempNode->book_name , scan_val) == ZERO )
			{
				if(TempNode->borrow_flag==INACTIVE)
				{
					printf("Book is NOT Borrowed! \n");
				}
				else
				{
					TempNode->borrow_flag=INACTIVE;
				}
				indicator=ACTIVE;
				break;
			}
			else
			{
				TempNode=TempNode->next;
			}
		}
		if(indicator==INACTIVE) 	printf("Book Not Found! \n");
		
		ret=R_OK;
	}
	
	
	return ret;
}
/************************************************************/
return_status_t VIEW_BOOKS(struct lib_t *head)
{
	return_status_t ret=R_NOK;
	struct lib_t *TempNode=NULL;
	uint8_t counter=0;
	
	if(head==NULL)
	{
		ret=EMPTY;
		printf("Library is Empty \n");
	}
	else
	{
		TempNode=head;
		while(TempNode!=NULL)
		{
			counter++;
			printf("%i)Book Name : %s \n",counter,TempNode->book_name);
			if(TempNode->borrow_flag==ACTIVE)
			{
				printf("Book is Borrowed by : %s \n",TempNode->student_name);
			}
			else 
			{
				printf("Book is NOT Borrowed \n");
			}
			printf("-------------------------\n");
			TempNode=TempNode->next;
		}
		printf("Library has %i Book(s) \n",counter);
		
		ret=R_OK;
	}
	
	return ret;
}