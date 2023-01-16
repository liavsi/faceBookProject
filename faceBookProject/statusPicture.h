#ifndef STATUSPICTURE_H
#define STATUSPICTURE_H

#include "status.h"


class StatusPicture : virtual public StatusText
{
public:
	StatusPicture(const std::string& textContent,const std::string& picture, const Date& d, const Time& t) :StatusText(textContent,d,t)
	{
		this->picture = picture;
	}

	StatusPicture(const std::string& textContent, const std::string& picture) :StatusText(textContent)
	{
		this->picture = picture;
	}

	//operator overloads
	const bool operator ==(const Status& other) const override
	{
		const StatusPicture* temp = dynamic_cast<const StatusPicture*>(&other);
		if (temp == NULL)
			return false;
		else if (temp == this)
			return this->picture == temp->picture;

	}

	const bool operator !=(const Status& other)const override
	{
		return !(*this == other);
	}
	void showPost() const override
	{
		cout <<"Status picture is at: "<< picture;
		this->Status::showPost();
	}

	virtual void toOs(ostream& os) const override
	{
		os <<"\n"<< textContent << "\n" << picture;
	}

private:
	std::string picture; //picture address

};




#endif // !STATUS_H
