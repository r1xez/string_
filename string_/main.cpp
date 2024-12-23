#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void readFile(const string& filename, vector<string>& data) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void writeFile(const string& filename, const vector<string>& data) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : data) {
            file << entry << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file for writing: " << filename << endl;
    }
}

int main() {
    vector<string> surnames, names, patronymics;

  
    readFile("P.txt", surnames);
    readFile("I.txt", names);
    readFile("B.txt", patronymics);


    if (surnames.size() != names.size() || surnames.size() != patronymics.size()) {
        cout << "Error: The files have different numbers of records!" << endl;
        return 1;
    }

    vector<string> fullNames;

  
    for (size_t i = 0; i < surnames.size(); ++i) {
        fullNames.push_back(surnames[i] + " " + names[i] + " " + patronymics[i]);
    }

    sort(fullNames.begin(), fullNames.end());

    
    writeFile("Report.txt", fullNames);

    cout << "Operation completed. Results saved to Report.txt." << endl;

    return 0;
}
