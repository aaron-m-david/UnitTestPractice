/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, multi_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAb");
	ASSERT_EQ(4, actual);
}
TEST(PasswordTest, single_and_upper_case)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAab");
	ASSERT_EQ(4, actual);
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, has_upper_and_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Ab");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, has_lower_no_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ab");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, has_upper_no_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AB");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, mixed_case_handed_empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, mixed_case_handed_string_of_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234567");
	ASSERT_EQ(0, actual);
}
TEST(PasswordTest, mixed_case_handed_whitespace)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("\t   \n");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, mixed_case_long_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("12321442141ds13221211212\n\n    \t \t \t //////DDbze");
	ASSERT_EQ(1, actual);
}
