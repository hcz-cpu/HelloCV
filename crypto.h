#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
using namespace std;
class Crypto {
    public:
        static string encrypt(const string& text,int key);
        static string decrypt(const string& text,int key);
};

#endif