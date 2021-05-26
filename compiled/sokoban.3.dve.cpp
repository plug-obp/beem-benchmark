#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint64_t ulong_long_int_t;
typedef int64_t slong_long_int_t;
typedef uint32_t ulong_int_t;
typedef int32_t slong_int_t;
typedef uint16_t ushort_int_t;
typedef int16_t sshort_int_t;
typedef uint8_t byte_t;
typedef uint8_t ubyte_t;
typedef int8_t sbyte_t;
typedef size_t size_int_t;

// -*- C++ -*- (c) 2010,2015 Petr Rockai <me@mornfall.net>

#include "stdint.h"
#ifdef _WIN32
#include <stdarg.h>
#endif

#ifndef DIVINE_GENERATOR_CESMI_CLIENT_H
#define DIVINE_GENERATOR_CESMI_CLIENT_H

enum cesmi_property_type { cesmi_pt_goal, cesmi_pt_deadlock, cesmi_pt_buchi };
/* the following are bitmasks (i.e. each value should be a power of 2 */
enum cesmi_flags { cesmi_goal = 1, cesmi_accepting = 2, cesmi_first_user_flag = 1 << 8 };

typedef struct {
    uint64_t handle;
    char *memory;
} cesmi_node;

typedef struct cesmi_setup {
    void *loader;
    cesmi_node (*make_node)( const struct cesmi_setup *setup, int size );
    cesmi_node (*clone_node)( const struct cesmi_setup *setup, cesmi_node orig );
    int (*add_property)( struct cesmi_setup *setup, char *id, char *desc, int type );
    void *instance; // per-instance data; never touched by DiVinE
    int property_count; /* filled in by setup */
    int property; /* filled in by loader */
    int instance_initialised;
    void (*add_flag)( struct cesmi_setup *setup, char *name, int id, int type );
    /* extensions at the end are ABI-compatible */
} cesmi_setup;

/* prototypes that CESMI modules need to implement */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32 /* augh; but very useful for show_node/show_transition */
int vasprintf(char **result, const char *format, va_list aq);
int asprintf(char **result, const char *format, ...);
#endif

    void  setup             ( cesmi_setup * );
     int  get_initial       ( const cesmi_setup *, int, cesmi_node * );
     int  get_successor     ( const cesmi_setup *, int, cesmi_node, cesmi_node * );
uint64_t  get_flags         ( const cesmi_setup *, cesmi_node );
    char *show_node         ( const cesmi_setup *, cesmi_node );
    char *show_transition   ( const cesmi_setup *, cesmi_node, int );

#ifdef __cplusplus
}
#endif

#endif




