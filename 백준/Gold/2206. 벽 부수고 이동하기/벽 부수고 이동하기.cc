#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> bfs(vector<vector<bool>> map, int _y, int _x)
{
	int y = map.size();
	int x = map[0].size();
	queue<pair<int, int>> q;
	vector<vector<int>> visited(y, vector<int>(x, INF));

	q.push(make_pair(_y, _x));
	visited[_y][_x] = 1;

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (visited[ny][nx] != INF) continue;

			if (map[ny][nx])
			{
				visited[ny][nx] = min(visited[ny][nx], visited[cy][cx] + 1);
			}
			else
			{
				q.push(make_pair(ny, nx));
				visited[ny][nx] = visited[cy][cx] + 1;
			}
			
		}
	}
	return visited;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<bool>> map(N, vector<bool>(M , false));
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '1') map[i][j] = true;
		}
	}

	auto src = bfs(map, 0, 0);
	auto dest = bfs(map, N - 1, M - 1);
	int res = src[N - 1][M - 1];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j])
			{
				res = min(res, src[i][j] + dest[i][j] - 1);
			}
		}
	}

	if (res == INF) cout << -1;
	else cout << res;
}
