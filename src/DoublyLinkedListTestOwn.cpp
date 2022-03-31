
#include <gtest/gtest.h>

#include "DoublyLinkedList.hpp"

struct TestStruct
{
	std::string key;
	std::string value;
	bool operator==(TestStruct const& other)
	{
		return key == other.key;
	}
};

TEST(CreateRemoveInt, StudentWrittenTests)
{
	DoublyLinkedList<int> list;
	list.create(4);
	list.create(3);
	list.create(2);
	list.create(1);
	EXPECT_EQ(list.size(), 4);
	list.remove(2);
	list.remove(1);
	EXPECT_EQ(list.size(), 2);
}

TEST(CreateRemoveStruct, StudentWrittenTests)
{
	DoublyLinkedList<TestStruct> list;
	list.create(TestStruct{ "a", "a" });
	list.create(TestStruct{ "b", "a" });
	list.create(TestStruct{ "c", "c" });
	list.create(TestStruct{ "d", "d" });
	EXPECT_EQ(list.size(), 4);
	list.remove(TestStruct{ "a", "a" });
	list.remove(TestStruct{ "c", "c" });
	list.remove(TestStruct{ "d", "d" });
	EXPECT_EQ(list.size(), 1);
}

TEST(CreateUpdateInt, StudentWrittenTests)
{
	DoublyLinkedList<int> list;
	list.create(4);
	list.create(3);
	list.create(2);
	list.create(1);
	EXPECT_EQ(list.size(), 4);
	list.update(3, 5);
	list.update(1, 0);
	EXPECT_EQ(list.retreive(4), 4);
	EXPECT_EQ(list.retreive(5), 5);
	EXPECT_EQ(list.retreive(2), 2);
	EXPECT_EQ(list.retreive(0), 0);
	EXPECT_THROW(list.retreive(1), std::runtime_error);
}

TEST(CreateUpdateStruct, StudentWrittenTests)
{
	DoublyLinkedList<TestStruct> list;
	list.create(TestStruct{ "a", "a" });
	list.create(TestStruct{ "b", "a" });
	list.create(TestStruct{ "c", "c" });
	list.create(TestStruct{ "d", "d" });
	EXPECT_EQ(list.size(), 4);
	list.update(TestStruct{ "a", "a" }, TestStruct{ "f","f" });
	list.update(TestStruct{ "c", "c" }, TestStruct{ "a","a" });
	EXPECT_EQ(list.retreive(TestStruct{ "f", "" }).value, "f");
	EXPECT_EQ(list.retreive(TestStruct{ "b", "" }).value, "a");
	EXPECT_EQ(list.retreive(TestStruct{ "a", "" }).value, "a");
}