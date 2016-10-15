class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        string s_re, s_tmp;
        for(const auto &c : s)
        {
            // Char is not in the substring.
            if (s_tmp.find(c) == std::string::npos)
            {
                s_tmp += c;
            }
            else
            {
                s_re = (s_tmp.size() > s_re.size())? s_tmp : s_re;
                // Skip from not repeating char.
                s_tmp = s_tmp.substr(s_tmp.find(c) + 1);
                s_tmp += c;
            }
        }
        
        // Nerver repeating or subtring at tail.
        return max(s_re.size(), s_tmp.size());
    }
};
