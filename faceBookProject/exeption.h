#ifndef EXEPTION_H
#define EXEPTION_H
#include <iostream>

class FaceBookExeption : public std::exception
{
public:
	virtual const char* what() const override { return "Failed while using Facebook\n"; }
};

class notUniqueExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override { return "This name is already exist in our system..\n"; }
};

class findingUserExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override{ return "This User does not exist in our system..\n"; }
};

class findingFanPageExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override { return "This Fan Page does not exist in our system..\n"; }
};


class DateFormatExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override {	return "Unvalid Date Foramt typed in!\n"; }
};

class DateUnvalidExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override { return "Unvalid date!\n"; }
};

class DateYetToComeExeption : public FaceBookExeption
{
public:
	virtual const char* what() const override { return "This date is yet to arrive!\n"; }
};

class IndexOutOfRange : public FaceBookExeption
{
public:
	virtual const char* what() const override { return "This number is out of range!\n"; }
};



#endif // !EXEPTION_H
