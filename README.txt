Unreal Challenge 1: Anno 1800 Production

Name: Alain Royce Creencia Section: X22
GitHub Link: https://github.com/alainroyce/Creencia_UEChal1.git

Main Level name: Anno
C++ Classes
1. Cart (Actor) - Attached to the CartTransport Blueprint. Used for loading in Coal Mine and Iron Mine and unloading for SteelBeam Furnace.
2. Cart2 (Actor) - Attached to the CartTransport2 Blueprint. Used for loading in Lumberjack and SteelBeam Furnace and unloading for Sewing Machine Factory
3. CoalMine (Actor Component)- Attached to the CoalMineBlueprint. Used for the Production of Coal.
4. IronMine (Actor Component) - Attached to the IronMineBlueprint. Used for the Production of Iron.
5. SteelBeamFurnace (Actor Component) - Attached to the SteelBeamFurnaceBlueprint. Used for the Production of Steel.
6. SewingMachine (Actor Component) - Attached to the SewingMachineFactoryBlueprint. Used for the Production of Sewing Machine.
7. Lumberjack (Actor Component) - Attached to the LumberjackBlueprint. Used for the Production of Lumbers.

Instructions:
1. Place the 7 Blueprints in the map. (CartTransport, CartTransport2, CoalMineBlueprint, IronMineBlueprint, SteelBeamFurnaceBlueprint, SewingMachineFactoryBlueprint,
 LumberjackBlueprint).
2. Attach the designated scripts for the blueprints for the following: (Parent Class)
Cart = CartTransport
Cart2 = CartTransport2
CoalMine = CoalMineBlueprint
IronMine = IronMineBlueprint
SteelBeamFurnace = SteelBeamFurnaceBlueprint
SewingMachine = SewingMachineFactoryBlueprint
Lumberjack = LumberjackBlueprint

3. After attaching all the scripts and placing all the blueprints, You can now run the game. 

4. There are modifiable variables in the details of each blueprint.

5. The camera is the default camera of Unreal Engine. Thus, you can travel in the world.