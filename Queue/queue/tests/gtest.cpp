#include <gtest/gtest.h>

#include <ctime>

#include "list_version/queue_impl.hpp"
#include "stack_version/queue_impl.hpp"

static const size_t kNTest = 1e6;

#ifdef QUEUE_STACK
using namespace queue_stack;
#endif

#ifdef QUEUE_LIST
using namespace queue_list;
#endif

TEST(IntQueueTest, CopyConstructorTest)
{
	for (size_t i = 0; i < kNTest; i++)
	{
		Queue<int> qu1;
		qu1.push(static_cast<int>(i));
		Queue<int> qu2 = qu1;
		ASSERT_EQ(qu1.front(), qu2.front());
	}
}

TEST(IntQueueTest, PushTest)
{
	Queue<int> qu;
	size_t val = kNTest;
	qu.push(val);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu.push(i);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(IntQueueTest, PopTest)
{
	Queue<int> qu;
	int val = rand() % kNTest;
	qu.push(val);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu.pop();
		val = rand() % kNTest;
		qu.push(val);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(IntQueueTest, IsEmptyTest)
{
	Queue<int> qu;
	ASSERT_EQ(true, qu.is_empty());
	qu.push(rand() % kNTest);
	ASSERT_EQ(false, qu.is_empty());
	qu.pop();
	ASSERT_EQ(true, qu.is_empty());
}

TEST(IntQueueTest, OperatorEqualTest)
{
	Queue<int> qu1;
	Queue<int> qu2;

	for (size_t i = 0; i < kNTest; i++)
	{
		auto val = static_cast<int>(i);
		qu1.push(val);
		qu2.push(val);
	}
	ASSERT_EQ(qu1, qu2);
}

TEST(IntQueueTest, OperatorNotEqualTest)
{
	Queue<int> qu1;
	Queue<int> qu2;

	for (size_t i = 0; i < kNTest; i++)
	{
		qu1.push(i);
		qu2.push(i - 1);
		ASSERT_NE(qu1, qu2);
	}
}

TEST(IntQueueTest, CopyOperatorTest)
{
	Queue<int> qu1;
	Queue<int> qu2;
	qu2.push(rand() % kNTest);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu1.push(static_cast<int>(i));
	}
	qu2 = qu1;
	ASSERT_EQ(qu1, qu2);
}

TEST(DoubleQueueTest, CopyConstructorTest)
{
	for (size_t i = 0; i < kNTest; i++)
	{
		Queue<double> qu1;
		qu1.push(static_cast<double>(i));
		Queue<double> qu2 = qu1;
		ASSERT_EQ(qu1.front(), qu2.front());
	}
}

Queue<double> queue_for_double_move_constructor(double* val)
{
	Queue<double> qu;
	*val = (static_cast<double>(rand() % kNTest)) / kNTest;
	qu.push(*val);
	return qu;
}

TEST(DoubleQueueTest, MoveConstructorTest)
{
	double val = 0;
	Queue<double> qu1(queue_for_double_move_constructor(&val));
	ASSERT_EQ(val, qu1.front());
}

TEST(DoubleQueueTest, PushTest)
{
	Queue<double> qu;
	double val = static_cast<double>(rand() % kNTest) / kNTest;
	qu.push(val);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu.push(i);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(DoubleQueueTest, PopTest)
{
	Queue<double> qu;
	double val = static_cast<double>(rand() % kNTest) / kNTest;
	qu.push(val);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu.pop();
		val = (static_cast<double>(rand() % kNTest)) / kNTest;
		qu.push(val);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(DoubleQueueTest, IsEmptyTest)
{
	Queue<double> qu;
	ASSERT_EQ(true, qu.is_empty());
	qu.push((static_cast<double>(rand() % kNTest)) / kNTest);
	ASSERT_EQ(false, qu.is_empty());
	qu.pop();
	ASSERT_EQ(true, qu.is_empty());
}

TEST(DoubleQueueTest, OperatorEqualTest)
{
	Queue<double> qu1;
	Queue<double> qu2;

	for (size_t i = 0; i < kNTest; i++)
	{
		auto val = static_cast<double>(i);
		qu1.push(val);
		qu2.push(val);
	}
	ASSERT_EQ(qu1, qu2);
}

TEST(DoubleQueueTest, OperatorNotEqualTest)
{
	Queue<double> qu1;
	Queue<double> qu2;

	for (size_t i = 0; i < kNTest; i++)
	{
		qu1.push(i);
		qu2.push(i - 1);
		ASSERT_NE(qu1, qu2);
	}
}

TEST(DoubleQueueTest, CopyOperatorTest)
{
	Queue<double> qu1;
	Queue<double> qu2;
	qu2.push((static_cast<double>(rand() % kNTest)) / kNTest);
	for (size_t i = 0; i < kNTest; i++)
	{
		qu1.push(static_cast<double>(i));
	}
	qu2 = qu1;
	ASSERT_EQ(qu1, qu2);
}

int main(int argc, char** argv)
{
	srand(time(nullptr));
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
