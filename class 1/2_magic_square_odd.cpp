#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n : ";
    cin >> n;
    int arr[100][100] = {0};
    int num = 1;
    int row = 0;
    int col = n / 2;
    while (num <= n * n)
    {
        arr[row][col] = num;
        int newrow = (row - 1 + n) % n;
        int newcol = (col + 1) % n;
        if (arr[newrow][newcol] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = newrow;
            col = newcol;
        }
        num++;
    }
    int maxlength=to_string(n*n).length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int number=arr[i][j];
            int numlen=to_string(number).length();
            for(int i=0;i<maxlength-numlen;i++)
            cout<<"0";
            cout << number << " ";
        }
        cout << endl;
    }
}