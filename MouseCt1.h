#pragma once
#include "Vector2/Vector2.h"

class MouseCt1
{
public:
	MouseCt1();
	~MouseCt1();

	bool GetClickTrg(void);			// �N���b�N�����u�Ԃ̏ꍇ�Atrue
	bool GetClicking(void);			// �N���b�N���̏ꍇ�Atrue
	const Vector2& GetPos(void);	// �N���b�N�ʒu�̎擾
	void Update();					// �}�E�X�N���b�N�̍X�V

private:
	Vector2 pos;				// �}�E�X�̍��W
	char mouseData;			// ���݂̃}�E�X�̃N���b�N���
	char mouseDataOld;		// 1�t���[���O�̃}�E�X�̃N���b�N���
};

