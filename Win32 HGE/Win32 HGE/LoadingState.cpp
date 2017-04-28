#include "precompiled.h"
#include "LoadingState.h"
#include "ResourceLoadingCompletedEvent.h"
#include "Broadcaster.h"
#include "hgefont.h"

LoadingState::LoadingState(std::vector<std::string> resources){
	m_resourcesToLoad = resources;

	ResourceRequest* request = new ResourceRequest(new Texture("font1.png"));
	RESOURCE_MANAGER->ProcessRequest(request);
	
	for(int i = 0; i < m_resourcesToLoad.size(); i++){
		std::string path = m_resourcesToLoad[i];
		std::string fileExtension = path.substr(path.length() - 4);
		if(fileExtension == ".png" || fileExtension == ".jpg"){
			request = new ResourceRequest(new Texture(path));
			bool alreadyAvailable = RESOURCE_MANAGER->ProcessRequest(request);
			if(!alreadyAvailable)
				m_requests.push_back(request);
		}else if(fileExtension == ".fnt"){
			request = new ResourceRequest(new FontResource(path));
			bool alreadyAvailable = RESOURCE_MANAGER->ProcessRequest(request);
			if(!alreadyAvailable)
				m_requests.push_back(request);
		}
	}
}

void LoadingState::Update(){
	if((m_requests.size() == 0) || (m_requests[m_requests.size() - 1]->IsFulfilled())){
		ResourceLoadingCompletedEvent event;
		BROADCASTER->NotifyAll(&event);
	}
}


void LoadingState::Render(){
	hgeFont font("font1.fnt");
	font.printf(100, 100, HGETEXT_MIDDLE, "Loading!");
}

void LoadingState::HandleKeyboardEvent(KeyEvent* event){

}

void LoadingState::HandleMouseEvent(MouseEvent* event){

}

void LoadingState::ChangeGameStateTo(IGameState::State newState){

}

void LoadingState::OnNotify(IEvent* event){

}

void LoadingState::LoadResources(){
}

std::vector<std::string> LoadingState::GetResourceVector(){
	return _resources;
}

void LoadingState::SetResourcesToLoad(std::vector<std::string> resources){
	_resources = resources;
}

LoadingState::~LoadingState(void){

}
