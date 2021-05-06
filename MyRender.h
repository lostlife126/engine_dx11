#pragma once

#include "engine.h"
#include <xnamath.h>

using namespace MyEngine;
class StaticMesh;
class MyRender : public Render
{
public:
	MyRender();
	bool Init(HWND hwnd);
	bool Draw();
	void Close();

	void* operator new(size_t i)
	{
		return _aligned_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_aligned_free(p);
	}

	XMMATRIX* getCamera()
	{
		return &m_View;
	}

private:
	friend StaticMesh;

	StaticMesh* m_mesh;

	XMMATRIX m_View;
	XMMATRIX m_Projection;
};