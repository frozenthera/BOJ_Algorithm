#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int> plus;
	priority_queue<int> minus;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			int res = 0;
			if (!plus.empty() && !minus.empty())
			{
				int p = -plus.top();
				int m = -minus.top();
				if (p < m)
				{
					res = p;
					plus.pop();
				}
				else
				{
					res = -m;
					minus.pop();
				}
			}
			else if (!plus.empty() && minus.empty())
			{
				res = -plus.top();
				plus.pop();
			}
			else if (plus.empty() && !minus.empty())
			{
				res = minus.top();
				minus.pop();
			}
			cout << res << "\n";
		}
		else
		{
			if (input < 0) minus.push(input);
			else plus.push(-input);
		}
	}
}
