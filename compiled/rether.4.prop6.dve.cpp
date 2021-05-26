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
        uint16_t Bandwidth:3;
        uint16_t Node_0:4;
        uint16_t Node_1:4;
        uint16_t Node_2:4;
        uint16_t Node_3:4;
        uint16_t Node_4:4;
        uint16_t Node_5:4;
        uint16_t Node_6:4;
        uint16_t Node_7:4;
        uint16_t Node_8:4;
        uint16_t Token:3;
        uint16_t LTL_property:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t in_RT[9];
    uint8_t RT_count;
    struct
    {
        uint8_t i;
    }
    __attribute__((__packed__)) Bandwidth;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_0;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_1;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_2;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_3;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_4;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_5;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_6;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_7;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_8;
    struct
    {
        uint8_t i;
        uint8_t NRT_count;
        uint8_t next;
    }
    __attribute__((__packed__)) Token;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.RT_count = 0;
    _out._control.Bandwidth = 0;
    _out.Node_0.granted = 0;
    _out._control.Node_0 = 0;
    _out.Node_1.granted = 0;
    _out._control.Node_1 = 0;
    _out.Node_2.granted = 0;
    _out._control.Node_2 = 0;
    _out.Node_3.granted = 0;
    _out._control.Node_3 = 0;
    _out.Node_4.granted = 0;
    _out._control.Node_4 = 0;
    _out.Node_5.granted = 0;
    _out._control.Node_5 = 0;
    _out.Node_6.granted = 0;
    _out._control.Node_6 = 0;
    _out.Node_7.granted = 0;
    _out._control.Node_7 = 0;
    _out.Node_8.granted = 0;
    _out._control.Node_8 = 0;
    _out.Token.NRT_count = 5;
    _out.Token.next = 0;
    _out._control.Token = 0;
    _out._control.LTL_property = 0;
    return 2;
}

