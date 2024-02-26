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

vector<long long> dp;

long long getSum(long long n)
{
	long long sum = 0;
	long long cur = n + 1;
	int c = 0;

	while (true)
	{
		if (cur == 0) break;
		int idx = 0;
		
		long long a = cur;
		long long k = 1;
		while (a != 1)
		{
			k <<= 1;
			a >>= 1;
			idx += 1;
		}
		sum += dp[idx] + k * c;
		cur -= k;
		c += 1;
	}
		
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long a, b;
	cin >> a >> b;

	int n = 0;
	while (pow(2, n) <= (b + 1)) n += 1;
	dp = vector<long long>(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		dp[i] = 2 * dp[i - 1] + pow(2, i-1);
	}
	
	cout << getSum(b) - getSum(a - 1);
}