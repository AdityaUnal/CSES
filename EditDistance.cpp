#include <cstdlib>
#include <string>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>

int LongestCommonSubsequence(std::string &s,std::string &t){
    int rows = s.length();
	int cols = t.length();
	std::vector<int> prev(cols,0);

	for(int i=0;i<rows;i++)
	{
		std::vector<int> curr(cols,0);
		curr[0] = prev[0];
		if(t[0] == s[i]){
            curr[0] = 1;
        }

		for(int j = 1;j<cols;j++)
		{
			if(t[j]==s[i])
			curr[j] = 1 + prev[j-1];
			else
			curr[j] = std::max(curr[j-1],prev[j]);
		}
		prev = curr;
	}
	return prev[cols - 1];
}

int main(){
    std::string word_one;
    std::string word_two;
    std::cin>>word_one;
    std::cin>>word_two;
    int common_substring_length = LongestCommonSubsequence(word_one, word_two);
    // std::cout<<common_substring_length<<"\n";
    int n = static_cast<int>(word_one.length());
    int m = static_cast<int>(word_two.length());
    int res = std::max(n - common_substring_length,(m - common_substring_length));
    res += abs(n - m);
    std::cout<<res<<"\n";
    return 0;
}