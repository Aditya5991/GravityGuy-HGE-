#include "precompiled.h"
#include "ResourceRequest.h"

ResourceRequest::ResourceRequest(IResource* resource){
	m_resource = resource;
}

IResource* ResourceRequest::GetResource(){
	return m_resource;
}

bool ResourceRequest::IsFulfilled(){
	return m_resource->IsLoaded();
}
