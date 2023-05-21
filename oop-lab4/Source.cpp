#include <string>
#include "Arctan.h"
#include "Arccot.h"
#include "Derivative.h"
#include "Collection.h"

int main()
{
	setlocale(0, "");

	cout << "Задание на выполнение:" << endl
		<< "Написать программу, в которой описана иерархия классов: функция от одной переменной(арктангенс, арккотангенс, а также класс, необходимый для представления производных)." << endl
		<< "Описать класс для хранения коллекции функций (массива указателей на базовый класс), в котором перегрузить операцию «[]»." << endl
		<< "Описать класс - итератор для итерации по элементам коллекции." << endl
		<< "Для базового класса и его потомков перегрузить операции «==», «!=», «=»." << endl
		<< "Продемонстрировать работу операторов." << endl;

	Collection collection;
	int action = 1;
	while (action)
	{
		cout << "Выберите действие:" << endl
			<< "0. Выйти из программы" << endl
			<< "1. Создать коллекцию функций" << endl
			<< "2. Добавить объект в конец коллекции" << endl
			<< "3. Вставить объект в середину коллекции" << endl
			<< "4. Сделать усечение коллекции" << endl
			<< "5. Удалить объект из середины коллекции" << endl
			<< "6. Вычислить значение функции объекта в коллекции" << endl
			<< "7. Переопределить объект в коллекции" << endl
			<< "8. Вывести содержимое коллекции" << endl
			<< "9. Сравнение элементов коллекции" << endl;

		try
		{
			cin >> action;
			switch (action)
			{
			case 0:
				break;

			case 1:
			{
				int size;
				cout << "Введите размер создаваемой коллекции: ";
				cin >> size;
				cin.ignore();

				Collection temp(size);
				for (int i = 0; i < size; i++)
				{
					cout << "Выберите тип объекта (arctg, arcctg, der) коллекции под номером " << i << ": ";
					string type;
					getline(cin, type);
					if (type == "arctg") temp[i] = new Arctan();
					if (type == "arcctg") temp[i] = new Arccot();
					if (type == "der") temp[i] = new Derivative(new Arctan());
				}
				collection = temp;

				break;
			}

			case 2:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите тип объекта (arctg, arcctg, der) для добавления в коллекцию: ";
				cin.ignore();
				string type;
				getline(cin, type);
				if (type == "arctg") collection.pushBack(new Arctan());
				if (type == "arcctg") collection.pushBack(new Arccot());
				if (type == "der") collection.pushBack(new Derivative());
				break;
			}

			case 3:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите позицию объекта (нумерация начинается с 0): ";
				int index;
				cin >> index;
				cout << "Выберите тип объекта (arctg, arcctg, der) для добавления в коллекцию: ";
				cin.ignore();
				string type;
				getline(cin, type);
				if (type == "arctg") collection.insert(new Arctan(), index);
				if (type == "arcctg") collection.insert(new Arccot(), index);
				if (type == "der") collection.insert(new Derivative(), index);
				break;
			}

			case 4:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите позицию объекта, после которой нужно сделать усечение (нумерация начинается с 0): ";
				int index;
				cin >> index;
				collection.truncation(index);
				break;
			}

			case 5:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите позицию объекта (нумерация начинается с 0): ";
				int index;
				cin >> index;
				collection.erase(index);
				break;
			}

			case 6:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите позицию объекта (нумерация начинается с 0): ";
				int index;
				cin >> index;
				cout << "Введите значение аргумента функции: ";
				double argumentValue;
				cin >> argumentValue;
				cout << "Результат: " << collection[index]->operator()(argumentValue) << endl;
				break;
			}

			case 7:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Выберите позицию объекта (нумерация начинается с 0): ";
				int index;
				cin >> index;
				cout << "Выберите тип объекта (arctg, arcctg, der) для добавления в коллекцию: ";
				cin.ignore();
				string type;
				getline(cin, type);
				if (type == "arctg") collection[index] = new Arctan();
				if (type == "arcctg") collection[index] = new Arccot();
				if (type == "der") collection[index] = new Derivative();
				break;
			}

			case 8:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				cout << "Адреса объектов коллекции:" << endl;
				Iterator it = collection.begin();
				while (it != collection.end())
				{
					cout << *it << endl;
					++it;
				}
				break;
			}

			case 9:
			{
				if (!collection.getSize())
				{
					cout << "Коллекция ещё не создана!" << endl;
					break;
				}

				int firstIndex, secondIndex;
				cout << "Введите номер первого элемента коллекции: ";
				cin >> firstIndex;
				cout << "Введите номер второго элемента коллекции: ";
				cin >> secondIndex;
				cout << "Результат логической операции сравнения: " << (collection[firstIndex] == collection[secondIndex]) << endl;
				break;
			}

			default:
				cout << "Такого действия нет!" << endl;
				break;
			}
			cout << endl;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl << endl;
		}
	}

	return 0;
}