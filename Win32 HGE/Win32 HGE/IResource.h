#pragma once

#include <string>

class IResource
{
protected:
	std::promise<bool> m_promise;
	std::future<bool> m_future;
	std::string m_path;

public:
	IResource(){
	}

	IResource(const IResource& obj){
	}

	virtual void Load() = 0;
	virtual std::string GetPath();
	virtual bool IsLoaded();
	virtual ~IResource() {}
};
