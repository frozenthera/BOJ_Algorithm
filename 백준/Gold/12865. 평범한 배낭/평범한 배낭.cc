#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>> list;
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int w, v;
		cin >> w >> v;
		list.push_back(make_pair(w, v));
	}

	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < K + 1; j++)
		{
			int weight = list[i - 1].first;
			int value = list[i - 1].second;
			if (weight > j)
			{
				dp[j][i] = dp[j][i - 1];
			}
			else
			{
				dp[j][i] = max(dp[j][i - 1], value + dp[j - weight][i - 1]);
			}
		}
	}
	cout << dp[K][N];
}