class Solution {
public:
    void mergesort(vector<int>& nums,int s,int e){
    if(s<e){
        int mid=(s+e)/2;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,e);
        merge(nums,s,mid,e);
   }

  }

int merge(vector<int>& nums,int s,int mid,int e){
        
       int size=e-s+1;
       int temp[size];
        int i=s,j=mid+1,k=0;
        
        while(i<=mid&&j<=e){
         if(nums[i]<=nums[j])
             temp[k++]=nums[i++];
         else
             temp[k++]=nums[j++];
        }
        while(i<=mid)  
            temp[k++]=nums[i++];
        while(j<=e)
            temp[k++]=nums[j++];
    
      i=s,k=0;
      for(i=s;i<e+1;i++){
        nums[i]=temp[k++];
      }
        
     return 0;
}

vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
