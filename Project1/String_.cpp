// ¹®ÀÚ¿­


#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char ch;
	
	while (true)
	{
		cin.get(ch);
		
		if(ch == '\n') break;
		cout << ch;

	}


}