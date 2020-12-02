#include <iostream>
#include <fstream>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::ios;

struct Password{
    int lower;
    int higher;
    char character;

    Password(string input) {
        lower = std::stoi( input.substr(0, input.find("-")));
        higher = std::stoi( input.substr( input.find("-")+1,input.find(" ")));
        character = input.substr(input.find(" ")+1,input.size())[0];
    }
    int Correct(string p){
        auto count = 0;
        for(auto it = p.begin(); it < p.end(); ++it) {
            if ((*it) == character){
                ++count;
            }
        }
        if (count >= lower && count <= higher) {
            return 1;
        }else{
            return 0;
        }
    }
};

int main() {
  std::fstream newfile;
  int answer = 0;
  newfile.open("input.txt",ios::in);  // open a file to perform write operation using file object
     if (newfile.is_open()){   //checking whether the file is open
      string line;
      while(getline(newfile, line)){ 
          std::string token = line.substr(0, line.find(":"));
          auto rightside = line.substr(line.find(":")+1, line.size());
          Password p = Password(token);
          answer = answer + p.Correct(rightside);
      }


     }
     cout<<"correct passwords:"<<answer<<endl;

    return 0;
}