/**
 * CharInfo.cpp
 * ------------
 *
 * Show Character's Fast Hit Recovery, Fast Cast Rate and Fast Block Rate in game.
 *
 * oracle (b3gn_oracle@hotmail.com)
 */
#include "D2HackIt\\Includes\\D2Hackit.h"
#include "D2HackIt\\Includes\\ClientCore.cpp" // Include the backend of the module

BOOL PRIVATE OnGameCommandHelp(char** argv, int argc);
BOOL PRIVATE OnGameCommandFHR(char** argv, int argc);
BOOL PRIVATE OnGameCommandFCR(char** argv, int argc);
BOOL PRIVATE OnGameCommandFBR(char** argv, int argc);

CLIENTINFO
(		
	0,1,
	"oracle",
	"www.b3gn.com/",
	"Char Info",
	"b3gn_oracle@hotmail.com"
)

MODULECOMMANDSTRUCT ModuleCommands[]=
{
	{
		"help",
		OnGameCommandHelp,
		"helpÿc0 List commands available in this module.\n"
		"<command> helpÿc0 Shows detailed help for <command> in this module."
	},
	{
		"fhr", OnGameCommandFHR,
		"hostile ÿc0Show your Fast Hit Recovery in game."
	},
	{
		"fcr", OnGameCommandFCR,
		"hp ÿc0Show your Fast Cast Rate in game."
	},
	{
		"fbr", OnGameCommandFBR,
		"mana ÿc0Show your Fast Block Rate in game."
	},
	{NULL}	// No more commands
};

BOOL EXPORT OnClientStart()
{
	return TRUE;
}

BOOL EXPORT OnClientStop()
{	
	return TRUE;
}

DWORD EXPORT OnQueryModuleData(DWORD dwDataID, LPVOID lpBuffer, DWORD dwMaxLength, LPARAM lParam)
{
	return 0;
}


BOOL PRIVATE OnGameCommandFHR(char** argv, int argc)
{
	DWORD classId = 0;
	classId = me->GetClassID();
	server->GameErrorf("-----------------------------------------------------");
	switch(classId)
	{
	case 0: { // Amazon
		server->GameInfof("ÿc1Frame         FHR");
		server->GameInfof("3         600");
		server->GameInfof("4         174");
		server->GameInfof("5         86");
		server->GameInfof("6         52");
		server->GameInfof("7         32");
		server->GameInfof("8         20");
		server->GameInfof("9         13");
		server->GameInfof("10        6");
		server->GameInfof("11        0");
		server->GameInfof(" ");
		break;}
	case 1: { // Sorceress
		server->GameInfof("ÿc1Frame         FHR");
		server->GameInfof("4         1480");
		server->GameInfof("5         280");
		server->GameInfof("6         142");
		server->GameInfof("7         86");
		server->GameInfof("8         60");
		server->GameInfof("9         42");
		server->GameInfof("10        30");
		server->GameInfof("11        20");
		server->GameInfof("12        14");
		server->GameInfof("13        9");
		server->GameInfof("14        5");
		server->GameInfof("15        0");
		server->GameInfof(" ");
		break;}
	case 2:
	case 5: { // Necromancer & Druid
		server->GameInfof("ÿc1Frame         FHR");
		server->GameInfof("4          377");
		server->GameInfof("5          152");
		server->GameInfof("6          86");
		server->GameInfof("7          56");
		server->GameInfof("8          39");
		server->GameInfof("9          26");
		server->GameInfof("10         16");
		server->GameInfof("11         10");
		server->GameInfof("12         5");
		server->GameInfof("13         0");
		server->GameInfof(" ");
		break;}
	case 3:
	case 4:
	case 6:{ // Barbarian & Assassin & Paladin
		server->GameInfof("ÿc1Frame         FHR");
		server->GameInfof("2          4680");
		server->GameInfof("3          200");
		server->GameInfof("4          86");
		server->GameInfof("5          48");
		server->GameInfof("6          27");
		server->GameInfof("7          15");
		server->GameInfof("8          7");
		server->GameInfof("9          0");
		server->GameInfof(" ");
		break;}


	}
	server->GameErrorf("ÿc2Your FHR: ÿc1%d", me->GetStat(STAT_FASTERHITRECOVERY));
	server->GameErrorf("-----------------------------------------------------");
	server->GameErrorf(" ");
	return TRUE;
}

