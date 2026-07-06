#include<vector>
#include <iostream>
#include <cstdint>
#include <cstddef>
#include <map>

int main(){
    size_t n;
    std::cin>>n;
    uint64_t res = 0;
    size_t l = 0,i = 0;
    std::map<uint64_t,size_t> mp;
    while(n){
        uint64_t x;
        std::cin>>x;
        auto itr = mp.find(x);
        if(itr != mp.end() and itr->second + 1 > l){
            l = itr->second + 1;
        }
        // std::cout<<l<<"\n";
        res += i - l + 1;
        mp[x] = i;
        i +=1;
        n--;
    }
    std::cout<<res<<"\n";
    return 0;
}