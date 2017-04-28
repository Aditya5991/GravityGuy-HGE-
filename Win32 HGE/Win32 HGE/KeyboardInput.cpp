#include "precompiled.h"
#include "KeyboardInput.h"
#include "..\HGE Tutorials\hgefont.h"

KeyboardInput::KeyboardInput(void){
	keys = new bool[MAX_KEYS];
	Reset();
}

void KeyboardInput::Reset(){
	for(int i = 0; i < MAX_KEYS; i++)
		keys[i] = false;
}

void KeyboardInput::Update(){
	HandleKeyPressed();
	HandleKeyReleased();
}

void KeyboardInput::HandleNumericCharactersPressed(){

}

void KeyboardInput::HandleAlphabetsPressed(){
	if(GetAsyncKeyState(0x41) && !keys[0x41]){ // A
		keys[0x41] = true;
		KeyEvent event(0x41, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x42) && !keys[0x42]){ // B
		keys[0x42] = true;
		KeyEvent event(0x42, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x43) && !keys[0x43]){ // C
		keys[0x43] = true;
		KeyEvent event(0x43, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x44) && !keys[0x44]){ // D
		keys[0x44] = true;
		KeyEvent event(0x44, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x45) && !keys[0x45]){  //E
		keys[0x45] = true;
		KeyEvent event(0x45, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x46) && !keys[0x46]){ // F
		keys[0x46] = true;
		KeyEvent event(0x46, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x47) && !keys[0x47]){ // G
		keys[0x47] = true;
		KeyEvent event(0x47, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x48) && !keys[0x48]){ // H
		keys[0x48] = true;
		KeyEvent event(0x48, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x49) && !keys[0x49]){ // I
		keys[0x49] = true;
		KeyEvent event(0x49, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4A) && !keys[0x4A]){ // J
		keys[0x4A] = true;
		KeyEvent event(0x4A, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4B) && !keys[0x4B]){ // K
		keys[0x4B] = true;
		KeyEvent event(0x4B, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4C) && !keys[0x4C]){ // L
		keys[0x4C] = true;
		KeyEvent event(0x4C, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4D) && !keys[0x4D]){ // M
		keys[0x4D] = true;
		KeyEvent event(0x4D, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4E) && !keys[0x4E]){ // N
		keys[0x4E] = true;
		KeyEvent event(0x4E, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x4F) && !keys[0x4F]){ // O
		keys[0x4F] = true;
		KeyEvent event(0x4F, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x50) && !keys[0x50]){ // P
		keys[0x50] = true;
		KeyEvent event(0x50, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x51) && !keys[0x51]){ // Q
		keys[0x51] = true;
		KeyEvent event(0x51, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x52) && !keys[0x52]){ // R
		keys[0x52] = true;
		KeyEvent event(0x52, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x53) && !keys[0x53]){ // S
		keys[0x53] = true;
		KeyEvent event(0x53, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x54) && !keys[0x54]){ // T
		keys[0x54] = true;
		KeyEvent event(0x54, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x55) && !keys[0x55]){ // U
		keys[0x55] = true;
		KeyEvent event(0x55, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x56) && !keys[0x56]){ // V
		keys[0x56] = true;
		KeyEvent event(0x56, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x57) && !keys[0x57]){ // W
		keys[0x57] = true;
		KeyEvent event(0x57, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x58) && !keys[0x58]){ // X
		keys[0x58] = true;
		KeyEvent event(0x58, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x59) && !keys[0x59]){ // Y
		keys[0x59] = true;
		KeyEvent event(0x59, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(0x5A) && !keys[0x5A]){ // Z
		keys[0x5A] = true;
		KeyEvent event(0x5A, true);
		BROADCASTER->NotifyAll(&event);
	}
}

void KeyboardInput::HandleAlphabetsReleased(){
	if(!GetAsyncKeyState(0x41) && keys[0x41]){ // A
		keys[0x41] = false;
		KeyEvent event(0x41, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x42) && keys[0x42]){ // B
		keys[0x42] = false;
		KeyEvent event(0x42, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x43) && keys[0x43]){ // C
		keys[0x43] = false;
		KeyEvent event(0x43, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x44) && keys[0x44]){ // D
		keys[0x44] = false;
		KeyEvent event(0x44, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x45) && keys[0x45]){  //E
		keys[0x45] = false;
		KeyEvent event(0x45, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x46) && keys[0x46]){ // F
		keys[0x46] = false;
		KeyEvent event(0x46, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x47) && keys[0x47]){ // G
		keys[0x47] = false;
		KeyEvent event(0x47, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x48) && keys[0x48]){ // H
		keys[0x48] = false;
		KeyEvent event(0x48, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x49) && keys[0x49]){ // I
		keys[0x49] = false;
		KeyEvent event(0x49, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4A) && keys[0x4A]){ // J
		keys[0x4A] = false;
		KeyEvent event(0x4A, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4B) && keys[0x4B]){ // K
		keys[0x4B] = false;
		KeyEvent event(0x4B, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4C) && keys[0x4C]){ // L
		keys[0x4C] = false;
		KeyEvent event(0x4C, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4D) && keys[0x4D]){ // M
		keys[0x4D] = false;
		KeyEvent event(0x4D, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4E) && keys[0x4E]){ // N
		keys[0x4E] = false;
		KeyEvent event(0x4E, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x4F) && keys[0x4F]){ // O
		keys[0x4F] = false;
		KeyEvent event(0x4F, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x50) && keys[0x50]){ // P
		keys[0x50] = false;
		KeyEvent event(0x50, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x51) && keys[0x51]){ // Q
		keys[0x51] = false;
		KeyEvent event(0x51, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x52) && keys[0x52]){ // R
		keys[0x52] = false;
		KeyEvent event(0x52, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x53) && keys[0x53]){ // S
		keys[0x53] = false;
		KeyEvent event(0x53, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x54) && keys[0x54]){ // T
		keys[0x54] = false;
		KeyEvent event(0x54, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x55) && keys[0x55]){ // U
		keys[0x55] = false;
		KeyEvent event(0x55, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x56) && keys[0x56]){ // V
		keys[0x56] = false;
		KeyEvent event(0x56, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x57) && keys[0x57]){ // W
		keys[0x57] = false;
		KeyEvent event(0x57, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x58) && keys[0x58]){ // X
		keys[0x58] = false;
		KeyEvent event(0x58, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x59) && keys[0x59]){ // Y
		keys[0x59] = false;
		KeyEvent event(0x59, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(0x5A) && keys[0x5A]){ // Z
		keys[0x5A] = false;
		KeyEvent event(0x5A, false);
		BROADCASTER->NotifyAll(&event);
	}

}

void KeyboardInput::HandleKeyPressed(){

	HandleAlphabetsPressed();
	HandleNumericCharactersPressed();

	/* player 1 */
	if(GetAsyncKeyState(VK_UP)){
		keys[VK_UP] = true;
		KeyEvent event(VK_UP, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_DOWN)){
		keys[VK_DOWN] = true;
		KeyEvent event(VK_DOWN, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_LEFT)){
		keys[VK_LEFT] = true;
		KeyEvent event(VK_LEFT, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		keys[VK_RIGHT] = true;
		KeyEvent event(VK_RIGHT, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_SPACE) && !keys[VK_SPACE]){
		keys[VK_SPACE] = true;
		KeyEvent event(VK_SPACE, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_CONTROL)){
		keys[VK_CONTROL] = true;
		KeyEvent event(VK_CONTROL, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_ESCAPE)){
		keys[VK_ESCAPE] = true;
		KeyEvent event(VK_ESCAPE, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_RETURN)){
		keys[VK_RETURN] = true;
		KeyEvent event(VK_RETURN, true);
		BROADCASTER->NotifyAll(&event);
	}

	/* player 2 */
	if(GetAsyncKeyState(VK_NUMPAD5)){
		keys[VK_NUMPAD5] = true;
		KeyEvent event(VK_NUMPAD5, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_NUMPAD2)){
		keys[VK_NUMPAD2] = true;
		KeyEvent event(VK_NUMPAD2, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_NUMPAD1)){
		keys[VK_NUMPAD1] = true;
		KeyEvent event(VK_NUMPAD1, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_NUMPAD3)){
		keys[VK_NUMPAD3] = true;
		KeyEvent event(VK_NUMPAD3, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_HOME)){
		keys[VK_HOME] = true;
		KeyEvent event(VK_HOME, true);
		BROADCASTER->NotifyAll(&event);
	}
	if(GetAsyncKeyState(VK_INSERT)){
		keys[VK_INSERT] = true;
		KeyEvent event(VK_INSERT, true);
		BROADCASTER->NotifyAll(&event);
	}

}

void KeyboardInput::HandleNumericCharactersReleased(){

}

void KeyboardInput::HandleKeyReleased(){

	HandleAlphabetsReleased();
	HandleNumericCharactersReleased();

	/* player 1 */
	if(!GetAsyncKeyState(VK_SPACE) && keys[VK_SPACE]){
		keys[VK_SPACE] = false;
		KeyEvent event(VK_SPACE, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_UP) && keys[VK_UP]){
		keys[VK_UP] = false;
		KeyEvent event(VK_UP, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_DOWN) && keys[VK_DOWN]){
		keys[VK_DOWN] = false;
		KeyEvent event(VK_DOWN, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_LEFT) && keys[VK_LEFT]){
		keys[VK_LEFT] = false;
		KeyEvent event(VK_LEFT, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_RIGHT) && keys[VK_RIGHT]){
		keys[VK_RIGHT] = false;
		KeyEvent event(VK_RIGHT, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_CONTROL) && keys[VK_CONTROL]){
		keys[VK_CONTROL] = false;
		KeyEvent event(VK_CONTROL, false);
		BROADCASTER->NotifyAll(&event);
	}

	/* player 2 */
	if(!GetAsyncKeyState(VK_NUMPAD5) && keys[VK_NUMPAD5]){
		keys[VK_NUMPAD5] = false;
		KeyEvent event(VK_NUMPAD5, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_NUMPAD2) && keys[VK_NUMPAD2]){
		keys[VK_NUMPAD2] = false;
		KeyEvent event(VK_NUMPAD2, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_NUMPAD1) && keys[VK_NUMPAD1]){
		keys[VK_NUMPAD1] = false;
		KeyEvent event(VK_NUMPAD1, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_NUMPAD3) && keys[VK_NUMPAD3]){
		keys[VK_NUMPAD3] = false;
		KeyEvent event(VK_NUMPAD3, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_HOME) && keys[VK_HOME]){
		keys[VK_HOME] = false;
		KeyEvent event(VK_HOME, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_INSERT) && keys[VK_INSERT]){
		keys[VK_INSERT] = false;
		KeyEvent event(VK_INSERT, false);
		BROADCASTER->NotifyAll(&event);
	}

///////////////////////
	if(!GetAsyncKeyState(VK_RETURN) && keys[VK_RETURN]){
		keys[VK_RETURN] = false;
		KeyEvent event(VK_RETURN, false);
		BROADCASTER->NotifyAll(&event);
	}
	if(!GetAsyncKeyState(VK_ESCAPE) && keys[VK_ESCAPE]){
		keys[VK_ESCAPE] = false;
		KeyEvent event(VK_ESCAPE, false);
		BROADCASTER->NotifyAll(&event);
	}
}

KeyboardInput::~KeyboardInput(){

}