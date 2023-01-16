#ifndef STATUSTEXT_H
#define STATUSTEXT_H

#include "status.h"


class StatusText: virtual public Status
{
public:
	StatusText(const std::string& text) :Status()
	{
		textContent = text;
	}

	StatusText(const StatusText& other) :Status(other)
	{
		textContent = other.textContent;
	}

	//operator overloads
	const bool operator ==(const Status& other) const override
	{
		const StatusText* temp = dynamic_cast<const StatusText*>(&other);
		if (temp == NULL)
			return false;
		return this->textContent == temp->textContent;

	}

	virtual void toOs(ostream& os) const override
	{
		os << " " << textContent;
	}

	const bool operator !=(const Status& other)const override
	{
		return !(*this == other);
	}

	void showPost() const override
	{
		cout <<"Text Content: " << textContent;
		this->Status::showPost();
	}

	
	

protected:
	std::string textContent;

};




#endif // !STATUS_H
