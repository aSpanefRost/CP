 //Longest Prefix which matches the suffix 
 //Time Complexity-O(n)
 // First Step of KMP
 int* solve(string s,int LPS[])
 {
    int n=s.length();
    LPS[0]=0;
    int j=0;
    for(int i=1;i<n;i++)
    {
       //if the i-th position and the j-th position matches then increment both i and j
       //and assign (j+1) to the array
       //Basically we are storing the length of largest prefix which is equal to the suffix in the array
       if(s[j]==s[i])
       {
       	 LPS[i]=j+1;
       	 j++;
       }
       else
       {
       	  //If the strings doesn't match then go to previous element of j , and check where 
       	  // the pattern has occured last time 
       	  // Then again start the matching 
       	  bool check=true;
       	  while(j!=0)
       	  {
       	  	 j=LPS[j-1];
       	  	 if(s[j]==s[i])
       	  	 {
       	  	 	LPS[i]=j+1;
       	  	 	j++;
       	  	 	check=false;
       	  	 	break;
       	  	 }
       	  }

       	  if(check) 
       	  {
       	  	//here the j-value is 0
       	  	//if it matches then put 1 in the array otherwise put 0 ; and only increase i , not j
       	  	if(s[j]==s[i]) LPS[i]=j+1;
       	  	else LPS[i]=0;
       	  }

       }
    } 
    // for(int i=0;i<n;i++) cout<<LPS[i]<<" ";    
    return LPS;
 }
 
void KMP()
{
	
	string s="abczabcgabzabcgabcgabcy";
	string p="abczabc";
	int lp=p.length();
	int ls=s.length();
	int arr[lp];
	solve(p,arr);
	// fo(i,lp) cout<<arr[i]<<" ";
	int j=0;
	int i=0;
	while(i<ls&&j<lp)
	{
		//if the string matches with pattern increase both i and j
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{ 
			//if the string doesn't matches with the pattern

			//if j=0 then increase the i value
			if(j==0)
			{
				i++;
			}
			//else decrease the j value to the last occured pattern 
			else
			{
				j=arr[j-1];
				// j=0;
			}
		}
	}
	if(j==lp) cout<<1;
	else cout<<0;
}
