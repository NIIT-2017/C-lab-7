#include <stdio.h>

struct RegionInfo
{
	char isoCountry[3];
	char regionCode[3];
	char regionName[50];
	RegionInfo* next;
};

RegionInfo* fillList(RegionInfo* begin);
void freeList(RegionInfo* begin);
void RegionNameSP(RegionInfo* begin, char* nameRegion);
void CountryISO_SP(RegionInfo* begin, char* countryISO);
