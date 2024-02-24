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

int Rrot(int n)
{
	int res = n;
	int temp = n % 10;
	res /= 10;
	res += temp * 1000;
	return res;
}

int Lrot(int n)
{
	int res = n;
	int temp = n / 1000;
	res *= 10;
	res %= 10000;
	res += temp;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc, src, dest;
	cin >> tc;
	for (int T = 0; T < tc; T++)
	{
		cin >> src >> dest;
		vector<bool> visited(10001, false);
		queue<pair<int, string>> q;
		q.push(make_pair(src, ""));
		visited[src] = true;
		while (!q.empty())
		{
			int cur = q.front().first;
			string path = q.front().second;
			q.pop();

			if (cur == dest)
			{
				cout << path << endl; 
				break;
			}

			int next = (cur * 2) % 10000;
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, path + "D"));
			}
			next = (cur + 9999) % 10000;
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, path + "S"));
			}
			next = Lrot(cur);
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, path + "L"));
			}
			next = Rrot(cur);
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, path + "R"));
			}
		}
	}
}