#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<vector<int>> map;
int cache[4][4][4][4];

int dp(int sy, int sx, int ey, int ex)
{
	if (cache[sy][sx][ey][ex] != -1) return cache[sy][sx][ey][ex];

	int res = 0;
	if (ey == sy)
	{
		for (int i = 0; i < ex - sx + 1; i++)
		{
			res += pow(10, i) * map[sy][ex - i];
		}
		cache[sy][sx][ey][ex] = res;
	}
	else if (ex == sx)
	{
		for (int i = 0; i < ey - sy + 1; i++)
		{
			res += pow(10, i) * map[ey - i][sx];
		}
		cache[sy][sx][ey][ex] = res;
	}
	else
	{
		cache[sy][sx][ey][ex] =
			max(
				max(dp(sy, sx, ey, sx) + dp(sy, sx + 1, ey, ex),
					dp(sy, ex, ey, ex) + dp(sy, sx, ey, ex - 1)),
				max(dp(sy, sx, sy, ex) + dp(sy + 1, sx, ey, ex),
					dp(ey, sx, ey, ex) + dp(sy, sx, ey - 1, ex)));
	}
	return cache[sy][sx][ey][ex];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					cache[i][j][k][l] = -1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	cout << dp(0, 0, N - 1, M - 1);
}
