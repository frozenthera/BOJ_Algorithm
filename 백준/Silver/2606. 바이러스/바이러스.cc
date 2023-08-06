#include <iostream>

using namespace std;

bool arr[100][100] = {false};
bool infected[100] = {false};
bool checked[100] = {false};

void check(int idx)
{
    if(infected[idx])
    {
        checked[idx] = true;
        for(int i=0; i<100; i++)
        {
            if(arr[idx][i] && !checked[i])
            {
                infected[i] = true;
                check(i);
            }
        }
    }
}

int main()
{
    int n, conn;
    cin >> n >> conn;
    for(int i=0; i<conn; i++)
    {
        int from, to;
        cin >> from >> to;
        arr[from-1][to-1] = true;
        arr[to-1][from-1] = true;
    }
    infected[0] = true;
    check(0);
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(infected[i])
        {
            cnt++;
        } 
    } 
    cout << cnt-1 << endl;
    return 0;
}