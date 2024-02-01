#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> mini(3, 0), maxi(3, 0), input(3), tmp(3,0);
	for (int i = 0; i < N; i++)
	{
		cin >> input[0] >> input[1] >> input[2];
		
		tmp[0] = max(maxi[0], maxi[1]) + input[0];
		tmp[1] = max(max(maxi[0], maxi[1]), maxi[2]) + input[1];
		tmp[2] = max(maxi[1], maxi[2]) + input[2];
		
		maxi[0] = tmp[0];
		maxi[1] = tmp[1];
		maxi[2] = tmp[2];

		tmp[0] = min(mini[0], mini[1]) + input[0];
		tmp[1] = min(min(mini[0], mini[1]), mini[2]) + input[1];
		tmp[2] = min(mini[1], mini[2]) + input[2];

		mini[0] = tmp[0];
		mini[1] = tmp[1];
		mini[2] = tmp[2];
	}
	cout << max(max(maxi[0], maxi[1]), maxi[2]) << " " << min(min(mini[0], mini[1]), mini[2]);
}
