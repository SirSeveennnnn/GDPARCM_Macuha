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
	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist(1000, 4000);
	IETThread::sleep(dist(engine));

	std::vector<string> tokens = StringUtils::split(path, '/');
	string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;

	display->spawnObject();

	delete this;
}
