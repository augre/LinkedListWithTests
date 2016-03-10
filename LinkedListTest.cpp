extern "C"
{
#include "LinkedList.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LinkedList)
{
    List list;
    ListElmnt element;
    int *data;

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
IGNORE_TEST(LinkedList, insert)
{
	CHECK_EQUAL(0, (data = (int *)malloc(sizeof(int))))
	*data = 29;
	LinkedList_InsertNext(&list, NULL,data);
	
}
