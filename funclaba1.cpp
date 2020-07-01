
#include "mylib.h"
using namespace std;
std::ostream& operator<< (std::ostream &out, const Bricks &br)
{
    out << br.num  << " " << br.colour << " " << br.form<< endl;
    return out;
}
std::istream& operator>> (std::istream &in,  Bricks &br)
{
    in >> br.num; 
    in >> br.colour;
    in >> br.form;
    return in;
}
void add (string namefile)
{//Добавление объектов на склад(либо новый тип, либо плюс к старому)
	ifstream fin;
	ofstream fout;
	fin.open(namefile);	
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		k++;
	}
	k--;
	Bricks *a = new Bricks[k+1];
	fin.close();
	fin.open(namefile);	
	for (i=0; i<k; i++){
		fin >> a[i];//Считываем элементы из файла, заодно выводим на экран все текущие элементы
	}
	int num, j;
	int tmp=-1;//Флаг для поиска совпадений
	string colour;
	string form;
	cin >> num  >>colour>> form;//Непосредственно, сколько каких кирпичей хотят добавить
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
				fout << a[i];
			}
			else {
				fout<< a[k];

			}
		}
	}
	else {//Флаг поменялся->Было совпадение ->Переписываем сам массив
		fout.open(namefile, ios::out);	//Открываем пустой файл	
		for (i=0; i<k; i++){//Переписываем в файл массив, нужная строчка уже исправлена
			fout << a[i];
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
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Bricks *a = new Bricks[k+1];
	fin.close();
	fin.open(namefile);
	for (i=0; i<k; i++){
		fin >> a[i];//Считываем элементы из файла, заодно выводим на экран все текущие элементы
	}
	int num;
	int tmp=-1;
	string colour;
	string form;
	cin >> num >>colour >> form;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
		if ((a[i].form== form)&&(a[i].colour== colour)){//Ищем соответствующие признаки
			if (num>a[i].num){//Если просят удалить больше, чем есть на складе
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
				fout << a[i];
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
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Bricks *a = new Bricks[k+1];
	fin.close();
	fin.open(namefile);
	for (i=0; i<k; i++){
		fin >> a[i];//Считываем элементы из файла, заодно выводим на экран все текущие элементы
	}	
	int num;
	int tmp=-1;
	string colour;
	string form;
	cin >>colour >> form;//Считываем данные об удаляемом типе объектов
	for (i=0; i<k; i++){ 
		if ((a[i].form== form)&&(a[i].colour== colour)){//Ищем соответствующие признаки
			cout << a[i];
			tmp=1;		
		} 
	}
	if (tmp==-1){
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
	f.open(namefile, ios::out);//EZ
	f.close();
}
