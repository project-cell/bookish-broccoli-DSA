class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size(), i=0;
        stack<int> st;
        while(i<n){
            if (st.empty() || st.top()!=s[i])
            st.push(s[i]);
            else
            st.pop();
        i++;
        }
        string ans="";
        while(!st.empty()){
            char a=st.top();
            st.pop();
            ans+= a;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};