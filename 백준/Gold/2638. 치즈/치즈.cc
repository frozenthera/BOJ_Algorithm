#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

int N, M;
vector<vector<int>> map;

bool isDone()
{
	for (const auto& row : map)
	{
		for (int value : row)
		{
			if (value != 0)
				return false;
		}
	}
	return true;
}


void bfs(int n, int m)
{
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	queue<pair<int, int>> q;
	q.push(make_pair(n, m));
	map[n][m] = 2;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		
		int i = cur.first;
		int j = cur.second;

		for (int k = 0; k < 4; k++)
		{
			int nx = i + dx[k];
			int ny = j + dy[k];
			pair<int, int> c_pair = make_pair(nx, ny);
			if (nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == 0)
			{
				q.push(c_pair);
				map[nx][ny] = 2;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	cin.ignore();
	
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		string str;
		getline(cin, str);
		istringstream ss(str);
		string stringBuffer;

		while (getline(ss, stringBuffer, ' ')) {
			temp.push_back(stoi(stringBuffer));
		}
		map.push_back(temp);
	}

	int day = 0;
	while (!isDone())
	{
		vector<pair<int, int>> list;
		
		bfs(0, 0);

		for (int i = 1; i < N-1; i++)
		{
			for (int j = 1; j < M-1; j++)
			{
				int cnt = 0;
				if (map[i - 1][j] == 2) cnt += 1;
				if (map[i + 1][j] == 2) cnt += 1;
				if (map[i][j - 1] == 2) cnt += 1;
				if (map[i][j + 1] == 2) cnt += 1;
				if (cnt > 1)
				{
					list.push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 2) map[i][j] = 0;
			}
		}

		for (auto it = list.begin(); it != list.end(); it++)
		{
			map[(*it).first][(*it).second] = 0;
		}
		day++;
	}

	cout << day << endl;
}