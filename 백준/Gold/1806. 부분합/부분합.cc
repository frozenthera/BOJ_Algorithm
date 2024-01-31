#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, S, res;
	vector<int> sum;
	sum.push_back(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		sum.push_back(sum.back() + n);
	}

	int len = 0;
	if (sum.back() < S) len = 0;
	else
	{
		int start = 0, end = 0;
		while (sum[end] < S) end += 1;
		len = end - start;

		while (end < N + 1)
		{
			if (sum[end] - sum[start + 1] >= S)
			{
				start += 1;
				len = end - start;
			}
			else
			{
				start += 1;
				end += 1;
			}
		}
	}
	cout << len;
}