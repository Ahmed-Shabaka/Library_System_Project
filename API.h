#ifndef _API_H_
#define _API_H_

#include "STD.h"

#define ADMIN 	1
#define USER 	2

#define ACTIVE 	1
#define INACTIVE 	0

#define ON 	1
#define OFF 	0

#define MAX_CHARACTERS 	20

#define PASSWORD 	123

#define ZERO 	0

typedef enum 
{
	R_OK=0,
	R_NOK=1,
	TRUE=2,
	FALSE=3,
	EMPTY=4,
	FULL=5,
}return_status_t;

struct lib_t
{
	uint8_t book_name[MAX_CHARACTERS];
	uint8_t borrow_flag;   // 	0 => not borrowed   ,   1 => borrowed
	uint8_t student_name[MAX_CHARACTERS];
	struct lib_t *next;
};

return_status_t ADD_BOOK(struct lib_t **head);
return_status_t DELETE_BOOK(struct lib_t **head);
return_status_t SEARCH_BOOK(struct lib_t *head);
return_status_t BORROW_BOOK(struct lib_t *head);
return_status_t RETURN_BOOK(struct lib_t *head);
return_status_t VIEW_BOOKS(struct lib_t *head);

#endif