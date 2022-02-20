#include <gtest/gtest.h>
#include <ctime>

#include "tree_impl.hpp"

static const size_t kNTest = 1e6;

using tree::Tree;

TEST(IntTreeTest, DefaultConstructor)
{
	Tree<int> tree;
	ASSERT_EQ(0, tree.size());
}

TEST(IntTreeTest, CopyConstructor)
{
	Tree<int> tree;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(rand()%kNTest);
	}
	Tree<int> tree_copy{tree};
	EXPECT_EQ(tree, tree_copy);
}

TEST(IntTreeTest, MoveConstructor)
{
	Tree<int> tree;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(rand()%kNTest);
	}
	Tree<int> tree_move(std::move(tree));
	ASSERT_NE(0, tree_move.size());
}

TEST(IntTreeTest, CopyOperator)
{
	Tree<int> tree;
	Tree<int> tree_copy;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(rand()%kNTest);
	}
	tree_copy = tree;
	EXPECT_EQ(tree, tree_copy);
}

TEST(IntTreeTest, MoveOperator)
{
	Tree<int> tree;
	Tree<int> tree_move;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(rand()%kNTest);
	}
	tree_move = std::move(tree);
	EXPECT_NE(0, tree_move.size());
}

TEST(IntTreeTest, IsEqTest)
{
	Tree<int> tree0;
	Tree<int> tree1;
	for(size_t i = 0; i < kNTest; i++)
	{
		int value = rand()%kNTest;
		tree0.insert(value);
		tree1.insert(value);
	}
	EXPECT_EQ(tree0, tree1);
}

TEST(IntTreeTest, IsNeqTest)
{
	Tree<int> tree0;
	Tree<int> tree1;
	for(size_t i = 0; i < kNTest; i++)
	{
		int value = rand()%kNTest;
		tree0.insert(value);
		tree1.insert(value);
	}
	tree0.insert(rand()%kNTest);
	EXPECT_NE(tree0, tree1);
}

TEST(IntTreeTest, IsEmptyTest)
{
	Tree<int> tree;
	EXPECT_EQ(tree.is_empty(), true);
	tree.insert(rand()%kNTest);
	EXPECT_EQ(tree.is_empty(), false);
}

TEST(IntTreeTest, SizeTest)
{
	Tree<int> tree;
	size_t size = 0;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(i);
		size++;
	}
	EXPECT_EQ(size, tree.size());
}

TEST(IntTreeTest, InsertGetTest)
{
	Tree<int> tree;
	int value = rand()%kNTest;
	tree.insert(value);
	EXPECT_NE(nullptr, tree.find(value));
	EXPECT_EQ(nullptr, tree.find(value + 1));
}

TEST(IntTreeTest, PrintTest)
{
	Tree<int> tree;
	for(size_t i = 0; i < kNTest; i++)
	{
		tree.insert(rand()%kNTest);
	}
	tree.print();
}

int main(int argc, char** argv)
{
	srand(time(nullptr));
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}