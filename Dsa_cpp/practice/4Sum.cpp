#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;


vector<vector<int>> optimalsol(vector<int> &nums,int target){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i!=0 &&nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){

            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum< target) k++;
                else{
                    l--;
                }
            }
        }
    }
    return ans;

}

vector<vector<int>> bruteforce(vector<int> &nums,int target)
{
    set<vector<int>> st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
     vector<vector<int>> ans(st.begin(), st.end());
    return ans;
   
}
int main()
{
    vector<int> nums = {-2, 1, 2, -1, 1, 0,-4};
    // vector<vector<int>> ans =bruteforce(nums,0);
    vector<vector<int>> ans =optimalsol(nums,0);
    for(auto row: ans){
        cout<<'[';
        for(auto col: row){
                cout<<col<<" ";

        }
        cout<<"]";
    }
    cout<<"\n";
    return 0;
}