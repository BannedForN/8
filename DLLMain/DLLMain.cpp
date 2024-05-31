#include <windows.h>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;



bool checkString(const string& str, const string& chars) {
    for (char c : chars) {
        if (str.find(c) == string::npos) {
            return false;
        }
    }
    return true;
}

extern "C" __declspec(dllexport) bool checkWords(const char* sentence, const char* wordsToFind) {
    string wordsToFindSet = wordsToFind;

    if (!checkString(sentence, wordsToFindSet)) {
        return false;
    }

    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}