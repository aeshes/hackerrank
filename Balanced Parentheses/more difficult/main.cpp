#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <algorithm>


bool ArePaired(const char left, const char right)
{
	if ((left == '(' && right == ')')
		|| (left == '[' && right == ']')
		|| (left == '{' && right == '}'))
		return true;
	return false;
}

typedef std::pair<char, int> entry_t;
typedef std::stack<entry_t>  stack_t;

void UpdateStack(stack_t & update, const char bracket, int n)
{
	if (!update.empty() && ArePaired(update.top().first, bracket))
		update.pop();
	else update.push({ bracket, n });
}

std::string Result(stack_t & st)
{
	if (st.empty())
		return std::string("Success");

	return std::to_string(st.top().second);
}

std::string
AreParenthesesBalanced(const std::string &str)
{
	stack_t st;

	int n = 1;
	for (const char bracket : str)
	{
		UpdateStack(st, bracket, n);
		++n;
	}

	return Result(st);
}

void check(const std::string &sample, const std::string &result, const int test)
{
	if (AreParenthesesBalanced(sample) == result)
		std::cout << "Test " << test << " OK\n";
	else
		std::cout << "Test " << test << " Failed\n";
}

void test()
{
	const std::string sample1("([](){([])})");
	const std::string sample2("()[]}");
	const std::string sample3("{{[()]]");

	check(sample1, std::string("Success"), 1);
	check(sample2, std::string("5"), 2);
	check(sample3, std::string("7"), 3);
}

int main()
{
	test();
	return 0;
}