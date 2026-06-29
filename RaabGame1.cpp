#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

class RaabGame {
    public:
    RaabGame(uint32_t n,uint32_t a,uint32_t b) : n_(n),a_(a),b_(b){
        total_points_ = a_ + b_;
        draws_ = n_ - total_points_;
    };
    bool possible_game(){
        if(total_points_ > n_){
            return false;
        }
        if(a_ == 0 or b_ == 0 ){
            if(total_points_ > 0){
                return false;
            }
        }
        return true;
    }
    void printCombinations(){
        auto v = combinations();
        for(auto i:v[0]){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
        for(auto i:v[1]){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
    private:
    uint32_t n_;
    uint32_t a_;
    uint32_t b_;
    uint32_t draws_;
    uint32_t total_points_;
    std::vector<std::vector<uint32_t>> combinations(){
        std::vector<std::vector<uint32_t>> res(2,std::vector<uint32_t>(n_));
        uint32_t player_a = 1;
        uint32_t player_b = 1;
        for(uint32_t i = 0; i < draws_; i +=1){
            res[0][i] = player_a;
            res[1][i] = player_a;
            player_a +=1;
        }
        // std::cout<<"Added Draws : "<<"\n";
        // for(auto i:res[0]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        // for(auto i:res[1]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        
        player_b = player_a;
        player_a = n_;
        for(uint32_t i = draws_;i < n_; i +=1){
            // std::cout<<i<<"\n";
            
            res[0][i] = player_a;
            player_a--;
        }
        // std::cout<<"Finished A : "<<"\n";
        // for(auto i:res[0]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        // for(auto i:res[1]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        
        player_b = n_;
        for(uint32_t i = n_ - b_;i < n_; i++){
            res[1][i] = player_b;
            player_b--;
        }
        for(uint32_t i = draws_;i < n_ - b_; i++){
            res[1][i] = player_b;
            player_b--;
        }
        // std::cout<<"Finished B : "<<"\n";
        // for(auto i:res[0]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        // for(auto i:res[1]){
        //     std::cout<<i<<" ";
        // }
        // std::cout<<"\n";
        return res;
    }
};

int main(){
    uint32_t t;
    std::cin>>t;
    while(t){
        uint32_t n,a,b;
        std::cin>>n>>a>>b;
        RaabGame obj(n,a,b);
        if(obj.possible_game()){
            std::cout<<"YES"<<"\n";
            obj.printCombinations();
        }
        else{
            std::cout<<"NO"<<"\n";
        }
        t--;
    }
    return 0;
}