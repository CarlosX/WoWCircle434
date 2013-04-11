#include "ScriptPCH.h"
#include "firelands.h"

enum ScriptTexts
{
    SAY_AGGRO       = 0,
    SAY_DEATH       = 1,
    SAY_KILL        = 2,
    SAY_SKIES       = 3,
    SAY_BURN        = 4,
    SAY_BURN_OUT    = 5,
};
// emote 337598
enum Spells
{
    SPELL_FIRESTORM             = 99605,  // on start 
    SPELL_FIRESTORM_H           = 100744, // in heroic mode instead of molting
    SPELL_BLAZING_CLAW          = 99843,  // while molting or after third phase
    SPELL_FIERY_VORTEX          = 99793,  // big vortex in center of room
    SPELL_HARSH_WINDS           = 100640, // damage all enemies that further that 60m from fiery votrex
    SPELL_FIERY_TORNADO         = 99817,  // tornados
    SPELL_MOLTING_1             = 99464,  // 1 sec periodic
    SPELL_MOLTING_2             = 99504,  // 200 ms periodic, after burn out
    SPELL_MOLTEN_FEATHER_BAR    = 101410, // unit power bar for feathers
    SPELL_MOLTEN_FEATHER_DUMMY  = 99507,  // visual?
    SPELL_MOLTEN_FEATHER_DK     = 99771,
    SPELL_MOLTEN_FEATHER_SHAM   = 98770,
    SPELL_MOLTEN_FEATHER_PAL    = 98769,
    SPELL_MOLTEN_FEATHER_HUN    = 98768,
    SPELL_MOLTEN_FEATHER_ROG    = 98767,
    SPELL_MOLTEN_FEATHER_DRU    = 98766,
    SPELL_MOLTEN_FEATHER_PRI    = 98765,
    SPELL_MOLTEN_FEATHER_WARL   = 98764,
    SPELL_MOLTEN_FEATHER_WARR   = 98762,
    SPELL_MOLTEN_FEATHER_MAG    = 98761,
    SPELL_MOLTEN_FEATHER_SCRIPT = 98734, // triggered by molten feather, apply buff (above)
    SPELL_MOLTEN_FEATHER        = 97128, // general buff from molten feather
    SPELL_WINGS_OF_FLAME        = 98624, //
    SPELL_WINGS_OF_FLAME_AURA   = 98619,
    SPELL_BLAZING_POWER_SUM     = 99528,
    SPELL_BLAZING_POWER         = 99462,
    SPELL_BLAZING_POWER_AURA    = 99461,
    SPELL_ALYSRAS_RAZOR         = 100029,
    SPELL_ALYSRAS_RAZOR_DUMMY   = 100038,
    SPELL_INCINDIARY_CLOUD_SUM  = 99529,
    SPELL_INCINDIARY_CLOUD      = 99426,
    SPELL_BURNOUT               = 99432,
    SPELL_BURNOUT_1             = 100399,
    SPELL_BURNOUT_2             = 100412,
    SPELL_SPARK                 = 99921,
    SPELL_IGNITED               = 99922,
    SPELL_FULL_POWER            = 99925,

    // Blazing Talon Initiate
    SPELL_BRASHFIRE             = 98868,
    SPELL_BRASHFIRE_AURA        = 98884,
    SPELL_FIEROBLAST            = 101223,
    SPELL_FIRE_IT_UP            = 100093,
    SPELL_BLAZING_SHIELD        = 101484,

    // Voracious Hatchling
    SPELL_IMPRINTED             = 99389,
    SPELL_IMPRINTED_TAUNT       = 99390,
    SPELL_SETIATED              = 99359,
    SPELL_HUNGRY                = 99361,
    SPELL_TANTRUM               = 99362,
    SPELL_GUSHING_WOUND         = 99308,

    // Molten Egg
    SPELL_EGG_EXPLOSION         = 99943,
    SPELL_SUMMON_HATCHLING      = 99723,

    // Plumb Lava Worm
    SPELL_LAVA_SPEW             = 99335,

    // Blazing Talon Clawshaper
    SPELL_IGNITION              = 99919,

    // Herald of the Burning End
    SPELL_RITUAL_OF_THE_FLAME   = 99199,
    SPELL_CATACLYSM_1           = 102111,
    SPELL_CATACLYSM_2           = 100761,

    // Molten Meteor
    SPELL_METEORIC_IMPACT       = 99558,
    SPELL_MOLTEN_METEOR_AURA_1  = 99215,
    SPELL_MOLTEN_METEOR_MISSILE = 99553,
    SPELL_MOLTEN_METEOR_SUMMON  = 99554,
    SPELL_MOLTEN_METEOR_DEATH   = 100055,
    SPELL_MOLTER_METEOR_AURA_2  = 100059,

    // Misc
    SPELL_ZERO_POWER            = 99905,
    SPELL_FIREHAWK_SMOKE        = 100712,
    SPELL_BROODMOTHER_COSMETIC  = 99734,
    SPELL_FIREHAWK_TRANSFORM_M  = 99550,
    SPELL_FIREHAWK_TRANSFORM_F  = 100350,
    SPELL_FIREHAWK_CLAWSHAPPER  = 99923,
    SPELL_FIREHAWK_REMOVE_FORM  = 99924,
};

