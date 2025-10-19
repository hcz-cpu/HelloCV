#include "filehandler.h"
#include <fstream>
#include <iostream>
using namespace std;

bool FileHandler::read(const string& filename,string& content){
    ifstream file(filename);
    if (!file.is_open()){
        cout<<"mistake:can't open the decumetory"<<filename<<endl;
        return false;
    }

    content.assign((istreambuf_iterator<char>(file)),
                    istreambuf_iterator<char>());
    file.close();
    return true;
}

bool FileHandler::write(const string& filename,const string& content){
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"error:can't create decumetory"<<filename<<endl;
        return false;
    }

    file << content;
    file.close();
    return true;
}