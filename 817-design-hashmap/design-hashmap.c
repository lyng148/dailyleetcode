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

typedef struct {
    node *arr[50007];
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *hashMap = (MyHashMap *)malloc(sizeof(MyHashMap));
    memset(hashMap->arr, 0, sizeof(hashMap->arr));
    return hashMap;
}

int hashCode(int key)
{
    int r = key % 50007;
    return r < 0 ? r + 50007 : r;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    node *Newnode = Makenode(key, value);
    int hashIndex = hashCode(key);

    while (obj->arr[hashIndex] != NULL && obj->arr[hashIndex]->key != -1 && obj->arr[hashIndex]->key != key)
    {
        hashIndex++;
        hashIndex %= 50007;
    }
    obj->arr[hashIndex] = Newnode;
}

int myHashMapGet(MyHashMap* obj, int key) {
  int hashIndex = hashCode(key);
  while (obj->arr[hashIndex] != NULL)
  {
    if (obj->arr[hashIndex]->key == key)
    {
        return obj->arr[hashIndex]->value;
    }
    hashIndex++;
    hashIndex %= 50007;
  }
  return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
  int hashIndex = hashCode(key);
  while (obj->arr[hashIndex] != NULL)
  {
    if (obj->arr[hashIndex]->key == key)
    {
        obj->arr[hashIndex]->value = -1;
        obj->arr[hashIndex]->key = -1;
        return;
    }
    hashIndex++;
    hashIndex %= 50007;
  }
  return;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->arr);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/