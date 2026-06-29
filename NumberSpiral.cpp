# include<iostream>
# include<cstdint>

uint64_t numberAt(const uint64_t x,const uint64_t y){
    //odd Column
    if(y%2){
        //odd row
        if(x%2){
            if(x<=y){
                return (y*y - x + 1);
            }
            return ((x*x - x + 1) - (x - y));
        }
        //even row
        if(x < y){
            return ((y*y - x + 1));
        }
        return ((x*x - y + 1));
    }
    //even column
    //odd row
    if(x%2){
        if(x < y){
            return ((y*y - y + 1) - (y - x));
        }
        return ((x*x - x + 1) - (x - y));
    }
    //even row
    if(x < y){
        return (y*y - y + 1 - (y - x));
    }
    return (x*x - y + 1);
}

int main(){
    int t;
    std::cin>>t;
    while(t){
        uint64_t x,y;
        std::cin>>x>>y;
        // enum class Column { kOdd, kEven };
        // enum class Row { kOdd, kEven };
        // std::cout<<([](uint64_t x,uint64_t y)->uint64_t{return (y > x) ? (y*y - (x - 1)): (x*x - (y - 1));})(x,y)<<"\n";
        std::cout<<numberAt(x, y)<<"\n";
        t--;
    }
    return 0;
}
/*
10
5 6
5 4
5 7
5 5
5 3
6 4
6 6
6 8
6 5
6 7

30
20
45
21
19
33
31
55
32
44
*/