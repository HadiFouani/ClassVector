#include <iostream>
using namespace std;
typedef int type;
class MyVector
{
    public:
        MyVector(int =1);
        MyVector(type*, int );
        MyVector(const MyVector&);
        ~MyVector();
        MyVector& operator=(const MyVector&);     
        const type operator[] (int i) const;
        type& operator[](int i);
        MyVector& operator+= (const MyVector&);

        void push_back(type);
        type pop_back();
    private:
        int size;
        int capacity;
        type* ptr;
        friend ostream& operator<< (ostream&, const MyVector&);

};
const MyVector operator+ (MyVector v1, const MyVector& v2);
int main()
{

    return 0;
}