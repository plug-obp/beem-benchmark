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
        uint16_t Node_9:4;
        uint16_t Token:3;
    }
    __attribute__((__packed__)) _control;
    uint8_t in_RT[10];
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
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_9;
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
    _out.Node_9.granted = 0;
    _out._control.Node_9 = 0;
    _out.Token.NRT_count = 4;
    _out.Token.next = 0;
    _out._control.Token = 0;
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
            l13: if (  ( ((*in)._control.Node_9 == 3) )  &&  ( (((*in).Node_9.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (9);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_9 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((*in)._control.Node_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (0);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_0 = 8;
                ((*out).Node_0.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.Node_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (1);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_1 = 8;
                ((*out).Node_1.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.Node_2 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (2);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_2 = 8;
                ((*out).Node_2.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.Node_3 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (3);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_3 = 8;
                ((*out).Node_3.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Node_4 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (4);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_4 = 8;
                ((*out).Node_4.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Node_5 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (5);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_5 = 8;
                ((*out).Node_5.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.Node_6 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (6);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_6 = 8;
                ((*out).Node_6.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.Node_7 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (7);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_7 = 8;
                ((*out).Node_7.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((*in)._control.Node_8 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (8);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_8 = 8;
                ((*out).Node_8.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.Node_9 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (9);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_9 = 8;
                ((*out).Node_9.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
        }
        l24: if (  ( ((*in)._control.Bandwidth == 1) ) )
        {
            l25: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
        }
        l26: if (  ( ((*in)._control.Node_0 == 3) ) )
        {
            l27: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
        }
        l28: if (  ( ((*in)._control.Node_0 == 2) ) )
        {
            l29: if (  ( (((*in).Node_0.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
        }
        l31: if (  ( ((*in)._control.Node_0 == 0) ) )
        {
            l32: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.Node_0 == 5) ) )
        {
            l35: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
        }
        l36: if (  ( ((*in)._control.Node_0 == 1) ) )
        {
            l37: if (  ( (((*in).Node_0.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( (((*in).Node_0.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
        }
        l39: if (  ( ((*in)._control.Node_0 == 8) ) )
        {
            l40: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.Node_0 == 4) ) )
        {
            l42: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 43;
            }
            l43: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
        }
        l44: if (  ( ((*in)._control.Node_1 == 3) ) )
        {
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
        l46: if (  ( ((*in)._control.Node_1 == 2) ) )
        {
            l47: if (  ( (((*in).Node_1.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.Node_1 == 0) ) )
        {
            l50: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
        }
        l52: if (  ( ((*in)._control.Node_1 == 5) ) )
        {
            l53: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.Node_1 == 1) ) )
        {
            l55: if (  ( (((*in).Node_1.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( (((*in).Node_1.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
        }
        l57: if (  ( ((*in)._control.Node_1 == 8) ) )
        {
            l58: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
        }
        l59: if (  ( ((*in)._control.Node_1 == 4) ) )
        {
            l60: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 61;
            }
            l61: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
        l62: if (  ( ((*in)._control.Node_2 == 3) ) )
        {
            l63: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
        }
        l64: if (  ( ((*in)._control.Node_2 == 2) ) )
        {
            l65: if (  ( (((*in).Node_2.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
            l66: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
        }
        l67: if (  ( ((*in)._control.Node_2 == 0) ) )
        {
            l68: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
        }
        l70: if (  ( ((*in)._control.Node_2 == 5) ) )
        {
            l71: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
        }
        l72: if (  ( ((*in)._control.Node_2 == 1) ) )
        {
            l73: if (  ( (((*in).Node_2.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( (((*in).Node_2.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
        }
        l75: if (  ( ((*in)._control.Node_2 == 8) ) )
        {
            l76: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
        }
        l77: if (  ( ((*in)._control.Node_2 == 4) ) )
        {
            l78: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 79;
            }
            l79: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
        }
        l80: if (  ( ((*in)._control.Node_3 == 3) ) )
        {
            l81: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
        }
        l82: if (  ( ((*in)._control.Node_3 == 2) ) )
        {
            l83: if (  ( (((*in).Node_3.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
        }
        l85: if (  ( ((*in)._control.Node_3 == 0) ) )
        {
            l86: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
            l87: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
        }
        l88: if (  ( ((*in)._control.Node_3 == 5) ) )
        {
            l89: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
        }
        l90: if (  ( ((*in)._control.Node_3 == 1) ) )
        {
            l91: if (  ( (((*in).Node_3.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( (((*in).Node_3.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
        }
        l93: if (  ( ((*in)._control.Node_3 == 8) ) )
        {
            l94: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
        }
        l95: if (  ( ((*in)._control.Node_3 == 4) ) )
        {
            l96: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 97;
            }
            l97: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 98;
            }
        }
        l98: if (  ( ((*in)._control.Node_4 == 3) ) )
        {
            l99: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
        }
        l100: if (  ( ((*in)._control.Node_4 == 2) ) )
        {
            l101: if (  ( (((*in).Node_4.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
            l102: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
        }
        l103: if (  ( ((*in)._control.Node_4 == 0) ) )
        {
            l104: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
        }
        l106: if (  ( ((*in)._control.Node_4 == 5) ) )
        {
            l107: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
        }
        l108: if (  ( ((*in)._control.Node_4 == 1) ) )
        {
            l109: if (  ( (((*in).Node_4.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
            l110: if (  ( (((*in).Node_4.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
        }
        l111: if (  ( ((*in)._control.Node_4 == 8) ) )
        {
            l112: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
        }
        l113: if (  ( ((*in)._control.Node_4 == 4) ) )
        {
            l114: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 115;
            }
            l115: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
        }
        l116: if (  ( ((*in)._control.Node_5 == 3) ) )
        {
            l117: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 118;
            }
        }
        l118: if (  ( ((*in)._control.Node_5 == 2) ) )
        {
            l119: if (  ( (((*in).Node_5.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
            l120: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
        }
        l121: if (  ( ((*in)._control.Node_5 == 0) ) )
        {
            l122: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
            l123: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
        }
        l124: if (  ( ((*in)._control.Node_5 == 5) ) )
        {
            l125: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
        }
        l126: if (  ( ((*in)._control.Node_5 == 1) ) )
        {
            l127: if (  ( (((*in).Node_5.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
            l128: if (  ( (((*in).Node_5.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
        }
        l129: if (  ( ((*in)._control.Node_5 == 8) ) )
        {
            l130: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
        }
        l131: if (  ( ((*in)._control.Node_5 == 4) ) )
        {
            l132: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 133;
            }
            l133: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
        }
        l134: if (  ( ((*in)._control.Node_6 == 3) ) )
        {
            l135: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
        }
        l136: if (  ( ((*in)._control.Node_6 == 2) ) )
        {
            l137: if (  ( (((*in).Node_6.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
            l138: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
        }
        l139: if (  ( ((*in)._control.Node_6 == 0) ) )
        {
            l140: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
            l141: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
        }
        l142: if (  ( ((*in)._control.Node_6 == 5) ) )
        {
            l143: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
        }
        l144: if (  ( ((*in)._control.Node_6 == 1) ) )
        {
            l145: if (  ( (((*in).Node_6.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
            l146: if (  ( (((*in).Node_6.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
        }
        l147: if (  ( ((*in)._control.Node_6 == 8) ) )
        {
            l148: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 149;
            }
        }
        l149: if (  ( ((*in)._control.Node_6 == 4) ) )
        {
            l150: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 151;
            }
            l151: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
        }
        l152: if (  ( ((*in)._control.Node_7 == 3) ) )
        {
            l153: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 154;
            }
        }
        l154: if (  ( ((*in)._control.Node_7 == 2) ) )
        {
            l155: if (  ( (((*in).Node_7.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 156;
            }
            l156: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
        }
        l157: if (  ( ((*in)._control.Node_7 == 0) ) )
        {
            l158: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 159;
            }
            l159: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 160;
            }
        }
        l160: if (  ( ((*in)._control.Node_7 == 5) ) )
        {
            l161: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 162;
            }
        }
        l162: if (  ( ((*in)._control.Node_7 == 1) ) )
        {
            l163: if (  ( (((*in).Node_7.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
            l164: if (  ( (((*in).Node_7.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 165;
            }
        }
        l165: if (  ( ((*in)._control.Node_7 == 8) ) )
        {
            l166: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 167;
            }
        }
        l167: if (  ( ((*in)._control.Node_7 == 4) ) )
        {
            l168: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 169;
            }
            l169: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 170;
            }
        }
        l170: if (  ( ((*in)._control.Node_8 == 3) ) )
        {
            l171: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 172;
            }
        }
        l172: if (  ( ((*in)._control.Node_8 == 2) ) )
        {
            l173: if (  ( (((*in).Node_8.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
            l174: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 175;
            }
        }
        l175: if (  ( ((*in)._control.Node_8 == 0) ) )
        {
            l176: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
            l177: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 178;
            }
        }
        l178: if (  ( ((*in)._control.Node_8 == 5) ) )
        {
            l179: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 180;
            }
        }
        l180: if (  ( ((*in)._control.Node_8 == 1) ) )
        {
            l181: if (  ( (((*in).Node_8.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 182;
            }
            l182: if (  ( (((*in).Node_8.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
        }
        l183: if (  ( ((*in)._control.Node_8 == 8) ) )
        {
            l184: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 185;
            }
        }
        l185: if (  ( ((*in)._control.Node_8 == 4) ) )
        {
            l186: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 187;
            }
            l187: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 188;
            }
        }
        l188: if (  ( ((*in)._control.Node_9 == 3) ) )
        {
            l189: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 190;
            }
        }
        l190: if (  ( ((*in)._control.Node_9 == 2) ) )
        {
            l191: if (  ( (((*in).Node_9.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 192;
            }
            l192: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 193;
            }
        }
        l193: if (  ( ((*in)._control.Node_9 == 0) ) )
        {
            l194: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 9) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_9.rt) = (1);
                (*out)._control.Node_9 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 195;
            }
            l195: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 9))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_9.rt) = (0);
                (*out)._control.Node_9 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 196;
            }
        }
        l196: if (  ( ((*in)._control.Node_9 == 5) ) )
        {
            l197: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                ((*out).Node_9.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 198;
            }
        }
        l198: if (  ( ((*in)._control.Node_9 == 1) ) )
        {
            l199: if (  ( (((*in).Node_9.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 200;
            }
            l200: if (  ( (((*in).Node_9.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 201;
            }
        }
        l201: if (  ( ((*in)._control.Node_9 == 8) ) )
        {
            l202: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 203;
            }
        }
        l203: if (  ( ((*in)._control.Node_9 == 4) ) )
        {
            l204: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 205;
            }
            l205: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 206;
            }
        }
        l206: if (  ( ((*in)._control.Token == 3) ) )
        {
            l207: if (  ( (((*in).Token.NRT_count == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 208;
            }
        }
        l208: if (  ( ((*in)._control.Token == 4) ) )
        {
            l209: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 210;
            }
            l210: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 211;
            }
            l211: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 212;
            }
            l212: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 213;
            }
            l213: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 214;
            }
            l214: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 215;
            }
            l215: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 216;
            }
            l216: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 217;
            }
            l217: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 218;
            }
            l218: if (  ( ((*in)._control.Node_9 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 10));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_9 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 219;
            }
        }
        l219: if (  ( ((*in)._control.Token == 1) ) )
        {
            l220: if (  ( ((((*in).Token.i < 10) && ((*in).in_RT[ (*in).Token.i ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 221;
            }
            l221: if (  ( (((*in).Token.i == 10)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 222;
            }
        }
        l222: if (  ( ((*in)._control.Token == 2) ) )
        {
            l223: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 224;
            }
            l224: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 225;
            }
            l225: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 226;
            }
            l226: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 227;
            }
            l227: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 228;
            }
            l228: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 229;
            }
            l229: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 230;
            }
            l230: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 231;
            }
            l231: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 232;
            }
            l232: if (  ( ((*in)._control.Node_9 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_9 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 233;
            }
        }
        l233: if (  ( ((*in)._control.Token == 5) ) )
        {
            l234: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((4 - (*out).RT_count));
                system_in_deadlock = false;
                *to = blob_out;
                return 235;
            }
        }
        l235: if (  ( ((*in)._control.Token == 0) ) )
        {
            l236: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 237;
            }
        }
    }
    l237: if (  ( system_in_deadlock ) )
    {
    }
    l238: return 0;
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
