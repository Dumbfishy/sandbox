#include <iostream>
#include <cassert> 

class Stackclass {

    int m_array[10] = {0};
    int m_length = 0;

public:
    void reset()
    {
        m_length = 0;
        for(auto i: m_array) {
            i = 0;
        }
    }

    void print()
    {
        std::cout << "( ";
        for(int i = 0; i < m_length; i++) {
                std::cout << m_array[i] << " ";
            }
        std::cout << ")" << std::endl;
    }

    bool push(int x)
    {
        if(m_length == 10) {
            return false;
        }
        m_array[m_length++] = x;
        return true;
    }

    void pop()
    {   
        assert(m_length > 0);
        m_array[--m_length] = 0;
    }
};


int main()
{
    Stackclass stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}
