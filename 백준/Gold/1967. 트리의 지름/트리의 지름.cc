#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> diameter;
vector<int> height;
vector<vector<pair<int, int>>> tree;

int calc_height(int node)
{
	if (height[node] == -1)
	{
		int res = 0;
		for (int i = 0; i < tree[node].size(); i++)
		{
			res = max(res, calc_height(tree[node][i].second) + tree[node][i].first);
		}
		height[node] = res;
	}
	return height[node];
}

int calc_diameter(int node)
{
	if (diameter[node] == -1)
	{
		int res = 0;
		vector<int> heights;
		for (int i = 0; i < tree[node].size(); i++)
		{
			res = max(res, calc_diameter(tree[node][i].second));
			heights.push_back(calc_height(tree[node][i].second) + tree[node][i].first);
		}

		if(heights.size() == 1)
		{
			res = max(res, heights[0]);
		}
		else if (heights.size() > 1)
		{
			sort(heights.begin(), heights.end());
			res = max(res, heights[heights.size() - 1] + heights[heights.size() - 2]);
		}

		diameter[node] = res;
	}
	return diameter[node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	tree = vector<vector<pair<int, int>>>(N+1);
	diameter = vector<int>(N+1, -1);
	height = vector<int>(N+1, -1);

	for (int i = 0; i < N - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back(make_pair(w, v));
	}
	
	diameter[1] = calc_diameter(1);
	sort(diameter.begin(), diameter.end());
	cout << diameter[N];
}