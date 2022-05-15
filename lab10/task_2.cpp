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

    int min_col = column + 1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            if(matrix[i][j] < 0)
            {
                min_col = j;
                break;
            }
    }
    cout<<min_col<<'\n';
    for(int i=0; i<row; i++)
    {
        bool flag = true;
        for(int j=1; j<column; j++)
        {
            if(matrix[i][j] < matrix[i][j-1])
                flag = false;            
        }


        if(flag == true)
        {
            matrix.insert(matrix.begin() + i, vector<int>(column,0));
            i++;
            row++;
        }
      //  cout<<row<<'\n';
    }
    
    if(min_col < column)
    {
        for(int i=0; i<row; i++)
            matrix[i].insert(matrix[i].begin() + min_col + 1, 1);   
        column++;     
    }

    
    output(matrix, row, column);
    return 0;
}