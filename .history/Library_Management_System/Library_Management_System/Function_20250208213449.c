#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Function.h"


// ��������ڵ�
Node* createNode(char* name, char *author, int year)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("malloc fair\n");
		return NULL;
	}
	strcpy(newNode->name, name);
	strcpy(newNode->author, author);
	newNode->year = year;
	newNode->next = NULL;
	return newNode;
}

// ���ͼ��
void addBook(Node** head, char *name, char *author, int year)
{
	Node* newNode = createNode(name, author, year);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

// ɾ��ͼ��
void deleteBook(Node** head, char* name)
{
	Node* temp = *head;
	Node* prev = NULL;
	if (temp != NULL && strcmp(temp->name, name) != 0)
	{
		*head = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL && strcmp(temp->name, name) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;

	prev->next = temp->next;
	free(temp);
}

// ��ʾͼ��
void showBook(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("name: %s, author: %s, year: %d\n", temp->name, temp->author, temp->year);
		temp = temp->next;
	}
}

// ����ͼ��
void searchBook(Node* head, char* name)
{
	Node* temp = head;
	
	while (temp != NULL && strcmp(temp->name, name) != 0 )
	{
		temp = temp->next;
	}
	if (temp != NULL && strcmp(temp->name, name) != 0 )
	{
		printf("name: %s, author: %s, year: %d", temp->name, temp->author, temp->year);
		return;
	}
	else 
	{
		printf("Book not found!\n");
	}
}

// �޸�ͼ��
void reviseBook(Node* head, char* name, char* author, int year)
{
	Node* temp = head;

	while (temp != NULL && strcmp(temp->name , name) != 0)
	{
		temp = temp->next;
	}
	if (strcmp(temp->name , name) != 0 && temp != NULL)
	{
		strcpy(head->author , author);
		head->year = year;
	}
}

// ����ͼ��
void saveBook(Node* head)
{
	FILE* file = fopen("books.text", "w");
	if (file == NULL)
	{
		printf("Failed to open file for writing\n");
		return;
	}
	Node* temp = head;
	while (temp != NULL)
	{
		fprintf(file, "%s, %s, %d\n", temp->name, temp->author, temp->year);
		temp = temp->next;
	}
	fclose(file);
	printf("Books saved to file\n");
}

// ��ȡ�ļ�
void loadBook(Node** head)
{
	FILE* file = fopen("books.txt", "r");
	if (file == NULL)
	{
		printf("Failed to open file for reading\n");
		return;
	}
	char name[20];
	char author[20];
	int year;
	while (fscanf(file, "%[^,],%[^,],%d\n", name, author, &year) != EOF)
	{
		addBook(head, name, author, year);
	}
	fclose(file);
	printf("Books loaded from file\n");
}

void meue()
{
	printf("1. ���ͼ��\n");
	printf("2. ɾ��ͼ��\n");
	printf("3. ����ͼ��\n");
	printf("4. �޸�ͼ��\n");
	printf("5. ��ʾͼ��\n");
	printf("6. ͼ������\n");
	printf("7. ���汾��\n");
	printf("8. ��ȡ����\n");
	printf("9. �˳�\n");
}
