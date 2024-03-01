#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#define INF 2e9

using namespace std;

int eval(int a, char c, int b)
{
	if (c == '+')
	{
		return a + b;
	}
	if (c == '-')
	{
		return a - b;
	}
	if (c == '*')
	{
		return a * b;
	}
}

int func(deque<int> num, deque<char> op)
{
	if (num.size() == 1) return num[0];
	if (num.size() == 2)
	{
		return eval(num[0], op[0], num[1]);
	}

	auto ndq = num;
	auto odq = op;
	int a = ndq.front();
	ndq.pop_front();
	int b = ndq.front();
	ndq.pop_front();
	char o1 = odq.front();
	odq.pop_front();
	char o2 = odq.front();
	int c = ndq.front();
	ndq.push_front(eval(a, o1, b));
	int F = func(ndq, odq);

	int k = eval(b, o2, c);
	ndq.pop_front();
	ndq.pop_front();
	odq.pop_front();
	ndq.push_front(eval(a, o1, k));
	int S = func(ndq, odq);

	return max(F, S);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string str;
	cin >> N >> str;
	deque<int> num;
	deque<char> op;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 != 0) op.push_back(str[i]);
		else num.push_back(str[i] - '0');
	}
	cout << func(num, op);
}