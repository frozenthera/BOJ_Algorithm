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
	int N, node, del, root, ans = 0;
	cin >> N;
	vector<vector<int>> tree(N);
	for (int i = 0; i < N; i++)
	{
		cin >> node;
		if (node == -1)
		{
			root = i;  
		}
		else
		{
			tree[node].push_back(i);
		}
	}
	cin >> del;
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == del) continue;
		if (tree[cur].size() == 0 || (tree[cur].size() == 1 && tree[cur][0] == del))
		{
			ans += 1;
			continue;
		}

		for (auto item : tree[cur])
		{
			q.push(item);
		}
	}
	cout << ans;
}