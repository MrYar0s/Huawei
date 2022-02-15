#include "../list_version/include/queue_impl.hpp"
#include "../stack_version/include/queue_impl.hpp"

#include <gtest/gtest.h>

#ifdef QUEUE_STACK
using namespace queue_stack;
#endif

#ifdef QUEUE_LIST
using namespace queue_list;
#endif

TEST(IntQueueTest, CopyConstructorTest)
{
	for(size_t i = 0; i < 100; i++)
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
	int val = 4;
	qu.push(val);
	for(size_t i = 0; i < 4; i++)
	{
		qu.push(i);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(IntQueueTest, PopTest)
{
	Queue<int> qu;
	int val = 4;
	qu.push(val);
	for(size_t i = 0; i < 1000000; i++)
	{
		qu.pop();
		val += 42;
		qu.push(val);
		ASSERT_EQ(val, qu.front());
	}
}

TEST(IntQueueTest, IsEmptyTest)
{
	Queue<int> qu;
	ASSERT_EQ(true, qu.is_empty());
	qu.push(4215);
	ASSERT_EQ(false, qu.is_empty());
	qu.pop();
	ASSERT_EQ(true, qu.is_empty());
}

TEST(IntQueueTest, OperatorEqualTest)
{
	Queue<int> qu1;
	Queue<int> qu2;

	for(size_t i = 0; i < 100000; i++)
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

	for(size_t i = 0; i < 1000000; i++)
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
	qu2.push(4121241);
	for(size_t i = 0; i < 1000000; i++)
	{
		qu1.push(static_cast<int>(i));
	}
	qu2 = qu1;
	ASSERT_EQ(qu1, qu2);
}

TEST(DoubleQueueTest, CopyConstructorTest)
{
        for(size_t i = 0; i < 1000000; i++)
        {
                Queue<double> qu1;
		qu1.push(static_cast<double>(i));
                Queue<double> qu2 = qu1;
                ASSERT_EQ(qu1.front(), qu2.front());
        }
}

Queue<double> queue_for_double_move_constructor()
{
        Queue<double> qu;
	std::cout << "Start size" << qu.size();
	qu.push(241.23);
	std::cout << "End size" << qu.size();
        return qu;
}

TEST(DoubleQueueTest, MoveConstructorTest)
{
        Queue<double> qu1(queue_for_double_move_constructor());
        ASSERT_EQ(241.23, qu1.front());
}

TEST(DoubleQueueTest, PushTest)
{
        Queue<double> qu;
        double val = 2.3;
	qu.push(val);
        for(size_t i = 0; i < 3; i++)
        {
                qu.push(i);
                ASSERT_EQ(val, qu.front());
        }
}

TEST(DoubleQueueTest, PopTest)
{
        Queue<double> qu;
        double val = 3.4;
        qu.push(val);
        for(size_t i = 0; i < 1000000; i++)
        {
                qu.pop();
                val += 1.52;
                qu.push(val);
                ASSERT_EQ(val, qu.front());
        }
}

TEST(DoubleQueueTest, IsEmptyTest)
{
        Queue<double> qu;
        ASSERT_EQ(true, qu.is_empty());
        qu.push(4.215);
        ASSERT_EQ(false, qu.is_empty());
        qu.pop();
        ASSERT_EQ(true, qu.is_empty());
}

TEST(DoubleQueueTest, OperatorEqualTest)
{
        Queue<double> qu1;
        Queue<double> qu2;

        for(size_t i = 0; i < 100000; i++)
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

        for(size_t i = 0; i < 1000000; i++)
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
        qu2.push(412.1241);
        for(size_t i = 0; i < 1000000; i++)
        {
                qu1.push(static_cast<double>(i));
        }
        qu2 = qu1;
        ASSERT_EQ(qu1, qu2);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
