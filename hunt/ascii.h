/* The MS-DOS ASCII Character Set */
#ifndef ascii_h
#define ascii_h

enum
{
    ASCII_NUL               = 0x00,
    ASCII_FACE1             = 0x01,
    ASCII_FACE2             = 0x02,
    ASCII_HEART             = 0x03,
    ASCII_DIAMOND           = 0x04,
    ASCII_CLUB              = 0x05,
    ASCII_SPADE             = 0x06,
    ASCII_DOT1              = 0x07,
    ASCII_DOT2              = 0x08,
    ASCII_RING1             = 0x09,
    ASCII_RING2             = 0x0A,
    ASCII_MALE              = 0x0B,
    ASCII_FEMALE            = 0x0C,
    ASCII_NOTE1             = 0x0D,
    ASCII_NOTE2             = 0x0E,
    ASCII_STAR              = 0x0F,
    ASCII_TRI_RIGHT         = 0x10,
    ASCII_TRI_LEFT          = 0x11,
    ASCII_UPDOWNARROW1      = 0x12,
    ASCII_DBL_EXCLAM        = 0x13,
    ASCII_PARAGRAPH         = 0x14,
    ASCII_SECTION           = 0x15,
    ASCII_CURSOR            = 0x16,
    ASCII_UPDOWNARROW2      = 0x17,
    ASCII_UPARROW           = 0x18,
    ASCII_DOWNARROW         = 0x19,
    ASCII_RIGHTARROW        = 0x1A,
    ASCII_LEFTARROW         = 0x1B,
    ASCII_REV_INV_NOT       = 0x1C,
    ASCII_RIGHTLEFTARROW    = 0x1D,
    ASCII_TRI_UP            = 0x1E,
    ASCII_TRI_DOWN          = 0x1F,
    
    /* printable characters omitted */
    
    ASCII_DELETE            = 0x7F,
    ASCII_C_CEDI_UPPER      = 0x80,
    ASCII_U_UMLT_LOWER      = 0x81,
    ASCII_E_ACUT_LOWER      = 0x82,
    ASCII_A_CIRC_LOWER      = 0x83,
    ASCII_A_UMLT_LOWER      = 0x84,
    ASCII_A_GRAV_LOWER      = 0x85,
    ASCII_A_RING_LOWER      = 0x86,
    ASCII_C_CEDI_LOWER      = 0x87,
    ASCII_E_CIRC_LOWER      = 0x88,
    ASCII_E_UMLT_LOWER      = 0x89,
    ASCII_E_GRAV_LOWER      = 0x8A,
    ASCII_I_UMLT_LOWER      = 0x8B,
    ASCII_I_CIRC_LOWER      = 0x8C,
    ASCII_I_GRAV_LOWER      = 0x8D,
    ASCII_A_UMLT_UPPER      = 0x8E,
    ASCII_A_RING_UPPER      = 0x8F,
    ASCII_E_ACUT_UPPER      = 0x90,
    ASCII_AE_LOWER          = 0x91,
    ASCII_AE_UPPER          = 0x92,
    ASCII_O_CIRC_LOWER      = 0x93,
    ASCII_O_UMLT_LOWER      = 0x94,
    ASCII_O_GRAV_LOWER      = 0x95,
    ASCII_U_CIRC_LOWER      = 0x96,
    ASCII_U_GRAV_LOWER      = 0x97,
    ASCII_Y_UMLT_LOWER      = 0x98,
    ASCII_O_UMLT_UPPER      = 0x99,
    ASCII_U_UMLT_UPPER      = 0x9A,
    ASCII_CENT              = 0x9B,
    ASCII_POUND             = 0x9C,
    ASCII_YEN               = 0x9D,
    ASCII_PESETA            = 0x9E,
    ASCII_F_HOOK            = 0x9F,
    ASCII_A_ACUT_LOWER      = 0xA0,
    ASCII_I_ACUT_LOWER      = 0xA1,
    ASCII_O_ACUT_LOWER      = 0xA2,
    ASCII_U_ACUT_LOWER      = 0xA3,
    ASCII_N_TILD_LOWER      = 0xA4,
    ASCII_N_TILD_UPPER      = 0xA5,
    ASCII_FEM_ORD           = 0xA6,
    ASCII_MASC_ORD          = 0xA7,
    ASCII_INV_QUESTION      = 0xA8,
    ASCII_NOT_REVERSED      = 0xA9,
    ASCII_NOT               = 0xAA,
    ASCII_FRAC_HALF         = 0xAB,
    ASCII_FRAC_QUARTER      = 0xAC,
    ASCII_INV_EXCLAMATION   = 0xAD,
    ASCII_LEFT_ANG_QUOTE    = 0xAE,
    ASCII_RIGHT_AND_QUOTE   = 0xAF,
    ASCII_BLOCK_LIGHT       = 0xB0,
    ASCII_BLOCK_MEDIUM      = 0xB1,
    ASCII_BLOCK_DARK        = 0xB2,

    /* box-drawing characters omitted */
    
    ASCII_BLOCK_FULL        = 0xDB,
    ASCII_BLOCK_BOTTOM      = 0xDC,
    ASCII_BLOCK_LEFT        = 0xDD,
    ASCII_BLOCK_RIGHT       = 0xDE,
    ASCII_BLOCK_TOP         = 0xDF,
    ASCII_ALPHA             = 0xE0,
    ASCII_BETA              = 0xE1,
    ASCII_GAMMA             = 0xE2,
    ASCII_PI                = 0xE3,
    ASCII_SIGMA_UPPER       = 0xE4,
    ASCII_SIGMA_LOWER       = 0xE5,
    ASCII_MU                = 0xE6,
    ASCII_TAU               = 0xE7,
    ASCII_PHI_UPPER         = 0xE8,
    ASCII_THETA             = 0xE9,
    ASCII_OMEGA             = 0xEA,
    ASCII_DELTA             = 0xEB,
    ASCII_INFINITY          = 0xEC,
    ASCII_PHI_LOWER         = 0xED,
    ASCII_EPSILON           = 0xEE,
    ASCII_INTERSECTION      = 0xEF,
    ASCII_IDENTICAL         = 0xF0,
    ASCII_PLUSMINUS         = 0xF1,
    ASCII_GT_OR_EQ          = 0xF2,
    ASCII_LT_OR_EQ          = 0xF3,
    ASCII_INTEGRAL_TOP      = 0xF4,
    ASCII_INTEGRAL_BOTTOM   = 0xF5,
    ASCII_DIVISION          = 0xF6,
    ASCII_ALMOST_EQUALS     = 0xF7,
    ASCII_DEGREE            = 0xF8,
    ASCII_INTERPUNCT1       = 0xF9,
    ASCII_INTERPUNCT2       = 0xFA,
    ASCII_RADICAL           = 0xFB,
    ASCII_SUPER_N           = 0xFC,
    ASCII_SUPER_2           = 0xFD,
    ASCII_SQUARE            = 0xFE,
    ASCII_NBSP              = 0xFF
};

#endif /* ascii_h */
