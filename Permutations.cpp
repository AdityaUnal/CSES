#include <cstdint>
#include <iostream>

int main(){
    uint32_t n = 0;
    std::cin>>n;
    if(n == 3 or n == 2){
        std::cout<<"NO SOLUTION"<<"\n";
        return 0;
    }
    for(int i = n - 1;i >= 1;i = i - 2){
        std::cout<<i<<" ";
    }
    for(int i = n ;i >= 1;i = i - 2){
        std::cout<<i<<" ";
    }
    return 0;
}