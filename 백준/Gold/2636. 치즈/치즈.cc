#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#define INF 2e9

using namespace std;

int dy[4] = { 1, -1, 0,0 };
int dx[4] = { 0,0,1, -1 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	int cheese = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) cheese += 1;
		}
	}

	int day = 0;
	while (cheese != 0)
	{
		queue<pair<int, int>> q;
		vector<pair<int, int>> v;
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		q.push(make_pair(0, 0));
		visited[0][0] = true;
		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];
				if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1 || visited[ny][nx]) continue;

				visited[ny][nx] = true;
				if (map[ny][nx] == 1) v.push_back(make_pair(ny, nx));
				else q.push(make_pair(ny, nx));
			}
		}
		if (cheese == v.size())
		{
			day += 1;
			break;
		}
		cheese -= v.size();
		for (auto item : v)
		{
			map[item.first][item.second] = 0;
		}
		day += 1;
	}
	cout << day << "\n" << cheese;
}