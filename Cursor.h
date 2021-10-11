#include <string>
using namespace std;
class Cursor{
    int x;
    int y;
    string type;
    int size;
    int hidden_size;
    bool hidden;
    public:
        void setPositionX(int _x);
        void setPositionY(int _y);
        void setType(string _type);
        void setSize(int _size);
        void setHiddenSize(int _hidden_size);
        void setHidden(bool _hidden);
        int getPositionX();
        int getPositionY();
        string getType();
        int getSize();
        int getHiddenSize();
        bool getHidden();
        void hide();
        void show();
        void init(int _x, int _y, string _type, int size);
        bool isHidden();
        string toString();
        Cursor();
        Cursor(int _x, int _y, string _type, int size);
        ~Cursor(){};
};