#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Singly-even check
    if (n % 2 != 0 || n % 4 == 0)
    {
        cout << "n must be singly even (6, 10, 14, ...)";
        return 0;
    }

    int m = n / 2;
    int k = (m - 1) / 2;

    int A[100][100] = {0};
    int B[100][100] = {0};
    int C[100][100] = {0};
    int D[100][100] = {0};

    // --------------------------------------------------
    // STEP 1: Create an odd-order magic square
    // --------------------------------------------------

    int small[100][100] = {0};

    int row = 0;
    int col = m / 2;

    for (int num = 1; num <= m * m; num++)
    {
        small[row][col] = num;

        int newrow = (row - 1 + m) % m;
        int newcol = (col + 1) % m;

        if (small[newrow][newcol] != 0)
        {
            row = (row + 1) % m;
        }
        else
        {
            row = newrow;
            col = newcol;
        }
    }

    // --------------------------------------------------
    // STEP 2: Create the four quadrants
    //
    //        A | C
    //        --+--
    //        D | B
    // --------------------------------------------------

    int block = m * m;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = small[i][j];
            B[i][j] = small[i][j] + block;
            C[i][j] = small[i][j] + 2 * block;
            D[i][j] = small[i][j] + 3 * block;
        }
    }

    // --------------------------------------------------
    // STEP 3: Swap first k columns of A and D
    // --------------------------------------------------

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            swap(A[i][j], D[i][j]);
        }
    }

    // --------------------------------------------------
    // STEP 4: Swap last k-1 columns of C and B
    // --------------------------------------------------

    for (int i = 0; i < m; i++)
    {
        for (int j = m - (k - 1); j < m; j++)
        {
            swap(C[i][j], B[i][j]);
        }
    }

    // --------------------------------------------------
    // STEP 5: Two special cell swaps
    // --------------------------------------------------

    int middle = m / 2;

    // Middle cell of the first column
    swap(A[middle][0], D[middle][0]);

    // Central cell
    swap(A[middle][middle], D[middle][middle]);

    // --------------------------------------------------
    // STEP 6: Assemble the final square
    //
    //        A | C
    //        --+--
    //        D | B
    // --------------------------------------------------

    int ans[100][100];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = A[i][j];
            ans[i][j + m] = C[i][j];

            ans[i + m][j] = D[i][j];
            ans[i + m][j + m] = B[i][j];
        }
    }

    // --------------------------------------------------
    // PRINT
    // --------------------------------------------------

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << "\t";
        }
        cout << endl;
    }
}

