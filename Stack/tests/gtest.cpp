#include <gtest/gtest.h>

#include "stack-impl.hpp"
#include "stack.hpp"

const static int kMaxAmount = 2151522;

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
	size_t maxi = 187912;
	size_t maxd = 7529;
	size_t maxc = 92412;
	size_t maxb = 9521643;
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
	size_t maxi = 187912;
	size_t maxd = 7529;
	size_t maxc = 92412;
	size_t maxb = 4126433;
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
	size_t size = 5162346;
	stack::Stack<int> a_stack_i(size);
	stack::Stack<int> b_stack_i(size);
	for (size_t i = 0; i < size; i++)
	{
		a_stack_i.push(i);
		b_stack_i.push(i);
	}
	EXPECT_EQ(true, a_stack_i == b_stack_i);
	b_stack_i.pop();
	b_stack_i.push(-1);
	EXPECT_EQ(false, a_stack_i == b_stack_i);
	stack::Stack<double> a_stack_d(size);
	stack::Stack<double> b_stack_d(size);
	double x = 0.3;
	for (size_t i = 0; i < size; i++)
	{
		a_stack_d.push(x);
		b_stack_d.push(x);
		x *= 1.4;
	}
	EXPECT_EQ(true, a_stack_d == b_stack_d);
	b_stack_d.pop();
	b_stack_d.push(-1.45);
	EXPECT_EQ(false, a_stack_d == b_stack_d);
	stack::Stack<char> a_stack_c(size);
	stack::Stack<char> b_stack_c(size);
	char c = 'b';
	for (size_t i = 0; i < size; i++)
	{
		a_stack_c.push(c);
		b_stack_c.push(c);
		c += 2;
	}
	EXPECT_EQ(true, a_stack_c == b_stack_c);
	b_stack_c.pop();
	b_stack_c.push('a');
	EXPECT_EQ(false, a_stack_c == b_stack_c);
	stack::Stack<bool> a_stack_b(size);
	stack::Stack<bool> b_stack_b(size);
	bool b = true;
	for (size_t i = 0; i < size; i++)
	{
		a_stack_b.push(b);
		b_stack_b.push(b);
		b = !b;
	}
	EXPECT_EQ(true, a_stack_b == b_stack_b);
	b_stack_b.pop();
	EXPECT_EQ(false, a_stack_b == b_stack_b);
}

TEST(StackTest, EqualOperator)
{
	size_t size = 6347584;
	stack::Stack<int> a_stack_i(size);
	a_stack_i.push(6347251);
	stack::Stack<int> b_stack_i;
	b_stack_i = a_stack_i;
	EXPECT_EQ(true, b_stack_i == a_stack_i);
	stack::Stack<double> a_stack_d(size);
	a_stack_d.push(-532.241);
	stack::Stack<double> b_stack_d;
	b_stack_d = a_stack_d;
	EXPECT_EQ(true, b_stack_d == a_stack_d);
	stack::Stack<char> a_stack_c(size);
	a_stack_c.push('F');
	stack::Stack<char> b_stack_c;
	b_stack_c = a_stack_c;
	EXPECT_EQ(true, b_stack_c == a_stack_c);
	stack::Stack<bool> a_stack_b(size);
	a_stack_b.push(false);
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
		d *= -1.45;
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
	char j = 'c';
	for (int i = 0; i < kMaxAmount; i++)
	{
		values.push_back(j);
		j += 2;
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
	bool k = true;
	for (int i = 0; i < kMaxAmount; i++)
	{
		values.push_back(k);
		k = !k;
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

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
