#include <stdio.h>
struct RegionInfo
{
	char regionCode[3];
	char regionName[40];
	char regionISO[3];
	RegionInfo* next; // go next struct
};
RegionInfo* loadingList(RegionInfo* begin);
void clearList(RegionInfo* begin); //free(buf)
void searchNameResult(RegionInfo* begin, char* nameRegion);
void searchISOResult(RegionInfo* begin, char* countryISO);