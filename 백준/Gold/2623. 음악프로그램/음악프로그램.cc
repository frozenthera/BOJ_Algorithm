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
	int N, M;
	cin >> N >> M;
	vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));
	vector<int> indegree(N + 1, 0);
	vector<bool> checked(N + 1, false);
	int temp, cur, last;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		last = -1;
		for (int j = 0; j < temp; j++)
		{	
			cin >> cur;
			if (last != -1 && !graph[last][cur])
			{
				graph[last][cur] = true;
				indegree[cur] += 1;
			}
			last = cur;
		}
	}

	queue<int> q;
	for (int i = 1; i <=  N; i++)
	{
		if (indegree[i] == 0)
		{
			checked[i] = true;
			q.push(i);
		}
	}

	vector<int> ans;
	for (int i = 1; i <= N; i++)
	{
		if (q.empty())
		{
			break;
		}
		
		int x = q.front();
		q.pop();

		ans.push_back(x);
		for (int j = 1; j <= N; j++)
		{
			if (graph[x][j]) indegree[j] -= 1;
			if (indegree[j] == 0 && !checked[j])
			{
				checked[j] = true;
				q.push(j);
			}
		}
	}

	if (ans.size() != N) cout << 0;
	else for (auto item : ans) cout << item << "\n";
}