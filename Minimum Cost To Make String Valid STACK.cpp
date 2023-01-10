/*
Minimum Bracket Reversal
*/
#include <stack>
int findMinimumCost(string str)
{

    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // Stack contain invalid expression now
    // b- count of open brace
    // a- count of close brace
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

/*
    invalis string -
    1. all open braces
    2. all close braces
    3. starting braces close then open braces
    rest all valid

    algo :-

    if str length is odd return -1

    every close braces have open braces before it
    in i/p string remove valid part then if the remaining part above 3 types of one\

    count banao of open nd close braces
    a - close braces
    b - open braces

    1.
    [ all open braces] - count even or count odd , reject odd case
    {{{{ =4
    { } { } =2 = 4/2 (b/2)

    2.
    [ all open braces ] - count even or count odd , odd one get rejected
    }}}} =4
    { } { } =2 = 4/2 (a/2)

    3.
    [ starting braces close then open braces ] - close,odd braces
    odd odd , even odd , odd even , odd odd ,  ( odd even && even odd cannot exist)

    odd odd wala = {{{  }}} - 3 , 3
        { } { } { } = 4


    even even wala  = }}}} {{{{  - 4 , 4
        { } { }  { } { } = 4

**  Required ans is coming through
**  2 in upper cases and 4 in lower cases
**  the  ans coming through    -----   { ( a + 1) / 2 +  ( b + 1) / 2  }


 */