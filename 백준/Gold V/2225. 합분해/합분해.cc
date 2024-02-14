#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 2e9
#define MOD 1000000000
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i < K + 1; i++) dp[0][i] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < K + 1; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[N][K];
}