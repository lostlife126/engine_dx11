#include "main.h"

using namespace MyEngine;


int main(int argc, char** argv)

{
	Engine engine;

	MyRender* render = new MyRender();
	MyInputCamera* input = new MyInputCamera();
	FrameworkDesc desc;
	desc.wnd.width = 640;
	desc.wnd.height = 480;
	desc.render = render;
	engine.SetRender(render);
	engine.Init(desc);
	engine.AddInputListener(input);
	input->setView(render->getCamera());
	engine.Run();

	engine.Close();
	system("pause");
	return 0;
}