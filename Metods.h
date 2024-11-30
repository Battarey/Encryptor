#include <iostream>
#include <Windows.h>
//#include <vector>
//#include <wchar.h>
//#include <locale.h>
#include <string> // for work with getline
#include <cstdlib> // for work with time

using namespace std;

class User {
	string nickname;

	string methodEncrypt;
	string textNoEncrypt;
	string textToEnccrypt;

	char day; char month; short year;
};

void firstAuthorizationMenu();

bool authorization();
bool registrationo(bool* authorization);

void logo();

void mainMenu();

void encryptionMethods();
void decryptionMethods();

void informationAboutEncrypts();

bool copyToBuffer(string textUser);

string encrypt_FullRandom(string textUser);
string encrypt_SW043(string textUser);
string decrypt_SW043(string textUser);
string encrypt_LERT05(string textUser);
string decrypt_LERT05(string textUser);
string encrypt_PihN(string textUser);
string decrypt_PihN(string textUser);
string encrypt_PO4(string textUser);
string decrypt_PO4(string textUser); 
string encrypt_D7(string textUser, char day);

string decrypt_D7(string textUser); // in work

string encrypt_new(string textUser); // in work

string encrypt_GH16(string textUser); // in work


string decrypt_GH16(string textUser); // in work

void testEncrypt();
