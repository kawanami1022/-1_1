#include <DxLib.h>
#include "Myself.h"
#include "TicketMachine.h"
#include "main.h"
#define SCREEN_SIZE_X (800)
#define SCREEN_SIZE_Y (600)

//Myself* s_Instance = nullptr;
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Myself::GetInstance().Run();
	Myself::Destroy();
	return 0;
}

