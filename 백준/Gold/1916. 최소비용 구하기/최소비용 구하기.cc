#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int N, M;
	cin >> N >> M;
	auto graph = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w,v));
	}
	int a, b;
	cin >> a >> b;

	vector<int> visited(N + 1, INF);
	visited[a] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, a));
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > visited[here]) continue;

		for (int i = 0; i < graph[here].size(); i++)
		{
			int totCost = graph[here][i].first + cost;
			int nxt = graph[here][i].second;
			if (totCost < visited[nxt])
			{
				visited[nxt] = totCost;
				pq.push(make_pair(-totCost, nxt));
			}
		}
	}

	cout << visited[b];
}