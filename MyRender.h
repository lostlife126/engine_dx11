#pragma once

#include "engine.h"
#include <xnamath.h>
#include "StaticMesh.h"

using namespace MyEngine;
class MyRender : public Render
{
public:
	MyRender();
	bool Init(HWND hwnd);
	bool Draw();
	void Close();

	XMMATRIX* getCamera()
	{
		return &m_View;
	}

private:

	StaticMesh* m_mesh;

	XMMATRIX m_View;
};