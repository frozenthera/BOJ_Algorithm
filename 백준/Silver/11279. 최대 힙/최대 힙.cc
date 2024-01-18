#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    queue<int> res;
    int N, cnt = 0;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 0)
        {
            cnt += 1;
            if(pq.empty())
            {
                res.push(0);
            }
            else 
            {
                res.push(pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(temp);
        }
    }

    while(!res.empty())
    {
        cout << res.front() << "\n";
        res.pop();
    } 
}