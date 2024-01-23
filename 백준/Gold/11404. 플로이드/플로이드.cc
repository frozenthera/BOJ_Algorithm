#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(N, INF));
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u-1][v-1] = min(graph[u-1][v-1], w);
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int res = (i==j || graph[i][j] == INF) ? 0 : graph[i][j];
			cout << res << ' ';
		}
		cout << "\n";
	}
}