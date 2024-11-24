//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertBottom(stack<int>& St,int element){
        // base case 
        if(St.empty()){
            St.push(element);
            return;
        }
        int top = St.top();
        St.pop();
        
        insertBottom(St,element);
        
        St.push(top);
    }
    void Reverse(stack<int> &St){
        // base case 
        if(St.empty()) return;
        
        int top = St.top();
        St.pop();
        
        Reverse(St);
        
        insertBottom(St,top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends