#include <gtest/gtest.h>

#include "../include/stack-impl.hpp"
#include "../include/stack.hpp"

size_t start = 1256235;

TEST(StackTest, IsEmptyInitially) {
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

TEST(StackTest, IsSizeInitially) {
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

TEST(StackTest, IsOtherInitially) {
  size_t maxi = 187912;
  size_t maxd = 7529;
  size_t maxc = 92412;
  size_t maxb = 4126433;
  stack::Stack<int> st_i(maxi);
  stack::Stack<double> st_d(maxd);
  stack::Stack<char> st_c(maxc);
  stack::Stack<bool> st_b(maxb);
  stack::Stack<int> st_ic(st_i);
  stack::Stack<double> st_dc(st_d);
  stack::Stack<char> st_cc(st_c);
  stack::Stack<bool> st_bc(st_b);
  ASSERT_EQ(st_i.max_size(), st_ic.max_size());
  ASSERT_EQ(st_d.max_size(), st_dc.max_size());
  ASSERT_EQ(st_c.max_size(), st_cc.max_size());
  ASSERT_EQ(st_b.max_size(), st_bc.max_size());
  ASSERT_EQ(st_i.size(), st_ic.size());
  ASSERT_EQ(st_d.size(), st_dc.size());
  ASSERT_EQ(st_c.size(), st_cc.size());
  ASSERT_EQ(st_b.size(), st_bc.size());
}

TEST(StackTest, IsEqualOperator) {
  size_t size = 5162346;
  stack::Stack<int> ai(size);
  stack::Stack<int> bi(size);
  for (size_t i = 0; i < size; i++) {
    ai.push(i);
    bi.push(i);
  }
  EXPECT_EQ(true, ai == bi);
  bi.pop();
  bi.push(-1);
  EXPECT_EQ(false, ai == bi);
  stack::Stack<double> ad(size);
  stack::Stack<double> bd(size);
  double x = 0.3;
  for (size_t i = 0; i < size; i++) {
    ad.push(x);
    bd.push(x);
    x *= 1.4;
  }
  EXPECT_EQ(true, ad == bd);
  bd.pop();
  bd.push(-1.45);
  EXPECT_EQ(false, ad == bd);
  stack::Stack<char> ac(size);
  stack::Stack<char> bc(size);
  char c = 'b';
  for (size_t i = 0; i < size; i++) {
    ac.push(c);
    bc.push(c);
    c += 2;
  }
  EXPECT_EQ(true, ac == bc);
  bc.pop();
  bc.push('a');
  EXPECT_EQ(false, ac == bc);
  stack::Stack<bool> ab(size);
  stack::Stack<bool> bb(size);
  bool b = true;
  for (size_t i = 0; i < size; i++) {
    ab.push(b);
    bb.push(b);
    b = !b;
  }
  EXPECT_EQ(true, ab == bb);
  bb.pop();
  EXPECT_EQ(false, ab == bb);
}

TEST(StackTest, EqualOperator) {
  size_t size = 6347584;
  stack::Stack<int> ai(size);
  ai.push(6347251);
  stack::Stack<int> bi;
  bi = ai;
  EXPECT_EQ(true, bi == ai);
  stack::Stack<double> ad(size);
  ad.push(-532.241);
  stack::Stack<double> bd;
  bd = ad;
  EXPECT_EQ(true, bd == ad);
  stack::Stack<char> ac(size);
  ac.push('F');
  stack::Stack<char> bc;
  bc = ac;
  EXPECT_EQ(true, bc == ac);
  stack::Stack<bool> ab(size);
  ai.push(false);
  stack::Stack<bool> bb;
  bb = ab;
  EXPECT_EQ(true, bb == ab);
}

TEST(StackTestInt, PushPopFunc) {
  stack::Stack<int> ai;
  for (size_t i = 0; i < 2 * start; i++) {
    ai.push(i);
    EXPECT_EQ(i, ai.top());
  }
  for (int i = 2 * start - 1; i >= 0; i--) {
    EXPECT_EQ(i, ai.top());
    ai.pop();
  }
}
TEST(StackTestDouble, PushPopFunc) {
  stack::Stack<double> ad;
  std::vector<double> v;
  double d = 0;
  for (size_t i = 0; i < 2 * start; i++) {
    v.push_back(d);
    d *= -1.45;
  }
  for (size_t i = 0; i < 2 * start; i++) {
    ad.push(v[i]);
    EXPECT_EQ(v[i], ad.top());
  }
  for (int i = 2 * start - 1; i >= 0; i--) {
    EXPECT_EQ(v[i], ad.top());
    ad.pop();
  }
}
TEST(StackTestChar, PushPopFunc) {
  stack::Stack<char> ac;
  std::vector<char> c;
  char j = 'c';
  for (size_t i = 0; i < 2 * start; i++) {
    c.push_back(j);
    j += 2;
  }
  for (size_t i = 0; i < 2 * start; i++) {
    ac.push(c[i]);
    EXPECT_EQ(c[i], ac.top());
  }
  for (int i = 2 * start - 1; i >= 0; i--) {
    EXPECT_EQ(c[i], ac.top());
    ac.pop();
  }
}
TEST(StackTestBool, PushPopFunc) {
  stack::Stack<bool> ab;
  std::vector<bool> b;
  bool k = true;
  for (size_t i = 0; i < 2 * start; i++) {
    b.push_back(k);
    k = !k;
  }
  for (size_t i = 0; i < 2 * start; i++) {
    ab.push(b[i]);
    EXPECT_EQ(b[i], ab.top()) << "push " << i;
  }
  for (int i = 2 * start - 1; i >= 0; i--) {
    EXPECT_EQ(b[i], ab.top()) << "pop " << i;
    ab.pop();
  }
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
