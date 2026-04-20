#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

//동적으로 메모리 할당받아서 0행0열 0값을 data에 넣고 삭제하고 뭐하고 뭐해서 출력하는 프로그램
int main()
{
	arrayList* myArrayList;
	myArrayList = createArrayList(4);

	if (sizeArrayList(myArrayList) == 0) //myarraylist에 al->size=0;이 제대로 동작했으면
	{									//sizearraylist(myarrayllist)==0일것임.
		printf("create ok\n");
	}


	elementArrayList item;
	item.row = 0;
	item.col = 0;
	item.value = -1;


	insertArrayList(myArrayList, 0, item);
	printArrayList(myArrayList);
	
	return 0;

}