enum Adds
{
    NPC_VOLCANO_FIRE_BUNNY          = 53158, // 98462 aura
    NPC_FIRESTORM                   = 53986,
    NPC_MOLTING_FEATHER             = 53089,
    NPC_BLAZING_TALON_INITIATE      = 53896,
    NPC_BLAZING_POWER               = 53554,
    NPC_INCINDIARY_CLOUD            = 53541,
    NPC_PLUMP_LAVA_WORM             = 53520,
    NPC_HERALD_OF_THE_BURNING_END   = 53375,
    NPC_BLAZING_TALON_CLAWSHAPER    = 53734,
    NPC_FIERY_VORTEX                = 53693,
    NPC_FIERY_TORNADO               = 53698,
    NPC_BRUSHFIRE                   = 53372,
    NPC_VORACIOUS_HATCHLING         = 53898,
    NPC_MOLTEN_EGG                  = 53681,
    NPC_MOLTEN_METEOR_1             = 53489,
    NPC_MOLTEN_METEOR_2             = 53784, // 100059 (after death)
    NPC_METEOR_CALLER               = 53487, // 99564
    NPC_BLAZING_BROODMOTHER_1       = 53900,
    NPC_BLAZING_BROODMOTHER_2       = 53680,

    NPC_CAPTIVE_DRUID_OF_THE_TALON  = 54019, // spawnmask 0
    NPC_FANDRAL                     = 54015, // spawnmask 0
};

enum Events
{
    EVENT_BERSERK           = 1,
    EVENT_INCINDIARY_CLOUD  = 2,
    EVENT_BLAZING_POWER     = 3,
    EVENT_ROTATE            = 4,
    EVENT_FLIGHT            = 5,
    EVENT_IGNITION          = 6,
    EVENT_BURN              = 7,
    EVENT_HARSH_WIND        = 8, 
    EVENT_CLAWSHAPER        = 9,
    EVENT_INITIATE          = 10,
    EVENT_EGGS              = 11,
    EVENT_BROODMOTHER       = 12,
    EVENT_MOVE_TORNADO      = 13,
    EVENT_START_COMBAT      = 14,
    EVENT_CHECK_ENERGY      = 15,
    EVENT_FIEROBLAST        = 16,
    EVENT_BRASHFIRE         = 17,
    EVENT_FLY_OUT           = 18,
    EVENT_EGG_EXPLOSION     = 19,
    EVENT_SUMMON_HATCHLING  = 20,
    EVENT_REMOVE_WINGS      = 21,
    EVENT_GUSHING_WOUND     = 22,
    EVENT_HUNGRY            = 23,
    EVENT_EAT_WORM          = 24,
    EVENT_SUMMON_WORMS      = 25,
    EVENT_HERALD            = 26,
    EVENT_CATACLYSM         = 27,
};

enum Misc
{
    POINT_TORNADO       = 1,
    POINT_CLAWSHAPER_1  = 2,
    POINT_CLAWSHAPER_2  = 3,
    POINT_INITIATE_1    = 4,
    POINT_BROODMOTHER_1 = 5,
    POINT_BROODMOTHER_2 = 6,
    POINT_METEOR        = 7,
};

const Position volcanofirePos[11] =
{
    {5.375f, -336.376f, 51.629f, 2.304f},
    {9.478f, -331.562f, 51.387f, 2.304f},
    {16.252f, -323.355f, 51.448f, 2.304f},
    {19.871f, -320.852f, 51.960f, 2.304f},
    {22.058f, -315.533f, 51.959f, 2.304f},
    {28.059f, -307.899f, 51.958f, 2.304f},
    {32.530f, -300.595f, 51.965f, 2.304f},

    {-103.034f, -294.838f, 56.158f, 2.304f},
    {-103.872f, -286.840f, 56.507f, 2.304f},
    {-103.593f, -280.863f, 56.531f, 2.304f},
    {-104.593f, -274.393f, 56.534f, 2.304f},
};

const Position flyPos[13] = 
{
    {9.61f, -310.33f, 132.0f, 4.2f},
    {9.61f, -310.33f, 61.6f, 2.96f},
    {-81.54f, -284.82f, 61.0f, 3.12f},
    {-81.54f, -284.82f, 132.0f, 3.12f},
    {-61.69f, -216.61f, 132.0f, 0.1f},
    {18.92f, -230.78f, 132.0f, 5.43f},
    {9.61f, -310.33f, 132.0f, 4.2f},
    {-47.56f, -352.11f, 132.0f, 2.68f},
    {-90.88f, -318.46f, 132.0f, 2.08f},
    {-81.54f, -284.82f, 132.0f, 3.12f},
    {-61.69f, -216.61f, 132.0f, 0.1f},
    {18.92f, -230.78f, 132.0f, 5.43f},
    {9.61f, -310.33f, 132.0f, 4.2f}
};

const Position centerPos = {-42.06f, -276.10f, 52.3f, 3.22f};  // center

Position const initiatePos[8] =
{
    {11.34f, -239.26f, 73.21f, 3.8f},
    {-39.70f, -351.33f, 69.51f, 1.67f},
    {-86.34f, -330.48f, 71.04f, 0.89f},
    {-90.80f, -237.90f, 73.95f, 5.72f},

    {-17.45f, -260.86f, 50.0f, 3.7f},
    {-38.51f, -320.45f, 52.0f, 1.67f},
    {-67.34f, -304.72f, 51.0f,  0.94f},
    {-71.76f, -256.38f, 53.0f, 5.72f}
};

