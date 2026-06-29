#include <algorithm>
#include <cstdint>
#include <string>
#include <iostream>
#include <utility>
#include <vector>

uint32_t factorial(int n){
    uint32_t res = 1;
    for(int i = n;i > 0;i--){
        res = res * i;
    }
    return res;
}

bool nextPermutation(std::string& s,std::string& og_string,uint32_t n){
    int i = n - 2;
    while(i >= 0){
        if(s[i + 1] > s[i]){
            uint32_t idx = 9;
            char to_swap = 123;
            for(int j = i +1;j < n;j +=1){
                if(s[i] < s[j] && to_swap > s[j]){
                    to_swap = s[j];
                    idx = j;                   
                }
            }
            if(idx!=9){
                std::swap(s[idx],s[i]);
            }
            break;
        }
        i--;
    }
    sort(s.begin() + i + 1,s.end());
    if(s == og_string){
        return false;
    }
    std::cout<<s<<"\n";
    return true;
}
    
int main(){
    std::string s;
    std::cin>>s;
    uint32_t n = s.length();
    std::vector<uint32_t> v(26,0);
    for(auto i:s){
        v[i -'a'] +=1;
    }
    uint32_t possible_permutations = factorial(n);
    for(int i:v){
        possible_permutations = possible_permutations/factorial(i);
    }
    std::cout<<possible_permutations<<"\n";
    std::sort(s.begin(),s.end());
    auto og_string = s;
    std::cout<<s<<"\n";
    while (true){
        if(!nextPermutation(s,og_string,n)){
            break;
        } 
    }
    return 0;
}