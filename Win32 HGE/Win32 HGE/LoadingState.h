#pragma once

#include <future>
#include <vector>
#include <string>
#include "IGameState.h"
#include "IResource.h"
#include "ResourceManager.h"
#include "ResourceRequest.h"

class LoadingState : public IGameState
{
private:
	std::vector<std::string> m_resourcesToLoad;
	std::future<bool> *m_future;
	std::vector<ResourceRequest*> m_requests;

public:
	LoadingState(std::vector<std::string>);

	void Update() override;
	void Render() override;

	void HandleKeyboardEvent(KeyEvent*) override;
	void HandleMouseEvent(MouseEvent*) override;
	void ChangeGameStateTo(IGameState::State) override;
	void LoadResources() override;
	std::vector<std::string> GetResourceVector();

	void OnNotify(IEvent*);

	void SetResourcesToLoad(std::vector<std::string>);

	~LoadingState(void);
};