Position const wormPos[4] = 
{
	{-24.179f, -311.185f, 56.000f, 1.0f},
	{-75.952f, -296.170f, 58.000f, 4.0f},
	{-71.017f, -255.195f, 58.000f, 0.2f},
	{-17.180f, -257.636f, 56.000f, 2.0f},
};

const Position broodmotherPos[6] =
{
    {46.930f, -207.560f, 105.000f, 3.951f}, // left summon
    {-28.813f, -378.088f, 107.371f, 1.697f}, // right summon

    {-32.901f, -272.019f, 105.0f, 0.0f}, //left egg pos z+5
    {46.930f, -207.560f, 90.000f, 0.0f}, //right egg pos z+5
    
    {-44.463f, -285.802f, 105.0f, 0.0f}, //left bird point to despawn
    {-28.813f, -378.088f, 90.371f, 0.0f} //right bird point to despawn
};

const Position meteorPos[8] = 
{
    {11.45f, -278.35f, 53.f, 0.0f},
    {11.41f, -230.67f, 58.f, 0.0f},
    {-32.60f, -217.37f, 57.f, 0.0f},
    {-72.04f, -231.57f, 56.5f, 0.0f},
    {-82.40f, -321.66f, 58.5f, 0.0f},
    {-63.90f, -332.92f, 56.5f, 0.0f},
    {-35.87f, -337.06f, 54.f, 0.0f}
};

