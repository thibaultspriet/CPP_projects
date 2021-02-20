#include <string>
using namespace std;

class Voiture{

    string color;
    int number;

    public:
        string getColor();
        int getNumber();
        void setColor(string color);
        void setNumber(int number);
        virtual void fillUp() = 0;
        virtual ~Voiture();
};