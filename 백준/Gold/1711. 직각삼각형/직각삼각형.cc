#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, a, b, ans = 0;
	cin >> n;
	vector<pair<int, int>> dots;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		dots.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = j; k < n; k++)
			{
				if (i == j || j == k || k == i) continue;
				long long v1 = (long long)(dots[j].first - dots[i].first) * (long long)(dots[k].first - dots[i].first);
				long long v2 = (long long)(dots[j].second - dots[i].second) * (long long)(dots[k].second - dots[i].second);
				if (v1 + v2 == 0)
				{
					ans++;
				}
			}
		}
	}

	cout << ans;
}