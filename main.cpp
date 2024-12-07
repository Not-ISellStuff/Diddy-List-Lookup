#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct File {
    std::vector<std::string> content;
};

std::vector<std::string> split(const std::string& str, const std::string& s) {
    std::vector<std::string> tks;
    size_t st = 0;
    size_t en = str.find(s);

    while (en != std::string::npos) {
        tks.push_back(str.substr(st, en - st));
        st = en + s.length();
        en = str.find(s, st);
    }
    tks.push_back(str.substr(st));

    return tks;
}

std::string low(const std::string& str) {
    std::string l = str; 
    for (char &c : l) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return l;
}

bool in(const std::vector<std::string>& vec, const std::string& i) {
    for (const auto& e : vec) {
        if (low(e) == low(i)) {
            return true;
        }
    }
    return false;
}

bool FindCeleb(const std::string& celeb, const std::vector<std::string>& list) {
    for (const auto& entry : list) {
        std::string ln = low(entry);
        std::vector<std::string> name = split(ln, " ");

        if (name.size() == 1) {
            if (name[0] == celeb) {
                return true;
            }
        } else if (name.size() >= 2) {
            std::string f = name[0];
            std::string s = name[1];

            if (in(name, f) && in(name, s)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    File file;

    std::string celeb;
    std::vector<std::string> DiddyPartyList;

    std::ifstream Diddy;
    Diddy.open("diddy.txt");

    if (Diddy.fail()) {
        std::cout << "[!] Error Getting The Diddy List. | Make sure diddy.txt is in the same directory as in this file";
        return 1;
    }

    std::string ln;
    while (std::getline(Diddy, ln)) {
        file.content.push_back(ln);
    }
    Diddy.close();

    std::cout << "Format: isellstuff or isell stuff\nEnter Celeb Name: ";
    std::cin >> celeb;

    bool found = FindCeleb(celeb, file.content);
    int nigga;

    if (found) {
        std::cout << "[+] " << celeb << " DID go to the diddy parties.";
        std::cout << "\nPress A Key Then Enter To Close > ";
        std::cin >> nigga;

        return 0;
    }
    std::cout << "[-] " << celeb << " did NOT go to the diddy parties.";
    std::cout << "\nPress A Key Then Enter To Close > ";
    std::cin >> nigga;

    return 0;
}