class boss_alysrazor : public CreatureScript
{
    public:
        boss_alysrazor() : CreatureScript("boss_alysrazor") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_alysrazorAI(pCreature);
        }

        struct boss_alysrazorAI : public BossAI
        {
            boss_alysrazorAI(Creature* pCreature) : BossAI(pCreature, DATA_ALYSRAZOR)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->setActive(true);
                me->SetSpeed(MOVE_RUN, 1.0f, true);
                me->SetSpeed(MOVE_FLIGHT, 2.0f, true);
            }

            int8 phase;
            uint8 circle;
            uint8 curPoint;

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != sObjectMgr->GetScriptId(FLScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            { 
                _Reset();
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_PASSIVE);
                curPoint = 0;
                phase = 0;
                circle = 0;
                me->SetMaxPower(POWER_MANA, 100);
                me->SetPower(POWER_MANA, 100);
                RemoveEncounterAuras();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode()
            {
                me->CombatStop(true);
                if (me->isMoving())
                    me->StopMoving();

                me->GetMotionMaster()->MovementExpired(false);
                me->GetMotionMaster()->Clear();

                CreatureAI::EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type != POINT_MOTION_TYPE || !data)
                    return;

                if (data == 13)
                {
                    circle += 2;
                    if (circle >= 2)
                    {
                        me->GetMotionMaster()->MovementExpired(false);
                        me->GetMotionMaster()->Clear();
                        phase = 2;
                        circle = 0;
                        Talk(SAY_SKIES);
                        if (Unit* pVortex = me->SummonCreature(NPC_FIERY_VORTEX, centerPos))
                            pVortex->CastSpell(pVortex, SPELL_FIERY_VORTEX);
                        events.ScheduleEvent(EVENT_BURN, 30000);
                        events.ScheduleEvent(EVENT_REMOVE_WINGS, 2000);
                        return;
                    }
                }

                switch (data)
                {
                    case 1:
                        events.CancelEvent(EVENT_BLAZING_POWER);
                        events.CancelEvent(EVENT_INCINDIARY_CLOUD);
                        break;
                    case 2:
                        DoCast(me, SPELL_BLAZING_CLAW, true);
                        DoCast(me, SPELL_MOLTING_1, true);
                        break;
                    case 3:
                        me->RemoveAura(SPELL_BLAZING_CLAW);
                        break;
                    case 4:
                        events.RescheduleEvent(EVENT_BLAZING_POWER, urand(2000, 5000));
                        events.RescheduleEvent(EVENT_INCINDIARY_CLOUD, urand(3000, 5000));
                        break;
                }
                if (curPoint >= 13)
                    curPoint = 1;
                curPoint++;
                events.ScheduleEvent(EVENT_FLIGHT, 1);
            }

            void JustReachedHome()
            {
                BossAI::JustReachedHome();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterCombat(Unit* attacker)
            {
                RemoveEncounterAuras();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_BERSERK, 6 * MINUTE * IN_MILLISECONDS);
                
                for (uint8 i = 0; i < 11; ++i)
                    me->SummonCreature(NPC_VOLCANO_FIRE_BUNNY, volcanofirePos[i]);

                phase = 1;
                curPoint = 1;

                me->SetCanFly(true);
                me->SetDisableGravity(true);

                DoCastAOE(SPELL_FIRESTORM, true);

                events.ScheduleEvent(EVENT_FLIGHT, 1);

                DoZoneInCombat();
                instance->SetBossState(DATA_ALYSRAZOR, IN_PROGRESS);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->GetMotionMaster()->MoveFall();
                _JustDied();
                Talk(SAY_DEATH);
                RemoveEncounterAuras();
            }
            
            void KilledUnit(Unit* who)
            {
                Talk(SAY_KILL);
            }

            bool AllowAchieve()
            {
                return false;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (phase == 3 && me->GetPower(POWER_MANA) >= 50)
                {
                    phase = 4;
                    me->RemoveAura(SPELL_BURNOUT);
                    DoCast(me, SPELL_IGNITED, true);
                    DoCast(me, SPELL_BLAZING_CLAW, true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    return;
                }
                else if (phase == 4 && me->GetPower(POWER_MANA) >= 100)
                {
                    phase = 0;
                    me->RemoveAura(SPELL_BLAZING_CLAW);
                    me->RemoveAura(SPELL_IGNITED);
                    summons.DespawnEntry(NPC_PLUMP_LAVA_WORM);
                    DoCast(me, SPELL_MOLTING_2, true);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastAOE(SPELL_FIRESTORM, true);
                    curPoint = 4;
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    events.ScheduleEvent(EVENT_FLIGHT, 2000);
                    return;
                }

                events.Update(diff);


                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLIGHT:
                            me->GetMotionMaster()->MovementExpired(false);
                            me->GetMotionMaster()->MovePoint(curPoint, flyPos[curPoint-1]);
                            break;
                        case EVENT_BLAZING_POWER:
                            DoCast(me, SPELL_BLAZING_POWER_SUM, true);
                            events.ScheduleEvent(EVENT_BLAZING_POWER, urand(2000, 4000));
                            break;
                        case EVENT_INCINDIARY_CLOUD:
                            DoCast(me, SPELL_INCINDIARY_CLOUD_SUM, true);
                            events.ScheduleEvent(EVENT_INCINDIARY_CLOUD, urand(2000, 4000));
                            break;
                        case EVENT_SUMMON_WORMS:
                            for (uint8 i = 0; i < 4; ++i)
                                me->SummonCreature(NPC_PLUMP_LAVA_WORM, wormPos[i]);
                            break;
                        case EVENT_INITIATE:
                            me->SummonCreature(NPC_BLAZING_TALON_INITIATE, initiatePos[urand(0, 3)]);
                            break;
                        case EVENT_BROODMOTHER:
                            me->SummonCreature(NPC_BLAZING_BROODMOTHER_1, broodmotherPos[0]);
                            me->SummonCreature(NPC_BLAZING_BROODMOTHER_2, broodmotherPos[1]);
                            break;
                        case EVENT_REMOVE_WINGS:
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WINGS_OF_FLAME);
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ALYSRAS_RAZOR);
                            break;
                        case EVENT_BURN:
                            Talk(SAY_BURN);
                            events.CancelEvent(EVENT_BLAZING_POWER);
                            events.CancelEvent(EVENT_INCINDIARY_CLOUD);
                            me->SetPower(POWER_MANA, 0);
                            phase = 3;
                            me->SetCanFly(false);
                            me->SetDisableGravity(false);
                            me->NearTeleportTo(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), centerPos.GetOrientation(), true);
                            summons.DespawnEntry(NPC_FIERY_VORTEX);
                            DoCast(me, SPELL_BURNOUT, true);
                            DoCast(me, SPELL_SPARK, true);
                            events.ScheduleEvent(EVENT_CLAWSHAPER, 2000);
                            break;
                        case EVENT_CLAWSHAPER:
                                if (Creature* pShaper = me->SummonCreature(NPC_BLAZING_TALON_CLAWSHAPER, initiatePos[0]))
                                    pShaper->AI()->Talk(SAY_AGGRO);
                                me->SummonCreature(NPC_BLAZING_TALON_CLAWSHAPER, initiatePos[1]);
                            break;
                        case EVENT_HERALD:
                            me->SummonCreature(NPC_HERALD_OF_THE_BURNING_END, centerPos);
                            break;
                    }
                }
            }
        private:

            void RemoveEncounterAuras()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZING_POWER_AURA);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MOLTEN_FEATHER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MOLTEN_FEATHER_BAR);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_IMPRINTED);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WINGS_OF_FLAME_AURA);
            }
        };
}; 

class npc_alysrazor_blazing_power : public CreatureScript
{
    public:

        npc_alysrazor_blazing_power() : CreatureScript("npc_alysrazor_blazing_power") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_blazing_powerAI(pCreature);
        }

        struct npc_alysrazor_blazing_powerAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_blazing_powerAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            void Reset()
            {
                DoCast(me, SPELL_BLAZING_POWER, true);
            }
        };
};

class npc_alysrazor_incindiary_cloud : public CreatureScript
{
    public:

        npc_alysrazor_incindiary_cloud() : CreatureScript("npc_alysrazor_incindiary_cloud") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_incindiary_cloudAI(pCreature);
        }

        struct npc_alysrazor_incindiary_cloudAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_incindiary_cloudAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            void Reset()
            {
                DoCast(me, SPELL_INCINDIARY_CLOUD, true);
            }
        };
};

class npc_alysrazor_fiery_vortex : public CreatureScript
{
    public:

        npc_alysrazor_fiery_vortex() : CreatureScript("npc_alysrazor_fiery_vortex") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_fiery_vortexAI(pCreature);
        }

        struct npc_alysrazor_fiery_vortexAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_fiery_vortexAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_HARSH_WIND, 5000);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HARSH_WIND:
                        {
                            DoCastAOE(SPELL_HARSH_WINDS, true);
                            events.ScheduleEvent(EVENT_HARSH_WIND, 5000);
                            break;
                        }
                    }
                }
            }
        };
};

