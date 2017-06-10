#include "vigenere.h"


vigenere::vigenere()
{
    //none
}

void vigenere::encrypt(istream& input, ostream& output,string key){
    int countkey = 0;
    char start = 'a';
    char *encrypted;
    string message;

    while(!(input.eof())){
        getline(input,message);
        encrypted = new char[message.length()];
        countkey = 0;

        for(unsigned int i = 0; i < message.length(); i++){ //lower cases all the characters in the string
        message[i] = tolower(message[i]);
        }

        for(unsigned int i = 0; i < message.length(); i++){
          if(static_cast<signed int>(message[i]) >= 92 && static_cast<signed int>(message[i]) <= 122 ){
              encrypted[i] = ((message[i] - start + key[countkey % key.length()] - 97) % 26) + start;
              countkey++;
          }
          else{
              encrypted[i] = message[i];
          }
          output << encrypted[i];
        }

        delete [] encrypted;
        if(!input.eof()){
        output << "\n";
        }
    }

}



void vigenere::decrypt(istream& input, ostream& output,string key){
    int countkey;
    char *decryptedmessage;
    char start = 'a';
    string message;

    while(!(input.eof())){
        getline(input,message);
        decryptedmessage = new char[message.length()];
        countkey = 0;


        for(unsigned int i = 0; i < message.length(); i++){ //lower cases all the characters in the string
        message[i] = tolower(message[i]);
        }

        for(unsigned int i = 0; i < message.length(); i++){

            if(message[i] < 92 || message[i] > 122){
                decryptedmessage[i] = message[i];
            }
            else if(key[countkey % key.length()] <= message[i]) {
                decryptedmessage[i] = start + abs(key[countkey % key.length()] - message[i]);
                countkey++;
            }
            else{
                decryptedmessage[i] = start + 26 - abs(key[countkey % key.length()] - message[i]);
                countkey++;
            }
            output << decryptedmessage[i];
        }
        delete [] decryptedmessage;
        if(!input.eof()){
        output << "\n";
        }
    }


}
