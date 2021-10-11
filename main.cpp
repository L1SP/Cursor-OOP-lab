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
    cout << "Введите начальные координаты курсора: ";
    cin >> x >> y;
    while (type != "горизонтальный" && type != "вертикальный") {
        cout << "Введите тип курсора(горизонтальный или вертикальный): ";
        cin >> type;
    }
    while (size > 15 || size < 1) {
        cout << "Введите размер курсора(от 1 до 15): ";
        cin >> size;
    }
    A->init(x, y, type, size);

    while(c!='0'){
        cout<<"Выберите пункт меню:"<<endl;
        cout<<"1. Изменить положение курсора."<<endl;
        cout<<"2. Изменить тип курсора."<<endl;
        cout<<"3. Изменить размер курсора."<<endl;
        cout<<"4. Получить положение курсора."<<endl;
        cout<<"5. Получить тип курсора."<<endl;
        cout<<"6. Получить размер курсора."<<endl;
        cout << "7. Скрыть курсор." << endl;
        cout << "8. Показать курсор." << endl;
        cout << "9. Вывести информацию о классе Cursor." << endl;
        cout<<"0. Завершить работу программы."<<endl;
        cin>>c;
        switch(c){
            case '1':
            {
                if (A->isHidden())
                    cout << "Курсор скрыт, изменение данных недоступно." << endl;
                else
                {
                    int _x, _y;
                    cout << "Введите новые координаты курсора: ";
                    cin >> _x >> _y;
                    A->setPositionX(_x);
                    A->setPositionY(_y);
                }
                break;
            }
            case '2':
            {
                if (A->isHidden())
                    cout << "Курсор скрыт, изменение данных недоступно." << endl;
                else {
                    string _type;
                    cout << "Введите новый тип курсора: ";
                    cin >> _type;
                    if (_type != "горизонтальный" && _type != "вертикальный")
                        cout << "Тип может принимать значения \"горизонтальный\" и \"вертикальный\"" << endl;
                    else
                        A->setType(_type);
                }
                break;
            }
            case '3':
            {
                if (A->isHidden()) {
                    cout << "Курсор скрыт, изменение данных недоступно." << endl;
                }
                else {
                    int _size;
                    cout << "Введите новый размер: ";
                    cin >> _size;
                    if (_size < 1 || _size>15)
                        cout << "Размер курсора может принимать значения от 1 до 15" << endl;
                    else
                        A->setSize(_size);
                }
                break;
            }
            case '4':
            {
                if (A->isHidden())
                    cout << "Курсор скрыт, информация недоступна." << endl;
                else
                    cout << "Текущие координаты курсора: " << A->getPositionX() << " " << A->getPositionY() << endl;
                break;
            }
            case '5':
            {
                if (A->isHidden())
                    cout << "Курсор скрыт, информация недоступна." << endl;
                else
                    cout << "Текущий тип курсора: " << A->getType() << endl;
                break;
            }
            case '6':
            {
                if (A->isHidden())
                    cout << "Курсор скрыт, информация недоступна." << endl;
                else
                    cout << "Текущий размер курсора: " << A->getSize() << endl;
                break;
            }
            case '7':
            {
                if (A->isHidden())
                    cout << "Курсор уже скрыт." << endl;
                else {
                    A->hide();
                    cout << "Курсор скрыт." << endl;
                }
                break;
            }
            case '8':
            {
                if (!(A->isHidden()))
                    cout << "Курсор еще не скрыт." << endl;
                else {
                A->show();
                cout << "Курсор восстановлен." << endl;
                }
                break;
            }
            case '9':
            {
                cout << "Информация об объекте: ";
                cout<<A->toString();
                break;
            }
        }
    }
    delete A;
    return 0;
}