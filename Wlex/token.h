#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

enum Type{ID,VALUE,EQUAL,PLUS,MINUS,MUL,DIV,POW,MOD,LEFTBRACE,RIGHTBRACE,END};
	
class Token
{
public:
	string name;
	Type type;
	int innerCode;

	Token();
	Token(string, Type, int);                             
	void print();
	void write(ofstream&);
};