#pragma once

#include <xnamath.h>

class Camera
{
public:

	XMVECTOR Eye;
	XMVECTOR At;
	XMVECTOR Up;
	XMMATRIX m_View;
	XMMATRIX m_Projection;

	void Init()
	{
		Eye = XMVectorSet(0.0f, 0.0f, -2.8f, 0.0f);
		At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
		m_View = XMMatrixLookAtLH(Eye, At, Up);

		m_Projection = XMMatrixPerspectiveFovLH(0.4f * 3.14f, (float)640 / 480, 0.1f, 1000.0f);
	}


};
