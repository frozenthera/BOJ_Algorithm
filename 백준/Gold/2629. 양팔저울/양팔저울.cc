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
	int N, M, W;
	cin >> N;
	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++) cin >> v[i];
	vector<vector<bool>> dp(40001, vector<bool>(N + 1, false));
	for (int i = 0; i < N + 1; i++) dp[0][i] = true;

	for (int j = 1; j < N + 1; j++)
	{
		for (int i = 1; i < 40001; i++)
		{
			dp[i][j] = dp[i][j - 1] || dp[abs(i - v[j])][j - 1] || (i + v[j] < 40001 ? dp[i + v[j]][j - 1] : false);
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> W;
		cout << (dp[W][N] ? "Y" : "N") << " ";
	}
}