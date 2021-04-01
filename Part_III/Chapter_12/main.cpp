#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool changeNumberForID(const string& inFileName, int inID, const string& inNewNumber) {
    fstream ioData(inFileName.c_str());
    if(!ioData) {
        cerr << "Error while opening file " << inFileName << '\n';
        return false; 
    }

    while(ioData.good()) {
        int id;
        string number;

        ioData >> id;
        if(id == inID) {
            ioData.seekp(ioData.tellg());
            ioData << " " << inNewNumber;
            break;
        }
        ioData >> number;
    }
    return true;
}

int main() {
    
    

    return 0;
}


void whatever() {
    ofstream outFile("test.txt", ios_base::trunc);
    if(!outFile.good()) {
        cerr << "Error while opening output file!\n";
    }

    int x = 5;
    outFile << "First line\n";
    outFile << "Second line and value of x: " << x << '\n';
    for(int i = 0; i < 10; i++) {
        outFile << i << '\n';
    }
}


void whatever2() {
    ofstream fout("test.out", ios_base::out);
    if(!fout) {
        cerr << "Error opening test.out for writing\n";
    }

    fout << 12345;
    streampos curPos = fout.tellp();
    if(curPos == 5) {
        cout << "Actual position is 5\n";
    }

    fout.seekp(2, ios_base::beg);
    fout << 0;
    fout.close();

    ifstream fin("test.out", ios_base::in);
    if(!fin) {
        cerr << "Error opening test.out for writing\n";
    }

    int x;
    fin >> x;
    if(x == 12045) {
        cout << "Value is 12045\n";
    }
}