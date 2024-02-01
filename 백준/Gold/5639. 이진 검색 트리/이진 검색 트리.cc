#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
vector<int> v;

void post_traverse(int s, int e)
{
	if (s == e)
	{
		cout << v[s] << "\n";
		return;
	}

	int LB = s;
	while (LB + 1 < v.size() && v[LB + 1] < v[s]) LB += 1;

	if (LB != s) post_traverse(s + 1, LB);
	if (LB < e) post_traverse(LB + 1, e);
	cout << v[s] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int input;
	while (cin >> input)
	{
		v.push_back(input);
	}

	post_traverse(0, v.size() - 1);
}