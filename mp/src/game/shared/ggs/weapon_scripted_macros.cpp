#include "cbase.h"
#include "npcevent.h"

#ifdef CLIENT_DLL
#include "c_hl2mp_player.h"
#include "c_te_effect_dispatch.h"
#else
#include "hl2mp_player.h"
#include "te_effect_dispatch.h"
#include "prop_combine_ball.h"
#endif

#include "basegrenade_shared.h"
#include "weapon_hl2mpbase_machinegun.h"

#include "../hl2mp/weapon_ar2.h"
#include "effect_dispatch_data.h"


// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

//=========================================================
//							AR3
//=========================================================
#ifdef CLIENT_DLL
#define CWeaponAR3 C_WeaponAR3
#endif

class CWeaponAR3 : public CWeaponAR2
{
public:
	DECLARE_CLASS(CWeaponAR3, CHL2MPMachineGun);

	CWeaponAR3() : CWeaponAR2() {};

	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

private:
	CWeaponAR3( const CWeaponAR3 & );

protected:
#ifndef CLIENT_DLL
	DECLARE_ACTTABLE();
#endif
};

IMPLEMENT_NETWORKCLASS_ALIASED(WeaponAR3, DT_WeaponAR3)

BEGIN_NETWORK_TABLE(CWeaponAR3, DT_WeaponAR3)
END_NETWORK_TABLE()

BEGIN_PREDICTION_DATA(CWeaponAR3)
END_PREDICTION_DATA()

LINK_ENTITY_TO_CLASS(weapon_ar3, CWeaponAR3);
PRECACHE_WEAPON_REGISTER(weapon_ar3);

#ifndef CLIENT_DLL

acttable_t	CWeaponAR3::m_acttable[] =
{
	{ ACT_HL2MP_IDLE, ACT_HL2MP_IDLE_AR2, false },
	{ ACT_HL2MP_RUN, ACT_HL2MP_RUN_AR2, false },
	{ ACT_HL2MP_IDLE_CROUCH, ACT_HL2MP_IDLE_CROUCH_AR2, false },
	{ ACT_HL2MP_WALK_CROUCH, ACT_HL2MP_WALK_CROUCH_AR2, false },
	{ ACT_HL2MP_GESTURE_RANGE_ATTACK, ACT_HL2MP_GESTURE_RANGE_ATTACK_AR2, false },
	{ ACT_HL2MP_GESTURE_RELOAD, ACT_HL2MP_GESTURE_RELOAD_AR2, false },
	{ ACT_HL2MP_JUMP, ACT_HL2MP_JUMP_AR2, false },
	{ ACT_RANGE_ATTACK1, ACT_RANGE_ATTACK_AR2, false },
};

IMPLEMENT_ACTTABLE(CWeaponAR3);

//=========================================================
//							End AR3
//=========================================================

#endif