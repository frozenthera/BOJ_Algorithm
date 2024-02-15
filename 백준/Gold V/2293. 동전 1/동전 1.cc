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

	int N, K;
	cin >> N >> K;
	vector<int> coin(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i + 1];
	}
	sort(coin.begin(), coin.end());
	
	vector<vector<int>> dp(2, vector<int>(K + 1, 0));
	dp[0][0] = 1;
	dp[1][0] = 1;

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < K + 1; j++)
		{
			dp[1][j] = dp[0][j];
			if (j >= coin[i]) dp[1][j] += dp[1][j - coin[i]];
		}
		dp[0] = dp[1];
	}
	cout << dp[0][K];
}