/*
In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members, who will be all attending the festival.
You know the starting and ending time of each movie. What is the maximum total number of movies the club members can watch entirely if they act optimally?
Input
The first input line has two integers n and k: the number of movies and club members.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending time of a movie.
Output
Print one integer: the maximum total number of movies.
*/

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

int main(){
    size_t n,k;
    std::cin>>n>>k;
    std::vector<std::pair<uint32_t, uint32_t>> movie_timings(n);//price of each ticket.
    // std::vector<int> end(n);
    for(int i = 0;i < n;i +=1){
        std::cin>>movie_timings[i].first>>movie_timings[i].second;
    }
    auto cmp = [&](const std::pair<uint32_t, uint32_t> a,const std::pair<uint32_t, uint32_t> b){ return a.second < b.second;};
    std::sort(movie_timings.begin(),movie_timings.end(),cmp);
    // std::vector<std::pair<int,int>> movies(n);//price of each ticket.
    int count = 0;
    std::multiset<uint32_t> end_time;
    for (size_t i = 0; i < k; ++i) {
        end_time.insert(0);
    }
    // int count = 0;
    for (const auto& [start, end] : movie_timings) {
        auto itr = end_time.upper_bound(start);
        if (itr == end_time.begin()) {
            continue;  // nobody free
        }
        --itr;  // latest free time ≤ start
        end_time.erase(itr);
        end_time.insert(end);
        ++count;
    }
    std::cout<<count<<"\n";
    return 0;
}