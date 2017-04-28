#pragma once

#include <map>
#include <future>
#include <string>
#include "Texture.h"
#include "FontResource.h"
#include "ResourceRequest.h"

#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER ResourceManager::GetInstance()
#endif

class ResourceManager
{
private:
	HANDLE mutex;
	std::string m_allResourcesPath;
	bool m_loading;
	std::map<std::string, IResource*> m_availableResources;
	std::vector<ResourceRequest*> m_requests;
	HANDLE threadHandle ;

	ResourceManager(void);
	static ResourceManager* m_instance;

public:

	bool ResourceExists(std::string);
	std::future<bool>* LoadResource(std::string);
	bool ProcessRequest(ResourceRequest*);
	void Unload(std::string);
	IResource* GetResource(std::string);

	void StartThread();
	
	static void ResourceThread(LPVOID);

	static ResourceManager* GetInstance();
	~ResourceManager(void);
};
