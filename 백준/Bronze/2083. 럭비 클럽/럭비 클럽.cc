#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<pair<string, string>> ans;
	string str;
	int a, h;
	cin >> str >> a >> h;
	while (!(str == "#" && a == 0 && h == 0))
	{
		if (a > 17 || h >= 80) ans.push_back(make_pair(str, "Senior"));
		else ans.push_back(make_pair(str, "Junior"));
		cin >> str >> a >> h;
	}
	for (auto item : ans)
	{
		cout << item.first << " " << item.second << "\n";
	}
}