class npc_alysrazor_fiery_tornado : public CreatureScript
{
    public:

        npc_alysrazor_fiery_tornado() : CreatureScript("npc_alysrazor_fiery_tornado") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_fiery_tornadoAI(pCreature);
        }

        struct npc_alysrazor_fiery_tornadoAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_fiery_tornadoAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            EventMap events;

            void Reset()
            {
                //DoCast(me, SPELL_FIERY_TORNADO, true);
                me->AddAura(SPELL_FIERY_TORNADO, me);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type == POINT_MOTION_TYPE)
                    if (data == POINT_TORNADO)
                        events.ScheduleEvent(EVENT_MOVE_TORNADO, 1000);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_TORNADO:
                        {
                            //me->GetMotionMaster()->MoveCircle(addsPos[0], 6 * MINUTE * IN_MILLISECONDS, (roll_chance_i(50) ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT));
                            break;
                        }
                    }
                }
            }
        };
};

class npc_alysrazor_blazing_talon_initiate : public CreatureScript
{
    public:

        npc_alysrazor_blazing_talon_initiate() : CreatureScript("npc_alysrazor_blazing_talon_initiate") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_blazing_talon_initiateAI(pCreature);
        }

        struct npc_alysrazor_blazing_talon_initiateAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_blazing_talon_initiateAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                waypoint = 0;
                me->SetReactState(REACT_PASSIVE);
            }

            uint8 waypoint;
            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void IsSummonedBy(Unit* summoner)
            {
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                for (uint8 i = 0; i < 4; ++i)
                {
                    if (initiatePos[i].GetPositionX() == me->GetPositionX())
                        waypoint = ++i;
                }
                
                me->GetMotionMaster()->MovePoint(POINT_INITIATE_1, initiatePos[4 + waypoint]);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (data == POINT_INITIATE_1)
                { 
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(me, (urand(0, 1) ? SPELL_FIREHAWK_TRANSFORM_M : SPELL_FIREHAWK_TRANSFORM_F));
                    me->GetMotionMaster()->MoveFall();

                    events.ScheduleEvent(EVENT_START_COMBAT, 700);

                    me->SetCanFly(false);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_COMBAT:
                            events.ScheduleEvent((urand(0, 1) ? EVENT_FIEROBLAST : EVENT_BRASHFIRE), 500);
                            break;
                        case EVENT_FIEROBLAST:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_FIEROBLAST);
                            events.ScheduleEvent(EVENT_BRASHFIRE, 3000);
                            break;
                        case EVENT_BRASHFIRE:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_BRASHFIRE);
                            events.ScheduleEvent(EVENT_FIEROBLAST, 3000);
                            break;
                    }
                }
            }
        };
};

class npc_alysrazor_brushfire : public CreatureScript
{
    public:
        npc_alysrazor_brushfire() : CreatureScript("npc_alysrazor_brushfire") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_brushfireAI (pCreature);
        }

        struct npc_alysrazor_brushfireAI : public ScriptedAI
        {
            npc_alysrazor_brushfireAI(Creature* pCreature) : ScriptedAI(pCreature) 
            {
                me->SetReactState(REACT_PASSIVE);
                started = false;
                needJump = false;
                pCreature->SetDisplayId(11686);
            }

            bool started, needJump;
            uint32 timerMove, jump, timerDespawn;

            void IsSummonedBy(Unit* summoner)
            {
                me->SetFacingTo(urand(0, 6));
                DoCast(me, SPELL_BRASHFIRE_AURA);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                started = true;
                needJump = true;
                jump = 500;
                timerMove = 1000;
                timerDespawn = 20000;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!started)
                    return;

                if (jump <= diff && needJump)
                {
                    me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), 60.0f, 200, 8);
                    needJump = false;
                } else jump -= diff;

                if (timerMove <= diff)
                {
                    me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 35, me->GetPositionY() + sin(me->GetOrientation()) * 35, 58.0f);
                } else timerMove -= diff;

                if (timerDespawn <= diff)
                {
                    me->DespawnOrUnsummon();
                } else timerDespawn -= diff;
            }
        };
};

class npc_alysrazor_blazing_talon_clawshaper : public CreatureScript
{
    public:

