#include <climits>
#include <iostream>
#include <cstdint>
#include <algorithm>
int main(){
    uint32_t n;
    std::cin>>n;
    long long res = LONG_LONG_MIN;
    long long sum = 0;
    for(uint32_t i = 0; i < n; i +=1){
        long long x;
        std::cin>>x;
        sum +=x;
        res = std::max(res,sum);
        if(sum < 0){
            sum = 0;
        }
        // std::cout<<i<<" : "<<sum<<" "<<x<<"\n";
    }
    std::cout<<res<<"\n";
    return 0;
}