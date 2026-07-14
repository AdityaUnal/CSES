/*
Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.
Range [a,b] contains range [c,d] if a \le c and d \le b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) how many other ranges it contains.
Then print a line that describes for each range (in the input order) how many other ranges contain it.

*/

#include<iostream>
#include<cstdint>
#include<cstddef>
#include<vector>
#include <algorithm>
#include<set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

int main(){
    auto cmp =[&](const std::vector<uint32_t> &a,const std::vector<uint32_t> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        else{
            return a[0] < b[0];
        }
    };
    size_t n;
    std::cin>>n;
    std::vector<std::vector<uint32_t>> ranges(n,std::vector<uint32_t>(3));
    
    for(size_t i = 0;i < n;i +=1){
        std::cin>>ranges[i][0]>>ranges[i][1];
        ranges[i][2] = i;
    }

    std::vector<uint32_t> res1(n,0);
    std::vector<uint32_t> res2(n,0);

    ordered_set<std::pair<uint32_t,uint32_t>> my_set;
    std::sort(ranges.begin(), ranges.end(), cmp);

    uint32_t timer = 1e9 + 1;
    for(size_t i = 0;i < n;i +=1){
        res2[ranges[i][2]] = my_set.size() - my_set.order_of_key({ranges[i][1],0});
        my_set.insert({ranges[i][1],timer--});
    }
    my_set.clear();
    uint32_t min_outer_range = 1e9 + 1;
    for (int i = static_cast<int>(n) - 1; i >= 0; --i) {
        res1[ranges[i][2]] = my_set.order_of_key({ranges[i][1],UINT32_MAX});
        my_set.insert({ranges[i][1],timer++});
    }
    for(auto i:res1){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    for(auto i:res2){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
    return 0;
}