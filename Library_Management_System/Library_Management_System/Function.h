#ifndef __FUNCTION_H__
#define __FUNCTION_H__

// 定义链表结构
typedef struct Node {
	char name[20]; // 书籍名称
	char author[20]; // 书籍作者
	int year; // 书籍年限
	struct Node* next;
} Node;

void meue(); // 菜单页面函数
void addBook(Node** head, char* name, char* author, int year);
void deleteBook(Node** head, char* name);
void showBook(Node* head);
void searchBook(Node* head, char* name);
void reviseBook(Node* head, char* name, char* author, int year);
void saveBook(Node* head);
void loadBook(Node** head);

#endif // !__FUNCTION_H__

