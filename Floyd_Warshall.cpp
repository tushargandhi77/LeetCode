//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(mat[i][j] == -1) mat[i][j] = 100000;
            }
        }
        
        for(int via = 0;via < m;via++){
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    mat[i][j] = min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(mat[i][j] == 100000) mat[i][j] = -1;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
