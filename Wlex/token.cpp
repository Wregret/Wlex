#include"token.h"

Token::Token()
{

}

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

void Token::write(ofstream &output)
{
	output << "(" << name << ", " << type << ", " << innerCode << ")" << endl;
}