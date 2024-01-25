#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	int res = 100002;
	if (K < N)
	{
		res = N - K;
	}
	else
	{
		priority_queue<pair<int, int>> pq;
		vector<bool> visited(1000001, false);
		pq.push(make_pair(0, N));
		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = -pq.top().first;
			pq.pop();

			visited[cur] = true;
			if (cur > K)
			{
				if (cur - 1 > -1 && !visited[cur - 1]) pq.push(make_pair(-(cost + 1), cur - 1));
				continue;
			}
			if (cur > 2 * K) continue;
			if (cur == K)
			{
				res = cost;
				break;
			}

			if(cur * 2 < 100001 && !visited[cur * 2]) pq.push(make_pair(-cost, cur * 2));
			if (cur + 1 < 100001 && !visited[cur + 1]) pq.push(make_pair(-(cost + 1), cur + 1)); 
			if (cur - 1 > -1 && !visited[cur - 1]) pq.push(make_pair(-(cost + 1), cur - 1));
		}
	}
	
	cout << res;
}