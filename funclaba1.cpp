#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "mylib.h"
using namespace std;
void add (string namefile)
{//Добавление объектов на склад(либо новый тип, либо плюс к старому)
	ifstream fin;
	ofstream fout;
	fin.open(namefile);	
	int  i=0;
	int k=0;
	string s;
	cout << "Enter the bricks you want to put('number color form')"<<endl;
	while (!fin.eof()){//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		k++;
	}
	k--;
	bricks *a = new bricks[k+1];//Выделяем память на массив типа  struct(с запасом)
	//fin.seekg( 0 );//Не забываем вернуть курсор в начало
	fin.close();//Убираем за собой
	fin.open(namefile);	
	for (i=0; i<k; i++){
		fin >> a[i].num ;
		
		fin >> a[i].colour;
		
		fin >> a[i].form;
		//Считываем элементы из файла, заодно выводим на экран все текущие элементы
		
	}
	int num, j;
	int tmp=-1;//Флаг для поиска совпадений
	string colour;
	string form;
	cin >> num  >>colour>> form;//Непосредственно, сколько каких кирпичей хотят добавить
	cout<< num<<endl<<colour<<endl<<form<<endl;
for (i=0; i<k; i++){
		if ((a[i].form== form)&&(a[i].colour== colour)){//Сравниваем параметры 
			a[i].num=a[i].num+num;
			tmp=i;//Меняем флаг
		}
	}
	fin.close();//Готовимся полностью очистить файл
	if (tmp==-1){//Флаг не поменялся-> Не было совпадений -> Дописываем в конец
		a[k].num= num;//заполняем предусмотрительно выделенную лишнюю ячейку в массиве введенными данными
		a[k].colour=colour;
		a[k].form=form;
		fout.open(namefile, ios::out);//Мы снова в файле, но он теперь пустой
		for (i=0; i<k+1; i++){//Переписываем весь дополненный массив в документ
			if ((i<k)&&(a[i].num>0)){
				fout << a[i].num<<" "<< a[i].colour<<" "<< a[i].form<<endl;
			}
			else {
				fout<< num<<" "<< colour<<" "<< form<<endl;

			}
		}
	}
	else {//Флаг поменялся->Было совпадение ->Переписываем сам массив
		fout.open(namefile, ios::out);	//Открываем пустой файл	
		for (i=0; i<k; i++){//Переписываем в файл массив, нужная строчка уже исправлена
			fout << a[i].num<<" "<<  a[i].colour<<" "<< a[i].form<<endl;
		}
	}
	fout.close();//Убираем за собой
	delete [] a;//Убираем за собойх2
}
void deleting(string namefile){//Удаление элементов
	ifstream fin;
	ofstream fout;	
	fin.open(namefile);	
	int  i=0;
	int k=0;
	cout <<"Enter the bricks you want to delete('number color form')"<<endl;
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	bricks *a = new bricks[k+1];//Выделяем память на массив типа  struct(с запасом)
	fin.close();
	fin.open(namefile);
	for (i=0; i<k; i++){
		fin >> a[i].num >> a[i].colour >>a[i].form;//Считываем элементы из файла, заодно выводим на экран все текущие элементы
		cout << a[i].num <<" "<<  a[i].colour <<" "<<  a[i].form<< endl;
	}
	int num;
	int tmp=-1;
	string colour;
	string form;
	cout << "What do you want us to delete? Format 'number color form'"<< endl;
	cin >> num >>colour >> form;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
//cout<<a[i].form<<endl<<form;
		if ((a[i].form== form)&&(a[i].colour== colour)){//Ищем соответствующие признаки
			if (num>a[i].num){//Если просят удалить больше, чем есть на складе
				cout <<"Sorry, we have not enough materials"<<endl;
				tmp=-2;
			}
			if (a[i].num>=num) {//Удаление кирпичей через уменьшение параметра количества на введенное значение
				a[i].num=a[i].num-num;
				tmp=i;
			}
		}
	}
	if (tmp>-1){//Если мы уменьшали количество
		fin.close();
		fout.open(namefile, ios::out);//открываем пустой файл
		for (i=0; i<k; i++){//Запись измененного массива в файл
			if(a[i].num>0){//Доп. условие - если количество равно нулю, записано не будет
				fout <<a[i].num<<" "<< a[i].colour<<" "<< a[i].form<<endl;
			}
		}
	}

	fout.close();
	delete[]a;
}
void search(string namefile){//Удаление элементов
	ifstream fin;
	ofstream fout;	
	fin.open(namefile);	
	int  i=0;
	int k=0;
	cout <<"Enter the bricks you want to find(' color form')"<<endl;
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	bricks *a = new bricks[k+1];//Выделяем память на массив типа  struct(с запасом)
	fin.close();
	fin.open(namefile);
	for (i=0; i<k; i++){
		fin >> a[i].num >> a[i].colour >>a[i].form;//Считываем элементы из файла, заодно выводим на экран все текущие элементы
		cout << a[i].num <<" "<<  a[i].colour <<" "<<  a[i].form<< endl;
	}
	int num;
	int tmp=-1;
	string colour;
	string form;
	cin >>colour >> form;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
//cout<<a[i].form<<endl<<form;
		if ((a[i].form== form)&&(a[i].colour== colour)){//Ищем соответствующие признаки
			cout << a[i].num<< " "<<a[i].colour<<" "<<a[i].form<<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){
		cout<<"There's no such bricks"<<endl;
	}	
	fout.close();
	delete[]a;
}
void allwrite(string namefile){//Вывести все элементы на экран
	ifstream fin;
	fin.open(namefile);
	string s;
	while (!fin.eof()){//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		cout<<s<<endl;
	}
	fin.close();//Убираем за собой
}

void allclear(string namefile){//Очистить файл с данными
	ofstream f;
	f.open(namefile);//EZ
	f.close();
}

