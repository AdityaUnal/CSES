#include<vector>
#include<cstdint>
#include<cstddef>
#include<iostream>
#include<map>
#include<algorithm>
int main(){
    size_t n;
    std::cin>>n;
    uint32_t l = 0;
    std::map<uint32_t, uint32_t> mp;
    uint32_t res = 0;
    for(uint32_t i = 0;i < n;i +=1){
        uint32_t k;
        std::cin>>k;
        auto itr = mp.find(k);
        if(itr!=mp.end()){
            l = std::max(itr->second + 1,l);
        }
        mp[k] = i;
        res = std::max(res,i - l + 1);
        // std::cout<<l<<" "<<i<<" "<<res<<"\n";
    }
    std::cout<<res<<"\n";
    return 0;
}