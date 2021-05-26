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
        uint16_t Node_0:5;
        uint16_t Node_1:5;
        uint16_t Node_2:5;
        uint16_t Node_3:5;
        uint16_t Node_4:5;
        uint16_t Node_5:5;
        uint16_t channel_ch_0_0:2;
        uint16_t channel_ch_1_0:2;
        uint16_t channel_ch_2_0:2;
        uint16_t channel_ch_3_0:2;
        uint16_t channel_ch_4_0:2;
        uint16_t channel_ch_5_0:2;
        uint16_t channel_ch_0_1:2;
        uint16_t channel_ch_1_1:2;
        uint16_t channel_ch_2_1:2;
        uint16_t channel_ch_3_1:2;
        uint16_t channel_ch_4_1:2;
        uint16_t channel_ch_5_1:2;
        uint16_t channel_ch_0_2:2;
        uint16_t channel_ch_1_2:2;
        uint16_t channel_ch_2_2:2;
        uint16_t channel_ch_3_2:2;
        uint16_t channel_ch_4_2:2;
        uint16_t channel_ch_5_2:2;
        uint16_t channel_ch_0_3:2;
        uint16_t channel_ch_1_3:2;
        uint16_t channel_ch_2_3:2;
        uint16_t channel_ch_3_3:2;
        uint16_t channel_ch_4_3:2;
        uint16_t channel_ch_5_3:2;
        uint16_t channel_ch_0_4:2;
        uint16_t channel_ch_1_4:2;
        uint16_t channel_ch_2_4:2;
        uint16_t channel_ch_3_4:2;
        uint16_t channel_ch_4_4:2;
        uint16_t channel_ch_5_4:2;
        uint16_t channel_ch_0_5:2;
        uint16_t channel_ch_1_5:2;
        uint16_t channel_ch_2_5:2;
        uint16_t channel_ch_3_5:2;
        uint16_t channel_ch_4_5:2;
        uint16_t channel_ch_5_5:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t connected[36];
    uint8_t toss;
    uint8_t elected;
    uint8_t elected_num;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_0;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_1;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_2;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_3;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_4;
    struct
    {
        uint8_t received[6];
        uint8_t j;
        uint8_t n;
        uint8_t m;
    }
    __attribute__((__packed__)) Node_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_1;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_2;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_3;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_4;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_0_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_1_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_2_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_3_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_4_5;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ch_5_5;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.connected[0] = 0;
    _out.connected[1] = 0;
    _out.connected[2] = 1;
    _out.connected[3] = 0;
    _out.connected[4] = 0;
    _out.connected[5] = 0;
    _out.connected[6] = 0;
    _out.connected[7] = 0;
    _out.connected[8] = 1;
    _out.connected[9] = 0;
    _out.connected[10] = 0;
    _out.connected[11] = 0;
    _out.connected[12] = 1;
    _out.connected[13] = 1;
    _out.connected[14] = 0;
    _out.connected[15] = 1;
    _out.connected[16] = 0;
    _out.connected[17] = 0;
    _out.connected[18] = 0;
    _out.connected[19] = 0;
    _out.connected[20] = 1;
    _out.connected[21] = 0;
    _out.connected[22] = 0;
    _out.connected[23] = 1;
    _out.connected[24] = 0;
    _out.connected[25] = 0;
    _out.connected[26] = 0;
    _out.connected[27] = 0;
    _out.connected[28] = 0;
    _out.connected[29] = 1;
    _out.connected[30] = 0;
    _out.connected[31] = 0;
    _out.connected[32] = 0;
    _out.connected[33] = 1;
    _out.connected[34] = 1;
    _out.connected[35] = 0;
    _out.elected = 6;
    _out.elected_num = 0;
    _out._control.Node_0 = 0;
    _out._control.Node_1 = 0;
    _out._control.Node_2 = 0;
    _out._control.Node_3 = 0;
    _out._control.Node_4 = 0;
    _out._control.Node_5 = 0;
    _out._control.channel_ch_0_0 = 0;
    _out._control.channel_ch_1_0 = 0;
    _out._control.channel_ch_2_0 = 0;
    _out._control.channel_ch_3_0 = 0;
    _out._control.channel_ch_4_0 = 0;
    _out._control.channel_ch_5_0 = 0;
    _out._control.channel_ch_0_1 = 0;
    _out._control.channel_ch_1_1 = 0;
    _out._control.channel_ch_2_1 = 0;
    _out._control.channel_ch_3_1 = 0;
    _out._control.channel_ch_4_1 = 0;
    _out._control.channel_ch_5_1 = 0;
    _out._control.channel_ch_0_2 = 0;
    _out._control.channel_ch_1_2 = 0;
    _out._control.channel_ch_2_2 = 0;
    _out._control.channel_ch_3_2 = 0;
    _out._control.channel_ch_4_2 = 0;
    _out._control.channel_ch_5_2 = 0;
    _out._control.channel_ch_0_3 = 0;
    _out._control.channel_ch_1_3 = 0;
    _out._control.channel_ch_2_3 = 0;
    _out._control.channel_ch_3_3 = 0;
    _out._control.channel_ch_4_3 = 0;
    _out._control.channel_ch_5_3 = 0;
    _out._control.channel_ch_0_4 = 0;
    _out._control.channel_ch_1_4 = 0;
    _out._control.channel_ch_2_4 = 0;
    _out._control.channel_ch_3_4 = 0;
    _out._control.channel_ch_4_4 = 0;
    _out._control.channel_ch_5_4 = 0;
    _out._control.channel_ch_0_5 = 0;
    _out._control.channel_ch_1_5 = 0;
    _out._control.channel_ch_2_5 = 0;
    _out._control.channel_ch_3_5 = 0;
    _out._control.channel_ch_4_5 = 0;
    _out._control.channel_ch_5_5 = 0;
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
        l3: if (  ( ((*in)._control.Node_0 == 6) ) )
        {
            l4: if (  ( (((*in).Node_0.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 16;
                ((*out).elected) = (0);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( (((*in).Node_0.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
        }
        l6: if (  ( ((*in)._control.Node_0 == 3) ) )
        {
            l7: if (  ( ((((*in).Node_0.j < 6) && !((*in).Node_0.received[ (*in).Node_0.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((((*in).Node_0.n == 0) && ((*in).Node_0.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
        }
        l9: if (  ( ((*in)._control.Node_0 == 11) ) )
        {
            l10: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
        }
        l12: if (  ( ((*in)._control.Node_0 == 7) ) )
        {
            l13: if (  ( ((0 != 0)) )  &&  ( ((*in)._control.channel_ch_0_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_0_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_0_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((1 != 0)) )  &&  ( ((*in)._control.channel_ch_1_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_1_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_1_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((2 != 0)) )  &&  ( ((*in)._control.channel_ch_2_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_2_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_2_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((3 != 0)) )  &&  ( ((*in)._control.channel_ch_3_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_3_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_3_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((4 != 0)) )  &&  ( ((*in)._control.channel_ch_4_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_4_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_4_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((5 != 0)) )  &&  ( ((*in)._control.channel_ch_5_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_5_0.v);
                (*out)._control.Node_0 = 8;
                (*out)._control.channel_ch_5_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
        }
        l19: if (  ( ((*in)._control.Node_0 == 8) ) )
        {
            l20: if (  ( ((((*in).Node_0.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.received[ ((*out).Node_0.m % 6) ]) = (1);
                ((*out).Node_0.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((((*in).Node_0.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
        }
        l22: if (  ( ((*in)._control.Node_0 == 14) ) )
        {
            l23: if (  ( ((0 != 0)) )  &&  ( ((*in)._control.channel_ch_0_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_0_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_0_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((1 != 0)) )  &&  ( ((*in)._control.channel_ch_1_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_1_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_1_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( ((2 != 0)) )  &&  ( ((*in)._control.channel_ch_2_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_2_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_2_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((3 != 0)) )  &&  ( ((*in)._control.channel_ch_3_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_3_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_3_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((4 != 0)) )  &&  ( ((*in)._control.channel_ch_4_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_4_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_4_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((5 != 0)) )  &&  ( ((*in)._control.channel_ch_5_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_5_0.v);
                (*out)._control.Node_0 = 15;
                (*out)._control.channel_ch_5_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
        }
        l29: if (  ( ((*in)._control.Node_0 == 15) ) )
        {
            l30: if (  ( ((((*in).Node_0.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.received[ ((*out).Node_0.m % 6) ]) = (1);
                ((*out).Node_0.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
        }
        l31: if (  ( ((*in)._control.Node_0 == 9) ) )
        {
            l32: if (  ( ((0 != 0)) )  &&  ( ((*in)._control.channel_ch_0_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_0_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_0_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((1 != 0)) )  &&  ( ((*in)._control.channel_ch_1_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_1_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_1_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( ((2 != 0)) )  &&  ( ((*in)._control.channel_ch_2_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_2_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_2_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( ((3 != 0)) )  &&  ( ((*in)._control.channel_ch_3_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_3_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_3_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( ((4 != 0)) )  &&  ( ((*in)._control.channel_ch_4_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_4_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_4_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((5 != 0)) )  &&  ( ((*in)._control.channel_ch_5_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_5_0.v);
                (*out)._control.Node_0 = 10;
                (*out)._control.channel_ch_5_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.Node_0 == 10) ) )
        {
            l39: if (  ( ((((*in).Node_0.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((((*in).Node_0.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.Node_0 == 0) ) )
        {
            l42: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( (((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) == 1) && (*in).connected[ ((0 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 7;
                ((*out).Node_0.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((((*in).connected[ ((0 * 6) + 0) ] + ((*in).connected[ ((0 * 6) + 1) ] + ((*in).connected[ ((0 * 6) + 2) ] + ((*in).connected[ ((0 * 6) + 3) ] + ((*in).connected[ ((0 * 6) + 4) ] + (*in).connected[ ((0 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 1;
                ((*out).Node_0.n) = (((*out).connected[ ((0 * 6) + 0) ] + ((*out).connected[ ((0 * 6) + 1) ] + ((*out).connected[ ((0 * 6) + 2) ] + ((*out).connected[ ((0 * 6) + 3) ] + ((*out).connected[ ((0 * 6) + 4) ] + (*out).connected[ ((0 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.Node_0 == 5) ) )
        {
            l50: if (  ( ((((*in).Node_0.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((((*in).Node_0.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 4;
                ((*out).Node_0.received[ ((*out).Node_0.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
        }
        l52: if (  ( ((*in)._control.Node_0 == 4) ) )
        {
            l53: if (  ( (((0 != 0) && ((*in).Node_0.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_0_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_0_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( (((1 != 0) && ((*in).Node_0.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_1_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_1_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( (((2 != 0) && ((*in).Node_0.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_2_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_2_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( (((3 != 0) && ((*in).Node_0.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_3_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_3_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( (((4 != 0) && ((*in).Node_0.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_4_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_4_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( (((5 != 0) && ((*in).Node_0.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_5_0.v);
                (*out)._control.Node_0 = 5;
                (*out)._control.channel_ch_5_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( ((((*in).Node_0.received[ 0 ] + ((*in).Node_0.received[ 1 ] + ((*in).Node_0.received[ 2 ] + ((*in).Node_0.received[ 3 ] + ((*in).Node_0.received[ 4 ] + (*in).Node_0.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
        }
        l60: if (  ( ((*in)._control.Node_0 == 1) ) )
        {
            l61: if (  ( ((0 != 0)) )  &&  ( ((*in)._control.channel_ch_0_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_0_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_0_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( ((1 != 0)) )  &&  ( ((*in)._control.channel_ch_1_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_1_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_1_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( ((2 != 0)) )  &&  ( ((*in)._control.channel_ch_2_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_2_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_2_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( ((3 != 0)) )  &&  ( ((*in)._control.channel_ch_3_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_3_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_3_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( ((4 != 0)) )  &&  ( ((*in)._control.channel_ch_4_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_4_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_4_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
            l66: if (  ( ((5 != 0)) )  &&  ( ((*in)._control.channel_ch_5_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_0.m) = ((*in).channel_ch_5_0.v);
                (*out)._control.Node_0 = 2;
                (*out)._control.channel_ch_5_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( (((*in).Node_0.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
        }
        l68: if (  ( ((*in)._control.Node_0 == 2) ) )
        {
            l69: if (  ( (((((*in).Node_0.m / 6) != 1) || (!((*in).connected[ ((0 * 6) + ((*in).Node_0.m % 6)) ] ) || ((*in).Node_0.received[ ((*in).Node_0.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if (  ( (((((*in).Node_0.m / 6) == 1) && ((*in).connected[ ((0 * 6) + ((*in).Node_0.m % 6)) ] && ((*in).Node_0.received[ ((*in).Node_0.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_0 = 1;
                ((*out).Node_0.received[ ((*out).Node_0.m % 6) ]) = (1);
                ((*out).Node_0.n) = (((*out).Node_0.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
        }
        l71: if (  ( ((*in)._control.Node_1 == 6) ) )
        {
            l72: if (  ( (((*in).Node_1.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 16;
                ((*out).elected) = (1);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( (((*in).Node_1.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
        }
        l74: if (  ( ((*in)._control.Node_1 == 3) ) )
        {
            l75: if (  ( ((((*in).Node_1.j < 6) && !((*in).Node_1.received[ (*in).Node_1.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( ((((*in).Node_1.n == 0) && ((*in).Node_1.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
        }
        l77: if (  ( ((*in)._control.Node_1 == 11) ) )
        {
            l78: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
        }
        l80: if (  ( ((*in)._control.Node_1 == 7) ) )
        {
            l81: if (  ( ((0 != 1)) )  &&  ( ((*in)._control.channel_ch_0_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_0_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_0_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( ((1 != 1)) )  &&  ( ((*in)._control.channel_ch_1_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_1_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_1_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( ((2 != 1)) )  &&  ( ((*in)._control.channel_ch_2_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_2_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_2_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if (  ( ((3 != 1)) )  &&  ( ((*in)._control.channel_ch_3_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_3_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_3_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((4 != 1)) )  &&  ( ((*in)._control.channel_ch_4_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_4_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_4_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( ((5 != 1)) )  &&  ( ((*in)._control.channel_ch_5_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_5_1.v);
                (*out)._control.Node_1 = 8;
                (*out)._control.channel_ch_5_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
        }
        l87: if (  ( ((*in)._control.Node_1 == 8) ) )
        {
            l88: if (  ( ((((*in).Node_1.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.received[ ((*out).Node_1.m % 6) ]) = (1);
                ((*out).Node_1.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( ((((*in).Node_1.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
        }
        l90: if (  ( ((*in)._control.Node_1 == 14) ) )
        {
            l91: if (  ( ((0 != 1)) )  &&  ( ((*in)._control.channel_ch_0_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_0_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_0_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( ((1 != 1)) )  &&  ( ((*in)._control.channel_ch_1_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_1_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_1_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if (  ( ((2 != 1)) )  &&  ( ((*in)._control.channel_ch_2_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_2_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_2_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
            l94: if (  ( ((3 != 1)) )  &&  ( ((*in)._control.channel_ch_3_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_3_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_3_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
            l95: if (  ( ((4 != 1)) )  &&  ( ((*in)._control.channel_ch_4_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_4_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_4_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( ((5 != 1)) )  &&  ( ((*in)._control.channel_ch_5_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_5_1.v);
                (*out)._control.Node_1 = 15;
                (*out)._control.channel_ch_5_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
        }
        l97: if (  ( ((*in)._control.Node_1 == 15) ) )
        {
            l98: if (  ( ((((*in).Node_1.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.received[ ((*out).Node_1.m % 6) ]) = (1);
                ((*out).Node_1.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
        }
        l99: if (  ( ((*in)._control.Node_1 == 9) ) )
        {
            l100: if (  ( ((0 != 1)) )  &&  ( ((*in)._control.channel_ch_0_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_0_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_0_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
            l101: if (  ( ((1 != 1)) )  &&  ( ((*in)._control.channel_ch_1_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_1_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_1_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
            l102: if (  ( ((2 != 1)) )  &&  ( ((*in)._control.channel_ch_2_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_2_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_2_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
            l103: if (  ( ((3 != 1)) )  &&  ( ((*in)._control.channel_ch_3_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_3_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_3_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( ((4 != 1)) )  &&  ( ((*in)._control.channel_ch_4_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_4_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_4_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if (  ( ((5 != 1)) )  &&  ( ((*in)._control.channel_ch_5_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_5_1.v);
                (*out)._control.Node_1 = 10;
                (*out)._control.channel_ch_5_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
        }
        l106: if (  ( ((*in)._control.Node_1 == 10) ) )
        {
            l107: if (  ( ((((*in).Node_1.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
            l108: if (  ( ((((*in).Node_1.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
        }
        l109: if (  ( ((*in)._control.Node_1 == 0) ) )
        {
            l110: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
            l111: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
            l112: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
            l113: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 114;
            }
            l114: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
            l115: if (  ( (((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) == 1) && (*in).connected[ ((1 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 7;
                ((*out).Node_1.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
            l116: if (  ( ((((*in).connected[ ((1 * 6) + 0) ] + ((*in).connected[ ((1 * 6) + 1) ] + ((*in).connected[ ((1 * 6) + 2) ] + ((*in).connected[ ((1 * 6) + 3) ] + ((*in).connected[ ((1 * 6) + 4) ] + (*in).connected[ ((1 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 1;
                ((*out).Node_1.n) = (((*out).connected[ ((1 * 6) + 0) ] + ((*out).connected[ ((1 * 6) + 1) ] + ((*out).connected[ ((1 * 6) + 2) ] + ((*out).connected[ ((1 * 6) + 3) ] + ((*out).connected[ ((1 * 6) + 4) ] + (*out).connected[ ((1 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.Node_1 == 5) ) )
        {
            l118: if (  ( ((((*in).Node_1.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
            l119: if (  ( ((((*in).Node_1.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 4;
                ((*out).Node_1.received[ ((*out).Node_1.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
        }
        l120: if (  ( ((*in)._control.Node_1 == 4) ) )
        {
            l121: if (  ( (((0 != 1) && ((*in).Node_1.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_0_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_0_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
            l122: if (  ( (((1 != 1) && ((*in).Node_1.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_1_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_1_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
            l123: if (  ( (((2 != 1) && ((*in).Node_1.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_2_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_2_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
            l124: if (  ( (((3 != 1) && ((*in).Node_1.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_3_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_3_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
            l125: if (  ( (((4 != 1) && ((*in).Node_1.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_4_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_4_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
            l126: if (  ( (((5 != 1) && ((*in).Node_1.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_5_1.v);
                (*out)._control.Node_1 = 5;
                (*out)._control.channel_ch_5_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
            l127: if (  ( ((((*in).Node_1.received[ 0 ] + ((*in).Node_1.received[ 1 ] + ((*in).Node_1.received[ 2 ] + ((*in).Node_1.received[ 3 ] + ((*in).Node_1.received[ 4 ] + (*in).Node_1.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
        }
        l128: if (  ( ((*in)._control.Node_1 == 1) ) )
        {
            l129: if (  ( ((0 != 1)) )  &&  ( ((*in)._control.channel_ch_0_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_0_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_0_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
            l130: if (  ( ((1 != 1)) )  &&  ( ((*in)._control.channel_ch_1_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_1_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_1_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
            l131: if (  ( ((2 != 1)) )  &&  ( ((*in)._control.channel_ch_2_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_2_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_2_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((3 != 1)) )  &&  ( ((*in)._control.channel_ch_3_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_3_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_3_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((4 != 1)) )  &&  ( ((*in)._control.channel_ch_4_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_4_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_4_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
            l134: if (  ( ((5 != 1)) )  &&  ( ((*in)._control.channel_ch_5_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_1.m) = ((*in).channel_ch_5_1.v);
                (*out)._control.Node_1 = 2;
                (*out)._control.channel_ch_5_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( (((*in).Node_1.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
        }
        l136: if (  ( ((*in)._control.Node_1 == 2) ) )
        {
            l137: if (  ( (((((*in).Node_1.m / 6) != 1) || (!((*in).connected[ ((1 * 6) + ((*in).Node_1.m % 6)) ] ) || ((*in).Node_1.received[ ((*in).Node_1.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
            l138: if (  ( (((((*in).Node_1.m / 6) == 1) && ((*in).connected[ ((1 * 6) + ((*in).Node_1.m % 6)) ] && ((*in).Node_1.received[ ((*in).Node_1.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_1 = 1;
                ((*out).Node_1.received[ ((*out).Node_1.m % 6) ]) = (1);
                ((*out).Node_1.n) = (((*out).Node_1.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
        }
        l139: if (  ( ((*in)._control.Node_2 == 6) ) )
        {
            l140: if (  ( (((*in).Node_2.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 16;
                ((*out).elected) = (2);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
            l141: if (  ( (((*in).Node_2.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
        }
        l142: if (  ( ((*in)._control.Node_2 == 3) ) )
        {
            l143: if (  ( ((((*in).Node_2.j < 6) && !((*in).Node_2.received[ (*in).Node_2.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( ((((*in).Node_2.n == 0) && ((*in).Node_2.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
        }
        l145: if (  ( ((*in)._control.Node_2 == 11) ) )
        {
            l146: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
            l147: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
        }
        l148: if (  ( ((*in)._control.Node_2 == 7) ) )
        {
            l149: if (  ( ((0 != 2)) )  &&  ( ((*in)._control.channel_ch_0_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_0_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_0_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
            l150: if (  ( ((1 != 2)) )  &&  ( ((*in)._control.channel_ch_1_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_1_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_1_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
            l151: if (  ( ((2 != 2)) )  &&  ( ((*in)._control.channel_ch_2_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_2_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_2_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
            l152: if (  ( ((3 != 2)) )  &&  ( ((*in)._control.channel_ch_3_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_3_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_3_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
            l153: if (  ( ((4 != 2)) )  &&  ( ((*in)._control.channel_ch_4_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_4_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_4_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 154;
            }
            l154: if (  ( ((5 != 2)) )  &&  ( ((*in)._control.channel_ch_5_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_5_2.v);
                (*out)._control.Node_2 = 8;
                (*out)._control.channel_ch_5_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
        }
        l155: if (  ( ((*in)._control.Node_2 == 8) ) )
        {
            l156: if (  ( ((((*in).Node_2.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.received[ ((*out).Node_2.m % 6) ]) = (1);
                ((*out).Node_2.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
            l157: if (  ( ((((*in).Node_2.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
        }
        l158: if (  ( ((*in)._control.Node_2 == 14) ) )
        {
            l159: if (  ( ((0 != 2)) )  &&  ( ((*in)._control.channel_ch_0_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_0_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_0_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 160;
            }
            l160: if (  ( ((1 != 2)) )  &&  ( ((*in)._control.channel_ch_1_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_1_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_1_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 161;
            }
            l161: if (  ( ((2 != 2)) )  &&  ( ((*in)._control.channel_ch_2_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_2_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_2_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 162;
            }
            l162: if (  ( ((3 != 2)) )  &&  ( ((*in)._control.channel_ch_3_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_3_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_3_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 163;
            }
            l163: if (  ( ((4 != 2)) )  &&  ( ((*in)._control.channel_ch_4_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_4_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_4_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
            l164: if (  ( ((5 != 2)) )  &&  ( ((*in)._control.channel_ch_5_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_5_2.v);
                (*out)._control.Node_2 = 15;
                (*out)._control.channel_ch_5_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 165;
            }
        }
        l165: if (  ( ((*in)._control.Node_2 == 15) ) )
        {
            l166: if (  ( ((((*in).Node_2.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.received[ ((*out).Node_2.m % 6) ]) = (1);
                ((*out).Node_2.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 167;
            }
        }
        l167: if (  ( ((*in)._control.Node_2 == 9) ) )
        {
            l168: if (  ( ((0 != 2)) )  &&  ( ((*in)._control.channel_ch_0_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_0_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_0_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
            l169: if (  ( ((1 != 2)) )  &&  ( ((*in)._control.channel_ch_1_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_1_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_1_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 170;
            }
            l170: if (  ( ((2 != 2)) )  &&  ( ((*in)._control.channel_ch_2_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_2_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_2_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 171;
            }
            l171: if (  ( ((3 != 2)) )  &&  ( ((*in)._control.channel_ch_3_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_3_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_3_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 172;
            }
            l172: if (  ( ((4 != 2)) )  &&  ( ((*in)._control.channel_ch_4_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_4_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_4_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 173;
            }
            l173: if (  ( ((5 != 2)) )  &&  ( ((*in)._control.channel_ch_5_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_5_2.v);
                (*out)._control.Node_2 = 10;
                (*out)._control.channel_ch_5_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
        }
        l174: if (  ( ((*in)._control.Node_2 == 10) ) )
        {
            l175: if (  ( ((((*in).Node_2.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
            l176: if (  ( ((((*in).Node_2.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
        }
        l177: if (  ( ((*in)._control.Node_2 == 0) ) )
        {
            l178: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 179;
            }
            l179: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 180;
            }
            l180: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
            l181: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 182;
            }
            l182: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
            l183: if (  ( (((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) == 1) && (*in).connected[ ((2 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 7;
                ((*out).Node_2.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 184;
            }
            l184: if (  ( ((((*in).connected[ ((2 * 6) + 0) ] + ((*in).connected[ ((2 * 6) + 1) ] + ((*in).connected[ ((2 * 6) + 2) ] + ((*in).connected[ ((2 * 6) + 3) ] + ((*in).connected[ ((2 * 6) + 4) ] + (*in).connected[ ((2 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 1;
                ((*out).Node_2.n) = (((*out).connected[ ((2 * 6) + 0) ] + ((*out).connected[ ((2 * 6) + 1) ] + ((*out).connected[ ((2 * 6) + 2) ] + ((*out).connected[ ((2 * 6) + 3) ] + ((*out).connected[ ((2 * 6) + 4) ] + (*out).connected[ ((2 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 185;
            }
        }
        l185: if (  ( ((*in)._control.Node_2 == 5) ) )
        {
            l186: if (  ( ((((*in).Node_2.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 187;
            }
            l187: if (  ( ((((*in).Node_2.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 4;
                ((*out).Node_2.received[ ((*out).Node_2.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 188;
            }
        }
        l188: if (  ( ((*in)._control.Node_2 == 4) ) )
        {
            l189: if (  ( (((0 != 2) && ((*in).Node_2.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_0_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_0_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 190;
            }
            l190: if (  ( (((1 != 2) && ((*in).Node_2.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_1_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_1_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 191;
            }
            l191: if (  ( (((2 != 2) && ((*in).Node_2.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_2_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_2_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 192;
            }
            l192: if (  ( (((3 != 2) && ((*in).Node_2.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_3_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_3_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 193;
            }
            l193: if (  ( (((4 != 2) && ((*in).Node_2.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_4_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_4_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 194;
            }
            l194: if (  ( (((5 != 2) && ((*in).Node_2.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_5_2.v);
                (*out)._control.Node_2 = 5;
                (*out)._control.channel_ch_5_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 195;
            }
            l195: if (  ( ((((*in).Node_2.received[ 0 ] + ((*in).Node_2.received[ 1 ] + ((*in).Node_2.received[ 2 ] + ((*in).Node_2.received[ 3 ] + ((*in).Node_2.received[ 4 ] + (*in).Node_2.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 196;
            }
        }
        l196: if (  ( ((*in)._control.Node_2 == 1) ) )
        {
            l197: if (  ( ((0 != 2)) )  &&  ( ((*in)._control.channel_ch_0_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_0_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_0_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 198;
            }
            l198: if (  ( ((1 != 2)) )  &&  ( ((*in)._control.channel_ch_1_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_1_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_1_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 199;
            }
            l199: if (  ( ((2 != 2)) )  &&  ( ((*in)._control.channel_ch_2_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_2_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_2_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 200;
            }
            l200: if (  ( ((3 != 2)) )  &&  ( ((*in)._control.channel_ch_3_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_3_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_3_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 201;
            }
            l201: if (  ( ((4 != 2)) )  &&  ( ((*in)._control.channel_ch_4_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_4_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_4_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 202;
            }
            l202: if (  ( ((5 != 2)) )  &&  ( ((*in)._control.channel_ch_5_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_2.m) = ((*in).channel_ch_5_2.v);
                (*out)._control.Node_2 = 2;
                (*out)._control.channel_ch_5_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 203;
            }
            l203: if (  ( (((*in).Node_2.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 204;
            }
        }
        l204: if (  ( ((*in)._control.Node_2 == 2) ) )
        {
            l205: if (  ( (((((*in).Node_2.m / 6) != 1) || (!((*in).connected[ ((2 * 6) + ((*in).Node_2.m % 6)) ] ) || ((*in).Node_2.received[ ((*in).Node_2.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 206;
            }
            l206: if (  ( (((((*in).Node_2.m / 6) == 1) && ((*in).connected[ ((2 * 6) + ((*in).Node_2.m % 6)) ] && ((*in).Node_2.received[ ((*in).Node_2.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_2 = 1;
                ((*out).Node_2.received[ ((*out).Node_2.m % 6) ]) = (1);
                ((*out).Node_2.n) = (((*out).Node_2.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 207;
            }
        }
        l207: if (  ( ((*in)._control.Node_3 == 6) ) )
        {
            l208: if (  ( (((*in).Node_3.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 16;
                ((*out).elected) = (3);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 209;
            }
            l209: if (  ( (((*in).Node_3.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 210;
            }
        }
        l210: if (  ( ((*in)._control.Node_3 == 3) ) )
        {
            l211: if (  ( ((((*in).Node_3.j < 6) && !((*in).Node_3.received[ (*in).Node_3.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 212;
            }
            l212: if (  ( ((((*in).Node_3.n == 0) && ((*in).Node_3.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 213;
            }
        }
        l213: if (  ( ((*in)._control.Node_3 == 11) ) )
        {
            l214: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 215;
            }
            l215: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 216;
            }
        }
        l216: if (  ( ((*in)._control.Node_3 == 7) ) )
        {
            l217: if (  ( ((0 != 3)) )  &&  ( ((*in)._control.channel_ch_0_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_0_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_0_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 218;
            }
            l218: if (  ( ((1 != 3)) )  &&  ( ((*in)._control.channel_ch_1_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_1_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_1_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 219;
            }
            l219: if (  ( ((2 != 3)) )  &&  ( ((*in)._control.channel_ch_2_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_2_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_2_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 220;
            }
            l220: if (  ( ((3 != 3)) )  &&  ( ((*in)._control.channel_ch_3_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_3_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_3_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 221;
            }
            l221: if (  ( ((4 != 3)) )  &&  ( ((*in)._control.channel_ch_4_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_4_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_4_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 222;
            }
            l222: if (  ( ((5 != 3)) )  &&  ( ((*in)._control.channel_ch_5_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_5_3.v);
                (*out)._control.Node_3 = 8;
                (*out)._control.channel_ch_5_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 223;
            }
        }
        l223: if (  ( ((*in)._control.Node_3 == 8) ) )
        {
            l224: if (  ( ((((*in).Node_3.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.received[ ((*out).Node_3.m % 6) ]) = (1);
                ((*out).Node_3.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 225;
            }
            l225: if (  ( ((((*in).Node_3.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 226;
            }
        }
        l226: if (  ( ((*in)._control.Node_3 == 14) ) )
        {
            l227: if (  ( ((0 != 3)) )  &&  ( ((*in)._control.channel_ch_0_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_0_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_0_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 228;
            }
            l228: if (  ( ((1 != 3)) )  &&  ( ((*in)._control.channel_ch_1_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_1_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_1_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 229;
            }
            l229: if (  ( ((2 != 3)) )  &&  ( ((*in)._control.channel_ch_2_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_2_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_2_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 230;
            }
            l230: if (  ( ((3 != 3)) )  &&  ( ((*in)._control.channel_ch_3_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_3_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_3_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 231;
            }
            l231: if (  ( ((4 != 3)) )  &&  ( ((*in)._control.channel_ch_4_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_4_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_4_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 232;
            }
            l232: if (  ( ((5 != 3)) )  &&  ( ((*in)._control.channel_ch_5_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_5_3.v);
                (*out)._control.Node_3 = 15;
                (*out)._control.channel_ch_5_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 233;
            }
        }
        l233: if (  ( ((*in)._control.Node_3 == 15) ) )
        {
            l234: if (  ( ((((*in).Node_3.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.received[ ((*out).Node_3.m % 6) ]) = (1);
                ((*out).Node_3.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 235;
            }
        }
        l235: if (  ( ((*in)._control.Node_3 == 9) ) )
        {
            l236: if (  ( ((0 != 3)) )  &&  ( ((*in)._control.channel_ch_0_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_0_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_0_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 237;
            }
            l237: if (  ( ((1 != 3)) )  &&  ( ((*in)._control.channel_ch_1_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_1_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_1_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 238;
            }
            l238: if (  ( ((2 != 3)) )  &&  ( ((*in)._control.channel_ch_2_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_2_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_2_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 239;
            }
            l239: if (  ( ((3 != 3)) )  &&  ( ((*in)._control.channel_ch_3_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_3_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_3_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 240;
            }
            l240: if (  ( ((4 != 3)) )  &&  ( ((*in)._control.channel_ch_4_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_4_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_4_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 241;
            }
            l241: if (  ( ((5 != 3)) )  &&  ( ((*in)._control.channel_ch_5_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_5_3.v);
                (*out)._control.Node_3 = 10;
                (*out)._control.channel_ch_5_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 242;
            }
        }
        l242: if (  ( ((*in)._control.Node_3 == 10) ) )
        {
            l243: if (  ( ((((*in).Node_3.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 244;
            }
            l244: if (  ( ((((*in).Node_3.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 245;
            }
        }
        l245: if (  ( ((*in)._control.Node_3 == 0) ) )
        {
            l246: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 247;
            }
            l247: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 248;
            }
            l248: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 249;
            }
            l249: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 250;
            }
            l250: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 251;
            }
            l251: if (  ( (((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) == 1) && (*in).connected[ ((3 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 7;
                ((*out).Node_3.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 252;
            }
            l252: if (  ( ((((*in).connected[ ((3 * 6) + 0) ] + ((*in).connected[ ((3 * 6) + 1) ] + ((*in).connected[ ((3 * 6) + 2) ] + ((*in).connected[ ((3 * 6) + 3) ] + ((*in).connected[ ((3 * 6) + 4) ] + (*in).connected[ ((3 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 1;
                ((*out).Node_3.n) = (((*out).connected[ ((3 * 6) + 0) ] + ((*out).connected[ ((3 * 6) + 1) ] + ((*out).connected[ ((3 * 6) + 2) ] + ((*out).connected[ ((3 * 6) + 3) ] + ((*out).connected[ ((3 * 6) + 4) ] + (*out).connected[ ((3 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 253;
            }
        }
        l253: if (  ( ((*in)._control.Node_3 == 5) ) )
        {
            l254: if (  ( ((((*in).Node_3.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 255;
            }
            l255: if (  ( ((((*in).Node_3.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 4;
                ((*out).Node_3.received[ ((*out).Node_3.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 256;
            }
        }
        l256: if (  ( ((*in)._control.Node_3 == 4) ) )
        {
            l257: if (  ( (((0 != 3) && ((*in).Node_3.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_0_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_0_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 258;
            }
            l258: if (  ( (((1 != 3) && ((*in).Node_3.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_1_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_1_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 259;
            }
            l259: if (  ( (((2 != 3) && ((*in).Node_3.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_2_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_2_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 260;
            }
            l260: if (  ( (((3 != 3) && ((*in).Node_3.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_3_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_3_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 261;
            }
            l261: if (  ( (((4 != 3) && ((*in).Node_3.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_4_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_4_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 262;
            }
            l262: if (  ( (((5 != 3) && ((*in).Node_3.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_5_3.v);
                (*out)._control.Node_3 = 5;
                (*out)._control.channel_ch_5_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 263;
            }
            l263: if (  ( ((((*in).Node_3.received[ 0 ] + ((*in).Node_3.received[ 1 ] + ((*in).Node_3.received[ 2 ] + ((*in).Node_3.received[ 3 ] + ((*in).Node_3.received[ 4 ] + (*in).Node_3.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 264;
            }
        }
        l264: if (  ( ((*in)._control.Node_3 == 1) ) )
        {
            l265: if (  ( ((0 != 3)) )  &&  ( ((*in)._control.channel_ch_0_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_0_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_0_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 266;
            }
            l266: if (  ( ((1 != 3)) )  &&  ( ((*in)._control.channel_ch_1_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_1_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_1_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 267;
            }
            l267: if (  ( ((2 != 3)) )  &&  ( ((*in)._control.channel_ch_2_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_2_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_2_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 268;
            }
            l268: if (  ( ((3 != 3)) )  &&  ( ((*in)._control.channel_ch_3_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_3_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_3_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 269;
            }
            l269: if (  ( ((4 != 3)) )  &&  ( ((*in)._control.channel_ch_4_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_4_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_4_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 270;
            }
            l270: if (  ( ((5 != 3)) )  &&  ( ((*in)._control.channel_ch_5_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_3.m) = ((*in).channel_ch_5_3.v);
                (*out)._control.Node_3 = 2;
                (*out)._control.channel_ch_5_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 271;
            }
            l271: if (  ( (((*in).Node_3.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 272;
            }
        }
        l272: if (  ( ((*in)._control.Node_3 == 2) ) )
        {
            l273: if (  ( (((((*in).Node_3.m / 6) != 1) || (!((*in).connected[ ((3 * 6) + ((*in).Node_3.m % 6)) ] ) || ((*in).Node_3.received[ ((*in).Node_3.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 274;
            }
            l274: if (  ( (((((*in).Node_3.m / 6) == 1) && ((*in).connected[ ((3 * 6) + ((*in).Node_3.m % 6)) ] && ((*in).Node_3.received[ ((*in).Node_3.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_3 = 1;
                ((*out).Node_3.received[ ((*out).Node_3.m % 6) ]) = (1);
                ((*out).Node_3.n) = (((*out).Node_3.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 275;
            }
        }
        l275: if (  ( ((*in)._control.Node_4 == 6) ) )
        {
            l276: if (  ( (((*in).Node_4.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 16;
                ((*out).elected) = (4);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 277;
            }
            l277: if (  ( (((*in).Node_4.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 278;
            }
        }
        l278: if (  ( ((*in)._control.Node_4 == 3) ) )
        {
            l279: if (  ( ((((*in).Node_4.j < 6) && !((*in).Node_4.received[ (*in).Node_4.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 280;
            }
            l280: if (  ( ((((*in).Node_4.n == 0) && ((*in).Node_4.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 281;
            }
        }
        l281: if (  ( ((*in)._control.Node_4 == 11) ) )
        {
            l282: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 283;
            }
            l283: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 284;
            }
        }
        l284: if (  ( ((*in)._control.Node_4 == 7) ) )
        {
            l285: if (  ( ((0 != 4)) )  &&  ( ((*in)._control.channel_ch_0_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_0_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_0_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 286;
            }
            l286: if (  ( ((1 != 4)) )  &&  ( ((*in)._control.channel_ch_1_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_1_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_1_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 287;
            }
            l287: if (  ( ((2 != 4)) )  &&  ( ((*in)._control.channel_ch_2_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_2_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_2_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 288;
            }
            l288: if (  ( ((3 != 4)) )  &&  ( ((*in)._control.channel_ch_3_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_3_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_3_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 289;
            }
            l289: if (  ( ((4 != 4)) )  &&  ( ((*in)._control.channel_ch_4_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_4_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_4_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 290;
            }
            l290: if (  ( ((5 != 4)) )  &&  ( ((*in)._control.channel_ch_5_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_5_4.v);
                (*out)._control.Node_4 = 8;
                (*out)._control.channel_ch_5_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 291;
            }
        }
        l291: if (  ( ((*in)._control.Node_4 == 8) ) )
        {
            l292: if (  ( ((((*in).Node_4.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.received[ ((*out).Node_4.m % 6) ]) = (1);
                ((*out).Node_4.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 293;
            }
            l293: if (  ( ((((*in).Node_4.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 294;
            }
        }
        l294: if (  ( ((*in)._control.Node_4 == 14) ) )
        {
            l295: if (  ( ((0 != 4)) )  &&  ( ((*in)._control.channel_ch_0_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_0_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_0_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 296;
            }
            l296: if (  ( ((1 != 4)) )  &&  ( ((*in)._control.channel_ch_1_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_1_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_1_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 297;
            }
            l297: if (  ( ((2 != 4)) )  &&  ( ((*in)._control.channel_ch_2_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_2_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_2_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 298;
            }
            l298: if (  ( ((3 != 4)) )  &&  ( ((*in)._control.channel_ch_3_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_3_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_3_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 299;
            }
            l299: if (  ( ((4 != 4)) )  &&  ( ((*in)._control.channel_ch_4_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_4_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_4_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 300;
            }
            l300: if (  ( ((5 != 4)) )  &&  ( ((*in)._control.channel_ch_5_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_5_4.v);
                (*out)._control.Node_4 = 15;
                (*out)._control.channel_ch_5_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 301;
            }
        }
        l301: if (  ( ((*in)._control.Node_4 == 15) ) )
        {
            l302: if (  ( ((((*in).Node_4.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.received[ ((*out).Node_4.m % 6) ]) = (1);
                ((*out).Node_4.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 303;
            }
        }
        l303: if (  ( ((*in)._control.Node_4 == 9) ) )
        {
            l304: if (  ( ((0 != 4)) )  &&  ( ((*in)._control.channel_ch_0_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_0_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_0_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 305;
            }
            l305: if (  ( ((1 != 4)) )  &&  ( ((*in)._control.channel_ch_1_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_1_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_1_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 306;
            }
            l306: if (  ( ((2 != 4)) )  &&  ( ((*in)._control.channel_ch_2_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_2_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_2_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 307;
            }
            l307: if (  ( ((3 != 4)) )  &&  ( ((*in)._control.channel_ch_3_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_3_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_3_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 308;
            }
            l308: if (  ( ((4 != 4)) )  &&  ( ((*in)._control.channel_ch_4_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_4_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_4_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 309;
            }
            l309: if (  ( ((5 != 4)) )  &&  ( ((*in)._control.channel_ch_5_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_5_4.v);
                (*out)._control.Node_4 = 10;
                (*out)._control.channel_ch_5_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 310;
            }
        }
        l310: if (  ( ((*in)._control.Node_4 == 10) ) )
        {
            l311: if (  ( ((((*in).Node_4.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 312;
            }
            l312: if (  ( ((((*in).Node_4.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 313;
            }
        }
        l313: if (  ( ((*in)._control.Node_4 == 0) ) )
        {
            l314: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 315;
            }
            l315: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 316;
            }
            l316: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 317;
            }
            l317: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 318;
            }
            l318: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 319;
            }
            l319: if (  ( (((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) == 1) && (*in).connected[ ((4 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 7;
                ((*out).Node_4.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 320;
            }
            l320: if (  ( ((((*in).connected[ ((4 * 6) + 0) ] + ((*in).connected[ ((4 * 6) + 1) ] + ((*in).connected[ ((4 * 6) + 2) ] + ((*in).connected[ ((4 * 6) + 3) ] + ((*in).connected[ ((4 * 6) + 4) ] + (*in).connected[ ((4 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 1;
                ((*out).Node_4.n) = (((*out).connected[ ((4 * 6) + 0) ] + ((*out).connected[ ((4 * 6) + 1) ] + ((*out).connected[ ((4 * 6) + 2) ] + ((*out).connected[ ((4 * 6) + 3) ] + ((*out).connected[ ((4 * 6) + 4) ] + (*out).connected[ ((4 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 321;
            }
        }
        l321: if (  ( ((*in)._control.Node_4 == 5) ) )
        {
            l322: if (  ( ((((*in).Node_4.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 323;
            }
            l323: if (  ( ((((*in).Node_4.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 4;
                ((*out).Node_4.received[ ((*out).Node_4.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 324;
            }
        }
        l324: if (  ( ((*in)._control.Node_4 == 4) ) )
        {
            l325: if (  ( (((0 != 4) && ((*in).Node_4.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_0_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_0_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 326;
            }
            l326: if (  ( (((1 != 4) && ((*in).Node_4.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_1_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_1_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 327;
            }
            l327: if (  ( (((2 != 4) && ((*in).Node_4.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_2_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_2_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 328;
            }
            l328: if (  ( (((3 != 4) && ((*in).Node_4.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_3_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_3_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 329;
            }
            l329: if (  ( (((4 != 4) && ((*in).Node_4.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_4_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_4_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 330;
            }
            l330: if (  ( (((5 != 4) && ((*in).Node_4.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_5_4.v);
                (*out)._control.Node_4 = 5;
                (*out)._control.channel_ch_5_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 331;
            }
            l331: if (  ( ((((*in).Node_4.received[ 0 ] + ((*in).Node_4.received[ 1 ] + ((*in).Node_4.received[ 2 ] + ((*in).Node_4.received[ 3 ] + ((*in).Node_4.received[ 4 ] + (*in).Node_4.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 332;
            }
        }
        l332: if (  ( ((*in)._control.Node_4 == 1) ) )
        {
            l333: if (  ( ((0 != 4)) )  &&  ( ((*in)._control.channel_ch_0_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_0_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_0_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 334;
            }
            l334: if (  ( ((1 != 4)) )  &&  ( ((*in)._control.channel_ch_1_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_1_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_1_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 335;
            }
            l335: if (  ( ((2 != 4)) )  &&  ( ((*in)._control.channel_ch_2_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_2_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_2_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 336;
            }
            l336: if (  ( ((3 != 4)) )  &&  ( ((*in)._control.channel_ch_3_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_3_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_3_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 337;
            }
            l337: if (  ( ((4 != 4)) )  &&  ( ((*in)._control.channel_ch_4_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_4_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_4_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 338;
            }
            l338: if (  ( ((5 != 4)) )  &&  ( ((*in)._control.channel_ch_5_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_4.m) = ((*in).channel_ch_5_4.v);
                (*out)._control.Node_4 = 2;
                (*out)._control.channel_ch_5_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 339;
            }
            l339: if (  ( (((*in).Node_4.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 340;
            }
        }
        l340: if (  ( ((*in)._control.Node_4 == 2) ) )
        {
            l341: if (  ( (((((*in).Node_4.m / 6) != 1) || (!((*in).connected[ ((4 * 6) + ((*in).Node_4.m % 6)) ] ) || ((*in).Node_4.received[ ((*in).Node_4.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 342;
            }
            l342: if (  ( (((((*in).Node_4.m / 6) == 1) && ((*in).connected[ ((4 * 6) + ((*in).Node_4.m % 6)) ] && ((*in).Node_4.received[ ((*in).Node_4.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_4 = 1;
                ((*out).Node_4.received[ ((*out).Node_4.m % 6) ]) = (1);
                ((*out).Node_4.n) = (((*out).Node_4.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 343;
            }
        }
        l343: if (  ( ((*in)._control.Node_5 == 6) ) )
        {
            l344: if (  ( (((*in).Node_5.n == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 16;
                ((*out).elected) = (5);
                ((*out).elected_num) = (((*out).elected_num + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 345;
            }
            l345: if (  ( (((*in).Node_5.n == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 346;
            }
        }
        l346: if (  ( ((*in)._control.Node_5 == 3) ) )
        {
            l347: if (  ( ((((*in).Node_5.j < 6) && !((*in).Node_5.received[ (*in).Node_5.j ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 348;
            }
            l348: if (  ( ((((*in).Node_5.n == 0) && ((*in).Node_5.j == 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 349;
            }
        }
        l349: if (  ( ((*in)._control.Node_5 == 11) ) )
        {
            l350: if (  ( (((*in).toss == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 13;
                ((*out).toss) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 351;
            }
            l351: if (  ( (((*in).toss == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 352;
            }
        }
        l352: if (  ( ((*in)._control.Node_5 == 7) ) )
        {
            l353: if (  ( ((0 != 5)) )  &&  ( ((*in)._control.channel_ch_0_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_0_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_0_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 354;
            }
            l354: if (  ( ((1 != 5)) )  &&  ( ((*in)._control.channel_ch_1_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_1_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_1_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 355;
            }
            l355: if (  ( ((2 != 5)) )  &&  ( ((*in)._control.channel_ch_2_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_2_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_2_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 356;
            }
            l356: if (  ( ((3 != 5)) )  &&  ( ((*in)._control.channel_ch_3_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_3_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_3_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 357;
            }
            l357: if (  ( ((4 != 5)) )  &&  ( ((*in)._control.channel_ch_4_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_4_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_4_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 358;
            }
            l358: if (  ( ((5 != 5)) )  &&  ( ((*in)._control.channel_ch_5_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_5_5.v);
                (*out)._control.Node_5 = 8;
                (*out)._control.channel_ch_5_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 359;
            }
        }
        l359: if (  ( ((*in)._control.Node_5 == 8) ) )
        {
            l360: if (  ( ((((*in).Node_5.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.received[ ((*out).Node_5.m % 6) ]) = (1);
                ((*out).Node_5.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 361;
            }
            l361: if (  ( ((((*in).Node_5.m / 6) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 362;
            }
        }
        l362: if (  ( ((*in)._control.Node_5 == 14) ) )
        {
            l363: if (  ( ((0 != 5)) )  &&  ( ((*in)._control.channel_ch_0_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_0_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_0_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 364;
            }
            l364: if (  ( ((1 != 5)) )  &&  ( ((*in)._control.channel_ch_1_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_1_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_1_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 365;
            }
            l365: if (  ( ((2 != 5)) )  &&  ( ((*in)._control.channel_ch_2_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_2_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_2_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 366;
            }
            l366: if (  ( ((3 != 5)) )  &&  ( ((*in)._control.channel_ch_3_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_3_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_3_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 367;
            }
            l367: if (  ( ((4 != 5)) )  &&  ( ((*in)._control.channel_ch_4_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_4_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_4_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 368;
            }
            l368: if (  ( ((5 != 5)) )  &&  ( ((*in)._control.channel_ch_5_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_5_5.v);
                (*out)._control.Node_5 = 15;
                (*out)._control.channel_ch_5_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 369;
            }
        }
        l369: if (  ( ((*in)._control.Node_5 == 15) ) )
        {
            l370: if (  ( ((((*in).Node_5.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.received[ ((*out).Node_5.m % 6) ]) = (1);
                ((*out).Node_5.n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 371;
            }
        }
        l371: if (  ( ((*in)._control.Node_5 == 9) ) )
        {
            l372: if (  ( ((0 != 5)) )  &&  ( ((*in)._control.channel_ch_0_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_0_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_0_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 373;
            }
            l373: if (  ( ((1 != 5)) )  &&  ( ((*in)._control.channel_ch_1_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_1_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_1_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 374;
            }
            l374: if (  ( ((2 != 5)) )  &&  ( ((*in)._control.channel_ch_2_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_2_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_2_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 375;
            }
            l375: if (  ( ((3 != 5)) )  &&  ( ((*in)._control.channel_ch_3_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_3_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_3_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 376;
            }
            l376: if (  ( ((4 != 5)) )  &&  ( ((*in)._control.channel_ch_4_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_4_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_4_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 377;
            }
            l377: if (  ( ((5 != 5)) )  &&  ( ((*in)._control.channel_ch_5_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_5_5.v);
                (*out)._control.Node_5 = 10;
                (*out)._control.channel_ch_5_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 378;
            }
        }
        l378: if (  ( ((*in)._control.Node_5 == 10) ) )
        {
            l379: if (  ( ((((*in).Node_5.m / 6) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 380;
            }
            l380: if (  ( ((((*in).Node_5.m / 6) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 381;
            }
        }
        l381: if (  ( ((*in)._control.Node_5 == 0) ) )
        {
            l382: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 0) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 383;
            }
            l383: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 384;
            }
            l384: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 2) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 385;
            }
            l385: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 3) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 386;
            }
            l386: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 387;
            }
            l387: if (  ( (((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) == 1) && (*in).connected[ ((5 * 6) + 5) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 7;
                ((*out).Node_5.j) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 388;
            }
            l388: if (  ( ((((*in).connected[ ((5 * 6) + 0) ] + ((*in).connected[ ((5 * 6) + 1) ] + ((*in).connected[ ((5 * 6) + 2) ] + ((*in).connected[ ((5 * 6) + 3) ] + ((*in).connected[ ((5 * 6) + 4) ] + (*in).connected[ ((5 * 6) + 5) ]))))) > 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 1;
                ((*out).Node_5.n) = (((*out).connected[ ((5 * 6) + 0) ] + ((*out).connected[ ((5 * 6) + 1) ] + ((*out).connected[ ((5 * 6) + 2) ] + ((*out).connected[ ((5 * 6) + 3) ] + ((*out).connected[ ((5 * 6) + 4) ] + (*out).connected[ ((5 * 6) + 5) ]))))));
                system_in_deadlock = false;
                *to = blob_out;
                return 389;
            }
        }
        l389: if (  ( ((*in)._control.Node_5 == 5) ) )
        {
            l390: if (  ( ((((*in).Node_5.m / 6) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 391;
            }
            l391: if (  ( ((((*in).Node_5.m / 6) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 4;
                ((*out).Node_5.received[ ((*out).Node_5.m % 6) ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 392;
            }
        }
        l392: if (  ( ((*in)._control.Node_5 == 4) ) )
        {
            l393: if (  ( (((0 != 5) && ((*in).Node_5.received[ 0 ] == 1))) )  &&  ( ((*in)._control.channel_ch_0_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_0_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_0_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 394;
            }
            l394: if (  ( (((1 != 5) && ((*in).Node_5.received[ 1 ] == 1))) )  &&  ( ((*in)._control.channel_ch_1_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_1_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_1_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 395;
            }
            l395: if (  ( (((2 != 5) && ((*in).Node_5.received[ 2 ] == 1))) )  &&  ( ((*in)._control.channel_ch_2_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_2_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_2_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 396;
            }
            l396: if (  ( (((3 != 5) && ((*in).Node_5.received[ 3 ] == 1))) )  &&  ( ((*in)._control.channel_ch_3_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_3_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_3_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 397;
            }
            l397: if (  ( (((4 != 5) && ((*in).Node_5.received[ 4 ] == 1))) )  &&  ( ((*in)._control.channel_ch_4_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_4_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_4_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 398;
            }
            l398: if (  ( (((5 != 5) && ((*in).Node_5.received[ 5 ] == 1))) )  &&  ( ((*in)._control.channel_ch_5_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_5_5.v);
                (*out)._control.Node_5 = 5;
                (*out)._control.channel_ch_5_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 399;
            }
            l399: if (  ( ((((*in).Node_5.received[ 0 ] + ((*in).Node_5.received[ 1 ] + ((*in).Node_5.received[ 2 ] + ((*in).Node_5.received[ 3 ] + ((*in).Node_5.received[ 4 ] + (*in).Node_5.received[ 5 ]))))) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 400;
            }
        }
        l400: if (  ( ((*in)._control.Node_5 == 1) ) )
        {
            l401: if (  ( ((0 != 5)) )  &&  ( ((*in)._control.channel_ch_0_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_0_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_0_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 402;
            }
            l402: if (  ( ((1 != 5)) )  &&  ( ((*in)._control.channel_ch_1_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_1_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_1_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 403;
            }
            l403: if (  ( ((2 != 5)) )  &&  ( ((*in)._control.channel_ch_2_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_2_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_2_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 404;
            }
            l404: if (  ( ((3 != 5)) )  &&  ( ((*in)._control.channel_ch_3_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_3_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_3_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 405;
            }
            l405: if (  ( ((4 != 5)) )  &&  ( ((*in)._control.channel_ch_4_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_4_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_4_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 406;
            }
            l406: if (  ( ((5 != 5)) )  &&  ( ((*in)._control.channel_ch_5_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Node_5.m) = ((*in).channel_ch_5_5.v);
                (*out)._control.Node_5 = 2;
                (*out)._control.channel_ch_5_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 407;
            }
            l407: if (  ( (((*in).Node_5.n <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 408;
            }
        }
        l408: if (  ( ((*in)._control.Node_5 == 2) ) )
        {
            l409: if (  ( (((((*in).Node_5.m / 6) != 1) || (!((*in).connected[ ((5 * 6) + ((*in).Node_5.m % 6)) ] ) || ((*in).Node_5.received[ ((*in).Node_5.m % 6) ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 17;
                system_in_deadlock = false;
                *to = blob_out;
                return 410;
            }
            l410: if (  ( (((((*in).Node_5.m / 6) == 1) && ((*in).connected[ ((5 * 6) + ((*in).Node_5.m % 6)) ] && ((*in).Node_5.received[ ((*in).Node_5.m % 6) ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Node_5 = 1;
                ((*out).Node_5.received[ ((*out).Node_5.m % 6) ]) = (1);
                ((*out).Node_5.n) = (((*out).Node_5.n - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 411;
            }
        }
        l411: if (  ( ((*in)._control.channel_ch_0_0 == 0) ) )
        {
            l412: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((0 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_0.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_0 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 413;
            }
            l413: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 0) ] && ((*in).Node_0.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_0.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_0 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 414;
            }
            l414: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((0 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_0.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_0 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 415;
            }
            l415: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((0 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_0.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_0 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 416;
            }
            l416: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((0 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_0.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_0 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 417;
            }
        }
        l417: if (  ( ((*in)._control.channel_ch_1_0 == 0) ) )
        {
            l418: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((0 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_0.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_0 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 419;
            }
            l419: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 0) ] && ((*in).Node_1.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_0.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_0 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 420;
            }
            l420: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((0 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_0.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_0 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 421;
            }
            l421: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((0 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_0.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_0 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 422;
            }
            l422: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((0 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_0.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_0 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 423;
            }
        }
        l423: if (  ( ((*in)._control.channel_ch_2_0 == 0) ) )
        {
            l424: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((0 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_0.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_0 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 425;
            }
            l425: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 0) ] && ((*in).Node_2.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_0.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_0 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 426;
            }
            l426: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((0 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_0.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_0 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 427;
            }
            l427: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((0 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_0.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_0 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 428;
            }
            l428: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((0 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_0.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_0 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 429;
            }
        }
        l429: if (  ( ((*in)._control.channel_ch_3_0 == 0) ) )
        {
            l430: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((0 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_0.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_0 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 431;
            }
            l431: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 0) ] && ((*in).Node_3.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_0.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_0 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 432;
            }
            l432: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((0 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_0.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_0 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 433;
            }
            l433: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((0 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_0.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_0 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 434;
            }
            l434: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((0 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_0.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_0 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 435;
            }
        }
        l435: if (  ( ((*in)._control.channel_ch_4_0 == 0) ) )
        {
            l436: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((0 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_0.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_0 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 437;
            }
            l437: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 0) ] && ((*in).Node_4.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_0.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_0 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 438;
            }
            l438: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((0 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_0.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_0 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 439;
            }
            l439: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((0 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_0.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_0 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 440;
            }
            l440: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((0 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_0.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_0 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 441;
            }
        }
        l441: if (  ( ((*in)._control.channel_ch_5_0 == 0) ) )
        {
            l442: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((0 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_0.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_0 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 443;
            }
            l443: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 0) ] && ((*in).Node_5.received[ 0 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_0.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_0 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 444;
            }
            l444: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((0 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_0.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_0 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 445;
            }
            l445: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((0 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_0.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_0 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 446;
            }
            l446: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((0 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_0.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_0 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 447;
            }
        }
        l447: if (  ( ((*in)._control.channel_ch_0_1 == 0) ) )
        {
            l448: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((1 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_1.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_1 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 449;
            }
            l449: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 1) ] && ((*in).Node_0.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_1.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_1 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 450;
            }
            l450: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((1 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_1.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_1 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 451;
            }
            l451: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((1 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_1.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_1 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 452;
            }
            l452: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((1 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_1.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_1 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 453;
            }
        }
        l453: if (  ( ((*in)._control.channel_ch_1_1 == 0) ) )
        {
            l454: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((1 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_1.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_1 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 455;
            }
            l455: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 1) ] && ((*in).Node_1.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_1.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_1 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 456;
            }
            l456: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((1 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_1.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_1 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 457;
            }
            l457: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((1 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_1.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_1 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 458;
            }
            l458: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((1 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_1.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_1 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 459;
            }
        }
        l459: if (  ( ((*in)._control.channel_ch_2_1 == 0) ) )
        {
            l460: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((1 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_1.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_1 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 461;
            }
            l461: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 1) ] && ((*in).Node_2.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_1.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_1 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 462;
            }
            l462: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((1 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_1.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_1 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 463;
            }
            l463: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((1 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_1.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_1 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 464;
            }
            l464: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((1 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_1.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_1 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 465;
            }
        }
        l465: if (  ( ((*in)._control.channel_ch_3_1 == 0) ) )
        {
            l466: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((1 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_1.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_1 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 467;
            }
            l467: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 1) ] && ((*in).Node_3.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_1.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_1 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 468;
            }
            l468: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((1 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_1.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_1 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 469;
            }
            l469: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((1 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_1.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_1 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 470;
            }
            l470: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((1 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_1.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_1 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 471;
            }
        }
        l471: if (  ( ((*in)._control.channel_ch_4_1 == 0) ) )
        {
            l472: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((1 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_1.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_1 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 473;
            }
            l473: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 1) ] && ((*in).Node_4.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_1.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_1 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 474;
            }
            l474: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((1 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_1.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_1 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 475;
            }
            l475: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((1 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_1.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_1 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 476;
            }
            l476: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((1 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_1.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_1 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 477;
            }
        }
        l477: if (  ( ((*in)._control.channel_ch_5_1 == 0) ) )
        {
            l478: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((1 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_1.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_1 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 479;
            }
            l479: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 1) ] && ((*in).Node_5.received[ 1 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_1.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_1 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 480;
            }
            l480: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((1 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_1.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_1 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 481;
            }
            l481: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((1 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_1.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_1 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 482;
            }
            l482: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((1 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_1.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_1 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 483;
            }
        }
        l483: if (  ( ((*in)._control.channel_ch_0_2 == 0) ) )
        {
            l484: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((2 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_2.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_2 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 485;
            }
            l485: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 2) ] && ((*in).Node_0.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_2.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_2 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 486;
            }
            l486: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((2 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_2.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_2 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 487;
            }
            l487: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((2 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_2.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_2 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 488;
            }
            l488: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((2 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_2.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_2 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 489;
            }
        }
        l489: if (  ( ((*in)._control.channel_ch_1_2 == 0) ) )
        {
            l490: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((2 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_2.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_2 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 491;
            }
            l491: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 2) ] && ((*in).Node_1.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_2.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_2 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 492;
            }
            l492: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((2 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_2.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_2 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 493;
            }
            l493: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((2 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_2.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_2 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 494;
            }
            l494: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((2 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_2.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_2 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 495;
            }
        }
        l495: if (  ( ((*in)._control.channel_ch_2_2 == 0) ) )
        {
            l496: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((2 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_2.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_2 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 497;
            }
            l497: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 2) ] && ((*in).Node_2.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_2.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_2 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 498;
            }
            l498: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((2 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_2.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_2 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 499;
            }
            l499: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((2 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_2.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_2 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 500;
            }
            l500: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((2 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_2.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_2 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 501;
            }
        }
        l501: if (  ( ((*in)._control.channel_ch_3_2 == 0) ) )
        {
            l502: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((2 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_2.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_2 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 503;
            }
            l503: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 2) ] && ((*in).Node_3.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_2.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_2 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 504;
            }
            l504: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((2 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_2.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_2 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 505;
            }
            l505: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((2 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_2.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_2 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 506;
            }
            l506: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((2 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_2.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_2 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 507;
            }
        }
        l507: if (  ( ((*in)._control.channel_ch_4_2 == 0) ) )
        {
            l508: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((2 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_2.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_2 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 509;
            }
            l509: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 2) ] && ((*in).Node_4.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_2.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_2 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 510;
            }
            l510: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((2 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_2.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_2 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 511;
            }
            l511: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((2 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_2.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_2 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 512;
            }
            l512: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((2 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_2.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_2 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 513;
            }
        }
        l513: if (  ( ((*in)._control.channel_ch_5_2 == 0) ) )
        {
            l514: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((2 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_2.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_2 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 515;
            }
            l515: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 2) ] && ((*in).Node_5.received[ 2 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_2.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_2 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 516;
            }
            l516: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((2 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_2.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_2 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 517;
            }
            l517: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((2 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_2.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_2 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 518;
            }
            l518: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((2 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_2.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_2 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 519;
            }
        }
        l519: if (  ( ((*in)._control.channel_ch_0_3 == 0) ) )
        {
            l520: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((3 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_3.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_3 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 521;
            }
            l521: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 3) ] && ((*in).Node_0.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_3.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_3 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 522;
            }
            l522: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((3 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_3.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_3 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 523;
            }
            l523: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((3 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_3.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_3 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 524;
            }
            l524: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((3 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_3.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_3 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 525;
            }
        }
        l525: if (  ( ((*in)._control.channel_ch_1_3 == 0) ) )
        {
            l526: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((3 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_3.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_3 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 527;
            }
            l527: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 3) ] && ((*in).Node_1.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_3.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_3 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 528;
            }
            l528: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((3 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_3.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_3 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 529;
            }
            l529: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((3 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_3.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_3 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 530;
            }
            l530: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((3 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_3.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_3 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 531;
            }
        }
        l531: if (  ( ((*in)._control.channel_ch_2_3 == 0) ) )
        {
            l532: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((3 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_3.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_3 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 533;
            }
            l533: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 3) ] && ((*in).Node_2.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_3.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_3 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 534;
            }
            l534: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((3 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_3.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_3 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 535;
            }
            l535: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((3 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_3.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_3 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 536;
            }
            l536: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((3 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_3.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_3 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 537;
            }
        }
        l537: if (  ( ((*in)._control.channel_ch_3_3 == 0) ) )
        {
            l538: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((3 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_3.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_3 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 539;
            }
            l539: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 3) ] && ((*in).Node_3.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_3.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_3 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 540;
            }
            l540: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((3 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_3.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_3 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 541;
            }
            l541: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((3 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_3.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_3 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 542;
            }
            l542: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((3 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_3.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_3 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 543;
            }
        }
        l543: if (  ( ((*in)._control.channel_ch_4_3 == 0) ) )
        {
            l544: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((3 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_3.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_3 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 545;
            }
            l545: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 3) ] && ((*in).Node_4.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_3.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_3 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 546;
            }
            l546: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((3 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_3.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_3 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 547;
            }
            l547: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((3 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_3.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_3 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 548;
            }
            l548: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((3 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_3.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_3 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 549;
            }
        }
        l549: if (  ( ((*in)._control.channel_ch_5_3 == 0) ) )
        {
            l550: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((3 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_3.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_3 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 551;
            }
            l551: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 3) ] && ((*in).Node_5.received[ 3 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_3.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_3 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 552;
            }
            l552: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((3 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_3.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_3 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 553;
            }
            l553: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((3 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_3.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_3 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 554;
            }
            l554: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((3 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_3.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_3 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 555;
            }
        }
        l555: if (  ( ((*in)._control.channel_ch_0_4 == 0) ) )
        {
            l556: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((4 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_4.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_4 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 557;
            }
            l557: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 4) ] && ((*in).Node_0.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_4.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_4 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 558;
            }
            l558: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((4 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_4.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_4 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 559;
            }
            l559: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((4 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_4.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_4 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 560;
            }
            l560: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((4 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_4.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_4 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 561;
            }
        }
        l561: if (  ( ((*in)._control.channel_ch_1_4 == 0) ) )
        {
            l562: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((4 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_4.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_4 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 563;
            }
            l563: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 4) ] && ((*in).Node_1.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_4.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_4 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 564;
            }
            l564: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((4 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_4.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_4 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 565;
            }
            l565: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((4 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_4.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_4 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 566;
            }
            l566: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((4 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_4.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_4 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 567;
            }
        }
        l567: if (  ( ((*in)._control.channel_ch_2_4 == 0) ) )
        {
            l568: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((4 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_4.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_4 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 569;
            }
            l569: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 4) ] && ((*in).Node_2.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_4.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_4 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 570;
            }
            l570: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((4 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_4.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_4 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 571;
            }
            l571: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((4 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_4.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_4 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 572;
            }
            l572: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((4 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_4.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_4 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 573;
            }
        }
        l573: if (  ( ((*in)._control.channel_ch_3_4 == 0) ) )
        {
            l574: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((4 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_4.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_4 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 575;
            }
            l575: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 4) ] && ((*in).Node_3.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_4.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_4 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 576;
            }
            l576: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((4 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_4.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_4 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 577;
            }
            l577: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((4 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_4.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_4 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 578;
            }
            l578: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((4 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_4.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_4 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 579;
            }
        }
        l579: if (  ( ((*in)._control.channel_ch_4_4 == 0) ) )
        {
            l580: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((4 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_4.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_4 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 581;
            }
            l581: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 4) ] && ((*in).Node_4.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_4.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_4 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 582;
            }
            l582: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((4 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_4.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_4 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 583;
            }
            l583: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((4 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_4.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_4 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 584;
            }
            l584: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((4 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_4.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_4 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 585;
            }
        }
        l585: if (  ( ((*in)._control.channel_ch_5_4 == 0) ) )
        {
            l586: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((4 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_4.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_4 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 587;
            }
            l587: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 4) ] && ((*in).Node_5.received[ 4 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_4.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_4 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 588;
            }
            l588: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((4 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_4.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_4 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 589;
            }
            l589: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((4 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_4.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_4 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 590;
            }
            l590: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((4 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_4.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_4 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 591;
            }
        }
        l591: if (  ( ((*in)._control.channel_ch_0_5 == 0) ) )
        {
            l592: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( (((5 == (*in).Node_0.j) && (*in).Node_0.received[ (*in).Node_0.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_5.v) = (((2 * 6) + 0));
                (*out)._control.channel_ch_0_5 = 1;
                (*out)._control.Node_0 = 3;
                ((*out).Node_0.j) = (((*out).Node_0.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 593;
            }
            l593: if (  ( ((*in)._control.Node_0 == 3) )  &&  ( ((((*in).Node_0.n == 1) && (((*in).Node_0.j == 6) && ((*in).connected[ ((0 * 6) + 5) ] && ((*in).Node_0.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_5.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_5 = 1;
                (*out)._control.Node_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 594;
            }
            l594: if (  ( ((*in)._control.Node_0 == 7) )  &&  ( ((5 == (*in).Node_0.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_5.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_5 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 595;
            }
            l595: if (  ( ((*in)._control.Node_0 == 12) )  &&  ( ((5 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_5.v) = (((3 * 6) + 0));
                (*out)._control.channel_ch_0_5 = 1;
                (*out)._control.Node_0 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 596;
            }
            l596: if (  ( ((*in)._control.Node_0 == 13) )  &&  ( ((5 == ((*in).Node_0.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_0_5.v) = (((1 * 6) + 0));
                (*out)._control.channel_ch_0_5 = 1;
                (*out)._control.Node_0 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 597;
            }
        }
        l597: if (  ( ((*in)._control.channel_ch_1_5 == 0) ) )
        {
            l598: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( (((5 == (*in).Node_1.j) && (*in).Node_1.received[ (*in).Node_1.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_5.v) = (((2 * 6) + 1));
                (*out)._control.channel_ch_1_5 = 1;
                (*out)._control.Node_1 = 3;
                ((*out).Node_1.j) = (((*out).Node_1.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 599;
            }
            l599: if (  ( ((*in)._control.Node_1 == 3) )  &&  ( ((((*in).Node_1.n == 1) && (((*in).Node_1.j == 6) && ((*in).connected[ ((1 * 6) + 5) ] && ((*in).Node_1.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_5.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_5 = 1;
                (*out)._control.Node_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 600;
            }
            l600: if (  ( ((*in)._control.Node_1 == 7) )  &&  ( ((5 == (*in).Node_1.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_5.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_5 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 601;
            }
            l601: if (  ( ((*in)._control.Node_1 == 12) )  &&  ( ((5 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_5.v) = (((3 * 6) + 1));
                (*out)._control.channel_ch_1_5 = 1;
                (*out)._control.Node_1 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 602;
            }
            l602: if (  ( ((*in)._control.Node_1 == 13) )  &&  ( ((5 == ((*in).Node_1.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_1_5.v) = (((1 * 6) + 1));
                (*out)._control.channel_ch_1_5 = 1;
                (*out)._control.Node_1 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 603;
            }
        }
        l603: if (  ( ((*in)._control.channel_ch_2_5 == 0) ) )
        {
            l604: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( (((5 == (*in).Node_2.j) && (*in).Node_2.received[ (*in).Node_2.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_5.v) = (((2 * 6) + 2));
                (*out)._control.channel_ch_2_5 = 1;
                (*out)._control.Node_2 = 3;
                ((*out).Node_2.j) = (((*out).Node_2.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 605;
            }
            l605: if (  ( ((*in)._control.Node_2 == 3) )  &&  ( ((((*in).Node_2.n == 1) && (((*in).Node_2.j == 6) && ((*in).connected[ ((2 * 6) + 5) ] && ((*in).Node_2.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_5.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_5 = 1;
                (*out)._control.Node_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 606;
            }
            l606: if (  ( ((*in)._control.Node_2 == 7) )  &&  ( ((5 == (*in).Node_2.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_5.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_5 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 607;
            }
            l607: if (  ( ((*in)._control.Node_2 == 12) )  &&  ( ((5 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_5.v) = (((3 * 6) + 2));
                (*out)._control.channel_ch_2_5 = 1;
                (*out)._control.Node_2 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 608;
            }
            l608: if (  ( ((*in)._control.Node_2 == 13) )  &&  ( ((5 == ((*in).Node_2.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_2_5.v) = (((1 * 6) + 2));
                (*out)._control.channel_ch_2_5 = 1;
                (*out)._control.Node_2 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 609;
            }
        }
        l609: if (  ( ((*in)._control.channel_ch_3_5 == 0) ) )
        {
            l610: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( (((5 == (*in).Node_3.j) && (*in).Node_3.received[ (*in).Node_3.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_5.v) = (((2 * 6) + 3));
                (*out)._control.channel_ch_3_5 = 1;
                (*out)._control.Node_3 = 3;
                ((*out).Node_3.j) = (((*out).Node_3.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 611;
            }
            l611: if (  ( ((*in)._control.Node_3 == 3) )  &&  ( ((((*in).Node_3.n == 1) && (((*in).Node_3.j == 6) && ((*in).connected[ ((3 * 6) + 5) ] && ((*in).Node_3.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_5.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_5 = 1;
                (*out)._control.Node_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 612;
            }
            l612: if (  ( ((*in)._control.Node_3 == 7) )  &&  ( ((5 == (*in).Node_3.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_5.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_5 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 613;
            }
            l613: if (  ( ((*in)._control.Node_3 == 12) )  &&  ( ((5 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_5.v) = (((3 * 6) + 3));
                (*out)._control.channel_ch_3_5 = 1;
                (*out)._control.Node_3 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 614;
            }
            l614: if (  ( ((*in)._control.Node_3 == 13) )  &&  ( ((5 == ((*in).Node_3.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_3_5.v) = (((1 * 6) + 3));
                (*out)._control.channel_ch_3_5 = 1;
                (*out)._control.Node_3 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 615;
            }
        }
        l615: if (  ( ((*in)._control.channel_ch_4_5 == 0) ) )
        {
            l616: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( (((5 == (*in).Node_4.j) && (*in).Node_4.received[ (*in).Node_4.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_5.v) = (((2 * 6) + 4));
                (*out)._control.channel_ch_4_5 = 1;
                (*out)._control.Node_4 = 3;
                ((*out).Node_4.j) = (((*out).Node_4.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 617;
            }
            l617: if (  ( ((*in)._control.Node_4 == 3) )  &&  ( ((((*in).Node_4.n == 1) && (((*in).Node_4.j == 6) && ((*in).connected[ ((4 * 6) + 5) ] && ((*in).Node_4.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_5.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_5 = 1;
                (*out)._control.Node_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 618;
            }
            l618: if (  ( ((*in)._control.Node_4 == 7) )  &&  ( ((5 == (*in).Node_4.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_5.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_5 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 619;
            }
            l619: if (  ( ((*in)._control.Node_4 == 12) )  &&  ( ((5 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_5.v) = (((3 * 6) + 4));
                (*out)._control.channel_ch_4_5 = 1;
                (*out)._control.Node_4 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 620;
            }
            l620: if (  ( ((*in)._control.Node_4 == 13) )  &&  ( ((5 == ((*in).Node_4.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_4_5.v) = (((1 * 6) + 4));
                (*out)._control.channel_ch_4_5 = 1;
                (*out)._control.Node_4 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 621;
            }
        }
        l621: if (  ( ((*in)._control.channel_ch_5_5 == 0) ) )
        {
            l622: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( (((5 == (*in).Node_5.j) && (*in).Node_5.received[ (*in).Node_5.j ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_5.v) = (((2 * 6) + 5));
                (*out)._control.channel_ch_5_5 = 1;
                (*out)._control.Node_5 = 3;
                ((*out).Node_5.j) = (((*out).Node_5.j + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 623;
            }
            l623: if (  ( ((*in)._control.Node_5 == 3) )  &&  ( ((((*in).Node_5.n == 1) && (((*in).Node_5.j == 6) && ((*in).connected[ ((5 * 6) + 5) ] && ((*in).Node_5.received[ 5 ] == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_5.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_5 = 1;
                (*out)._control.Node_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 624;
            }
            l624: if (  ( ((*in)._control.Node_5 == 7) )  &&  ( ((5 == (*in).Node_5.j)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_5.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_5 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 625;
            }
            l625: if (  ( ((*in)._control.Node_5 == 12) )  &&  ( ((5 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_5.v) = (((3 * 6) + 5));
                (*out)._control.channel_ch_5_5 = 1;
                (*out)._control.Node_5 = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 626;
            }
            l626: if (  ( ((*in)._control.Node_5 == 13) )  &&  ( ((5 == ((*in).Node_5.m % 6))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ch_5_5.v) = (((1 * 6) + 5));
                (*out)._control.channel_ch_5_5 = 1;
                (*out)._control.Node_5 = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 627;
            }
        }
    }
    l627: if (  ( system_in_deadlock ) )
    {
    }
    l628: return 0;
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
        case 469: goto l469;
        case 470: goto l470;
        case 471: goto l471;
        case 472: goto l472;
        case 473: goto l473;
        case 474: goto l474;
        case 475: goto l475;
        case 476: goto l476;
        case 477: goto l477;
        case 478: goto l478;
        case 479: goto l479;
        case 480: goto l480;
        case 481: goto l481;
        case 482: goto l482;
        case 483: goto l483;
        case 484: goto l484;
        case 485: goto l485;
        case 486: goto l486;
        case 487: goto l487;
        case 488: goto l488;
        case 489: goto l489;
        case 490: goto l490;
        case 491: goto l491;
        case 492: goto l492;
        case 493: goto l493;
        case 494: goto l494;
        case 495: goto l495;
        case 496: goto l496;
        case 497: goto l497;
        case 498: goto l498;
        case 499: goto l499;
        case 500: goto l500;
        case 501: goto l501;
        case 502: goto l502;
        case 503: goto l503;
        case 504: goto l504;
        case 505: goto l505;
        case 506: goto l506;
        case 507: goto l507;
        case 508: goto l508;
        case 509: goto l509;
        case 510: goto l510;
        case 511: goto l511;
        case 512: goto l512;
        case 513: goto l513;
        case 514: goto l514;
        case 515: goto l515;
        case 516: goto l516;
        case 517: goto l517;
        case 518: goto l518;
        case 519: goto l519;
        case 520: goto l520;
        case 521: goto l521;
        case 522: goto l522;
        case 523: goto l523;
        case 524: goto l524;
        case 525: goto l525;
        case 526: goto l526;
        case 527: goto l527;
        case 528: goto l528;
        case 529: goto l529;
        case 530: goto l530;
        case 531: goto l531;
        case 532: goto l532;
        case 533: goto l533;
        case 534: goto l534;
        case 535: goto l535;
        case 536: goto l536;
        case 537: goto l537;
        case 538: goto l538;
        case 539: goto l539;
        case 540: goto l540;
        case 541: goto l541;
        case 542: goto l542;
        case 543: goto l543;
        case 544: goto l544;
        case 545: goto l545;
        case 546: goto l546;
        case 547: goto l547;
        case 548: goto l548;
        case 549: goto l549;
        case 550: goto l550;
        case 551: goto l551;
        case 552: goto l552;
        case 553: goto l553;
        case 554: goto l554;
        case 555: goto l555;
        case 556: goto l556;
        case 557: goto l557;
        case 558: goto l558;
        case 559: goto l559;
        case 560: goto l560;
        case 561: goto l561;
        case 562: goto l562;
        case 563: goto l563;
        case 564: goto l564;
        case 565: goto l565;
        case 566: goto l566;
        case 567: goto l567;
        case 568: goto l568;
        case 569: goto l569;
        case 570: goto l570;
        case 571: goto l571;
        case 572: goto l572;
        case 573: goto l573;
        case 574: goto l574;
        case 575: goto l575;
        case 576: goto l576;
        case 577: goto l577;
        case 578: goto l578;
        case 579: goto l579;
        case 580: goto l580;
        case 581: goto l581;
        case 582: goto l582;
        case 583: goto l583;
        case 584: goto l584;
        case 585: goto l585;
        case 586: goto l586;
        case 587: goto l587;
        case 588: goto l588;
        case 589: goto l589;
        case 590: goto l590;
        case 591: goto l591;
        case 592: goto l592;
        case 593: goto l593;
        case 594: goto l594;
        case 595: goto l595;
        case 596: goto l596;
        case 597: goto l597;
        case 598: goto l598;
        case 599: goto l599;
        case 600: goto l600;
        case 601: goto l601;
        case 602: goto l602;
        case 603: goto l603;
        case 604: goto l604;
        case 605: goto l605;
        case 606: goto l606;
        case 607: goto l607;
        case 608: goto l608;
        case 609: goto l609;
        case 610: goto l610;
        case 611: goto l611;
        case 612: goto l612;
        case 613: goto l613;
        case 614: goto l614;
        case 615: goto l615;
        case 616: goto l616;
        case 617: goto l617;
        case 618: goto l618;
        case 619: goto l619;
        case 620: goto l620;
        case 621: goto l621;
        case 622: goto l622;
        case 623: goto l623;
        case 624: goto l624;
        case 625: goto l625;
        case 626: goto l626;
        case 627: goto l627;
        case 628: goto l628;
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
