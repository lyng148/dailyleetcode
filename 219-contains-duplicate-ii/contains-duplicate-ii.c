

#define SIZE 1000000

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

    while (hashArr[hashIndex] != NULL && hashArr[hashIndex]->key != key)
    {
        hashIndex++;
        hashIndex %= SIZE;
    }

    hashArr[hashIndex] = Newnode;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int x){
    node *hashArr[SIZE];
    memset(hashArr, 0, sizeof(hashArr));

    for (int i = 0; i < numsSize; i++)
    {
        node *k = search(hashArr, nums[i]);
        if (k == NULL)
        {
            insert(hashArr, nums[i], i);
        }
        else
        {
            if (i - k->value <= x) return true;
            else
            {
                insert(hashArr, nums[i], i);
            }
        }
    }

    return false;
}