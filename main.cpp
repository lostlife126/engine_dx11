#include "main.h"

using namespace MyEngine;



int main(int argc, char** argv)

{
	Engine engine;

	MyRender* render = new MyRender();

	engine.SetRender(render);
	engine.Init();

	engine.Run();

	engine.Close();
	system("pause");
	return 0;
}