#include <cstdint>
#include <vector>
#include <iostream>

int main(){
    uint64_t n;
    std::cin>>n;
    uint64_t sum_n = n*(n + 1)/2;
    if(sum_n%2){
        std::cout<<"NO"<<"\n";
        return 0;
    }
    std::cout<<"YES"<<"\n";
    if(n%2){
        std::cout<<(n/2 + 1)<<"\n";
        for(int i = 1;i <= n/2;i +=2){
            std::cout<<i<<" "<<(n - i)<<" ";
        }
        std::cout<<"\n"<<(n/2)<<"\n";
        for(int i = 2;i < n/2;i +=2){
            std::cout<<i<<" "<<(n - i)<<" ";
        }
        std::cout<<n;
        return 0;
    }
    std::cout<<(n/2)<<"\n";
    for(int i = 1;i < n/2;i +=2){
        std::cout<<i<<" "<<(n - i + 1)<<" ";
    }
    std::cout<<"\n"<<(n/2)<<"\n";
    for(int i = 2;i <= n/2;i +=2){
        std::cout<<i<<" "<<(n - i + 1)<<" ";
    }

    return 0;
}