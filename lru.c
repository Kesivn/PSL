#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct List {
	List* next;
	List* last;
	int value;
	int key;
}list;

List* hash[100];
List head;
List tail;

int get(int key, List* p);
int put(int key, int value);

int get(int key) {
	int ans = -1;
	if (hash[key] != NULL) ans = hash[key]->value;
	return ans;
}

int put(int key, int value) {
	int i;
	List* p;
	if (hash[key] != NULL) {
		hash[key]->last->next = hash[key]->next;
		hash[key]->next->last = hash[key]->last;
		head.next->last = hash[key];
		hash[key]->next = head.next;
		head.next = hash[key];
		hash[key]->last = &head;
	}
	else {
		p = tail.last;
		p->last->next = &tail;
		tail.last = p->last;
		head.next->last = p;
		p->next = head.next;
		head.next = p;
		p->last = &head;
		hash[key] = p;
		i = p->key;
		hash[i] = NULL;
		p->key = key;
		p->value = value;


	}
	return 0;


}
