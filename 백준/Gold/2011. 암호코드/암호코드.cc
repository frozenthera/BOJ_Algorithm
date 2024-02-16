#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 2e9
#define MOD 1000000
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int N = str.size();
	vector<int> dp(N + 1, 0);
	if (str[N - 1] != '0') dp[N - 1] = 1;
	dp[N] = 1;
	for (int i = N - 2; i > -1; i--)
	{
		if(str[i] != '0') dp[i] = dp[i + 1];
		int val = (str[i] - '0') * 10 + (str[i + 1] - '0');
		if (val > 0 && val < 27 && str[i] - '0' != 0) dp[i] = (dp[i] + dp[i + 2]) % MOD;
	}
	cout << dp[0];
}