        npc_alysrazor_blazing_talon_clawshaper() : CreatureScript("npc_alysrazor_blazing_talon_clawshaper") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_blazing_talon_clawshaperAI(pCreature);
        }

        struct npc_alysrazor_blazing_talon_clawshaperAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_blazing_talon_clawshaperAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
            }

            InstanceScript* pInstance;
            EventMap events;
            bool bLeft;

            void Reset()
            {
                events.Reset();
            }

            void IsSummonedBy(Unit* summoner)
            {
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                bLeft = (me->GetPositionX() > -35.0f);
                me->GetMotionMaster()->MovePoint(POINT_CLAWSHAPER_2, initiatePos[(bLeft ? 4 : 5)]);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (data == POINT_CLAWSHAPER_1)
                { 
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(me, SPELL_FIREHAWK_CLAWSHAPPER);
                    me->GetMotionMaster()->MoveFall();
                    events.ScheduleEvent(EVENT_START_COMBAT, 700);

                    me->SetCanFly(false);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                }
                else if (data == POINT_CLAWSHAPER_2)
                {
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_COMBAT:
                            me->SetReactState(REACT_AGGRESSIVE);
                            events.ScheduleEvent(EVENT_IGNITION, 3000);
                            events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                            break;
                        case EVENT_IGNITION:
                            if (Unit* pAlysrazor = me->FindNearestCreature(NPC_ALYSRAZOR, 300.0f))
                                if (pAlysrazor->GetPower(POWER_MANA) < 50)
                                    DoCast(pAlysrazor, SPELL_IGNITION);
                            break;
                        case EVENT_CHECK_ENERGY:
                            if (Creature* pAlysrazor = me->FindNearestCreature(NPC_ALYSRAZOR, 5000.0f))
                            {
                                if (pAlysrazor->GetPower(POWER_ENERGY) >= 50)
                                {
                                    events.CancelEvent(EVENT_IGNITION);
                                    me->AttackStop();
                                    me->InterruptNonMeleeSpells(false);
                                    me->SetReactState(REACT_PASSIVE);
                                    DoCast(me, SPELL_FIREHAWK_REMOVE_FORM);
                                    me->SetCanFly(true);
                                    me->SetDisableGravity(true);
                                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                                    me->GetMotionMaster()->MovePoint(POINT_CLAWSHAPER_2, initiatePos[bLeft ? 0 : 1]);
                                }
                                else
                                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                            }
                            else
                                me->DespawnOrUnsummon();
                        break;
                    }
                }
            }
        };
};

class npc_alysrazor_blazing_broodmother : public CreatureScript
{
    public:
        npc_alysrazor_blazing_broodmother() : CreatureScript("npc_alysrazor_blazing_broodmother") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_alysrazor_blazing_broodmotherAI (creature);
        }

        struct npc_alysrazor_blazing_broodmotherAI : public ScriptedAI
        {
            npc_alysrazor_blazing_broodmotherAI(Creature* pCreature) : ScriptedAI(pCreature) 
            {
                me->SetReactState(REACT_PASSIVE);
            }

            EventMap events;
            bool bLeft;

            void IsSummonedBy(Unit* summoner)
            {
                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                DoCast(me, SPELL_BROODMOTHER_COSMETIC, true);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                bLeft = (me->GetPositionX() > 0);
                
                me->GetMotionMaster()->MovePoint(POINT_BROODMOTHER_1, broodmotherPos[(bLeft ? 2 : 3)]);
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (data == POINT_BROODMOTHER_1)
                {
                    me->SummonCreature(NPC_MOLTEN_EGG, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                    events.ScheduleEvent(EVENT_FLY_OUT, 1000);
                }
                else if (data == POINT_BROODMOTHER_2)
                {
                    me->DespawnOrUnsummon();
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLY_OUT:
                            me->GetMotionMaster()->MovePoint(POINT_BROODMOTHER_2, broodmotherPos[(bLeft ? 4 : 5)]);
                            break;
                    }
                }
            }
        };
};

class npc_alysrazor_molten_egg : public CreatureScript
{
    public:
        npc_alysrazor_molten_egg() : CreatureScript("npc_alysrazor_molten_egg") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_molten_eggAI (pCreature);
        }

        struct npc_alysrazor_molten_eggAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_molten_eggAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) 
            { 
                started = false;
            }

            EventMap events;
            bool started;

            void IsSummonedBy(Unit* summoner)
            {
                me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), 56.00f, me->GetOrientation());
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                events.ScheduleEvent(EVENT_EGG_EXPLOSION, 3500);
                started = true;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!started)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EGG_EXPLOSION:
                            DoCast(me, SPELL_EGG_EXPLOSION);
                            events.ScheduleEvent(EVENT_SUMMON_HATCHLING, 5000);
                            break;
                        case EVENT_SUMMON_HATCHLING:
                            DoCast(me, SPELL_SUMMON_HATCHLING);
                            me->DespawnOrUnsummon(500);
                            break;
                    }
                }
            }
        };
};

