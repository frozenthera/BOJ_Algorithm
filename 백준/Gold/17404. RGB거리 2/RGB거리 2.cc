#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

vector<vector<int>> cost;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	cost = vector<vector<int>>(N, vector<int>(3, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	int ans = INF;
	auto dp = vector<vector<int>>(N, vector<int>(3, -1));
	for (int i = 0; i < 3; i++)
	{
		dp[0][0] = INF;
		dp[0][1] = INF;
		dp[0][2] = INF;
		dp[0][i] = cost[0][i];
		for (int j = 1; j < N; j++)
		{
			dp[j][0] = min(dp[j - 1][1] + cost[j][0], dp[j - 1][2] + cost[j][0]);
			dp[j][1] = min(dp[j - 1][0] + cost[j][1], dp[j - 1][2] + cost[j][1]);
			dp[j][2] = min(dp[j - 1][0] + cost[j][2], dp[j - 1][1] + cost[j][2]);
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			ans = min(ans, dp[N-1][j]);
		}
	}
	cout << ans;
}