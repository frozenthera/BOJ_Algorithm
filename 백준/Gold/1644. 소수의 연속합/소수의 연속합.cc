#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#define INF 2e9

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<bool> isPrime(N + 1, true);
	vector<int> v;
	vector<long long> sum;
	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
		{
			v.push_back(i);
			for (int j = i * 2; j <= N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	sum.push_back(0);
	for (int i = 0; i < v.size(); i++)
	{
		sum.push_back(sum[i] + v[i]);
	}

	int s = 0, e = 1, ans = 0;
	while (e < sum.size())
	{
		// cout << s << " " << e << " " << sum[e] - sum[s] << endl;
		if (sum[e] - sum[s] == N)
		{
			ans += 1;
			s += 1;
			e += 1;
			continue;
		}
		if (sum[e] - sum[s] < N)
		{
			e += 1;
			continue;
		}
		if (sum[e] - sum[s] > N)
		{
			s += 1;
			continue;
		}
	}
	cout << ans;
}