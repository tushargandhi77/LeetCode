//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int N;
	    vector<string> result;
	    void solve(string& curr,string &s,int idx){
	        if(idx>=N){
	            if(curr != "") result.push_back(curr);
	            return;
	        }
	        
	        curr.push_back(s[idx]);
	        solve(curr,s,idx+1);
	        curr.pop_back();
	        
	        solve(curr,s,idx+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    N = s.length();
		    string curr = "";
		    solve(curr,s,0);
		    sort(begin(result),end(result));
		    return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
