#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;

void print_vec(vector<int> vec)
{
	for_each(vec.begin(), vec.end(), [](const auto& e) {cout << e << " "; });
	cout << "\n";
}

int main()
{
	int N;
	cin >> N;
	cin.ignore();

	vector<int> vec;
	vector<int> asc;
	vector<int> desc;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	vector<int> v;
	v.push_back(-INF);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (v.back() < vec[i])
		{
			v.push_back(vec[i]);
			ans++;
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), vec[i]);
			*it = vec[i];
		}
		asc.push_back(ans);
	}

	ans = 0;
	v.clear();
	v.push_back(-INF);
	for (int i = N - 1; i >= 0; i--)
	{
		if (v.back() < vec[i])
		{
			v.push_back(vec[i]);
			ans++;
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), vec[i]);
			*it = vec[i];
		}
		desc.push_back(ans);
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (max < asc[i] + desc[N - i - 1] - 1) max = asc[i] + desc[N - i - 1] - 1;
	}
	cout << max << endl;
}