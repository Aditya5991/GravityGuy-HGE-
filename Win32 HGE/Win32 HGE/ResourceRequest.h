#pragma once

#include <future>
#include "IResource.h"

class ResourceRequest{
public:
	IResource* m_resource;

	ResourceRequest(IResource*);

	IResource* GetResource();

	bool IsFulfilled();
};
