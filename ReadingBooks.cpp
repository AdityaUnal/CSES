#include <iostream>
#include <vector>
#include <cstdint>
#include<algorithm>
int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<uint64_t> v(n);
    for(int i = 0;i < n ;i +=1){
        std::cin>>v[i];
    }
    uint64_t res = 0;
    std::sort(v.begin(),v.end());
    // uint64_t res = 0;
    for(int i = 0;i < n - 1;i +=1){
        res +=v[i];
    }
    if(res < v[n - 1]){
        res = v[n - 1]*2;
    }
    else{
        res += v[n - 1];
    }
    // res = res*2;
    // if(low == high){
    //     res +=sum_high;
    // }
    // if(low == high){
    //     res +=
    // }
    std::cout<<res<<"\n";
    return 0;
}