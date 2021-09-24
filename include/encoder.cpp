#include "Rotor.cpp"
#include "enutil.cpp"
using namespace std;

/* 
    encoder.cpp - 2021-09-23
    Encoder class JEJ
    Kópirájt kodolas3 (megint csak xd)
*/

class encoder
{
private:
    rotor *rotor1;
    rotor *rotor2;
    rotor *rotor3;
    enutil *enutilObj;
    bool encrypt;

public:
    encoder(int platters[], int start[], bool encrypt);
    ~encoder();
    char encode(char letter);
};

encoder::encoder(int platters[], int start[], bool encrypt = true)
{
    this->enutilObj = new enutil();
    this->encrypt = encrypt;

    for (int i = 0; i < 3; i++)
    {
        std::vector<int> pair;

        // Most tényleg ennyire túl kellett ezt komplikálni?
        // Válasz: IGEN, lol
        // Tényleg nem szeretem a cpp-t
        // De nem baj
        switch (platters[i])
        {
        case 1:
            pair = this->enutilObj->firstRotor;
            break;
        case 2:
            pair = this->enutilObj->secRotor;
            break;
        case 3:
            pair = this->enutilObj->thirdRotor;
            break;
        case 4:
            pair = this->enutilObj->fourthRotor;
            break;
        case 5:
            pair = this->enutilObj->fifthRotor;
            break;
        default:
            break;
        }

        // Mi a ferde fasz
        switch (i)
        {
        case 0:
            this->rotor1 = new rotor(pair, start[i]);
            break;
        case 1:
            this->rotor2 = new rotor(pair, start[i]);
            break;
        case 2:
            this->rotor3 = new rotor(pair, start[i]);
            break;

        default:
            break;
        }
    }
}

encoder::~encoder()
{
    delete this->enutilObj;
    delete this->rotor1;
    delete this->rotor2;
    delete this->rotor2;
}
char encoder::encode(char letter)
{
    // Karakterből számba konverál
    int charNum;

    int res1, res2, res3;

    char result, enigma, swap;

    // Encode - decode
    if (this->encrypt)
    {
        /* 
            Encrypt:
             - Szám
             - Rotorok
             - Betűcsere
             - Betű újra
        */

        charNum = enutilObj->charToKey(&letter);

        res1 = this->rotor1->encode(charNum);
        res2 = this->rotor2->encode(res1);
        res3 = this->rotor3->encode(res2);
        /*
        if (rotor1->addPos()) {
            if (rotor2->addPos()) {
                rotor3->addPos();
            }
        }*/

        enigma = enutilObj->keyToChar(res3);
        result = enutilObj->letterSwap(enigma);
    }
    else
    {
        /* 
            Decrypt:
             - Betűcsere
             - Szám
             - Rotorok
             - Betű újra
        */

        swap = enutilObj->letterSwap(letter);
        charNum = enutilObj->charToKey(&swap);

        res1 = this->rotor3->decode(charNum);
        res2 = this->rotor2->decode(res1);
        res3 = this->rotor1->decode(res2);
        /*
        if (rotor1->addPos()) {
            if (rotor2->addPos()) {
                rotor3->addPos();
            }
        }*/

        result = enutilObj->keyToChar(res3);
    }

    this->rotor1->writePosition();
    // this->rotor2->writePosition();
    // this->rotor3->writePosition();

    // Karakterbe visszafele, kérem alásan
    return result;
}