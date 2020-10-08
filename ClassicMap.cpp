//ClassicMap.cpp

#include "GameOfLife.h"


ClassicMap::ClassicMap(int r,int c):Map(r,c){

}

ClassicMap::~ClassicMap(){

}

/*int ClassicMap::Method(int r,int c){
  NumNeighbors(r,c);
  return subNumNeighbors(r,c);

}*/

int ClassicMap::NumNeighbors(int r,int c){
  cout<<"executing ClassicMap::subNumNeighbors"<<endl;
  int numN = 0;
  for(int i = r-1; i <= r+1; ++i){
    for(int j = c-1; i <= c+1; ++j){
      if(i<0||j<0||i>=rows||j>=cols||(i==r&&j==c)){
        continue;
      }
      if(grid[i][j] == 'X'){
        numN++;
      }
    }
  }
  cout<<"numN= "<<numN<<endl;
  return numN;
}
