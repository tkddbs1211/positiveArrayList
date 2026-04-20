#include <stdio.h>
#include <stdlib.h>

typedef struct elementArrayListType {
	int row;
	int col;
	int value;
} elementArrayList; 

typedef struct arrayListType
{
	elementArrayList* data; // = elementArrayList data[100] 배열은 거의 포인터랑 같음.
	int size; 
	int capacity;
} arrayList;
//typedef struct arrayListType arrayList;

/*elementArrayList *data = malloc(....)
elementArrayList data[100] <=> int data [100]*/

extern arrayList* createArrayList(int size);
extern void destroyArrayList(arrayList* al);
extern int isEmptyArrayList(arrayList* al);
extern int isFullArrayList(arrayList* al);
extern int sizeArrayList(arrayList* al);
extern int insertArrayList(arrayList* al, int pos, elementArrayList item);
extern elementArrayList deleteArrayList(arrayList* al, int pos);
extern int initArrayList(arrayList* al);
extern elementArrayList getItemArrayList(arrayList* al, int pos);
extern int replaceItemArrayList(arrayList* al, int pos, elementArrayList item);
extern void printArrayList(arrayList* al);
