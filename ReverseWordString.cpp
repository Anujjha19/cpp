/* #include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s = "my name is akash";
    int start = 0;
    int p = 0;
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[p] == ' ' || s[p] == '\0')
        {
            int end = p - 1;
            while (start <= end)
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            start=p+1;
        }
        p++;
    }
    cout<<s;
} */
// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words*/
void reverseWords(string s)
{
	
	// temporary vector to store all words
	vector<string> tmp;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		
		// Check if we encounter space
		// push word(str) to vector
		// and make str NULL
		if (s[i] == ' ')
		{
			tmp.push_back(str);
			str = "";
		}

		// Else add character to
		// str to form current word
		else
			str += s[i];
	}

	// Last word remaining,add it to vector
	tmp.push_back(str);

	// Now print from last to first in vector
	int i;
	for (i = tmp.size() - 1; i > 0; i--)
		cout << tmp[i] << " ";
	// Last word remaining,print it
	//cout << tmp[0] << endl;
}

// Driver Code
int main()
{
	string s = " Anuj   123  Jha";
	reverseWords(s);
	return 0;
}
