#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcd(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	vector<int> vec;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	vector<int> ans;
	
	vector<bool> v(3, false);
	v.insert(v.end(), 2, true);
	do
	{
		vector<int> temp;
		for (int j = 0; j < 5; j++)
		{
			if (!v[j]) temp.push_back(vec[j]);
		}

		ans.push_back(lcd(lcd(temp[0], temp[1]), temp[2]));
			
	} while (next_permutation(v.begin(), v.end()));

	sort(ans.begin(), ans.end());
	cout << ans[0];
}