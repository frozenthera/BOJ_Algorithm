#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 1000000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string src, dest;
	cin >> N >> src >> dest;
	
	// 1번을 누르지 않는다
	string unpush = src;
	int cnt = 0, ans = INF;
	for (int i = 1; i < N; i++)
	{
		if (unpush[i - 1] != dest[i - 1])
		{
			unpush[i - 1] = dest[i - 1];
			unpush[i] = (unpush[i] == '0' ? '1' : '0');
			if (i != N - 1) unpush[i + 1] = (unpush[i + 1] == '0' ? '1' : '0');
			cnt += 1;
		}
	}
	if (unpush != dest) ans = min(ans, INF);
	else ans = cnt;
	
	string push = src;
	cnt = 1;
	push[0] = (push[0] == '0' ? '1' : '0');
	push[1] = (push[1] == '0' ? '1' : '0');
	for (int i = 1; i < N; i++)
	{
		if (push[i - 1] != dest[i - 1])
		{
			push[i - 1] = dest[i - 1];
			push[i] = (push[i] == '0' ? '1' : '0');
			if (i != N - 1) push[i + 1] = (push[i + 1] == '0' ? '1' : '0');
			cnt += 1;
		}
	}
	if (push != dest) ans = min(ans, INF);
	else ans = min(ans, cnt);

	if (ans == INF) ans = -1;
	cout << ans;
}