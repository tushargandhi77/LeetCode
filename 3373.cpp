class Solution {
public:
    unordered_map<int,vector<int>> makeADJ(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    void DFS(int curr,int parent,unordered_map<int,vector<int>>& adj,vector<int>& mark,int& zero,int& one){
        if(mark[curr] == 0){
            zero++;
        }
        else{
            one++;
        }

        for(int& ngbr: adj[curr]){
            if(ngbr != parent){
                mark[ngbr] = (mark[curr] == 0 ? 1 : 0);
                DFS(ngbr,curr,adj,mark,zero,one); 
            }
        }

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size() + 1;
        int M = edges2.size() + 2;

        unordered_map<int,vector<int>> adjA = makeADJ(edges1);
        unordered_map<int,vector<int>> adjB = makeADJ(edges2);

        vector<int> markA(N,-1);
        int zeroA = 0;
        int oneA = 0;
        markA[0] = 0;
        DFS(0,-1,adjA,markA,zeroA,oneA);

        vector<int> markB(M,-1);
        int zeroB = 0;
        int oneB = 0;
        markB[0] = 0;
        DFS(0,-1,adjB,markB,zeroB,oneB);

        int maxE = max(zeroB,oneB);

        vector<int> result(N,0);
        for(int i = 0;i<N;i++){
            result[i] = (markA[i] == 0 ? zeroA : oneA) + maxE;
        }

        return result;
    }
};
