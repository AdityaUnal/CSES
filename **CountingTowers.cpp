#include<cstddef>
#include<cstdint>
#include<iostream>
#include<vector>

#define MOD 1000000007
int main(){
    uint64_t t;
    std::cin>>t;
    std::vector<uint64_t> joined(1e6 + 1,-1);
    std::vector<uint64_t> seperate(1e6 + 1,-1);
    std::vector<uint64_t> dp(1e6 + 1,-1);
    joined[1] = 1;
    seperate[1] = 1;
    dp[1] = 2;
    // std::vector<uint64_t> seperate(1e6 + 1,-1);
    uint64_t height = 1;
    while(t){
        uint64_t n;
        std::cin>>n;
        if(dp[n] == -1){
            for(auto i = height + 1;i <= n;i +=1){
                joined[i] = (((2*joined[i - 1])%MOD) + seperate[i - 1])%MOD; 
                seperate[i] = (((4*seperate[i - 1])%MOD) + joined[i - 1])%MOD; 
                dp[i] = (joined[i] + seperate[i])%MOD;
                // std::cout<<i<<" : "<<dp[i]<<"\n";
            }
        }
        std::cout<<dp[n]<<"\n";
        height = n;
        t--;
    }
    return 0;
}