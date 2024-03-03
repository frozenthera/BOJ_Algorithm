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
	
	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		int K, temp;
		cin >> K;
		priority_queue<long long> pq;
		for (int i = 0; i < K; i++)
		{
			cin >> temp;
			pq.push(-temp);
		}
		
		long long sum = 0;
		while (pq.size() != 1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			pq.push(a + b);
			sum += (-a - b);
		}
		cout << sum << endl;
	}
}