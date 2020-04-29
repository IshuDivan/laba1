#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
struct bricks{
	int  num;	
	string form;
	string colour;
};
void add (string namefile);
void search(string namefile);
void deleting(string namefile);
void allwrite(string namefile);
void allclear(string namefile);

