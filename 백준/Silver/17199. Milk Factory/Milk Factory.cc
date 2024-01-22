#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<vector<bool>> graph(N, vector<bool>(N, false));
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][k] && graph[k][j])
				{
					graph[i][j] = true;
				}
			}
		}
	}

	int res = -2;
	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		for (int j = 0; j < N; j++)
		{
			if (j == i) continue;
			flag = flag && graph[j][i];
		}

		if (flag)
		{
			res = i;
			break;
		}
	}

	cout << res+1 << endl;
}