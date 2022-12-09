What Is This?

This mod adds artillery strike signal grenades to the loot economy.

The grenades act as smoke grenades, but shortly after pulling the pin you will hear a distant artillery barage like when a regular artillery strike occurs.

A few seconds later several bombs will drop around the smoke grenade. The bombs can be configured by the server owner to make them more or less lethal to players and infected.

Default Configuration:
Player_Kill = false; // Does bomb contact insta-kill players?
Player_BreakLegs = true; // Does bomb contact break legs?
Player_CauseBleeds = true; // Does bomb contact cause bleeds?
Player_ExtraDamage = 0; // Don't set this higher than 0.5 or it's basically certain death and you might as well turn Player_Kill=true
SafeUnderRoof = true; // Is player & DamageObjects/Car safe from bombs while under a roof? (Doesn't apply to zombies)
Zombie_Kill = true; // Does bomb contact kill zombies?
Animal_Kill = true; // Does bomb contact kill animals?
MinStrikeSecs = 10; // Minimum delay before playing artillery sound
MaxStrikeSecs = 20; // Max delay before playing artillery sound
MinBombSecs = 15; // Min delay AFTER playing artillery sound for bombs to drop
MaxBombSecs = 30; // Max delay AFTER playing artillery sound for bombs to drop
MinBombs = 9; // Min bombs to drop
MaxBombs = 12; // Max bombs to drop
BombDropRadius = 30; // Bomb radius from smoke grenade position - bombs are dropped within this radius (meters)
BombDamageRadius = 30; // Bomb damage radius from explosions - any objects within this distance are affected by below settings (meters)
ChemStrikeDoesDamage = true; // If disabled then chemical artillery strikes don't damage objects/cars, they only drop gas and affect players & zeds
CarMinDamage = 100; // If a car is bombed, this defines how much damage to apply to a randomly selected car part from the below list
CarMaxDamage = 250; // If a car is bombed, this defines how much damage to apply to a randomly selected car part from the below list
DamageCarParts = List // This array defines a list of car parts that can be damaged (can be attachment slot name, attachment classname, or vehicle damage zone)
DamageObjects = List // This array defines any other ingame objects that are to be affected by bombs (eg. tents, storage items, whatever you like)

Installation Instructions:

Install this mod like any other mod - copy it into your server's root directory, add it to your launch parameters, and make sure to copy the .bikey into your server keys.

Don't forget to add the types.xml entries and modify your quantities & spawn locations according to your preference.

This mod must be installed on both the server & client.

Repack & Source Code:

You can repack this mod if you like, and do anything else you want with it for that matter. The source code is on my GitHub at www.zenarchist.io

Enjoy!