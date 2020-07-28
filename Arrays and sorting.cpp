#include <iostream>
#include <string>

using namespace std;

struct node
{
	string name;
	int id;
};

class Data
{
public:
	void SortByName();
	void SortByID();
	void DataEntry();
	Data()
	{
		size = 5;
		employee = new node[size];
		counter = 0;
	}
private:
	int size;
	int counter;
	node* employee;
	void SizeIncrease();
	int AsciiTotal(string&);
};

void Data::DataEntry()
{

	cout << "Leave the name space empty to terminate adding to the list\n";
	string name;
	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "Name: ";
		getline(cin, name);
		if (name == "")
			break;
		else
		{
			(employee + counter)->name = name;
			cout << "ID: ";
			cin >> (employee + counter)->id;
			counter++;
			if (counter >= size)
				SizeIncrease();
		}
	}
}

void Data::SortByID()
{
	int small,place;
	string smalln;
	if (counter > 1)
	{
		for (int j = 0; j < counter - 1; j++)
		{
			place = j;
			for (int i = j + 1; i < counter; i++)
			{
				if ((employee + i)->id < (employee + place)->id)
				{
					small = (employee + i)->id;
					smalln = (employee + i)->name;
					place = i;
				}
			}
			if (place == j);
			else
			{
				(employee + place)->id = (employee + j)->id;
				(employee + place)->name = (employee + j)->name;
				(employee + j)->id = small;
				(employee + j)->name = smalln;
			}
		}
	}
	else cout << "There is only one data entry. It is already sorted\n";
	for (int i = 0; i < counter; i++)
	{
		cout << "Name: " << (employee + i)->name << endl;
		cout << "ID: " << (employee + i)->id << endl;
	}
	system("pause");
}

void Data::SortByName()
{
	int small, place;
	string smalln;
	if (counter > 1)
	{
		for (int j = 0; j < counter - 1; j++)
		{
			place = j;
			for (int i = j + 1; i < counter; i++)
			{
				if ((employee + i)->name.at(0) < (employee + place)->name.at(0))
				{
					small = (employee + i)->id;
					smalln = (employee + i)->name;
					place = i;
				}
			}
			if (place == j);
			else
			{
				(employee + place)->id = (employee + j)->id;
				(employee + place)->name = (employee + j)->name;
				(employee + j)->id = small;
				(employee + j)->name = smalln;
			}
		}
	}
	else cout << "There is only one data entry. It is already sorted\n";
	for (int i = 0; i < counter; i++)
	{
		cout << "Name: " << (employee + i)->name << endl;
		cout << "ID: " << (employee + i)->id << endl;
	}
	system("pause");
}

int Data::AsciiTotal(string& name)
{
	int total = 0;
	for (int i = 0; i < name.length(); i++)
		total += name.at(i);
	return total;
}

void Data::SizeIncrease()
{
	node* temp = new node[size * 2];
	for (int i = 0; i < size; i++)
		*(temp + i) = *(employee + i);
	employee = temp;
	size *= 2;
}

int main()
{
	Data d;
	char op;
	do
	{
		system("cls");
		cout << "1. Enter List\n";
		cout << "\n2. Sort by ID\n";
		cout << "\n3. Sort by Name\n";
		cout << "\nChoose: ";
		cin >> op;
		switch (op)
		{
		case '1':
			d.DataEntry();
			break;
		case '2':
			d.SortByID();
			break;
		case '3':
			d.SortByName();
			break;
		default:
			cout << "Choose from the following\n";
			system("pause");
			system("cls");
			break;
		}
	} while (true);
}


