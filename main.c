#include "API.h"

extern struct lib_t *head;

int main()
{
	uint8_t scan_val=0;
	return_status_t ret=R_NOK;
	
	printf("LIBRARY MANAGEMENT SYSTEM \n");
	label :
	printf("Log In :\n1)Admin\n2)Student\n0)Exit \n");
	fflush(stdin);
	scanf("%d",&scan_val);
	if(ADMIN==scan_val)
	{
		printf("Enter Password : ");
		fflush(stdin);
		scanf("%d",&scan_val);
		if(PASSWORD!=scan_val)
		{
			printf("Wrong Password! \n");
			goto label ;
		}
		printf("WELCOME \n");
		while(ON)
		{
			printf("1)ADD BOOK \n");
			printf("2)DELETE BOOK \n");
			printf("3)SEARCH BOOK \n");
			printf("4)BORROW BOOK \n");
			printf("5)RETURN BOOK \n");
			printf("6)VIEW BOOKS \n");
			printf("0)EXIT \n");
			
			fflush(stdin);
			scanf("%d",&scan_val);
			
			switch(scan_val)
			{
				case 1: ret=ADD_BOOK(&head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 2: DELETE_BOOK(&head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 3: SEARCH_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 4: BORROW_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 5: RETURN_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 6: VIEW_BOOKS(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 0: goto label ;
				break;
				default : printf("Invalid! \n");
				break;
			}
		}
	}
	if(USER==scan_val)
	{
		printf("WELCOME \n");
		while(ON)
		{
			printf("1)SEARCH BOOK \n");
			printf("2)BORROW BOOK \n");
			printf("3)RETURN BOOK \n");
			printf("4)VIEW BOOKS \n");
			printf("0)EXIT \n");
			
			fflush(stdin);
			scanf("%d",&scan_val);
			
			switch(scan_val)
			{
				case 1: SEARCH_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 2: BORROW_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 3: RETURN_BOOK(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 4: VIEW_BOOKS(head);
				if(ret==R_NOK)  printf("ret=R_NOK! \n");
				break;
				case 0: goto label ;
				break;
				default : printf("Invalid! \n");
				break;
			}
		}
	}
	else if (ZERO==scan_val)
	{
		return ZERO;
	}
	else
	{
		printf("Invalid! \n");
	}
	
	return ZERO;
}