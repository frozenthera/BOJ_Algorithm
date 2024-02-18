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
	int tc;
	cin >> tc;
	for (int T = 0; T < tc; T++)
	{
		int N, K, V;
		cin >> N >> K;
		vector<int> cost(N, 0);
		vector<vector<int>> graph(N);
		vector<vector<int>> parent(N);
		vector<int> indegree(N, 0);
		vector<int> ans(N, -1);
		for (int i = 0; i < N; i++)
		{
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			parent[b - 1].push_back(a - 1);
			indegree[b - 1] += 1;
		}
		cin >> V;
		V -= 1;
		
		vector<int> v;
		queue<int> q;
		for (int i = 0; i < N; i++)
		{
			if (indegree[i] == 0)
			{
				ans[i] = cost[i];
				q.push(i);
			}
		}

		for (int i = 0; i < N; i++)
		{
			int cur = q.front();
			v.push_back(cur);
			q.pop();

			for (auto item : graph[cur])
			{
				indegree[item] -= 1;
				if (indegree[item] == 0) q.push(item);
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (ans[v[i]] != -1) continue;
			int m = -1;
			for (int j = 0; j < parent[v[i]].size(); j++)
			{
				m = max(m, ans[parent[v[i]][j]]);
			}
			ans[v[i]] = m + cost[v[i]];
		}
		cout << ans[V] << "\n";
	}
}