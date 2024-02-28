#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 1000000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc = 1;
	int n;
	cin >> n;

	int dy[4] = { 1, -1, 0,0 };
	int dx[4] = { 0 ,0 , 1,-1 };

	while (n != 0)
	{
		
		vector<vector<int>> map(n, vector<int>(n));
		vector<vector<int>> dp(n, vector<int>(n, INF));
		priority_queue<pair<int, pair<int, int>>> pq;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		pq.push(make_pair(-map[0][0], make_pair(0, 0)));
		dp[0][0] = map[0][0];

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int cy = pq.top().second.first;
			int cx = pq.top().second.second;
			pq.pop();

			if (cy == n - 1 && cx == n - 1) break;
			
			for (int i = 0; i < 4; i++)
			{
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || nx < 0 || ny > n - 1 || nx > n - 1) continue;

				int ncost = cost + map[ny][nx];
				if (ncost < dp[ny][nx])
				{
					pq.push(make_pair(-ncost, make_pair(ny, nx)));
					dp[ny][nx] = ncost;
				}
			}
		}

		cout << "Problem " << tc << ": " << dp[n - 1][n - 1] << "\n";
		tc += 1;

		cin >> n;
	}
	
}