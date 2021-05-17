//As there is a duplicate number  , the linked list using the indexs and values and then the values will become index ....
//The index will create a circle
//As there is a circle then , we can use the tortoise method
//Tortoise method will help use finding the duplicate

//Tortoise mehod ::
//The idea behind the algorithm is that, if you have two pointers in a linked list, one moving twice as fast (the hare) than the other (the tortoise), 
//then if they intersect, there is a cycle in the linked list. If they don't intersect, then there is no cycle
int findDuplicate(vector<int>& nums) 
    {
       int fast=nums[0];
       int slow=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
