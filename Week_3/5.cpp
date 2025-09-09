#include <iostream>
using namespace std;
#include <vector>


/*
problem statement:

Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix
*/

// (a) Diagonal Matrix.

vector<int> DiagonalMatrix(vector<vector<int>>&mat){
    if(mat.size() != mat[0].size())return {}; // diagonal matrix is always a square matrix;
    vector<int>Diag;
    for(int i = 0 ; i < mat.size() ; i++){
        Diag.push_back(mat[i][i]);
    }
    return Diag;
}

// (b) Tri-diagonal Matrix.
/*
    this is example of Tri diagonal matrix
    1 4 0 0 0
    1 3 2 0 0
    0 2 2 1 0
    0 0 1 5 9
    0 0 0 6 1

*/
vector<vector<int>> TriDiagonalMat(vector<vector<int>> &mat){
    vector<int> diag;
    vector<int> upper;
    vector<int> lower;
    int n = mat.size();
    // matrix is always square matrix;

        for (int i = 0; i < n; i++) {
        if (i > 0) upper.push_back(mat[i-1][i]);   // upper diag
        if (i < n-1) lower.push_back(mat[i+1][i]); // lower diag
        diag.push_back(mat[i][i]);                 // diag
        }

    // printing it
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j==i){// diagonal element
                cout<<diag[j]<<"    ";
            }
            else if (j == i+1) {   // upper diagonal
                cout << upper[i] << "    ";
            }
            else if (j+1 == i) {   // lower diagonal
                cout << lower[j] << "    ";
            }
            else{ // element should be 0 , to form Tri diagonnal matrix
                cout<<0<<"    ";
            }
        }
        cout<<endl;
    }
    return {upper , diag , lower};
}

// (c) Lower triangular matrix;


/*
example:
1 0 0
1 2 0
1 2 3
*/
vector<vector<int>> LowerTriangularMat(vector<vector<int>> &mat){
    int n = mat.size();
    vector<vector<int>>ans;
    for(int i = 0 ; i < n ; i++){
        vector<int>temp;
        for(int j = 0 ; j <= i ; j++){
            temp.push_back(mat[i][j]);
        }
        ans.push_back(temp);
    }

    // printing of this triangular matrix
    n = ans.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= i ; j++){
            cout<<" "<<ans[i][j]<<" ";
        }
        for(int j = i+1 ; j < n ; j++)cout<<" 0 ";
        cout<<endl;
    }
    return ans;
}

// (d) Upper triangular Matrix
/*
1 3 4
0 2 5
0 0 3
elements below diagnol are 0
*/
vector<vector<int>> UpperTriMat(vector<vector<int>> &mat){
    vector<vector<int>>ans;
    int n = mat.size();
    for(int i = 0 ; i < n ; i++){
        vector<int>temp;
        for(int j = i ; j < n ; j++){
            temp.push_back(mat[i][j]);
        }
        ans.push_back(temp);
    }

    // printing our upper triangualar matrix with our answer
    n = ans.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++)cout<<"0 ";
        int idx = 0;
        for(int j = i ; j < n ; j++)cout<<ans[i][idx++]<<" ";

        cout<<endl;
    }
    return ans;
}

// (e) Symmetric Matrix
// symmetric matrix is a matrix whose transpose is same as of original matrix or we can say A[i][j] == A[j][i]
vector<vector<int>> SymmetrixMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    vector<vector<int>>ans;
    // we can store it like we store above upper triangular matrix
    for(int i = 0 ; i < n ; i++){
        vector<int>temp;
        for(int j = 0 ; j<=i ; j++){
            temp.push_back(mat[i][j]);
        }
        ans.push_back(temp);
    }

    // printing of our stored symmetric matrix
    n = ans.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if (j <= i) {
                cout << ans[i][j] << "  "; // stored directly
            } else {
                cout << ans[j][i] << "  "; // take from transpose
            }
        }
        cout<<endl;
    }
    return ans;
}



int main(){
    vector<vector<int>> mat = { // for TriDiagonal matrix
        {1, 4, 0, 0, 0},
        {1, 3, 2, 0, 0},
        {0, 2, 2, 1, 0},
        {0, 0, 1, 5, 9},
        {0, 0, 0, 6, 1}
    };

    vector<vector<int>>res = TriDiagonalMat(mat); // to store our space efficient  tri-Diagonal matrix
    vector<vector<int>> mat2 = { // we can directly pass a Lower triangual matrix , but for verification does our function corectly store a lower triangular matrix we pass full matrix and our code successfully store and print our lower triangular matrix

        {1, 110, 110},
        {1, 2, 110},
        {1, 2, 3}
    };
    vector<vector<int>>mat3 = LowerTriangularMat(mat2); // to store our space efficient Lower triangular matrix

    cout<<endl;
    vector<vector<int>> mat4 = { // we can directly pass a upper triangual matrix , but for verification does our function corectly store a upper triangular elelments only we pass full matrix and our code successfully store and print our lower triangular matrix

        {1, 110, 110},
        {1, 2, 110},
        {1, 2, 3}
    };
    vector<vector<int>>mat4UpperTri = UpperTriMat(mat2); // to store our space efficient upper triangular matrix

    vector<vector<int>> mat5 = { //for symmetrix matrix
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<endl;
    vector<vector<int>>mat5SymMat = SymmetrixMatrix(mat5);

    return 0 ;

}