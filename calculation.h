
#include <iostream>
#include <fstream>
#include <cassert>
#include "linkedStack.h"
#include "linkedQueue.h"





class InforXApp {
private:
    linkedStackType<char> charStack; // Stack for reversing characters
    linkedQueueType<char> charQueue; // Queue for reversing characters
    ifstream inputFile;
    ofstream outputFile;
    

    void reverseCharacters(string& str) {
        linkedStackType<char> tempStack;

        for (int i = 0; i < str.length(); ++i) {
            tempStack.push(str[i]);
        }

        str = "";
        while (!tempStack.isEmptyStack()) {
            char currentChar = tempStack.top();
            switch (currentChar) {
                case 'a':
                case 'A':
                    currentChar = '*';
                    break;
                case 'e':
                case 'E':
                    currentChar = '@';
                    break;
                case 'i':
                case 'I':
                    currentChar = '#';
                    break;
                case 'o':
                case 'O':
                    currentChar = '$';
                    break;
                case 'u':
                case 'U':
                    currentChar = '&';
                    break;
                default:
                    break;
            }
            str += currentChar;
            tempStack.pop();
        }
    }

    void reverseCharactersQueue(string& str) {
        for (int j = 0; j < str.length(); ++j) {
            charQueue.addQueue(str[j]);
        }

        str = "";
        while (!charQueue.isEmptyQueue()) {
            char tempChar = charQueue.front();
            switch (tempChar) {
                case '*':
                    tempChar = 'a';
                    break;
                case '@':
                    tempChar = 'e';
                    break;
                case '#':
                    tempChar = 'i';
                    break;
                case '$':
                    tempChar = 'o';
                    break;
                case '&':
                    tempChar = 'u';
                    break;
                default:
                    break;
            }
            str += tempChar;
            charQueue.deleteQueue();
        }
    }

    string reverseSentence(const string& sentence) {
        string reversedSentence;

        for (int i = sentence.length() - 1; i >= 0; --i) {
            reversedSentence += sentence[i];
        }

        return reversedSentence;
    }

public:
    InforXApp() {}
    ~InforXApp(){}
    
    void encryptText() {
    string inputFileName;
    cout << "\tEnter the input file name: ";
    getline(cin, inputFileName);
    system("cls");
    inputFile.open(inputFileName);

    string outputFileName;
    cout << "\tEnter the output file name where you want to store the output: ";
    getline(cin, outputFileName);
    system("cls");
    outputFile.open(outputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        string inputText;
        string encryptedText;

        while (getline(inputFile, inputText)) {
            if (!inputText.empty()) {
                reverseCharacters(inputText);
                encryptedText += inputText + "\n";
            }
        }

        cout << "\tEncrypt:\n\n\n " << encryptedText << endl;

        outputFile << encryptedText; // Write encryptedText to the output file

        inputFile.close();
        outputFile.close(); // Close the output file stream
    } else {
        cout << "\tError opening file: " << inputFileName  << endl;
    }
    system("pause");
    system("cls");
}
	

    void decryptText() {
    string inputFileName;
    cout << "\tEnter the input file name: ";
    getline(cin, inputFileName);
    system("cls");

    inputFile.open(inputFileName);

    string outputFileName;
    cout << "\tEnter the output file name where you want to store the output: ";
    getline(cin, outputFileName);
    system("cls");
    outputFile.open(outputFileName);

    if (inputFile.is_open() && outputFile.is_open()) {
        string inputText;
        string decryptedText;

        while (getline(inputFile, inputText)) {
            if (!inputText.empty()) {
                inputText = reverseSentence(inputText);
                reverseCharactersQueue(inputText);
                decryptedText += inputText + "\n";
            }
        }

        cout << "\tDecrypt:\n\n\n " << decryptedText << endl;

        outputFile << decryptedText; // Write decryptedText to the output file

        inputFile.close();
        outputFile.close(); // Close the output file stream
    } else {
        cout << "\tError opening file: " << inputFileName  << endl;
    }
    system("pause");
    system("cls");
}
    
    
};
