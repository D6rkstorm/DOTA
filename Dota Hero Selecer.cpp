#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

struct Hero{
	string name;
	int role;
};

void findHero(Hero characters[], int c);

int main()
{
	ifstream infile;
	int i = 0;
	char cNum[1];
	Hero characters[113];

	infile.open("Hero.csv");
	if(infile.is_open())
	{
		int c = 0;
		while(infile.good())
		{
			infile.getline(characters[c].name,256,',');
			infile.getline(cNum,256,',');
			characters[c].role = atoi(cNum);
			i++;
			c++;
		}
		infile.close();
	}
	else
	{
		cout << "Error";
	}

}


void findHero(Hero characters[], int c)
{
	vector<string> arr;
	int result;
	cout << "------------What Position do you want to play?------------" << endl 
		 << "------------For Offlane Enter--3--------------------------" << endl
		 << "------------For Carry Enter--1----------------------------" << endl
		 << "------------For Mid Enter--2------------------------------" << endl
		 << "------------For Offlane Support Enter--4------------------" << endl
		 << "------------For Safelane Support Enter--5-----------------" << endl
		 << "------------Complete Random--6----------------------------" << endl;
	cin >> result;
	if(result == 6)
	{
		int r = (rand() % 113) + 1;
		cout << characters[r].name << endl;
	}
	for(int i = 0; i < c; i++)
	{
		if(characters[i].role == result)
			{arr.push_back(characters[i].name);}
	}
	int k = (rand() % arr.size()) + 1;
	cout << arr[k];
	cout << endl << "Finished" << endl;
}