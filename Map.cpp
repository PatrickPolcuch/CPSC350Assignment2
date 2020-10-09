//map.cpp

#include "GameOfLife.h"

Map::Map(int r,int c,char type){//makes the map
  rows = r;
  cols = c;
  maptype = type;

  char grid[100][100];
}

Map::~Map(){

}

void Map::MapFromString(string str){//make a map from a user inputed file
  char c;
  int curRow = 0;
  int curCol = 0;

  for(int i = 0; i<str.size(); ++i){
    c = str.at(i);
    if(c == '\n'){
      curRow++;
      curCol = 0;
    }else if(c == 'X'){
      grid[curRow][curCol] = 'X';
      curCol++;
    }else if(c =='-'){
      grid[curRow][curCol] = '-';
      curCol++;
    }else if(c == char(10)||c == (char)(13)||c == ' '){//I dont know why these chars are in a text file
      continue;
    }else{
      cout<<"Something went wrong in Map::MapFromString(string str)"<<endl;
      cout<<(int)c<<endl;
      break;
    }
  }
}

void Map::RandomMap(){
  cout<<"What initial population density would you like? (0,1]"<<endl;
  float popDensity = 0;
  cin>>popDensity;
  int numCells = (int)(popDensity*rows*cols);
  if(numCells == 0){
    numCells = 1;
  }

  for(int i =0; i<rows; ++i){
    for(int j = 0; j<cols; ++j){
      grid[i][j] = '-';
    }
  }

  srand (time(NULL));//generates a random seed for rand()
  while(numCells != 0){
      int row = rand() % rows;
      int col = rand() % cols;
      if(grid[rows][cols] != 'X'){
        grid[row][col]='X';
        numCells--;
      }
  }

  cout<<MapToString()<<endl;
}

string Map::MapToString(){
  string ret = "";//return string
  for(int i =0; i<rows; ++i){
    for(int j = 0; j<cols; j++){
      ret += grid[i][j];
    }
    ret += '\n';
  }
  return ret;
}

int Map::NumNeighbors(int r,int c){
  switch(maptype){
    case 'C':
      return NumNeighborsClassic(r,c);
      break;
    case 'D':
      return NumNeighborsDoughnut(r,c);
      break;
    case 'M':
      return NumNeighborsMirror(r,c);
      break;
    default:
     cout<<"invalid map type: int Map::NumNeighbors(int r,int c)"<<endl;
  }
  return -1;
}

int Map::NumNeighborsClassic(int r,int c){
  int numN = 0;
  for(int i = r-1; i <= r+1; ++i){
    for(int j = c-1; j <= c+1; ++j){
      if(i<0||j<0||i>=rows||j>=cols||(i==r&&j==c)){
        continue;
      }
      if(grid[i][j] == 'X'){
        numN++;
      }
    }
  }
  return numN;
}

int Map::NumNeighborsDoughnut(int r,int c){
  int numN = 0;
  for(int i = r-1; i <= r+1; ++i){
    for(int j = c-1; j <= c+1; ++j){
      if(i==r&&j==c){
        continue;
      }
      if(grid[(i+rows)%rows][(j+cols)%cols] == 'X'){
        numN++;
      }
    }
  }
  return numN;
}

int Map::NumNeighborsMirror(int r,int c){
  int numN = 0;
  for(int i = r-1; i <= r+1; ++i){
    for(int j = c-1; j <= c+1; ++j){
      if(i==r&&j==c){
        continue;
      }
      int iforNow = i;
      int jforNow = j;
      if(i<0){
        iforNow = i+1;
      }
      if(j<0){
        jforNow = j+1;
      }
      if(i>=rows){
        iforNow = i-1;
      }
      if(j>=cols){
        jforNow = j-1;
      }
      cout<<i<<","<<j<<endl;
      cout<<iforNow<<","<<jforNow<<endl;
      cout<<endl;
      if(grid[iforNow][jforNow] == 'X'){
        numN++;
      }
    }
  }
  return numN;
}

string Map::NextGen(){
  string ret = "";//return string
  for(int i =0; i<rows; ++i){
    for(int j = 0; j<cols; j++){
      int neighbors = NumNeighbors(i,j);
      if(neighbors<=1||neighbors>=4){
        ret+='-';
        continue;
      }
      if(neighbors == 2){
        ret+=grid[i][j];
        continue;
      }
      if(neighbors == 3){
        ret+='X';
      }
    }
    ret += '\n';
  }
  MapFromString(ret);
  return ret;
}
