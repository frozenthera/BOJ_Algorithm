#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, res = -1;
	cin >> a >> b;
	priority_queue<pair<int, long long>> pq;
	vector<bool> visited(1e9 + 1, false);

	pq.push(make_pair(0, a));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		long long cur = pq.top().second;
		pq.pop();

		if (cur == b)
		{
			res = cost;
			break;
		}
		if (cur > b || visited[cur])
		{
			continue;
		}

		visited[cur] = true;
		pq.push(make_pair(cost + 1, cur * 2));
		pq.push(make_pair(cost + 1, cur * 10 + 1));
	}
	cout << (res == -1 ? -1 : res + 1);
}