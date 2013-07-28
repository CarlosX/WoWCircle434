#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#define DMScriptName "instance_deadmines"

enum CannonState
{
    CANNON_NOT_USED,
    CANNON_BLAST_INITIATED,
    PIRATES_ATTACK,
    EVENT_DONE
};

enum NPCs
{
    NPC_GLUBTOK       = 47162,
    NPC_HELIX         = 47296,
    NPC_OAF           = 47297,
    NPC_FOEREAPER     = 43778,
    NPC_ADMIRAL       = 47626,
    NPC_CAPTAIN       = 47739,
    NPC_VANESSA       = 49541,
    NPC_NOTE          = 49564,
    // horde npc
    NPC_KAGTHA        = 46889,
    NPC_SLINKY        = 46906,
    NPC_MISS_MAYHEM   = 46902,
    NPC_REAPER_PR     = 46903,
    NPC_HAND_ASSASIN  = 46890,
    // alliance npc
    NPC_HORATIO_LAINE = 46612,
    NPC_INVESTIGATOR  = 46614,
    NPC_DEFENDER      = 50595,
    NPC_CRIME_SCENE   = 46613,
};

enum Data
{
    DATA_GLUBTOK          = 1,
    DATA_HELIX            = 2,
    DATA_FOEREAPER        = 3,
    DATA_ADMIRAL          = 4,
    DATA_CAPTAIN          = 5,
    DATA_VANESSA          = 6,
    DATA_CANNON_EVENT     = 7,
    DATA_OAF              = 8,
    DATA_TEAM_IN_INSTANCE = 9,
};

enum GameObjects
{
    GO_FOUNDRY_DOOR   = 16399,
    GO_FACTORY_DOOR   = 13965,
    GO_MAST_ROOM_DOOR = 16400,
    GO_IRONCLAD_DOOR  = 16397,
    GO_DEFIAS_CANNON  = 16398,
    GO_DOOR_LEVER     = 101833,
};

enum Sounds
{
    SOUND_CANNONFIRE  = 1400,
    SOUND_DESTROYDOOR = 3079,
};

const Position centershipPos = {-63.167f, -819.315f, 41.27f, 6.25f};

#endif