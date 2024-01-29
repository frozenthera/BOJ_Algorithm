#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	stack<char> st;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cout << str[i];
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!st.empty() && st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}