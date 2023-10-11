#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 256

typedef struct node
{
    int key;
    char* value;
} node;

node *Makenode(int key, char* value)
{
    node *Newnode = (node *)malloc(sizeof(node));
    Newnode->key = key;
    Newnode->value = (char *)malloc(strlen(value) + 1); // Cấp phát bộ nhớ cho value
    strcpy(Newnode->value, value);
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

void insert(node **hashArr, int key, char* value)
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

bool wordPattern(char *pattern, char *s) {
    node *hashArr[SIZE];
    memset(hashArr, 0, sizeof(hashArr));

    char **value = (char **)malloc(300 * sizeof(char *));
    for (int i = 0; i < 300; i++) {
        value[i] = (char *)malloc(3000 * sizeof(char));
    }

    char *token = strtok(s, " ");
    int i = 0;
    while (token != NULL && i < 300) {
        strcpy(value[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    if (i != strlen(pattern)) {
        // Số lượng key và value không khớp
        return false;
    }

    for (int j = 0; pattern[j] != '\0'; j++) {
        node *k = search(hashArr, pattern[j]);
        if (k == NULL) {
            // Kiểm tra giá trị đã tồn tại trong bảng băm
            for (int m = 0; m < SIZE; m++) {
                if (hashArr[m] != NULL && strcmp(hashArr[m]->value, value[j]) == 0) {
                    return false;
                }
            }
            insert(hashArr, pattern[j], value[j]);
        } else {
            if (strcmp(value[j], k->value) != 0) {
                return false;
            }
        }
    }

    // Giải phóng bộ nhớ
    for (int k = 0; k < 300; k++) {
        free(value[k]);
    }
    free(value);

    return true;
}
