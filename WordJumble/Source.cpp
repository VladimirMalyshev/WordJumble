#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer. "},
        {"labored", "Going slowly. is it?"},
        {"persistent", "���� at it."},
        {"jumbe", "It's what the game is all about."}
    };
    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; //�����. ������� ����� �������
    string theHint = WORDS[choice][HINT];
    string jumble = theWord; // ������������ ������� �����
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
        int indexl = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[indexl];
        jumble[indexl] = jumble[index2];
        jumble[index2] = temp;
    }
    cout << "Welcome to Word Jum�le!\n\n";
    cout << "Unscramble the letters to make a word. \n";
    cout << "Enter 'hint' for � hint. \n";
    cout << "Enter 'quit' to quit the game. \n\n";
    cout << "The jumble is: " << jumble;
    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Sorry, that's not it. ";
        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }
    if (guess == theWord)
    {
        cout << "\nThat's it! You guessed it!\n";
    }
    cout << "\nThanks for playing.\n";
    return 0;
}
