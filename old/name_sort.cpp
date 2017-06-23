
#include <iostream>
#include <string>

using namespace std;


int main (void) 
{

    int numNames = 0;
    
    cout << "How many names will you enter?" << endl;
    cin >> numNames;

    string *Names = new string[numNames];

    for (int i = 0; i < numNames; ++i) {
        cout << "Enter name #" << (i + 1) << ":";
        cin >> Names[i];
    }

    //sort the names
    for (int i = 0; i < numNames; i++) {
        int smallest = i;
        for (int current = i + 1; current < numNames; ++current) {
            if (Names[current] < Names[smallest]) {
                smallest = current;
            }
        }
        //swap if smaller
        swap(Names[i],Names[smallest]);
    }

    cout << "Here are your sorted names," << endl;


    for (int i = 0; i < numNames; i++) {
        cout << "Name#" << i+1 << ": " <<  Names[i] << endl;
    }

    delete[] Names;
        Names = 0;

    return 0;
}
