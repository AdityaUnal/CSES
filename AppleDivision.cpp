#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
# include <iostream>
# include <bitset>
#include <cstdint>
#include <vector>

const uint64_t max_bitset_size = (1<<20);

long long minDifference(std::vector<uint32_t>& p,uint32_t n){
    // std::bitset<20> flags;
    long long res = LONG_LONG_MAX;
    uint64_t combinations = 0;
    while(combinations < (1ULL<<n)){
        long long sum_zero = 0;
        long long sum_one = 0;

            for(int k = 0;k < n;k +=1){
                if(combinations & (1ULL<<k)){
                    sum_one +=p[k];
                }
                else{
                    sum_zero +=p[k];

                }
            }
        combinations +=1;
        // std::cout<<" "<<combinations<<" : "<<sum_one<<" "<<sum_zero<<"\n";
        // flags.set(combinations) ;
        res = std::min(static_cast<long long>(std::abs(sum_one - sum_zero)),res);
    }
    return res;
}

int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<uint32_t> p(n);
    for(int i = 0;i < n;i++){
        std::cin>>p[i];
    }
    std::cout<<minDifference(p,n)<<"\n";
}