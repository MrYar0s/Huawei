#include <gtest/gtest.h>

#include "stack-impl.hpp"
#include "stack.hpp"

const static int kMaxAmount = 1e6;

TEST(StackTest, IsEmptyInitially)
{
	stack::Stack<int> st_i;
	stack::Stack<double> st_d;
	stack::Stack<char> st_c;
	stack::Stack<bool> st_b;
	ASSERT_EQ(0, st_i.size());
	ASSERT_EQ(0, st_d.size());
	ASSERT_EQ(0, st_c.size());
	ASSERT_EQ(0, st_b.size());
	ASSERT_EQ(st_i.START_SIZE, st_i.max_size());
	ASSERT_EQ(st_d.START_SIZE, st_d.max_size());
	ASSERT_EQ(st_c.START_SIZE, st_c.max_size());
	ASSERT_EQ(st_b.START_SIZE, st_b.max_size());
}

TEST(StackTest, IsSizeInitially)
{
	size_t maxi = kMaxAmount;
	size_t maxd = kMaxAmount;
	size_t maxc = kMaxAmount;
	size_t maxb = kMaxAmount;
	stack::Stack<int> st_i(maxi);
	stack::Stack<double> st_d(maxd);
	stack::Stack<char> st_c(maxc);
	stack::Stack<bool> st_b(maxb);
	ASSERT_EQ(0, st_i.size());
	ASSERT_EQ(0, st_d.size());
	ASSERT_EQ(0, st_c.size());
	ASSERT_EQ(0, st_b.size());
	ASSERT_EQ(maxi, st_i.max_size());
	ASSERT_EQ(maxd, st_d.max_size());
	ASSERT_EQ(maxc, st_c.max_size());
	ASSERT_EQ(maxb, st_b.max_size());
}

TEST(StackTest, IsOtherInitially)
{
	size_t maxi = kMaxAmount;
	size_t maxd = kMaxAmount;
	size_t maxc = kMaxAmount;
	size_t maxb = kMaxAmount;
	stack::Stack<int> st_i(maxi);
	stack::Stack<double> st_d(maxd);
	stack::Stack<char> st_c(maxc);
	stack::Stack<bool> st_b(maxb);
	const stack::Stack<int> &st_ic(st_i);
	const stack::Stack<double> &st_dc(st_d);
	const stack::Stack<char> &st_cc(st_c);
	const stack::Stack<bool> &st_bc(st_b);
	ASSERT_EQ(st_i.max_size(), st_ic.max_size());
	ASSERT_EQ(st_d.max_size(), st_dc.max_size());
	ASSERT_EQ(st_c.max_size(), st_cc.max_size());
	ASSERT_EQ(st_b.max_size(), st_bc.max_size());
	ASSERT_EQ(st_i.size(), st_ic.size());
	ASSERT_EQ(st_d.size(), st_dc.size());
	ASSERT_EQ(st_c.size(), st_cc.size());
	ASSERT_EQ(st_b.size(), st_bc.size());
}

TEST(StackTest, IsEqualOperator)
{
	size_t size = kMaxAmount;
	stack::Stack<int> a_stack_i(size);
	stack::Stack<int> b_stack_i(size);
	for (size_t i = 0; i < size; i++)
	{
		a_stack_i.push(i);
		b_stack_i.push(i);
	}
	EXPECT_EQ(true, a_stack_i == b_stack_i);
	b_stack_i.pop();
	b_stack_i.push(rand()%kMaxAmount));
	EXPECT_EQ(false, a_stack_i == b_stack_i);
	stack::Stack<double> a_stack_d(size);
	stack::Stack<double> b_stack_d(size);
	double x = static_cast<double>(rand()/kMaxAmount);
	for (size_t i = 0; i < size; i++)
	{
		a_stack_d.push(x);
		b_stack_d.push(x);
		x = static_cast<double>(rand()/kMaxAmount);
	}
	EXPECT_EQ(true, a_stack_d == b_stack_d);
	b_stack_d.pop();
	b_stack_d.push(static_cast<double>(rand()/kMaxAmount));
	EXPECT_EQ(false, a_stack_d == b_stack_d);
	stack::Stack<char> a_stack_c(size);
	stack::Stack<char> b_stack_c(size);
	char c = static_cast<char>(rand()%256);
	for (size_t i = 0; i < size; i++)
	{
		a_stack_c.push(c);
		b_stack_c.push(c);
		c = static_cast<char>(rand()%256);
	}
	EXPECT_EQ(true, a_stack_c == b_stack_c);
	b_stack_c.pop();
	b_stack_c.push(static_cast<char>(rand()%256));
	EXPECT_EQ(false, a_stack_c == b_stack_c);
	stack::Stack<bool> a_stack_b(size);
	stack::Stack<bool> b_stack_b(size);
	bool b = static_cast<bool>(rand()%2);
	for (size_t i = 0; i < size; i++)
	{
		a_stack_b.push(b);
		b_stack_b.push(b);
		b = static_cast<bool>(rand()%2);
	}
	EXPECT_EQ(true, a_stack_b == b_stack_b);
	b_stack_b.pop();
	EXPECT_EQ(false, a_stack_b == b_stack_b);
}

