#define _CRT_SECURE_NO_WARNINGS

#include "Function.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0;
	char name[20] = { 0 };
	char author[20] = { 0 };
	int year = 0;
	Node* head = NULL;

	while(1)
	{
		meue(); // ²Ëµ¥Ò³Ãæº¯Êý
		printf("Please select an option\n");
		scanf("%1d", &num);
		getchar();

		switch (num)
		{
		case 1:
			printf("Please enter the title, author and year of the book\n");
			printf("\nname:");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;
			printf("\nauthor:");
			fgets(author, sizeof(author), stdin);
			author[strcspn(author, "\n")] = 0;
			printf("\nyear:");
			scanf("%4d", &year);
			getchar();

			addBook(&head, name, author, year);
			printf("\nBooks added\n");
			break;
		case 2:
			printf("\nPlease enter the name of the book you want to delete\n");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;

			deleteBook(&head, name);
			break;
		case 3:
			printf("\nPlease enter the name of the book you want to search for\n");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;

			searchBook(head, name);
			break;
		case 4:
			printf("\nPlease enter the name of the book you want to modify\n");
			printf("name:");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;
			printf("\nauthor:");
			fgets(author, sizeof(author), stdin);
			author[strcspn(author, "\n")] = 0;
			printf("\nyear:");
			scanf("%4d", &year);
			getchar();

			reviseBook(head, name, author, year);
			break;
		case 5:
			showBook(head);
			break;
		case 7:
			saveBook(head);
			break;
		case 8:
			loadBook(&head);
			break;
		case 9:
			exit(0);

		default:
			printf("Invalid option. Please try again.\n");
		}
	}

	return 0;
}
