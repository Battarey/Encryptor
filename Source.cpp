#include "Metods.h"

int main() {
	//srand(time(0));

	//mainMenu();
	//encryptionMethods();
	//decryptionMethods();

	//testEncrypt();

	return 84953;
}






//string encrypt_GH16(string textUser) { // создать метод шифровки, который добавляет 1 элемент перед и 1 после символа
//    string alphabet = "PvGB]Q:LYf[S/q_id>O1b+%m3eTZ7g0^p&ENtMH8nx{y}#h5JozCK2XwIcl?F,R!DU@Vja9.rkW')6u-4=A(s*";
//    char countEnPO = alphabet.length();
//    char countEnPOGlobal = alphabet.length();
//
//    char countMinusOrPlus; char indexOfAlphabet;
//    char symbolAddFirst; char symbolAddSecond;
//    string strAddFirst; string strAddSecond;
//
//    for (short i = 0; i < textUser.length(); i++) {
//        for (short j = 0; j < countEnPO; j++) {
//            if (textUser[i] == alphabet[j]) {
//                textUser[i] = alphabet[(j + 3) % countEnPO];
//
//                if (j - 6 < 0) {
//                    countMinusOrPlus = j - 6; indexOfAlphabet = countEnPOGlobal + countMinusOrPlus;
//                    symbolAddFirst = alphabet[indexOfAlphabet]; strAddFirst += symbolAddFirst; countEnPOGlobal = alphabet.length();
//                }
//                else { symbolAddFirst = alphabet[j - 6]; strAddFirst += symbolAddFirst; }
//                cout << "";
//                if (j + 6 > countEnPO) {
//                    countMinusOrPlus = j + 6; indexOfAlphabet = countMinusOrPlus - countEnPOGlobal;
//                    symbolAddSecond = alphabet[indexOfAlphabet]; strAddSecond += symbolAddSecond; countEnPOGlobal = alphabet.length();
//                }
//                else { symbolAddSecond = alphabet[j + 6]; strAddSecond += symbolAddSecond; }
//
//                break;
//            }
//        }
//    }
//
//    short arrTextSize = textUser.length(); short arrFirstSize = strAddFirst.length(); short arrSecondSize = strAddSecond.length();
//
//    char* arrTextUser = new char[arrTextSize] {};
//    char* arrFirstStr = new char[arrFirstSize] {};
//    char* arrSecondStr = new char[arrSecondSize] {};
//
//    for (short i = 0; i < arrTextSize; i++) {
//        arrTextUser[i] += textUser[i];
//        arrFirstStr[i] += strAddFirst[i];
//        arrSecondStr[i] += strAddSecond[i];
//    }
//    textUser = "";
//    for (short i = 0; i < strAddFirst.length(); i++) {
//        textUser += arrFirstStr[i];
//        textUser += arrTextUser[i];
//        textUser += arrSecondStr[i];
//    }
//
//    delete[] arrFirstStr;
//    arrFirstStr = nullptr;
//    delete[] arrTextUser;
//    arrTextUser = nullptr;
//    delete[] arrSecondStr;
//    arrSecondStr = nullptr;
//
//    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
//    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
//
//    return textUser;
//}