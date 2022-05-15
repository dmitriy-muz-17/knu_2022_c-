#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int row, column;
    vector<vector <int>> matrix;

    cout<< "Input K P: ";
    cin>>row>>column;
    matrix.resize(row);
    for(int i=0; i<row; i++)
        matrix[i].resize(column);
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            cin>>matrix[i][j]; 
    int min = 0, sum_min = 0;
    int min_el = matrix[0][0], min_col = 0;
    for(int i=0; i<column; i++)
        sum_min += matrix[0][i];
    
    for(int i=0; i<row; i++)
    {
        int sum = 0;
        for(int j=0; j<column; j++)
        {
            sum += matrix[i][j];
            if(matrix[i][j] < min_el)
            {
                min_col = j;
                min_el = matrix[i][j];
            }
        } 
        if(sum_min > sum)
        {
            sum_min = sum;
            min = i;
        }       
    }
    matrix.erase(matrix.begin() + min) ;
    row--;
    for(int i=0; i<row; i++)
        matrix[i].erase(matrix[i].begin() + min_col);
    column--;

    cout<<'\n';
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            cout<< matrix[i][j] << " ";
        cout<< '\n';
    }
    return 0;
}