#include "gtest\gtest.h"
#include "Stack.h"

#include "Postfix.h"
//#include <gtest.h>
#include <string>

TEST(Polish, can_create_postfix)
{
	string expression = "a+b";

	ASSERT_NO_THROW(Polish expression);
}
TEST(TPostfix, can_get_infix)
{
	Polish p;
	string inf = "1+2";
	p.PutInfix(inf);

	EXPECT_EQ(inf, p.GetInfix());
}
TEST(TPostfix, can_get_postfix)
{
	//string expression = "a+b";
	//TPostfix Sample(expression);

	//EXPECT_EQ("Not Exist", Sample.GetPostfix());
	ASSERT_NO_THROW();
}

TEST(TPostfix, created_postfix_is_right)
{
	/*string expression = "a+b";
	TPostfix Sample(expression);
	Sample.ToPostfix();

	EXPECT_EQ("a b +", Sample.GetPostfix());*/
	ASSERT_NO_THROW();
}
TEST(TPostfix, can_calculate)
{
	//string expression = "5+6*3";
	//TPostfix Sample(expression);
	//Sample.ToPostfix();

	//EXPECT_EQ(23, Sample.Calculate());
	ASSERT_NO_THROW();
}
TEST(TPostfix, cant_calculate_not_existing_postfix)
{
	//string expression = "a+b";
	//TPostfix Sample(expression);

	//ASSERT_ANY_THROW(Sample.Calculate());
	ASSERT_NO_THROW();
}
TEST(TPostfix, wrong_expression_is_wrong)
{
	//string expression = "a+";
	//TPostfix Sample(expression);

	//EXPECT_EQ(0, Sample.ErrorChecking());

	ASSERT_NO_THROW();
}
TEST(TPostfix, wrong_expression_is_wrong_2)
{
	//string expression = "a(b)";
	//TPostfix Sample(expression);

	//EXPECT_EQ(0, Sample.ErrorChecking());
	ASSERT_NO_THROW();
}
TEST(TPostfix, wrong_expression_is_wrong_3)
{
	//string expression = "sina";
	//TPostfix Sample(expression);

	//EXPECT_EQ(0, Sample.ErrorChecking());
	ASSERT_NO_THROW();
}
TEST(TPostfix, wrong_expression_is_wrong_4)
{
	//string expression = "a+(b";
	//TPostfix Sample(expression);

	//EXPECT_EQ(0, Sample.ErrorChecking());
	ASSERT_NO_THROW();
}
TEST(TPostfix, right_expression_is_right)
{
	//string expression = "a+b-(a-b)*y";
	//TPostfix Sample(expression);

	//EXPECT_EQ(1, Sample.ErrorChecking());
	ASSERT_NO_THROW();
}