//=========================================================
// Base Weapon to create macro'd weapons with
//=========================================================
#ifndef _WEAPON_GGSBASE_HPP
#define _WEAPON_GGSBASE_HPP

#include "cbase.h"
#include "npcevent.h"
#include "in_buttons.h"

#ifdef CLIENT_DLL
#include "c_hl2mp_player.h"
#else
#include "hl2mp_player.h"
#endif

#include "weapon_hl2mpbasehlmpcombatweapon.h"

//modify this to alter the rate of fire
//#define ROF 0.075f //RPS, 60 Sec / 800 Rounds = 0.075f

//The gun will fire up to this number of bullets while you hold the fire button. 
//If you set it to 1 the gun will be semi auto. If you set it to 3 the gun will fire three round bursts
//#define BURST 500

#ifdef CLIENT_DLL
#define CWeaponGGSBase C_WeaponGGSBase
#endif

//-----------------------------------------------------------------------------
// CWeaponGGSBase
//-----------------------------------------------------------------------------

class CWeaponGGSBase : public CBaseHL2MPCombatWeapon
{
public:

	DECLARE_CLASS(CWeaponGGSBase, CBaseHL2MPCombatWeapon);
	CWeaponGGSBase(void);
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	void Precache(void);
	void ItemPostFrame(void);
	void ItemPreFrame(void);
	void ItemBusyFrame(void);
	void PrimaryAttack(void);
	void AddViewKick(void);
	void DryFire(void);
	void GetStance(void);
	bool Holster(CBaseCombatWeapon *pSwitchingTo = NULL); // Required so that you un-zoom when switching weapons
	Activity GetPrimaryAttackActivity(void);

	virtual bool Reload(void);

	int GetMinBurst() { return 2; }
	int GetMaxBurst() { return 5; }
	float GetFireRate(void) { return ROF; }

	//modify this part to control the general accuracy of the gun

	virtual const Vector& GetBulletSpread(void);

	void ToggleZoom(void);
	void CheckZoomToggle(void);

	DECLARE_ACTTABLE();

private:
	int BURST;
	float ROF;

	//Hackey, fix asap
	bool first;

	CNetworkVar(int, m_iBurstCurr);
	CNetworkVar(bool, m_bInZoom);
	CNetworkVar(float, m_flAttackEnds);
	CNetworkVar(int, m_iStance);

private:
	CWeaponGGSBase(const CWeaponGGSBase &);
};

#endif