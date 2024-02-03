#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;
		priority_queue<long long> maxH;
		priority_queue<long long> minH;
		unordered_map<long long, int> map;
		for (int j = 0; j < n; j++)
		{
			char inst;
			long long val;
			cin >> inst >> val;
			if (inst == 'D')
			{
				if (maxH.size() == 0 || minH.size() == 0) continue;
				if (val == 1)
				{
					long long max_num = maxH.top();

					if (map[max_num] != 0) map[max_num] -= 1;
					maxH.pop();
				}
				else if (val == -1)
				{
					long long min_num = -minH.top();

					if (map[min_num] != 0) map[min_num] -= 1;
					minH.pop();
				}
				
				while (minH.size() != 0 && map[-minH.top()] == 0)
				{
					minH.pop();
				}
				while (maxH.size() != 0 && map[maxH.top()] == 0)
				{
					maxH.pop();
				}
			}
			else if(inst == 'I')
			{
				maxH.push(val);
				minH.push(-val);
				map[val] += 1;
			}
		}

		if (minH.size() == 0)
		{
			cout << "EMPTY\n";
;		}
		else
		{
			cout << maxH.top() << " " << -minH.top() << "\n";
		}
	}
}