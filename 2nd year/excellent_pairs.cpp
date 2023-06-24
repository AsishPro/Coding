int bits(int s){
    int b=0;
    while(s!=0){
       if(s%2==1)
       b++;
       s=s/2;
    }
    return b;
}

class Solution {
public:
   
    long long countExcellentPairs(vector<int>& nums, int k){
        
        unordered_set<int>s(nums.begin(),nums.end());
        
        vector<int>nums2;
        
        vector<int>::iterator itr;
        for(auto itr=s.begin();itr!=s.end();itr++){
           nums2.push_back(*itr);
        }
        sort(nums2.begin(),nums2.end());
        
      // for(int i=0;i<s.size();i++){
      //  cout<<nums2[i]<<' ';
      // }
        
//         //removing duplicates
//         int x=0,c[100];
        
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]!=nums[i+1]){
//                 c[x]=nums[i];
//                 x++;
//             }        
//         }
     long long int count=0; 
      
     for(int i=0;i<nums2.size();i++){
         for(int j=0;j<nums2.size();j++){
            if(bits(nums2[i])+bits(nums2[j])>=k)
             count++;
         }   
     }
    
    //  for(int i=0;i<nums2.size();i++){
    //     for(int j=0;j<nums2.size();j++){
    //     if(bits(nums2[i])+bits(nums2[j])>=k){
    //         //printf("%d %d\n",nums2[i],nums2[j]);
    //           count++;
    //        }
    //     }
    // }
    
    return count;
    }
};