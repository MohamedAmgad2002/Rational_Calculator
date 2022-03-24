// FCAI - Programming 1  2022 - Assignment 2
// Program Name: Rational calculator.cpp
// Program Description: ....
// Last Modification Date: 22/3/2022
// Author1 and ID and Group: Mohamed Amgad 20210330
// Author2 and ID and Group: Mostafa Ali 20210393
// Author3 and ID and Group: Yousef Alaa 20210478
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

char op_chars[4], ch;
int k(0), num1(0), den1(0), num2(0), den2(0), prop_fraction(0), key(1), turn(1),
index(0), nfind = 1, num_bef_div;
string equations;

void positive_op(int& num_result, int& den_result) {

    if (num_result < den_result) {
        cout << "Result = " << num_result << '/' << den_result;
    }
    else if (num_result > den_result && num_result % den_result == 0) {
        cout << "Result = " << num_result / den_result;
    }
    else if (num_result > den_result && num_result % den_result != 0) {
        while (num_result > den_result) {
            num_result = num_result - den_result;
            prop_fraction++;
        }
        cout << "Result = " << prop_fraction << " " << num_result << '/'
            << den_result;
    }
}
bool valid_rational(string& str) {
    regex valid_input("[-]?[0-9]+[/][1-9]+[+-/*]?[-]?[0-9]+[/][1-9]+");
    return regex_match(str, valid_input);
}

int gcd1(int x, int y) {
    int gcd = 0;
    while (x != y && x > 0 && y > 0)

    {
        if (x > y)
            x = x - y;

        else

            y = y - x;

        gcd = x;
    }
    return gcd;
}
void split(string x, int& num, int& den) {
    string charachter;
    string num1, num2;
    for (int i = 0; i < x.length(); i++) {
        charachter = x[i];
        if (charachter == "/" || charachter == "|") {
            for (int j = i + 1; j < x.length(); j++) {
                charachter = x[j];
                num2 += x[j];
            }
            break;
        }
        else {
            num1 += x[i];
        }
    }
    num = stoi(num1);
    den = stoi(num2);
}
void Add(int num1, int num2, int den1, int den2) {
    float final_num = num1 * den2 + num2 * den1;
    float final_den = den1 * den2;
    if (final_num < 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
        key = 1;
    }
    else if (final_num < 0 && final_den > 0 || final_num > 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
        key = 0;
    }

    if (final_num == 0) {
        cout << "Result = " << final_num;
    }
    if (final_num != final_den && key > 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        positive_op(num_result, den_result);

    }
    else if (final_num != final_den && key == 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = -" << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = -" << num_result / den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = -" << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else {
        int equal_result = final_num / final_den;
        cout << "Result = " << equal_result;
    }
}

