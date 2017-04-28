#include "precompiled.h"
#include "FontResource.h"

FontResource::FontResource(std::string path){
	m_path = path;
	m_future = m_promise.get_future();
}

void FontResource::Load(){
	m_font = new hgeFont(m_path.c_str());
	m_future.share();
}

void FontResource::Render(int x, int y, std::string text){
	m_font->Render(x, y, HGETEXT_MIDDLE, text.c_str());
}

bool FontResource::IsLoaded(){
	return !m_future.valid();
}

double FontResource::GetStringWidth(std::string str){
	return m_font->GetStringWidth(str.c_str());
}

double FontResource::GetHeight(){
	return m_font->GetHeight();
}

FontResource::~FontResource(void){
}
