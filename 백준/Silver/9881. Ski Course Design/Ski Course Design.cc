#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> hill;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		hill.push_back(temp);
	}
	sort(hill.begin(), hill.end());

	int M = 987654321;
	for (int i = hill[0]; i <= 83; i++)
	{
		int temp = 0;
		for (auto it = hill.begin(); it != hill.end(); it++)
		{
			if (*it < i)  temp += pow((*it - i), 2);
			if (*it > i + 17) temp += pow((*it - i - 17), 2);
		}
		M = min(M, temp);
	}
	cout << M;
}
