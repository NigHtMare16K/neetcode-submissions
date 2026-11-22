class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for(string ch : strs) {
            ans += to_string(ch.size());
            ans += "#";

            for(int j = 0; j < ch.size(); j++) {
                ans += ch[j];
            }
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        for(int i = 0; i < s.size(); ) {

            string num = "";

            while(s[i] != '#') {
                num += s[i];
                i++;
            }

            int n = stoi(num);
            i++; // Skip '#'

            string b = "";
            int count = 0;
            int j = i;

            while(count < n) {
                b += s[j];
                j++;
                count++;
            }

            ans.push_back(b);
            i = j;
        }

        return ans;
    }
};
