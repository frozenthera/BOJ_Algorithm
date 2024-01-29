#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	pair<int, int> st;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'I') st = make_pair(i, j);
			if (str[j] == 'X')
			{
				graph[i][j] = -1;
			}
			if (str[j] == 'P')
			{
				graph[i][j] = 1;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(st);

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	int res = 0;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		graph[cx][cy] = 2;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || graph[nx][ny] == -1 || graph[nx][ny] == 2) continue;

			if (graph[nx][ny] == 1)
			{
				res += 1;
			}

			q.push(make_pair(nx, ny));
			graph[nx][ny] = 2;
		}
	}

	if (res == 0) cout << "TT" << endl;
	else cout << res << endl;
}

