extern "C"
{
#include "LinkedList.h"
}

#include "CppUTest/TestHarness.h"

void put10IntsInTheList(List *list)
{
	int i, *data;
	ListElmnt *element;
	element = list_head(list);
	for (i = 10; i > 0; i--) {
		if ((data = (int *)malloc(sizeof(int))) == NULL)
			return;
		*data = i;
	if (LinkedList_InsertNext(list, NULL, data) != 0)
		return;

	  }
}

TEST_GROUP(LinkedList)
{
	List list;
	ListElmnt *element;
	int *data, *data2, i;

	void setup()
	{
		LinkedList_Create(&list, free);
	}

	void teardown()
	{
		//       LinkedList_Destroy();
	}
};

TEST(LinkedList, Create)
{
	LONGS_EQUAL(0, list_size(&list));
	CHECK_EQUAL(free, list.destroy);
	CHECK_EQUAL(0, list_head(&list));
	CHECK_EQUAL(0, list_tail(&list));
}

TEST(LinkedList, insert10Elements)
{
	put10IntsInTheList(&list);
	CHECK_EQUAL(10, list_size(&list));
	element = list_head(&list);
	for(i=1; i<11; i++)
	{
		data = (int*) list_data(element);
		CHECK_EQUAL(i,*data)
		element = list_next(element);
	}
}
}
