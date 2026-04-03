class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        stack<int> st;
        for (auto it: s){
            int val=0;
            if(it=='('){
                st.push(0);
            }
            else {
                while(st.top()!=0){
                    val+=st.top();
                    st.pop();
                }
                if (val == 0) 
                    val = 1;
                else
                    val = 2 * val;
                st.pop();
                st.push(val);
            }
        }
        while (!st.empty()){
            int node=st.top();
            score+=node;
            st.pop();
        }
        return score;
    }
};