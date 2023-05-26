#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string salt(const string& input) 
{
    string saltedInput = input;
    time_t currentTime = time(nullptr);
    mt19937 rng(static_cast<unsigned>(currentTime));
    for (int i = 0; i < 32; ++i) {
        char randomChar = static_cast<char>(rng() % 94 + 33);
        saltedInput += randomChar;
    }

    return saltedInput;
}

int main() 
{
    string input = "password";
    string saltedInput = salt(input);

    cout << "Input       : " << input << endl;
    cout << "Salted input: " << saltedInput << endl;

    return 0;
}
