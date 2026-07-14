#include<iostream>
#include<cstdint>
#include<cstddef>
#include<vector>
#include <algorithm>
int main(){
    auto cmp =[&](const std::vector<uint32_t> &a,const std::vector<uint32_t> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        else{
            return a[0] < b[0];
        }
    };
    size_t n;
    std::cin>>n;
    std::vector<std::vector<uint32_t>> ranges(n,std::vector<uint32_t>(3));
    
    for(size_t i = 0;i < n;i +=1){
        std::cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2] = i;
    }

    std::vector<uint32_t> res1(n,0);
    std::vector<uint32_t> res2(n,0);

    
    std::sort(ranges.begin(), ranges.end(), cmp);

    uint32_t max_outer_range = 0;
    for(size_t i = 0;i < n;i +=1){
        if(max_outer_range >= ranges[i][1]){
            res2[ranges[i][2]] = 1;
        }
        max_outer_range = std::max(max_outer_range,ranges[i][1]);
    }
    uint32_t min_outer_range = 1e9 + 1;
    for (int i = static_cast<int>(n) - 1; i >= 0; --i) {
        if (min_outer_range <= ranges[i][1]) {
            res1[ranges[i][2]] = 1;
        }
        min_outer_range = std::min(min_outer_range, ranges[i][1]);
    }
    for(auto i:res1){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    for(auto i:res2){
        std::cout<<i<<" ";
    }
    return 0;
}