#include <iostream>
using namespace std;

// Завдання 1.1. If35: значення функції u(x)
void taskIf35();
// Завдання 1.2. If15: сума двох найбільших з трьох чисел
void taskIf15();
// Завдання 2. Геометрія, варіант 14: чи належить точка чорній області
void taskGeom14();

// Завдання 3. Меню вибору завдання
int main()
{
    int menu;
    cout << "Task number (1 - If35, 2 - If15, 3 - Geom14): ";
    cin >> menu;

    if (!cin) {                                  // введено не число
        cout << "Wrong task! (Only 1,2,3)" << endl;
        return 0;
    }

    switch (menu) {                              // перемикання між завданнями
        case 1: taskIf35();   break;
        case 2: taskIf15();   break;
        case 3: taskGeom14(); break;
        default: cout << "Wrong task! (Only 1,2,3)" << endl;
    }
    return 0;
}

// ---------- Завдання 1.1: If35 ----------
void taskIf35()
{
    double x, u;
    cout << "************* If 35 *****************" << endl;
    cout << "Enter x: ";
    cin >> x;

    if (!cin) {                                  // перевірка коректності вводу
        cout << "Wrong number!" << endl;
        return;
    }

    if (x <= 0)                                  // x <= 0
        u = -x * x;
    else if (x <= 3)                             // 0 < x <= 3
        u = x;
    else                                         // x > 3
        u = 9 - x;

    cout << "u(x) = " << u << endl;
}

// ---------- Завдання 1.2: If15 ----------
void taskIf15()
{
    double a, b, c, sum;
    cout << "************* If 15 *****************" << endl;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (!cin) {
        cout << "Wrong numbers!" << endl;
        return;
    }

    // сума двох найбільших = сума двох, що не є найменшим
    if (a <= b && a <= c)                        // a - найменше
        sum = b + c;
    else if (b <= a && b <= c)                   // b - найменше
        sum = a + c;
    else                                         // c - найменше
        sum = a + b;

    cout << "Sum of two largest = " << sum << endl;
}

// ---------- Завдання 2: Geometry 14 ----------
void taskGeom14()
{
    double r, x, y;
    cout << "************* Geom 14 *****************" << endl;
    cout << "Enter radius r: ";
    cin >> r;

    if (!cin || r <= 0) {                        // радіус має бути додатним
        cout << "Incorrect radius!" << endl;
        return;
    }

    cout << "Enter point (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cout << "Not numeric data!" << endl;
        return;
    }

    // центр кола (r, r); точка в колі, якщо відстань до центру < r
    double dx = x - r, dy = y - r;
    bool inCircle = dx * dx + dy * dy < r * r;

    // частина 1: у колі, правіше x=r, нижче y=r, над діагоналлю x+y=2r
    bool part1 = inCircle && x > r && y < r && x + y > 2 * r;

    // частина 2: трикутник під віссю OX у межах ромба
    bool part2 = x > r && y < 0 && x - y < 2 * r;

    if (part1 || part2)
        cout << "The point belongs to the black area." << endl;
    else
        cout << "The point does NOT belong to the black area." << endl;
}
