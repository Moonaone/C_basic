#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Function.h"


// 创建链表节点
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

// 添加图书
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

// 删除图书
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

// 显示图书
void showBook(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		printf("name: %s, author: %s, year: %d\n", temp->name, temp->author, temp->year);
		temp = temp->next;
	}
}

// 查找图书
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

// 修改图书
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

// 保存图书
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

// 读取文件
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
	printf("1. 添加图书\n");
	printf("2. 删除图书\n");
	printf("3. 查找图书\n");
	printf("4. 修改图书\n");
	printf("5. 显示图书\n");
	printf("6. 图书排序\n");
	printf("7. 保存本地\n");
	printf("8. 读取本地\n");
	printf("9. 退出\n");
}
