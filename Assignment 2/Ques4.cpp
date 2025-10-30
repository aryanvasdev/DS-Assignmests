#include <iostream>
#include <string>

using namespace std;

string concatenate(const string& s1, const string& s2) {
    return s1 + s2;
}

string reverseString(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
    return s;
}

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

string deleteVowels(const string& s) {
    string result = "";
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (!isVowel(s[i])) {
            result += s[i];
        }
    }
    return result;
}

void sortStrings(string strArray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strArray[j] > strArray[j + 1]) {
                string temp = strArray[j];
                strArray[j] = strArray[j + 1];
                strArray[j + 1] = temp;
            }
        }
    }
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int main() {
    const int MAX_STRINGS = 100;
    string myStrings[MAX_STRINGS];

    while (true) {
        cout << "\n--- String Operations Menu ---" << endl;
        cout << "1. Concatenate two strings" << endl;
        cout << "2. Reverse a string" << endl;
        cout << "3. Delete vowels from a string" << endl;
        cout << "4. Sort a list of strings" << endl;
        cout << "5. Convert a character to lowercase" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string s1, s2;
            cout << "Enter first string: ";
            getline(cin, s1);
            cout << "Enter second string: ";
            getline(cin, s2);
            cout << "Result: " << concatenate(s1, s2) << endl;
        } 
        else if (choice == 2) {
            string s;
            cout << "Enter a string: ";
            getline(cin, s);
            cout << "Result: " << reverseString(s) << endl;
        } 
        else if (choice == 3) {
            string s;
            cout << "Enter a string: ";
            getline(cin, s);
            cout << "Result: " << deleteVowels(s) << endl;
        } 
        else if (choice == 4) {
            int n;
            cout << "How many strings to sort? (Max 100): ";
            cin >> n;
            if (n > MAX_STRINGS) n = MAX_STRINGS;
            cin.ignore(); 

            for (int i = 0; i < n; ++i) {
                cout << "Enter string " << (i + 1) << ": ";
                getline(cin, myStrings[i]);
            }
            
            sortStrings(myStrings, n);
            
            cout << "Sorted strings:" << endl;
            for (int i = 0; i < n; i++) {
                cout << myStrings[i] << endl;
            }
        } 
        else if (choice == 5) {
            char c;
            cout << "Enter an uppercase character: ";
            cin >> c;
            cout << "Result: " << toLower(c) << endl;
        } 
        else if (choice == 6) {
            cout << "Exiting." << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
