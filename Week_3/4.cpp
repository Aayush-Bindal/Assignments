#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void revString(string &s){
    int n = s.length();
    for (int i = 0; i < n/2; i++){
        swap(s[i], s[n-i-1]);
    }
}

void removeVowel(string &s){
    int n = s.length();
    int i = 0;
    while (i < n){
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U'){
            s.erase(s.begin() + i);
        }
        else i++;
    }
}

void bubbleSort(string &s){
    int n = s.length();
    bool isSwapped = false;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (s[j] > s[j+1]){
                swap(s[j], s[j+1]);
                isSwapped = true;
            }
        }
        if (!isSwapped){
            break;
        }
    }
}

void convert(string &s){
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + ('a' - 'A');
        }
    }
}

int main() {
    // ques 4a
    string firstName = "jeffery";
    string lastName = "Bezos";
    string fullName = firstName + " " + lastName;
    cout << fullName << endl;

    //ques 4b
    string greet = "hello";
    cout << greet << endl;
    revString(greet);
    cout << greet << endl;

    //ques 4c
    cout << fullName << endl;
    removeVowel(fullName);
    cout << fullName << endl;

    //ques 4d
    cout << firstName << endl;
    bubbleSort(firstName);
    cout << firstName << endl;

    //ques 4e
    cout << lastName << endl;
    convert(lastName);
    cout << lastName << endl;

    return 0;
}