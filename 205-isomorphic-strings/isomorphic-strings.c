#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 200

typedef struct node
{
    int key;
    int value;
} node;

node *Makenode(int key, int value)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->key = key;
    Newnode->value = value;
    return Newnode;
}

int hashCode(int key)
{
    int r = key % SIZE;
    return r < 0 ? r + SIZE : r;
}

node *search(node **hashArr, int key)
{

    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL)
    {
        if (hashArr[hashIndex]->key == key)
            return hashArr[hashIndex];
        hashIndex++;
        hashIndex %= SIZE;
    }

    return NULL;
}

void insert(node **hashArr, int key, int value)
{
    node *Newnode = Makenode(key, value);

    int hashIndex = hashCode(key);

    while (hashArr[hashIndex] != NULL && hashArr[hashIndex]->key != -1)
    {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashArr[hashIndex] = Newnode;
}

bool isIsomorphic(char * s, char * t){
    node *hashArr[SIZE];
    int check[SIZE] = {0};
    memset(hashArr, 0, sizeof(hashArr));

    for (int i = 0; s[i] != '\0'; i++)
    {
        node *k = search(hashArr, s[i]);
        if (k == NULL && check[t[i]] == 0)
        {
            insert(hashArr, s[i], t[i]);
            check[t[i]] = 1;
            continue;
        }
        else if (k == NULL && check[t[i]] == 1) return false;
        else
        {
            if (k->value != t[i]) return false;
        }
    }
    return true;
}