#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 987654321

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	vector<bool> res;
	for (int x = 0; x < TC; x++)
	{
		int N, M, W;
		cin >> N >> M >> W;

		vector<vector<int>> graph(N, vector<int>(N, INF));
		
		for (int i = 0; i < N; i++)
		{
			graph[i][i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			graph[u - 1][v - 1] = min(graph[u - 1][v - 1], w);
			graph[v - 1][u - 1] = min(graph[v - 1][u - 1], w);
		}
		for (int i = 0; i < W; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			graph[u - 1][v - 1] = min(graph[u - 1][v - 1], -w);
		}

		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (graph[i][j] > graph[i][k] + graph[k][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}

		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (graph[i][i] < 0)
			{
				flag = true;
			}
		}
		res.push_back(flag);
	}

	for (int i = 0; i < TC; i++)
	{
		cout << (res[i] ? "YES" : "NO") << "\n";
	}
}