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
	ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.tie(NULL);

	int R, C;
	cin >> C >> R;
	vector<vector<int>> map(R, vector<int>(C, 0));
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	deque<pair<int, int>> dq;
	vector<vector<bool>> visited(R, vector<bool>(C, false));
	vector<vector<int>> costs(R, vector<int>(C, INF));
	dq.push_back(make_pair(0, 0));
	costs[0][0] = 0;
	visited[0][0] = true;
	while (!dq.empty())
	{
		int cy = dq.front().first;
		int cx = dq.front().second;
		int cost = costs[cy][cx];
		dq.pop_front();

		if (cy == R - 1 && cx == C - 1)
		{
			if (map[cy][cx] == 1) cost += 1;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1 || visited[ny][nx]) continue;

			if (map[ny][nx] == 1)
			{
				costs[ny][nx] = min(costs[ny][nx], cost + 1);
				dq.push_back(make_pair(ny, nx));
			}
			else
			{
				costs[ny][nx] = min(costs[ny][nx], cost);;
				dq.push_front(make_pair(ny, nx));
			}
			visited[ny][nx] = true;
		}
	}
	std::cout << costs[R - 1][C - 1];
}