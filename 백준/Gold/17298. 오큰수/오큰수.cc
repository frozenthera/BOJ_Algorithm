#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 2e9

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> ans(N, -1);
	stack<int> st;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int NGE = -1;
	int maxIdx = N - 1;
	for (int i = N - 1; i > -1; i--)
	{
		if (st.empty())
		{
			ans[i] = -1;
			st.push(v[i]);
			continue;
		}
		while (!st.empty() && st.top() <= v[i])
		{
			st.pop();
		}
		if (st.empty())
		{
			ans[i] = -1;
			st.push(v[i]);
		}
		else
		{
			ans[i] = st.top();
			st.push(v[i]);
		}
	}

	for (auto item : ans)
	{
		cout << item << " ";
	}
}
