#include "StreamAssetLoader.h"
#include "StringUtils.h"
#include "TextureManager.h"
#include <random>

StreamAssetLoader::StreamAssetLoader(string path, TextureDisplay* display)
{
	this->path = path;
	this->display = display;
}

StreamAssetLoader::~StreamAssetLoader()
{
	cout << "Stream Asset Loader Destroyed" << endl;
}

void StreamAssetLoader::run()
{
	//IETThread::sleep(200);

	std::vector<string> tokens = StringUtils::split(path, '/');
	string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;

	display->spawnObject();

	delete this;
}
