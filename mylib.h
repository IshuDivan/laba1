#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Bricks{
public:
	int  num;	
	string form;
	string colour;
	friend std::ostream& operator<< (std::ostream &out, const Bricks &br);
	friend std::istream& operator>> (std::istream &in,  Bricks &br);
};
std::ostream& operator<< (std::ostream &out, const Bricks &br);
void add (string namefile);
void search(string namefile);
void deleting(string namefile);
void allwrite(string namefile);
void allclear(string namefile);
