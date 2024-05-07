#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomeNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FullArrayWithOrderdNumber(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            arr[i][j] = RandomeNumber(0, 9);
        }
    }
}

void PrintArrayInMatrix(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
}

bool IsScalarMatrix(short arr1[3][3], short Rows, short Cols)
{
    short FirstDiagElement = arr1[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j && arr1[i][j] != FirstDiagElement)
            {
                return false;
            }
            else if (i != j && arr1[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void PossibilityOccurrence(short arr1[3][3], short rows, short cols)
{

    int counter = 0;
    while (true)
    {
        FullArrayWithOrderdNumber(arr1, rows, cols);
        if (IsScalarMatrix(arr1, rows, cols))
        {
            cout << "\ntry number : " << counter << "\n\n";
            cout << "Matrix1:\n";
            PrintArrayInMatrix(arr1, rows, cols);
            break;
        }
        counter++;
    }
}

int main()
{

    srand((unsigned)time(NULL));
    short arr1[3][3];
    short cols = 3, rows = 3;


    //  1         0          0
    //  0         1          0
    //  0         0          1

    FullArrayWithOrderdNumber(arr1, rows, cols);

    cout << "Matrix1:\n";
    PrintArrayInMatrix(arr1, rows, cols);


    if (IsScalarMatrix(arr1,rows,cols))
    {
        cout << "\nYes: Matrix is identity.\n";
    }
    else
    {
        cout << "\nNo: matrices is Not identity.\n";
    }

    //PossibilityOccurrence(arr1, rows, cols);

    return 0;
}