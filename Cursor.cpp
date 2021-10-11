#include <iostream>
#include <string>
#include "Cursor.h"
using namespace std;
void Cursor::setPositionX(int _x){
    x=_x;
}
void Cursor::setPositionY(int _y) {
    y = _y;
}
void Cursor::setType(string _type){
    type = _type;
}
void Cursor::setSize(int _size){
    size=_size;
}
void Cursor::setHiddenSize(int _hidden_size) {
    hidden_size = _hidden_size;
}
void Cursor::setHidden(bool _hidden) {
    hidden = _hidden;
}
void Cursor::hide(){
    hidden_size=size;
    hidden = 1;
    size=0;
}
void Cursor::show(){
    size=hidden_size;
    hidden = 0;
    hidden_size=0;
}
Cursor::Cursor() {
    x = 0;
    y = 0;
    type = "none";
    size = 0;
    hidden_size = 0;
    hidden = 0;
}
Cursor::Cursor(int _x=0, int _y=0, string _type="none", int _size = 0) {
    x=_x;
    y=_y;
    type = _type;
    size = _size;
    hidden_size = 0;
    hidden = 0;
};
int Cursor::getPositionX() {
    return x;
}
int Cursor::getPositionY() {
    return y;
}
string Cursor::getType() {
    return type;
}
int Cursor::getSize() {
    return size;
}
int Cursor::getHiddenSize() {
    return hidden_size;
}
bool Cursor::getHidden() {
    return hidden;
}
void Cursor::init(int _x, int _y, string _type, int _size) {
    x = _x;
    y = _y;
    type = _type;
    size = _size;
}
bool Cursor::isHidden() {
    return hidden;
}
string Cursor::toString() {
    string str = "x= ";
    str += getPositionX();
    str += ", ";
    str += "y = ";
    str += to_string(getPositionY());
    str += ", ";
    str += "type = ";
    str += getType();
    str += ", ";
    str += "size = ";
    str += to_string(getSize());
    str += ", ";
    str += "hidden_size = ";
    str += to_string(getHiddenSize());
    str += ", ";
    str += "hidden = ";
    str += to_string(getHidden());
    str += '\n';
    return str;
}