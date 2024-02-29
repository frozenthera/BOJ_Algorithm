#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#define INF 2e9

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, temp;
	cin >> N;
	vector<int> v(N), ans;
	vector<bool> included(N, false);
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v[i] = temp - 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (included[i]) continue;
		vector<bool> visited(N, false);
		int cur = i;
		while (!visited[cur])
		{
			visited[cur] = true;
			cur = v[cur];
		}

		if (cur == i)
		{
			for(int i = 0; i <N; i++)
			{
				if (!visited[i]) continue;
				ans.push_back(i);
				included[i] = true;
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto item : ans) cout << item + 1 << "\n";
}