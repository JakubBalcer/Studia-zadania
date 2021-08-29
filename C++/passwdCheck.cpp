#include <iostream>

#define ARR_SIZE 21

using namespace std;

int length(char str[])
{
    int i = 0;
    int len = 0;
    while (str[i] != '\0')
    {
        i++;
        len++;
    }
    return len;
}

bool has_capital(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (int(str[i]) >= 65 && int(str[i]) <= 90)
            return true;
        i++;
    }
    return false;
}

bool has_lower(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (int(str[i]) >= 97 && int(str[i]) <= 122)
            return true;
        i++;
    }
    return false;
}

bool has_special(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        int x = int(str[i]);
        if (x == 33 || (x >= 35 && x <= 38) || (x >= 40 && x <= 42) || x == 63 || x == 94)
            return true;
        i++;
    }
    return false;
}

bool correct_length(char str[])
{
    return length(str) >= 8 && length(str) <= 20;
}

char *password()
{
    int errors;
    static char input_data[ARR_SIZE];

    do
    {
        errors = 0;
        cout << "Prosze wprowadzic haslo \n";
        cin >> input_data;

        if (!correct_length(input_data))
        {
            cout << "Nieprawidlowa dlugosc hasla \n";
            errors++;
        }

        if (!has_capital(input_data))
        {
            cout << "Brak wielkiego znaku \n";
            errors++;
        }

        if (!has_lower(input_data))
        {
            cout << "Brak malego znaku \n";
            errors++;
        }

        if (!has_special(input_data))
        {
            cout << "Brak znaku specjalnego \n";
            errors++;
        }

        cout << "Errors: " << errors << endl;
        if (errors > 0)
            cout << "Niepoprawne haslo, prosze ponowic probe: \n \n";
    } while (errors >= 1);

    cout << "Haslo poprawne \n \n";
    return input_data;
}

bool strings_match(char str1[], char str2[])
{
    if (length(str1) != length(str2))
        return false;
    else
        for (int i = 0; i < length(str1); i++)
            if (str1[i] != str2[i])
                return false;
    return true;
}

bool password_again(char pass[])
{
    char pass_again[ARR_SIZE];
    cout << "Prosze wprowadzic haslo ponownie \n";
    cin >> pass_again;
    return strings_match(pass, pass_again);
}

int main(int argc, char *argv[])
{
    bool success = 0;
    char *pass = NULL;
    while (!success)
    {
        pass = password();
        if (!password_again(pass))
            cout << "Hasla sie nie zgadzaja, ponawiamy procedure \n";
        else
            success = 1;
    }
    delete pass;
    cout << "Brawo, udalo ci sie ustawic haslo";
    return 0;
}
