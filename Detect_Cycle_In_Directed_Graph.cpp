//We will use DFS to detect Cycle in an Directed Graph

//(White Node) visited[id]=0 is used for node which is not yet visited
//(Grey Node) visited[id]=1 is used for the node which is visited and currently its child nodes are being visited and 
//(Black Node) visited[id]=2 done when all the child nodes of a node ("id") are visited and the function returns to parent node of node ("id").
// So at that time it is marked as 2 because this node does not require any further traversing.


  //false->contains a cycle . True-> Does not contain a cycle
    bool isCycle(int i,vector<int> ar[],vector<int>& visited) 
    {
        if(visited[i]==1)
        {
            return false;
        }
        if(visited[i]==0)
        {
            visited[i]=1;
            for(auto x:ar[i])
            {
                int b=isCycle(x,ar,visited);
                if(!b) return false;
            }
        }
        visited[i]=2;
        return true;
    }


//  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> ar[numCourses];
//         for(int i=0;i<prerequisites.size();i++)
//         {
//             ar[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
//         vector<int> visited(numCourses,0);
//         for(int i=0;i<numCourses;i++)
//         {
//             if(visited[i]==0)
//             {
//                 int a=isCycle(i,ar,visited);
//                 if(!a) return false;
//             }
//         }
//         return true;
//     }
