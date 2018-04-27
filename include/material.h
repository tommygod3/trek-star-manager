#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cstdio>
#include <algorithm>

#include <iostream>

namespace SDI
{
	using std::vector;
	using std::string;

	class material
	{
	private:
		//Filename at loading
		string materialFilename;
		//Unique ID to identify material
		unsigned long materialId;
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
		string bonusFeatures;
		vector<string> additionalSubtitles;
		string sideOneDetails;
		string sideTwoDetails;
		vector<string> movieList;

	public:
		//Constructor to set id
		material(unsigned long idIn, bool exists);
		//Destructor
		~material();
		//Function to load in from file
		void loadIn();
		//Function to save to file
		void saveOut();
		//Getters:
		unsigned long getMaterialId();
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
		void setMaterialId(unsigned long idIn);
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
		void addAdditionalLanguage(string additionalLaguageIn);
		void setBonusFeatures(string bonusFeaturesIn);
		void setAdditionalSubtitles(vector<string> additionalSubtitlesIn);
		void addAdditionalSubtitle(string additionalSubtitleIn);
		void setSideOneDetails(string sideOneDetailsIn);
		void setSideTwoDetails(string sideTwoDetailsIn);
		void setMovieList(vector<string> movieListIn);
		void addToMovieList(string movieIn);
		//Calculations:
		void setFromFile(string inFromFile, unsigned int attribute);
	};
}


#endif
