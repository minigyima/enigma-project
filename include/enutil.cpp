#include <string>
#include <fstream>
#include <vector>
using namespace std;
/* 
    enutil.cpp - 2021-09-23
    A zösszes konvertáló és egyéb helper cucc egy osztályba sűrítve
    Kópirájt kodolas3 (xd)
    Egészségére váljék!
*/

class enutil
{
private:
    // Olyan nincs
public:
    // Szegény Bence
    // Részvétem azért, hogy ezt be kellett gépelned
    string letters[27] = {"", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

    // Ez mondjuk nem köll
    enutil(/* args */);
    ~enutil();

    // Karakter transzformálás
    int charToKey(char *letter);
    char keyToChar(int key);

    // Karakter csere
    char letterSwap(char ch);

    // Karakter ellenőrző
    bool isLetter(char in);

    /*      
        WTF Hardcodeolt random rotorok?
        Ömm... Hát.. Igen.
        Ez nem a legjobb megoldás de leszarom xd
    */
    std::vector<int> firstRotor = {0, 23, 3, 2, 13, 17, 26, 9, 16, 7, 20, 19, 21, 4, 25, 18, 8, 5, 15, 11, 10, 12, 24, 1, 22, 14, 6};
    std::vector<int> secRotor = {0, 4, 17, 24, 1, 7, 16, 5, 14, 21, 13, 25, 18, 10, 8, 22, 6, 2, 12, 26, 23, 9, 15, 20, 3, 11, 19};
    std::vector<int> thirdRotor = {0, 14, 24, 11, 15, 10, 8, 21, 6, 17, 5, 3, 19, 20, 1, 4, 23, 9, 25, 12, 13, 7, 26, 16, 2, 18, 22};
    std::vector<int> fourthRotor = {0, 7, 24, 17, 25, 22, 11, 1, 16, 14, 19, 6, 13, 12, 9, 21, 8, 3, 20, 10, 18, 15, 5, 26, 2, 4, 23};
    std::vector<int> fifthRotor = {0, 16, 6, 17, 11, 12, 2, 22, 10, 21, 8, 4, 5, 19, 20, 24, 1, 3, 26, 13, 14, 9, 7, 25, 15, 23, 18};
};

enutil::enutil(/* args */)
{
    // Ide most kéne valami?
    // Lusta vagyok én a static classokhoz lol
}

enutil::~enutil()
{
    // -||-
}

/* 
    Köszönjük szépen Bésán Úr!
    Kommentek magyarázni és debuggolni ha esetleg valami félrecsúszna

    Karakterré alakítás értéke a result stringben
    Számmá alakítás értéke a k shortban
    funkció a karakterek számmá alakításához
    A visszatérő értéke (k) a szám; de ha hiba van akkor a visszaadott érték 44 
*/

int enutil::charToKey(char *letter)
{
    string ans = string(letter, 1);
    unsigned short k = 0;
    do
    {
        //cout << "No match \n";
        k++;
    } while (letters[k - 1] != ans && k < 27);
    if (k <= 27)
    {
        //cout << "Found it\n";
        k--;
    }
    else
    {
        //cout << "Error - no match\n";
        k = 44;
    }
    return k;
}

/* 
    Köszönjük Emese! (régi reklám xdd)
    Kulcsból csinál karaktertet
    A visszaadott érték egy 1 hosszúságú char 
*/

char enutil::keyToChar(int key)
{
    string letter = this->letters[key];
    return letter[0];
}

char enutil::letterSwap(char ch)
{
    char letters[20];

    bool isSet = false;

    ifstream fbe("betuparok.txt");

    int i = 0;
    while (fbe >> letters[i])
        i++;

    fbe.close();

    i = 0;
    while (isSet == false && i < 20)
    {
        if (ch == letters[i])
        {
            if (i % 2 == 0)
            {
                ch = letters[i + 1];
                isSet = true;
            }
            else if (i % 2 == 1)
            {
                ch = letters[i - 1];
                isSet = true;
            }
        }

        i++;
    }

    return ch;
}

// Input filter
// Számokat és egyéb gonosz dolgokat ne tessék bevenni
//                   8==============================D   11
bool enutil::isLetter(char in)
{
    in = toupper(in); //nagybetűkké alakítja a bemenetet a könnyebb feldolgozás érdekében
    bool isLetter = 0;
    for (int i = 1; i < 27; i++)
    {
        if (in == this->letters[i][0])
        {
            isLetter = 1;
        }
    }
    if (&in == " ")
    {
        isLetter = 0;
    }
    return isLetter;
}