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
	long long N;
	cin >> N;
	N %= 1500000;
	long long dp[3]{0, 1, 1};
	for (long long i = 1; i < N; i++)
	{
		dp[2] = (dp[0] + dp[1]) % 1000000;
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	cout << dp[1];
}