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

TEST(LinkedList, Destroy)
{
	put10IntsInTheList(&list);
	CHECK_EQUAL(11, list_size(&list));
	LinkedList_Destroy(&list);
	LONGS_EQUAL(0, list_size(&list));
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

TEST(LinkedList, insert10ElementsAndRemove7)
{
	put10IntsInTheList(&list);
	CHECK_EQUAL(10, list_size(&list));
	element = list_head(&list);
	for (i=0; i<5; i++)
		element = list_next(element);
	if (LinkedList_RemoveNext(&list, element, (void**)&data)!=0)
		FAIL("failed to remove");
	CHECK_EQUAL(9, list_size(&list));
	CHECK_EQUAL(7, *data)
}

TEST(LinkedList, removeAllElements)
{
	put10IntsInTheList(&list);
	CHECK_EQUAL(10, list_size(&list));
	int size=list_size(&list);
	for (i=0; i<size; i++)
	{
		if (LinkedList_RemoveNext(&list, NULL, (void**)&data)!=0)
			FAIL("failed to remove");
		free(data);
	}
	CHECK_EQUAL(0, list_size(&list));
}
