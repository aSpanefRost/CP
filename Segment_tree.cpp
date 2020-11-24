

//segment tree for range-min query

int arr[100001];  
int st[400001];     //Array to store the segment tree
int lazy[400001];   //Array to store the lazy tree

//Function to buid the tree-- Complexity=O(n)
void buildTree(int si, int ss,int se)
{
   if(ss==se)
   {
     st[si]=arr[ss];
     return;
   }

   int mid=(ss+se)/2;
   buildTree(2*si,ss,mid);
   buildTree(2*si+1,mid+1,se);

   st[si]=min(st[2*si],st[2*si+1]);
}

//Funtion to find the min value in a given range-- Complexity=O(logn)
int query(int si,int ss,int se,int qs,int qe)
{   

    //Extra code fore Lazy propagation-  When range query is not needed
    //remove the following code 
    //*
     if(lazy[si]!=0)
     {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx;
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
     }

     //*/
    if(qe<ss||qs>se)
    {
      return INT_MAX;           //No Overlap
    }
    if(qs<=ss&&qe>=se)
    {
      return st[si];       //Complete Overlap
    }
                           
                           //Partial Overlap
    int mid=(ss+se)/2;
    int l=query(2*si , ss, mid, qs,qe);
    int r=query(2*si+1, mid+1, se, qs , qe);
    return min(l,r);
}


//Funtion to update at a particular position-- Complexity=O(logn)
void point_update(int si, int ss,int se, int qi)
{
  if(ss==se)
  {
    st[si]=arr[ss];  //Update the leaf node 
    return;
  }

  int mid=(ss+se)/2;
  if(qi<=mid) point_update(2*si,ss,mid,qi);
  else point_update(2*si+1,mid+1,se,qi);

  st[si]=min(st[2*si],st[2*si+1]);

}

//Range_update using lazy propagation
//Complexity=O(logn)
void range_update(int si, int ss, int se, int qs, int qe, int val)
{
    //handling pending updates
     

    if(lazy[si]!=0)
     {
        int dx=lazy[si];
        lazy[si]=0;
        st[si]+=dx;
        if(ss!=se)
        {
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
     }
    //No Overlap
    if(qe<ss||qs>se) return;
    
    //Complete Overlap
    if(qs<=ss&&qe>=se)
    {
       int dx=val;
       st[si]+=dx;
       if(ss!=se)
       {
        lazy[2*si]+=val;
        lazy[2*si+1]+=val;
       }
       return;

    }
     
     //partial overlap
    int mid=(ss+se)/2;
    range_update(2*si,ss,mid,qs,qe,val);
    range_update(2*si+1,mid+1,se,qs,qe,val);

    st[si]=min(st[2*si],st[2*si+1]);

}