void Subtract(float num1, float num2, float den1, float den2) {

    float final_num(0), final_den(0);
    if ((num1 / den1) >= (num2 / den2) && (num1 / num2) > 0) {
        final_num = (num1 * den2) - (num2 * den1);
        final_den = den1 * den2;
    }
    else if ((num1 / den1) < (num2 / den2)) {

        final_num = (num2 * den1) - (num1 * den2);
        final_den = den1 * den2;
        key = 0;
    }

    else if ((num1 / den1) > (num2 / den2) && (num2 / den2) < 0) {

        final_num = (num1 * den2) - (num2 * den1);
        final_den = den1 * den2;
        key = 1;
    }
    if (final_num < 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
    }
    if (final_num == 0) {
        cout << "Result = " << final_num;
    }
    else if (final_num != final_den && key > 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = " << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = " << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = " << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (final_num != final_den && key == 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = -" << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = -" << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = -" << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (final_num == final_den && key == 0) {
        cout << "Result = -" << final_num / final_den;
    }
    else {
        cout << "Result = " << final_num / final_den;
    }
}

void multiply(int num1, int num2, int den1, int den2) {
    int final_num = num1 * num2;
    int final_den = den1 * den2;
    if (final_num < 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
        key = 1;
    }
    else if (final_num < 0 && final_den > 0 || final_num > 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
        key = 0;
    }

    if (final_num == 0) {
        cout << "Result = " << final_num;
    }
    if (final_num != final_den && key > 0) {

        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = " << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = " << num_result / den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = " << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (final_num != final_den && key == 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = -" << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = -" << num_result / den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = -" << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (key == 0) {
        int equal_result = final_num / final_den;
        cout << "Result = -" << equal_result;
    }
    else {
        int equal_result = final_num / final_den;
        cout << "Result = -" << equal_result;
    }
}

void divide(int num1, int num2, int den1, int den2) {
    int final_num = num1 * den2;
    int final_den = den1 * num2;
    if (final_num < 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(abs(final_num), abs(final_den));
        key = 1;
    }
    else if (final_num < 0 && final_den > 0 || final_num > 0 && final_den < 0) {
        final_num = abs(final_num);
        final_den = abs(final_den);
        gcd1(final_num, final_den);
        key = 0;
    }

    if (final_num == 0) {
        cout << "Result = " << final_num;
    }
    if (final_num != final_den && key > 0) {

        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = " << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = " << num_result / den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = " << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (final_num != final_den && key == 0) {
        int gcdv = gcd1(final_num, final_den);
        int num_result = final_num / gcdv;
        int den_result = final_den / gcdv;
        if (num_result < den_result) {
            cout << "Result = -" << num_result << '/' << den_result;
        }
        else if (num_result > den_result && num_result % den_result == 0) {
            cout << "Result = -" << num_result / den_result;
        }
        else if (num_result > den_result && num_result % den_result != 0) {
            while (num_result > den_result) {
                num_result = num_result - den_result;
                prop_fraction++;
            }
            cout << "Result = -" << prop_fraction << " " << num_result << '/'
                << den_result;
        }
    }
    else if (key == 0) {
        int equal_result = final_num / final_den;
        cout << "Result = -" << equal_result;
    }
    else {
        int equal_result = final_num / final_den;
        cout << "Result = " << equal_result;
    }
}

int main() {
    cout << "Welcome to the Rational Calculator !\n";
    char key = 'y';
    while (key == 'y') {
        nfind = 1;
        key = 1;
        cout << "Enter the equation: ";
        getline(cin, equations);
        equations.erase(remove(equations.begin(), equations.end(), ' '),
            equations.end());
        while (!valid_rational(equations)) {
            cout << "Invalid input\n";
            cout << "Enter the equation:\n";
            getline(cin, equations);
            equations.erase(remove(equations.begin(), equations.end(), ' '),
                equations.end());
        }
        for (int i = 0; i < equations.length(); i++) {
            if (!isdigit(equations[i])) {
                op_chars[k] = equations[i];
                k++;
            }
        }
        if (op_chars[0] != '/') {
            index = 2;
        }
        else {
            index = 1;
        }
        if (op_chars[index] == '/') {
            num_bef_div = equations.find('/');
            equations.replace(num_bef_div, 1, "|");
            ch = op_chars[index];
        }
        else if (op_chars[index] == '*') {
            ch = op_chars[index];
        }
        else if (op_chars[index] == '+') {
            ch = op_chars[index];
        }
        else {
            ch = op_chars[index];
        }
        nfind = equations.find(ch, nfind + 1);
        equations.substr(0, nfind);
        equations.substr(nfind + 1, equations.length() - (nfind + 1));
        split(equations.substr(0, nfind), num1, den1);
        split(equations.substr(nfind + 1, equations.length() - (nfind + 1)), num2,
            den2);

        switch (ch) {
        case '+':
            Add(num1, num2, den1, den2);
            break;
        case '-':
            Subtract(num1, num2, den1, den2);
            break;
        case '*':
            multiply(num1, num2, den1, den2);
            break;
        case '/':
            divide(num1, num2, den1, den2);
            break;
        }

        cout << "\nDo you want to make another calculation [Y/N]:\n";
        cin >> key;
        cin.ignore();
    }
    if (tolower(key) != 'y') {
        cout << "Thank you";
    }
    return 0;
}
