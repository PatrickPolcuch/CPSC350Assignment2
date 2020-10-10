/*Patrick Polcuch
2348668
CPSC350Assignment2
runGame.cpp
Runs the game of Life
*/

#include "GameOfLife.h"

runGame::runGame(){
  //dont need a contructor
}

runGame::~runGame(){

}

void runGame::run(){//runs the game

  cout<<"What type of map would you like, Doughnut, Mirror, or Classic? (enter as 'D', 'M', or 'C')"<<endl;
  string usermapStr ="";
  cin>>usermapStr;

  cout<<"Would you like to like to start from a file, or generate a random map? (file/rand)"<<endl;
  string userfile = "";
  cin>>userfile;

  int rows;
  int cols;
  string text = "empty";
  if(userfile.compare("file")==0||userfile.compare("File")==0){//reads the file and gets the num of rows and colums and the text representation of the map
    cout<<"What is the name of the file?"<<endl;
    string fileName;
    cin>>fileName;

    ifstream myFile;
    myFile.open(fileName);

    string curLine;
    getline(myFile,curLine);

    stringstream intRow(curLine);//gets the string and makes it an integer
    intRow>>rows;

    getline(myFile,curLine);
    stringstream intCol(curLine);
    intCol>>cols;

    text = "";
    while(getline(myFile,curLine)){
      text +=curLine+'\n';
    }
  }else{//gets the num of rows and colums for a random map
    cout<<"How many rows?"<<endl;
    cin>>rows;

    cout<<"How many colums?"<<endl;
    cin>>cols;
  }

  char usermapChar = 'C';//to get the map type
  if(usermapStr.compare("D")==0||usermapStr.compare("d")==0){
    usermapChar = 'D';
  }else if(usermapStr.compare("M")==0||usermapStr.compare("m")==0){
    usermapChar = 'M';
  }else if(usermapStr.compare("C")==0||usermapStr.compare("c")==0){
    usermapChar = 'C';
  } else{
    cout<<"Incorrect input for map type, defaulting to Classic map"<<endl;
  }

  Map* myMap = new Map(rows, cols, usermapChar);//creates the Map object

  if(text.compare("empty")==0){//initialized the map for random generation
    myMap->RandomMap();
  }else{//initializes the map from the text file
    myMap->MapFromString(text);
  }

  char delivery;
  while(true){//gets this question awnsered by the user \/
    cout<<"Would you like to hit enter before each generation, have a brief pause between generations, of output all generations to a file? ('E','P','F')"<<endl;
    cin>>delivery;
    if(delivery == 'E'||delivery == 'P'||delivery == 'F'){
      break;
    }
    cout<<"incorrect responce, please enter 'E','P', or 'F'"<<endl;
  }


  string fileContents = "";

  int generation = 0;
  string gen0 = "gen0";
  string gen1 = "gen1";
  string gen2 = "gen2";


  cout<<"Generation "<<generation<<'\n'<<myMap->MapToString()<<endl;
  fileContents += "Generation "+to_string(generation)+'\n'+myMap->MapToString()+'\n';
  while(true){//does the generations
    pause(delivery);
    string next = myMap->NextGen();
    generation++;

    if(generation%3==0){
      gen0=next;
    }else if(generation%3==1){
      gen1 =next;
    }else if(generation%3==2){
      gen2 = next;
    }
    if(gen0.compare(gen1)==0||gen0.compare(gen2) == 0||gen1.compare(gen2) == 0){//checks to see if the generations have Stabilized
      cout<<"Stabilized"<<endl;

      fileContents+="Stabilized\n";
      break;
    }
    cout<<"Generation "<<generation<<'\n'<<next<<endl;
    fileContents += "Generation "+to_string(generation)+'\n'+next+'\n';
  }

  if(delivery == 'F'){//write to file
    cout<<"what is the name of the file you would like to output to?"<<endl;
    string fileName = "";
    cin>>fileName;

    ofstream myFile;
    myFile.open(fileName);
    myFile<<fileContents;
    myFile.close();

  }

  delete myMap;
}

void runGame::pause(char type){//handles the pause type for the generations
  if(type == 'E'){//Enter
    getchar();
  }else if(type == 'P'){//Pause
    sleep_for(seconds(1));
  }
}
