#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
vector<vector<pair<int, int>>> graph;
int N;

long long pathfind(int s, int e)
{
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, s));
	vector<long long> visited(N+1, INF);
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
				pq.push(make_pair(-totCost, idx));
			}
		}	
	}
	return visited[e];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int E, A, B;
	cin >> N >> E;
	graph = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));

	}
	cin >> A >> B;

	long long fst = pathfind(1, A) + pathfind(A, B) + pathfind(B, N);
	// cout << pathfind(1, A) << " " << pathfind(A, B) << " " << pathfind(B, N) << endl;
	long long snd = pathfind(1, B) + pathfind(B, A) + pathfind(A, N);
	// cout << pathfind(1, B) << " " << pathfind(B, A) << " " << pathfind(A, N) << endl;
	long long res = min(fst, snd);
	cout << (res >= INF ? -1 : res);
}