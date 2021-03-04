//Kosaraju's algorithm (Code inspired from the CodeNcode Yt channel)

vector<int> ar[1001];  //adjacency list to store the graph
vector<int> tr[1001];  //adjacency list to store the transpose graph

vector<int> order;     //To store the nodes of condensation graph and they are in 
                       // order of DFS traversal 
vector<int> SSC;       // To store a strongly connected component

int vis[1001];

void dfs(int node)     //dfs to sort the nodes in increasing order of their "out-time"
{
     vis[node]=1;
     for(auto x:ar[node])
     {
        if(vis[node]==0)
        {
           dfs(node);
        }
     }
     order.push_back(node);
}

void dfs1(int node)    //dfs to traverse the nodes of transpose graph
{
    SSC.push_back(node);
    vis[node]=1;
    for(auto x:tr[node])
    {
       if(vis[x]==0)
       {
        dfs1(x);
       }
    }
}

void solve()
{
    int n;   //no. of nodes
    int m;  // no. of edges
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=0;i<m;i++)
    {
       cin>>a>>b;
       ar[a].push_back(b);
       tr[b].push_back(a);
    } 
    for(int i=1;i<=n;i++)
    {
       if(vis[i]==0) dfs(i);
    }
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++)
    {
       if(vis[order[n-i]]==0)
       {
         SSC.clear();
         dfs1(order[n-i]);

         cout<<"dfs1() called from"<<order[n-i]<<"and Printing SSC"<<endl;
         for(auto x: SSC)
         {
          cout<<x<<" ";
         }
          cout<<endl;
       }
    }

}  

 
signed main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    t=1;
    //cin>>t;
     while(t--)
     {
        solve();
     }
    
  return 0;
}
