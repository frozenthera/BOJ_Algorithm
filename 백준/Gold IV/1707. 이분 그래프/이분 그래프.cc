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

	int tc;
	cin >> tc;
	for (int k = 0; k < tc; k++)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int>> graph(V + 1);
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> tag(V + 1, -1);
		queue<int> q;
		bool flag = false;
		for (int j = 1; j < V + 1; j++)
		{
			if (tag[j] != -1) continue;
			q.push(j);
			tag[j] = 0;
			while (!q.empty() && !flag)
			{
				int cur = q.front();
				q.pop();

				for (int i = 0; i < graph[cur].size(); i++)
				{
					int nxt = graph[cur][i];
					if (tag[nxt] == tag[cur])
					{
						flag = true;
						break;
					}
					else if (tag[nxt] == -1)
					{
						tag[nxt] = 1 - tag[cur];
						q.push(nxt);
					}
				}
			}
		}
		cout << (flag ? "NO\n" : "YES\n");
	}
}