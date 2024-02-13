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

	int R, C;	
	cin >> R >> C;
	// 0 = house, 1 = beaver, 2 = water, 3 = stone, 4 = empty
	vector<vector<int>> map(R, vector<int>(C, 0));
	vector<vector<bool>> beaverVisited(R, vector<bool>(C, false));
	vector<vector<bool>> waterVisited(R, vector<bool>(C, false));
	int waterCnt = 0, stoneCnt = 0;
	int dy[4] = { 1, -1, 0,0 };
	int dx[4] = { 0, 0, 1,-1 };
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			switch (str[j])
			{
			case 'D':
				map[i][j] = 0;
				break;
			case 'S':
				map[i][j] = 1;
				break;
			case '*':
				waterCnt += 1;
				map[i][j] = 2;
				break;
			case 'X':
				stoneCnt += 1;
				map[i][j] = 3;
				break;
			case '.':
				map[i][j] = 4;
				break;
			default:
				map[i][j] = 4;
			}
		}
	}

	int day = 1;
	queue<pair<int, int>> q;
	while (waterCnt + stoneCnt + 1 != R * C)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == 1 && !beaverVisited[i][j])
				{
					q.push(make_pair(i, j));
					beaverVisited[i][j] = true;
				}
			}
		}

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1) continue;
				if (map[ny][nx] == 0) goto EXIT;
				if (beaverVisited[ny][nx] || map[ny][nx] != 4) continue;

				map[ny][nx] = 1;
				
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == 2 && !waterVisited[i][j])
				{
					waterCnt += 1;
					q.push(make_pair(i, j));
					waterVisited[i][j] = true;
				}
			}
		}

		while (!q.empty())
		{
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || nx < 0 || ny > R - 1 || nx > C - 1) continue;
				if (waterVisited[ny][nx] || map[ny][nx] == 0 || map[ny][nx] == 3) continue;

				map[ny][nx] = 2;
			}
		}
		day += 1;
	}

	cout << "KAKTUS";
	return 0;

EXIT :
	cout << day;
	return 0;
}