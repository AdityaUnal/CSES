#include <iterator>
#include<map>
#include<set>
#include<cstdint>
#include<iostream>
#include<cstddef>

int main(){
    size_t x,n;
    std::cin>>x>>n;
    std::set<uint32_t> light;
    std::map<uint32_t,uint32_t> distance_count;
    light.insert(x);
    light.insert(0);
    distance_count[x] = 1;
    while(n){
        uint32_t p;
        std::cin>>p;
        auto upper_bound = light.upper_bound(p);
        auto lower_bound = std::prev(upper_bound);
        uint32_t removed_distance = *upper_bound - *lower_bound;
        distance_count[removed_distance]--;
        if(distance_count[removed_distance] == 0){
            distance_count.erase(removed_distance);
        }
        auto distance_from_lower = p - *lower_bound;
        auto distance_from_upper = *upper_bound - p;
        distance_count[distance_from_lower] +=1;
        distance_count[distance_from_upper] +=1;
        light.insert(p);

        std::cout<<distance_count.rbegin()->first<<"\n";
        n--;
    }
    return 0;
}