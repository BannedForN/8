#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

typedef bool (*checkWordsFunc)(const char*, const char*);

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    HINSTANCE hGetProcIDDLL = LoadLibraryA("DLLMain.dll");

    if (hGetProcIDDLL == nullptr) {
        cout << "Не удалось загрузить динамическую библиотеку" << endl;
        return EXIT_FAILURE;
    }

    checkWordsFunc checkString = (checkWordsFunc)GetProcAddress(hGetProcIDDLL, "checkWords");
    if (!checkString) {
        cout << "Функция не найдена" << endl;
        FreeLibrary(hGetProcIDDLL);
        return EXIT_FAILURE;
    }

    string sentence, wordsToFind;
    cout << "Введите слово или предложение: ";
    getline(cin, sentence);
    cout << "Введите символы для поиска: ";
    getline(cin, wordsToFind);


    if (checkString(sentence.c_str(), wordsToFind.c_str())) {
        cout << "Все символы <<" << wordsToFind << ">> найдены" << endl;
    }
    else {
        cout << "Не все символы <<" << wordsToFind << ">> найдены" << endl;
    }
    FreeLibrary(hGetProcIDDLL);

    return EXIT_SUCCESS;
}