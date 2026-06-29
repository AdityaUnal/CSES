#include <iostream>
#include <string>
#include <vector>
#include <cstdint>


/*
* arr is the chess board
* arr[i][j] == true -> signifies we can keep there
* arr[i][j] == false -> signifies we cannot keep there
*/
void markBoard(std::vector<std::vector<bool>>& arr, int i, int j){
    for(int row = 0;row < 8;row +=1){
        arr[row][j] = false;
    }
    for(int col = 0;col < 8;col +=1){
        arr[i][col] = false;
    }
    for(int row = i,column = j; row >= 0 and column >= 0; row--,column-- ){
        arr[row][column] = false;
    }
    for(int row = i,column = j; row < 8 and column < 8; row++,column++ ){
        arr[row][column] = false;
    }
    for(int row = i,column = j; row >= 0 and column < 8; row--,column++ ){
        arr[row][column] = false;
    }
    for(int row = i,column = j; row < 8 and column >= 0; row++,column-- ){
        arr[row][column] = false;
    }
}
uint32_t f(std::vector<std::vector<bool>> arr, int i, int j){
    if(i != -1 ){
        if(!arr[i][j]){
            return 0;
        }
        markBoard(arr, i,j);
        if(i == 7){
            return 1;
        }
    }

    uint32_t res = 0;
    for(int j = 0;j < 8;j +=1){
        res +=f(arr,i + 1,j);
    }
    return res;
}

int main(){
    std::vector<std::vector<bool>> arr(8,std::vector<bool>(8,true));
    for(int i = 0;i < 8;i +=1){
        std::string s;
        std::cin>>s;
        for(int j = 0; j < 8; j+=1){
            if(s[j] == '*'){
                arr[i][j] = false;
            }
        }
    }
    std::cout<<f(arr,-1,0)<<"\n";
    return 0;
}