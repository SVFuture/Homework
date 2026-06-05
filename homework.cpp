#include <iostream>
#include <cstring>

using namespace std;

struct Book
{
    char title[50];
    char author[50];
    char publisher[50];
    char genre[40];
};

void swapStrings(char a[], char b[])
{
    char temp[50];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void swapBook(Book &a, Book &b)
{
    swapStrings(a.title, b.title);
    swapStrings(a.author, b.author);
    swapStrings(a.publisher, b.publisher);
    swapStrings(a.genre, b.genre);
}

int main()
{
    Book books[10] =
    {
        {"Кобзар", "Шевченко", "Освіта", "Поезія"},
        {"Лісова пісня", "Українка", "Фоліо", "Драма"},
        {"Захар Беркут", "Франко", "КСД", "Роман"},
        {"1984", "Орвелл", "КСД", "Антиутопія"},
        {"Алхімік", "Коельйо", "КСД", "Роман"},
        {"Тигролови", "Багряний", "Ранок", "Пригоди"},
        {"Місто", "Підмогильний", "Фоліо", "Роман"},
        {"Гаррі Поттер", "Ролінґ", "А-БА-БА-ГА-ЛА-МА-ГА", "Фентезі"},
        {"Маленький принц", "Екзюпері", "Фоліо", "Казка"},
        {"Маруся Чурай", "Костенко", "Либідь", "Історичний роман"}
    };

    cout << "Усі книги:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << books[i].title << " | "
             << books[i].author << " | "
             << books[i].publisher << " | "
             << books[i].genre << endl;
    }

    int n;
    cout << "\nВведіть номер книги для редагування (1-10): ";
    cin >> n;
    cin.ignore();

    cout << "Нова назва: ";
    cin.getline(books[n - 1].title, 50);

    cout << "Новий автор: ";
    cin.getline(books[n - 1].author, 50);

    cout << "Нове видавництво: ";
    cin.getline(books[n - 1].publisher, 50);

    cout << "Новий жанр: ";
    cin.getline(books[n - 1].genre, 40);

    char search[50];

    cout << "\nВведіть автора для пошуку: ";
    cin.getline(search, 50);

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(books[i].author, search) == 0)
            cout << books[i].title << endl;
    }

    cout << "\nВведіть назву книги для пошуку: ";
    cin.getline(search, 50);

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(books[i].title, search) == 0)
            cout << books[i].author << endl;
    }

    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++)
            if (strcmp(books[i].title, books[j].title) > 0)
            {
                swapBook(books[i], books[j]);
            }

    cout << "\nСортування за назвою:\n";
    for (int i = 0; i < 10; i++)
        cout << books[i].title << endl;

    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++)
            if (strcmp(books[i].author, books[j].author) > 0)
            {
                swapBook(books[i], books[j]);
            }

    cout << "\nСортування за автором:\n";
    for (int i = 0; i < 10; i++)
        cout << books[i].author << " - " << books[i].title << endl;

    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++)
            if (strcmp(books[i].publisher, books[j].publisher) > 0)
            {
                swapBook(books[i], books[j]);
            }

    cout << "\nСортування за видавництвом:\n";
    for (int i = 0; i < 10; i++)
        cout << books[i].publisher << " - " << books[i].title << endl;

    return 0;
}