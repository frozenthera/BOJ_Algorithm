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

int N, M;
vector<int> v;
vector<vector<int>> dp;
int func(int left, int idx)
{
	if (idx >= N) return 0;
	if (dp[left][idx] != -1) return dp[left][idx];
	
	int choose = func(left - 1, idx + M);
	for (int i = 0; i < M; i++) choose += v[idx + i];
	dp[left][idx] = max(choose, func(left, idx + 1));
	return dp[left][idx];
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	cin >> M;
	for (int i = 0; i < M - 1; i++) v.push_back(0);
	dp = vector<vector<int>>(4, vector<int>(N + M - 1, -1));
	for (int i = 0; i < N + M - 1; i++) dp[0][i] = 0;

	cout << func(3, 0);
}