#include"token.h"
#include<fstream>

int lookup(char, int);
bool isLetter(char);
bool isDigit(char);
bool isNotEndState(int);
Token makeToken(string, int, int);

int main()
{
	string name;
	char c;
	int innerCode = 0;
	int state = 0;
	int s;

	ifstream input;
	input.open("source.txt");
	if (input.is_open())
	{
		while (true)
		{
			input >> c;
			int s = lookup(c, state);
			if (s != -1)
			{
				state = s;
				name.push_back(c);
			}
			else
			{
				if (isNotEndState(s))
				{
					cerr << "Transitive Error!" << endl;
					break;
				}
				else
				{
					if (input.eof())
					{
						makeToken(name, state, innerCode).print();
						break;
					}
					else
					{
						input.unget();
						makeToken(name, state, innerCode).print();
						name.clear();
						state = 0;
						innerCode++;
					}
				}
			}
		}
		input.close();
	}
	else
		cerr << "File not open!" << endl;
	return 0;
}

int lookup(char c, int state)
{
	switch(state)
	{
		case 0:
			if (isLetter(c))return 1;
			if (isDigit(c))return 2;
			if (c == '=')return 6;
			if (c == '+')return 7;
			if (c == '-')return 8;
			if (c == '*')return 9;
			if (c == '/')return 10;
			if (c == '^')return 11;
			if (c == '(')return 12;
			if (c == ')')return 13;
			if (c == ';')return 14;
			if (c = '%')return 15;
			else return -1;
			break;
		case 1:
			if (isLetter(c))return 3;
			else return -1;
			break;
		case 2:
			if (isDigit(c))return 2;
			if (c == '.')return 4;
			else return -1;
			break;
		case 3:
			if (isLetter(c) || isDigit(c))return 3;
			else return -1;
			break;
		case 4:
			if (isDigit(c))return 5;
			else return -1;
			break;
		case 5:
			if (isDigit(c))return 5;
			else return -1;
			break;
		default:
			return -1;
			break;
	}
}

bool isLetter(char c)
{
	if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'))
		return true;
	else
		return false;
}

bool isDigit(char c)
{
	if (c >= '0'&&c <= '9')
		return true;
	else
		return false;
}

bool isNotEndState(int s)
{
	if (s == 0)
		return true;
	else
		return false;
}

Token makeToken(string name, int state, int innerCode)
{
	Type type;
	switch (state)
	{
	case 1:
	case 3:
		type = ID;
		break;
	case 2:
	case 4:
	case 5:
		type = VALUE;
		break;
	case 6:
		type = EQUAL;
		break;
	case 7:
		type = PLUS;
		break;
	case 8:
		type = MINUS;
		break;
	case 9:
		type = MUL;
		break;
	case 10:
		type = DIV;
		break;
	case 11:
		type = POW;
		break;
	case 12:
		type = LEFTBRACE;
		break;
	case 13:
		type = RIGHTBRACE;
		break;
	case 14:
		type = END;
		break;
	case 15:
		type = MOD;
		break;
	}
	return Token(name, type, innerCode);
}