void setup( cesmi_setup *setup ) {
    setup->add_property( setup, strdup( "deadlock" ), NULL, cesmi_pt_deadlock );
    setup->add_property( setup, strdup( "assert" ), NULL, cesmi_pt_goal );
    setup->add_flag( setup, strdup( "assert" ), cesmi_first_user_flag, 0 );
    setup->add_property( setup, strdup( "LTL" ), NULL, cesmi_pt_buchi );
}
uint64_t get_flags( const cesmi_setup *setup, cesmi_node n )
{
    state_struct_t &state = *reinterpret_cast< state_struct_t * >( n.memory );
    uint64_t f = 0;
    switch ( setup->property )
    {
        case 1: if ( f & cesmi_first_user_flag ) f |= cesmi_goal;
        return f;
        case 2:
        if (  ( (state._control.LTL_property == 1) ) )
            f |= cesmi_accepting;
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
        l3: if (  ( ((*in)._control.Bandwidth == 0) ) )
        {
            l4: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((*in).Node_0.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((*in).Node_1.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((*in).Node_2.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((*in).Node_3.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((*in).Node_4.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((*in).Node_5.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.Node_6 == 3) )  &&  ( (((*in).Node_6.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_6 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((*in)._control.Node_7 == 3) )  &&  ( (((*in).Node_7.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_7 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((*in)._control.Node_8 == 3) )  &&  ( (((*in).Node_8.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_8 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((*in)._control.Node_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((*in)._control.Node_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.Node_2 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.Node_3 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.Node_4 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Node_5 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Node_6 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.Node_7 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.Node_8 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
        }
        l22: if (  ( ((*in)._control.Bandwidth == 1) ) )
        {
            l23: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
        }
        l25: if (  ( ((*in)._control.Node_0 == 3) ) )
        {
            l26: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.Node_0 == 2) ) )
        {
            l28: if (  ( (((*in).Node_0.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.Node_0 == 0) ) )
        {
            l31: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
        }
        l33: if (  ( ((*in)._control.Node_0 == 5) ) )
        {
            l34: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
        }
        l35: if (  ( ((*in)._control.Node_0 == 1) ) )
        {
            l36: if (  ( (((*in).Node_0.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( (((*in).Node_0.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.Node_0 == 4) ) )
        {
            l39: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.Node_1 == 3) ) )
        {
            l42: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
        }
        l43: if (  ( ((*in)._control.Node_1 == 2) ) )
        {
            l44: if (  ( (((*in).Node_1.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
        }
        l46: if (  ( ((*in)._control.Node_1 == 0) ) )
        {
            l47: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.Node_1 == 5) ) )
        {
            l50: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
        }
        l51: if (  ( ((*in)._control.Node_1 == 1) ) )
        {
            l52: if (  ( (((*in).Node_1.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( (((*in).Node_1.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.Node_1 == 4) ) )
        {
            l55: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
        }
        l57: if (  ( ((*in)._control.Node_2 == 3) ) )
        {
            l58: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
        }
        l59: if (  ( ((*in)._control.Node_2 == 2) ) )
        {
            l60: if (  ( (((*in).Node_2.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
        l62: if (  ( ((*in)._control.Node_2 == 0) ) )
        {
            l63: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.Node_2 == 5) ) )
        {
            l66: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
        }
        l67: if (  ( ((*in)._control.Node_2 == 1) ) )
        {
            l68: if (  ( (((*in).Node_2.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if (  ( (((*in).Node_2.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
        }
        l70: if (  ( ((*in)._control.Node_2 == 4) ) )
        {
            l71: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
        }
        l73: if (  ( ((*in)._control.Node_3 == 3) ) )
        {
            l74: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
        }
        l75: if (  ( ((*in)._control.Node_3 == 2) ) )
        {
            l76: if (  ( (((*in).Node_3.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
        }
        l78: if (  ( ((*in)._control.Node_3 == 0) ) )
        {
            l79: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
        }
        l81: if (  ( ((*in)._control.Node_3 == 5) ) )
        {
            l82: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
        }
        l83: if (  ( ((*in)._control.Node_3 == 1) ) )
        {
            l84: if (  ( (((*in).Node_3.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( (((*in).Node_3.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
        }
        l86: if (  ( ((*in)._control.Node_3 == 4) ) )
        {
            l87: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
            l88: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
        }
        l89: if (  ( ((*in)._control.Node_4 == 3) ) )
        {
            l90: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
        }
        l91: if (  ( ((*in)._control.Node_4 == 2) ) )
        {
            l92: if (  ( (((*in).Node_4.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
        }
        l94: if (  ( ((*in)._control.Node_4 == 0) ) )
        {
            l95: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
        }
        l97: if (  ( ((*in)._control.Node_4 == 5) ) )
        {
            l98: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
        }
        l99: if (  ( ((*in)._control.Node_4 == 1) ) )
        {
            l100: if (  ( (((*in).Node_4.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
            l101: if (  ( (((*in).Node_4.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
        }
        l102: if (  ( ((*in)._control.Node_4 == 4) ) )
        {
            l103: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
        }
        l105: if (  ( ((*in)._control.Node_5 == 3) ) )
        {
            l106: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
        }
        l107: if (  ( ((*in)._control.Node_5 == 2) ) )
        {
            l108: if (  ( (((*in).Node_5.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
            l109: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
        }
        l110: if (  ( ((*in)._control.Node_5 == 0) ) )
        {
            l111: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
            l112: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
        }
        l113: if (  ( ((*in)._control.Node_5 == 5) ) )
        {
            l114: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
        }
        l115: if (  ( ((*in)._control.Node_5 == 1) ) )
        {
            l116: if (  ( (((*in).Node_5.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
            l117: if (  ( (((*in).Node_5.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 118;
            }
        }
        l118: if (  ( ((*in)._control.Node_5 == 4) ) )
        {
            l119: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
            l120: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
        }
        l121: if (  ( ((*in)._control.Node_6 == 3) ) )
        {
            l122: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
        }
        l123: if (  ( ((*in)._control.Node_6 == 2) ) )
        {
            l124: if (  ( (((*in).Node_6.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
            l125: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
        }
        l126: if (  ( ((*in)._control.Node_6 == 0) ) )
        {
            l127: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
            l128: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
        }
        l129: if (  ( ((*in)._control.Node_6 == 5) ) )
        {
            l130: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
        }
        l131: if (  ( ((*in)._control.Node_6 == 1) ) )
        {
            l132: if (  ( (((*in).Node_6.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( (((*in).Node_6.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
        }
        l134: if (  ( ((*in)._control.Node_6 == 4) ) )
        {
            l135: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
            l136: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 137;
            }
        }
        l137: if (  ( ((*in)._control.Node_7 == 3) ) )
        {
            l138: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
        }
        l139: if (  ( ((*in)._control.Node_7 == 2) ) )
        {
            l140: if (  ( (((*in).Node_7.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
            l141: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
        }
        l142: if (  ( ((*in)._control.Node_7 == 0) ) )
        {
            l143: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
        }
        l145: if (  ( ((*in)._control.Node_7 == 5) ) )
        {
            l146: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
        }
        l147: if (  ( ((*in)._control.Node_7 == 1) ) )
        {
            l148: if (  ( (((*in).Node_7.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 149;
            }
            l149: if (  ( (((*in).Node_7.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
        }
        l150: if (  ( ((*in)._control.Node_7 == 4) ) )
        {
            l151: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
            l152: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
        }
        l153: if (  ( ((*in)._control.Node_8 == 3) ) )
        {
            l154: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
        }
        l155: if (  ( ((*in)._control.Node_8 == 2) ) )
        {
            l156: if (  ( (((*in).Node_8.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
            l157: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
        }
        l158: if (  ( ((*in)._control.Node_8 == 0) ) )
        {
            l159: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 160;
            }
            l160: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 161;
            }
        }
        l161: if (  ( ((*in)._control.Node_8 == 5) ) )
        {
            l162: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 163;
            }
        }
        l163: if (  ( ((*in)._control.Node_8 == 1) ) )
        {
            l164: if (  ( (((*in).Node_8.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 165;
            }
            l165: if (  ( (((*in).Node_8.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 166;
            }
        }
        l166: if (  ( ((*in)._control.Node_8 == 4) ) )
        {
            l167: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 168;
            }
            l168: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
        }
        l169: if (  ( ((*in)._control.Token == 3) ) )
        {
            l170: if (  ( (((*in).Token.NRT_count == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 171;
            }
        }
        l171: if (  ( ((*in)._control.Token == 4) ) )
        {
            l172: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 173;
            }
            l173: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
            l174: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 175;
            }
            l175: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
            l176: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
            l177: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 178;
            }
            l178: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 179;
            }
            l179: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 180;
            }
            l180: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
        }
        l181: if (  ( ((*in)._control.Token == 1) ) )
        {
            l182: if (  ( ((((*in).Token.i < 9) && ((*in).in_RT[ (*in).Token.i ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
            l183: if (  ( (((*in).Token.i == 9)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 184;
            }
        }
        l184: if (  ( ((*in)._control.Token == 2) ) )
        {
            l185: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 186;
            }
            l186: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 187;
            }
            l187: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 188;
            }
            l188: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 189;
            }
            l189: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 190;
            }
            l190: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 191;
            }
            l191: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 192;
            }
            l192: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 193;
            }
            l193: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 194;
            }
        }
        l194: if (  ( ((*in)._control.Token == 5) ) )
        {
            l195: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((5 - (*out).RT_count));
                system_in_deadlock = false;
                *to = blob_out;
                return 196;
            }
        }
        l196: if (  ( ((*in)._control.Token == 0) ) )
        {
            l197: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 198;
            }
        }
    }
    l198: if (  ( system_in_deadlock ) )
    {
    }
    l199: return 0;
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
        case 185: goto l185;
        case 186: goto l186;
        case 187: goto l187;
        case 188: goto l188;
        case 189: goto l189;
        case 190: goto l190;
        case 191: goto l191;
        case 192: goto l192;
        case 193: goto l193;
        case 194: goto l194;
        case 195: goto l195;
        case 196: goto l196;
        case 197: goto l197;
        case 198: goto l198;
        case 199: goto l199;
    }
}
int get_successor1( const cesmi_setup *setup, int next_state, cesmi_node from, cesmi_node *to ) 
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
        l3: if (  ( ((*in)._control.Bandwidth == 0) ) )
        {
            l4: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_0 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_0 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_0 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_1 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_1 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_1 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_2 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_2 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_2 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_3 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_3 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_3 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_4 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_4 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_4 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_5 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_5 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_5 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((*in)._control.Node_6 == 3) )  &&  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_6 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.Node_6 == 3) )  &&  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_6 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((*in)._control.Node_6 == 3) )  &&  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_6 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( ((*in)._control.Node_7 == 3) )  &&  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_7 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((*in)._control.Node_7 == 3) )  &&  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_7 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((*in)._control.Node_7 == 3) )  &&  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_7 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((*in)._control.Node_8 == 3) )  &&  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_8 = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( ((*in)._control.Node_8 == 3) )  &&  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_8 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if (  ( ((*in)._control.Node_8 == 3) )  &&  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_8 = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( ((*in)._control.Node_0 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((*in)._control.Node_0 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((*in)._control.Node_0 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( ((*in)._control.Node_1 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( ((*in)._control.Node_1 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( ((*in)._control.Node_1 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((*in)._control.Node_2 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( ((*in)._control.Node_2 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( ((*in)._control.Node_2 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((*in)._control.Node_3 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( ((*in)._control.Node_3 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( ((*in)._control.Node_3 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( ((*in)._control.Node_4 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((*in)._control.Node_4 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((*in)._control.Node_4 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( ((*in)._control.Node_5 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( ((*in)._control.Node_5 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((*in)._control.Node_5 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
            l49: if (  ( ((*in)._control.Node_6 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( ((*in)._control.Node_6 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((*in)._control.Node_6 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( ((*in)._control.Node_7 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( ((*in)._control.Node_7 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( ((*in)._control.Node_7 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((*in)._control.Node_8 == 2) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( ((*in)._control.Node_8 == 2) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((*in)._control.Node_8 == 2) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
        }
        l58: if (  ( ((*in)._control.Bandwidth == 1) ) )
        {
            l59: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.Node_0 == 3) ) )
        {
            l66: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
        }
        l69: if (  ( ((*in)._control.Node_0 == 2) ) )
        {
            l70: if (  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( (((*in).Node_0.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
            l75: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
        }
        l76: if (  ( ((*in)._control.Node_0 == 0) ) )
        {
            l77: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
            l81: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
        }
        l83: if (  ( ((*in)._control.Node_0 == 5) ) )
        {
            l84: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
        }
        l87: if (  ( ((*in)._control.Node_0 == 1) ) )
        {
            l88: if (  ( (((*in).Node_0.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( (((*in).Node_0.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
            l90: if (  ( (((*in).Node_0.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
            l91: if (  ( (((*in).Node_0.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( (((*in).Node_0.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if (  ( (((*in).Node_0.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
        }
        l94: if (  ( ((*in)._control.Node_0 == 4) ) )
        {
            l95: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
            l97: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 98;
            }
            l98: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
            l99: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
            l100: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
        }
        l101: if (  ( ((*in)._control.Node_1 == 3) ) )
        {
            l102: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
            l103: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
        }
        l105: if (  ( ((*in)._control.Node_1 == 2) ) )
        {
            l106: if (  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
            l107: if (  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
            l108: if (  ( (((*in).Node_1.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
            l109: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
            l110: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
            l111: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
        }
        l112: if (  ( ((*in)._control.Node_1 == 0) ) )
        {
            l113: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 114;
            }
            l114: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
            l115: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
            l116: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
            l117: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 118;
            }
            l118: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
        }
        l119: if (  ( ((*in)._control.Node_1 == 5) ) )
        {
            l120: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
            l121: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
            l122: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
        }
        l123: if (  ( ((*in)._control.Node_1 == 1) ) )
        {
            l124: if (  ( (((*in).Node_1.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
            l125: if (  ( (((*in).Node_1.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
            l126: if (  ( (((*in).Node_1.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
            l127: if (  ( (((*in).Node_1.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
            l128: if (  ( (((*in).Node_1.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
            l129: if (  ( (((*in).Node_1.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
        }
        l130: if (  ( ((*in)._control.Node_1 == 4) ) )
        {
            l131: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
            l134: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
            l136: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 137;
            }
        }
        l137: if (  ( ((*in)._control.Node_2 == 3) ) )
        {
            l138: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
            l139: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 140;
            }
            l140: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
        }
        l141: if (  ( ((*in)._control.Node_2 == 2) ) )
        {
            l142: if (  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
            l143: if (  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( (((*in).Node_2.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
            l145: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
            l146: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
            l147: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
        }
        l148: if (  ( ((*in)._control.Node_2 == 0) ) )
        {
            l149: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
            l150: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
            l151: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
            l152: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
            l153: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 154;
            }
            l154: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
        }
        l155: if (  ( ((*in)._control.Node_2 == 5) ) )
        {
            l156: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
            l157: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
            l158: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 159;
            }
        }
        l159: if (  ( ((*in)._control.Node_2 == 1) ) )
        {
            l160: if (  ( (((*in).Node_2.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 161;
            }
            l161: if (  ( (((*in).Node_2.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 162;
            }
            l162: if (  ( (((*in).Node_2.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 163;
            }
            l163: if (  ( (((*in).Node_2.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
            l164: if (  ( (((*in).Node_2.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 165;
            }
            l165: if (  ( (((*in).Node_2.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 166;
            }
        }
        l166: if (  ( ((*in)._control.Node_2 == 4) ) )
        {
            l167: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 168;
            }
            l168: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
            l169: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 170;
            }
            l170: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 171;
            }
            l171: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 172;
            }
            l172: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 173;
            }
        }
        l173: if (  ( ((*in)._control.Node_3 == 3) ) )
        {
            l174: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 175;
            }
            l175: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
            l176: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
        }
        l177: if (  ( ((*in)._control.Node_3 == 2) ) )
        {
            l178: if (  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 179;
            }
            l179: if (  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 180;
            }
            l180: if (  ( (((*in).Node_3.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
            l181: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 182;
            }
            l182: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
            l183: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 184;
            }
        }
        l184: if (  ( ((*in)._control.Node_3 == 0) ) )
        {
            l185: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 186;
            }
            l186: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 187;
            }
            l187: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 188;
            }
            l188: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 189;
            }
            l189: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 190;
            }
            l190: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 191;
            }
        }
        l191: if (  ( ((*in)._control.Node_3 == 5) ) )
        {
            l192: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 193;
            }
            l193: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 194;
            }
            l194: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 195;
            }
        }
        l195: if (  ( ((*in)._control.Node_3 == 1) ) )
        {
            l196: if (  ( (((*in).Node_3.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 197;
            }
            l197: if (  ( (((*in).Node_3.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 198;
            }
            l198: if (  ( (((*in).Node_3.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 199;
            }
            l199: if (  ( (((*in).Node_3.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 200;
            }
            l200: if (  ( (((*in).Node_3.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 201;
            }
            l201: if (  ( (((*in).Node_3.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 202;
            }
        }
        l202: if (  ( ((*in)._control.Node_3 == 4) ) )
        {
            l203: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 204;
            }
            l204: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 205;
            }
            l205: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 206;
            }
            l206: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 207;
            }
            l207: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 208;
            }
            l208: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 209;
            }
        }
        l209: if (  ( ((*in)._control.Node_4 == 3) ) )
        {
            l210: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 211;
            }
            l211: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 212;
            }
            l212: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 213;
            }
        }
        l213: if (  ( ((*in)._control.Node_4 == 2) ) )
        {
            l214: if (  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 215;
            }
            l215: if (  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 216;
            }
            l216: if (  ( (((*in).Node_4.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 217;
            }
            l217: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 218;
            }
            l218: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 219;
            }
            l219: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 220;
            }
        }
        l220: if (  ( ((*in)._control.Node_4 == 0) ) )
        {
            l221: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 222;
            }
            l222: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 223;
            }
            l223: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 224;
            }
            l224: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 225;
            }
            l225: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 226;
            }
            l226: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 227;
            }
        }
        l227: if (  ( ((*in)._control.Node_4 == 5) ) )
        {
            l228: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 229;
            }
            l229: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 230;
            }
            l230: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 231;
            }
        }
        l231: if (  ( ((*in)._control.Node_4 == 1) ) )
        {
            l232: if (  ( (((*in).Node_4.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 233;
            }
            l233: if (  ( (((*in).Node_4.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 234;
            }
            l234: if (  ( (((*in).Node_4.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 235;
            }
            l235: if (  ( (((*in).Node_4.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 236;
            }
            l236: if (  ( (((*in).Node_4.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 237;
            }
            l237: if (  ( (((*in).Node_4.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 238;
            }
        }
        l238: if (  ( ((*in)._control.Node_4 == 4) ) )
        {
            l239: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 240;
            }
            l240: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 241;
            }
            l241: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 242;
            }
            l242: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 243;
            }
            l243: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 244;
            }
            l244: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 245;
            }
        }
        l245: if (  ( ((*in)._control.Node_5 == 3) ) )
        {
            l246: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 247;
            }
            l247: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 248;
            }
            l248: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 249;
            }
        }
        l249: if (  ( ((*in)._control.Node_5 == 2) ) )
        {
            l250: if (  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 251;
            }
            l251: if (  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 252;
            }
            l252: if (  ( (((*in).Node_5.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 253;
            }
            l253: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 254;
            }
            l254: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 255;
            }
            l255: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 256;
            }
        }
        l256: if (  ( ((*in)._control.Node_5 == 0) ) )
        {
            l257: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 258;
            }
            l258: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 259;
            }
            l259: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 260;
            }
            l260: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 261;
            }
            l261: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 262;
            }
            l262: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 263;
            }
        }
        l263: if (  ( ((*in)._control.Node_5 == 5) ) )
        {
            l264: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 265;
            }
            l265: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 266;
            }
            l266: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 267;
            }
        }
        l267: if (  ( ((*in)._control.Node_5 == 1) ) )
        {
            l268: if (  ( (((*in).Node_5.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 269;
            }
            l269: if (  ( (((*in).Node_5.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 270;
            }
            l270: if (  ( (((*in).Node_5.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 271;
            }
            l271: if (  ( (((*in).Node_5.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 272;
            }
            l272: if (  ( (((*in).Node_5.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 273;
            }
            l273: if (  ( (((*in).Node_5.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 274;
            }
        }
        l274: if (  ( ((*in)._control.Node_5 == 4) ) )
        {
            l275: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 276;
            }
            l276: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 277;
            }
            l277: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 278;
            }
            l278: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 279;
            }
            l279: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 280;
            }
            l280: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 281;
            }
        }
        l281: if (  ( ((*in)._control.Node_6 == 3) ) )
        {
            l282: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 283;
            }
            l283: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 284;
            }
            l284: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 285;
            }
        }
        l285: if (  ( ((*in)._control.Node_6 == 2) ) )
        {
            l286: if (  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 287;
            }
            l287: if (  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 288;
            }
            l288: if (  ( (((*in).Node_6.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 289;
            }
            l289: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 290;
            }
            l290: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 291;
            }
            l291: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 292;
            }
        }
        l292: if (  ( ((*in)._control.Node_6 == 0) ) )
        {
            l293: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 294;
            }
            l294: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 295;
            }
            l295: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 296;
            }
            l296: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 297;
            }
            l297: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 298;
            }
            l298: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 299;
            }
        }
        l299: if (  ( ((*in)._control.Node_6 == 5) ) )
        {
            l300: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 301;
            }
            l301: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 302;
            }
            l302: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 303;
            }
        }
        l303: if (  ( ((*in)._control.Node_6 == 1) ) )
        {
            l304: if (  ( (((*in).Node_6.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 305;
            }
            l305: if (  ( (((*in).Node_6.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 306;
            }
            l306: if (  ( (((*in).Node_6.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 307;
            }
            l307: if (  ( (((*in).Node_6.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 308;
            }
            l308: if (  ( (((*in).Node_6.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 309;
            }
            l309: if (  ( (((*in).Node_6.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 310;
            }
        }
        l310: if (  ( ((*in)._control.Node_6 == 4) ) )
        {
            l311: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 312;
            }
            l312: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 313;
            }
            l313: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 314;
            }
            l314: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 315;
            }
            l315: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 316;
            }
            l316: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 317;
            }
        }
        l317: if (  ( ((*in)._control.Node_7 == 3) ) )
        {
            l318: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 319;
            }
            l319: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 320;
            }
            l320: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 321;
            }
        }
        l321: if (  ( ((*in)._control.Node_7 == 2) ) )
        {
            l322: if (  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 323;
            }
            l323: if (  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 324;
            }
            l324: if (  ( (((*in).Node_7.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 325;
            }
            l325: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 326;
            }
            l326: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 327;
            }
            l327: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 328;
            }
        }
        l328: if (  ( ((*in)._control.Node_7 == 0) ) )
        {
            l329: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 330;
            }
            l330: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 331;
            }
            l331: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 332;
            }
            l332: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 333;
            }
            l333: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 334;
            }
            l334: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 335;
            }
        }
        l335: if (  ( ((*in)._control.Node_7 == 5) ) )
        {
            l336: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 337;
            }
            l337: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 338;
            }
            l338: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 339;
            }
        }
        l339: if (  ( ((*in)._control.Node_7 == 1) ) )
        {
            l340: if (  ( (((*in).Node_7.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 341;
            }
            l341: if (  ( (((*in).Node_7.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 342;
            }
            l342: if (  ( (((*in).Node_7.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 343;
            }
            l343: if (  ( (((*in).Node_7.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 344;
            }
            l344: if (  ( (((*in).Node_7.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 345;
            }
            l345: if (  ( (((*in).Node_7.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 346;
            }
        }
        l346: if (  ( ((*in)._control.Node_7 == 4) ) )
        {
            l347: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 348;
            }
            l348: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 349;
            }
            l349: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 350;
            }
            l350: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 351;
            }
            l351: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 352;
            }
            l352: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 353;
            }
        }
        l353: if (  ( ((*in)._control.Node_8 == 3) ) )
        {
            l354: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 355;
            }
            l355: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 356;
            }
            l356: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 357;
            }
        }
        l357: if (  ( ((*in)._control.Node_8 == 2) ) )
        {
            l358: if (  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 359;
            }
            l359: if (  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 360;
            }
            l360: if (  ( (((*in).Node_8.granted == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 361;
            }
            l361: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 362;
            }
            l362: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 363;
            }
            l363: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 364;
            }
        }
        l364: if (  ( ((*in)._control.Node_8 == 0) ) )
        {
            l365: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 366;
            }
            l366: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 367;
            }
            l367: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 368;
            }
            l368: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 369;
            }
            l369: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 370;
            }
            l370: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 371;
            }
        }
        l371: if (  ( ((*in)._control.Node_8 == 5) ) )
        {
            l372: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 373;
            }
            l373: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 374;
            }
            l374: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 375;
            }
        }
        l375: if (  ( ((*in)._control.Node_8 == 1) ) )
        {
            l376: if (  ( (((*in).Node_8.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 377;
            }
            l377: if (  ( (((*in).Node_8.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 378;
            }
            l378: if (  ( (((*in).Node_8.rt == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 379;
            }
            l379: if (  ( (((*in).Node_8.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 380;
            }
            l380: if (  ( (((*in).Node_8.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 381;
            }
            l381: if (  ( (((*in).Node_8.rt == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 382;
            }
        }
        l382: if (  ( ((*in)._control.Node_8 == 4) ) )
        {
            l383: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 384;
            }
            l384: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 385;
            }
            l385: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 386;
            }
            l386: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 387;
            }
            l387: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 388;
            }
            l388: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 389;
            }
        }
        l389: if (  ( ((*in)._control.Token == 3) ) )
        {
            l390: if (  ( (((*in).Token.NRT_count == 0)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 391;
            }
            l391: if (  ( (((*in).Token.NRT_count == 0)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 392;
            }
            l392: if (  ( (((*in).Token.NRT_count == 0)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 393;
            }
        }
        l393: if (  ( ((*in)._control.Token == 4) ) )
        {
            l394: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 395;
            }
            l395: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 396;
            }
            l396: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 397;
            }
            l397: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 398;
            }
            l398: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 399;
            }
            l399: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 400;
            }
            l400: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 401;
            }
            l401: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 402;
            }
            l402: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 403;
            }
            l403: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 404;
            }
            l404: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 405;
            }
            l405: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 406;
            }
            l406: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 407;
            }
            l407: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 408;
            }
            l408: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 409;
            }
            l409: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 410;
            }
            l410: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 411;
            }
            l411: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 412;
            }
            l412: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 413;
            }
            l413: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 414;
            }
            l414: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 415;
            }
            l415: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 416;
            }
            l416: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 417;
            }
            l417: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 418;
            }
            l418: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 419;
            }
            l419: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 420;
            }
            l420: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 9));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 421;
            }
        }
        l421: if (  ( ((*in)._control.Token == 1) ) )
        {
            l422: if (  ( ((((*in).Token.i < 9) && ((*in).in_RT[ (*in).Token.i ] == 0))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 423;
            }
            l423: if (  ( ((((*in).Token.i < 9) && ((*in).in_RT[ (*in).Token.i ] == 0))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 424;
            }
            l424: if (  ( ((((*in).Token.i < 9) && ((*in).in_RT[ (*in).Token.i ] == 0))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 425;
            }
            l425: if (  ( (((*in).Token.i == 9)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 426;
            }
            l426: if (  ( (((*in).Token.i == 9)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 427;
            }
            l427: if (  ( (((*in).Token.i == 9)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 428;
            }
        }
        l428: if (  ( ((*in)._control.Token == 2) ) )
        {
            l429: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 430;
            }
            l430: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 431;
            }
            l431: if (  ( ((*in)._control.Node_0 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 432;
            }
            l432: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 433;
            }
            l433: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 434;
            }
            l434: if (  ( ((*in)._control.Node_1 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 435;
            }
            l435: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 436;
            }
            l436: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 437;
            }
            l437: if (  ( ((*in)._control.Node_2 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 438;
            }
            l438: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 439;
            }
            l439: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 440;
            }
            l440: if (  ( ((*in)._control.Node_3 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 441;
            }
            l441: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 442;
            }
            l442: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 443;
            }
            l443: if (  ( ((*in)._control.Node_4 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 444;
            }
            l444: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 445;
            }
            l445: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 446;
            }
            l446: if (  ( ((*in)._control.Node_5 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 447;
            }
            l447: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 448;
            }
            l448: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 449;
            }
            l449: if (  ( ((*in)._control.Node_6 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 450;
            }
            l450: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 451;
            }
            l451: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 452;
            }
            l452: if (  ( ((*in)._control.Node_7 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 453;
            }
            l453: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 454;
            }
            l454: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 455;
            }
            l455: if (  ( ((*in)._control.Node_8 == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 456;
            }
        }
        l456: if (  ( ((*in)._control.Token == 5) ) )
        {
            l457: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((5 - (*out).RT_count));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 458;
            }
            l458: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((5 - (*out).RT_count));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 459;
            }
            l459: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((5 - (*out).RT_count));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 460;
            }
        }
        l460: if (  ( ((*in)._control.Token == 0) ) )
        {
            l461: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 462;
            }
            l462: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 463;
            }
            l463: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 464;
            }
        }
    }
    l464: if (  ( system_in_deadlock ) )
    {
        l465: if (  ( ((*in)._control.LTL_property == 0) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 0;
            *to = blob_out;
            return 466;
        }
        l466: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 1;
            *to = blob_out;
            return 467;
        }
        l467: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Node_0 == 2)) )) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 1;
            *to = blob_out;
            return 468;
        }
    }
    l468: return 0;
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
        case 185: goto l185;
        case 186: goto l186;
        case 187: goto l187;
        case 188: goto l188;
        case 189: goto l189;
        case 190: goto l190;
        case 191: goto l191;
        case 192: goto l192;
        case 193: goto l193;
        case 194: goto l194;
        case 195: goto l195;
        case 196: goto l196;
        case 197: goto l197;
        case 198: goto l198;
        case 199: goto l199;
        case 200: goto l200;
        case 201: goto l201;
        case 202: goto l202;
        case 203: goto l203;
        case 204: goto l204;
        case 205: goto l205;
        case 206: goto l206;
        case 207: goto l207;
        case 208: goto l208;
        case 209: goto l209;
        case 210: goto l210;
        case 211: goto l211;
        case 212: goto l212;
        case 213: goto l213;
        case 214: goto l214;
        case 215: goto l215;
        case 216: goto l216;
        case 217: goto l217;
        case 218: goto l218;
        case 219: goto l219;
        case 220: goto l220;
        case 221: goto l221;
        case 222: goto l222;
        case 223: goto l223;
        case 224: goto l224;
        case 225: goto l225;
        case 226: goto l226;
        case 227: goto l227;
        case 228: goto l228;
        case 229: goto l229;
        case 230: goto l230;
        case 231: goto l231;
        case 232: goto l232;
        case 233: goto l233;
        case 234: goto l234;
        case 235: goto l235;
        case 236: goto l236;
        case 237: goto l237;
        case 238: goto l238;
        case 239: goto l239;
        case 240: goto l240;
        case 241: goto l241;
        case 242: goto l242;
        case 243: goto l243;
        case 244: goto l244;
        case 245: goto l245;
        case 246: goto l246;
        case 247: goto l247;
        case 248: goto l248;
        case 249: goto l249;
        case 250: goto l250;
        case 251: goto l251;
        case 252: goto l252;
        case 253: goto l253;
        case 254: goto l254;
        case 255: goto l255;
        case 256: goto l256;
        case 257: goto l257;
        case 258: goto l258;
        case 259: goto l259;
        case 260: goto l260;
        case 261: goto l261;
        case 262: goto l262;
        case 263: goto l263;
        case 264: goto l264;
        case 265: goto l265;
        case 266: goto l266;
        case 267: goto l267;
        case 268: goto l268;
        case 269: goto l269;
        case 270: goto l270;
        case 271: goto l271;
        case 272: goto l272;
        case 273: goto l273;
        case 274: goto l274;
        case 275: goto l275;
        case 276: goto l276;
        case 277: goto l277;
        case 278: goto l278;
        case 279: goto l279;
        case 280: goto l280;
        case 281: goto l281;
        case 282: goto l282;
        case 283: goto l283;
        case 284: goto l284;
        case 285: goto l285;
        case 286: goto l286;
        case 287: goto l287;
        case 288: goto l288;
        case 289: goto l289;
        case 290: goto l290;
        case 291: goto l291;
        case 292: goto l292;
        case 293: goto l293;
        case 294: goto l294;
        case 295: goto l295;
        case 296: goto l296;
        case 297: goto l297;
        case 298: goto l298;
        case 299: goto l299;
        case 300: goto l300;
        case 301: goto l301;
        case 302: goto l302;
        case 303: goto l303;
        case 304: goto l304;
        case 305: goto l305;
        case 306: goto l306;
        case 307: goto l307;
        case 308: goto l308;
        case 309: goto l309;
        case 310: goto l310;
        case 311: goto l311;
        case 312: goto l312;
        case 313: goto l313;
        case 314: goto l314;
        case 315: goto l315;
        case 316: goto l316;
        case 317: goto l317;
        case 318: goto l318;
        case 319: goto l319;
        case 320: goto l320;
        case 321: goto l321;
        case 322: goto l322;
        case 323: goto l323;
        case 324: goto l324;
        case 325: goto l325;
        case 326: goto l326;
        case 327: goto l327;
        case 328: goto l328;
        case 329: goto l329;
        case 330: goto l330;
        case 331: goto l331;
        case 332: goto l332;
        case 333: goto l333;
        case 334: goto l334;
        case 335: goto l335;
        case 336: goto l336;
        case 337: goto l337;
        case 338: goto l338;
        case 339: goto l339;
        case 340: goto l340;
        case 341: goto l341;
        case 342: goto l342;
        case 343: goto l343;
        case 344: goto l344;
        case 345: goto l345;
        case 346: goto l346;
        case 347: goto l347;
        case 348: goto l348;
        case 349: goto l349;
        case 350: goto l350;
        case 351: goto l351;
        case 352: goto l352;
        case 353: goto l353;
        case 354: goto l354;
        case 355: goto l355;
        case 356: goto l356;
        case 357: goto l357;
        case 358: goto l358;
        case 359: goto l359;
        case 360: goto l360;
        case 361: goto l361;
        case 362: goto l362;
        case 363: goto l363;
        case 364: goto l364;
        case 365: goto l365;
        case 366: goto l366;
        case 367: goto l367;
        case 368: goto l368;
        case 369: goto l369;
        case 370: goto l370;
        case 371: goto l371;
        case 372: goto l372;
        case 373: goto l373;
        case 374: goto l374;
        case 375: goto l375;
        case 376: goto l376;
        case 377: goto l377;
        case 378: goto l378;
        case 379: goto l379;
        case 380: goto l380;
        case 381: goto l381;
        case 382: goto l382;
        case 383: goto l383;
        case 384: goto l384;
        case 385: goto l385;
        case 386: goto l386;
        case 387: goto l387;
        case 388: goto l388;
        case 389: goto l389;
        case 390: goto l390;
        case 391: goto l391;
        case 392: goto l392;
        case 393: goto l393;
        case 394: goto l394;
        case 395: goto l395;
        case 396: goto l396;
        case 397: goto l397;
        case 398: goto l398;
        case 399: goto l399;
        case 400: goto l400;
        case 401: goto l401;
        case 402: goto l402;
        case 403: goto l403;
        case 404: goto l404;
        case 405: goto l405;
        case 406: goto l406;
        case 407: goto l407;
        case 408: goto l408;
        case 409: goto l409;
        case 410: goto l410;
        case 411: goto l411;
        case 412: goto l412;
        case 413: goto l413;
        case 414: goto l414;
        case 415: goto l415;
        case 416: goto l416;
        case 417: goto l417;
        case 418: goto l418;
        case 419: goto l419;
        case 420: goto l420;
        case 421: goto l421;
        case 422: goto l422;
        case 423: goto l423;
        case 424: goto l424;
        case 425: goto l425;
        case 426: goto l426;
        case 427: goto l427;
        case 428: goto l428;
        case 429: goto l429;
        case 430: goto l430;
        case 431: goto l431;
        case 432: goto l432;
        case 433: goto l433;
        case 434: goto l434;
        case 435: goto l435;
        case 436: goto l436;
        case 437: goto l437;
        case 438: goto l438;
        case 439: goto l439;
        case 440: goto l440;
        case 441: goto l441;
        case 442: goto l442;
        case 443: goto l443;
        case 444: goto l444;
        case 445: goto l445;
        case 446: goto l446;
        case 447: goto l447;
        case 448: goto l448;
        case 449: goto l449;
        case 450: goto l450;
        case 451: goto l451;
        case 452: goto l452;
        case 453: goto l453;
        case 454: goto l454;
        case 455: goto l455;
        case 456: goto l456;
        case 457: goto l457;
        case 458: goto l458;
        case 459: goto l459;
        case 460: goto l460;
        case 461: goto l461;
        case 462: goto l462;
        case 463: goto l463;
        case 464: goto l464;
        case 465: goto l465;
        case 466: goto l466;
        case 467: goto l467;
        case 468: goto l468;
    }
}
int get_successor( const cesmi_setup *setup, int next_state, cesmi_node from, cesmi_node *to ) 
{
    switch ( setup->property )
    {
        case 0: 
        case 1:
        return get_successor0( setup, next_state, from, to );
        case 2:
        return get_successor1( setup, next_state, from, to );
    }
}
