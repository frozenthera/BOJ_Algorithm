#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int L;
    float A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    int ans = L - max(ceil(A/C), ceil(B/D));
    cout << ans;
}