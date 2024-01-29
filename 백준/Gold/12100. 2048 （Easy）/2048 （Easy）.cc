#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> left_merge(vector<vector<int>> map)
{
	int N = map.size();
	auto res = map;
	for (int i = 0; i < N; i++)
	{
		int idx = 0;
		for (int j = 0; j < N; j++)
		{
			if (res[i][j] == 0 || idx == j) continue;

			if (res[i][idx] == res[i][j])
			{
				res[i][idx] *= 2;
				res[i][j] = 0;
				idx += 1;
			}
			else
			{
				if (res[i][idx] == 0)
				{
					res[i][idx] = res[i][j];
					res[i][j] = 0;
					continue;
				}
				idx += 1;
				if (idx == j) continue;
				res[i][idx] = res[i][j];
				res[i][j] = 0;
			}
		}
	}
	return res;
}

vector<vector<int>> rotate(vector<vector<int>> map)
{
	int N = map.size();
	auto res = map;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res[j][N - 1 - i] = map[i][j];
		}
	}
	return res;
}

int simulate(vector<vector<int>> map, int limit)
{
	int N = map.size();
	if (limit == 5)
	{
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > res)
				{
					res = map[i][j];
				}
			}
		}
		return res;
	}

	auto first = simulate(left_merge(map), limit + 1);
	auto second = simulate(rotate(rotate(rotate(left_merge(rotate(map))))), limit + 1);
	auto third = simulate(rotate(rotate(left_merge(rotate(rotate(map))))), limit + 1);
	auto fourth = simulate(rotate(left_merge(rotate(rotate(rotate(map))))), limit + 1);
	
	auto ret = first;
	if (ret < second)
	{
		ret = second;
	}
	if (ret < third)
	{
		ret = third;
	}
	if (ret < fourth)
	{
		ret = fourth;
	}
	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	
	auto ret = simulate(map, 0);
	cout << ret << endl;
}