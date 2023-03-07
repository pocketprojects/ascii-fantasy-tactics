char screen[14][22] = {
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
};

char info_panel[2][22] = {
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
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
    char letter[1];
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
    struct weapon {char w_name[10]; int dmg;}pc_weapon;
    struct spell_1 {char s1_name[10]; char s1_desc[40]; int s1_range; int s1_dmg; int s1_recov;}pc_spell1;
    struct spell_2 {char s2_name[10]; char s2_desc[40]; int s2_range; int s2_dmg; int s2_recov;}pc_spell2;
    struct spell_3 {char s3_name[10]; char s3_desc[40]; int s3_range; int s3_dmg; int s3_recov;}pc_spell3;
    struct spell_4 {char s4_name[10]; char s4_desc[40]; int s4_range; int s4_dmg; int s4_recov;}pc_spell4;
    int x_position;
    int y_position;
};


struct character_pc pcs[2] = {
    {"A","AV",1,"Avery", "Fighter","This one is protagonist.",1,0,2000,40,8,15,1,1,{"Big Sword",8},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},12,3},
    {"K","KK",2,"Koko",  "Black Mage", "I will eradicate them.",  1,0,2500,40,6,13,1,0,{"Magic Rod",3},{"Light.Bolt","Range 50 + 10 per lvl. DMG 1d6 in 10x40.",50,5,0},{"Fireball","Rnge 100 + 10 per lvl. DMG 1d6 rad 20.",100,6,0},{"","",0,0,0},{"","",0,0,0},12,4}
};
int amount_of_fighters = sizeof(pcs) / sizeof(pcs[0]);
// struct character_pc character1 = {"A",1,"Avery", "Fighter","This one is protagonist.",1,0,2000,40,8,15,1,1,{"Big Sword",8},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},{"","",0,0,0},12,3};
// struct character_pc character2 = {"K",2,"Koko",  "Black Mage", "I will eradicate them.",  1,0,2500,40,6,13,1,0,{"Magic Rod",3},{"Light.Bolt","Range 50 + 10 per lvl. DMG 1d6 in 10x40.",50,5,0},{"Fireball","Rnge 100 + 10 per lvl. DMG 1d6 rad 20.",100,6,0},{"","",0,0,0},{"","",0,0,0},12,4};

struct enemy { 
    char letter[1];
    char id[2];         // id is must be unique, since we could have multiple figures with the same letter.
    int initiative;
    char name[10];
    char race[10];
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

struct enemy monsters[2] = {
    {"g","g1",3,"Fred","Goblin",4,14,30,4,7,18,1,3},
    {"r","r1",4,"Rogue","Human",5,13,40,4,7,18,1,4}
};

int amount_of_monsters = sizeof(monsters) / sizeof(monsters[0]);
