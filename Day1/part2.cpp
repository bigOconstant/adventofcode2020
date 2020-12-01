#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set> 
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::stringstream;
using std::set;
int main(){
  std::fstream newfile;
  set<int> set; 
    newfile.open("input.txt",ios::in);  // open a file to perform write operation using file object
     if (newfile.is_open()){   //checking whether the file is open
      string line;
      while(getline(newfile, line)){ //read data from file object and put it into string.
	stringstream ss(line);
	int num = 0;
	
	ss >> num;
	set.insert(num);
	//   cout << num << "\n"; //print the data of the string
      }
      newfile.close(); //close the file object.
   }


    for (auto itr = set.begin();  itr != set.end(); ++itr) 
      {
        auto toplevel = 2020 - (*itr);
      
        for (auto itr2 = set.begin();  itr2 != set.end(); ++itr2) {
          if(itr2 == itr){
            continue;
          }
          auto itemToFind = toplevel - (*itr2);
          if (itemToFind == (*itr) || itemToFind == (*itr2)) {
            continue;
          }
          const bool is_in = set.find(itemToFind) != set.end();
          if (is_in) {
            cout<<itemToFind * (*itr) * (*itr2)<<endl;
            goto exit;
          }

        }

    }
    exit:

    return 0;
     
    

}
