#include <iostream>
#include <stack>
#include <string>
using namespace std;
void valid_paren(string input)
{
    // Declaraing a stack.
    stack<char> s;
    int length = input.length();
    char top;
    // Iterating over the entire string.
    for (int i = 0; i < length; i++)
    {
        //  If the input string contains an opening parenthesis,
        //  push in on to the stack.
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            s.push(input[i]);
        }
        else
        { // In the case of valid parentheses, the stack cannot be
          // be empty if a closing parenthesis is encountered.
            if (s.empty())
            {
                cout << input << " contains invalid parentheses." << endl;
                return;
            }
            else
            {
                top = s.top();
                // If the input string contains a closing bracket,
                // then pop the corresponding opening parenthesis if
                // present.
                if (input[i] == ')' && top == '(' ||
                    input[i] == '}' && top == '{' ||
                    input[i] == ']' && top == '[')
                {
                    s.pop();
                }
                else
                {
                    // The opening and closing parentheses are of
                    // different types. This implies an invaled sequence
                    cout << input << " contains invalid parentheses." << endl;
                    return;
                }
            }
        }
    }
    //  Checking the status of the stack to determine the
    //  validity of the string.
    if (s.empty())
    {
        cout << input << " contains valid parentheses." << endl;
    }
    else
    {
        cout << input << " contains invalid parentheses." << endl;
    }
}
int main()
{
    string input1 = "{{}}()[()]";
    string input2 = "{][}";
    string input3 = ")";
    valid_paren(input1);
    valid_paren(input2);
    valid_paren(input3);
    return 0;
}
/* 
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                brackets.push(s[i]);
            }
            else
            {
                if (!brackets.empty())
                {
                    char temp = brackets.top();
                    if ((temp == '(' && s[i] == ')') || (temp == '{' && s[i] == '}') || (temp == '[' && s[i] == ']'))
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (!brackets.empty())
        {
            return false;
        }
        return true;
    }
};
 */
/*


T.C = O(n)
S.C = O(n)

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {

        char ch = expression[i];

        // if opening bracket, stack push
        // if close bracket, stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
        return true;
    else
        return false;
} */
/*
class Solution {
public:
bool isValid(string s) {

    if(s.size() == 1)
        return false;

    stack<char> stack;

    int i=0;
    while(i < s.size()){
        if(s[i] == '(' ||
           s[i] == '{' ||
           s[i] == '['   ){

            stack.push(s[i]);
            i++;
        }
        else {

            if(s[i] == ')'){

                if(!stack.empty() && stack.top() == '('){
                    stack.pop();
                    i++;}

                else return false;

            }
            if(s[i] == ']'){

                if(!stack.empty() && stack.top() == '[' ){
                    stack.pop();
                    i++;}

                else return false;

            }
            if(s[i] == '}'){

                if(!stack.empty() && stack.top() == '{'){
                    stack.pop();
                    i++;}

                else return false;
            }
        }
    }
    if(stack.empty())
        return true;
    else return false;
}
};

 */
