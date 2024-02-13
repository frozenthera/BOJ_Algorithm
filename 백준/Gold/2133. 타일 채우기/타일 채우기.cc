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
	int N;
	cin >> N;
	int ans = 0;
	vector<int> dp(31, 0);
	if (N % 2 != 0)
	{
		ans = 0;
	}
	else
	{
		dp[0] = 1;
		dp[2] = 3;
		for (int i = 4; i < N + 1; i += 2)
		{
			dp[i] += dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j -= 2)
			{
				dp[i] += dp[j] * 2;
			}
		}
		ans = dp[N];
	}
	cout << ans;
}