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
            cout << "\nОшибка! Некорректный ввод данных. Попробуйте снова.\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
        }
    } while (choice!=14);
}
void Main_Menu_Text() {
    system("cls");
    cout << "Меню:\n\n"
        "1. Работа со списком;\n"
        "2. Индивидуальное задание;\n"
        "3. Выход из программы.\n"
        "\nВаш выбор: ";
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
        cout << "\nОшибка! Некорректный ввод данных. Попробуйте снова.\n\n\a";
        system("pause");
        cin.ignore(256, '\n');
        main();
    }
    else
        exit(0);
}
void CreatingaList_Text() {
    cout << "Меню:\n\n"
        "1. Создание упорядоченного списка;\n"
        "2. Создание неупорядоченного списка;\n"
        "3. Выход из программы.\n"
        "\nВаш выбор: ";
}
void CreatingaList(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128])
{
    cin >> choice;

    if (choice == 1) {
        CompletionList(List1, element, count);
        List1.sort();
        cout << "Упорядоченный список: ";
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
    cout << "\nОшибка! Некорректный ввод данных. Попробуйте снова.\n\n\a";
    system("pause");
    cin.ignore(256, '\n');
    CreatingaList(List1, choice, element, count, value, Buf);
    }
}
void SelectingaListActionText() {
    system("cls");
    cout<<"1.  Поиск элемента в списке;\n"
        "2.  Добавить элемент в начало списка;\n"
        "3.  Добавить элемент в конец списка;\n"
        "4.  Добавить элемент до элемента с определенным значением информационного поля;\n"
        "5.  Добавить элемент после элемента с определенным значением информационного поля\n"
        "6.  Удалить первый элемент списка;\n"
        "7.  Удалить последний элемент списка;\n"
        "8.  Удалить элемент с определенным значением информационного поля;\n"
        "9.  Удалить весь список;\n"
        "10. Взять первый элемент списка;\n"
        "11. Взять последний элемент списка;\n"
        "12. Взять элемент с определенным значением информационного поля;\n"
        "13. Просмотр всего списка;\n"
        "14. Выход из программы.\n"
        "\nВаш выбор: ";
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
        cout << "\t\t\t\t\t  | Добавление элемента в начало списка |\n\n\n";
        cout << "Введите элемент: "; cin >> element; cout << "\n\n";
        List1.push_front(element);        // Добавление элемента в начало списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 3) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t | Добавление элемента в конец списка |\n\n\n";
        cout << "Введите элемент: "; cin >> element; cout << "\n\n";
        List1.push_back(element);          // Добавление элемента в конец списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 4) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t   | Добавление элемента  до элемента с определенным значением информационного поля |\n\n\n";
        cout << "Введите количество элементов : "; cin >> count; cout << "\n";
        Buf[count];

        cout << "Введите элементы перед которыми необходимо вставить новые: ";
        for (int i = 0; i < count; i++)
        {
            cin >> value;
            while (!FindCheck(List1, value))
            {
                cout << "\n\nОшибка! Возможно один из введенных элементов отсутствует в списке!\a\n\n";
                system("pause");
                cin.ignore(256, '\n');
                SelectingaListAction(List1, choice, element, count, value, Buf);
            }
            Buf[i] = value;
        }
        cout << "\n\n";
        cout << "Введите новые элементы: ";
        itr = List1.begin();
        for (int i = 0; i < count; i++)
        {
            if ((*itr) == Buf[i])
            {
                cin >> element;
                List1.emplace(itr, element);  // Вставляем новый элемент на позицию на которую указывает итератор
                itr++;
            }
        }
        cout << "\n\n";
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 5) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t| Добавление элемента после элемента с определенным значением информационного поля |\n\n\n";
        cout << "Введите количество элементов : "; cin >> count; cout << "\n";
        Buf[count];

        cout << "Введите элементы после которых необходимо вставить новые: ";
        for (int i = 0; i < count; i++)
        {
            cin >> value;
            while (!FindCheck(List1, value))
            {
                cout << "\n\nОшибка! Возможно один из введенных элементов отсутствует в списке!\a\n\n";
                system("pause");
                cin.ignore(256, '\n');
                SelectingaListAction(List1, choice, element, count, value, Buf);
            }
            Buf[i] = value;
        }
        cout << "\n\n";
        cout << "Введите новые элементы: ";
        itr = List1.begin();
        for (int i = 0; i < count; i++)
        {
            while ((*itr) != Buf[i])
            {
                itr++;
            }
            itr++;
            cin >> element;
            List1.emplace(itr, element);   // Вставляем новый элемент на позицию
        }                                 // на которую указывает итератор
        cout << "\n\n";
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 6) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t   | Удаление первого элемента списка |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.pop_front();       // Удаляем первый элемент списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 7) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t| Удаление последнего элемента списка |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.pop_back();        // Удаляем последний элемент списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 8) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t   | Удаление элемента с определенным значением информационного поля |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "Введите элемент из списка, который необходимо удалить : "; cin >> element; cout << "\n";
        while (!FindCheck(List1, element))
        {
            cout << "\n\nОшибка! Введенный элемент отсутствует в списке!\a\n\n";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }

        itr = List1.begin();
        while ((*itr) != element)
        {
            itr++;
        }
        List1.erase(itr);          // Удаляем элемент, на который указывает итератор
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 9) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t\t| Удаление всего списка |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        List1.clear();      // Удаляем весь список
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 10) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t    | Просмотр и удаление первого элемента списка |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "Первый элемент списка: | " << List1.front() << " |" << "\n\n";
        List1.pop_front();              // Удаляем первый элемент списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 11) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t  | Просмотр и удаление последнего элемента списка |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "Последний элемент списка: | " << List1.back() << " |" << "\n\n";
        List1.pop_back();               // Удаляем последний элемент списка
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 12) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t| Просмотр и удаление элемента списка с определенным значением информационного поля |\n\n\n";
        if (List1.empty())
        {
            cout << "\nОшибка! Список пуст!\n\n\a";
            system("pause");
            cin.ignore(256, '\n');
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }

        while (!FindCheck(List1, element))
        {
            cout << "\n\nОшибка! Введенный элемент отсутствует в списке!\a\n\n";
            system("pause");
            cin.ignore(256, '\n');    cout << "Введите элемент из списка: "; cin >> element; cout << "\n";
            SelectingaListAction(List1, choice, element, count, value, Buf);
        }
        cout << "Заданный элемент найден в списке: | ";
        itr = List1.begin();
        while ((*itr) != element)
        {
            itr++;
        }
        cout << (*itr) << " |" << "\n\n";
        List1.erase(itr);          // Удаляем элемент, на который указывает итератор
        cout << "Список изменен:   ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        Emptiness(List1);
        cout << "\n\n";
        system("pause");
    }
    else if (choice == 13) {
        system("cls");
        Emptiness(List1);
        cout << "\t\t\t\t\t\t | Просмотр всего списка |\n\n\n";
        cout << "Весь список: ";
        cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
        cout << "\n\n";
        system("pause");
    }
}
void CompletionList(list <int>& List1, int& element, int& count)
{
    system("cls");
    Emptiness(List1);
    cout << "Введите количество элементов: "; cin >> count; cout << "\n";
    cout << "Заполните список " << count << "ю элементами: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "List[" << i << "]=";
        cin >>element;
        List1.push_back(element);
    }
    system("cls");
    cout << "Заполненный список:   ";
    cout << " | "; copy(List1.begin(), List1.end(), std::ostream_iterator<int>(cout, " | "));
    cout << "\n\n";
    Emptiness(List1);
    cout << "\n";

}
void TwoLists(list <int>& List1, int& choice, int& element, int& count, int& value, int Buf[128])
{
    system("cls");
    cout << "\n\t\t\t\t\t      | Заполнение первого списка |\n\n\n";
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

    cout << "Введите искомый элемент списка: "; cin >> element;  cout << "\n\n";
    itr = std::find(List1.begin(), List1.end(), element);

    if (itr != List1.end())
    {
        Str = "присутствует";
        cout << "Искомый элемент " << Str << " в списке\n\n";

    }
    else
    {
        Str = "отсутствует";
        cout << "Искомый элемент " << Str << " в списке\n\n";
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
            Str = "пуст";
            cout << "Состояние списка: " << Str << "\n\n";
        }
        if (i == 1)
        {
            Str = "заполнен";
            cout << "Состояние списка: " << Str << "\n\n";
        }
    }

}







