#include "mylib.h"//Подключаем заголовочный файл
using namespace std;
int main(int argc, char *argv[]){
	string namefile; 
	namefile=argv[1];
	cout << "Good morning."<<endl;
	string s;//На случай смены файла с данными
	int n;
	int k=0;
	fstream file1;
	fstream file2;
	while (k==0){//Цикл по k
		cout <<"Your Database name right now is: "<< namefile<<endl;
		cout <<"Press:"<<endl;
		cout <<"1- to see all our materials"<<endl;
		cout <<"2- to find specific bricks type"<<endl;
		cout <<"3- to add materials"<<endl;
		cout <<"4- to delete materials"<<endl;
		cout <<"8- to clear all database"<<endl;
		cout <<"9- to change database"<<endl;
		cout <<"0- to stop working with database"<<endl;
		cin >> n;
		void (*func)(string namefile);//Указатель на функцию
		switch (n){
		case 0:
			exit(0);
		break;
		case 1:
			func=allwrite;
		break;
		case 2:
			func=search;
		break;
		case 3:
			func=add;
		break;
		case 4:
			func=deleting;
		break;
		case 8:
			func=allclear;
		break;
		case 9:
			cout <<"Please enter new database name:(txt file!)"<<endl;
			cin >> s;
			
			file2.open(s);
			if(!file2){
				cout <<"Sorry, database can not be found. Please try again"<<endl;
			}
			else{	
				cout<<"Database changed sucsessfully"<<endl;
				namefile=s;			
			}
			file2.close();break;
		default:
			cout<<"You uncorrect data. Please, try again"<<endl;
		break;
		}
		if ((n==1)||(n==2)||(n==3)||(n==4)||(n==8)){
			func(namefile);	//Вызов соответствующей функции
		}
	}
	return 0;
}
