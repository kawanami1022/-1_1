#pragma once
#include "Vector2/Vector2.h"

class MouseCt1
{
public:
	MouseCt1();
	~MouseCt1();

	bool GetClickTrg(void);			// クリックした瞬間の場合、true
	bool GetClicking(void);			// クリック中の場合、true
	const Vector2& GetPos(void);	// クリック位置の取得
	void Update();					// マウスクリックの更新

private:
	Vector2 pos;				// マウスの座標
	char mouseData;			// 現在のマウスのクリック状態
	char mouseDataOld;		// 1フレーム前のマウスのクリック状態
};

