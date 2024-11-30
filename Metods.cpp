#include "Metods.h"

//     string alphabet = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789!?,./@#;:%^&*()[]{}-_=+|<>'~`";

void firstAuthorizationMenu() {
    cout << "First autoriz successfully" << endl;

    mainMenu();
}

bool authorization() {
    bool successfulAuthorization = false;

    return successfulAuthorization;
}

bool registrationo(bool* authorization) {

    return authorization;
}

void logo() {
    cout << " ==================================================== " << "         " << " ======================================================= " << endl;
    cout << "\t\t\t\t\t\t      " << "Encryptor" << endl;
    cout << " ==================================================== " << "         " << " ======================================================= " << endl;
}

void testEncrypt() {
    cout << "You choise GH16 input your text: ";
    string textUser;
    //cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    getline(cin, textUser);
    string str = encrypt_GH16(textUser);
    cout << "Result: " << str << endl;
    //cout << "Encrypt: " << decrypt_GH16(str) << endl;
}


void mainMenu() {
    char choiseUser;
    cout << "Welocme to the data encryption application!" << endl;
    cout << "So far, the application can only encrypt the strings that you enter" << endl;
    cout << "In this program, you can both encrypt and decrypt" <<
        "the text that you encrypted in advance in this application." << endl <<
        "Enter 1 if you need encryption, 2 if you need decryption. Input: "; cin >> choiseUser;
    if (choiseUser == '1') { encryptionMethods(); }
    else if (choiseUser == '2') { decryptionMethods(); }
    else { cout << "Incorrect input!"; }
}

void informationAboutEncrypts() {

}

void encryptionMethods() {
    char choiseMethodE;
    cout << "Choise your encryption method: " << endl;
    cout << "1. SW-043\n2. LERT_05\n3. PihN\n4. D7\n5. PO4\nYour choise: "; cin >> choiseMethodE;
    if (choiseMethodE == '1') {
        cout << "You choise SW-043, input your text: ";
        string textUser;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUser);
        cout << "Result: " << encrypt_SW043(textUser) << endl;
    }
    else if (choiseMethodE == '2') {
        cout << "You choise LERT_05, input your text: ";
        string textUser;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUser);
        cout << "Result: " << encrypt_LERT05(textUser) << endl;
    }
    else if (choiseMethodE == '3') {
        cout << "You choise PihN, input your text: ";
        string textUser;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUser);
        cout << "Result: " << encrypt_PihN(textUser) << endl;
    }
    else if (choiseMethodE == '4') {
        SYSTEMTIME st;
        GetLocalTime(&st);
        char day = st.wDay;
        cout << "Input your text: ";
        string textUser;
        (cin >> textUser).get();
        cout << "Result: " << encrypt_D7(textUser, day) << endl;
    }
    else if (choiseMethodE == '5') {
        cout << "Input your text: ";
        string textUser;
        (cin >> textUser).get();
        cout << "Result: " << encrypt_PO4(textUser) << endl;
    }
    else { cout << "Incorrect input!"; }
}
void decryptionMethods() {
    char choiseMethodD;
    cout << "Choise your decryption method: " << endl;
    cout << "1. SW-043\n2. LERT_05\n3. PihN\n4. D7\n5. PO4\nYour choise: "; cin >> choiseMethodD;
    if (choiseMethodD == '1') {
        cout << "You choise SW-043, input your text: ";
        string textUserP;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUserP);
        cout << "Result: " << decrypt_SW043(textUserP) << endl;
    }
    else if (choiseMethodD == '2') {
        cout << "You choise LERT_05, input your text: ";
        string textUserP;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUserP);
        cout << "Result: " << decrypt_LERT05(textUserP) << endl;
    }
    else if (choiseMethodD == '3') {
        cout << "You choise PihN, input your text: ";
        string textUserP;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUserP);
        cout << "Result: " << decrypt_PihN(textUserP) << endl;
    }
    else if (choiseMethodD == '4') {
        cout << "You choise D7, input your text: ";
        string textUserP;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUserP);
        cout << "Result: " << decrypt_D7(textUserP) << endl;
    }
    else if (choiseMethodD == '5') {
        cout << "You choise PO4, input your text: ";
        string textUserP;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        getline(cin, textUserP);
        cout << "Result: " << decrypt_PO4(textUserP) << endl;
    }
    else { cout << "Incorrect input!"; }
}

