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

	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) graph[i][i] = 1;
	
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][k] == 1 && graph[k][j] == 1) graph[i][j] = 1;
			}
		}
	}

	bool ans = true;
	int last, cur;
	cin >> last;
	for (int i = 1; i < M; i++)
	{
		cin >> cur;
		if (graph[last - 1][cur - 1] == 0)
		{
			ans = false;
			break;
		}
		last = cur;
	}
	cout << (ans ? "YES" : "NO");
}