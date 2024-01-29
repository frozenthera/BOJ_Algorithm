#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int one = str1.length();
	int two = str2.length();
	vector<vector<int>> lcs(one + 1, vector<int>(two + 1, 0));


	for (int i = 1; i < one + 1; i++)
	{
		for (int j = 1; j < two + 1; j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	int maxi = 0;
	for (int i = 0; i < one+1; i++)
	{
		for (int j = 0; j < two+1; j++)
		{
			maxi = max(maxi, lcs[i][j]);
		}
	}
	cout << maxi;
}