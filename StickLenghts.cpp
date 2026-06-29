#include <algorithm>
#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <cstdlib>
int main(){
    uint32_t n;
    uint64_t sum = 0;
    std::cin>>n;
    std::vector<long long> p(n);
    for(uint32_t i = 0;i < n;i +=1){
        // uint64_t x;
        std::cin>>p[i];
    }
    std::sort(p.begin(),p.end());
    long long median = (n%2) ? p[n/2]:((p[n/2] +p[(n-1)/2])/2); 
    uint64_t changes = 0;
    // std::cout<<median<<"\n";
    for(uint32_t i = 0;i < n;i +=1){
        // uint64_t x;
        changes += std::llabs(median - p[i]);
        
    }
    std::cout<<changes<<"\n";
    return 0;
}