string encrypt_SW043(string textUser) {
    string alphabet = "D@A]m.&5YM*t)H_d2fkyrel[p#>G0TbBROx9cuvo!{W(UKhz=}i4q%'PE:LC3,IsZXVN8n^Q7?g+JaF61Sjw/-";
    char countEnSW = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countEnSW; j++) {
            if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 3) % countEnSW]; break; }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}
string decrypt_SW043(string textUser) {
    string alphabet = "D@A]m.&5YM*t)H_d2fkyrel[p#>G0TbBROx9cuvo!{W(UKhz=}i4q%'PE:LC3,IsZXVN8n^Q7?g+JaF61Sjw/-";
    char countDeSW = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countDeSW; j++) {
            if (textUser[i] == alphabet[j]) {
                if (j >= 3) { textUser[i] = alphabet[j - 3]; break; }
                else if (j == 0) { textUser[i] = alphabet[(countDeSW - 3)]; break; }
                else if (j == 1) { textUser[i] = alphabet[(countDeSW - 2)]; break; }
                else if (j == 2) { textUser[i] = alphabet[(countDeSW - 1)]; break; }
            }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}

string encrypt_LERT05(string textUser) {
    string alphabet = "=ZJ^kp({e+ncy#,TF[)aLO.0!4B%j&R*_-fz]2lSMH3@gEwWuhADY'/q}PsIodGri:71VN8UXxbt>m5K9QC6?v";
    char countEnLE = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countEnLE; j++) {
            if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnLE]; break; }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}
string decrypt_LERT05(string textUser) { 
    string alphabet = "=ZJ^kp({e+ncy#,TF[)aLO.0!4B%j&R*_-fz]2lSMH3@gEwWuhADY'/q}PsIodGri:71VN8UXxbt>m5K9QC6?v";
    char countDeLE = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countDeLE; j++) {
            if (textUser[i] == alphabet[j]) {
                if (j >= 2) { textUser[i] = alphabet[j - 2]; break; }
                else if (j == 0) { textUser[i] = alphabet[(countDeLE - 1)]; break; }
                else if (j == 1) { textUser[i] = alphabet[(countDeLE)]; break; }
            }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}

string encrypt_PihN(string textUser) {
    string alphabet = "748zFKPNV:}=(u%/I!wfSa3.+v^1mG>Z]R2HL?esj*-tOi0k@Y_ADyTbJ{X,UB)n[Mh#&pQ59E6o'lxrWdcgqC";
    char countEnPI = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countEnPI; j++) {
            if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 5) % countEnPI]; break; }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}
string decrypt_PihN(string textUser) {
    string alphabet = "748zFKPNV:}=(u%/I!wfSa3.+v^1mG>Z]R2HL?esj*-tOi0k@Y_ADyTbJ{X,UB)n[Mh#&pQ59E6o'lxrWdcgqC";
    char countDePI = alphabet.length();

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countDePI; j++) {
            if (textUser[i] == alphabet[j]) {
                if (j >= 5) { textUser[i] = alphabet[j - 5]; break; }
                else if (j == 0) { textUser[i] = alphabet[(countDePI - 5)]; break; }
                else if (j == 1) { textUser[i] = alphabet[(countDePI - 4)]; break; }
                else if (j == 2) { textUser[i] = alphabet[(countDePI - 3)]; break; }
                else if (j == 3) { textUser[i] = alphabet[(countDePI - 2)]; break; }
                else if (j == 4) { textUser[i] = alphabet[(countDePI - 1)]; break; }
                //else if (j == 5) { textUser[i] = alphabet[(countDePI - 5)]; break; }
            }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}

