#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

arrayList* createArrayList(int size) {
	arrayList* al; //arrayList를 가르키는 al생성
	al = (arrayList*)malloc(sizeof(arrayList));//al을 만들 메모리를 arrayList만큼 할당받음

	al->data = (elementArrayList*)malloc(  //al->data al안에있는 data에다가 넣어라 (arrayList에 있는 data에 넣어라)
		sizeof(elementArrayList) * size); //elementArrayList를 * size만큼 할당 , size만큼 x행y열 z값 저장 가능.
	al->size = 0; //size 0으로 초기화 
	al->capacity = size; // al-> capacity >>최대개수=count 

	return al;
}

void destroyArrayList(arrayList* al) {
	free(al->data); //malloc 이후엔 다시 free()해줘야함. data 먼저 하고
	free(al);      //그 다음에 al해줌
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;                //size가 0이면 참 즉, row col value가 하나도 없으면 1 리턴
	}
	else {
		return 0;            //아니면 0 리턴
	}
}

int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) { //size가 capacity 최대 용량과 같으면 참 1 리턴하기
		return 1;
	}
	else {
		return 0; //아니면 0 리턴
	}
}

int sizeArrayList(arrayList* al) {   
	return al->size;  //al에 저장된 원소 개수 반환 , size 만큼 row col value 있기에 al -> size 리턴
}

int insertArrayList(arrayList* al,
	int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size) { //pos가 0보다 작거나 size보다 크면 return 0;
		return 0;
	}
	
	if (item.value <= 0)
	{	
		printf("positive only\n");
		return 0;
	}

	if (al->size == al->capacity) //size와 capacity가 같아지면 realloc이용
	{
		int newCapacity = al->capacity * 2; //보통 공간을 원래 공간 2배로 잡는다고 함

		elementArrayList* newData = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCapacity);//newdata= realloc가 새 주소값을 구해오면, 그 주소를 저장하는 변수

		if (newData != NULL)//newdata의 값이 null이 아니면
		{	
			printf("success\n");
			al->data = newData;//newdata의 값을 data에 저장
			al->capacity = newCapacity;//newcapacity값을 capacity에 저장
		}
	}

	for (int i = al->size-1; i >= pos; i--) {  //넣고싶은 자리에 수를 넣으려면, 기존 숫자들을 뒤로 한칸씩 밀어내야함.
		al->data[i + 1] = al->data[i];        //앞에서부터 밀면 뒤에수를 덮어써버림 따라서 뒤에서부터
	}										//이러면 pos자리가 비게 됨. -1이 없었음*******

	al->data[pos] = item;    //data[pos]자리에 item 추가함
	al->size++;				//데어터 하나 늘어났으니 size++
	 
	return 1;				//정상 종료
}

elementArrayList deleteArrayList(
	arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
		printf("error\n");					//error출력*******
	}

	elementArrayList item = al->data[pos];

	if (item.value <= 0)
	{
		printf("positive only\n");
	}
												//pos위치를 덮어쓰기위한 for문
	for (int i = pos; i < al->size - 1; i++) { //data[i+1]을 data[i]에 덮어쓰기. 결국 data[i]가 pos덮어씀.
		al->data[i] = al->data[i + 1];
	}

	al->size--;  //size 하나 줄이기 

	return item; //item을 return해서 item이 무슨 값이었는지 저장.
}

void initArrayList(arrayList* al) {

	if (al == NULL)return; //al에 아무것도 없다면, 나가기*******

	for (int i = al->size - 1; i >= 0; i--) { //deleteArrayList(al,pos)>>pos자리 지우기 위함 전체 지우려면,
		deleteArrayList(al, i);				//destory가 뒤에껄 앞에 덮어씌우는 작업이므로 pos 자리에 i 두고 size-1부터 --
	}
}

elementArrayList getItemArrayList(
	arrayList* al, int pos) {
	return al->data[pos];//data에 pos의 원소를 반환
}

int replaceItemArrayList(arrayList* al,
	int pos, elementArrayList item) {

	if (item.value <= 0)
	{	
		printf("positive only\n");
		return 0;
	}

	if (pos < 0 || pos > al->size - 1) { //pos가 0보다 작거나 size-1보다 크면 return 0
		return 0;
	}

	al->data[pos] = item; //data의 pos 위치에 item넣기

	return 1; //정상 종료
}

void printArrayList(arrayList* al) {
	printf("List= ");

	printf("Cap: %d, size: %d\n", al->capacity, al->size);

	for (int i = 0; i < al->size; i++) {
		printf("(%d %d %d) ", al->data[i].row,al->data[i].col, al->data[i].value);
	}
}
