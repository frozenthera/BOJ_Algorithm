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

int N;
bool isprime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

void func(int n, int len)
{
	if (len == N)
	{
		cout << n << "\n";
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		if (!isprime(n * 10 + i)) continue;
		func(n * 10 + i, len + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	func(0, 0);
}