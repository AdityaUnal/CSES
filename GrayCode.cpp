#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <bitset>

std::string printBits(uint32_t n,uint32_t num){
    std::string res;
    res.resize(n,'0');
    for(int i = n - 1;i >= 0; i--){
        if((num&(1<<((n-1) - i))) == 1){
            res[i] = '1';
        }
    }
    return res;
}

void f(uint32_t num,uint32_t n,std::bitset<(1<<16)>& v){
    if(v[num] == 1){
        return ;
    }
    std::cout<<printBits(n,num)<<"\n";
    v[num] = 1;
    for(int i = 0;i < n;i +=1){
        f((num|(1<<i)),n,v);
    }
}

int main(){
    uint32_t n;
    std::cin>>n;
    std::bitset<(1<<16)> v;
    f(0,n,v);
}