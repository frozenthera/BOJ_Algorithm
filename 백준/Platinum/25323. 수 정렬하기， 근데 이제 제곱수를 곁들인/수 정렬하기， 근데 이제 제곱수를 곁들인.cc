#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

long long gcd(long long a, long long b)
{
	if(a < b) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

bool isSquare(long long n) {
	long long root = sqrt(n);
	return root * root == n ? true : false;
}

bool isMulSquare(long long a, long long b)
{
	long long GCD = gcd(a, b);
	long long l = a / GCD;
	long long m = b / GCD;
	return isSquare(l) && isSquare(m);
	/*if (GCD == 1)
	{
		if (l == m) return true;
		else if (!isSquare(l) && !isSquare(m)) return false;
		return true;
	}
	return isMulSquare(l, m);*/
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<long long> vec(N);
	vector<long long> res(N);
	unordered_map<long long, int> pos;
	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		vec[i] = temp;
		pos[temp] = i;
	}
	
	sort(vec.begin(), vec.end());

	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		if(!isMulSquare(vec[i], vec[pos[vec[i]]]))
		{
			flag = false;
			break;
		}
	}
	
	cout << (flag ? "YES" : "NO");
}