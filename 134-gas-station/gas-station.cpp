class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        for(int i=0; i<gas.size(); i++){
            gas[i]=gas[i]-cost[i];
            sum+=gas[i];
        }
        if(sum<0) return -1;
        int i=0;
        int j=1; 
        int cnt=gas[0];
        while(i!=j && gas.size()>1){
          while(cnt<0){
              cnt-=gas[i];
              i++;
              if(i==j)break;
          }
          cnt+=gas[j];
          j++;
          if(j==gas.size()) j=0;
        }
        return i; 
    }
};