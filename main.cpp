#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class my_ctype : public std::ctype<char> {
public:
    mask const* get_table() {
        static std::vector<std::ctype<char>::mask>
            table(classic_table(), classic_table() + table_size);
        table['^'] = (mask)space;
        return &table[0];
    }
    my_ctype(size_t refs = 0) : std::ctype<char>(get_table(), false, refs) { }
};

class math
{
public: 
    void en2();
};

void calcu()
{
    math eigenv;
    eigenv.en2();
}

void math::en2() //Eigenvalues for 2x2 matrixes 
{
    float a11, a12, a21, a22, det11, det12, det2, ac, bc, cc, eigv1, eigv2;
    cout << "Insert your matrix here:\n"; 
    cout << "Firt item:\t"; cin >> a11; cout << "Second item:\t"; cin >> a12; cout << "Third item:\t"; cin >> a21; cout << "Fourth item:\t"; cin >> a22; system("cls");
    cout << "Your matrix is: \n\n\t" << a11 << "\t" << a12 << "\n\t" << a21 << "\t" << a22 << "\n";
    //Determinant Calculations
    det11 = a11 * a22;
    det12 = (-a11) + (-a22);
    det2 = a12 * a21;
    //Polynomial function elements
    ac = 1;
    bc = det12;
    cc = det11 - det2;
    //Eigenvalues
    eigv1 = (-bc - sqrt((bc * bc) - (4 * ac * cc))) / (2 * ac);
    eigv2 = (-bc + sqrt((bc * bc) - (4 * ac * cc))) / (2*ac);
    
    if (eigv1 == eigv2)
    {
        cout << "\n\nThe Eigen Values for this matrix are: " << eigv1 << "\n";
    }
    else
    {
        cout << "\n\nThe Eigen Values for this matrix are: " << eigv1 << " and " << eigv2 << "\n";
    }
    system("PAUSE"); system("cls");
}

int main()
{
    int option;
    cout << "Assessment 2\nExisting Project\nPresented by: Diego Rojas (00315670T)\n";
    cout << "\nSelect your option:\n1.\tEigen Values of a 2-by-2 matrix.\n2.\tExit\n";
    cout << "\nInsert your choice: "; cin >> option;
    system("cls");

    switch (option)
    {
    case 1:
        calcu();
        main();
        break;
    case 2:
        cout << "Thanks for your attention!";
        return 0;
        break;
    default:
        cout << "Wrong option selected\n";
        system("PAUSE"); system("cls");
        main();
    }
}
