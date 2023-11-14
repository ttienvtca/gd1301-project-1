#include "DemoJson.h"
#include "json/rapidjson.h"
#include "json/document.h"

bool DemoJson::init()
{
	if (!Scene::init())
	{
		return false;
	}

	std::string content = FileUtils::getInstance()->getStringFromFile("data.json");

	rapidjson::Document docs;

	docs.Parse(content.c_str());

	int coinData = docs["coin"].GetInt();

	std::string playerName = docs["playerName"].GetString();

	auto stats = docs["stats"].GetArray();

	for (int i = 0; i < stats.Size(); ++i)
	{
		int atk = stats[i]["atk"].GetInt();
		int hp = stats[i]["hp"].GetInt();
		log("atk: %d", atk);
		log("hp: %d", hp);
	}

	return true;
}
