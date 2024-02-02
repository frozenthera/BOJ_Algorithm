#include <iostream>
#include <algorithm>
#include <vector>

#define INF 987654321
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M;
	vector<pair<int, int>> list;
	int a , b;
	cin >> a >> b;
	while (!(a == 0 && b == 0))
	{
		list.push_back(make_pair(a, b));
		cin >> a >> b;
	}

	sort(list.begin(), list.end());

	int ans = 0, idx = 0, e = 0, s = -50001, ruler = 0;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].second < 0) continue;

		if (list[i].first > s && list[i].first <= e)
		{
			if (ruler <= list[i].second)
				ruler = list[i].second;
			if (list[i].second >= M)
			{
				ans++;
				e = M;
				break;
			}
			continue;
		}
		else
			if (e > ruler)
				break;
		ans++;
		s = e;
		e = ruler;
	}

	if (e == M)
		cout << ans;
	else
		cout << 0;
}