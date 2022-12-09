// TODO: Make a signal flare version for striking targets far away?
class CfgPatches
{
	class ZenArtillery
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = { "DZ_Data" };
		units[] = {};
	};
};

class CfgMods
{
	class ZenArtillery
	{
		dir="ZenArtillery";
		picture=""; 
		action="";
		hideName=1;
		hidePicture=1;
		name="ZenArtillery";
		credits=""; 
		author="";
		authorID="0";  
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission" 
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[] =
				{
					"ZenArtillery/scripts/3_game";
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"ZenArtillery/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				value="";
				files[] =
				{
					"ZenArtillery/scripts/5_mission"
				};
			};
		}
	};
};

class CfgVehicles
{
	// Define grenades
	class M18SmokeGrenade_Red;
	class Zen_ArtillerySmokeGrenade : M18SmokeGrenade_Red
	{
		scope = 2;
		displayName = "$STR_ZENARTILLERYGRENADE0";
		descriptionShort = "$STR_ZENARTILLERYGRENADE1";
		weight = 250;
		hiddenSelectionsTextures[] =
		{
			"ZenArtillery\data\artillerystrikegrenade_red_co.paa"
		};
		class EnergyManager
		{
			energyAtSpawn = 180; // 3 mins lifetime
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
			updateInterval = 5;
		};
	};
	class M18SmokeGrenade_Green;
	class Zen_ArtillerySmokeGrenadeChem : M18SmokeGrenade_Green
	{
		scope = 2;
		displayName = "$STR_ZENARTILLERYCHEMGRENADE0";
		descriptionShort = "$STR_ZENARTILLERYCHEMGRENADE1";
		weight = 250;
		hiddenSelectionsTextures[] =
		{
			"ZenArtillery\data\artillerystrikegrenade_green_co.paa"
		};
		class EnergyManager
		{
			energyAtSpawn = 180; // 3 mins lifetime
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
			updateInterval = 5;
		};
	};

	// Define bomb
	class Grenade_Base;
	class Zen_ArtilleryBomb : Grenade_Base
	{
		scope = 2;
		displayName = "ZenBangBang";
		model = "DZ\weapons\explosives\grenade.p3d";
		itemSize[] = { 1,1 };
		weight = 5000;
		forceFarBubble = "true";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "dz\weapons\explosives\data\grenade_co.paa" };
		hiddenSelectionsMaterials[] = { "dz\weapons\explosives\data\grenade.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1;
					healthLevels[] = { {1,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.7,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.5,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0,{"DZ\weapons\explosives\data\grenade_destruct.rvmat"}} };
				};
			};
		};
	};
}

class CfgAmmo
{
	class DefaultAmmo;
	class Zen_ArtilleryBomb_Ammo : DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 15;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;

		soundSetExplosion[] =
		{
			"Landmine_Explosion_SoundSet",
			"Plastic_Explosion_SoundSet",
			"Landmine_Explosion_Tail_SoundSet",
			"Plastic_Explosion_Tail_SoundSet"
		};

		class DamageApplied
		{
			type = "FragGrenade";
			class Health
			{
				damage = 1;
			};
			class Blood
			{
				damage = 1;
			};
			class Shock
			{
				damage = 33;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
}