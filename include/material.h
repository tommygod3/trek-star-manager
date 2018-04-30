#ifndef MATERIAL_H
#define MATERIAL_H

#include "sbst.h"

namespace SDI
{
	class material
	{
	private:
		//Filename at loading
		string materialFilename;
		//Unique ID to identify material
		unsigned long long materialId;
		//0 = DVD, 1 = DS-DVD, 2 = Boxset, 3 = VHS, 4 = Bluray
		unsigned int materialType;
		string title;
		string format;
		string audioFormat;
		string runtime;
		string language;
		unsigned int retailPrice;
		string subtitles;
		string frameAspect;
		string packaging;
		vector<string> additionalLanguages;
		string bonusFeatures = "";
		vector<string> additionalSubtitles;
		string sideOneDetails = "";
		string sideTwoDetails = "";
		stringBinarySearchTree movieList;
		//Whether this should be saved
		bool toBeSaved = 1;

	public:
		//Constructor to set id
		material(unsigned long long idIn, bool exists);
		//Destructor
		~material();
		//Function to load in from file
		void loadIn();
		//Function to save to file
		void saveOut();
		//Function to delete material
		void removeThisMaterial();
		//Getters:
		unsigned long long getMaterialId();
		unsigned int getMaterialType();
		string getTitle();
		string getFormat();
		string getAudioFormat();
		string getRuntime();
		string getLanguage();
		unsigned int getRetailPrice();
		string getSubtitles();
		string getFrameAspect();
		string getPackaging();
		vector<string> getAdditionalLanguages();
		string getBonusFeatures();
		vector<string> getAdditionalSubtitles();
		string getSideOneDetails();
		string getSideTwoDetails();
		vector<string> getMovieList();
		//Setters:
		void setMaterialId(unsigned long long idIn);
		void setMaterialType(unsigned int typeIn);
		void setTitle(string titleIn);
		void setFormat(string formatIn);
		void setAudioFormat(string audioFormatIn);
		void setRuntime(string runtimeIn);
		void setLanguage(string laguageIn);
		void setRetailPrice(unsigned int retailPriceIn);
		void setSubtitles(string subtitlesIn);
		void setFrameAspect(string frameAspectIn);
		void setPackaging(string packagingIn);
		void setAdditionalLanguages(vector<string> additionalLaguagesIn);
		void resetAdditionalLanguages();
		void addAdditionalLanguage(string additionalLaguageIn);
		void setBonusFeatures(string bonusFeaturesIn);
		void resetBonusFeatures();
		void setAdditionalSubtitles(vector<string> additionalSubtitlesIn);
		void resetAdditionalSubtitles();
		void addAdditionalSubtitle(string additionalSubtitleIn);
		void setSideOneDetails(string sideOneDetailsIn);
		void resetSideOneDetails();
		void setSideTwoDetails(string sideTwoDetailsIn);
		void resetSideTwoDetails();
		void resetMovieList();
		void addToMovieList(string movieIn);
		//Calculations:
		void setFromFile(string inFromFile, unsigned int attribute);
	};
}


#endif
