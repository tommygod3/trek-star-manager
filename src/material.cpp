#include "material.h"

namespace SDI
{
	material::material(unsigned long idIn)
	{
		this->setMaterialId(idIn);
	}

	//Getters:
	unsigned long material::getMaterialId()
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

	string material::getRetailPrice()
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

	vector<string> material::getAdditionalSubtitles()
	{
		return additionalSubtitles;
	}

	string material::getBonusFeatures()
	{
		return bonusFeatures;
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
	void material::setMaterialId(unsigned long idIn)
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

	void material::setRetailPrice(string retailPriceIn)
	{
		if (retailPriceIn.size() == 0)
		{
			throw std::invalid_argument("Retail price selection invalid: input empty");
		}
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

	void material::setAdditionalSubtitles(vector<string> additionalSubtitlesIn)
	{
		additionalSubtitles = additionalSubtitlesIn;
	}

	void material::setBonusFeatures(string bonusFeaturesIn)
	{
		if (bonusFeaturesIn.size() == 0)
		{
			throw std::invalid_argument("Bonus features selection invalid: input empty");
		}
		bonusFeatures = bonusFeaturesIn;
	}

	void material::setSideOneDetails(string sideOneDetailsIn)
	{
		if (sideOneDetailsIn.size() == 0)
		{
			throw std::invalid_argument("Side one details selection invalid: input empty");
		}
		sideOneDetails = sideOneDetailsIn;
	}

	void material::setSideTwoDetails(string sideTwoDetailsIn)
	{
		if (sideTwoDetailsIn.size() == 0)
		{
			throw std::invalid_argument("Side two details selection invalid: input empty");
		}
		sideTwoDetails = sideTwoDetailsIn;
	}

	void material::setMovieList(vector<string> movieListIn)
	{
		if (movieListIn.size() == 0)
		{
			throw std::invalid_argument("Movie list selection invalid: input empty");
		}
		movieList = movieListIn;
	}
}