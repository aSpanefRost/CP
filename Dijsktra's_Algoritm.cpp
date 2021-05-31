#include<iostream>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
#include<set>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
 
#define fo(i,n) for(lli i=0;i<n;i++)
#define vi vector<lli>
#define lli long long int
#define mem(a,n) memset(a,n,sizeof(a))
#define de(x) cout<<"*"<<x<<"*"<<endl
const lli mod=1000000007;
const lli INF=1000000000;


int main()
{
 
    
  
    lli n,m;
    cin>>n>>m;
    vector<pair<lli,lli> > adj[n];
    lli a,b,w;
    for(lli i=0;i<m;i++)
    {
        cin>>a>>b>>w;
       // a++;b++;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    priority_queue<pair<lli,lli> ,vector<pair<lli,lli> > ,greater<pair<lli,lli > > > pq;

    vector<lli> dist (n+1,INF);

    pq.push(make_pair(0,0));
    dist[0]=0;
	bool visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    while(!pq.empty())
    {
        lli curr=pq.top().second;
        
        lli curr_dis=pq.top().first;
        pq.pop();
        for(pair<lli,lli> edge: adj[curr])
        {
            if(!visited[edge.first] && !visited[curr])
            {
            	if(curr_dis+edge.second<dist[edge.first] && edge.second!=0)
            	{
                	dist[edge.first]=curr_dis+edge.second;
                	pq.push(make_pair(dist[edge.first],edge.first));
            	}
            }
//             edge.first =0;
//             edge.second =0;
            
        }
        visited[curr] = true;
    }
    for(lli i=0;i<n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    
    return 0;
}



//Another Example : Leetcode 1514
//  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         vector<pair<int,double> > ar[n];
//         for(int i=0;i<edges.size();i++)
//         {
//             ar[edges[i][0]].push_back({edges[i][1],succProb[i]});
//             ar[edges[i][1]].push_back({edges[i][0],succProb[i]});
//         }
//         priority_queue<pair<double,int>> pq;
//         vector<double> prob(n,0);
//         prob[start]=1;
//         pq.push({1,start});
//         vector<bool> visited(n,false);
//         while(!pq.empty())
//         {
//             auto curr=pq.top();
//             //cout<<curr.second<<endl;
//             pq.pop();
//             visited[curr.second]=true;
//             for(auto x:ar[curr.second])
//             {
//                 if(!visited[x.first])
//                 {
//                     if(curr.first*x.second>prob[x.first])
//                     {
//                        // cout<<curr.second<<" "<<x.first<<" "<<curr.first<<" "<<x.second<<" "<<prob[x.first]<<endl;
//                         prob[x.first]=(curr.first)*(x.second);
//                         pq.push({prob[x.first],x.first});
//                     }
                   
//                 }
//             }
//         }
//         for(int i=0;i<n;i++) cout<<prob[i]<<" ";
//         return prob[end];
//     }
