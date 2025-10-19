#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
using namespace std;
class FileHandler {
    public: 
        static bool read(const string& filename,string& content);
        static bool write(const string& filename,const string& content);
};

#endif