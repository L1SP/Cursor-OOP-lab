#include <iostream>
#include <Windows.h>
#include "Cursor.h"
using namespace std;

int main(){
    int x=0, y=0, size=0;
    string type="none";
    char c = ' ';
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Cursor *A = new Cursor;
    cout << "������� ��������� ���������� �������: ";
    cin >> x >> y;
    while (type != "��������������" && type != "������������") {
        cout << "������� ��� �������(�������������� ��� ������������): ";
        cin >> type;
    }
    while (size > 15 || size < 1) {
        cout << "������� ������ �������(�� 1 �� 15): ";
        cin >> size;
    }
    A->init(x, y, type, size);

    while(c!='0'){
        cout<<"�������� ����� ����:"<<endl;
        cout<<"1. �������� ��������� �������."<<endl;
        cout<<"2. �������� ��� �������."<<endl;
        cout<<"3. �������� ������ �������."<<endl;
        cout<<"4. �������� ��������� �������."<<endl;
        cout<<"5. �������� ��� �������."<<endl;
        cout<<"6. �������� ������ �������."<<endl;
        cout << "7. ������ ������." << endl;
        cout << "8. �������� ������." << endl;
        cout << "9. ������� ���������� � ������ Cursor." << endl;
        cout<<"0. ��������� ������ ���������."<<endl;
        cin>>c;
        switch(c){
            case '1':
            {
                if (A->isHidden())
                    cout << "������ �����, ��������� ������ ����������." << endl;
                else
                {
                    int _x, _y;
                    cout << "������� ����� ���������� �������: ";
                    cin >> _x >> _y;
                    A->setPositionX(_x);
                    A->setPositionY(_y);
                }
                break;
            }
            case '2':
            {
                if (A->isHidden())
                    cout << "������ �����, ��������� ������ ����������." << endl;
                else {
                    string _type;
                    cout << "������� ����� ��� �������: ";
                    cin >> _type;
                    if (_type != "��������������" && _type != "������������")
                        cout << "��� ����� ��������� �������� \"��������������\" � \"������������\"" << endl;
                    else
                        A->setType(_type);
                }
                break;
            }
            case '3':
            {
                if (A->isHidden()) {
                    cout << "������ �����, ��������� ������ ����������." << endl;
                }
                else {
                    int _size;
                    cout << "������� ����� ������: ";
                    cin >> _size;
                    if (_size < 1 || _size>15)
                        cout << "������ ������� ����� ��������� �������� �� 1 �� 15" << endl;
                    else
                        A->setSize(_size);
                }
                break;
            }
            case '4':
            {
                if (A->isHidden())
                    cout << "������ �����, ���������� ����������." << endl;
                else
                    cout << "������� ���������� �������: " << A->getPositionX() << " " << A->getPositionY() << endl;
                break;
            }
            case '5':
            {
                if (A->isHidden())
                    cout << "������ �����, ���������� ����������." << endl;
                else
                    cout << "������� ��� �������: " << A->getType() << endl;
                break;
            }
            case '6':
            {
                if (A->isHidden())
                    cout << "������ �����, ���������� ����������." << endl;
                else
                    cout << "������� ������ �������: " << A->getSize() << endl;
                break;
            }
            case '7':
            {
                if (A->isHidden())
                    cout << "������ ��� �����." << endl;
                else {
                    A->hide();
                    cout << "������ �����." << endl;
                }
                break;
            }
            case '8':
            {
                if (!(A->isHidden()))
                    cout << "������ ��� �� �����." << endl;
                else {
                A->show();
                cout << "������ ������������." << endl;
                }
                break;
            }
            case '9':
            {
                cout << "���������� �� �������: ";
                cout<<A->toString();
                break;
            }
        }
    }
    delete A;
    return 0;
}