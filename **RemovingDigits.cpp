/*
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
*/
#include<iostream>
#include<cstddef>
#include <cstdint>
#include<vector>

uint32_t greatestDigit(uint32_t num){
    uint32_t res = 0;
    while(num){
        res = std::max(num%10,res);
        num = num/10;
    }
    return res;
}

int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<uint32_t> dp(n + 1,0);
    // uint32_t res = 0;
    for(size_t i = 1;i <= n; i+= 1){
        dp[i] = dp[i - greatestDigit(i)] + 1;
        // if(n == i){
        //     break;
        // }
        // if(n < i){
        //     res--;
        //     break;
        // }
        // std::cout<<i<<" "<<res<<"\n";
        // res +=2;
    }
    std::cout<<dp[n]<<"\n";
    return 0;
}