class npc_alysrazor_voracious_hatchling : public CreatureScript // 53509
{
    public:
        npc_alysrazor_voracious_hatchling() : CreatureScript("npc_voracious_hatchling") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_voracious_hatchlingAI (pCreature);
        }

        struct npc_alysrazor_voracious_hatchlingAI : public ScriptedAI
        {
            npc_alysrazor_voracious_hatchlingAI(Creature* pCreature) : ScriptedAI(pCreature) 
            {
            }

            EventMap events;

            void IsSummonedBy(Unit* summoner)
            {
                me->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
                if (Unit* pTarget = me->FindNearestPlayer(300.0f, true))
                {
                    AttackStart(pTarget);
                    DoCast(pTarget, SPELL_IMPRINTED);
                    pTarget->CastSpell(me, SPELL_IMPRINTED_TAUNT, true);
                    events.ScheduleEvent(EVENT_EAT_WORM, 1000);
                    events.ScheduleEvent(EVENT_HUNGRY, 9000);
                    events.ScheduleEvent(EVENT_GUSHING_WOUND, 15000);
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GUSHING_WOUND:
                            DoCast(me->getVictim(), SPELL_GUSHING_WOUND);
                            events.ScheduleEvent(EVENT_GUSHING_WOUND, 60000);
                        case EVENT_EAT_WORM:
                            if (Creature* pWorm = me->FindNearestCreature(NPC_PLUMP_LAVA_WORM, 5.0f, true))
                            {
                                pWorm->DespawnOrUnsummon();
                                
                                DoCast(me, SPELL_SETIATED, true);

                                if (me->HasAura(SPELL_HUNGRY))
                                    me->RemoveAura(SPELL_HUNGRY);
                                if (me->HasAura(SPELL_TANTRUM))
                                    me->RemoveAura(SPELL_TANTRUM);
                            }
                            events.ScheduleEvent(EVENT_EAT_WORM, 1000);
                            break;
                        case EVENT_HUNGRY:
                            if (!me->HasAura(SPELL_SETIATED))
                                if (!me->HasAura(SPELL_HUNGRY))
                                    DoCast(me, SPELL_HUNGRY, true);
                            events.ScheduleEvent(EVENT_HUNGRY, 2000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_alysrazor_plump_lava_worm : public CreatureScript
{
    public:

        npc_alysrazor_plump_lava_worm() : CreatureScript("npc_alysrazor_plump_lava_worm") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_plump_lava_wormAI(pCreature);
        }

        struct npc_alysrazor_plump_lava_wormAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_plump_lava_wormAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                DoCast(me, SPELL_LAVA_SPEW);
                events.ScheduleEvent(EVENT_ROTATE, 4000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ROTATE:
                        {
                            float curr_o = me->GetOrientation();
                            curr_o += 0.10f;
                            me->SetOrientation(curr_o);
                            events.ScheduleEvent(EVENT_ROTATE, 200);
                            break;
                        }
                    }
                }
            }
        };
};

class npc_alysrazor_molten_feather : public CreatureScript
{
    public:

        npc_alysrazor_molten_feather() : CreatureScript("npc_alysrazor_molten_feather") { }


        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (!pInstance || pInstance->GetBossState(DATA_ALYSRAZOR) != IN_PROGRESS)
                return true;

            if (pPlayer->HasAura(SPELL_WINGS_OF_FLAME_AURA))
                return true;

            uint8 stacks = 0;
            if (Aura const* aur = pPlayer->GetAura(SPELL_MOLTEN_FEATHER))
                stacks = aur->GetStackAmount();

            if (stacks >= 3)
                return true;

            pPlayer->CastSpell(pPlayer, SPELL_MOLTEN_FEATHER, true);          
            pPlayer->SetPower(POWER_ALTERNATE_POWER, stacks + 1);

            if (stacks >= 2)
            {
                pPlayer->RemoveAura(SPELL_MOLTEN_FEATHER);
                pPlayer->CastSpell(pPlayer, SPELL_WINGS_OF_FLAME, true);
                pPlayer->SetPower(POWER_ALTERNATE_POWER, 0);
            }

            pCreature->DespawnOrUnsummon();
            return true;
        }
};

class npc_alysrazor_herald_of_the_burning_end : public CreatureScript
{
    public:

        npc_alysrazor_herald_of_the_burning_end() : CreatureScript("npc_alysrazor_herald_of_the_burning_end") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_herald_of_the_burning_endAI(pCreature);
        }

        struct npc_alysrazor_herald_of_the_burning_endAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_herald_of_the_burning_endAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE); 
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_RITUAL_OF_THE_FLAME, true);
                DoCast(me, SPELL_CATACLYSM_1);
            }
        };
};

class npc_alysrazor_molten_meteor : public CreatureScript
{
    public:

        npc_alysrazor_molten_meteor() : CreatureScript("npc_alysrazor_molten_meteor") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_alysrazor_molten_meteorAI(pCreature);
        }

        struct npc_alysrazor_molten_meteorAI : public Scripted_NoMovementAI
        {
            npc_alysrazor_molten_meteorAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                if (me->GetEntry() == NPC_MOLTEN_METEOR_2)
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void IsSummonedBy(Unit* /*owner*/)
            {
                DoCast(me, SPELL_METEORIC_IMPACT, true);
            }

            void Reset()
            {
                DoCast(me, ((me->GetEntry() == NPC_MOLTEN_METEOR_2) ? SPELL_MOLTER_METEOR_AURA_2 : SPELL_MOLTEN_METEOR_AURA_1), true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (me->GetEntry() == NPC_MOLTEN_METEOR_1)
                    me->GetMotionMaster()->MovePoint(POINT_METEOR, meteorPos[urand(0, 6)]);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (me->GetEntry() == NPC_MOLTEN_METEOR_1)
                {
                    DoCast(me, SPELL_MOLTEN_METEOR_DEATH, true);
                    me->DespawnOrUnsummon(500);
                }
            }

            void MovementInform(uint32 type, uint32 data)
            {
                if (me->GetEntry() == NPC_MOLTEN_METEOR_1)
                {
                    if (type == POINT_MOTION_TYPE)
                        if (data == POINT_METEOR)
                            me->DespawnOrUnsummon(500);
                }
            }
        };
};

class spell_alysrazor_fieroblast : public SpellScriptLoader
{
    public:
        spell_alysrazor_fieroblast() : SpellScriptLoader("spell_alysrazor_fieroblast") { }

