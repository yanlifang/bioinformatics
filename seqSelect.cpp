#include <iostream>
#include <fstream> 
#include <string> 

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;



int main(int argc, const char * argv[]){


    ifstream ifs;
    ofstream ofs;

    string in_filename;
    string out_filename;
    string line;

    cout << "Please enter you query filename: \n";
    cin >> in_filename;
    ifs.open(in_filename);

    while(!ifs){
        cout << "File open failed! Please enter a correct filename: \n";
        cin >> in_filename;
        ifs.open(in_filename);
    }
    
    cout <<"Please enter a output filename, like an accession number: \n";
        cin >> out_filename;
        ofs.open(out_filename);

    while(getline(ifs, line)){
        
        if (line[0] = '>')
        {
            ofs << line;
            ofs << endl;
            line.clear();
        }   

        getline(ifs, line);
     
        cout << "Please enter your start and end postion: \n";
        int startPos, endPos;
        cin >> startPos >> endPos;

        for(int i = startPos; i < endPos; i++){
            ofs << line[i];
        }
        ofs << endl;
        line.clear();            
    }
   
    return 0;

}

