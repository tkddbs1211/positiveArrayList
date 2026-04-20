#include <stdio.h>
#include <stdlib.h>

typedef struct elementArrayListType {
	int row;
	int col;
	int value;
} elementArrayList; // typedef : struct elementArrayListTpye 앞으로 elementArrayList라고 부르겠다.

typedef struct arrayListType
{
	elementArrayList* data; // = elementArrayList data[100] 배열은 거의 포인터랑 같음. 포인터 data생성 
	int size; 
	int capacity;//전체 용량
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
