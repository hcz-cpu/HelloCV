#include "crypto.h"
using namespace std;

string Crypto::encrypt(const string& text,int key){
    string result = text;
    for(char& c : result){
        if (isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            c = (c -base +key)%26 +base;
        }
    }
    return result;
}

string Crypto::decrypt(const string& text,int key){
    return encrypt(text,26 -(key%26));
}