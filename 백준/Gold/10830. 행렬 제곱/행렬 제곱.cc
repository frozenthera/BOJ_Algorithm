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

vector<vector<int>> v;
int N;

vector<vector<int>> mul(vector<vector<int>> mat, bool square)
{
	vector<vector<int>> res(N, vector<int>(N, 0));
	vector<vector<int>> target = (square ? mat : v);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				res[i][j] += (mat[i][k] * target[k][j]) % 1000;
			}
			res[i][j] %= 1000;
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long B;
	cin >> N >> B;
	v = vector<vector<int>>(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
		}
	}

	long long cur = B;
	vector<bool> list;
	while (cur != 1)
	{
		if (cur % 2 == 0)
		{
			list.push_back(true);
			cur /= 2;
		}
		else
		{
			list.push_back(false);
			cur -= 1;
		}
	}

	vector<vector<int>> ans;
	ans = v;
	for (int i = list.size() - 1; i > -1; i--)
	{
		ans = mul(ans, list[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << (ans[i][j] % 1000) << " ";
		}
		cout << "\n";
	}
}