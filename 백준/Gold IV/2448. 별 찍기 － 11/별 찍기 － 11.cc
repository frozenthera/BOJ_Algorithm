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
vector<string> ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K = 0;
	cin >> N;
	while (3 * pow(2, K) != N) K += 1;
	ans = vector<string>(N, "");
	vector<vector<string>> dp(K + 1, vector<string>(N, ""));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 - i; j++) ans[i] += " ";
	}

	dp[0][0] = "*";
	dp[0][1] = "* *";
	dp[0][2] = "*****";
	
	for (int i = 1; i < K + 1; i++)
	{
		int last = 3 * pow(2, i - 1);
		for (int j = 0; j < last; j++)
		{
			dp[i][j] += dp[i - 1][j];
		}
		for (int j = last; j < N; j++)
		{
			dp[i][j] += dp[i - 1][j - last];
			for (int q = 0; q < dp[i - 1][last - 1].length() - dp[i - 1][j - last].length() + 1; q++) dp[i][j] += " ";
			dp[i][j] += dp[i - 1][j - last];
		}
	}
		
	for (int i = 0; i < N - 1; i++)
	{
		cout << ans[i] + dp[K][i] + ans[i] + "\n";
	}
	cout << ans[N - 1] + dp[K][N - 1] + ans[N - 1];
}