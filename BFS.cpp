void bfs(vector<int> ar[],int N) 
{
   //testing dev
   int vis[N+1];
   for(int i=0;i<=N;i++) vis[i]=0;
   queue<int> q;
   int c=1;
   q.push(c);
   //cout<<c;
   vis[c]=1;
   while(!q.empty())
   {
   	  int v=q.front();
   	  q.pop();
   	  cout<<v<<"->";
   	  for(int x:ar[v])
   	  {
   	  	if(vis[x]==0)
   	  	{
   	  		vis[x]=1;
   	  		q.push(x);
   	  	}
   	  }
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
    //int vis[N+1];
    //for(int i=1;i<=N;i++) vis[i]=0;
    bfs(ar,N);
    return 0;
}
