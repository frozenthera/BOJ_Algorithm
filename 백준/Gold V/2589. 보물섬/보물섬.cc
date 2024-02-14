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

int dy[4] = { 1, -1 ,0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int R, C;
	cin >> R >> C;
	vector<vector<bool>> map(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			if (str[j] == 'L') map[i][j] = true;
		}
	}

	vector<pair<int, int>> v;
	int minCnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!map[i][j]) continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 0 || ny > R - 1 || nx < 0 || nx > C - 1) cnt += 1;
				else if (!map[ny][nx]) cnt += 1;
			}

			if (minCnt < cnt && cnt != 4)
			{
				v = vector<pair<int, int>>();
				v.push_back(make_pair(i, j));
				minCnt = cnt;
			}
			else if (minCnt == cnt && cnt != 4)
			{
				v.push_back(make_pair(i, j));
				minCnt = cnt;
			}
		}
	}

	int longest = 0;
	queue<pair<int, pair<int, int>>> q;
	for (auto item : v)
	{
		vector<vector<bool>> visited(R, vector<bool>(C, false));

		q.push(make_pair(0, make_pair(item.first, item.second)));
		visited[item.first][item.second] = true;

		int cost = 0;
		while (!q.empty())
		{
			cost = -q.front().first;
			int cy = q.front().second.first;
			int cx = q.front().second.second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int ny = cy + dy[k];
				int nx = cx + dx[k];

				if (ny < 0 || ny > R - 1 || nx < 0 || nx > C - 1 || visited[ny][nx] || !map[ny][nx]) continue;

				q.push(make_pair(-(cost + 1), make_pair(ny, nx)));
				visited[ny][nx] = true;
			}
		}
		longest = max(longest, cost);
	}
	cout << longest;
}