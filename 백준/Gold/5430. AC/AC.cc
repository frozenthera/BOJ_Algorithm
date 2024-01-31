#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		string inst, list;
		deque<int> v;
		int n;
		bool isforward = true;
		cin >> inst >> n >> list;

		list.erase(0 ,1);
		list.erase(list.size() - 1 ,1);
		istringstream ss(list);
		string stringBuffer;

		while (getline(ss, stringBuffer, ',')) {
			v.push_back(stoi(stringBuffer));
		}

		bool err = false;
		for (int j = 0; j < inst.size(); j++)
		{
			if (inst[j] == 'R')
			{
				isforward = !isforward;
			}
			else
			{
				if (v.size() == 0)
				{
					err = true;
				}
				else
				{
					if (isforward)
					{
						v.pop_front();
					}
					else
					{
						v.pop_back();
					}
				}
			}
		}
		if (!err)
		{
			cout << '[';
			if (!v.empty())
			{
				if (isforward)
				{
					for (auto it = v.begin(); it != v.end(); it++)
					{
						if(it == v.begin()) cout << *it;
						else cout << "," << *it;
					}
				}
				else if (!isforward)
				{
					for (auto it = v.rbegin(); it != v.rend(); it++)
					{
						if (it == v.rbegin()) cout << *it;
						else cout << "," << *it;
					}
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}
	}
	

}
