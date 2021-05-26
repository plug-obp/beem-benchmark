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
        uint16_t glykoza:1;
        uint16_t puryvat_oxyd:1;
        uint16_t krebs_0:4;
        uint16_t glykolyza:1;
        uint16_t ETS:1;
        uint16_t rest_of_cell:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t glukosa;
    uint8_t ATP;
    uint8_t ADP;
    uint8_t NADp;
    uint8_t NADH;
    uint8_t puryvat;
    uint8_t acetyl_co_a;
    uint8_t O2;
    uint8_t CO2;
    uint8_t Hp;
    uint8_t H20;
    uint8_t energy;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.glukosa = 2;
    _out.ATP = 4;
    _out.ADP = 4;
    _out.NADp = 12;
    _out.NADH = 2;
    _out.puryvat = 0;
    _out.acetyl_co_a = 0;
    _out.O2 = 15;
    _out.CO2 = 0;
    _out.Hp = 10;
    _out.H20 = 10;
    _out.energy = 0;
    _out._control.glykoza = 0;
    _out._control.puryvat_oxyd = 0;
    _out._control.krebs_0 = 0;
    _out._control.glykolyza = 0;
    _out._control.ETS = 0;
    _out._control.rest_of_cell = 0;
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
        l3: if (  ( ((*in)._control.glykoza == 0) ) )
        {
            l4: if (  ( ((((*in).glukosa >= 1) && (((*in).ATP >= 2) && (((*in).ADP >= 2) && ((*in).NADp >= 2))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.glykoza = 0;
                ((*out).glukosa) = (((*out).glukosa - 1));
                ((*out).ADP) = (((*out).ADP - 2));
                ((*out).ATP) = (((*out).ATP + 2));
                ((*out).NADp) = (((*out).NADp - 2));
                ((*out).NADH) = (((*out).NADH + 2));
                ((*out).puryvat) = (((*out).puryvat + 2));
                ((*out).Hp) = (((*out).Hp + 2));
                ((*out).H20) = (((*out).H20 + 2));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
        }
        l5: if (  ( ((*in)._control.puryvat_oxyd == 0) ) )
        {
            l6: if (  ( ((((*in).puryvat >= 1) && ((*in).NADp >= 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.puryvat_oxyd = 0;
                ((*out).puryvat) = (((*out).puryvat - 1));
                ((*out).NADp) = (((*out).NADp - 1));
                ((*out).acetyl_co_a) = (((*out).acetyl_co_a + 1));
                ((*out).NADH) = (((*out).NADH + 1));
                ((*out).CO2) = (((*out).CO2 + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.krebs_0 == 1) ) )
        {
            l8: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
        }
        l9: if (  ( ((*in)._control.krebs_0 == 6) ) )
        {
            l10: if (  ( (((*in).H20 >= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 7;
                ((*out).H20) = (((*out).H20 - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
        }
        l11: if (  ( ((*in)._control.krebs_0 == 2) ) )
        {
            l12: if (  ( (((*in).NADp >= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 3;
                ((*out).NADp) = (((*out).NADp - 1));
                ((*out).NADH) = (((*out).NADH + 1));
                ((*out).Hp) = (((*out).Hp + 1));
                ((*out).CO2) = (((*out).CO2 + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
        }
        l13: if (  ( ((*in)._control.krebs_0 == 7) ) )
        {
            l14: if (  ( (((*in).NADp >= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 0;
                ((*out).NADp) = (((*out).NADp - 1));
                ((*out).NADH) = (((*out).NADH + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
        l15: if (  ( ((*in)._control.krebs_0 == 0) ) )
        {
            l16: if (  ( ((((*in).acetyl_co_a >= 1) && ((*in).H20 >= 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 1;
                ((*out).acetyl_co_a) = (((*out).acetyl_co_a - 1));
                ((*out).H20) = (((*out).H20 - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
        }
        l17: if (  ( ((*in)._control.krebs_0 == 3) ) )
        {
            l18: if (  ( (((*in).NADp >= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.krebs_0 = 6;
                ((*out).NADH) = (((*out).NADH + 1));
                ((*out).CO2) = (((*out).CO2 + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
        }
        l19: if (  ( ((*in)._control.ETS == 0) ) )
        {
            l20: if (  ( (((*in).ADP >= 2)) )  &&  ( ((*in)._control.glykolyza == 0) )  &&  ( ((((*in).NADH >= 1) && (((*in).O2 >= 1) && ((*in).Hp >= 2)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ETS = 0;
                ((*out).ADP) = (((*out).ADP - 2));
                ((*out).ATP) = (((*out).ATP + 2));
                (*out)._control.glykolyza = 0;
                ((*out).NADH) = (((*out).NADH - 1));
                ((*out).NADp) = (((*out).NADp + 1));
                ((*out).O2) = (((*out).O2 - 1));
                ((*out).Hp) = (((*out).Hp - 2));
                ((*out).H20) = (((*out).H20 + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
        }
        l21: if (  ( ((*in)._control.rest_of_cell == 0) ) )
        {
            l22: if (  ( (((*in).ATP >= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.rest_of_cell = 0;
                ((*out).ATP) = (((*out).ATP - 1));
                ((*out).ADP) = (((*out).ADP + 1));
                ((*out).energy) = (((*out).energy + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
        }
    }
    l23: if (  ( system_in_deadlock ) )
    {
    }
    l24: return 0;
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
        case 15: goto l15;
        case 16: goto l16;
        case 17: goto l17;
        case 18: goto l18;
        case 19: goto l19;
        case 20: goto l20;
        case 21: goto l21;
        case 22: goto l22;
        case 23: goto l23;
        case 24: goto l24;
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
