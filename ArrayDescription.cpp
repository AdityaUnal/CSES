#include <algorithm>
#include <vector>
#include <iostream>
#include <cstddef>
#include <cstdint>
#define MOD 1000000007
int main(){
    size_t n;
    uint32_t m;
    std::cin>>n>>m;
    std::vector<uint32_t> counts(m + 1,0);
    uint32_t last_element ;
    for(size_t i = 0;i < n;i +=1){
        std::vector<uint32_t> curr(m + 1,0);
        uint32_t x;
        std::cin>>x;
        if(x == 0){
            if(i == 0){
                for(auto j = 0;j <= m;j +=1){
                    curr[j] = 1;
                }
            }
            else{
                for(auto j = 1;j <= m;j +=1){
                    if(j!=1){
                        curr[j - 1] = (curr[j - 1] + counts[j])%MOD;
                    }
                    curr[j] = (curr[j] + counts[j])%MOD;
                    if(j!=m){
                        curr[j + 1] = (curr[j + 1] + counts[j])%MOD;
                    }
                }
            }
        }
        else{
            if(i == 0){
                counts[x] = 1;
            }
            curr[x] = counts[x];
            curr[x] = (curr[x] + counts[x - 1])%MOD;
            if(x!=m){
                curr[x] = (curr[x] + counts[x + 1])%MOD;
            }
        }
        counts = curr;
        if(i == n - 1){
            last_element = x;
        }
    }
    uint32_t res = 0;
    if(last_element == 0){
        for (auto i = 1; i <= m; i +=1) {
            res = (res + counts[i])%MOD;
        }
    }
    else{
        res = counts[last_element];
    }
    std::cout<<res<<"\n";
    return 0;
}