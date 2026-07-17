/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
*/

#include <algorithm>
#include <cstdint>
#include<vector>
#include <iostream>

uint32_t MOD = 1e9 + 7;

int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<uint32_t> arr(n + 1,0);
    arr[0] = 1;
    for(int i = 1;i <= n;i +=1){
        for(int j = 1;j <=std::min(6,i);j +=1){
            arr[i] = (arr[i] + arr[i - j])%MOD;
        }
        // std::cout<<arr[i]<<"\n";
    }
    std::cout<<arr[n]<<"\n";
    return 0;
}