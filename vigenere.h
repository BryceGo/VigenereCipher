#ifndef VIGENERE_H
#define VIGENERE_H
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class vigenere
{
    public:
        vigenere();
        void encrypt(istream& input, ostream& output,string key);
        void decrypt(istream& input, ostream& output,string key);
};

#endif // VIGENERE_H
