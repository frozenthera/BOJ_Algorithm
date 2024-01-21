#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;
vector<vector<int>> map;
int move(int i, int j, int state)
{
	if (i == N - 1 && j == N - 1) return 1;
	int sum = 0; 
	if (state == 0)
	{
		if (j < N-1 && map[i][j + 1] == 0)
		{
			sum += move(i, j + 1, 0);
		}
		if (i < N-1 && j < N-1 && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
		{
			sum += move(i + 1, j + 1, 2);
		}
	}
	else if (state == 1)
	{
		if (i < N-1 && map[i + 1][j] == 0)
		{
			sum += move(i + 1, j, 1);
		}
		if (i < N - 1 && j < N - 1 && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
		{
			sum += move(i + 1, j + 1, 2);
		}
	}
	else
	{
		if (j < N - 1 && map[i][j + 1] == 0)
		{
			sum += move(i, j + 1, 0);
		}
		if (i < N-1 && map[i + 1][j] == 0)
		{
			sum += move(i + 1, j, 1);
		}
		if (i < N - 1 && j < N - 1 && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
		{
			sum += move(i + 1, j + 1, 2);
		}
	}
	return sum;
}

int main()
{
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		string str;
		getline(cin, str);
		istringstream ss(str);
		string stringBuffer;

		while (getline(ss, stringBuffer, ' ')) {
			temp.push_back(stoi(stringBuffer));
		}
		map.push_back(temp);
	}
	// 0 -> horizontal, 1 -> vertical, 2 -> diagonal
	int state = 0;
	cout << move(0, 1, 0) << endl;
}