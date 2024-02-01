#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
vector<vector<pair<int, int>>> graph;
int N;

pair<vector<int>, long long> pathfind(int s, int e)
{
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, s));
	vector<long long> visited(N + 1, INF);
	vector<int> parent(N + 1, -1);
	visited[s] = 0;
	while (!pq.empty())
	{
		long long cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (cost > visited[here]) continue;

		for (int i = 0; i < graph[here].size(); i++)
		{
			long long totCost = cost + graph[here][i].first;
			int idx = graph[here][i].second;
			if (totCost < visited[idx])
			{
				visited[idx] = totCost;
				parent[idx] = here;
				pq.push(make_pair(-totCost, idx));
			}
		}
	}

	vector<int> path;
	int cur = e;
	while (cur != -1)
	{
		path.push_back(cur);
		cur = parent[cur];
	}
	reverse(path.begin(), path.end());
	return make_pair(path, visited[e]);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, A, B;
	cin >> N >> M;
	graph = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
	}
	cin >> A >> B;

	auto res = pathfind(A, B);
	cout << res.second << "\n" << res.first.size() << "\n";
	for (auto item : res.first)
	{
		cout << item << " ";
	}
}