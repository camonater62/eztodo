#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    string homedir = getenv("HOME");
    string filepath = homedir + "/todo";

    fstream file;
    file.open(filepath, ios::in);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    string command = (argc > 1) ? argv[1] : "-v";
    string value = "";
    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            value += argv[i];
            if (i != argc - 1) {
                value += " ";
            }
        }
    }

    if (command == "-a" && value != "") {
        lines.push_back(value);
    } else if (command == "-c" && value != "") {
        int index = stoi(value);
        if (index > (int) lines.size() || index < 1) {
            cerr << "Index is out of bounds" << endl;
            return 0;
        }
        lines.erase(lines.begin() + index - 1);
    }

    file.open(filepath, ios::out);
    for (int i = 0; i < (int) lines.size(); i++) {
        cout << i + 1 << ". " << lines[i] << endl;
        file << lines[i] << endl;
    }
    file.close();
}