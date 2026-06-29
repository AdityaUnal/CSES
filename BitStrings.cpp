#include <iostream>
#include <cstdint>

#define MOD static_cast<uint64_t>(1e9 + 7)

int main(){
    uint64_t n = 0;
    std::cin>>n;
    uint64_t res = 1;
    while(n){
        res = (res * 2)%MOD;
        n--;
    }
    std::cout<<res<<"\n";
    return 0;
}