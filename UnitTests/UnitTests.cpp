#include "gtest\gtest.h"
#include "Stack.h"
#include "Postfix.h"

TEST(Polish, can_create_postfix)
{
	ASSERT_NO_THROW(Polish p);
}

TEST(Polish, can_put_infix)
{
	Polish p;
	string inf = "1+2";

	ASSERT_NO_THROW(p.PutInfix(inf));
}

TEST(Polish, can_get_infix)
{
	Polish p;
	string inf = "1+2";
	p.PutInfix(inf);

	EXPECT_EQ(inf, p.GetInfix());
}

TEST(Polish, can_get_postfix)
{
	Polish p;
	string str = "null";

	EXPECT_EQ(str, p.GetPostfix());
}


TEST(Polish, created_postfix_is_right)
{
string inf = "2+3";
Polish p;
p.PutInfix(inf);
p.Translator();
string postfix = p.GetPostfix();
EXPECT_EQ("2 3 +", postfix);
}

TEST(Polish, can_calculate)
{
	string inf = "2+3*2";
	Polish p;
	p.PutInfix(inf);
	p.Translator();
	EXPECT_EQ(8, p.GetResult());
}

//TEST(Polish, cant_calculate_not_exising_infix)
//{
//	string str = "a+b";
//	Polish p;
//	p.PutInfix(str);
//	p.Translator();
//	ASSERT_ANY_THROW(p.GetResult());
//}

TEST(Polish, wrong_infix_is_wrong_1)
{
	string inf = "a+";
	Polish p;
	p.PutInfix(inf);
	EXPECT_EQ(0,p.CINCheck());
}

TEST(Polish, wrong_infix_is_wrong_2)
{
	string inf = "*a";
	Polish p;
	p.PutInfix(inf);
	EXPECT_EQ(0, p.CINCheck());
}

TEST(Polish, wrong_infix_is_wrong_3)
{
	string inf = "(a";
	Polish p;
	p.PutInfix(inf);
	EXPECT_EQ(0, p.CINCheck());
}

TEST(Polish, wrong_infix_is_wrong_4)
{
	string inf = "a(b)";  //после операнда не может стоять операнд добавить
	Polish p;
	p.PutInfix(inf);
	EXPECT_EQ(0, p.CINCheck());
}

TEST(Polish, right_infix_is_right)
{
	string inf = "a+b";
	Polish p;
	p.PutInfix(inf);
	EXPECT_EQ(1, p.CINCheck());
}

/////////////STACK///////////

TEST(Stack, can_create_with_pozitiv_lendth)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}

TEST(Stack, cant_create_with_negativ_length)
{
	ASSERT_ANY_THROW(Stack<int> st(-5));
}

TEST(Stack, cant_create_with_large_length)
{
	int n = MemSize + 1;
	ASSERT_ANY_THROW(Stack<int> st(n));
}

TEST(Stack, can_push_elem)
{
	Stack<int>st(5);
	ASSERT_NO_THROW(st.Push(5));
}

TEST(Stack, can_get_top)
{
	Stack<int>st(5);
	st.Push(2);
	EXPECT_EQ(2, st.Watchtop());
}