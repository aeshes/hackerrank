/*
Given a sequence consisting of parentheses, determine whether the expression is balanced. A sequence of parentheses is balanced if every open parentheses can be paired uniquely with a closed parentheses that occurs after the former. Also, the interval between them must be balanced. You will be given three types of parentheses: (, {, and [.

{[()]} - This is a balanced parentheses.
{[(])} - This is not a balanced parentheses.

*/


#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
 
bool ArePair(char opening, char closing)
{
	if(opening == '(' && closing == ')') 		return true;
	else if(opening == '{' && closing == '}') 	return true;
	else if(opening == '[' && closing == ']')	return true;
	return false;
}
 
bool AreParenthesesBalanced(std::string& exp)
{
	std::stack<char> s;
	for(int i = 0; i < exp.length(); i++)
	{
		if(s.empty())
			s.push(exp[i]);
		else
		{
			if(ArePair(s.top(), exp[i]))
				s.pop();
			else
				s.push(exp[i]);
		}
	}
	return s.empty() ? true : false;
}
 
int main() {
	std::string exp;
	int ntests;
 
 
	std::cin >> ntests;
	for(int i = 0; i < ntests; i++){
		std::cin >> exp;
		std::cout << (AreParenthesesBalanced(exp) ? "YES" : "NO") << std::endl;
	}
	return 0;
}