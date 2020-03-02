typedef unsigned char   undefined;

typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef struct entity_t entity_t, *Pentity_t;

typedef struct z64_actor_s z64_actor_s, *Pz64_actor_s;

typedef struct z64_actor_s z64_actor_t;

typedef uchar uint8_t;

typedef struct z64_collider_cylinder_main_s z64_collider_cylinder_main_s, *Pz64_collider_cylinder_main_s;

typedef struct z64_collider_cylinder_main_s z64_collider_cylinder_main_t;

typedef uint uint32_t;

typedef short int16_t;

typedef enum actor_type { /* Actor Types */
    Bg=1,
    Boss=9,
    Chest=11,
    Door=10,
    Enemy=5,
    Explosives=3,
    Item_Action=7,
    Misc=8,
    NPC=4,
    Player=2,
    Prop=6,
    Switch=0
} actor_type;

typedef enum actor_type z64_actor_type_t;

typedef char int8_t;

typedef struct vec3f_s vec3f_s, *Pvec3f_s;

typedef struct vec3f_s vec3f_t;

typedef struct vec3s_s vec3s_s, *Pvec3s_s;

typedef struct vec3s_s vec3s_t;

typedef ushort uint16_t;

typedef struct z64_col_poly_s z64_col_poly_s, *Pz64_col_poly_s;

typedef struct z64_col_poly_s z64_col_poly_t;

typedef struct z64_collider_s z64_collider_s, *Pz64_collider_s;

typedef struct z64_collider_s z64_collider_t;

typedef struct z64_collider_body_s z64_collider_body_s, *Pz64_collider_body_s;

typedef struct z64_collider_body_s z64_collider_body_t;

typedef struct z64_collider_touch_s z64_collider_touch_s, *Pz64_collider_touch_s;

typedef struct z64_collider_touch_s z64_collider_touch_t;

typedef struct z64_collider_bump_s z64_collider_bump_s, *Pz64_collider_bump_s;

typedef struct z64_collider_bump_s z64_collider_bump_t;

typedef int int32_t;

struct vec3f_s { /* 3 Vector Structure (Float) */
    float x; /* X Vector */
    float y; /* Y Vector */
    float z; /* Z Vector */
};

struct vec3s_s { /* 3 Vector Structure (Signed Short) */
    int16_t x; /* X Vector */
    int16_t y; /* Y Vector */
    int16_t z; /* Z Vector */
};

struct z64_actor_s { /* Common Actor Instance Structure */
    int16_t actor_id; /* Actor Number */
    z64_actor_type_t actor_type; /* Actor Type */
    int8_t room_index; /* Room Index */
    uint32_t flags; /* Special Actor Flags */
    vec3f_t pos_1; /* Position (1) */
    vec3s_t rot_init; /* Initial Rotation */
    char unk_01_[2]; /* Undocumented / Unused */
    uint16_t variable; /* Actor Variable */
    uint8_t alloc_index; /* Allocation Index */
    char unk1F; /* Undocumented / Unused */
    uint16_t sound_effect; /* Actor Sound Effect */
    char unk_03_[2]; /* Undocumented / Unused */
    vec3f_t pos_2; /* Position (2) */
    int16_t unk30; /* Undocumented / Unused */
    int16_t xz_dir; /* Direction (X and Z axes) */
    int16_t unk34; /* Undocumented / Unused */
    uint16_t unk36; /* Undocumented / Unused */
    vec3f_t pos_3; /* Position (3) */
    vec3s_t rot_1; /* Rotation (1) */
    char unk_06_[2]; /* Undocumented / Unused */
    float unk_07_; /* Undocumented / Unused */
    vec3f_t scale; /* Actor Scale */
    vec3f_t vel_1; /* Velocity (1) */
    float xz_speed; /* Speed (X and Z axes) */
    float gravity; /* Gravity */
    float min_vel_y; /* Minimum Velocity (Y axis) */
    z64_col_poly_t * wall_poly; /* Wall Collision */
    z64_col_poly_t * floor_poly; /* Floor Collision */
    uint8_t wall_poly_source;
    uint8_t floor_poly_source;
    int16_t wall_rot; /* Rotation Towards Wall */
    float floor_height; /* Height of Floor (Maybe?) */
    float water_surface_dist; /* Distance to Water Surface */
    uint16_t bgcheck_flags;
    int16_t rot_toward_link_y; /* Y Rotation to face Player */
    float unk_0x8C; /* Undocumented / Unused */
    float dist_from_link_xz; /* Distance From Player (X and Z axes) */
    float dist_from_link_y; /* Distance From Player (Y axis) */
    void * damage_table; /* Pointer to Damage Table */
    vec3f_t vel_2; /* Velocity (2) */
    char unk_0B_[6]; /* Undocumented / Unused */
    uint8_t mass; /* Mass */
    uint8_t health; /* Health */
    uint8_t damage; /* Damage Amount */
    uint8_t damage_effect; /* Damage Effect */
    uint8_t impact_effect; /* Impact Effect */
    char unk_0D; /* Undocumented / Unused */
    vec3s_t rot_2; /* Rotation (2) */
    char unk_0E_[2]; /* Undocumented / Unused */
    float unk_0xBC; /* Undocumented / Unused */
    void * draw_drop_shadow; /* Shadow Draw Function */
    float unk_0xC4; /* Undocumented / Unused */
    uint8_t unk_0xC8; /* Undocumented / Unused */
    char pad_0xC9_[3]; /* Pad (Controller Related?) */
    vec3f_t unk_0xCC; /* Undocumented / Unused */
    vec3f_t unk_0xD8; /* Undocumented / Unused */
    vec3f_t unk_0xE4; /* Undocumented / Unused */
    float unk_0xF0; /* Undocumented / Unused */
    float unk_0xF4; /* Undocumented / Unused */
    float unk_0xF8; /* Undocumented / Unused */
    float unk_0xFC; /* Undocumented / Unused */
    vec3f_t pos_4; /* Position (4) */
    uint16_t unk_0F_; /* Undocumented / Unused */
    uint16_t text_id; /* Actor Message ID */
    int16_t frozen;
    char unk_10_[3]; /* Undocumented / Unused */
    uint8_t active;
    uint8_t unk_11_; /* Undocumented / Unused */
    uint8_t navi_enemy_text_id; /* Navi Info Message ID */
    void * attached_a; /* Attached Actor A */
    void * attached_b; /* Attached Actor B */
    void * prev; /* Previous Actor */
    void * next; /* Next Actor */
    void * ctor; /* Constructor */
    void * dtor; /* Destructor */
    void * main_proc; /* Main Function */
    void * draw_proc; /* Draw Function */
    void * code_entry; /* Code Entry */
};

