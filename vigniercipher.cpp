#include <iostream>
#include <cstring>
#include <fstream>
#include "vigenere.h"

using namespace std;

int main (void) {

  string key = "/0";
  string filenamein;
  string filenameout;
  char answer;
  ofstream ofile;
  ifstream ifile;
  vigenere cipher;


  char *decryptedmessage;

  char start = 'a';
  char *encrypted = NULL;
  int countkey = 0;

  cout << "Please input your key here: " << endl;
  cin >> key;

  cout << "Please type in the name of the input file: ";
  cin >> filenamein;

  cout << "Please type in the name of the output file: ";
  cin >> filenameout;

/* //debugging purposes
    key = "king";
    filenamein = "i.txt";
    filenameout = "o.txt";
*/
  cout << endl;

  ofile.open(filenameout);
  ifile.open(filenamein);

  if(ifile.fail()){
    cout << "Error input file cannot be opened." << endl;
    return 1;
  }

  cout << "Encrypt or decrypt?: ";
  cin >> answer;

  if(answer == 'd' || answer == 'D'){
    cipher.decrypt(ifile,ofile,key);
  }else{
    cipher.encrypt(ifile,ofile,key);
  }
  cout << "done..";


  ofile.close();
  ifile.close();
}
