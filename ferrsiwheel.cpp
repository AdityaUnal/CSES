#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
int main(){
    uint32_t n,x;
    std::cin>>n>>x;
    std::vector<uint32_t> p(n);
    for(uint32_t i = 0;i < n;i +=1){
        std::cin>>p[i];
    }
    std::sort(p.begin(),p.end());
    uint32_t i = 0;
    uint32_t j = n - 1;
    uint32_t res = 0;
    while( i < j){
        if(p[i] + p[j] <= x){
            i +=1;
        }
        j--;
        res +=1;
    }
    if(i == j){
        res +=1;
    }
    std::cout<<res<<"\n";
    return 0;
}