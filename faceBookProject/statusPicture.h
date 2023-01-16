#ifndef STATUSPICTURE_H
#define STATUSPICTURE_H

#include "status.h"


class StatusPicture : virtual public Status
{
public:
	StatusPicture(std::string& picture) :Status()
	{
		this->picture = picture;
	}

	//operator overloads
	const bool operator ==(const Status& other) const override
	{
		const StatusPicture* temp = dynamic_cast<const StatusPicture*>(&other);
		if (temp == NULL)
			return false;
		return this->picture == temp->picture;

	}

	const bool operator !=(const Status& other)const override
	{
		return !(*this == other);
	}
	void showPost() const override
	{
		cout <<"Status picture is at: "<< picture << "| posted at: ";
		this->Status::showPost();
	}

private:
	std::string picture; //picture address

};




#endif // !STATUS_H
