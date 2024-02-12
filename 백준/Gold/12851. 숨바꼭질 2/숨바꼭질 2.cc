#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#define INF 2e9

using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int step = INF, ans = 0;
	if (N >= K)
	{
		step = N - K;
		ans = 1;
	}
	else
	{
		priority_queue<pair<int, int>> pq;
		pq.push(make_pair(0, N));
		vector<pair<int, int>> visited(100001, make_pair(0, INF));
		visited[N].second = 0;
		visited[N].first = 1;

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int here = pq.top().second;
			pq.pop();

			if (step < cost) continue;

			if (here + 1 == K || here - 1 == K || here * 2 == K)
			{
				if (cost + 1 <= step)
				{
					ans += visited[here].first;
					step = cost + 1;
					continue;
				}
			}

			if (here + 1 <= 1e5)
			{
				//해당 노드를 발견한 스텝에서 다른 가짓수로 방문
				if (cost + 1 == visited[here + 1].second)
				{
					visited[here + 1].first += visited[here].first;
				}
				//해당 노드를 그 스텝에서 처음 발견
				else if (cost + 1 < visited[here + 1].second)
				{
					visited[here + 1].first = visited[here].first;
					visited[here + 1].second = cost + 1;
					pq.push(make_pair(-(cost + 1), here + 1));
				}
			}
			if (here - 1 > -1)
			{
				//해당 노드를 발견한 스텝에서 다른 가짓수로 방문
				if (cost + 1 == visited[here - 1].second)
				{
					visited[here - 1].first += visited[here].first;
				}
				//해당 노드를 그 스텝에서 처음 발견
				else if (cost + 1 < visited[here - 1].second)
				{
					visited[here - 1].first = visited[here].first;
					visited[here - 1].second = cost + 1;
					pq.push(make_pair(-(cost + 1), here - 1));
				}
			}
			if (here * 2 <= 1e5)
			{
				//해당 노드를 발견한 스텝에서 다른 가짓수로 방문
				if (cost + 1 == visited[here * 2].second)
				{
					visited[here * 2].first += visited[here].first;
				}
				//해당 노드를 그 스텝에서 처음 발견
				else if (cost + 1 < visited[here * 2].second)
				{
					visited[here * 2].first = visited[here].first;
					visited[here * 2].second = cost + 1;
					pq.push(make_pair(-(cost + 1), here * 2));
				}
			}
		}
	}

	cout << step << "\n" << ans;
}