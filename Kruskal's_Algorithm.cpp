#include<iostream>

//Edge structure which contains the source and destination index and the weight of the edge
typedef struct 
{
    int src;
    int des;
    int weight;
}Edge;
 
bool func(Edge a,Edge b)
{
    return a.weight<b.weight;
}
//what is parent of the set ,ith element belongs to 
int find(int i,int parent[])
{
    while(1)
    {
       if(i==parent[i]) 
       {
          return i;
       }
       else 
       {
         i=parent[i];
       }
    }
}
//if two vertices belongs two differnt sets , merge them .
void union1(int a,int b,int parent[])
{
    int x=find(a,parent);
    int y=find(b,parent);
    if(x==y) return;
    else parent[x]=y;
}  


int main()
{
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   
    int v,e;
    cin>>v>>e;
    Edge arr[e];
    int a,b,c;
    for(int i=0;i<e;i++)
    {
      cin>>a>>b>>c;
      arr[i].src=a;
      arr[i].des=b;
      arr[i].weight=c;
    }
    sort(arr,arr+e,func);

    int parent[v];   //parent array to store the value of the parents of each vertex. Initially parent would be same vertex.
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    
    //Kruskal's algorithm
    
    int count=0;
    int i=0;
    while(count!=v-1)  //We're only interested in (v-1) number of edges . because a tree has (v-1) edges
    {
        if(find(arr[i].src,parent)!=find(arr[i].des,parent))
        {
            union1(arr[i].src,arr[i].des,parent);
            count++;
            if(arr[i].src>arr[i].des) cout<<arr[i].des<<" "<<arr[i].src<<" "<<arr[i].weight<<endl;
            else cout<<arr[i].src<<" "<<arr[i].des<<" "<<arr[i].weight<<endl;
        }
        i++;
    }

    return 0;

}
