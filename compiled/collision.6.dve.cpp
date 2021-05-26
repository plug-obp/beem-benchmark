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
        uint16_t Medium:3;
        uint16_t Slave1:2;
        uint16_t User1:2;
        uint16_t Slave2:2;
        uint16_t User2:2;
        uint16_t Slave3:2;
        uint16_t User3:2;
        uint16_t Slave4:2;
        uint16_t User4:2;
        uint16_t Slave5:2;
        uint16_t User5:2;
        uint16_t Master:2;
    }
    __attribute__((__packed__)) _control;
    struct
    {
        int16_t m;
        uint8_t i;
    }
    __attribute__((__packed__)) Medium;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) Slave1;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) User1;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) Slave2;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) User2;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) Slave3;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) User3;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) Slave4;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) User4;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) Slave5;
    struct
    {
        int16_t m;
    }
    __attribute__((__packed__)) User5;
    struct
    {
        uint8_t next;
        int16_t m;
    }
    __attribute__((__packed__)) Master;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out._control.Medium = 0;
    _out._control.Slave1 = 0;
    _out._control.User1 = 0;
    _out._control.Slave2 = 0;
    _out._control.User2 = 0;
    _out._control.Slave3 = 0;
    _out._control.User3 = 0;
    _out._control.Slave4 = 0;
    _out._control.User4 = 0;
    _out._control.Slave5 = 0;
    _out._control.User5 = 0;
    _out.Master.next = 1;
    _out._control.Master = 0;
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
        l3: if (  ( ((*in)._control.Medium == 2) ) )
        {
            l4: if (  ( (((*in).Medium.i == ((*in).Medium.m % 10))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).Medium.i != ((*in).Medium.m % 10)) && ((*in).Medium.i <= 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( (((*in).Medium.i == (5 + 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Medium = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.Medium == 1) ) )
        {
            l8: if (  ( ((*in)._control.Slave1 == 2) )  &&  ( (((*in).Slave1.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((1 + ((((*in).Slave1.m % 10) * 10) + ((((*in).Slave1.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((*in)._control.Slave2 == 2) )  &&  ( (((*in).Slave2.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((2 + ((((*in).Slave2.m % 10) * 10) + ((((*in).Slave2.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.Slave3 == 2) )  &&  ( (((*in).Slave3.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((3 + ((((*in).Slave3.m % 10) * 10) + ((((*in).Slave3.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((*in)._control.Slave4 == 2) )  &&  ( (((*in).Slave4.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((4 + ((((*in).Slave4.m % 10) * 10) + ((((*in).Slave4.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((*in)._control.Slave5 == 2) )  &&  ( (((*in).Slave5.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((5 + ((((*in).Slave5.m % 10) * 10) + ((((*in).Slave5.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((*in)._control.Master == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((0 + (((*in).Master.next * 10) + (0 * (10 * 10)))));
                (*out)._control.Medium = 3;
                (*out)._control.Master = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
        l15: if (  ( ((*in)._control.Medium == 0) ) )
        {
            l16: if (  ( ((*in)._control.Slave1 == 2) )  &&  ( (((*in).Slave1.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((1 + ((((*in).Slave1.m % 10) * 10) + ((((*in).Slave1.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.Slave2 == 2) )  &&  ( (((*in).Slave2.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((2 + ((((*in).Slave2.m % 10) * 10) + ((((*in).Slave2.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Slave3 == 2) )  &&  ( (((*in).Slave3.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((3 + ((((*in).Slave3.m % 10) * 10) + ((((*in).Slave3.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Slave4 == 2) )  &&  ( (((*in).Slave4.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((4 + ((((*in).Slave4.m % 10) * 10) + ((((*in).Slave4.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.Slave5 == 2) )  &&  ( (((*in).Slave5.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((5 + ((((*in).Slave5.m % 10) * 10) + ((((*in).Slave5.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.Master == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((0 + (((*in).Master.next * 10) + (0 * (10 * 10)))));
                (*out)._control.Medium = 0;
                (*out)._control.Master = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((*in)._control.Slave1 == 2) )  &&  ( (((*in).Slave1.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((1 + ((((*in).Slave1.m % 10) * 10) + ((((*in).Slave1.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.Slave2 == 2) )  &&  ( (((*in).Slave2.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((2 + ((((*in).Slave2.m % 10) * 10) + ((((*in).Slave2.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((*in)._control.Slave3 == 2) )  &&  ( (((*in).Slave3.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((3 + ((((*in).Slave3.m % 10) * 10) + ((((*in).Slave3.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( ((*in)._control.Slave4 == 2) )  &&  ( (((*in).Slave4.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((4 + ((((*in).Slave4.m % 10) * 10) + ((((*in).Slave4.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((*in)._control.Slave5 == 2) )  &&  ( (((*in).Slave5.m != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((5 + ((((*in).Slave5.m % 10) * 10) + ((((*in).Slave5.m % (10 * 10)) / 10) * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((*in)._control.Master == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Medium.m) = ((0 + (((*in).Master.next * 10) + (0 * (10 * 10)))));
                (*out)._control.Medium = 1;
                (*out)._control.Master = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
        }
        l28: if (  ( ((*in)._control.Slave1 == 2) ) )
        {
            l29: if (  ( (((*in).Slave1.m == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.Slave1 == 1) ) )
        {
            l31: if (  ( (((((*in).Slave1.m % (10 * 10)) / 10) != 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((((((*in).Slave1.m % (10 * 10)) / 10) == 1) && (((*in).Slave1.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave1.m) = (0);
                (*out)._control.Slave1 = 2;
                (*out)._control.User1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((((((*in).Slave1.m % (10 * 10)) / 10) == 1) && (((*in).Slave1.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave1.m) = ((2 + ((2 * 10) + (0 * (10 * 10)))));
                (*out)._control.Slave1 = 2;
                (*out)._control.User1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.Slave1 == 0) ) )
        {
            l35: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((1 != ((*in).Medium.m % 10)) && (1 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave1.m) = ((*in).Medium.m);
                (*out)._control.Slave1 = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
        }
        l36: if (  ( ((*in)._control.User1 == 1) ) )
        {
            l37: if (  ( ((1 == (*in).User1.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( ((1 != (*in).User1.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
        }
        l39: if (  ( ((*in)._control.User1 == 0) ) )
        {
            l40: if (  ( ((*in)._control.Slave1 == 1) )  &&  ( ((((((*in).Slave1.m % (10 * 10)) / 10) == 1) && (((*in).Slave1.m / (10 * 10)) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User1.m) = (((*in).Slave1.m / (10 * 10)));
                (*out)._control.User1 = 1;
                (*out)._control.Slave1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.Slave2 == 2) ) )
        {
            l42: if (  ( (((*in).Slave2.m == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
        }
        l43: if (  ( ((*in)._control.Slave2 == 1) ) )
        {
            l44: if (  ( (((((*in).Slave2.m % (10 * 10)) / 10) != 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((((((*in).Slave2.m % (10 * 10)) / 10) == 2) && (((*in).Slave2.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave2.m) = (0);
                (*out)._control.Slave2 = 2;
                (*out)._control.User2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( ((((((*in).Slave2.m % (10 * 10)) / 10) == 2) && (((*in).Slave2.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave2.m) = ((3 + ((3 * 10) + (0 * (10 * 10)))));
                (*out)._control.Slave2 = 2;
                (*out)._control.User2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
        }
        l47: if (  ( ((*in)._control.Slave2 == 0) ) )
        {
            l48: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((2 != ((*in).Medium.m % 10)) && (2 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave2.m) = ((*in).Medium.m);
                (*out)._control.Slave2 = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.User2 == 1) ) )
        {
            l50: if (  ( ((2 == (*in).User2.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((2 != (*in).User2.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User2 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
        }
        l52: if (  ( ((*in)._control.User2 == 0) ) )
        {
            l53: if (  ( ((*in)._control.Slave2 == 1) )  &&  ( ((((((*in).Slave2.m % (10 * 10)) / 10) == 2) && (((*in).Slave2.m / (10 * 10)) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User2.m) = (((*in).Slave2.m / (10 * 10)));
                (*out)._control.User2 = 1;
                (*out)._control.Slave2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.Slave3 == 2) ) )
        {
            l55: if (  ( (((*in).Slave3.m == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
        }
        l56: if (  ( ((*in)._control.Slave3 == 1) ) )
        {
            l57: if (  ( (((((*in).Slave3.m % (10 * 10)) / 10) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( ((((((*in).Slave3.m % (10 * 10)) / 10) == 3) && (((*in).Slave3.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User3 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave3.m) = (0);
                (*out)._control.Slave3 = 2;
                (*out)._control.User3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( ((((((*in).Slave3.m % (10 * 10)) / 10) == 3) && (((*in).Slave3.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User3 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave3.m) = ((4 + ((4 * 10) + (0 * (10 * 10)))));
                (*out)._control.Slave3 = 2;
                (*out)._control.User3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
        }
        l60: if (  ( ((*in)._control.Slave3 == 0) ) )
        {
            l61: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((3 != ((*in).Medium.m % 10)) && (3 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave3.m) = ((*in).Medium.m);
                (*out)._control.Slave3 = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
        l62: if (  ( ((*in)._control.User3 == 1) ) )
        {
            l63: if (  ( ((3 == (*in).User3.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( ((3 != (*in).User3.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User3 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.User3 == 0) ) )
        {
            l66: if (  ( ((*in)._control.Slave3 == 1) )  &&  ( ((((((*in).Slave3.m % (10 * 10)) / 10) == 3) && (((*in).Slave3.m / (10 * 10)) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User3.m) = (((*in).Slave3.m / (10 * 10)));
                (*out)._control.User3 = 1;
                (*out)._control.Slave3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
        }
        l67: if (  ( ((*in)._control.Slave4 == 2) ) )
        {
            l68: if (  ( (((*in).Slave4.m == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
        }
        l69: if (  ( ((*in)._control.Slave4 == 1) ) )
        {
            l70: if (  ( (((((*in).Slave4.m % (10 * 10)) / 10) != 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( ((((((*in).Slave4.m % (10 * 10)) / 10) == 4) && (((*in).Slave4.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User4 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave4.m) = (0);
                (*out)._control.Slave4 = 2;
                (*out)._control.User4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( ((((((*in).Slave4.m % (10 * 10)) / 10) == 4) && (((*in).Slave4.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User4 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave4.m) = ((5 + ((5 * 10) + (0 * (10 * 10)))));
                (*out)._control.Slave4 = 2;
                (*out)._control.User4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
        }
        l73: if (  ( ((*in)._control.Slave4 == 0) ) )
        {
            l74: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((4 != ((*in).Medium.m % 10)) && (4 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave4.m) = ((*in).Medium.m);
                (*out)._control.Slave4 = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
        }
        l75: if (  ( ((*in)._control.User4 == 1) ) )
        {
            l76: if (  ( ((4 == (*in).User4.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if (  ( ((4 != (*in).User4.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User4 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
        }
        l78: if (  ( ((*in)._control.User4 == 0) ) )
        {
            l79: if (  ( ((*in)._control.Slave4 == 1) )  &&  ( ((((((*in).Slave4.m % (10 * 10)) / 10) == 4) && (((*in).Slave4.m / (10 * 10)) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User4.m) = (((*in).Slave4.m / (10 * 10)));
                (*out)._control.User4 = 1;
                (*out)._control.Slave4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
        }
        l80: if (  ( ((*in)._control.Slave5 == 2) ) )
        {
            l81: if (  ( (((*in).Slave5.m == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
        }
        l82: if (  ( ((*in)._control.Slave5 == 1) ) )
        {
            l83: if (  ( (((((*in).Slave5.m % (10 * 10)) / 10) != 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if (  ( ((((((*in).Slave5.m % (10 * 10)) / 10) == 5) && (((*in).Slave5.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User5 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave5.m) = (0);
                (*out)._control.Slave5 = 2;
                (*out)._control.User5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((((((*in).Slave5.m % (10 * 10)) / 10) == 5) && (((*in).Slave5.m / (10 * 10)) == 0))) )  &&  ( ((*in)._control.User5 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave5.m) = ((1 + ((1 * 10) + (0 * (10 * 10)))));
                (*out)._control.Slave5 = 2;
                (*out)._control.User5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
        }
        l86: if (  ( ((*in)._control.Slave5 == 0) ) )
        {
            l87: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((5 != ((*in).Medium.m % 10)) && (5 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Slave5.m) = ((*in).Medium.m);
                (*out)._control.Slave5 = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
        }
        l88: if (  ( ((*in)._control.User5 == 1) ) )
        {
            l89: if (  ( ((5 == (*in).User5.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
            l90: if (  ( ((5 != (*in).User5.m)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User5 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
        }
        l91: if (  ( ((*in)._control.User5 == 0) ) )
        {
            l92: if (  ( ((*in)._control.Slave5 == 1) )  &&  ( ((((((*in).Slave5.m % (10 * 10)) / 10) == 5) && (((*in).Slave5.m / (10 * 10)) != 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User5.m) = (((*in).Slave5.m / (10 * 10)));
                (*out)._control.User5 = 1;
                (*out)._control.Slave5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
        }
        l93: if (  ( ((*in)._control.Master == 1) ) )
        {
            l94: if (  ( (((((*in)._control.Medium == 0)) && ((((*in)._control.Slave1 == 0)) && ((((*in)._control.Slave2 == 0)) && ((((*in)._control.Slave3 == 0)) && ((((*in)._control.Slave4 == 0)) && (((*in)._control.Slave5 == 0)))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Master = 0;
                ((*out).Master.next) = ((((*out).Master.next % 5) + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
            l95: if (  ( ((*in)._control.Medium == 2) )  &&  ( (((0 != ((*in).Medium.m % 10)) && (0 == (*in).Medium.i))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Master.m) = ((*in).Medium.m);
                (*out)._control.Master = 1;
                (*out)._control.Medium = 2;
                ((*out).Medium.i) = (((*out).Medium.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
        }
    }
    l96: if (  ( system_in_deadlock ) )
    {
    }
    l97: return 0;
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