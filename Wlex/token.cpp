#include"token.h"

Token::Token(string name, Type type, int innerCode)
{
	this->name = name;
	this->type = type;
	this->innerCode = innerCode;
}

void Token::print()
{
	cout << "(" << name << ", " << type << ", " << innerCode << ")" << endl;
}