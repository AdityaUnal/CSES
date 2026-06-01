#include <algorithm>
#include <cstdint>
#include<iostream>
#include<string>


int main(){
    std::string s ;
    std::cin>>s;
    const uint32_t n = s.length();
    uint32_t res = 0,l = 0;
    for(int i = 0;i < n;i +=1){
        if(i == 0 or s[i] != s[i - 1]){
            l = 0;
        }
        l +=1;
        res = std::max(l,res);
    }
    std::cout<<res<<"\n";
    return 0;
}