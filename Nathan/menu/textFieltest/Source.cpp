#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <ctime>


using namespace std;



int main()
{
	int n;
	string line;
	ifstream myFile("art.txt");
	if (myFile.is_open())
	{
		while (getline(myFile,line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}
	
	
	PlaySound(TEXT("sod.wav"), NULL, SND_ASYNC);

	cin >> n;
	
	if (n == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

