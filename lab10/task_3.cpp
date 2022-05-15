#include <iostream>
#include <vector>

using namespace std;

void output(vector<vector <int>> matrix, int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            cout<< matrix[i][j] << " ";
        cout<< '\n';
    }    
}
int find_row_negative(vector<vector <int>> matrix, int row, int column)
{
    int pos = 0;
    for(int i=0; i<row; i++)
    {
        bool flag = true;
        for(int j=0; j<column; j++)
            if(matrix[i][j] >= 0)
                flag = false;
        if(flag == true)
        {
            pos = i; 
            break;
        }
                   
    }
    return pos;
}
int find_row_positive(vector<vector <int>> matrix, int row, int column)
{
    int pos = 0;
    for(int i=0; i<row; i++)
    {
        bool flag = true;
        for(int j=0; j<column; j++)
            if(matrix[i][j] < 0)
                flag = false;
        if(flag == true)
        {
            pos = i; 
            break;
        }
                   
    }
    return pos;
}
int find_column_even(vector<vector <int>> matrix, int row, int column)
{
    int pos = 0;
    for(int j=0; j<column; j++)
    {
        bool flag = true;
        for(int i=0; i<row; i++)
            if(abs(matrix[i][j]) % 2 == 1)
                flag = false;
        if(flag == true)
        {
            pos = j; 
            break;
        }
                   
    }
    return pos;
}
int find_column_odd(vector<vector <int>> matrix, int row, int column)
{
    int pos = 0;
    for(int j=0; j<column; j++)
    {
        bool flag = true;
        for(int i=0; i<row; i++)
            if(abs(matrix[i][j]) % 2 ==  0)
                flag = false;
        if(flag == true)
        {
            pos = j; 
            break;
        }
                   
    }
    return pos;
}

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

    int row_neg = find_row_negative(matrix, row, column);   
    int row_pos = find_row_positive(matrix, row, column); 
    int column_odd = find_column_odd(matrix, row, column);
    int column_even = find_column_even(matrix, row, column);
    matrix[row_neg].swap(matrix[row_pos]);
    for(int i=0; i<row; i++)
        swap(matrix[i][column_even], matrix[i][column_odd]);
    cout<<'\n';
    output(matrix, row, column);
    return 0;
}