struct state_struct_t
{
    struct
    {
        uint16_t P:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t a[209];
    uint8_t x;
    uint8_t y;
    uint8_t done;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.a[0] = 1;
    _out.a[1] = 1;
    _out.a[2] = 1;
    _out.a[3] = 1;
    _out.a[4] = 1;
    _out.a[5] = 1;
    _out.a[6] = 1;
    _out.a[7] = 1;
    _out.a[8] = 1;
    _out.a[9] = 1;
    _out.a[10] = 1;
    _out.a[11] = 1;
    _out.a[12] = 1;
    _out.a[13] = 1;
    _out.a[14] = 1;
    _out.a[15] = 1;
    _out.a[16] = 1;
    _out.a[17] = 1;
    _out.a[18] = 1;
    _out.a[19] = 1;
    _out.a[20] = 1;
    _out.a[21] = 1;
    _out.a[22] = 1;
    _out.a[23] = 0;
    _out.a[24] = 0;
    _out.a[25] = 0;
    _out.a[26] = 1;
    _out.a[27] = 1;
    _out.a[28] = 1;
    _out.a[29] = 1;
    _out.a[30] = 1;
    _out.a[31] = 1;
    _out.a[32] = 1;
    _out.a[33] = 1;
    _out.a[34] = 1;
    _out.a[35] = 1;
    _out.a[36] = 1;
    _out.a[37] = 1;
    _out.a[38] = 1;
    _out.a[39] = 1;
    _out.a[40] = 1;
    _out.a[41] = 1;
    _out.a[42] = 2;
    _out.a[43] = 0;
    _out.a[44] = 0;
    _out.a[45] = 1;
    _out.a[46] = 1;
    _out.a[47] = 1;
    _out.a[48] = 1;
    _out.a[49] = 1;
    _out.a[50] = 1;
    _out.a[51] = 1;
    _out.a[52] = 1;
    _out.a[53] = 1;
    _out.a[54] = 1;
    _out.a[55] = 1;
    _out.a[56] = 1;
    _out.a[57] = 1;
    _out.a[58] = 1;
    _out.a[59] = 1;
    _out.a[60] = 1;
    _out.a[61] = 0;
    _out.a[62] = 0;
    _out.a[63] = 2;
    _out.a[64] = 1;
    _out.a[65] = 1;
    _out.a[66] = 1;
    _out.a[67] = 1;
    _out.a[68] = 1;
    _out.a[69] = 1;
    _out.a[70] = 1;
    _out.a[71] = 1;
    _out.a[72] = 1;
    _out.a[73] = 1;
    _out.a[74] = 1;
    _out.a[75] = 1;
    _out.a[76] = 1;
    _out.a[77] = 1;
    _out.a[78] = 1;
    _out.a[79] = 0;
    _out.a[80] = 2;
    _out.a[81] = 0;
    _out.a[82] = 2;
    _out.a[83] = 0;
    _out.a[84] = 0;
    _out.a[85] = 1;
    _out.a[86] = 1;
    _out.a[87] = 1;
    _out.a[88] = 1;
    _out.a[89] = 1;
    _out.a[90] = 1;
    _out.a[91] = 1;
    _out.a[92] = 1;
    _out.a[93] = 1;
    _out.a[94] = 1;
    _out.a[95] = 1;
    _out.a[96] = 1;
    _out.a[97] = 1;
    _out.a[98] = 0;
    _out.a[99] = 1;
    _out.a[100] = 0;
    _out.a[101] = 1;
    _out.a[102] = 1;
    _out.a[103] = 0;
    _out.a[104] = 1;
    _out.a[105] = 1;
    _out.a[106] = 1;
    _out.a[107] = 1;
    _out.a[108] = 1;
    _out.a[109] = 1;
    _out.a[110] = 1;
    _out.a[111] = 1;
    _out.a[112] = 1;
    _out.a[113] = 1;
    _out.a[114] = 1;
    _out.a[115] = 0;
    _out.a[116] = 0;
    _out.a[117] = 0;
    _out.a[118] = 1;
    _out.a[119] = 0;
    _out.a[120] = 1;
    _out.a[121] = 1;
    _out.a[122] = 0;
    _out.a[123] = 1;
    _out.a[124] = 1;
    _out.a[125] = 1;
    _out.a[126] = 1;
    _out.a[127] = 1;
    _out.a[128] = 0;
    _out.a[129] = 0;
    _out.a[130] = 0;
    _out.a[131] = 0;
    _out.a[132] = 1;
    _out.a[133] = 1;
    _out.a[134] = 0;
    _out.a[135] = 2;
    _out.a[136] = 0;
    _out.a[137] = 0;
    _out.a[138] = 2;
    _out.a[139] = 0;
    _out.a[140] = 0;
    _out.a[141] = 0;
    _out.a[142] = 0;
    _out.a[143] = 0;
    _out.a[144] = 0;
    _out.a[145] = 0;
    _out.a[146] = 0;
    _out.a[147] = 0;
    _out.a[148] = 0;
    _out.a[149] = 0;
    _out.a[150] = 0;
    _out.a[151] = 1;
    _out.a[152] = 1;
    _out.a[153] = 1;
    _out.a[154] = 1;
    _out.a[155] = 1;
    _out.a[156] = 1;
    _out.a[157] = 0;
    _out.a[158] = 1;
    _out.a[159] = 1;
    _out.a[160] = 1;
    _out.a[161] = 0;
    _out.a[162] = 1;
    _out.a[163] = 0;
    _out.a[164] = 1;
    _out.a[165] = 1;
    _out.a[166] = 0;
    _out.a[167] = 0;
    _out.a[168] = 0;
    _out.a[169] = 0;
    _out.a[170] = 1;
    _out.a[171] = 1;
    _out.a[172] = 1;
    _out.a[173] = 1;
    _out.a[174] = 1;
    _out.a[175] = 1;
    _out.a[176] = 0;
    _out.a[177] = 0;
    _out.a[178] = 0;
    _out.a[179] = 0;
    _out.a[180] = 0;
    _out.a[181] = 1;
    _out.a[182] = 0;
    _out.a[183] = 1;
    _out.a[184] = 1;
    _out.a[185] = 1;
    _out.a[186] = 1;
    _out.a[187] = 1;
    _out.a[188] = 1;
    _out.a[189] = 1;
    _out.a[190] = 1;
    _out.a[191] = 1;
    _out.a[192] = 1;
    _out.a[193] = 1;
    _out.a[194] = 1;
    _out.a[195] = 1;
    _out.a[196] = 1;
    _out.a[197] = 1;
    _out.a[198] = 1;
    _out.a[199] = 1;
    _out.a[200] = 1;
    _out.a[201] = 1;
    _out.a[202] = 1;
    _out.a[203] = 1;
    _out.a[204] = 1;
    _out.a[205] = 1;
    _out.a[206] = 1;
    _out.a[207] = 1;
    _out.a[208] = 1;
    _out.x = 11;
    _out.y = 9;
    _out.done = 0;
    _out._control.P = 0;
    return 2;
}

void setup( cesmi_setup *setup ) {
    setup->add_property( setup, strdup( "deadlock" ), NULL, cesmi_pt_deadlock );
    setup->add_property( setup, strdup( "assert" ), NULL, cesmi_pt_goal );
    setup->add_flag( setup, strdup( "assert" ), cesmi_first_user_flag, 0 );
}
uint64_t get_flags( const cesmi_setup *setup, cesmi_node n )
{
    state_struct_t &state = *reinterpret_cast< state_struct_t * >( n.memory );
    uint64_t f = 0;
    switch ( setup->property )
    {
        case 1: if ( f & cesmi_first_user_flag ) f |= cesmi_goal;
        return f;
    }
    return f;
}

int get_successor0( const cesmi_setup *setup, int next_state, cesmi_node from, cesmi_node *to ) 
{
    const state_struct_t *in = reinterpret_cast< state_struct_t * >( from.memory );
    bool system_in_deadlock = false;
    goto switch_state;
    l1: if ( false )
    {
        l2: ;
    }
    else
    {
        l3: if (  ( ((*in)._control.P == 0) ) )
        {
            l4: if (  ( ((((*in).done == 0) && (((*in).a[ 74 ] == 2) && (((*in).a[ 75 ] == 2) && (((*in).a[ 85 ] == 2) && (((*in).a[ 86 ] == 2) && (((*in).a[ 96 ] == 2) && ((*in).a[ 97 ] == 2)))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).done) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).done == 0) && ((*in).a[ (((*in).y * 19) + ((*in).x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).x) = (((*out).x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((((*in).done == 0) && ((*in).a[ (((*in).y * 19) + ((*in).x + 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).x) = (((*out).x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((((*in).done == 0) && ((*in).a[ ((((*in).y - 1) * 19) + (*in).x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).y) = (((*out).y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((((*in).done == 0) && ((*in).a[ ((((*in).y + 1) * 19) + (*in).x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).y) = (((*out).y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((((*in).done == 0) && (((*in).a[ (((*in).y * 19) + ((*in).x - 1)) ] == 2) && ((*in).a[ (((*in).y * 19) + ((*in).x - 2)) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).a[ (((*out).y * 19) + ((*out).x - 2)) ]) = (2);
                ((*out).a[ (((*out).y * 19) + ((*out).x - 1)) ]) = (0);
                ((*out).x) = (((*out).x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((((*in).done == 0) && (((*in).a[ (((*in).y * 19) + ((*in).x + 1)) ] == 2) && ((*in).a[ (((*in).y * 19) + ((*in).x + 2)) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).a[ (((*out).y * 19) + ((*out).x + 2)) ]) = (2);
                ((*out).a[ (((*out).y * 19) + ((*out).x + 1)) ]) = (0);
                ((*out).x) = (((*out).x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((((*in).done == 0) && (((*in).a[ ((((*in).y - 1) * 19) + (*in).x) ] == 2) && ((*in).a[ ((((*in).y - 2) * 19) + (*in).x) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).a[ ((((*out).y - 2) * 19) + (*out).x) ]) = (2);
                ((*out).a[ ((((*out).y - 1) * 19) + (*out).x) ]) = (0);
                ((*out).y) = (((*out).y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((((*in).done == 0) && (((*in).a[ ((((*in).y + 1) * 19) + (*in).x) ] == 2) && ((*in).a[ ((((*in).y + 2) * 19) + (*in).x) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).a[ ((((*out).y + 2) * 19) + (*out).x) ]) = (2);
                ((*out).a[ ((((*out).y + 1) * 19) + (*out).x) ]) = (0);
                ((*out).y) = (((*out).y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
        }
    }
    l13: if (  ( system_in_deadlock ) )
    {
    }
    l14: return 0;
    switch_state: switch( next_state )
    {
        case 1: system_in_deadlock = true; goto l1;
        case 2: goto l2;
        case 3: goto l3;
        case 4: goto l4;
        case 5: goto l5;
        case 6: goto l6;
        case 7: goto l7;
        case 8: goto l8;
        case 9: goto l9;
        case 10: goto l10;
        case 11: goto l11;
        case 12: goto l12;
        case 13: goto l13;
        case 14: goto l14;
    }
}
int get_successor( const cesmi_setup *setup, int next_state, cesmi_node from, cesmi_node *to ) 
{
    switch ( setup->property )
    {
        case 0: 
        case 1:
        return get_successor0( setup, next_state, from, to );
    }
}
