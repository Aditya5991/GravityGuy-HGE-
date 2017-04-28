#include "precompiled.h"
#include "IResource.h"

std::string IResource::GetPath(){ return m_path; }

bool IResource::IsLoaded(){
	return !m_future.valid();
}

void IResource::Load(){
}