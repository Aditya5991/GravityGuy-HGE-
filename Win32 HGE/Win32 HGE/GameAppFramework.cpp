#include "precompiled.h"
#include "GameAppFramework.h"
#include "hgefont.h"
#include "Utils.h"
#include "ResourceManager.h"
#include "Animation.h"

GameAppFramework* GameAppFramework::m_instance = 0;

GameAppFramework::GameAppFramework(void){
}


void GameAppFramework::init(){
	m_hge = hgeCreate(HGE_VERSION);

	m_hge->System_SetState(HGE_FRAMEFUNC, HGEUpdateCallback);
	m_hge->System_SetState(HGE_RENDERFUNC, HGERenderCallback);
	m_hge->System_SetState(HGE_FPS, FPS);

	m_hge->System_SetState(HGE_WINDOWED, true);
	m_hge->System_SetState(HGE_TITLE, "Game");

	m_hge->System_SetState(HGE_SCREENWIDTH, GAME_WIDTH);
	m_hge->System_SetState(HGE_SCREENHEIGHT, GAME_HEIGHT);
	m_hge->System_SetState(HGE_SCREENBPP, 32);

	_cursor = new hgeSprite(m_hge->Texture_Load("Ball.jpg"), 0, 0, 32, 32);
}

void GameAppFramework::StartGame(){
	if(m_hge->System_Initiate()){
		RESOURCE_MANAGER->StartThread();
		m_hge->System_Start();
	}
	else{	
		MessageBox(NULL, "Errrrrrrrrrrrrrrrr", "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
}

void GameAppFramework::EndGame(){
	m_hge->System_Shutdown();
	m_hge->Release();
}

bool GameAppFramework::Update()
{
	INPUT_INSTANCE->Update();

	GAME_STATE_MANAGER->Update();

	return true;
}

bool GameAppFramework::Render(){
	m_hge->Gfx_BeginScene();
	m_hge->Gfx_Clear(0);

	GAME_STATE_MANAGER->Render();

	float mouseX, mouseY;
	HGE_INSTANCE->Input_GetMousePos(&mouseX, &mouseY);
	_cursor->Render(mouseX, mouseY);

	m_hge->Gfx_EndScene();
	return false;
}

bool GameAppFramework::HGEUpdateCallback(){
	//If true : HGE exits the game loop
	return !GameAppFramework::GetInstance()->Update();
}

bool GameAppFramework::HGERenderCallback(){
	return GameAppFramework::GetInstance()->Render();
}

HGE* GameAppFramework::getHGE(){ return m_hge; }

GameAppFramework* GameAppFramework::GetInstance(){
	if(m_instance == NULL) 
		m_instance = new GameAppFramework();
	return m_instance;
}

GameAppFramework::~GameAppFramework(void){
}
