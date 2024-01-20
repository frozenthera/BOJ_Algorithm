#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int N, M;
vector<int> example;
void print_vec(vector<int> vec)
{
	for_each(vec.begin(), vec.end(), [](const auto& e) {cout << e << " "; });
	cout << "\n";
}

void func(vector<int> vec, int curIdx)
{
	if (curIdx > N-1)
	{
		return;
	}
	if (vec.size() == M)
	{
		print_vec(vec);
	}
	else
	{
		vec.push_back(example[curIdx]);
		func(vec, curIdx);
		vec.pop_back();
		func(vec, curIdx + 1);
	}
}

int main()
{
	cin >> N >> M;
	cin.ignore();

	string str;
	getline(cin, str);
	istringstream ss(str);
	string stringBuffer;

	while (getline(ss, stringBuffer, ' ')) {
		example.push_back(stoi(stringBuffer));
	}

	sort(example.begin(), example.end());
	example.erase(unique(example.begin(), example.end()), example.end());

	N = example.size();

	vector<int> queue;
	func(queue, 0);
}