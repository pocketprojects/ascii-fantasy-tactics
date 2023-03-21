char screen[SCREEN_HEIGHT][SCREEN_WIDTH];

char info_panel[2][22] = {
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
};

char side_panel[12][32] = {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};

/* LEVELS*/
char lvl1[14][22] = {
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
};

/*PARTY - PLAYABLE CHARACTERS*/

struct character_pc {
    char letter;
    char id[2];         // id is must be unique, since we could have multiple figures with the same letter.
    int initiative;
    char name[10];
    char pc_class[10];
    char pc_description[24];
    int lvl;
    int xp;
    int max_xp;
    int mov; /*how many squares player can move*/
    int hp;
    int ac; /*Armor Class*/
    int bonus; /*Attack Bonus*/
    int chain_mail;
    char weapon[2];
    char spells[4][2];
    int x_position;
    int y_position;
};


struct character_pc pcs[4] = {
    {'A',"av",2,"Avery", "Fighter","This one is protagonist.",1,0,2000,40,8,15,1,1,{'b','s'},{{'n','n'},{'n','n'},{'n','n'},{'n','n'}},12,3},
    {'K',"kk",4,"Koko",  "Bl__Mage","I will eradicate them.",  1,0,2500,40,6,13,1,0,{'m','r'},{{'l','b'},{'f','b'},{'n','n'},{'n','n'}},12,4},
    {'M',"mk",6,"Marsh", "Archer","You can\'t escape!",1,0,2500,30,6,13,1,0,{'b','w'},{{'n','n'},{'n','n'},{'n','n'},{'n','n'}},12,5},
    {'Z',"zk",8,"Zok",   "Wh__Mage","Need help?",1,0,1500,30,8,13,1,0,{'m','r'},{{'l','b'},{'r','e'},{'n','n'},{'n','n'}},12,6}
};
int amount_of_fighters = sizeof(pcs) / sizeof(pcs[0]);
// struct character_pc character1 = {"A",1,"Avery", "Fighter","This one is protagonist.",1,0,2000,40,8,15,1,1,{"Big Sword",8},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},12,3};
// struct character_pc character2 = {"K",2,"Koko",  "Black Mage", "I will eradicate them.",  1,0,2500,40,6,13,1,0,{"Magic Rod",3},{"Light.Bolt","Range 50 + 10 per lvl. DMG 1d6 in 10x40.",50,5,0},{"Fireball","Rnge 100 + 10 per lvl. DMG 1d6 rad 20.",100,6,0},{"","",0,0,0},{"","",0,0,0},12,4};

struct enemy { 
    char letter;
    char id[2];         // id is must be unique, since we could have multiple figures with the same letter.
    int initiative;
    char name[10];
    char race[14];
    char attack_description[40];
    int hp;
    int ac; /*Armor Class*/
    int mov; /*how many squares player can move*/
    int dmg;
    int morale;
    int saves; /*"SAVES AS target, BFT, p. 89"*/
    int x_position;
    int y_position;
};

/*
Saving throw - d20 against number. 1 is always failure, 20 alway success.
If number + modifier equals or exceeds target number, the roll is success,
otherwise faild.
*/

struct enemy monsters[4] = {
    {'g',"g1",1,"Fred","Goblin","Goblin attacks!",4,14,30,4,7,18,1,3},
    {'r',"r1",3,"Rogue","Human","Rogue attacks",5,13,40,4,7,18,1,4},
    {'t',"t1",5,"Ted",  "Tentacle_Worm","Squeezed you hard!",14,13,30,8,7,18,1,5},
    {'h',"h1",7,"BadBoy", "Hell_Hound","Fire breed attack!",18,14,40,6,9,20,1,6}
};

int amount_of_monsters = sizeof(monsters) / sizeof(monsters[0]);

struct spell {
    char id[2];
    char name[12];
    char desc[40];
    int range;
    int dmg;
    int recov;
    int inc_mov;
    int dec_mov;
};

struct spell spells[3] = {
    {"lb","Light_Bolt","Light bolt the strikes target",50,5,0,0,0},
    {"fb","Fire_Ball ","Ball of fire hits the target",60,6,0,0,0},
    {"re","Recovery  ","Targets HP points has been recovered",10,0,4,0,0}
};

int amount_of_spells = sizeof(spells) / sizeof(spells[0]);

struct weapon {
    char id[2];
    char name[12];
    int ranged; /*0 if sword or dagger, 1 if i.e. bow*/
    int range;
    int inc_dmg;
    int inc_ac;
    int inc_mov;
    int dec_mov;
};

struct weapon weapons[3] = {
    {"bs","Big_Sword",0,0,2,0,0,0},
    {"mr","Magic_Rod",0,0,1,0,0,0},
    {"bw","Bow",1,60,2,0,0,0}
};

int amount_of_weapon = sizeof(weapons) / sizeof(weapons[0]);