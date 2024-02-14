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
	ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.tie(NULL);
	int N, K, r, c, L, X;
	char C;
	cin >> N >> K;
	//empty = 0, snake = 1, apple = 2
	vector<vector<int>> map(N, vector<int>(N, 0));
	queue<pair<int, char>> seq;
	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		map[r - 1][c - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		seq.push(make_pair(X, C));
	}
	int dir = 0, sec = 0;
	pair<int, int> vec[4] = { make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0) };

	deque<pair<int, int>> snake;
	snake.push_back(make_pair(0, 0));
	map[0][0] = 1;

	while (true)
	{
		//game simulate
		int ny = snake.front().first + vec[dir].first;
		int nx = snake.front().second + vec[dir].second;

		if (ny < 0 || nx < 0 || ny > N - 1 || nx > N - 1 || map[ny][nx] == 1)
		{
			sec += 1;
			break;
		}
		if (map[ny][nx] == 2)
		{
			map[ny][nx] = 1;
			snake.push_front(make_pair(ny, nx));
		}
		else
		{
			map[ny][nx] = 1;
			snake.push_front(make_pair(ny, nx));
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		sec += 1;

		//check action
		if (seq.empty()) continue;

		int actTime = seq.front().first;
		if (sec != actTime) continue;

		char action = seq.front().second;
		seq.pop();

		if (action == 'L')
		{
			dir = (dir + 3) % 4;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
	std::cout << sec;
}