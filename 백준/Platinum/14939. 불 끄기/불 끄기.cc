#include <iostream>
#include <cmath>
#include <stdio.h>

bool arr[12][12] = {true};

using namespace std;

bool validate()
{
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
        {
            if(arr[i][j]) return false;
        }
    }
    return true;
}

int check(int col, int row)
{
    if(row > 2)
    {
        if(arr[col][row-2]) return 987654321;
    }

    if(row > 10)
    {
        if(validate()) return 0;
        else return 987654321;
    }

    int nextCol, nextRow;
    if(col == 10)
    {
        nextCol = 1;
        nextRow = row + 1;
    }
    else
    {
        nextCol = col+1;
        nextRow = row;
    }

    //누르지 않는 경우
    int min = check(nextCol, nextRow);

    //누르는 경우
    arr[col][row] = !arr[col][row];
    arr[col-1][row] = !arr[col-1][row];
    arr[col][row-1] = !arr[col][row-1];
    arr[col+1][row] = !arr[col+1][row];
    arr[col][row+1] = !arr[col][row+1];

    int temp = check(nextCol, nextRow);
    if(temp < min)
    {
        return temp + 1;
    }
    else
    {
        //누르는게 잘못된 풀이인 경우 원래대로 돌려놓기
        arr[col][row] = !arr[col][row];
        arr[col-1][row] = !arr[col-1][row];
        arr[col][row-1] = !arr[col][row-1];
        arr[col+1][row] = !arr[col+1][row];
        arr[col][row+1] = !arr[col][row+1];
        return min;
    }
}

int main()
{
    string str;
    for(int i=1; i<=10; i++)
    {
        cin >> str;
        for(int j=0; j<10; j++)
        {
            if(str[j] == 'O') arr[i][j+1] = true;
            else arr[i][j+1] = false;
        }
    }

    int res = check(1,1);
    if(res > 101) cout << -1 << endl;
    else cout << res << endl;
   
    return 0;
}