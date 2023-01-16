#ifndef STATUSVIDEO_H
#define STATUSVIDEO_H

#include "status.h"


class StatusVideo : virtual public Status
{
public:
	StatusVideo(const std::string& video) :Status()
	{
		this->video = video;
	}

	//operator overloads
	const bool operator ==(const Status& other) const override
	{
		const StatusVideo* temp = dynamic_cast<const StatusVideo*>(&other);
		if (temp == NULL)
			return false;
		return this->video == temp->video;

	}

	const bool operator !=(const Status& other)const override
	{
		return !(*this == other);
	}

	void showPost() const override
	{
		cout << "Status video is at: " << video << "| posted at: ";
		this->Status::showPost();
	}

private:
	std::string video; //video address

};




#endif // !STATUSVIDEO_H
