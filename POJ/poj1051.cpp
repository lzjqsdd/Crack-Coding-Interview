#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string code[128];

char decryption(string s)
{
	for(int i='A';i<='Z';i++)
		if(s==code[i]) return (char)i;

	if(s==code['.']) return '.';
	if(s==code['?']) return '?';
	if(s==code[',']) return ',';
	if(s==code['_']) return '_';
}

int main()
{
	code['A']=".-";code['B']="-...";code['C']="-.-.";code['D']="-..";
	code['E']=".";code['F']="..-.";code['G']="--.";code['H']="....";
	code['I']="..";code['J']=".---";code['K']="-.-";code['L']=".-..";
	code['M']="--";code['N']="-.";code['O']="---";code['P']=".--.";
	code['Q']="--.-";code['R']=".-.";code['S']="...";code['T']="-";
	code['U']="..-";code['V']="...-";code['W']=".--";code['X']="-..-";
	code['Y']="-.--";code['Z']="--..";code['_']="..--";code['.']="---.";
	code[',']=".-.-";code['?']="----";

	string origin_s,entry_s,decry_s;
	int len[101];
	int i=1,n;
	cin>>n;
	while(i<=n)
	{
		entry_s.clear();decry_s.clear();
		cin>>origin_s;
		for(int j=0;j<origin_s.length();j++)
		{
			entry_s+=code[origin_s[j]];
			len[j]=code[origin_s[j]].length();
		}

		cout<<i<<": ";
		int pos = 0;
		for(int k=origin_s.length()-1;k>=0;k--)
		{
			cout<<decryption(entry_s.substr(pos,len[k]));
			pos+=len[k];
		}
		cout<<endl;
		i++;
	}

	return 0;

}