bool copyToBuffer(string textUser) {
    bool successfulCopying = false;

    if (OpenClipboard(NULL)) {
        EmptyClipboard();

        HGLOBAL hClipboardData;
        hClipboardData = GlobalAlloc(GMEM_DDESHARE, textUser.size() + 1);

        char* pszBuffer = (char*)GlobalLock(hClipboardData);
        strcpy_s(pszBuffer, textUser.size() + 1, textUser.c_str());
        GlobalUnlock(hClipboardData);

        SetClipboardData(CF_TEXT, hClipboardData); CloseClipboard();
        successfulCopying = true;
    }

    return successfulCopying;
}

string encrypt_D7(string textUser, char day) {
    switch (day) { // 1 - 9 четыре последних, 10 - 19 пять последних символов, 20 - 31 шесть последних символов
        // добавить разнообразие, чтобы элементы например добавлялись в начало/середину/конец
    case 1: {
        string alphabet = "cTaUK}Qjw='*(EZMfkGz2D3]/m?BR-Hgsdy50oCOF#@h7P4)VW8lqbN.9,ptu{!+>IYSJ^AnXr16x&vL:ie[%_";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string one = "_qA%"; textUser += one; 

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 2: {
        string alphabet = "z:d]WPB9*ZI1aoL[eg%7/>p23#0)K5n!C.u}MfGUb@(^O{6j,RN+QYJsVS4qAXxy8wmF=H-cDEir_l&'tTv?kh";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string two = "/3]_"; textUser += two;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 3: {
        string alphabet = ".RU8B:rS7o4AT_+3KqL2W=9#Npsl&HfFtGn!Z-C[zEM,vxa(@?h)u}y>dIYDicPO^g6]J51XV/0%jm*Qe{w'bk";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string three = "mH3b"; textUser += three;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 4: {
        string alphabet = "st24.fx^kgj'&R+BL{:}95]zpuHAwC,#N?U%SoTmOh(D0ry=eZ[FMan@)Ec*iYP3IVbd7q/Q1v_>!lJX6W-G8K";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string four = "?1Vs"; textUser += four;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 5: {
        string alphabet = "o,pK.LNSnHeqyVGD)A{6Fx?b/Is]YU@[:#C9Zft07ajW^rEiX=%&'_23P*lkc}z8MJ>1uORv+Q5gdh4-mw!(BT";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string five = "2@nB"; textUser += five;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 6: {
        string alphabet = "8Ff#{z?%o=@]q0K-:UCl2Z3I/jgc*_GLR.Hn+pEO4[TSxX9NVr(6!s,vt1>d5bki&^ABeJYhD7wy}m)'MQaPuW";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string six = "nn_n"; textUser += six;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 7: {
        string alphabet = "^E]ZxlVzSA3CaL){6+}cjGX/(bqt?DB0vHp7@UM4wWK#o:9i1=,I5yf!PN2g['r_mdnk*.F>8RTQh-eJuY&sO%";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string seven = "2@nB"; textUser += seven;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 8: {
        string alphabet = "7Pa,y)=j{>U_Y}eglBV:up/%S?2[H'@#QbozXw^G.EMLd4JT39fN08xrZmKi6vn]5CWRk-+*hIA(q&DctO!F1s";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string eight = "rkdV"; textUser += eight;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 9: {
        string alphabet = "0x9B/+KHyeqr%=M1Ga]I>ms,Jz_iS)ZQo6Wb&2*Uj!7(vN38AF}w#h@?uTP'fdpYt[4R:Ong.lV{L-5c^CDkEX";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string nine = "r03-"; textUser += nine;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 10: {
        string alphabet = "_VF,lX@Z19H6.%2]T-e?IowCSMK0jn{=Aby:+iqW7r3^zfJP8#hx'4t>Qs5}&!ELD*g([O)NGck/uRmvYaUdBp";        
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string ten = "2>/dP"; textUser += ten;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 11: {
        string alphabet = "TcGLSwXx})3049CjR-p@m.zNH#=V?oyYl2nikQ1sq!ZO8I,(h_&v+^J'W5fA:*bBD7{M/[t]rgd%6>eFPKUuaE";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string eleven = "dlUI8"; textUser += eleven;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 12: {
        string alphabet = "'AIay(BO:0b6@SRQr,vTe9koxz.VJ%_tglpwC{DF7jUh#-^L&}YmWn[!?fPXcN>E)G8412iM3*Kusdq]Z=+/H5";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twelve = "Nh61#"; textUser += twelve;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 13: {
        string alphabet = "s+'ySjxR7eC3=tmW5r}o%OYJ@K>_9.TBM?l-6cwfPi,n{g082zkb&q]!ZGIp:v#(V^LQUa1D/[*dA4)XhuHFNE";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string thirteen = "_jN+3"; textUser += thirteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 14: {
        string alphabet = "9qlN@A-/{06SpQ,j&7(xUnwtK=OM1a)^V?*'c+%8PhF>X2L![zD:EGrsRZBvIfy4o3.W}bu]JgHiYC#d_k5Tem";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string fourteen = "Fk?3)"; textUser += fourteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 15: {
        string alphabet = "&,UW:ztXlKpd+w(e-IP4s^y>oEi1gQ_vY7AM3%B}*R/6TxD.][JS0c8#b@k'mjfG)nZ{2rC?Hha!5VFO=Lq9Nu";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string fiveteen = ":zxc!"; textUser += fiveteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 16: {
        string alphabet = "C7#_wk1AX0xmuoY,6ZS(>s4lF&^Jt:vU+E'G8eaBfhVMb%5OI*}Pc?H[qpd9DQKT/N{in3)-W2RyL]g!=@z.rj";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string sixteen = "POx[@"; textUser += sixteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 17: {
        string alphabet = "[16Q:Ov24WZPxK5r,baLIhw@_*Bz?3pSNlmE=c0.RU}T]%kCd#>V-qoF+iA8(!J{^ft/HXuGM7n&9gjy)YDes'";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string seventeen = "Nq1!L"; textUser += seventeen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 18: {
        string alphabet = ":bm825PNMTj(%ISC}u^YRG#VL-qE&J'sik0g.KX!Qte6W]l73*O=Bz)wD9Fvoyrx_n@,AZf>d1c?{H4a+p[U/h";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string eighteen = "j4EW:"; textUser += eighteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 19: {
        string alphabet = "-Uta9s/o2Er%c=M1[A&QYS]kv'V3Hhu.q5m48#xbKI^DXBRCdFj,@Jz}+{*gNGi(:l!fPnpTOZ_L7>0yweW)?6";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string nineteen = "JdY6/"; textUser += nineteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 20: {
        string alphabet = "Q9ywJ^x.ub4I17nAOs'(?=lNMRcjz#X*3hi-_Tm]qeDZGpS0fFU5>CK:&6}rHdtEW)%g{B[k+!8L,a/@YvVo2P";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twenty = "m7B3*>"; textUser += twenty;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 21: {
        string alphabet = "sm5JYzGO!R#A_o6ci+VHUt{9(uXE[kQ4j@K-v3)^/PaBF81ZLd=q.?TMx>fD0,yw:l]Cn}&h7bgepW%NS*Ir2'";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyOne = "N4kQ?O"; textUser += twentyOne;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 22: {
        string alphabet = "o9^5Y}?fMD>k{nq]b0R&A[*JIK8OuSvX-/hLlgHx,6ms_34VZ.U'cN(rzFp2E1T7W:=jPdCy!)iBaeQt%#+@Gw";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyTwo = "SW_3<H"; textUser += twentyTwo;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 23: {
        string alphabet = "(JT8:HPVWwQan9e/}pZYjfX_C{b7Axzy14Bc^r2KtgS@h6+.&E=k>'i3[,!q*]UMIo0ON#dFvG5-mL%D?Rlsu)";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyThree = "L_8*Ne"; textUser += twentyThree;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 24: {
        string alphabet = "Tmp?Vdg9o0L67[=NQf+!^I(t>xZc#F%SsaKHb.RGiA]4&JWuM,wEC}r_h:DYny3X-eU'q8v1@z/25{B*OlP)jk";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyFour = "T0b2L-"; textUser += twentyFour;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 25: {
        string alphabet = "*+5RYn]s^hd2y@HAQ=1r.[at?fc9X)Gx8E4q,z%Tjw#0Oi/JBM&U:6mNL7bpKeZV{FP}>u-g_3lokS(D!WC'Iv";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyFive = "oUY%VQ"; textUser += twentyFive;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 26: {
        string alphabet = "Sp3jWv>70CMsYEPnbTzL2#Do]GFi91yUeVB6xZ}N-AO%=u4_:h,!IQk/{cdH)q[a&5XRw?+^trlKm'f8.J*g(@";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentySix = "P][_34"; textUser += twentySix;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 27: {
        string alphabet = "r/uC+:.^fIL'H6_hn5eYT4>Z!K9qWvomb={RJX1[gjPpM?Qy@D8l*0Ua)2O-sxwdViGk]%Nz,B3ASF#cE7&(t}";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentySeven = "C7_Uq2"; textUser += twentySeven;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 28: {
        string alphabet = "y6zd*SIPC?=(+!xGfcg^8D243E,hwj>u1[T0r@FRMV'.QLZOYs}m5b#&)veakH7Ai9JX%/{Bp:]q_tnlKoUWN-";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyEight = "_LmE4H"; textUser += twentyEight;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    case 29: {
        string alphabet = ",/01!vE6&?G_.)OzxKo=SX:F4]>3%@eCRq}cuBy8J'7mgQ+PMV[AIL#2h*awf^WpZN-rnkDHs{jbdTt(i5UlY9";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string twentyNine = "jnfwqo"; textUser += twentyNine;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 30: {
        string alphabet = "_fEy:VBOGH,j1]LN&wUT/%6vg?s*#K>!ez5(R4=QIA+PZnb^@7.W8J0hC9Xd}YD-qrFM3){utkpSmx2'icl[ao";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string thirteen = "0M3fUy"; textUser += thirteen;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

        break;
    }
    case 31: {
        string alphabet = "r^v!%V1a5nJ.}6/q8p]{U4xA[Sc(HtCmW_:NoKlE7TD3>X)OLu0Qsbz=?@YBkewRj#ZGMg*d,IF9+ihfy2P&'-";
        char countEnSW = alphabet.length();

        for (short i = 0; i < textUser.length(); i++) {
            for (short j = 0; j < countEnSW; j++) {
                if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 2) % countEnSW]; break; }
            }
        }

        string thirtyOne = "<M3p?8"; textUser += thirtyOne;

        if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
        else { cout << "The text was not copied to the clipboard due to an error!" << endl; }
        break;
    }
    }
    return textUser;
}
string decrypt_D7(string textUser) {

    return textUser;
}

string encrypt_FullRandom(string textUser) {
    string alphabet = "#0}4ngzpU&Y@)oW97sQxqdEmij?RyHL+6e-SFhI!DO>8G.1J[/5KkZ2v*bcuP]l={NA:^BXMf(V3w,'taT%_rC";
    char countEnSW = alphabet.length();
    char randNumber = 0;

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countEnSW; j++) {
            if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(rand() % (countEnSW - 0) + 0) % countEnSW]; break; }
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}

string encrypt_new(string textUser) {
    string alphabet = "%duLSPT[DF?-]Kw@/omCc94_grx3*B&X>zW+!{10'7J;HAjM~YRyq6tZU|#hNOG^pav`kVif=2}.n(Il)5<s:eQE,b8"; // 157      
    unsigned char countEnNew = alphabet.length(); 
    unsigned char countEnNewGlobal = alphabet.length();


    //// изменение алфавита, из которого он берёт символы
    //short fiveLastSymbol = 6; short count = 0; 
    //short countFixGlobal = 0;
    //string gap; string result;

    //for (short i = 0; i < fiveLastSymbol; i++) {
    //    gap = alphabet[countEnNew - i];
    //    cout << gap;
    //    result += gap;
    //}
    //unsigned char minus = (countEnNew - fiveLastSymbol) + 1;
    //alphabet.erase(minus, 6);
    //alphabet = result + alphabet;
    //cout << endl << alphabet << endl;
    //// 


    //// изменяет символ каждые 5 раз, поэтому разработать систему выбора цифр
    //// 1 раз +15, 2 раз -28, 3 раз +112, 4 раз -84, 5 раз +3 
    //char maybeMinusOrPlus = 0; unsigned char minusOrPlusResult = 0;
    //unsigned char countFixLocale = 0;
    //for (short i = 0; i < textUser.length(); i++) {
    //    for (short j = 0; j < countEnNew; j++) {
    //        if (textUser[i] == alphabet[j] and countFixLocale == 0) { 
    //            if (j + 15 > countEnNewGlobal) { maybeMinusOrPlus = j + 15; minusOrPlusResult = maybeMinusOrPlus - countEnNewGlobal; textUser[i] = alphabet[minusOrPlusResult]; countFixLocale++; break; }
    //            else { textUser[i] = alphabet[(j + 15)]; countFixLocale++; break; }
    //        }
    //        else if (textUser[i] == alphabet[j] and countFixLocale == 1) { 
    //            if (j - 28 < 0) { maybeMinusOrPlus = j - 28; minusOrPlusResult = countEnNewGlobal + maybeMinusOrPlus; textUser[i] = alphabet[minusOrPlusResult]; countFixLocale++; break; }
    //            else { textUser[i] = alphabet[(j - 28) % countEnNew]; countFixLocale++; break; } 
    //        }
    //        else if (textUser[i] == alphabet[j] and countFixLocale == 2) {
    //            if (j + 112 > countEnNewGlobal) { maybeMinusOrPlus = j + 112; minusOrPlusResult = maybeMinusOrPlus - countEnNewGlobal; textUser[i] = alphabet[minusOrPlusResult]; countFixLocale++; break; }
    //            else { textUser[i] = alphabet[(j + 112)]; countFixLocale++; break; }
    //        }
    //        else if (textUser[i] == alphabet[j] and countFixLocale == 3) { 
    //            if (j - 84 < 0) { maybeMinusOrPlus = j - 84; minusOrPlusResult = countEnNewGlobal + maybeMinusOrPlus; textUser[i] = alphabet[minusOrPlusResult]; countFixLocale++; break; }
    //            else { textUser[i] = alphabet[(j - 84) % countEnNew]; countFixLocale++; break; }
    //        }
    //        else if (textUser[i] == alphabet[j] and countFixLocale == 4) { 
    //            if (j + 3 > countEnNewGlobal) { maybeMinusOrPlus = j +3; minusOrPlusResult = maybeMinusOrPlus - countEnNewGlobal; textUser[i] = alphabet[minusOrPlusResult]; countFixLocale = 0; break; }
    //            else { textUser[i] = alphabet[(j + 3)]; countFixLocale = 0; break; }
    //        }
    //        else { cout << "error!" << endl; }
    //    }
    //}
    ////




        // в начале 3-5 символа, сколько раз сменялся алфавит !!!!!!!!!!!


    return textUser;
}

string encrypt_multilevel(string textUser) {
    // шифрование многоразовое из разных шифровок

    return textUser;
}

string encrypt_PO4(string textUser) {
    string alphabet = "Kdgq4-6RO!#fMa.=ui:]xrp3Il@5V{19T(Cy>+_JnhHL8vBjW,7m/0keo*XS^&)Dsc2G%[?QNtbPz'AZFUYE}w";
    char countEnPO = alphabet.length(); 

    char symbolAdd;
    string strAdd;

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countEnPO; j++) {
            if (textUser[i] == alphabet[j]) { textUser[i] = alphabet[(j + 3) % countEnPO]; symbolAdd = alphabet[j + 6]; strAdd += symbolAdd; break; }
        }
    }

    textUser += strAdd;

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}
string decrypt_PO4(string textUser) {
    string alphabet = "Kdgq4-6RO!#fMa.=ui:]xrp3Il@5V{19T(Cy>+_JnhHL8vBjW,7m/0keo*XS^&)Dsc2G%[?QNtbPz'AZFUYE}w";
    char countDePO = alphabet.length();

    short count = textUser.length() / 2;
    string strNew;

    for (short i = 0; i < count; i++) {
        strNew += textUser[i];
    }

    textUser = strNew;

    for (short i = 0; i < textUser.length(); i++) {
        for (short j = 0; j < countDePO; j++) {
            if (textUser[i] == alphabet[j]) {
                if (j >= 3) { textUser[i] = alphabet[j - 3]; break; }
                else if (j == 0) { textUser[i] = alphabet[(countDePO - 3)]; break; }
                else if (j == 1) { textUser[i] = alphabet[(countDePO - 2)]; break; }
                else if (j == 2) { textUser[i] = alphabet[(countDePO - 1)]; break; }
            }
        }
    }

    return textUser;
}


string encrypt_GH16(string textUser) { // создать метод шифровки, который добавляет 1 элемент перед и 1 после символа
    string alphabet = "PvGB]Q:LYf[S/q_id>O1b+%m3eTZ7g0^p&ENtMH8nx{y}#h5JozCK2XwIcl?F,R!DU@Vja9.rkW')6u-4=A(s*";
    char countEnPO = alphabet.length();
    char countEnPOGlobal = alphabet.length();
    textUser += " "; 

    string textUserNew; string textNewReady = " "; string newText;
    string FirstStr; char secondStr;

    for (short i = 0; i < textUser.length(); i++) {

        if (textUser[i] == ' ') {
            char countMinus;
            for (short k = 0; k < textUserNew.length(); k++) {
                for (short j = 0; j < countEnPO; j++) {
                    if (textUserNew[k] == alphabet[j]) {

                        textUserNew[k] = alphabet[(j + 3) % countEnPO];

                        if (j - 6 < 0) {
                            countMinus = j - 6; countEnPOGlobal += countMinus;
                            FirstStr = alphabet[countEnPOGlobal]; textNewReady += FirstStr; countEnPOGlobal = alphabet.length();
                        }
                        else if (j - 6 > 0) { FirstStr = alphabet[j - 6]; textNewReady += FirstStr; }

                        textNewReady += textUserNew[k];

                        cout << "";

                        if (j + 6 > countEnPO) {
                            countMinus = j + 6; countMinus -= countEnPOGlobal;
                            secondStr = alphabet[countMinus]; textNewReady += secondStr;
                        }
                        else if (j + 6 < countEnPO) { secondStr = alphabet[j + 6]; textNewReady += secondStr; }

                    }
                }
                newText += textNewReady; newText += " ";
                textUserNew = ""; 
            } // не работает как надо, если получица - реализовать дешифратор для него
        } 
        else { textUserNew += textUser[i]; }
    }

    if (copyToBuffer(newText)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return newText;
}

string decrypt_GH16(string textUser) {
    string alphabet = "PvGB]Q:LYf[S/q_id>O1b+%m3eTZ7g0^p&ENtMH8nx{y}#h5JozCK2XwIcl?F,R!DU@Vja9.rkW')6u-4=A(s*";
    char countEnPO = alphabet.length();

    //for (short i = 0; i < textUser.length(); i+2) {
    //    for (short j = 1; j < textUser.length(); j+2) {
    //        for (short k = 2; k < textUser.length(); k+2) {
    //            for (short q = 0; q < countEnPO; q++) {
    //                textUser[j] = alphabet[(j - 3) % countEnPO];
    //            }
    //        }
    //    }
    //}

    for (short i = 1; i < textUser.length(); i++) {
        for (short j = 0; j < countEnPO; j++) {
            textUser[i] = alphabet[(j - 3) % countEnPO];
        }
    }

    if (copyToBuffer(textUser)) { cout << "The text has been copied to the clipboard!" << endl; }
    else { cout << "The text was not copied to the clipboard due to an error!" << endl; }

    return textUser;
}