TEST(StackTest, EqualOperator)
{
	size_t size = kMaxAmount;
	stack::Stack<int> a_stack_i(size);
	a_stack_i.push(rand()%kMaxAmount);
	stack::Stack<int> b_stack_i;
	b_stack_i = a_stack_i;
	EXPECT_EQ(true, b_stack_i == a_stack_i);
	stack::Stack<double> a_stack_d(size);
	a_stack_d.push(static_cast<double>(rand()/kMaxAmount));
	stack::Stack<double> b_stack_d;
	b_stack_d = a_stack_d;
	EXPECT_EQ(true, b_stack_d == a_stack_d);
	stack::Stack<char> a_stack_c(size);
	a_stack_c.push(static_cast<char>(rand()%256));
	stack::Stack<char> b_stack_c;
	b_stack_c = a_stack_c;
	EXPECT_EQ(true, b_stack_c == a_stack_c);
	stack::Stack<bool> a_stack_b(size);
	a_stack_b.push(static_cast<bool>(rand()%2));
	stack::Stack<bool> b_stack_b;
	b_stack_b = a_stack_b;
	EXPECT_EQ(true, b_stack_b == a_stack_b);
}

TEST(StackTestSizeT, PushPopFunc)
{
	stack::Stack<int> stack_sz;
	for (int i = 0; i < kMaxAmount; i++)
	{
		stack_sz.push(i);
		EXPECT_EQ(i, stack_sz.top());
	}
	for (int i = kMaxAmount - 1; i >= 0; i--)
	{
		EXPECT_EQ(i, stack_sz.top());
		stack_sz.pop();
	}
}
TEST(StackTestDouble, PushPopFunc)
{
	stack::Stack<double> stack_d;
	std::vector<double> values;
	double d = 0;
	for (int i = 0; i < kMaxAmount; i++)
	{
		values.push_back(d);
		d = static_cast<double>(rand()/kMaxAmount);
	}
	for (int i = 0; i < kMaxAmount; i++)
	{
		stack_d.push(values[i]);
		EXPECT_EQ(values[i], stack_d.top());
	}
	for (int i = kMaxAmount - 1; i >= 0; i--)
	{
		EXPECT_EQ(values[i], stack_d.top());
		stack_d.pop();
	}
}
TEST(StackTestChar, PushPopFunc)
{
	stack::Stack<char> stack_c;
	std::vector<char> values;
	char j = static_cast<char>(rand()%256);
	for (int i = 0; i < kMaxAmount; i++)
	{
		values.push_back(j);
		j = static_cast<char>(rand()%256);
	}
	for (int i = 0; i < kMaxAmount; i++)
	{
		stack_c.push(values[i]);
		EXPECT_EQ(values[i], stack_c.top());
	}
	for (int i = kMaxAmount - 1; i >= 0; i--)
	{
		EXPECT_EQ(values[i], stack_c.top());
		stack_c.pop();
	}
}
TEST(StackTestBool, PushPopFunc)
{
	stack::Stack<bool> stack_b;
	std::vector<bool> values;
	bool k = false;
	for (int i = 0; i < kMaxAmount; i++)
	{
		values.push_back(k);
		k = static_cast<bool>(rand()%2);
	}
	for (int i = 0; i < kMaxAmount; i++)
	{
		stack_b.push(values[i]);
		EXPECT_EQ(values[i], stack_b.top()) << "push " << i;
	}
	for (int i = kMaxAmount - 1; i >= 0; i--)
	{
		EXPECT_EQ(values[i], stack_b.top()) << "pop " << i;
		stack_b.pop();
	}
}

TEST(StackTestInt, TopFunc)
{
	stack::Stack<int> stack_i;
	int value = rand()%kMaxAmount
	stack_i.push(value);
	EXPECT_EQ(value, stack_i.top());
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
