#include "material.h"

namespace SDI
{
	material::material(unsigned long long idIn, bool exists)
	{
		this->setMaterialId(idIn);
		if (exists)
		{
			materialFilename = "../data/material" + std::to_string(idIn) + ".txt";
			loadIn();
		}
	}

	material::~material()
	{
		//Save existing
		if (toBeSaved)
		{
			saveOut();
		}
		else
		{
			remove(materialFilename.c_str());
		}
	}

	void material::loadIn()
	{
		std::ifstream materialIn(materialFilename);
		if (!materialIn.is_open())
		{
			throw std::runtime_error("Error with material file - cannot find " + materialFilename);
		}
		string parser;
		getline(materialIn, parser);

		if (parser == "")
		{
			throw std::runtime_error("Error loading in material info, project name: " + std::to_string(materialId));
		}

		string deliminator = ",";
		size_t position = 0;
		string attributeIn;
		unsigned int counter = 0;
		vector<int> posOfVecs = { 10,12,15 };

		while ((position = parser.find(deliminator)) != std::string::npos)
		{
			attributeIn = parser.substr(0, position);
			if (std::find(posOfVecs.begin(), posOfVecs.end(), counter) != posOfVecs.end())
			{
				int currentAttribute = counter;
				unsigned int quantity = std::stoul(attributeIn);
				parser.erase(0, position + deliminator.length());
				for (unsigned int i = 0; i < quantity; i++)
				{

					position = parser.find(deliminator);
					attributeIn = parser.substr(0, position);
					setFromFile(attributeIn, currentAttribute);
					parser.erase(0, position + deliminator.length());
				}
				position = parser.find(deliminator);
				attributeIn = parser.substr(0, position);
				counter++;
				if (counter > 15)
				{
					break;
				}
			}
			setFromFile(attributeIn, counter);
			parser.erase(0, position + deliminator.length());
			counter++;
		}

		materialIn.close();
	}

	void material::saveOut()
	{
		remove(materialFilename.c_str());
		materialFilename = "../data/material" + std::to_string(getMaterialId()) + ".txt";
		std::ofstream materialOut(materialFilename);
		string csv = ",";

		materialOut << getMaterialType() << csv << getTitle() << csv << getFormat() << csv << getAudioFormat() << csv << getRuntime() << csv << getLanguage() << csv << getRetailPrice() << csv << getSubtitles() << csv << getFrameAspect() << csv << getPackaging() << csv;
		materialOut << additionalLanguages.size() << csv;
		for (unsigned int i = 0; i < additionalLanguages.size(); i++)
		{
			materialOut << additionalLanguages.at(i) << csv;
		}
		materialOut << getBonusFeatures() << csv;
		materialOut << additionalSubtitles.size() << csv;
		for (unsigned int i = 0; i < additionalSubtitles.size(); i++)
		{
			materialOut << additionalSubtitles.at(i) << csv;
		}
		materialOut << getSideOneDetails() << csv << getSideTwoDetails() << csv;
		materialOut << movieList.size() << csv;
		for (unsigned int i = 0; i < movieList.size(); i++)
		{
			materialOut << movieList.at(i) << csv;
		}
		materialOut.close();
	}

	void material::removeThisMaterial()
	{
		toBeSaved = 0;
	}

	//Getters:
	unsigned long long material::getMaterialId()
	{
		return materialId;
	}

	unsigned int material::getMaterialType()
	{
		return materialType;
	}

	string material::getTitle()
	{
		return title;
	}

	string material::getFormat()
	{
		return format;
	}

	string material::getAudioFormat()
	{
		return audioFormat;
	}

	string material::getRuntime()
	{
		return runtime;
	}

	string material::getLanguage()
	{
		return language;
	}

	unsigned int material::getRetailPrice()
	{
		return retailPrice;
	}

	string material::getSubtitles()
	{
		return subtitles;
	}

	string material::getFrameAspect()
	{
		return frameAspect;
	}

	string material::getPackaging()
	{
		return packaging;
	}

	vector<string> material::getAdditionalLanguages()
	{
		return additionalLanguages;
	}

	string material::getBonusFeatures()
	{
		return bonusFeatures;
	}

	vector<string> material::getAdditionalSubtitles()
	{
		return additionalSubtitles;
	}

	string material::getSideOneDetails()
	{
		return sideOneDetails;
	}

	string material::getSideTwoDetails()
	{
		return sideTwoDetails;
	}

	vector<string> material::getMovieList()
	{
		return movieList;
	}

	//Setters:
	void material::setMaterialId(unsigned long long idIn)
	{
		materialId = idIn;
	}

	void material::setMaterialType(unsigned int typeIn)
	{
		if (typeIn > 4)
		{
			throw std::invalid_argument("Material type selection invalid: input greater than 4");
		}
		materialType = typeIn;
	}

	void material::setTitle(string titleIn)
	{
		if (titleIn.size() == 0)
		{
			throw std::invalid_argument("Title selection invalid: input empty");
		}
		title = titleIn;
	}

	void material::setFormat(string formatIn)
	{
		if (formatIn.size() == 0)
		{
			throw std::invalid_argument("Format selection invalid: input empty");
		}
		format = formatIn;
	}

