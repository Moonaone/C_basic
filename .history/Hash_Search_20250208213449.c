#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct HashNode
{
    char * key;
    int value;
    struct HashNode * next;
} HashNode;

typedef struct HashTable
{
    HashNode * table[TABLE_SIZE];
} HashTable;

HashTable * create_table()
{
    HashTable * hashtable = (HashTable*)malloc(sizeof(HashTable));
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

unsigned int hash(const char* key)
{
    unsigned int hash = 0;
    while(*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

void insert(HashTable* hashtable,const char* key, int value)
{
    unsigned int index = hash(key);
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = hashtable->table[index];
    hashtable->table[index] = new_node;
}

int search(HashTable* hashtable, const char* key)
{
    unsigned int index = hash(key);
    HashNode* node = hashtable->table[index];
    while(node != NULL)
    {
        if(strcmp(node->key, key) == 0)
        {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

void delete(HashTable* hashtable, const char* key)
{
    unsigned int index = hash(key);
    HashNode* node = hashtable->table[index];
    HashNode* prev = NULL;
    while(node != NULL)
    {
        if(strcmp(node->key, key) == 0)
        {
            if(prev == NULL)
            {
                hashtable->table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}
