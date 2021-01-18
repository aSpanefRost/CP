void dfs(vector<int> ar[],int N,int v,int vis[]) 
{
    vis[v]=1;
    cout<<v<<"->";
    for(int x:ar[v])
    {
    	if(vis[x]==0)dfs(ar,N,x,vis);
    }
}
 
int main()
{
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int N,M;
    cin>>N>>M;
    vector<int> ar[N+1];
    int a,b;
    for(int i=1;i<=M;i++)
    {  
    	cin>>a>>b;
    	a++;
    	b++;
       ar[a].push_back(b);
       ar[b].push_back(a);
    }
    int vis[N+1];
    for(int i=1;i<=N;i++) vis[i]=0;
    dfs(ar,N,1,vis);
    return 0;
}