struct z64_collider_s { /* Collider Structure */
    z64_actor_t * actor;
    z64_actor_t * unk_actor_1;
    z64_actor_t * unk_actor_2;
    z64_actor_t * unk_actor_3;
    uint8_t collider_flags; /* Compared to 0x11 */
    uint8_t collide_flags; /* Compared to 0x10 */
    uint8_t mask_a; /* Bitwise-and compared to 0x13 */
    uint8_t mask_b; /* Bitwise-and compared to 0x12 */
    uint8_t unk_0x14;
    uint8_t type; /* Cylinder Collection, Cylinder, Triangle Collection, Quad */
};

struct z64_collider_bump_s {
    int32_t flags; /* Collision Exclusion Mask */
    uint8_t effect;
    uint8_t unk_0x05;
    int32_t unk_0x08;
};

struct z64_collider_touch_s {
    int32_t flags; /* Toucher Attack Identifier Flags */
    uint8_t unk_0x04;
    uint8_t damage; /* Damage or Stun Timer */
};

struct z64_collider_body_s { /* Collider Body Structure */
    z64_collider_touch_t toucher;
    z64_collider_bump_t bumper;
    uint8_t flags;
    uint8_t toucher_flags;
    uint8_t bumper_flags;
    uint8_t flags_2;
    int32_t unk_0x18;
    z64_collider_t * collider;
    int32_t unk_0x20;
    void * colliding;
};

struct z64_collider_cylinder_main_s { /* Previously (z64_capsule) */
    z64_collider_t base;
    z64_collider_body_t body;
    int16_t radius;
    int16_t height;
    int16_t y_shift;
    vec3s_t position;
};

struct entity_t {
    z64_actor_t actor;
    uint8_t inst_unk_00_[860];
    z64_collider_cylinder_main_t capsule;
    uint32_t inst_04E4;
    uint8_t inst_unk_01_[124];
    uint32_t inst_0564;
    uint8_t inst_unk_02_[124];
    uint32_t inst_05E4;
    uint8_t inst_unk_03_[136];
    uint32_t inst_0670;
    uint8_t inst_unk_04_[1056];
};

struct z64_col_poly_s { /* Collision Polygon Structure */
    uint16_t type; /* Collision Type */
    uint16_t unk_00_va; /* Vertex Index A */
    uint16_t unk_01_vb; /* Vertex Index B */
    uint16_t vc; /* Vertex Index C */
    vec3s_t norm; /* Normal Vector */
    int16_t dist; /* Plane Distance from Origin */
};

