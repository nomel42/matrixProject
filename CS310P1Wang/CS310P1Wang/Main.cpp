#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	//part 1
	//ASCII code 48 or 0x30	%c = char, 
	//(%i,%d = int), (%f = float), (%x = hex)

	char first = '0';
	for (int i = 0; i < 10; i++)
		printf("%c    %d    %x\n", first + i, first + i, first + i);

	printf("\n");

	//part 2

	// J = 0100 1010
	// j = 0110 1010 
  //0x20 = 0010 0000
	//     0100 1010

	// uppercase + 0x20 = lowercase
	// uppercase = lowercase - 0x20 
	//char c = 'j' - 0x20; ////hex :) :P :L >:( ;_; (X.X)
	//char c2 = 'J' + 0x20; 
	//printf("%c	%c\n",c , c2);

	for (char c = 'J'; c <= 'N'; c++)
	{
		printf("%c => %x	%c => %x \n", c, c, c + 32, c + 0x20);
	}
	printf("\n");
	//part 3


	int val;
	do
	{
		cout << "Press 1 to enter uppercase, 2 to enter lower case" << endl;
		cin >> val;
		if (val != 1 && val != 2)
			cout << "you are is fired!" << endl;
	} while (val != 1 && val != 2);

	char chara;
	if (val == 1)
	{

		cout << "Type a uppercase letter" << endl;
		cin >> chara;
		printf("%c => %c \n", chara, chara + 0x20);
	}
	else
	{
		cout << "Type a lowercase letter" << endl;
		cin >> chara;
		printf("%c => %c \n", chara, chara - 0x20);
	}

	printf("\n");

	//part 4

	//yay bit shifting ->>>>>>>
	string magic;
	cout << "Enter a 2 character number (0-9)" << endl;
	cin >> magic;

	// 0 = 0011 0000
	// 1 = 0011 0001
	// 2 = 0011 0010
	// 3 = 0011 0011
	// 4 = 0011 0100
	// 5 = 0011 0101
	// 6 = 0011 0110
	// 7 = 0011 0111
	// 8 = 0011 1000
	// 9 = 0011 1001

	//   0x75 to binary
	//   0111 0101

	char c1 = magic[0];
	char c2 = magic[1];
	// 65
	// c1 = 0011 0110
	// c2 = 0011 0101
	//
	// temp c1 = c1 & 0000 1111
	// temp c1 = 0000 0110
	// temp c1 = 0110 0000
	// temp c2 = 0000 0101
	// OR        0110 0101
	// 0x65 -> 0110 0101 
	int packed = ((c1 & 0x0f) << 4) ^ (c2 & 0x0f);
	printf("packed BCD = Binary coded decimal; %x \n \n", packed);
	
	//part 5
	int bcdVal;
	cout << "BCD to char (0-9)" << endl;
	scanf_s("%x", &bcdVal);
	printf("bcdVal = %x", bcdVal);

	// 0x000000f0 = 0000, 0000, 0000, 0000, 0000, 0000, 0000, 1111

	char mostAsc;
	char leastAsc;
	//  0011 0000 === 0,48 in decimal 
	mostAsc = ((bcdVal >> 4) & 0x0000000f) + 0x30;
	leastAsc = (bcdVal & 0x0000000f) + 0x30;
	cout << endl;
	cout << "ascii value is " << mostAsc << leastAsc << endl;
	return 0;
}