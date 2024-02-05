#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	double myHP, myATK, enemHP, enemATK, P, S;
	cin >> myHP >> myATK >> enemHP >> enemATK >> P >> S;
	
	long long myRate = ceil(myHP / enemATK);
	long long enemRate = ceil(enemHP / myATK);
	long long healEnemRate = ceil((enemHP + S) / myATK);

	if (enemHP - (enemRate - 1) * myATK <= P)
	{
		if (myRate >= healEnemRate)
		{
			cout << "Victory!";
		}
		else
		{
			cout << "gg";
		}
	}
	else
	{
		if (myRate >= enemRate)
		{
			cout << "Victory!";
		}
		else
		{
			cout << "gg";
		}
	}
	
}