BOOL PRIVATE OnGameCommandFBR(char** argv, int argc)
{
	DWORD classId = 0;
	classId = me->GetClassID();
	server->GameErrorf("-----------------------------------------------------");
	switch(classId)
	{
	case 0:
	case 3:
	case 6: { // Amazon & Paladin & Assassin
		server->GameInfof("ÿc1Frame         FBR");
		server->GameInfof("1         600");
		server->GameInfof("2         86");
		server->GameInfof("3         32");
		server->GameInfof("4         13");
		server->GameInfof("5         0");
		server->GameInfof(" ");
		break;}
	case 1: { // Sorceress
		server->GameInfof("ÿc1Frame         FBR");
		server->GameInfof("2         4680");
		server->GameInfof("3         200");
		server->GameInfof("4         86");
		server->GameInfof("5         48");
		server->GameInfof("6         27");
		server->GameInfof("7         15");
		server->GameInfof("8         7");
		server->GameInfof("9         0");
		server->GameInfof(" ");
		break;}

	case 4: { // Barbarian
		server->GameInfof("ÿc1Frame         FBR");
		server->GameInfof("2         280");
		server->GameInfof("3         86");
		server->GameInfof("4         42");
		server->GameInfof("5         20");
		server->GameInfof("6         9");
		server->GameInfof("7         0");
		server->GameInfof(" ");
		break;}
	case 2:
	case 5: { // Necromancer & Druid
		server->GameInfof("ÿc1Frame         FBR");
		server->GameInfof("3          600");
		server->GameInfof("4          174");
		server->GameInfof("5          86");
		server->GameInfof("6          52");
		server->GameInfof("7          32");
		server->GameInfof("8          20");
		server->GameInfof("9          13");
		server->GameInfof("10         6");
		server->GameInfof("11         0");
		server->GameInfof(" ");
		break;}


	}
	server->GameErrorf("ÿc2Your FBR: ÿc1%d", me->GetStat(STAT_FASTERBLOCK));
	server->GameErrorf("-----------------------------------------------------");
	server->GameErrorf(" ");
	return TRUE;
}

BOOL PRIVATE OnGameCommandFCR(char** argv, int argc)
{
	DWORD classId = 0;
	classId = me->GetClassID();
	server->GameErrorf("-----------------------------------------------------");
	switch(classId)
	{
	case 0: { // Amazon
		server->GameInfof("ÿc1Frame         FCR");
		server->GameInfof("11         152");
		server->GameInfof("12         99");
		server->GameInfof("13         68");
		server->GameInfof("14         48");
		server->GameInfof("15         32");
		server->GameInfof("16         22");
		server->GameInfof("17         14");
		server->GameInfof("18         7");
		server->GameInfof("19         0");
		server->GameInfof(" ");
		break;}
	case 1:
	case 4: { // Sorceress & Barbarian
		server->GameInfof("ÿc1Frame         FCR");
		server->GameInfof("7          200");
		server->GameInfof("8          105");
		server->GameInfof("9          63");
		server->GameInfof("10         37");
		server->GameInfof("11         20");
		server->GameInfof("12         9");
		server->GameInfof("13         0");
		server->GameInfof(" ");
		break;}
	case 2:
	case 3: { // Necromancer & Paladin
		server->GameInfof("ÿc1Frame    FCR");
		server->GameInfof("8          125");
		server->GameInfof("9          75");
		server->GameInfof("10         48");
		server->GameInfof("11         30");
		server->GameInfof("12         18");
		server->GameInfof("13         9");
		server->GameInfof("14         0");
		server->GameInfof(" ");
		break;}
	case 5: { // Druid
		server->GameInfof("ÿc1Frame    FCR");
		server->GameInfof("9          292");
		server->GameInfof("10         163");
		server->GameInfof("11         99");
		server->GameInfof("12         68");
		server->GameInfof("13         45");
		server->GameInfof("14         30");
		server->GameInfof("15         19");
		server->GameInfof("16         10");
		server->GameInfof("17         4");
		server->GameInfof("18         0");
		server->GameInfof(" ");
		break;}
	case 6: { // Assassin
		server->GameInfof("ÿc1Frame    FCR");
		server->GameInfof("9          174");
		server->GameInfof("10         102");
		server->GameInfof("11         65");
		server->GameInfof("12         42");
		server->GameInfof("13         27");
		server->GameInfof("14         16");
		server->GameInfof("15         8");
		server->GameInfof("16         0");
		server->GameInfof(" ");
		break;}


	}
	server->GameErrorf("ÿc2Your FCR: ÿc1%d", me->GetStat(STAT_FASTERCAST));
	server->GameErrorf("-----------------------------------------------------");
	server->GameErrorf(" ");
	return TRUE;
}

