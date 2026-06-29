#include <iostream>
#include <cstdint>

int main(){
    uint64_t n;
    std::cin>>n;
    uint64_t fives = 0;
    for(int i = 5;i <= n;i +=5){
        uint64_t num = i;
        while((num)%5 == 0){
            fives +=1;
            num = num/5;
        }
    }
    std::cout<<fives<<"\n";
    return 0;
}