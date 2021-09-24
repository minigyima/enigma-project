#include <iostream>
#include <climits>
#include "../include/encoder.cpp"

int main()
{
	enutil *enutilObj = new enutil();
	int tarcsa[3];
	int kezdo[3];
	int err = 0;

	bool isEncrypt;

	std::cout << "Titkositas vagy visszafejtes (1, 0): ";
	std::cin >> isEncrypt;

	do
	{
		if (err != 0)
		{
			cout << "Nem jok a szamok!\n";
		}
		cout << "Irj be 3 kulombozo szamot 1-tol 5-ig: ";
		std::cin >> tarcsa[0] >> tarcsa[1] >> tarcsa[2];
		err++;
		for (int i = 0; i < 3; i++)
		{
			tarcsa[i] -= 1;
		}
	} while (!(tarcsa[0] < 5 && tarcsa[1] < 5 && tarcsa[2] < 5 && tarcsa[0] != tarcsa[1] && tarcsa[2] != tarcsa[1] && tarcsa[0] != tarcsa[2]));
	err = 0;
	do
	{
		if (err != 0)
		{
			cout << "Nem jok a szamok!\n";
		}
		cout << "Irj be 3 szamot 1-tol 26-ig: ";
		std::cin >> kezdo[0] >> kezdo[1] >> kezdo[2];
		err++;
		for (int i = 0; i < 3; i++)
		{
			kezdo[i] -= 1;
		}
	} while (!(kezdo[0] < 26 && kezdo[1] < 26 && kezdo[2] < 26));
	for (int i = 0; i < 3; i++)
	{
		tarcsa[i]++;
	}
	for (int i = 0; i < 3; i++)
	{
		kezdo[i]++;
	}

	cout << "\n Elfogadva\n Tarcsa 1: " << tarcsa[0] << " pozicio: " << kezdo[0] << ", Tarcsa 2: " << tarcsa[1] << " pozicio: " << kezdo[1] << ", Tarcsa 3: " << tarcsa[2] << " pozicio: " << kezdo[2];
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	encoder *enc = new encoder(tarcsa, kezdo, isEncrypt);
	const string end = "0";
	string text = "";
	char in;

	cout << "\n Add meg a kodolando szoveget: ";
	cin >> text;
	//getline(cin, text);
	while (text != end)
	{

		for (int i = 0; i < text.length(); i++)
		{
			//text[i] = toupper(text[i]);
			if (enutilObj->isLetter(text[i]))
			{
				in = text[i];
				in = enc->encode(in);
				text[i] = in;
			}
		}
		cout << "\n A kod: " << text;
		cout << "\n Add meg a kodolando szoveget: ";
		cin >> text;
	}
}