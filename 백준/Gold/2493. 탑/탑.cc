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
	vector<int> ans(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	//height, idx
	stack<pair<int, int>> st;
	for (int i = 0; i < N; i++)
	{
		while (!st.empty() && st.top().first <= v[i])
		{
			st.pop();
		}
		if (st.empty())
		{
			ans[i] = 0;
		}
		else
		{
			ans[i] = st.top().second;
		}
		st.push(make_pair(v[i], i+1));
	}

	for (auto item : ans)
	{
		cout << item << " ";
	}
}