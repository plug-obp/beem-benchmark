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
        uint16_t Node_10:4;
        uint16_t Node_11:4;
        uint16_t Token:3;
    }
    __attribute__((__packed__)) _control;
    uint8_t in_RT[12];
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
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_10;
    struct
    {
        uint8_t rt;
        uint8_t granted;
    }
    __attribute__((__packed__)) Node_11;
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
    _out.Node_10.granted = 0;
    _out._control.Node_10 = 0;
    _out.Node_11.granted = 0;
    _out._control.Node_11 = 0;
    _out.Token.NRT_count = 6;
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
            l14: if (  ( ((*in)._control.Node_10 == 3) )  &&  ( (((*in).Node_10.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (10);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_10 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.Node_11 == 3) )  &&  ( (((*in).Node_11.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (11);
                (*out)._control.Bandwidth = 2;
                (*out)._control.Node_11 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.Node_0 == 2) ) )
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
                return 17;
            }
            l17: if (  ( ((*in)._control.Node_1 == 2) ) )
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
                return 18;
            }
            l18: if (  ( ((*in)._control.Node_2 == 2) ) )
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
                return 19;
            }
            l19: if (  ( ((*in)._control.Node_3 == 2) ) )
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
                return 20;
            }
            l20: if (  ( ((*in)._control.Node_4 == 2) ) )
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
                return 21;
            }
            l21: if (  ( ((*in)._control.Node_5 == 2) ) )
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
                return 22;
            }
            l22: if (  ( ((*in)._control.Node_6 == 2) ) )
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
                return 23;
            }
            l23: if (  ( ((*in)._control.Node_7 == 2) ) )
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
                return 24;
            }
            l24: if (  ( ((*in)._control.Node_8 == 2) ) )
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
                return 25;
            }
            l25: if (  ( ((*in)._control.Node_9 == 2) ) )
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
                return 26;
            }
            l26: if (  ( ((*in)._control.Node_10 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (10);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_10 = 8;
                ((*out).Node_10.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((*in)._control.Node_11 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Bandwidth.i) = (11);
                (*out)._control.Bandwidth = 1;
                (*out)._control.Node_11 = 8;
                ((*out).Node_11.granted) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
        }
        l28: if (  ( ((*in)._control.Bandwidth == 1) ) )
        {
            l29: if (  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Bandwidth = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.Node_0 == 3) ) )
        {
            l31: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
        }
        l32: if (  ( ((*in)._control.Node_0 == 2) ) )
        {
            l33: if (  ( (((*in).Node_0.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
        }
        l35: if (  ( ((*in)._control.Node_0 == 0) ) )
        {
            l36: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 0) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (1);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.rt) = (0);
                (*out)._control.Node_0 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.Node_0 == 5) ) )
        {
            l39: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                ((*out).Node_0.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
        }
        l40: if (  ( ((*in)._control.Node_0 == 1) ) )
        {
            l41: if (  ( (((*in).Node_0.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( (((*in).Node_0.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
        }
        l43: if (  ( ((*in)._control.Node_0 == 8) ) )
        {
            l44: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 45;
            }
        }
        l45: if (  ( ((*in)._control.Node_0 == 4) ) )
        {
            l46: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 47;
            }
            l47: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
        }
        l48: if (  ( ((*in)._control.Node_1 == 3) ) )
        {
            l49: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
        }
        l50: if (  ( ((*in)._control.Node_1 == 2) ) )
        {
            l51: if (  ( (((*in).Node_1.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
        }
        l53: if (  ( ((*in)._control.Node_1 == 0) ) )
        {
            l54: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 1) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (1);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.rt) = (0);
                (*out)._control.Node_1 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
        }
        l56: if (  ( ((*in)._control.Node_1 == 5) ) )
        {
            l57: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                ((*out).Node_1.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
        }
        l58: if (  ( ((*in)._control.Node_1 == 1) ) )
        {
            l59: if (  ( (((*in).Node_1.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( (((*in).Node_1.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
        }
        l61: if (  ( ((*in)._control.Node_1 == 8) ) )
        {
            l62: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 63;
            }
        }
        l63: if (  ( ((*in)._control.Node_1 == 4) ) )
        {
            l64: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 65;
            }
            l65: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
        }
        l66: if (  ( ((*in)._control.Node_2 == 3) ) )
        {
            l67: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
        }
        l68: if (  ( ((*in)._control.Node_2 == 2) ) )
        {
            l69: if (  ( (((*in).Node_2.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
        }
        l71: if (  ( ((*in)._control.Node_2 == 0) ) )
        {
            l72: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 2) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (1);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 2))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.rt) = (0);
                (*out)._control.Node_2 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
        }
        l74: if (  ( ((*in)._control.Node_2 == 5) ) )
        {
            l75: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                ((*out).Node_2.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
        }
        l76: if (  ( ((*in)._control.Node_2 == 1) ) )
        {
            l77: if (  ( (((*in).Node_2.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( (((*in).Node_2.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
        }
        l79: if (  ( ((*in)._control.Node_2 == 8) ) )
        {
            l80: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 81;
            }
        }
        l81: if (  ( ((*in)._control.Node_2 == 4) ) )
        {
            l82: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 83;
            }
            l83: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
        }
        l84: if (  ( ((*in)._control.Node_3 == 3) ) )
        {
            l85: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
        }
        l86: if (  ( ((*in)._control.Node_3 == 2) ) )
        {
            l87: if (  ( (((*in).Node_3.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
            l88: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
        }
        l89: if (  ( ((*in)._control.Node_3 == 0) ) )
        {
            l90: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 3) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (1);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
            l91: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 3))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.rt) = (0);
                (*out)._control.Node_3 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
        }
        l92: if (  ( ((*in)._control.Node_3 == 5) ) )
        {
            l93: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                ((*out).Node_3.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
        }
        l94: if (  ( ((*in)._control.Node_3 == 1) ) )
        {
            l95: if (  ( (((*in).Node_3.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( (((*in).Node_3.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
        }
        l97: if (  ( ((*in)._control.Node_3 == 8) ) )
        {
            l98: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 99;
            }
        }
        l99: if (  ( ((*in)._control.Node_3 == 4) ) )
        {
            l100: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 101;
            }
            l101: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
        }
        l102: if (  ( ((*in)._control.Node_4 == 3) ) )
        {
            l103: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
        }
        l104: if (  ( ((*in)._control.Node_4 == 2) ) )
        {
            l105: if (  ( (((*in).Node_4.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
            l106: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
        }
        l107: if (  ( ((*in)._control.Node_4 == 0) ) )
        {
            l108: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 4) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (1);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
            l109: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.rt) = (0);
                (*out)._control.Node_4 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
        }
        l110: if (  ( ((*in)._control.Node_4 == 5) ) )
        {
            l111: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                ((*out).Node_4.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
        }
        l112: if (  ( ((*in)._control.Node_4 == 1) ) )
        {
            l113: if (  ( (((*in).Node_4.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 114;
            }
            l114: if (  ( (((*in).Node_4.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
        }
        l115: if (  ( ((*in)._control.Node_4 == 8) ) )
        {
            l116: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.Node_4 == 4) ) )
        {
            l118: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 119;
            }
            l119: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
        }
        l120: if (  ( ((*in)._control.Node_5 == 3) ) )
        {
            l121: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
        }
        l122: if (  ( ((*in)._control.Node_5 == 2) ) )
        {
            l123: if (  ( (((*in).Node_5.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
            l124: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
        }
        l125: if (  ( ((*in)._control.Node_5 == 0) ) )
        {
            l126: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 5) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (1);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
            l127: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.rt) = (0);
                (*out)._control.Node_5 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
        }
        l128: if (  ( ((*in)._control.Node_5 == 5) ) )
        {
            l129: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                ((*out).Node_5.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
        }
        l130: if (  ( ((*in)._control.Node_5 == 1) ) )
        {
            l131: if (  ( (((*in).Node_5.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( (((*in).Node_5.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
        }
        l133: if (  ( ((*in)._control.Node_5 == 8) ) )
        {
            l134: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 135;
            }
        }
        l135: if (  ( ((*in)._control.Node_5 == 4) ) )
        {
            l136: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 137;
            }
            l137: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
        }
        l138: if (  ( ((*in)._control.Node_6 == 3) ) )
        {
            l139: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 140;
            }
        }
        l140: if (  ( ((*in)._control.Node_6 == 2) ) )
        {
            l141: if (  ( (((*in).Node_6.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
            l142: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
        }
        l143: if (  ( ((*in)._control.Node_6 == 0) ) )
        {
            l144: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 6) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (1);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
            l145: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_6.rt) = (0);
                (*out)._control.Node_6 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
        }
        l146: if (  ( ((*in)._control.Node_6 == 5) ) )
        {
            l147: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                ((*out).Node_6.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
        }
        l148: if (  ( ((*in)._control.Node_6 == 1) ) )
        {
            l149: if (  ( (((*in).Node_6.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
            l150: if (  ( (((*in).Node_6.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
        }
        l151: if (  ( ((*in)._control.Node_6 == 8) ) )
        {
            l152: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 153;
            }
        }
        l153: if (  ( ((*in)._control.Node_6 == 4) ) )
        {
            l154: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 155;
            }
            l155: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_6 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 156;
            }
        }
        l156: if (  ( ((*in)._control.Node_7 == 3) ) )
        {
            l157: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
        }
        l158: if (  ( ((*in)._control.Node_7 == 2) ) )
        {
            l159: if (  ( (((*in).Node_7.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 160;
            }
            l160: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 161;
            }
        }
        l161: if (  ( ((*in)._control.Node_7 == 0) ) )
        {
            l162: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 7) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (1);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 163;
            }
            l163: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 7))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_7.rt) = (0);
                (*out)._control.Node_7 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
        }
        l164: if (  ( ((*in)._control.Node_7 == 5) ) )
        {
            l165: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                ((*out).Node_7.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 166;
            }
        }
        l166: if (  ( ((*in)._control.Node_7 == 1) ) )
        {
            l167: if (  ( (((*in).Node_7.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 168;
            }
            l168: if (  ( (((*in).Node_7.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
        }
        l169: if (  ( ((*in)._control.Node_7 == 8) ) )
        {
            l170: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 171;
            }
        }
        l171: if (  ( ((*in)._control.Node_7 == 4) ) )
        {
            l172: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 173;
            }
            l173: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_7 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
        }
        l174: if (  ( ((*in)._control.Node_8 == 3) ) )
        {
            l175: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
        }
        l176: if (  ( ((*in)._control.Node_8 == 2) ) )
        {
            l177: if (  ( (((*in).Node_8.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 178;
            }
            l178: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 179;
            }
        }
        l179: if (  ( ((*in)._control.Node_8 == 0) ) )
        {
            l180: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 8) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (1);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
            l181: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_8.rt) = (0);
                (*out)._control.Node_8 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 182;
            }
        }
        l182: if (  ( ((*in)._control.Node_8 == 5) ) )
        {
            l183: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                ((*out).Node_8.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 184;
            }
        }
        l184: if (  ( ((*in)._control.Node_8 == 1) ) )
        {
            l185: if (  ( (((*in).Node_8.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 186;
            }
            l186: if (  ( (((*in).Node_8.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 187;
            }
        }
        l187: if (  ( ((*in)._control.Node_8 == 8) ) )
        {
            l188: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 189;
            }
        }
        l189: if (  ( ((*in)._control.Node_8 == 4) ) )
        {
            l190: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 191;
            }
            l191: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_8 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 192;
            }
        }
        l192: if (  ( ((*in)._control.Node_9 == 3) ) )
        {
            l193: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 194;
            }
        }
        l194: if (  ( ((*in)._control.Node_9 == 2) ) )
        {
            l195: if (  ( (((*in).Node_9.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 196;
            }
            l196: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 197;
            }
        }
        l197: if (  ( ((*in)._control.Node_9 == 0) ) )
        {
            l198: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 9) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_9.rt) = (1);
                (*out)._control.Node_9 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 199;
            }
            l199: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 9))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_9.rt) = (0);
                (*out)._control.Node_9 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 200;
            }
        }
        l200: if (  ( ((*in)._control.Node_9 == 5) ) )
        {
            l201: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                ((*out).Node_9.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 202;
            }
        }
        l202: if (  ( ((*in)._control.Node_9 == 1) ) )
        {
            l203: if (  ( (((*in).Node_9.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 204;
            }
            l204: if (  ( (((*in).Node_9.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 205;
            }
        }
        l205: if (  ( ((*in)._control.Node_9 == 8) ) )
        {
            l206: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
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
                return 207;
            }
        }
        l207: if (  ( ((*in)._control.Node_9 == 4) ) )
        {
            l208: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
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
                return 209;
            }
            l209: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_9 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 210;
            }
        }
        l210: if (  ( ((*in)._control.Node_10 == 3) ) )
        {
            l211: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 212;
            }
        }
        l212: if (  ( ((*in)._control.Node_10 == 2) ) )
        {
            l213: if (  ( (((*in).Node_10.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 214;
            }
            l214: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 215;
            }
        }
        l215: if (  ( ((*in)._control.Node_10 == 0) ) )
        {
            l216: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 10) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_10.rt) = (1);
                (*out)._control.Node_10 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 217;
            }
            l217: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 10))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_10.rt) = (0);
                (*out)._control.Node_10 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 218;
            }
        }
        l218: if (  ( ((*in)._control.Node_10 == 5) ) )
        {
            l219: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 6;
                ((*out).Node_10.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 220;
            }
        }
        l220: if (  ( ((*in)._control.Node_10 == 1) ) )
        {
            l221: if (  ( (((*in).Node_10.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 222;
            }
            l222: if (  ( (((*in).Node_10.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 223;
            }
        }
        l223: if (  ( ((*in)._control.Node_10 == 8) ) )
        {
            l224: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 225;
            }
        }
        l225: if (  ( ((*in)._control.Node_10 == 4) ) )
        {
            l226: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 227;
            }
            l227: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_10 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 228;
            }
        }
        l228: if (  ( ((*in)._control.Node_11 == 3) ) )
        {
            l229: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 230;
            }
        }
        l230: if (  ( ((*in)._control.Node_11 == 2) ) )
        {
            l231: if (  ( (((*in).Node_11.granted == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 232;
            }
            l232: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 233;
            }
        }
        l233: if (  ( ((*in)._control.Node_11 == 0) ) )
        {
            l234: if (  ( ((*in)._control.Token == 1) )  &&  ( ((((*in).Token.i == 11) && ((*in).in_RT[ (*in).Token.i ] == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_11.rt) = (1);
                (*out)._control.Node_11 = 1;
                (*out)._control.Token = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 235;
            }
            l235: if (  ( ((*in)._control.Token == 3) )  &&  ( ((((*in).Token.NRT_count > 0) && ((*in).Token.next == 11))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_11.rt) = (0);
                (*out)._control.Node_11 = 1;
                (*out)._control.Token = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 236;
            }
        }
        l236: if (  ( ((*in)._control.Node_11 == 5) ) )
        {
            l237: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 6;
                ((*out).Node_11.granted) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 238;
            }
        }
        l238: if (  ( ((*in)._control.Node_11 == 1) ) )
        {
            l239: if (  ( (((*in).Node_11.rt == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 240;
            }
            l240: if (  ( (((*in).Node_11.rt == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 241;
            }
        }
        l241: if (  ( ((*in)._control.Node_11 == 8) ) )
        {
            l242: if (  ( ((*in)._control.Bandwidth == 1) )  &&  ( (((*in).in_RT[ (*in).Bandwidth.i ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 6;
                (*out)._control.Bandwidth = 0;
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (0);
                ((*out).RT_count) = (((*out).RT_count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 243;
            }
        }
        l243: if (  ( ((*in)._control.Node_11 == 4) ) )
        {
            l244: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 5;
                (*out)._control.Bandwidth = 0;
                ((*out).RT_count) = (((*out).RT_count + 1));
                ((*out).in_RT[ (*out).Bandwidth.i ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 245;
            }
            l245: if (  ( ((*in)._control.Bandwidth == 2) )  &&  ( (((*in).RT_count >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_11 = 6;
                (*out)._control.Bandwidth = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 246;
            }
        }
        l246: if (  ( ((*in)._control.Token == 3) ) )
        {
            l247: if (  ( (((*in).Token.NRT_count == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 248;
            }
        }
        l248: if (  ( ((*in)._control.Token == 4) ) )
        {
            l249: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 250;
            }
            l250: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 251;
            }
            l251: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 252;
            }
            l252: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 253;
            }
            l253: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 254;
            }
            l254: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 255;
            }
            l255: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 256;
            }
            l256: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 257;
            }
            l257: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 258;
            }
            l258: if (  ( ((*in)._control.Node_9 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_9 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 259;
            }
            l259: if (  ( ((*in)._control.Node_10 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_10 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 260;
            }
            l260: if (  ( ((*in)._control.Node_11 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                ((*out).Token.next) = ((((*out).Token.next + 1) % 12));
                ((*out).Token.NRT_count) = (((*out).Token.NRT_count - 1));
                (*out)._control.Node_11 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 261;
            }
        }
        l261: if (  ( ((*in)._control.Token == 1) ) )
        {
            l262: if (  ( ((((*in).Token.i < 12) && ((*in).in_RT[ (*in).Token.i ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 263;
            }
            l263: if (  ( (((*in).Token.i == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 264;
            }
        }
        l264: if (  ( ((*in)._control.Token == 2) ) )
        {
            l265: if (  ( ((*in)._control.Node_0 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 266;
            }
            l266: if (  ( ((*in)._control.Node_1 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 267;
            }
            l267: if (  ( ((*in)._control.Node_2 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 268;
            }
            l268: if (  ( ((*in)._control.Node_3 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 269;
            }
            l269: if (  ( ((*in)._control.Node_4 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 270;
            }
            l270: if (  ( ((*in)._control.Node_5 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 271;
            }
            l271: if (  ( ((*in)._control.Node_6 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 272;
            }
            l272: if (  ( ((*in)._control.Node_7 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 273;
            }
            l273: if (  ( ((*in)._control.Node_8 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 274;
            }
            l274: if (  ( ((*in)._control.Node_9 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_9 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 275;
            }
            l275: if (  ( ((*in)._control.Node_10 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_10 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 276;
            }
            l276: if (  ( ((*in)._control.Node_11 == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (((*out).Token.i + 1));
                (*out)._control.Node_11 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 277;
            }
        }
        l277: if (  ( ((*in)._control.Token == 5) ) )
        {
            l278: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 0;
                ((*out).Token.NRT_count) = ((6 - (*out).RT_count));
                system_in_deadlock = false;
                *to = blob_out;
                return 279;
            }
        }
        l279: if (  ( ((*in)._control.Token == 0) ) )
        {
            l280: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Token = 1;
                ((*out).Token.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 281;
            }
        }
    }
    l281: if (  ( system_in_deadlock ) )
    {
    }
    l282: return 0;
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
