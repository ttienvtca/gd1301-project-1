#include "DemoJson.h"
#include "json/rapidjson.h"
#include "json/document.h"

bool DemoJson::init()
{
	if (!Scene::init())
	{
		return false;
	}

	std::string dataContent = FileUtils::getInstance()->getStringFromFile("game-data.json");

	rapidjson::Document docs;

	docs.Parse(dataContent.c_str());

	std::string charName = docs["characterName"].GetString();
	float speed = docs["speed"].GetFloat();

	log("Character Name: %s", charName.c_str());
	log("Character Speed: %lf", speed);

	auto weapons = docs["weapons"].GetArray();
	for (int i = 0; i < weapons.Size(); ++i)
	{
		std::string name = weapons[0]["weaponName"].GetString();
		int level = weapons[0]["level"].GetInt();

		log("weapon name: %s", name.c_str());
		log("weapon level: %d", level);
	}


	return true;
}
