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

vector<int> in;
vector<int> post;

void ToPre(int sin, int ein, int spost, int epost)
{
	vector<int> ans;
	if (ein < sin || epost < spost) return;
	if (sin == ein || spost== epost)
	{
		cout << in[sin] << " ";
		return;
	}

	int root = post[epost];	
	cout << root << " ";

	int nsin = sin;
	int nspost = spost;
	while ( in[nsin] != root )
	{
		nsin += 1;
		nspost += 1;
	}
	ToPre(sin, nsin - 1, spost, nspost - 1);
	nsin += 1;
	ToPre(nsin, ein, nspost, epost - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	in = vector<int>(N);
	post = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> in[i];
	for (int i = 0; i < N; i++) cin >> post[i];
	ToPre(0, N - 1, 0, N - 1);
}