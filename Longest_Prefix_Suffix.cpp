
 //Longest Prefix which matches the suffix 
 //Time Complexity-O(n)
 // First Step of KMP
 void solve()
 {
    string s;
    cin>>s;
    int n=s.length();
    int LPS[n];
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
    for(int i=0;i<n;i++) cout<<LPS[i]<<" ";    
 }
