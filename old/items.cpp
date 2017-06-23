
#include <iostream>
#include <string>

using namespace std;

enum ITEMS
{
    ITEM_HEALTH,
    ITEM_TORCH,
    ITEM_ARROW,
    MAX_ITEM
} e_items;

void countTotalItems(int items_a[MAX_ITEM]);

int main (void) 
{

    int items[MAX_ITEM] = {2,5,10};

    countTotalItems(items);

    return 0;
}

void countTotalItems(int items_a[MAX_ITEM])
{
    int count = 0;

    for (int i = 0; i < MAX_ITEM; i++)
    {
        count += items_a[i];
    }

    cout << "the number of items in your bag is " << count << endl;

}

