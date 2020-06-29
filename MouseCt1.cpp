#include <DxLib.h>
#include "MouseCt1.h"
#include "_debug/_DebugConOut.h"

MouseCt1::MouseCt1()
{
	pos = { 0,0 };
	mouseData = 0;
	mouseDataOld = 0;
	TRACE("MouseCt1の生成")
}

MouseCt1::~MouseCt1()
{
	TRACE("MouseCt1の破棄")
}

bool MouseCt1::GetClickTrg(void)
{
	return (mouseData == 1 && mouseDataOld == 0);
}

bool MouseCt1::GetClicking(void)
{
	return (mouseData == 1 && mouseDataOld == 1);;
}

const Vector2& MouseCt1::GetPos(void)
{
	// TODO: return ステートメントをここに挿入します
	
	return pos;
}

void MouseCt1::Update()
{
	// マウスの座標取得
	GetMousePoint(&pos.x, &pos.y);
	mouseDataOld = mouseData;
	// マウスのクリック状態取得
	mouseData = GetMouseInput();

}
