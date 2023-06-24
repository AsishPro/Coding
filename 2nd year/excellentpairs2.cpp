int bits(int s){
    int b=0;
    while(s!=0){
       //if(s%2==1)
       b=b+(s%2);
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
            
           nums2.push_back(bits(*itr));
        }
        sort(nums2.begin(),nums2.end());
       
        long long int count=0;
   
     
     for(int i=0;i<nums2.size();i++){
         for(int j=0;j<nums2.size();j++){
            if(nums2[i]+nums2[j]>=k)
             count++;
         }   
     }
    
   
    
    return count;
    }
};