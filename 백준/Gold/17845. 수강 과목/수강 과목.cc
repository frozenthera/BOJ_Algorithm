#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> data;
	for (int i = 0; i < k; i++)
	{
		int I, T;
		cin >> I >> T;
		data.push_back(make_pair(T, I));
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < k + 1; j++)
		{
			int value = data[j - 1].first;
			int time = data[j - 1].second;

			if (i < value)
			{
				dp[i][j] = dp[i][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - value][j-1] + time);
			}
		}
	}

	cout << dp[n][k];
}
