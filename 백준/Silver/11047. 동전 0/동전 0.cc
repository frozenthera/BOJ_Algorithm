#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	int res = 0;
	for (auto it = v.rbegin(); it != v.rend(); it++)
	{
		if (K <= 0) break;
		res += (int)(K / *it);
		K = K % *it;
	}

	cout << res;
}