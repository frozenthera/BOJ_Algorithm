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

	int N, M, x, y;
	cin >> N >> M;
	vector<int> v(101, 0);
	vector<int> dp(101, 101);
	for (int i = 0; i < N + M; i++)
	{
		cin >> x >> y;
		v[x] = y;
	}
	queue<pair<int, int>> q;
	vector<bool> visited(101, false);

	q.push(make_pair(0, 1));
	visited[1] = true;
	while (!q.empty())
	{
		int cost = q.front().first;
		int cur = q.front().second;
		q.pop();

		if (cur > 100) continue;
		if (cur == 100)
		{
			cout << cost;
			break;
		}

		for (int i = 1; i < 7; i++)
		{
			int nxt = cur + i;
			if (nxt > 100 || visited[nxt]) continue;
			visited[nxt] = true;
			if (v[nxt] != 0) nxt = v[nxt];
			visited[nxt] = true;
			q.push(make_pair(cost + 1, nxt));
		}
	}
}