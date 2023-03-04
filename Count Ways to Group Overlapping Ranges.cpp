class Solution {
public:
    int power(int i,int j,int p){
    if(j==0){
        return 1;
    }
    if(j==1){
        return i;
    }
    long long  ans=power(i,j/2,p);
    ans=(ans*ans)%p;
    if(j%2==1){
        ans=(ans*i)%p;
    }
    return ans;
}
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        vector<vector<int>> ans;
        for(auto &i: ranges){
            if(ans.size()==0 or ans.back()[1]<i[0]){
                ans.push_back(i);
            }
            else{
                ans.back()[1]=max(ans.back()[1],i[1]);
            }
        }
        // long long ans=0;
        int sz=ans.size();
        return power(2,sz,1e9+7);
        
    }
};
