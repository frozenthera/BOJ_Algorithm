#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	int INF = 987654321;
	cin >> V >> E >> K;

	vector<vector<pair<int, int>>> graph(V+1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}

	vector<int> shortest(V+1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, K));
	shortest[K] = 0;
	
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (shortest[here] < cost) continue;
		for (int i = 0; i < graph[here].size(); i++)
		{
			int totCost = graph[here][i].first + cost;
			int idx = graph[here][i].second;
			if (totCost < shortest[idx])
			{
				shortest[idx] = totCost;
				pq.push(make_pair(-totCost, idx));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (shortest[i] == INF) cout << "INF" << "\n";
		else cout << shortest[i] << "\n";
	}
}