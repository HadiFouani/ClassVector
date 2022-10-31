#include <iostream>
using namespace std;
class Myclass
{
    public:
    int* x;
    Myclass(int a=0)
    {
        this->x= new int(a);
        cout<<"object created"<<endl;
    }
    void display()
    {
        cout<<"x= "<<*x<<endl;
    }
    Myclass (const Myclass& mc): x(new int (*mc.x))
    {
        // int a =*mc.x;
        // x=new int(a);
        cout<<"object copied"<<endl;
    }
    ~Myclass()
    {
        delete x;
        x=nullptr;
        cout<<"object destructed"<<endl;
    }
    void fct(Myclass mc)
    {
        cout<< *(mc.x)<<endl;
    }
    Myclass fct2(Myclass& m1)
    {
        Myclass m(*m1.x);
        return m;
    }
};

int main()
{
    Myclass mcl1;
    // Myclass mcl2(5);
    // Myclass mcl3=mcl2;
    mcl1.display();
    // mcl2.display();
    // mcl3.display();
    // *(mcl3.x)=7; 
    // mcl3.display();
    // {
    //     Myclass mcl2(mcl1);
    //     *(mcl2.x)=7;
    //     cout<<"M2 dans le block  ";
    //     mcl2.display();
    // }
    // cout<<"M1 a l'exterieur"<<endl;
    // mcl1.display();
    // Myclass mcl1(3);
    // Myclass mcl2(4);
    // mcl2.display();
    // mcl2=mcl1;
    // mcl2.display();
    // mcl1.display();
    // Myclass m1(4);
    // Myclass m2 = fct2(m1);
    // return 0;

}

//Cours 28/octobre/2022
//
//Si on n'a pas cree une fonction de copie le compilateur lui meme la cree.
//Mais les 2 objets aurait la meme espace dans la memoire.
//donc si l'un detruit la memoire l'autre ne peut pas y acceder.
//