modded class MissionServer
{
	// Called when server initializes
	override void OnInit()
	{
		super.OnInit();
		Print("[ZenArtilleryStrike] OnInit");

		// Load config
		GetZenArtilleryConfig();
	}
};