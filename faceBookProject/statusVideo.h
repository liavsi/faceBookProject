#ifndef STATUSVIDEO_H
#define STATUSVIDEO_H

#include "status.h"


class StatusVideo : virtual public StatusText
{
public:
	StatusVideo(const std::string& textContent, const std::string& video) :StatusText(textContent)
	{
		this->video = video;
	}

	//operator overloads
	const bool operator ==(const Status& other) const override
	{
		const StatusVideo* temp = dynamic_cast<const StatusVideo*>(&other);
		if (temp == NULL)
			return false;
		if (temp == this)
			return this->video == temp->video;

	}

	const bool operator !=(const Status& other)const override
	{
		return !(*this == other);
	}

	void showPost() const override
	{
		cout << "Status video is at: " << video ;
		this->Status::showPost();
	}

	virtual void toOs(ostream& os) const override
	{
		os <<"\n" << textContent << "\n" << video;
	}
private:
	std::string video; //video address

};




#endif // !STATUSVIDEO_H
