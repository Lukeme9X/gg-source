#include "cbase.h"
#include "weapon_parse.h"
#include "KeyValues.h"

class GGSWeaponParse : public FileWeaponInfo_t
{
public:
	DECLARE_CLASS_GAMEROOT(GGSWeaponParse, FileWeaponInfo_t);

	void Parse(::KeyValues* pKeyValuesData, const char* szWeaponName)
	{
		BaseClass::Parse(pKeyValuesData, szWeaponName);

		m_flCycleTime = pKeyValuesData->GetFloat("CycleTime", 0.15f);
		m_iBullets = pKeyValuesData->GetInt("Bullets", 1);
		m_iBurst = pKeyValuesData->GetInt("Burst", 500);
	}

	//float m_flCycleTime;
	//int	m_iBullets;
	//int m_iBurst;
};

// This function probably exists somewhere in your mod already.
FileWeaponInfo_t* CreateWeaponInfo()
{
	return new GGSWeaponParse;
}