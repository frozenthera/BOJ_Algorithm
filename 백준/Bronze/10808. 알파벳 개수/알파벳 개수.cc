#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    vector<int> v(26, 0);
    for(int i =0; i< str.size(); i++)
    {
        v[str[i] - 'a'] += 1;
    }
    for(auto item : v) cout << item << " ";
}