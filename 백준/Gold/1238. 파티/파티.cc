#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;
	vector<vector<int>> graph(N, vector<int>(N, INF));

	for (int i = 0; i < M; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;
		graph[a - 1][b - 1] = t;
	}


	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][k] != INF && graph[k][j] != INF)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	vector<int> dist(N, INF);
	for (int i = 0; i < N; i++)
	{
		dist[i] = graph[X - 1][i] + graph[i][X - 1];
	}
	dist[X - 1] = 0;

	sort(dist.begin(), dist.end());
	cout << dist[N - 1];
}