	void material::setAudioFormat(string audioFormatIn)
	{
		if (audioFormatIn.size() == 0)
		{
			throw std::invalid_argument("Audio format selection invalid: input empty");
		}
		audioFormat = audioFormatIn;
	}

	void material::setRuntime(string runtimeIn)
	{
		if (runtimeIn.size() == 0)
		{
			throw std::invalid_argument("Runtime selection invalid: input empty");
		}
		runtime = runtimeIn;
	}

	void material::setLanguage(string languageIn)
	{
		if (languageIn.size() == 0)
		{
			throw std::invalid_argument("Language selection invalid: input empty");
		}
		language = languageIn;
	}

	void material::setRetailPrice(unsigned int retailPriceIn)
	{
		retailPrice = retailPriceIn;
	}

	void material::setSubtitles(string subtitlesIn)
	{
		if (subtitlesIn.size() == 0)
		{
			throw std::invalid_argument("Subtitles selection invalid: input empty");
		}
		subtitles = subtitlesIn;
	}

	void material::setFrameAspect(string frameAspectIn)
	{
		if (frameAspectIn.size() == 0)
		{
			throw std::invalid_argument("Frame aspect selection invalid: input empty");
		}
		frameAspect = frameAspectIn;
	}

	void material::setPackaging(string packagingIn)
	{
		if (packagingIn.size() == 0)
		{
			throw std::invalid_argument("Packaging selection invalid: input empty");
		}
		packaging = packagingIn;
	}

	void material::setAdditionalLanguages(vector<string> additionalLaguagesIn)
	{
		additionalLanguages = additionalLaguagesIn;
	}

	void material::resetAdditionalLanguages()
	{
		additionalLanguages = vector<string>();
	}

	void material::addAdditionalLanguage(string additionalLaguageIn)
	{
		additionalLanguages.push_back(additionalLaguageIn);
	}

	void material::setBonusFeatures(string bonusFeaturesIn)
	{
		if (bonusFeaturesIn.size() == 0)
		{
			throw std::invalid_argument("Bonus features selection invalid: input empty");
		}
		bonusFeatures = bonusFeaturesIn;
	}

	void material::resetBonusFeatures()
	{
		bonusFeatures = "";
	}

	void material::setAdditionalSubtitles(vector<string> additionalSubtitlesIn)
	{
		additionalSubtitles = additionalSubtitlesIn;
	}

	void material::resetAdditionalSubtitles()
	{
		additionalSubtitles = vector<string>();
	}

	void material::addAdditionalSubtitle(string additionalSubtitleIn)
	{
		additionalSubtitles.push_back(additionalSubtitleIn);
	}

	void material::setSideOneDetails(string sideOneDetailsIn)
	{
		if (sideOneDetailsIn.size() == 0)
		{
			throw std::invalid_argument("Side one details selection invalid: input empty");
		}
		//Add option in function call to specify from file so can be set to ""
		sideOneDetails = sideOneDetailsIn;
	}

	void material::resetSideOneDetails()
	{
		sideOneDetails = "";
	}

	void material::setSideTwoDetails(string sideTwoDetailsIn)
	{
		if (sideTwoDetailsIn.size() == 0)
		{
			throw std::invalid_argument("Side two details selection invalid: input empty");
		}
		sideTwoDetails = sideTwoDetailsIn;
	}

	void material::resetSideTwoDetails()
	{
		sideTwoDetails = "";
	}

	void material::setMovieList(vector<string> movieListIn)
	{
		if (movieListIn.size() == 0)
		{
			throw std::invalid_argument("Movie list selection invalid: input empty");
		}
		movieList = movieListIn;
	}

	void material::resetMovieList()
	{
		movieList = vector<string>();
	}

	void material::addToMovieList(string movieIn)
	{
		if (movieIn.size() == 0)
		{
			throw std::invalid_argument("Movie selection invalid: input empty");
		}
		movieList.push_back(movieIn);
	}

	//Calc functions:
	void material::setFromFile(string inFromFile, unsigned int attribute)
	{
		switch (attribute)
		{
		case 0:
			setMaterialType(std::stoi(inFromFile));
			break;
		case 1:
			setTitle(inFromFile);
			break;
		case 2:
			setFormat(inFromFile);
			break;
		case 3:
			setAudioFormat(inFromFile);
			break;
		case 4:
			setRuntime(inFromFile);
			break;
		case 5:
			setLanguage(inFromFile);
			break;
		case 6:
			setRetailPrice(std::stoi(inFromFile));
			break;
		case 7:
			setSubtitles(inFromFile);
			break;
		case 8:
			setFrameAspect(inFromFile);
			break;
		case 9:
			setPackaging(inFromFile);
			break;
		case 10:
			addAdditionalLanguage(inFromFile);
			break;
		case 11:
			if (inFromFile == "")
			{
				resetBonusFeatures();
			}
			else
			{
				setBonusFeatures(inFromFile);
			}
			break;
		case 12:
			addAdditionalSubtitle(inFromFile);
			break;
		case 13:
			if (inFromFile == "")
			{
				resetSideOneDetails();
			}
			else
			{
				setSideOneDetails(inFromFile);
			}
			break;
		case 14:
			if (inFromFile == "")
			{
				resetSideTwoDetails();
			}
			else
			{
				setSideTwoDetails(inFromFile);
			}
			break;
		case 15:
			addToMovieList(inFromFile);
			break;
		}
	}
}