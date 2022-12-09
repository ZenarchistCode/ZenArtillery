modded class PlayerBase
{
	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (ammo.Contains("Zen_ArtilleryBomb_Ammo") && GetGame().IsDedicatedServer())
		{
			// If player is safe under roof, check for it
			if (GetZenArtilleryConfig().SafeUnderRoof)
			{
				if (PosIsUnderRoof(GetPosition()) && IsSoundInsideBuilding())
					return; // Player is safe - don't apply any damage for artillery strike.
			}

			// Break player legs if enabled in config
			if (GetZenArtilleryConfig().Player_BreakLegs)
			{
				if (Math.RandomIntInclusive(1, 2) == 1)
				{
					SetHealth("RightLeg", "", 0);
				}
				else
				{
					SetHealth("LeftLeg", "", 0);
				}
			}

			// Make player bleed if enabled in config
			if (GetZenArtilleryConfig().Player_CauseBleeds)
			{
				bool sendInjuredSound = false;

				if (GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightFoot"))
				{
					sendInjuredSound = true;
				}

				if (!sendInjuredSound && GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArm"))
				{
					sendInjuredSound = true;
				}

				// Send injured sound if player is injured
				if (sendInjuredSound)
				{
					SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
				}
			}

			// If it should kill players, kill them
			if (GetZenArtilleryConfig().Player_Kill)
			{
				SetHealth(0);
			}
			else
			{
				// Deal damage if specified in config
				if (GetZenArtilleryConfig().Player_ExtraDamage > 0)
				{
					SetHealth(GetHealth() - GetZenArtilleryConfig().Player_ExtraDamage);
				}
			}
		}

		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}

	// Check if given position is under a roof/hard object
	static bool PosIsUnderRoof(vector position)
	{
		float hitFraction;
		vector hitPosition, hitNormal;
		vector from = position;
		vector to = from + "0 25 0"; // Check for roof 25m above player
		Object hitObject;
		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.ITEM_LARGE | PhxInteractionLayers.BUILDING | PhxInteractionLayers.VEHICLE;
		return DayZPhysics.RayCastBullet(from, to, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
	}
}