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
	int N, M, temp;
	cin >> N;
	unordered_map<int, bool> um;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		um[temp] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		cout << (um[temp] ? 1 : 0) << " ";
	}
}