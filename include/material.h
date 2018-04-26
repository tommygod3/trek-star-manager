#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>
#include <stdexcept>

namespace SDI
{
	using std::vector;
	using std::string;

	class material
	{
	private:
		unsigned long materialId;
		unsigned int materialType;
		string title;
		string format;
		string audioFormat;
		string runtime;
		string language;
		string retailPrice;
		string subtitles;
		string frameAspect;
		string packaging;
		vector<string> additionalLanguages;
		vector<string> additionalSubtitles;
		string bonusFeatures;
		string sideOneDetails;
		string sideTwoDetails;
		vector<string> movieList;

	public:
		//Constructor to set id
		material(unsigned long idIn);
		//Getters:
		unsigned long getMaterialId();
		unsigned int getMaterialType();
		string getTitle();
		string getFormat();
		string getAudioFormat();
		string getRuntime();
		string getLanguage();
		string getRetailPrice();
		string getSubtitles();
		string getFrameAspect();
		string getPackaging();
		vector<string> getAdditionalLanguages();
		vector<string> getAdditionalSubtitles();
		string getBonusFeatures();
		string getSideOneDetails();
		string getSideTwoDetails();
		vector<string> getMovieList();
		//Setters:
		void setMaterialId(unsigned long idIn);
		void setMaterialType(unsigned int typeIn);
		void setTitle(string titleIn);
		void setFormat(string formatIn);
		void setAudioFormat(string audioFormatIn);
		void setRuntime(string runtimeIn);
		void setLanguage(string laguageIn);
		void setRetailPrice(string retailPriceIn);
		void setSubtitles(string subtitlesIn);
		void setFrameAspect(string frameAspectIn);
		void setPackaging(string packagingIn);
		void setAdditionalLanguages(vector<string> additionalLaguagesIn);
		void setAdditionalSubtitles(vector<string> additionalSubtitlesIn);
		void setBonusFeatures(string bonusFeaturesIn);
		void setSideOneDetails(string sideOneDetailsIn);
		void setSideTwoDetails(string sideTwoDetailsIn);
		void setMovieList(vector<string> movieListIn);
	};
}


#endif
