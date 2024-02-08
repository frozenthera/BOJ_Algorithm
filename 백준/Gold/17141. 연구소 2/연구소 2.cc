#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;

int N, M;
vector<vector<int>> map;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int simulation(vector<pair<int,int>> virus, vector<vector<int>> map)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	for (auto item : virus)
	{
		map[item.first][item.second] = 0;
		pq.push(make_pair(0, item));
	}

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cy = pq.top().second.first;
		int cx = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1) continue;
			if (map[ny][nx] != -1) continue;

			pq.push(make_pair(- cost - 1, make_pair(ny, nx)));
			map[ny][nx] = cost+1;
		}
	}

	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(map[i][j] != INF) ans = max(ans, map[i][j]);
			if (map[i][j] == -1) return INF;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	//0 = 빈 칸, 1 = 벽, 2 = 바이러스 가능
	vector<pair<int, int>> virus;
	map = vector<vector<int>>(N, vector<int>(N, -1));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 2)
			{
				virus.push_back(make_pair(i, j));
			}
			if (temp == 1) map[i][j] = INF;	
		}
	}

	int ans = INF;
	int sz = virus.size();
	vector<bool> v(M, false);
	v.insert(v.end(), sz - M, true);
	do
	{
		vector<pair<int, int>> temp;
		for (int j = 0; j < sz; j++)
		{
			if (!v[j]) temp.push_back(virus[j]);
		}

		ans = min(ans, simulation(temp, map));

	} while (next_permutation(v.begin(), v.end()));

	cout << (ans == INF ? -1 : ans);
}
