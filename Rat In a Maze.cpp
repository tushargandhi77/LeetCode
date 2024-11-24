//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> result;
    
    void solve(int i,int j, vector<vector<int>>& mat,string& path,int n){
        if(i < 0 || i >= n || j < 0 || j >=n || mat[i][j] == 0) return;
        
        if(i == n-1 && j == n-1) result.push_back(path);
        
        mat[i][j] = 0;
        
        // right
        path.push_back('R');
        solve(i,j+1,mat,path,n);
        path.pop_back();
        
        
        // left
        path.push_back('L');
        solve(i,j-1,mat,path,n);
        path.pop_back();
        
        
        // up
        path.push_back('U');
        solve(i-1,j,mat,path,n);
        path.pop_back();
        
        
        // down
        path.push_back('D');
        solve(i+1,j,mat,path,n);
        path.pop_back();
        
        mat[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        string s = "";
        solve(0,0,mat,s,n);
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
