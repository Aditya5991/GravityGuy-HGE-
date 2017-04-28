#include "precompiled.h"
#include "Texture.h"
#include "GameAppFramework.h"

Texture::Texture(std::string path){
	m_path = path;
	m_future = m_promise.get_future();
}

void Texture::Load(){
	texture = HGE_INSTANCE->Texture_Load(m_path.c_str());
	m_future.share();
}

HTEXTURE Texture::GetData(){
	return texture;
}

bool Texture::IsLoaded(){
	return !m_future.valid();
}

Texture::~Texture(void){
}
