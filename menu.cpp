#include "menu.h"
#include "crypto.h"
#include "filehandler.h"
#include <iostream>
using namespace std;
void Menu::showMenu(){
    cout<<"1.text encryption"<<endl;
    cout<<"2.text decryption"<<endl;
    cout<<"3.document encryption"<<endl;
    cout<<"4.document decryption"<<endl;
    cout<<"5.back"<<endl;
    cout<<"please choose functions"<<endl; 
}

void Menu::run(){
    int choice = 0;

    do{
        showMenu();
        cin>>choice;
        handleChoice(choice);
    }while (choice !=5);
}

void Menu::handleChoice(int choice){
    switch (choice)
    {
    case 1:textEncrypt();
        break;
    case 2:textDecrypt();
        break;
    case 3:fileEncrypt();
        break;
    case 4:fileDecrypt();
        break;
    case 5:cout<<"goodbye"<<endl;
        break;
    default:cout<<"error!!!"<<endl;
        break;
    }
}

void Menu::textEncrypt(){
    string text;
    int key;
    cout<<"text encrypt:";
    cin.ignore();
    getline(cin,text);
    cout<<"please write your key:";
    cin>>key;
    string result = Crypto::encrypt(text,key);
    cout<<"the result is "<<result<<endl;
}

void Menu::textDecrypt(){
    string text;
    int key;
    cout<<"text decrypt:";
    cin.ignore();
    getline(cin,text);
    cout<<"please write your key:";
    cin>>key;
    string result=Crypto::decrypt(text,key);
    cout<<"the result is"<<result<<endl;
}

void Menu::fileEncrypt(){
    string inputFile,content;
    int key;
    cout<<"file encrypt:";
    cin.ignore();
    getline(cin,inputFile);
    cout<<"please write your key:";
    cin>>key;
    if(!FileHandler::read(inputFile,content))return;
    content=Crypto::encrypt(content,key);
    if(FileHandler::write("encrypted.txt",content)){
        cout<<"have been encrypted to encrypted.txt"<<endl;
    }
}

void Menu::fileDecrypt(){
    string inputFile,content;
    int key;
    cout<<"file decrypt:";
    cin.ignore();
    getline(cin,inputFile);
    cout<<"please write your key:";
    cin>>key;
    if(!FileHandler::read(inputFile,content))return;
    content=Crypto::decrypt(content,key);
    if(FileHandler::write("decrypted.txt",content)){
        cout<<"have been decrypted to decrypted.txt"<<endl;
    }
}