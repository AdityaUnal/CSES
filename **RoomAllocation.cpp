/*
There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid solution.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a \le b \le 10^9
*/
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> customers(n);
  for (int i = 0; i < n; ++i) {
    int arrival = 0;
    int departure = 0;
    std::cin >> arrival >> departure;
    customers[i] = {arrival, departure, i};
  }

  std::sort(customers.begin(), customers.end());

  std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> occupied;
  std::vector<int> res(n,-1);
  int max_rooms = 0;
  // res[std::get<2>(customers[0])] = max_rooms;
  int departed_customer = 0;
  int i = 0;
  while(i < n){
    int arrival = customers[i][0];
    int departure = customers[i][1];
    int idx = customers[i][2];

    if(!occupied.empty() and occupied.top().first < arrival){
      int room = occupied.top().second;
      occupied.pop();
      res[idx] = room;
      occupied.push({departure, room});
    } else {
      ++max_rooms;
      res[idx] = max_rooms;
      occupied.push({departure, max_rooms});
    }
    
    i +=1;
  }
  std::cout<<max_rooms<<"\n";
  for(int j : res){
    std::cout<<j<<" ";
  }
  std::cout<<"\n";
  return 0;
}
