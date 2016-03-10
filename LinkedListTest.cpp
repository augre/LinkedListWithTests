extern "C"
{
#include "LinkedList.h"
}

#include "CppUTest/TestHarness.h"

/*
static void print_list(const List *list) {

	ListElmt           *element;
	int                *data, i;

	fprintf(stdout, "List size is %d\n", list_size(list));

	i = 0;
	element = list_head(list);

	while (1) {

		data = list_data(element);
		fprintf(stdout, "list[%03d]=%03d\n", i, *data);

		i++;

		if (list_is_tail(element))
			break;
		else
			element = list_next(element);

	}

	return;

}
*/
TEST_GROUP(LinkedList)
{
	List list;
	ListElmnt *element;
	int *data, *data2;

	void setup()
	{
		LinkedList_Create(&list, NULL);
	}

	void teardown()
	{
		//       LinkedList_Destroy();
	}
};

TEST(LinkedList, Create)
{
	LONGS_EQUAL(0, list.size);
	CHECK_EQUAL(0, list.destroy);
	CHECK_EQUAL(0, list.head);
	CHECK_EQUAL(0, list.tail);
}

TEST(LinkedList, insert)
{
	if ((data = (int *)malloc(sizeof(int))) == NULL)
		FAIL("bad malloc");
	*data = 29;
	CHECK_EQUAL(0,LinkedList_InsertNext(&list, NULL,data));
	CHECK_EQUAL(1, list.size);
	element = list.head;
	data2 =(int*) element->data;
	CHECK_EQUAL(*data, *data2);
}
