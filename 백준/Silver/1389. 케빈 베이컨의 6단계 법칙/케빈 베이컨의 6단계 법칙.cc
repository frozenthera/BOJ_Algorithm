#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(N, INF));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int res = 987654321;
	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			temp += graph[i][j];
		}

		if (res > temp)
		{
			ans = i;
			res = temp;
		}
	}

	cout << ans + 1;
}