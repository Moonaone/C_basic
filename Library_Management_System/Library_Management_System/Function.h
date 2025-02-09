#ifndef __FUNCTION_H__
#define __FUNCTION_H__

// ��������ṹ
typedef struct Node {
	char name[20]; // �鼮����
	char author[20]; // �鼮����
	int year; // �鼮����
	struct Node* next;
} Node;

void meue(); // �˵�ҳ�溯��
void addBook(Node** head, char* name, char* author, int year);
void deleteBook(Node** head, char* name);
void showBook(Node* head);
void searchBook(Node* head, char* name);
void reviseBook(Node* head, char* name, char* author, int year);
void saveBook(Node* head);
void loadBook(Node** head);

#endif // !__FUNCTION_H__

