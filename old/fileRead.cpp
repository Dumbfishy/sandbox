// io/read-file-sum.cpp - Read integers from file and print sum.
// Fred Swartz 2003-08-20

#include <iostream>
#include <string>
#include <fstream>

int main() {
    int sum = 0;
    int x;
    std::string String;
    std::ifstream inFile;

    inFile.open("test.txt");
    if (!inFile) {
        std::cout << "Unable to open file";
        return -1;
    }

    while (!inFile.eof()) {
        getline(inFile,String);
        std::cout << String << '\n';
    }

    /*
    while (inFile >> x) {
        sum = sum + x;
    }
    */
    inFile.close();
    std::cout << "Sum = " << sum << std::endl; 
    return 0;
}
