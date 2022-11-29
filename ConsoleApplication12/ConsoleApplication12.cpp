#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <windows.h>
#include "Menu.h"

using namespace std;

class Congruencia
{
private:
    int a, b, m, x, xmod, size = 0;
    list<int> l;
public:
    void firststep();
    void laststep();
    void check();
    void clear()
    {
        l.clear();
        size = 0;
    }
};

void Congruencia::firststep()
{
    int tempA, tempM, temp, mod, A;
    cout << "Введіть значенення A, B та М ( ax = b(mod m) ) : " << endl;
    cin >> a >> b >> m;
    mod = m;
    A = a;
    cout << a << "x = " << b << "(mod" << m << ")" << endl;
    cout << endl;

    while (A != 0)
    {
        temp = mod / A;
        tempM = A * temp;
        tempA = mod - tempM;
        cout << mod << " = " << A << " * ";
        SetColor(2, 0);
        cout << temp;
        SetColor(15, 0);
        cout << " + " << tempA << endl;
        mod = A;
        A = tempA;
        l.push_back(temp);
        size++;
    }
}

void Congruencia::laststep()
{
    int tempPK, tempPK2, PK, q = 0, P;
    auto firstel = l.begin();
    int lastel = l.size() - 1;
    cout << endl;
    cout << "k";
    for (int i = -1; i < size; i++)
    {
        cout << setw(5) << i;
    }
    cout << endl;

    cout << "qk" << setw(4) << "//";
    for (auto i = l.begin(); i != l.end(); i++)
    {
        SetColor(2, 0);
        cout << setw(5) << *i;
        SetColor(15, 0);
    }
    cout << endl;

    cout << "Pk" << setw(4) << "1" << setw(5) << *firstel;

    for (auto i = l.begin(); i != l.end(); ++i)
    {
        if (*i == *firstel)
        {
            q++;
            tempPK = *firstel;
            PK = *firstel;
            continue;
        }
        if (q == 1)
        {
            tempPK2 = 1;
        }
        if (lastel == q)
        {
            P = PK;
        }
        PK = *i * tempPK + tempPK2;
        tempPK2 = tempPK;
        tempPK = PK;
        cout << setw(5) << PK;
        q++;
    }
    cout << endl << endl;
    x = pow(-1, size - 1) * b * P;
    cout << "x = (-1)^" << size - 1 << " * " << P << " * " << b << "(mod" << m << ")" << endl;
    cout << "x = " << x << "(mod" << m << ")" << endl;
    if (x < 0)
        while (x < 0)
            x += m;
    xmod = x % m;
    cout << "x = " << xmod << "(mod" << m << ")" << endl;
}

void Congruencia::check()
{
    cout << endl;
    cout << "Перевірка:" << endl;
    int checkTrue = (a * xmod) % m;
    cout << endl;
    if (checkTrue != b)
    {
        SetColor(15, 4);
        cout << "Результат може бути не правильним! Скоротіть конгруенцію!" << endl;
        SetColor(15, 0);
    }
    else
    {
        SetColor(15, 2);
        cout << "Перевірка пройдена успішно!" << endl;
        SetColor(15, 0);
    }
    cout << endl;
    cout << a << " * " << xmod << "(mod" << m << ") = " << checkTrue << endl;
    cout << endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool sw = 0;
    cout << "Добрий день!" << endl;
    cout << "Вас вітає програма вичеслення конгруєнції" << endl;
    Congruencia c;
    Menu m;
    while (sw != 1)
    {
        c.firststep();
        c.laststep();
        c.check();
        c.clear();
        system("pause");
        system("cls");
        cout << "Чи бажаєте ви продовжити?" << endl;
        vector<string> v = { "Так", "Ні" };
        int menu = m.select_vertical(v) + 1;
        switch (menu)
        {
        case 1: break;
        case 2: sw = 1; break;
        default:
            break;
        }
        system("cls");
    }

}