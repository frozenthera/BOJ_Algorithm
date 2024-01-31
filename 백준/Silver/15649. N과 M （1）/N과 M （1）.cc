#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;

void func(vector<int> cur)
{
	if (cur.size() == M)
	{
		for (int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (find(cur.begin(), cur.end(), i) == cur.end())
		{
			cur.push_back(i);
			func(cur);
			cur.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	func(vector<int>());
}
