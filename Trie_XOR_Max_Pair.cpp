//The Naive method is to generate all the pairs and take xor and filter the max out of them
// But the Naive method would take O(n^2)

//If we try to solve the problem using Trie data structure this would significantly decrease the complexity
//The insert would take Nlog(Max)
//The Max pair would also take Nlog(Max)

typedef struct trieNode trieNode; 

struct trieNode
{
	trieNode* left;
	trieNode* right;
};

//head is the top node of the trie data structure
void insert(trieNode* head,int val)
{
	trieNode* curr=head;
    for(int i=31;i>=0;i--)
    {
    	int bit=(val>>i)&1;  //the i-th bit
    	if(bit==0)
    	{
           if(curr->left==NULL)    //if the the node doesn't exist then create a node
           {
           	 trieNode* node=new trieNode;
           	 curr->left=node;
           	 curr=node;
           	 
           }
           else
           {
           	curr=curr->left;
           }
           
    	}
    	else
    	{
    		if(curr->right==NULL)
    		{
    			trieNode* node=new trieNode;
    			curr->right=node;
    			curr=node;
    			
    		}
    		else 
    		{
    			curr=curr->right;
    		}
    	}
    }
}

int findMaxXorPair(trieNode* head,int arr[],int n)
{
	int maxXorPair=INT_MIN;
	int bit;
	trieNode* curr;
	int temp;
	int val;
	for(int i=0;i<n;i++)
	{
        curr=head;
        val=arr[i];  //we are taking one value and checking what could be the other element so that their xor results into max value
        temp=0;
        for(int j=31;j>=0;j--)
        {
           bit=(val>>j)&1;
           if(bit==0)
           {
           	   if(curr->right)  
           	   {
                  temp+=pow(2,j);  //if there's exists the counter value so the bitwise xor would be one and this would contribute 2^j to the value
                  curr=curr->right;
           	   }
           	   else
           	   {
           	   	 curr=curr->left;
           	   }
           }
           else
           {
           	   if(curr->left)
           	   {
           	   	 temp+=pow(2,j);
           	   	 curr=curr->left;
           	   }
           	   else
           	   {
           	   	 curr=curr->right;
           	   }
           }
        }
        if(maxXorPair<temp) maxXorPair=temp;
	}
	return maxXorPair;
	
}

void solve()
{
	trieNode *head=new trieNode();
	int arr[6]={8,1,2,15,10,5};
	for(int i=0;i<6;i++)
	{
		insert(head,arr[i]);
	}
	cout<<findMaxXorPair(head,arr,6);

}
