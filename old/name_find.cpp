
#include <iostream>
#include <string>

using namespace std;


int main (void) 
{

    int numNames = 0;
    
    string userName;

    string Names[] = {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg","Holly"};

    cout << "Enter a name:" << endl;
    cin >> userName;
    
    int found = 0;

    for (string loopName : Names) {
        if (loopName == userName) {
            found = 1;
        }
    }

    if (found == 1) {
        cout << userName << " was found." << endl;
    } else {
        cout << userName << " was not found." << endl;
    }

    return 0;
}
