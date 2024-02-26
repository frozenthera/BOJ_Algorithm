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
	int N, M, a, b;
	cin >> N >> M;
	vector<int> indegree(N, 0);
	vector<vector<int>> graph(N, vector<int>());
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		indegree[b - 1] += 1;
		graph[a - 1].push_back(b - 1);
	}
	queue<int> q;
	for (int i = 0; i< N; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		cout << cur + 1 << " ";

		for (auto item : graph[cur])
		{
			indegree[item] -= 1;
			if (indegree[item] == 0) q.push(item);
		}
	}
}