        class spell_alysrazor_fieroblast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_fieroblast_SpellScript);

            void FireItUp()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_FIRE_IT_UP, TRIGGERED_FULL_MASK);
            }

            void Register()
            {
                AfterCast += SpellCastFn(spell_alysrazor_fieroblast_SpellScript::FireItUp);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_fieroblast_SpellScript();
        }
};

class spell_alysrazor_harsh_winds : public SpellScriptLoader
{
    public:
        spell_alysrazor_harsh_winds() : SpellScriptLoader("spell_alysrazor_harsh_winds") { }

        class spell_alysrazor_harsh_winds_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_harsh_winds_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                targets.remove_if(PositionCheck(GetCaster()));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alysrazor_harsh_winds_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            class PositionCheck
            {
                public:
                    PositionCheck(Unit* caster) : _caster(caster) {}
        
                    bool operator()(WorldObject* unit)
                    {
                       return (_caster->GetDistance2d(unit) <= 60.0f);
                    }

                    private:
                        Unit* _caster;
                };

        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_harsh_winds_SpellScript();
        }
};

class spell_alysrazor_molten_feather : public SpellScriptLoader
{
    public:
        spell_alysrazor_molten_feather() : SpellScriptLoader("spell_alysrazor_molten_feather") { }

        class spell_alysrazor_molten_feather_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_alysrazor_molten_feather_AuraScript);

			void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

				GetTarget()->SetPower(POWER_ALTERNATE_POWER, 0);

				if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_PRI))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_PRI);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_MAG))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_MAG);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_DK))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_DK);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_WARR))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_WARR);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_WARL))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_WARL);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_SHAM))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_SHAM);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_DRU))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_DRU);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_HUN))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_HUN);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_PAL))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_PAL);
                if (GetTarget()->HasAura(SPELL_MOLTEN_FEATHER_ROG))
                    GetTarget()->RemoveAura(SPELL_MOLTEN_FEATHER_ROG);
            }

            void Register()
            {
				AfterEffectRemove += AuraEffectRemoveFn(spell_alysrazor_molten_feather_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_alysrazor_molten_feather_AuraScript();
        }
};

class spell_alysrazor_molten_feather_script : public SpellScriptLoader
{
    public:
        spell_alysrazor_molten_feather_script() : SpellScriptLoader("spell_alysrazor_molten_feather_script") { }


        class spell_alysrazor_molten_feather_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_molten_feather_script_SpellScript);

            

            void HandleScript(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                if (GetHitUnit()->GetTypeId() != TYPEID_PLAYER)
                    return;

                uint32 auraId = 0;
                switch (GetHitUnit()->getClass())
                {
                    case CLASS_PRIEST: auraId = SPELL_MOLTEN_FEATHER_PRI; break;
                    case CLASS_MAGE: auraId = SPELL_MOLTEN_FEATHER_MAG; break;
                    case CLASS_DEATH_KNIGHT: auraId = SPELL_MOLTEN_FEATHER_DK; break;
                    case CLASS_WARRIOR: auraId = SPELL_MOLTEN_FEATHER_WARR; break;
                    case CLASS_WARLOCK: auraId = SPELL_MOLTEN_FEATHER_WARL; break;
                    case CLASS_SHAMAN: auraId = SPELL_MOLTEN_FEATHER_SHAM; break;
                    case CLASS_DRUID: auraId = SPELL_MOLTEN_FEATHER_DRU; break;
                    case CLASS_HUNTER: auraId = SPELL_MOLTEN_FEATHER_HUN; break;
                    case CLASS_PALADIN: auraId = SPELL_MOLTEN_FEATHER_PAL; break;
                    case CLASS_ROGUE: auraId = SPELL_MOLTEN_FEATHER_ROG; break;
                }
                if (auraId)
                    GetHitUnit()->CastSpell(GetHitUnit(), auraId, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_molten_feather_script_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_molten_feather_script_SpellScript();
        }
};

class spell_alysrazor_cataclysm : public SpellScriptLoader
{
    public:
        spell_alysrazor_cataclysm() : SpellScriptLoader("spell_alysrazor_cataclysm") { }


        class spell_alysrazor_cataclysm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_cataclysm_SpellScript);

            

            void HandleScript()
            {
                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_MOLTEN_METEOR_MISSILE, true);
                GetCaster()->Kill(GetCaster(), false);
            }

            void Register()
            {
                AfterCast += SpellCastFn(spell_alysrazor_cataclysm_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_cataclysm_SpellScript();
        }
};

void AddSC_boss_alysrazor()
{
    new boss_alysrazor();
    new npc_alysrazor_molten_feather();
    new npc_alysrazor_blazing_power();
    new npc_alysrazor_incindiary_cloud();
    new npc_alysrazor_fiery_vortex();
    new npc_alysrazor_fiery_tornado();
    new npc_alysrazor_blazing_talon_initiate(); 
    new npc_alysrazor_brushfire();
    new npc_alysrazor_blazing_talon_clawshaper();
    new npc_alysrazor_blazing_broodmother();
    new npc_alysrazor_molten_egg();
    new npc_alysrazor_voracious_hatchling();
    new npc_alysrazor_plump_lava_worm();
    new npc_alysrazor_molten_meteor();
    new spell_alysrazor_fieroblast();
    new spell_alysrazor_harsh_winds();
    new spell_alysrazor_molten_feather();
    new spell_alysrazor_molten_feather_script();
    new spell_alysrazor_cataclysm();
}