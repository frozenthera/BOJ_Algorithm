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

	string str;
	cin >> str;

	vector<int> v(10, 0);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '6' || str[i] == '9') v[6] += 1;
		else v[str[i] - '0'] += 1;
	}
	int m = -1;
	v[6] = (v[6] + 1) / 2;
	for (auto item : v)
	{
		m = max(m, item);
	}
	cout << m;
}