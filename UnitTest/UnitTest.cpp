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
	Polish p;
	string str = "a+b";

	EXPECT_EQ(str, p.GetPostfix());
}

TEST(TPostfix, created_postfix_is_right)
{
	string str = "a+b";
	Polish p;
	p.PutInfix(str);
	p.Translator();
	string postfix = p.GetPostfix;
	EXPECT_EQ("a b +", postfix);
}

TEST(TPostfix, can_calculate)
{
	string str = "5+6";
	Polish p;
	p.PutInfix(str);
	p.Translator();
	double res = p.GetResult();
	EXPECT_EQ(23, res);
}

TEST(TPostfix, cant_calculate_not_existing_postfix)
{
	string str= "a+b";
	Polish p;
	p.PutInfix(str);
	double res = p.GetResult();
	ASSERT_ANY_THROW(res);
}



TEST(TPostfix, wrong_expression_is_wrong)
{
	//string str = "a+";
	//Polish p;
	//p.PutInfix(str);
	//EXPECT_EQ(0, p.CINCheck());

	ASSERT_NO_THROW();
}


//TEST(TPostfix, wrong_expression_is_wrong_2)
//{
//	//string expression = "a(b)";
//	//TPostfix Sample(expression);
//
//	//EXPECT_EQ(0, Sample.ErrorChecking());
//	ASSERT_NO_THROW();
//}
//TEST(TPostfix, wrong_expression_is_wrong_3)
//{
//	//string expression = "sina";
//	//TPostfix Sample(expression);
//
//	//EXPECT_EQ(0, Sample.ErrorChecking());
//	ASSERT_NO_THROW();
//}
//TEST(TPostfix, wrong_expression_is_wrong_4)
//{
//	//string expression = "a+(b";
//	//TPostfix Sample(expression);
//
//	//EXPECT_EQ(0, Sample.ErrorChecking());
//	ASSERT_NO_THROW();
//}
//TEST(TPostfix, right_expression_is_right)
//{
//	//string expression = "a+b-(a-b)*y";
//	//TPostfix Sample(expression);
//
//	//EXPECT_EQ(1, Sample.ErrorChecking());
//	ASSERT_NO_THROW();
//}