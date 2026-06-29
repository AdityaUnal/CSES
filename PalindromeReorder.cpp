#include <iostream>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

int main(){
    std::string s;
    std::cin>>s;
    uint32_t n = s.length();
    std::vector<uint32_t> v(26,0);
    for(auto i:s){
        v[i - 'A'] +=1;    } 
    uint32_t odd = 0;
    for(auto i :v){
        // std::cout<<i<<"\n";
        if(i%2){
            odd +=1;
            if(odd > 1){
                std::cout<<"NO SOLUTION"<<"\n";
                return 0;
            }
        }
    }
    std::unordered_map<int, char> mp;
    for(int i = 0;i < 26;i +=1){
        mp[i] = i +'A';
    }
    std::string res;
    res.resize(n);
    int odd_char = -1;
    uint32_t k = 0;
    for(int i  = 0 ;i < 26;i +=1){
        while(v[i] >= 2){
            res[k] = mp[i];
            res[n - k - 1] = mp[i];
            v[i] = v[i] - 2;
            k +=1;
        }
        if(v[i] == 1){
            if(odd_char != -1){
                std::cout<<"NO SOLUTION"<<"\n";
            }
            odd_char = i;
        }
    }
    if(odd_char != -1){
        res[k] = mp[odd_char];
    }
    std::cout<<res<<"\n";

    return 0;
}
