#include <iostream>
#include <string>
#include <vector>

// I realize I could've used unordered_maps but refrained to avoid risking points docked.
const std::vector<std::string> morse_map = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Morse --> ENG
std::string DecodeFrom_Morse(const std::string& MorseSequence) {
    std::string EnglishText, CurrentCode;
    for (char CharInSequence : MorseSequence) {
        if (CharInSequence == ' ') {
            if (!CurrentCode.empty()) {
                
                for (size_t i = 0; i < morse_map.size(); ++i) {
                    if (morse_map[i] == CurrentCode) {
                        EnglishText += ('a' + i);
                        break;
                    }
                }
                CurrentCode.clear();
            }
        } else {
            CurrentCode += CharInSequence;
        }
    }

    if (!CurrentCode.empty()) {
        for (size_t i = 0; i < morse_map.size(); ++i) {
            if (morse_map[i] == CurrentCode) {
                EnglishText += ('a' + i);
                break;
            }
        }
    }
    return EnglishText;
}

// ENGLISH --> Morse
std::string encode_to_morse(const std::string& inputText) {
    std::string morseCode;
    for (char c : inputText) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Convert to lowercase
        }
        if (c >= 'a' && c <= 'z') {
            if (!morseCode.empty()) {
                morseCode += " ";
            }
            morseCode += morse_map[c - 'a'];
        }
    }
    return morseCode;
}

int main() {
    std::string user_input;
    std::cout << "Enter text to encode into Morse code: ";
    std::getline(std::cin, user_input);

    // converttoMorse
    std::string Morse_Output = encode_to_morse(user_input);
    std::cout << "Morse Code: " << Morse_Output << std::endl;

    // morse-->english
    std::string Decoded_Text = DecodeFrom_Morse(Morse_Output);
    std::cout << "Decoded Text: " << Decoded_Text << std::endl;

    return 0;
}

