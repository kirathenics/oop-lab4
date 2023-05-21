#include <string>
#include "Arctan.h"
#include "Arccot.h"
#include "Derivative.h"
#include "Collection.h"

int main()
{
	setlocale(0, "");

	cout << "������� �� ����������:" << endl
		<< "�������� ���������, � ������� ������� �������� �������: ������� �� ����� ����������(����������, ������������, � ����� �����, ����������� ��� ������������� �����������)." << endl
		<< "������� ����� ��� �������� ��������� ������� (������� ���������� �� ������� �����), � ������� ����������� �������� �[]�." << endl
		<< "������� ����� - �������� ��� �������� �� ��������� ���������." << endl
		<< "��� �������� ������ � ��� �������� ����������� �������� �==�, �!=�, �=�." << endl
		<< "������������������ ������ ����������." << endl;

	Collection collection;
	int action = 1;
	while (action)
	{
		cout << "�������� ��������:" << endl
			<< "0. ����� �� ���������" << endl
			<< "1. ������� ��������� �������" << endl
			<< "2. �������� ������ � ����� ���������" << endl
			<< "3. �������� ������ � �������� ���������" << endl
			<< "4. ������� �������� ���������" << endl
			<< "5. ������� ������ �� �������� ���������" << endl
			<< "6. ��������� �������� ������� ������� � ���������" << endl
			<< "7. �������������� ������ � ���������" << endl
			<< "8. ������� ���������� ���������" << endl
			<< "9. ��������� ��������� ���������" << endl;

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
				cout << "������� ������ ����������� ���������: ";
				cin >> size;
				cin.ignore();

				Collection temp(size);
				for (int i = 0; i < size; i++)
				{
					cout << "�������� ��� ������� (arctg, arcctg, der) ��������� ��� ������� " << i << ": ";
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
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ��� ������� (arctg, arcctg, der) ��� ���������� � ���������: ";
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
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ������� ������� (��������� ���������� � 0): ";
				int index;
				cin >> index;
				cout << "�������� ��� ������� (arctg, arcctg, der) ��� ���������� � ���������: ";
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
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ������� �������, ����� ������� ����� ������� �������� (��������� ���������� � 0): ";
				int index;
				cin >> index;
				collection.truncation(index);
				break;
			}

			case 5:
			{
				if (!collection.getSize())
				{
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ������� ������� (��������� ���������� � 0): ";
				int index;
				cin >> index;
				collection.erase(index);
				break;
			}

			case 6:
			{
				if (!collection.getSize())
				{
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ������� ������� (��������� ���������� � 0): ";
				int index;
				cin >> index;
				cout << "������� �������� ��������� �������: ";
				double argumentValue;
				cin >> argumentValue;
				cout << "���������: " << collection[index]->operator()(argumentValue) << endl;
				break;
			}

			case 7:
			{
				if (!collection.getSize())
				{
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "�������� ������� ������� (��������� ���������� � 0): ";
				int index;
				cin >> index;
				cout << "�������� ��� ������� (arctg, arcctg, der) ��� ���������� � ���������: ";
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
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				cout << "������ �������� ���������:" << endl;
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
					cout << "��������� ��� �� �������!" << endl;
					break;
				}

				int firstIndex, secondIndex;
				cout << "������� ����� ������� �������� ���������: ";
				cin >> firstIndex;
				cout << "������� ����� ������� �������� ���������: ";
				cin >> secondIndex;
				cout << "��������� ���������� �������� ���������: " << (collection[firstIndex] == collection[secondIndex]) << endl;
				break;
			}

			default:
				cout << "������ �������� ���!" << endl;
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