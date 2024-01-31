#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string str;
	cin >> N >> M >> str;
	
	char lastChar;
	int len = 0, start = 0, end = 1, res = 0;

	while (start < M - 1 && !(str[start] == 'I' && str[start + 1] == 'O'))
	{
		start = end;
		end += 1;
	}
	len = 1;
	lastChar = 'I';

	while (end < M)
	{
		while (end < M && lastChar != str[end])
		{
			lastChar = str[end];
			end += 1;
		}

		if (lastChar == 'I')
		{
			len = end - start;
		}
		else len = end - start - 1;

		if(len >= 2 * N + 1) res += (int)((len - 1) / 2) - N + 1;

		start = end;
		end += 1;

		while (start < M - 1 && !(str[start] == 'I' && str[start + 1] == 'O'))
		{
			start = end;
			end += 1;
		}
		len = 1;
		lastChar = 'I';
	}

	cout << res;
}