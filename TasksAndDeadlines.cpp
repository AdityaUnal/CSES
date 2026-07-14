/*
You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
Input
The first input line has an integer n: the number of tasks.
After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.
Output
Print one integer: the maximum reward.
*/

#include <algorithm>
#include <cstddef>
#include<iostream>
#include <utility>
#include<vector>
#include<cstdint>

int main(){
    uint32_t n;
    std::cin>>n;
    std::vector<std::vector<uint32_t>> tasks(n,std::vector<uint32_t>(2));
    for(size_t i = 0;i < n;i +=1){
        std::cin>>tasks[i][0]>>tasks[i][1];
    }
    std::sort(tasks.begin(),tasks.end());
    long long res = 0;
    long long time = 0;
    for(auto v:tasks){
        time +=v[0];
        res += v[1] - time; 
    }
    std::cout<<res<<"\n";
    return 0;
}