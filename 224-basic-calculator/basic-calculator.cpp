class Solution {
public:
    long long calculate(string s) {
        stack<long long> st;

        long long num=0;
        long long ans=0;
        long long sign=1;

        for (auto it: s){
            if (isdigit(it)){
                num=(num*10)+(it-'0');
            }
            else if (it=='-'){
                ans+=(num*sign);
                sign=-1;
                num=0;
            }
            else if (it=='+'){
                ans+=(num*sign);
                sign=1;
                num=0;
            }
            else if (it=='('){
                st.push(ans);
                ans=0;
                st.push(sign);
                num=0;
                sign=1;
            }
            else if (it==')') {
                ans+=(num*sign);
                num=0;
                ans*=st.top();
                st.pop();
                ans+=st.top();
                st.pop();
            }
        }
        ans+=(num*sign);
        return ans;
    }
};