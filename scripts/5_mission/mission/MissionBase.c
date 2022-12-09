modded class MissionBase extends MissionBaseWorld
{
	private ref EffectSound m_ZenArtySound;

	void MissionBase()
	{
		if (!GetGame().IsDedicatedServer()) // Register server->client RPCs
		{
			GetRPCManager().AddRPC("ZAS_RPC", "RPC_ZAS_ReceiveAirstrikeData", this, SingeplayerExecutionType.Server);
		}
	}

	// SERVER->CLIENT RPCS /////////////////////////////////////////////////////////////////////////////
	void RPC_ZAS_ReceiveAirstrikeData(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		if (type == CallType.Client && GetGame().IsDedicatedServer() == false)
		{
			Param1< vector > data;
			if (!ctx.Read(data))
			{
				Print("[ZenArtillery] RPC_ZAS_ReceiveAirstrikeData: sync data read error");
				return;
			}

			vector soundPosition = data.param1;

			if (soundPosition)
			{
				m_ZenArtySound = SEffectManager.PlaySound("Artillery_Distant_Barrage_SoundSet", soundPosition, 0.1, 0.1);
				m_ZenArtySound.SetAutodestroy(true);
			}
		}
	}
};