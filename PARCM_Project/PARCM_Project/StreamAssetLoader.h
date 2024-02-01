#pragma once
#include"IETThread.h"
#include "TextureDisplay.h"
#include<string>

using namespace std;

class StreamAssetLoader : public IETThread
{
public:
	StreamAssetLoader(string path, TextureDisplay* display);
	~StreamAssetLoader();

private:
	void run();

	string path;
	TextureDisplay* display;
};

