// Kadane Algorithm
// It gives us the Largest sum contiguous sub-array of the given array.
// In Brute force approach, it will take O(n^2) time.
// But we can Easily do this in O(n) time using Kadane's Algorithm

int kadane(int arr[],int n)
{
   int local_maximum=arr[0];      
   int gloabl_maximum=arr[0];
   int temp;
   for(int i=1;i<n;i++)
   { 
    temp=local_maximum+arr[i];
    local_maximum=max(arr[i],temp);
    if(local_maximum>gloabl_maximum) gloabl_maximum=local_maximum;

   }
   return gloabl_maximum;
}
