#include <algorithm>
#include <set>
#include <utility>
#include<vector>
#include<iostream>
#include<cstddef>
#include<cstdint>

int main(){
    size_t n;
    std::cin>>n;
    std::vector<uint32_t> arr(n);
    std::multiset<uint32_t> s;
    uint32_t res = 0;
    
    for(size_t i = 0;i < n;i +=1){
        uint32_t k;
        std::cin>>k;
        auto upper_bound = s.upper_bound(k);
        if(upper_bound == s.end()){
            res +=1;
        }
        else{
            s.erase(upper_bound);
        }
        s.insert(k);
    }
    // std::sort(temp.begin(),temp.end());
    // size_t l = 0;
    // for(size_t i = 1;i < n;i +=1){
    //     std::cout<<" l ="<<l<<" i = "<<i;
    //     if(temp[i].second > temp[l].second){
    //         std::cout<<" res";
    //         res += 1 ;
    //     }
    //     else{
    //         std::cout<<" l";
    //         l +=1;
    //     }
    //     std::cout<<"\n";
    // }
    std::cout<<res<<"\n";
    return 0;
}