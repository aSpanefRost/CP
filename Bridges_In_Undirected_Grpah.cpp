  //Explanation :: https://cp-algorithms.com/graph/bridge-searching.html
  //Problem Link :: https://leetcode.com/problems/critical-connections-in-a-network/submissions/
  vector<vector<int> > ans;
    int timer=0;
    void dfs(int v,int p,vector<int> ar[],vector<bool>& visited,vector<int>& tin,vector<int>& low)
    {
        visited[v]=true;
        tin[v]=low[v]=timer++;
        for(auto to:ar[v])
        {
            if(to==p) continue;
            if(visited[to])
            {
                //back edge
                low[v]=min(low[v],tin[to]);
            }
            else
            {
                dfs(to,v,ar,visited,tin,low);
                low[v]=min(low[v],low[to]);
                if(low[to]>tin[v])
                {
                    vector<int> temp(2);
                    temp[0]=v;
                    temp[1]=to;
                    ans.push_back(temp);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> ar[n];
        int size=connections.size();
        for(int i=0;i<size;i++)
        {
            ar[connections[i][0]].push_back(connections[i][1]);
            ar[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n,false);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        for(int i=0;i<n;i++)
        {
            if(!visited[i]) dfs(i,-1,ar,visited,tin,low);
        }
        return ans;
    }
