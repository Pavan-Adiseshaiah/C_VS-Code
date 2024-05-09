#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> p_tri(numRows);

    for (int i=0; i<numRows; i++)   {
        for (int j=0; j<=i; j++)   {
            if (!j || j==i) {
                p_tri[i].push_back(1);
            }
            else if (i>0)   {
                p_tri[i].push_back(p_tri[i-1][j-1]+p_tri[i-1][j]);
            }
        }
    }

    return p_tri;
}

// vector<vector<int>> generate(int numRows) {
//     vector<vector<int>> p_tri;                      // Don't initialize with numRows

//     for (int i=0; i<numRows; i++)   {
//         vector<int> row(i+1, 1);

//         for (int j=1; j<i; j++)   {
//             row[j] = p_tri[i-1][j-1] + p_tri[i-1][j];
//         }
//         p_tri.push_back(row);
//     }

//     return p_tri;
// }


int main()  {
    vector<vector<int>> res = generate(5);

    for (auto i : res)  {
        for (auto j : i)    {
            cout << j << " ";
        }
        cout << endl;
    }
}