class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int all=m+n;
        if(m==0){
            if(n%2==0){
                double i=nums2[(n/2)-1];
                double j=nums2[n/2];
                double med=(i+j)/2;
                return med;
            }
            else{
                double med=nums2[n/2];
                return med;
            }
        }
        if(n==0){
            if(m%2==0){
                double i=nums1[(m/2)-1];
                double j=nums1[m/2];
                double med=(i+j)/2;
                return med;
            }
            else{
                double med=nums1[m/2];
                return med;
            }
        }
        vector<int> nums(all);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums.begin());
        if(all % 2==0){
            
            double i=nums[(all/2)-1];
            double j=nums[all/2];
            double med=(i+j)/2;
            return med;
          
        }
        double med=nums[all/2];
        return med; 
    }
};