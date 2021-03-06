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
        uint16_t User_0:4;
        uint16_t User_1:4;
        uint16_t User_2:4;
        uint16_t User_3:4;
    }
    __attribute__((__packed__)) _control;
    uint8_t chan[4];
    uint8_t partner[4];
    uint8_t record[4];
    struct
    {
        uint8_t dev;
        uint8_t mbit;
    }
    __attribute__((__packed__)) User_0;
    struct
    {
        uint8_t dev;
        uint8_t mbit;
    }
    __attribute__((__packed__)) User_1;
    struct
    {
        uint8_t dev;
        uint8_t mbit;
    }
    __attribute__((__packed__)) User_2;
    struct
    {
        uint8_t dev;
        uint8_t mbit;
    }
    __attribute__((__packed__)) User_3;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.chan[0] = 255;
    _out.chan[1] = 255;
    _out.chan[2] = 255;
    _out.chan[3] = 255;
    _out.partner[0] = 255;
    _out.partner[1] = 255;
    _out.partner[2] = 255;
    _out.partner[3] = 255;
    _out.record[0] = 255;
    _out.record[1] = 255;
    _out.record[2] = 255;
    _out.record[3] = 255;
    _out.User_0.dev = 1;
    _out._control.User_0 = 0;
    _out.User_1.dev = 1;
    _out._control.User_1 = 0;
    _out.User_2.dev = 1;
    _out._control.User_2 = 0;
    _out.User_3.dev = 1;
    _out._control.User_3 = 0;
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
        l3: if (  ( ((*in)._control.User_0 == 3) ) )
        {
            l4: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).chan[ 0 ]) = (255);
                ((*out).partner[ 0 ]) = (255);
                ((*out).User_0.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
        }
        l5: if (  ( ((*in)._control.User_0 == 2) ) )
        {
            l6: if (  ( (((*in).partner[ 0 ] == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( (((*in).partner[ 0 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( (((*in).partner[ 0 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((((*in).partner[ 0 ] != 0) && (((*in).partner[ 0 ] != 4) && ((*in).chan[ (*in).partner[ 0 ] ] != 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 3;
                ((*out).record[ (*out).partner[ 0 ] ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((((*in).partner[ 0 ] != 0) && (((*in).partner[ 0 ] != 4) && ((*in).chan[ (*in).partner[ 0 ] ] == 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 7;
                ((*out).record[ (*out).partner[ 0 ] ]) = (0);
                ((*out).chan[ (*out).partner[ 0 ] ]) = ((0 + (0 * 20)));
                ((*out).chan[ 0 ]) = (((*out).partner[ 0 ] + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
        }
        l11: if (  ( ((*in)._control.User_0 == 1) ) )
        {
            l12: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.dev) = (1);
                ((*out).chan[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
        }
        l18: if (  ( ((*in)._control.User_0 == 0) ) )
        {
            l19: if (  ( (((*in).chan[ 0 ] == 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 1;
                ((*out).User_0.dev) = (0);
                ((*out).chan[ 0 ]) = ((0 + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( (((*in).chan[ 0 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 4;
                ((*out).partner[ 0 ]) = (((*out).chan[ 0 ] % 20));
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
        }
        l21: if (  ( ((*in)._control.User_0 == 7) ) )
        {
            l22: if (  ( ((((*in).chan[ 0 ] % 20) != (*in).partner[ 0 ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( (((((*in).chan[ 0 ] % 20) == (*in).partner[ 0 ]) && (((*in).chan[ 0 ] / 20) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( (((((*in).chan[ 0 ] % 20) == (*in).partner[ 0 ]) && (((*in).chan[ 0 ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 10;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
        }
        l25: if (  ( ((*in)._control.User_0 == 9) ) )
        {
            l26: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.dev) = (1);
                ((*out).chan[ 0 ]) = (255);
                ((*out).chan[ (*out).partner[ 0 ] ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.User_0 == 10) ) )
        {
            l28: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.dev) = (1);
                ((*out).chan[ 0 ]) = (255);
                ((*out).partner[ 0 ]) = ((((*out).partner[ 0 ] % 20) + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
        }
        l29: if (  ( ((*in)._control.User_0 == 4) ) )
        {
            l30: if (  ( ((((*in).chan[ (*in).partner[ 0 ] ] % 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( ((((*in).chan[ (*in).partner[ 0 ] ] % 20) != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).partner[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
        }
        l32: if (  ( ((*in)._control.User_0 == 13) ) )
        {
            l33: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).chan[ 0 ]) = (255);
                ((*out).partner[ 0 ]) = (255);
                ((*out).User_0.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( (((*in).record[ 0 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 2;
                ((*out).partner[ 0 ]) = ((*out).record[ 0 ]);
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
        }
        l35: if (  ( ((*in)._control.User_0 == 5) ) )
        {
            l36: if (  ( ((((*in).User_0.dev != 1) || ((*in).chan[ 0 ] == 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((((*in).chan[ (*in).partner[ 0 ] ] % 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( ((((*in).chan[ (*in).partner[ 0 ] ] % 20) != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
        }
        l39: if (  ( ((*in)._control.User_0 == 12) ) )
        {
            l40: if (  ( (((((*in).chan[ 0 ] / 20) == 1) && ((*in).User_0.dev == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 12;
                ((*out).User_0.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( (((((*in).chan[ 0 ] / 20) == 1) && ((*in).User_0.dev == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 12;
                ((*out).User_0.dev) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( ((((*in).chan[ 0 ] / 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).partner[ 0 ]) = (255);
                ((*out).chan[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
        }
        l43: if (  ( ((*in)._control.User_0 == 11) ) )
        {
            l44: if (  ( (((((*in).chan[ (*in).partner[ 0 ] ] % 20) == 0) && (((*in).chan[ (*in).partner[ 0 ] ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 12;
                ((*out).User_0.dev) = (0);
                ((*out).chan[ (*out).partner[ 0 ] ]) = ((0 + (1 * 20)));
                ((*out).chan[ 0 ]) = (((*out).partner[ 0 ] + (1 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((((*in).chan[ (*in).partner[ 0 ] ] == 255) || (((*in).chan[ (*in).partner[ 0 ] ] % 20) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.dev) = (1);
                ((*out).partner[ 0 ]) = (255);
                ((*out).chan[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
        }
        l46: if (  ( ((*in)._control.User_0 == 6) ) )
        {
            l47: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).chan[ 0 ]) = (255);
                ((*out).partner[ 0 ]) = (255);
                ((*out).User_0.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
        }
        l48: if (  ( ((*in)._control.User_1 == 3) ) )
        {
            l49: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).chan[ 1 ]) = (255);
                ((*out).partner[ 1 ]) = (255);
                ((*out).User_1.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
        }
        l50: if (  ( ((*in)._control.User_1 == 2) ) )
        {
            l51: if (  ( (((*in).partner[ 1 ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( (((*in).partner[ 1 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( (((*in).partner[ 1 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( ((((*in).partner[ 1 ] != 1) && (((*in).partner[ 1 ] != 4) && ((*in).chan[ (*in).partner[ 1 ] ] != 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 3;
                ((*out).record[ (*out).partner[ 1 ] ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((((*in).partner[ 1 ] != 1) && (((*in).partner[ 1 ] != 4) && ((*in).chan[ (*in).partner[ 1 ] ] == 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 7;
                ((*out).record[ (*out).partner[ 1 ] ]) = (1);
                ((*out).chan[ (*out).partner[ 1 ] ]) = ((1 + (0 * 20)));
                ((*out).chan[ 1 ]) = (((*out).partner[ 1 ] + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
        }
        l56: if (  ( ((*in)._control.User_1 == 1) ) )
        {
            l57: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.dev) = (1);
                ((*out).chan[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
        }
        l63: if (  ( ((*in)._control.User_1 == 0) ) )
        {
            l64: if (  ( (((*in).chan[ 1 ] == 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 1;
                ((*out).User_1.dev) = (0);
                ((*out).chan[ 1 ]) = ((1 + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( (((*in).chan[ 1 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 4;
                ((*out).partner[ 1 ]) = (((*out).chan[ 1 ] % 20));
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
        }
        l66: if (  ( ((*in)._control.User_1 == 7) ) )
        {
            l67: if (  ( ((((*in).chan[ 1 ] % 20) != (*in).partner[ 1 ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( (((((*in).chan[ 1 ] % 20) == (*in).partner[ 1 ]) && (((*in).chan[ 1 ] / 20) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if (  ( (((((*in).chan[ 1 ] % 20) == (*in).partner[ 1 ]) && (((*in).chan[ 1 ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 10;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
        }
        l70: if (  ( ((*in)._control.User_1 == 9) ) )
        {
            l71: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.dev) = (1);
                ((*out).chan[ 1 ]) = (255);
                ((*out).chan[ (*out).partner[ 1 ] ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
        }
        l72: if (  ( ((*in)._control.User_1 == 10) ) )
        {
            l73: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.dev) = (1);
                ((*out).chan[ 1 ]) = (255);
                ((*out).partner[ 1 ]) = ((((*out).partner[ 1 ] % 20) + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
        }
        l74: if (  ( ((*in)._control.User_1 == 4) ) )
        {
            l75: if (  ( ((((*in).chan[ (*in).partner[ 1 ] ] % 20) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( ((((*in).chan[ (*in).partner[ 1 ] ] % 20) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).partner[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
        }
        l77: if (  ( ((*in)._control.User_1 == 13) ) )
        {
            l78: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).chan[ 1 ]) = (255);
                ((*out).partner[ 1 ]) = (255);
                ((*out).User_1.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( (((*in).record[ 1 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 2;
                ((*out).partner[ 1 ]) = ((*out).record[ 1 ]);
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
        }
        l80: if (  ( ((*in)._control.User_1 == 5) ) )
        {
            l81: if (  ( ((((*in).User_1.dev != 1) || ((*in).chan[ 1 ] == 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( ((((*in).chan[ (*in).partner[ 1 ] ] % 20) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( ((((*in).chan[ (*in).partner[ 1 ] ] % 20) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
        }
        l84: if (  ( ((*in)._control.User_1 == 12) ) )
        {
            l85: if (  ( (((((*in).chan[ 1 ] / 20) == 1) && ((*in).User_1.dev == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 12;
                ((*out).User_1.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( (((((*in).chan[ 1 ] / 20) == 1) && ((*in).User_1.dev == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 12;
                ((*out).User_1.dev) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
            l87: if (  ( ((((*in).chan[ 1 ] / 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).partner[ 1 ]) = (255);
                ((*out).chan[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
        }
        l88: if (  ( ((*in)._control.User_1 == 11) ) )
        {
            l89: if (  ( (((((*in).chan[ (*in).partner[ 1 ] ] % 20) == 1) && (((*in).chan[ (*in).partner[ 1 ] ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 12;
                ((*out).User_1.dev) = (0);
                ((*out).chan[ (*out).partner[ 1 ] ]) = ((1 + (1 * 20)));
                ((*out).chan[ 1 ]) = (((*out).partner[ 1 ] + (1 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
            l90: if (  ( ((((*in).chan[ (*in).partner[ 1 ] ] == 255) || (((*in).chan[ (*in).partner[ 1 ] ] % 20) != 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.dev) = (1);
                ((*out).partner[ 1 ]) = (255);
                ((*out).chan[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
        }
        l91: if (  ( ((*in)._control.User_1 == 6) ) )
        {
            l92: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).chan[ 1 ]) = (255);
                ((*out).partner[ 1 ]) = (255);
                ((*out).User_1.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
        }
        l93: if (  ( ((*in)._control.User_2 == 3) ) )
        {
            l94: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).chan[ 2 ]) = (255);
                ((*out).partner[ 2 ]) = (255);
                ((*out).User_2.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
        }
        l95: if (  ( ((*in)._control.User_2 == 2) ) )
        {
            l96: if (  ( (((*in).partner[ 2 ] == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
            l97: if (  ( (((*in).partner[ 2 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 98;
            }
            l98: if (  ( (((*in).partner[ 2 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
            l99: if (  ( ((((*in).partner[ 2 ] != 2) && (((*in).partner[ 2 ] != 4) && ((*in).chan[ (*in).partner[ 2 ] ] != 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 3;
                ((*out).record[ (*out).partner[ 2 ] ]) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
            l100: if (  ( ((((*in).partner[ 2 ] != 2) && (((*in).partner[ 2 ] != 4) && ((*in).chan[ (*in).partner[ 2 ] ] == 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 7;
                ((*out).record[ (*out).partner[ 2 ] ]) = (2);
                ((*out).chan[ (*out).partner[ 2 ] ]) = ((2 + (0 * 20)));
                ((*out).chan[ 2 ]) = (((*out).partner[ 2 ] + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
        }
        l101: if (  ( ((*in)._control.User_2 == 1) ) )
        {
            l102: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).User_2.dev) = (1);
                ((*out).chan[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
            l103: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
            l106: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
            l107: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
        }
        l108: if (  ( ((*in)._control.User_2 == 0) ) )
        {
            l109: if (  ( (((*in).chan[ 2 ] == 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 1;
                ((*out).User_2.dev) = (0);
                ((*out).chan[ 2 ]) = ((2 + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
            l110: if (  ( (((*in).chan[ 2 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 4;
                ((*out).partner[ 2 ]) = (((*out).chan[ 2 ] % 20));
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
        }
        l111: if (  ( ((*in)._control.User_2 == 7) ) )
        {
            l112: if (  ( ((((*in).chan[ 2 ] % 20) != (*in).partner[ 2 ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
            l113: if (  ( (((((*in).chan[ 2 ] % 20) == (*in).partner[ 2 ]) && (((*in).chan[ 2 ] / 20) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 114;
            }
            l114: if (  ( (((((*in).chan[ 2 ] % 20) == (*in).partner[ 2 ]) && (((*in).chan[ 2 ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 10;
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
        }
        l115: if (  ( ((*in)._control.User_2 == 9) ) )
        {
            l116: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).User_2.dev) = (1);
                ((*out).chan[ 2 ]) = (255);
                ((*out).chan[ (*out).partner[ 2 ] ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.User_2 == 10) ) )
        {
            l118: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).User_2.dev) = (1);
                ((*out).chan[ 2 ]) = (255);
                ((*out).partner[ 2 ]) = ((((*out).partner[ 2 ] % 20) + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
        }
        l119: if (  ( ((*in)._control.User_2 == 4) ) )
        {
            l120: if (  ( ((((*in).chan[ (*in).partner[ 2 ] ] % 20) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
            l121: if (  ( ((((*in).chan[ (*in).partner[ 2 ] ] % 20) != 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).partner[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
        }
        l122: if (  ( ((*in)._control.User_2 == 13) ) )
        {
            l123: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).chan[ 2 ]) = (255);
                ((*out).partner[ 2 ]) = (255);
                ((*out).User_2.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
            l124: if (  ( (((*in).record[ 2 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 2;
                ((*out).partner[ 2 ]) = ((*out).record[ 2 ]);
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
        }
        l125: if (  ( ((*in)._control.User_2 == 5) ) )
        {
            l126: if (  ( ((((*in).User_2.dev != 1) || ((*in).chan[ 2 ] == 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
            l127: if (  ( ((((*in).chan[ (*in).partner[ 2 ] ] % 20) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
            l128: if (  ( ((((*in).chan[ (*in).partner[ 2 ] ] % 20) != 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
        }
        l129: if (  ( ((*in)._control.User_2 == 12) ) )
        {
            l130: if (  ( (((((*in).chan[ 2 ] / 20) == 1) && ((*in).User_2.dev == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 12;
                ((*out).User_2.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
            l131: if (  ( (((((*in).chan[ 2 ] / 20) == 1) && ((*in).User_2.dev == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 12;
                ((*out).User_2.dev) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((((*in).chan[ 2 ] / 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).partner[ 2 ]) = (255);
                ((*out).chan[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
        }
        l133: if (  ( ((*in)._control.User_2 == 11) ) )
        {
            l134: if (  ( (((((*in).chan[ (*in).partner[ 2 ] ] % 20) == 2) && (((*in).chan[ (*in).partner[ 2 ] ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 12;
                ((*out).User_2.dev) = (0);
                ((*out).chan[ (*out).partner[ 2 ] ]) = ((2 + (1 * 20)));
                ((*out).chan[ 2 ]) = (((*out).partner[ 2 ] + (1 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( ((((*in).chan[ (*in).partner[ 2 ] ] == 255) || (((*in).chan[ (*in).partner[ 2 ] ] % 20) != 2))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).User_2.dev) = (1);
                ((*out).partner[ 2 ]) = (255);
                ((*out).chan[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
        }
        l136: if (  ( ((*in)._control.User_2 == 6) ) )
        {
            l137: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_2 = 0;
                ((*out).chan[ 2 ]) = (255);
                ((*out).partner[ 2 ]) = (255);
                ((*out).User_2.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
        }
        l138: if (  ( ((*in)._control.User_3 == 3) ) )
        {
            l139: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).chan[ 3 ]) = (255);
                ((*out).partner[ 3 ]) = (255);
                ((*out).User_3.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 140;
            }
        }
        l140: if (  ( ((*in)._control.User_3 == 2) ) )
        {
            l141: if (  ( (((*in).partner[ 3 ] == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
            l142: if (  ( (((*in).partner[ 3 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
            l143: if (  ( (((*in).partner[ 3 ] == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( ((((*in).partner[ 3 ] != 3) && (((*in).partner[ 3 ] != 4) && ((*in).chan[ (*in).partner[ 3 ] ] != 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 3;
                ((*out).record[ (*out).partner[ 3 ] ]) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
            l145: if (  ( ((((*in).partner[ 3 ] != 3) && (((*in).partner[ 3 ] != 4) && ((*in).chan[ (*in).partner[ 3 ] ] == 255)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 7;
                ((*out).record[ (*out).partner[ 3 ] ]) = (3);
                ((*out).chan[ (*out).partner[ 3 ] ]) = ((3 + (0 * 20)));
                ((*out).chan[ 3 ]) = (((*out).partner[ 3 ] + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
        }
        l146: if (  ( ((*in)._control.User_3 == 1) ) )
        {
            l147: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).User_3.dev) = (1);
                ((*out).chan[ 3 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
            l148: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 149;
            }
            l149: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
            l150: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
            l151: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
            l152: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
        }
        l153: if (  ( ((*in)._control.User_3 == 0) ) )
        {
            l154: if (  ( (((*in).chan[ 3 ] == 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 1;
                ((*out).User_3.dev) = (0);
                ((*out).chan[ 3 ]) = ((3 + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
            l155: if (  ( (((*in).chan[ 3 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 4;
                ((*out).partner[ 3 ]) = (((*out).chan[ 3 ] % 20));
                system_in_deadlock = false;
                *to = blob_out;
                return 156;
            }
        }
        l156: if (  ( ((*in)._control.User_3 == 7) ) )
        {
            l157: if (  ( ((((*in).chan[ 3 ] % 20) != (*in).partner[ 3 ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
            l158: if (  ( (((((*in).chan[ 3 ] % 20) == (*in).partner[ 3 ]) && (((*in).chan[ 3 ] / 20) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 159;
            }
            l159: if (  ( (((((*in).chan[ 3 ] % 20) == (*in).partner[ 3 ]) && (((*in).chan[ 3 ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 10;
                system_in_deadlock = false;
                *to = blob_out;
                return 160;
            }
        }
        l160: if (  ( ((*in)._control.User_3 == 9) ) )
        {
            l161: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).User_3.dev) = (1);
                ((*out).chan[ 3 ]) = (255);
                ((*out).chan[ (*out).partner[ 3 ] ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 162;
            }
        }
        l162: if (  ( ((*in)._control.User_3 == 10) ) )
        {
            l163: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).User_3.dev) = (1);
                ((*out).chan[ 3 ]) = (255);
                ((*out).partner[ 3 ]) = ((((*out).partner[ 3 ] % 20) + (0 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
        }
        l164: if (  ( ((*in)._control.User_3 == 4) ) )
        {
            l165: if (  ( ((((*in).chan[ (*in).partner[ 3 ] ] % 20) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 166;
            }
            l166: if (  ( ((((*in).chan[ (*in).partner[ 3 ] ] % 20) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).partner[ 3 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 167;
            }
        }
        l167: if (  ( ((*in)._control.User_3 == 13) ) )
        {
            l168: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).chan[ 3 ]) = (255);
                ((*out).partner[ 3 ]) = (255);
                ((*out).User_3.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
            l169: if (  ( (((*in).record[ 3 ] != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 2;
                ((*out).partner[ 3 ]) = ((*out).record[ 3 ]);
                system_in_deadlock = false;
                *to = blob_out;
                return 170;
            }
        }
        l170: if (  ( ((*in)._control.User_3 == 5) ) )
        {
            l171: if (  ( ((((*in).User_3.dev != 1) || ((*in).chan[ 3 ] == 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 172;
            }
            l172: if (  ( ((((*in).chan[ (*in).partner[ 3 ] ] % 20) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 173;
            }
            l173: if (  ( ((((*in).chan[ (*in).partner[ 3 ] ] % 20) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
        }
        l174: if (  ( ((*in)._control.User_3 == 12) ) )
        {
            l175: if (  ( (((((*in).chan[ 3 ] / 20) == 1) && ((*in).User_3.dev == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 12;
                ((*out).User_3.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
            l176: if (  ( (((((*in).chan[ 3 ] / 20) == 1) && ((*in).User_3.dev == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 12;
                ((*out).User_3.dev) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
            l177: if (  ( ((((*in).chan[ 3 ] / 20) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).partner[ 3 ]) = (255);
                ((*out).chan[ 3 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 178;
            }
        }
        l178: if (  ( ((*in)._control.User_3 == 11) ) )
        {
            l179: if (  ( (((((*in).chan[ (*in).partner[ 3 ] ] % 20) == 3) && (((*in).chan[ (*in).partner[ 3 ] ] / 20) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 12;
                ((*out).User_3.dev) = (0);
                ((*out).chan[ (*out).partner[ 3 ] ]) = ((3 + (1 * 20)));
                ((*out).chan[ 3 ]) = (((*out).partner[ 3 ] + (1 * 20)));
                system_in_deadlock = false;
                *to = blob_out;
                return 180;
            }
            l180: if (  ( ((((*in).chan[ (*in).partner[ 3 ] ] == 255) || (((*in).chan[ (*in).partner[ 3 ] ] % 20) != 3))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).User_3.dev) = (1);
                ((*out).partner[ 3 ]) = (255);
                ((*out).chan[ 3 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
        }
        l181: if (  ( ((*in)._control.User_3 == 6) ) )
        {
            l182: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_3 = 0;
                ((*out).chan[ 3 ]) = (255);
                ((*out).partner[ 3 ]) = (255);
                ((*out).User_3.dev) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
        }
    }
    l183: if (  ( system_in_deadlock ) )
    {
    }
    l184: return 0;
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
        case 25: goto l25;
        case 26: goto l26;
        case 27: goto l27;
        case 28: goto l28;
        case 29: goto l29;
        case 30: goto l30;
        case 31: goto l31;
        case 32: goto l32;
        case 33: goto l33;
        case 34: goto l34;
        case 35: goto l35;
        case 36: goto l36;
        case 37: goto l37;
        case 38: goto l38;
        case 39: goto l39;
        case 40: goto l40;
        case 41: goto l41;
        case 42: goto l42;
        case 43: goto l43;
        case 44: goto l44;
        case 45: goto l45;
        case 46: goto l46;
        case 47: goto l47;
        case 48: goto l48;
        case 49: goto l49;
        case 50: goto l50;
        case 51: goto l51;
        case 52: goto l52;
        case 53: goto l53;
        case 54: goto l54;
        case 55: goto l55;
        case 56: goto l56;
        case 57: goto l57;
        case 58: goto l58;
        case 59: goto l59;
        case 60: goto l60;
        case 61: goto l61;
        case 62: goto l62;
        case 63: goto l63;
        case 64: goto l64;
        case 65: goto l65;
        case 66: goto l66;
        case 67: goto l67;
        case 68: goto l68;
        case 69: goto l69;
        case 70: goto l70;
        case 71: goto l71;
        case 72: goto l72;
        case 73: goto l73;
        case 74: goto l74;
        case 75: goto l75;
        case 76: goto l76;
        case 77: goto l77;
        case 78: goto l78;
        case 79: goto l79;
        case 80: goto l80;
        case 81: goto l81;
        case 82: goto l82;
        case 83: goto l83;
        case 84: goto l84;
        case 85: goto l85;
        case 86: goto l86;
        case 87: goto l87;
        case 88: goto l88;
        case 89: goto l89;
        case 90: goto l90;
        case 91: goto l91;
        case 92: goto l92;
        case 93: goto l93;
        case 94: goto l94;
        case 95: goto l95;
        case 96: goto l96;
        case 97: goto l97;
        case 98: goto l98;
        case 99: goto l99;
        case 100: goto l100;
        case 101: goto l101;
        case 102: goto l102;
        case 103: goto l103;
        case 104: goto l104;
        case 105: goto l105;
        case 106: goto l106;
        case 107: goto l107;
        case 108: goto l108;
        case 109: goto l109;
        case 110: goto l110;
        case 111: goto l111;
        case 112: goto l112;
        case 113: goto l113;
        case 114: goto l114;
        case 115: goto l115;
        case 116: goto l116;
        case 117: goto l117;
        case 118: goto l118;
        case 119: goto l119;
        case 120: goto l120;
        case 121: goto l121;
        case 122: goto l122;
        case 123: goto l123;
        case 124: goto l124;
        case 125: goto l125;
        case 126: goto l126;
        case 127: goto l127;
        case 128: goto l128;
        case 129: goto l129;
        case 130: goto l130;
        case 131: goto l131;
        case 132: goto l132;
        case 133: goto l133;
        case 134: goto l134;
        case 135: goto l135;
        case 136: goto l136;
        case 137: goto l137;
        case 138: goto l138;
        case 139: goto l139;
        case 140: goto l140;
        case 141: goto l141;
        case 142: goto l142;
        case 143: goto l143;
        case 144: goto l144;
        case 145: goto l145;
        case 146: goto l146;
        case 147: goto l147;
        case 148: goto l148;
        case 149: goto l149;
        case 150: goto l150;
        case 151: goto l151;
        case 152: goto l152;
        case 153: goto l153;
        case 154: goto l154;
        case 155: goto l155;
        case 156: goto l156;
        case 157: goto l157;
        case 158: goto l158;
        case 159: goto l159;
        case 160: goto l160;
        case 161: goto l161;
        case 162: goto l162;
        case 163: goto l163;
        case 164: goto l164;
        case 165: goto l165;
        case 166: goto l166;
        case 167: goto l167;
        case 168: goto l168;
        case 169: goto l169;
        case 170: goto l170;
        case 171: goto l171;
        case 172: goto l172;
        case 173: goto l173;
        case 174: goto l174;
        case 175: goto l175;
        case 176: goto l176;
        case 177: goto l177;
        case 178: goto l178;
        case 179: goto l179;
        case 180: goto l180;
        case 181: goto l181;
        case 182: goto l182;
        case 183: goto l183;
        case 184: goto l184;
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
