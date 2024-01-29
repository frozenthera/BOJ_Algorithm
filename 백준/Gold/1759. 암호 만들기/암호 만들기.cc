#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<char> s;
int L, C;

void func(deque<char> vec, int idx, int numOfVowel)
{
	if (vec.size() == L)
	{
		if (numOfVowel == 0 || L - numOfVowel < 2) return;
		for (auto it = vec.begin(); it != vec.end(); it++) cout << *it;
		cout << endl;
		return;
	}

	if (idx > C - 1) return;

	vec.push_back(s[idx]);
	if (s[idx] == 'a' || s[idx] == 'e' || s[idx] == 'i' || s[idx] == 'o' || s[idx] == 'u')
	{
		func(vec, idx + 1, numOfVowel + 1);
	}
	else
	{
		func(vec, idx + 1, numOfVowel);
	}
	vec.pop_back();
	func(vec, idx + 1, numOfVowel);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;
		
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		s.push_back(c);
	}
	sort(s.begin(), s.end());

	func(deque<char>(), 0, 0);
}