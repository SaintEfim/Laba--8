#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
int main();
void Main_Menu_Text();
void Main_Menu(list <int>& List1, list <int>& List2, int& choice, int& element, int& count, int& value, int Buf[128]);
void CreatingaList_Text();
void CreatingaList(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128]);
void SelectingaListActionText();
void SelectingaListAction(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128]);
void CompletionList(list <int>& List1, int& element, int& count);
void TwoLists(list <int>& List1,int& choice, int& element, int& count, int& value, int Buf[128]);
bool FindCheck(list <int>& List1, int& element);
bool Find(list <int>& List1);
void Emptiness(list <int>& List1);
int main()
{
    setlocale(LC_ALL, "RU");
    list <int> List1, List2;
    int choice,element, count, value, Buf[128];
    int* pBuf = Buf;
    Main_Menu_Text();
    Main_Menu(List1, List2, choice, element, count, value, Buf);
    do {
        SelectingaListActionText();
        SelectingaListAction(List1, choice, element, count, value, Buf);
        if (choice > 14) {
            cout << "\n������! ������������ ���� ������. ���������� �����.\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
        }
    } while (choice!=14);
}
void Main_Menu_Text() {
    system("cls");
    cout << "����:\n\n"
        "1. ������ �� �������;\n"
        "2. �������������� �������;\n"
        "3. ����� �� ���������.\n"
        "\n��� �����: ";
}
void Main_Menu(list <int>& List1, list <int>& List2, int& choice, int& element, int& count, int& value, int Buf[128])
{
    cin >> choice;
    if (choice == 1) {
        system("cls");
        CreatingaList_Text();
        CreatingaList(List1, choice, element, count, value, Buf);
    }
    else if (choice == 2)
        TwoLists(List1,choice, element, count, value, Buf);
    else if (choice > 3) {
        cout << "\n������! ������������ ���� ������. ���������� �����.\n\n\a";
        system("pause");
        cin.ignore(256, '\n');
        main();
    }
    else
        exit(0);
}
void CreatingaList_Text() {
    cout << "����:\n\n"
        "1. �������� �������������� ������;\n"
        "2. �������� ���������������� ������;\n"
        "3. ����� �� ���������.\n"
        "\n��� �����: ";
}
void CreatingaList(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128])
{
    cin >> choice;

    if (choice == 1) {
        CompletionList(List1, element, count);
        List1.sort();
        cout << "������������� ������: ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 2) {
        CompletionList(List1, element, count);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 3)
        exit(0);
    else{
    cout << "\n������! ������������ ���� ������. ���������� �����.\n\n\a";
    system("pause");
    cin.ignore(256, '\n');
    CreatingaList(List1, choice, element, count, value, Buf);
    }
}
void SelectingaListActionText() {
    system("cls");
    cout<<"1.  ����� �������� � ������;\n"
        "2.  �������� ������� � ������ ������;\n"
        "3.  �������� ������� � ����� ������;\n"
        "4.  �������� ������� �� �������� � ������������ ��������� ��������������� ����;\n"
        "5.  �������� ������� ����� �������� � ������������ ��������� ��������������� ����\n"
        "6.  ������� ������ ������� ������;\n"
        "7.  ������� ��������� ������� ������;\n"
        "8.  ������� ������� � ������������ ��������� ��������������� ����;\n"
        "9.  ������� ���� ������;\n"
        "10. ����� ������ ������� ������;\n"
        "11. ����� ��������� ������� ������;\n"
        "12. ����� ������� � ������������ ��������� ��������������� ����;\n"
        "13. �������� ����� ������;\n"
        "14. ����� �� ���������.\n"
        "\n��� �����: ";
}
void SelectingaListAction(list <int>& List1, int &choice,int & element,int & count,int &value,int Buf[128])
{
    list <int> ::iterator itr;
    cin >> choice;

    if (choice == 1) {
        Find(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 2) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t  | ���������� �������� � ������ ������ |\n\n\n";
        cout << "������� �������: "; cin >> element; cout << "\n\n";
        List1.push_front(element);        // ���������� �������� � ������ ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 3) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t | ���������� �������� � ����� ������ |\n\n\n";
        cout << "������� �������: "; cin >> element; cout << "\n\n";
        List1.push_back(element);          // ���������� �������� � ����� ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 4) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t   | ���������� ��������  �� �������� � ������������ ��������� ��������������� ���� |\n\n\n";
        cout << "������� ���������� ��������� : "; cin >> count; cout << "\n";
        Buf[count];

        cout << "������� �������� ����� �������� ���������� �������� �����: ";
        for (int i = 0; i < count; i++)
        {
            cin >> value;
            while (!FindCheck(List1, value))
            {
                cout << "\n\n������! �������� ���� �� ��������� ��������� ����������� � ������!\a\n\n";
                system("pause");
                cin.ignore(256, '\n');
                SelectingaListAction(List1, choice, element, count, value, Buf);
            }
            Buf[i] = value;
        }
        cout << "\n\n";
        cout << "������� ����� ��������: ";
        itr = List1.begin();
        for (int i = 0; i < count; i++)
        {
            if ((*itr) == Buf[i])
            {
                cin >> element;
                List1.emplace(itr, element);  // ��������� ����� ������� �� ������� �� ������� ��������� ��������
                itr++;
            }
        }
        cout << "\n\n";
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 5) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t| ���������� �������� ����� �������� � ������������ ��������� ��������������� ���� |\n\n\n";
        cout << "������� ���������� ��������� : "; cin >> count; cout << "\n";
        Buf[count];

        cout << "������� �������� ����� ������� ���������� �������� �����: ";
        for (int i = 0; i < count; i++)
        {
            cin >> value;
            while (!FindCheck(List1, value))
            {
                cout << "\n\n������! �������� ���� �� ��������� ��������� ����������� � ������!\a\n\n";
                system("pause");
                cin.ignore(256, '\n');
                SelectingaListAction(List1, choice, element, count, value, Buf);
            }
            Buf[i] = value;
        }
        cout << "\n\n";
        cout << "������� ����� ��������: ";
        itr = List1.begin();
        for (int i = 0; i < count; i++)
        {
            while ((*itr) != Buf[i])
            {
                itr++;
            }
            itr++;
            cin >> element;
            List1.emplace(itr, element);   // ��������� ����� ������� �� �������
        }                                 // �� ������� ��������� ��������
        cout << "\n\n";
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 6) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t   | �������� ������� �������� ������ |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.pop_front();       // ������� ������ ������� ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 7) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t| �������� ���������� �������� ������ |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.pop_back();        // ������� ��������� ������� ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 8) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t   | �������� �������� � ������������ ��������� ��������������� ���� |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "������� ������� �� ������, ������� ���������� ������� : "; cin >> element; cout << "\n";
        while (!FindCheck(List1, element))
        {
            cout << "\n\n������! ��������� ������� ����������� � ������!\a\n\n";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }

        itr = List1.begin();
        while ((*itr) != element)
        {
            itr++;
        }
        List1.erase(itr);          // ������� �������, �� ������� ��������� ��������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 9) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t\t| �������� ����� ������ |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.clear();      // ������� ���� ������
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 10) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t    | �������� � �������� ������� �������� ������ |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "������ ������� ������: | " << List1.front() << " |" << "\n\n";
        List1.pop_front();              // ������� ������ ������� ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 11) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t  | �������� � �������� ���������� �������� ������ |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "��������� ������� ������: | " << List1.back() << " |" << "\n\n";
        List1.pop_back();               // ������� ��������� ������� ������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 12) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t| �������� � �������� �������� ������ � ������������ ��������� ��������������� ���� |\n\n\n";
        if (List1.empty())
        {
            cout << "\n������! ������ ����!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }

        while (!FindCheck(List1, element))
        {
            cout << "\n\n������! ��������� ������� ����������� � ������!\a\n\n";
            system("pause");
            cin.ignore(256, '\n');    cout << "������� ������� �� ������: "; cin >> element; cout << "\n";
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "�������� ������� ������ � ������: | ";
        itr = List1.begin();
        while ((*itr) != element)
        {
            itr++;
        }
        cout << (*itr) << " |" << "\n\n";
        List1.erase(itr);          // ������� �������, �� ������� ��������� ��������
        cout << "������ �������:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 13) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t\t | �������� ����� ������ |\n\n\n";
        cout << "���� ������: ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        system("pause");
    }
}
void CompletionList(list <int>& List1, int& element, int& count)
{
    system("cls");
    Emptiness(List1);
    cout << "������� ���������� ���������: "; cin >> count; cout << "\n";
    cout << "��������� ������ " << count << "� ����������: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "List[" << i << "]=";
        cin >>element;
        List1.push_back(element);
    }
    system("cls");
    cout << "����������� ������:   ";
    cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
    cout << "\n\n";
    Emptiness(List1);
    cout << "\n";

}
void TwoLists(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128])
{
    system("cls");
    cout << "\n\t\t\t\t\t      | ���������� ������� ������ |\n\n\n";
    system("pause");
    CompletionList(List1, element, count);
    List1.reverse();
}
bool FindCheck(list <int>& List1, int& element)
{
    list <int> ::iterator itr;
    itr = std::find(List1.begin(), List1.end(), element);
    return itr != List1.end();
}
bool Find(list <int>& List1)
{
    system("cls");
    int element;
    string Str;
    list <int> ::iterator itr;

    cout << "������� ������� ������� ������: "; cin >> element;  cout << "\n\n";
    itr = std::find(List1.begin(), List1.end(), element);

    if (itr != List1.end())
    {
        Str = "������������";
        cout << "������� ������� " << Str << " � ������\n\n";

    }
    else
    {
        Str = "�����������";
        cout << "������� ������� " << Str << " � ������\n\n";
    }
    return itr != List1.end();
}
void Emptiness(list <int>& List1)
{
    string Str;
    try
    {
        if (List1.empty())
        {
            throw 0;
        }
        else
        {
            throw 1;
        }
    }
    catch (int i)
    {
        if (i == 0)
        {
            Str = "����";
            cout << "��������� ������: " << Str << "\n\n";
        }
        if (i == 1)
        {
            Str = "��������";
            cout << "��������� ������: " << Str << "\n\n";
        }
    }

}







