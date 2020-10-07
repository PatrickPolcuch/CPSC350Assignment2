//runGame.cpp

#include "GameOfLife.h"

runGame::rungame(){
  //dont need a contructor
}

runGame::~runGame(){

}

void runGame::run(){
  cout<<"What type of map would you like, Doughnut, Mirror, or Classic? (enter as 'D', 'M', or 'C')"<<endl;
  string usermap ="";
  cin>>usermap;

  cout<<"Would you like to like to start from a file, or generate a random map? (Yes/No)"<<endl;
  string userfile = "";
  bool file = false;
  cin>>userfile;
  if(userfile.compare("Yes")==0||userfile.compare("yes")==0){
    file = true;
  }


  if(usermap.compare("D")==0||usermap.compare("d")==0){
    //make a doughnut map
  }else if(usermap.compare("M")==0||usermap.compare("m")==0){
    //make a mirror map
  }else if(usermap.compare("C")==0||usermap.compare("c")==0){
    //make a classic map
  } else{
    cout<<"Incorrect input for map type"<<endl;
  }

}
