#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int isOccupied; // 0 = empty, 1 = occupied, -1 = deleted
} HashEntry;

typedef struct {
    HashEntry table[TABLE_SIZE];
} HashTable;

void initTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].isOccupied = 0;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTable *ht, int key) {
    int index = hash(key);
    int i = index;

    while (ht->table[i].isOccupied == 1) {
        if (ht->table[i].key == key) {
            printf("Duplicate key found: %d\n", key);
            return;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == index) {
            printf("Table is full, can't insert %d\n", key);
            return;
        }
    }

    ht->table[i].key = key;
    ht->table[i].isOccupied = 1;
    printf("Inserted key %d at index %d\n", key, i);
}

int search(HashTable *ht, int key) {
    int index = hash(key);
    int i = index;

    while (ht->table[i].isOccupied != 0) {
        if (ht->table[i].isOccupied == 1 && ht->table[i].key == key) {
            return i;
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == index) {
            break;
        }
    }
    return -1;
}

void delete(HashTable *ht, int key) {
    int index = search(ht, key);
    if (index == -1) {
        printf("Key %d not found\n", key);
        return;
    }
    ht->table[index].isOccupied = -1;
    printf("Deleted key %d from index %d\n", key, index);
}

void printTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i].isOccupied == 1) {
            printf("Index %d: %d\n", i, ht->table[i].key);
        }
    }
}

int main() {
    HashTable ht;
    initTable(&ht);

    insert(&ht, 20);
    insert(&ht, 30);
    insert(&ht, 40);
    insert(&ht, 25);
    insert(&ht, 35);

    printf("Search for 30: Index %d\n", search(&ht, 30));
    printf("Search for 50: Index %d\n", search(&ht, 50));

    printTable(&ht);

    delete(&ht, 30);
    delete(&ht, 50);

    printTable(&ht);

    return 0;
}