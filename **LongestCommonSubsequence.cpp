#include <cstdlib>
#include <string>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>

std::vector<uint32_t> LongestCommonSubsequence(std::vector<uint32_t> &a,std::vector<uint32_t> &b){
    int rows = a.size();
	int cols = b.size();
	std::vector<std::vector<uint32_t>> prev(cols);
    
	for(int i = 0;i<rows;i++)
	{
        std::vector<std::vector<uint32_t>> curr(cols);
        curr[0] = prev[0];
		if(b[0] == a[i]){
            if(curr[0].size() == 0){
                curr[0].push_back(a[i]);

            }
        }

		for(int j = 1;j<cols;j++)
		{
			if(b[j]==a[i]){
                curr[j] = prev[j-1];
                curr[j].push_back(a[i]);
                // std::cout<<"Hello"<<"\n";
            }
			else{
                auto len_curr_arr = curr[j -1 ].size();
                auto len_prev_arr = prev[j].size();
                if(len_curr_arr == len_prev_arr){
                    if(len_curr_arr == 0){
                        continue;
                    }
                    if(curr[j - 1][len_curr_arr - 1] > prev[j][len_prev_arr - 1]){
                        curr[j] = prev[j];
                    }
                    else{
                        curr[j] = curr[j - 1];
                    }
                }
                else if(len_curr_arr > len_prev_arr){
                    curr[j] = curr[j - 1];
                }
                else{
                    curr[j] = prev[j];
                }

            }
			// curr[j] = std::max(curr[j-1],prev[j]);
		}
		prev = curr;
	}
	return prev[cols - 1];
}

int main(){
    size_t n,m;
    std::cin>>n;
    std::cin>>m;
    std::vector<uint32_t> a(n);
    std::vector<uint32_t> b(m);
    // std::string word_two;
    for(size_t i = 0;i < n;i++){
        std::cin>>a[i];
    }
    for(size_t i = 0;i < m;i++){
        std::cin>>b[i];
        // std::cin>>a[i];
    }
    // std::cout<<"Hello"<<"\n";
    auto res =  LongestCommonSubsequence(a, b);
    // std::cout<<common_substring_length<<"\n";
    // std
    std::cout<<res.size()<<"\n";
    for(auto i:res){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    return 0;
}