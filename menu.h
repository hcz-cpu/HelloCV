#ifndef MENY_H
#define MENU_H

class Menu {
    public:
        void run();

    private:
        void showMenu();
        void handleChoice(int choice);
        void textEncrypt();
        void textDecrypt();
        void fileEncrypt();
        void fileDecrypt();
};

#endif