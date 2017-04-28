#include "precompiled.h"
#include "ResourceManager.h"
#include <future>
#include <process.h>

ResourceManager* ResourceManager::m_instance = 0;

ResourceManager::ResourceManager(void){
	m_loading = false;
	mutex = CreateMutex(NULL, FALSE, NULL);
}

void ResourceManager::StartThread(){
	threadHandle = (HANDLE)_beginthread(ResourceManager::ResourceThread, 0, NULL);
}

void ResourceManager::ResourceThread(LPVOID lpParam){
	while(1){
		if(!RESOURCE_MANAGER->m_requests.size() > 0)
			continue;

		ResourceRequest *request = RESOURCE_MANAGER->m_requests[0];
		IResource* resource = request->GetResource();
		std::string path = resource->GetPath();

		/*int size = RESOURCE_MANAGER->m_requests.size();
		if(RESOURCE_MANAGER->ResourceExists(path)){
		RESOURCE_MANAGER->m_requests.erase(RESOURCE_MANAGER->m_requests.begin());
		int size1 = RESOURCE_MANAGER->m_requests.size();
		continue;
		}*/
		
		std::string fileExtension = path.substr(path.length() - 4); 
		if(fileExtension == ".jpg" || fileExtension == ".png"){
			resource->Load();
		}
		else if(fileExtension == ".fnt"){
			resource->Load();
		}

		RESOURCE_MANAGER->m_availableResources[path] = resource;
		RESOURCE_MANAGER->m_requests.erase(RESOURCE_MANAGER->m_requests.begin());
	}
}

std::future<bool>* ResourceManager::LoadResource(std::string totalPath){
	m_allResourcesPath = totalPath;
	m_loading = true;
	return NULL;
}

bool ResourceManager::ProcessRequest(ResourceRequest* request){
	std::string path = request->GetResource()->GetPath();
	if(m_availableResources[path] == NULL){
		m_requests.push_back(request);
		return false;
	}
	return true;
}

void ResourceManager::Unload(std::string path){
	m_availableResources.erase(path);
}

bool ResourceManager::ResourceExists(std::string resourcePath){
	return (m_availableResources[resourcePath] != NULL);
}

IResource* ResourceManager::GetResource(std::string path){
	return m_availableResources[path];
}

ResourceManager* ResourceManager::GetInstance(){
	if(m_instance == NULL)
		m_instance = new ResourceManager();
	return m_instance;
}

ResourceManager::~ResourceManager(void){
}

