class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr=0,idx=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            curr=curr+gas[i]-cost[i];
            if(curr<0){
                idx=i+1;
                curr=0;
            }
        }
        curr=0;
        for(int i=0;i<n;i++){
            int start=(i+idx)%n;
            curr=curr-cost[start]+gas[start];
            if(curr<0){
                return -1;
            }
        }
        return idx;
    }
};
