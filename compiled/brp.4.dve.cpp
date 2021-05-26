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
        uint16_t Producer:3;
        uint16_t Consumer:3;
        uint16_t Sender:3;
        uint16_t Receiver:3;
        uint16_t K:2;
        uint16_t L:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t prod_n;
    struct
    {
        uint8_t result;
        uint8_t n;
    }
    __attribute__((__packed__)) Producer;
    struct
    {
        uint8_t m;
        uint8_t n;
    }
    __attribute__((__packed__)) Consumer;
    struct
    {
        uint8_t ab;
        uint8_t n;
        uint8_t i;
        uint8_t counter;
    }
    __attribute__((__packed__)) Sender;
    struct
    {
        uint8_t value;
        uint8_t exp_ab;
    }
    __attribute__((__packed__)) Receiver;
    struct
    {
        uint8_t value;
    }
    __attribute__((__packed__)) K;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out._control.Producer = 0;
    _out.Consumer.n = 0;
    _out._control.Consumer = 0;
    _out.Sender.ab = 0;
    _out._control.Sender = 0;
    _out.Receiver.exp_ab = 0;
    _out._control.Receiver = 1;
    _out._control.K = 0;
    _out._control.L = 0;
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
        l3: if (  ( ((*in)._control.Producer == 3) ) )
        {
            l4: if (  ( ((((*in).Producer.result == 2) || ((*in).Producer.result == 3))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
        }
        l5: if (  ( ((*in)._control.Producer == 0) ) )
        {
            l6: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (8);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (9);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (10);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (11);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (12);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (13);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (14);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (15);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (16);
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (17);
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (18);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (19);
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (20);
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
        }
        l26: if (  ( ((*in)._control.Producer == 2) ) )
        {
            l27: if (  ( ((*in)._control.Sender == 4) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (1);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i < (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (2);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (3);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.Consumer == 2) ) )
        {
            l31: if (  ( (((*in).Consumer.n == (*in).prod_n)) )  &&  ( ((*in)._control.Producer == 3) )  &&  ( (((*in).Producer.result == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.Producer = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( (((*in).Consumer.n != (*in).prod_n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
        }
        l33: if (  ( ((*in)._control.Consumer == 1) ) )
        {
            l34: if (  ( ((((*in).Consumer.m == 4) || ((*in).Consumer.m == 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( (((*in).Consumer.m == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                ((*out).Consumer.n) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( (((*in).Consumer.m == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
        }
        l37: if (  ( ((*in)._control.Consumer == 0) ) )
        {
            l38: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && (((*in).Receiver.value & 2) == 2))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (1);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (5);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 4)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (4);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( ((*in)._control.Receiver == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (2);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
        }
        l42: if (  ( ((*in)._control.Sender == 0) ) )
        {
            l43: if (  ( ((*in)._control.Producer == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Sender.n) = ((*in).prod_n);
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (1);
                (*out)._control.Producer = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
        }
        l44: if (  ( ((*in)._control.Sender == 1) ) )
        {
            l45: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
        }
        l46: if (  ( ((*in)._control.Sender == 4) ) )
        {
            l47: if (  ( (((*in).Sender.i < (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (((*out).Sender.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
        }
        l48: if (  ( ((*in)._control.Sender == 2) ) )
        {
            l49: if (  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 4;
                ((*out).Sender.ab) = ((1 - (*out).Sender.ab));
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( (((*in).Sender.counter == 20)) )  &&  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( (((*in).Sender.counter == 20)) )  &&  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( (((*in).Sender.counter < 20)) )  &&  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( (((*in).Sender.counter < 20)) )  &&  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.Receiver == 4) ) )
        {
            l55: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 2;
                ((*out).Receiver.exp_ab) = (((*out).Receiver.value & 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
        }
        l56: if (  ( ((*in)._control.Receiver == 0) ) )
        {
            l57: if (  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 2;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( ((((*in).Receiver.value & 2) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
        }
        l59: if (  ( ((*in)._control.Receiver == 1) ) )
        {
            l60: if (  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 4;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( ((*in)._control.Sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
        l62: if (  ( ((*in)._control.Receiver == 5) ) )
        {
            l63: if (  ( ((*in)._control.Sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
        }
        l64: if (  ( ((*in)._control.K == 0) ) )
        {
            l65: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i == (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (2 + (*in).Sender.ab)));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
            l66: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i == (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((2 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i < (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i < (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((*in).Sender.ab);
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
        }
        l69: if (  ( ((*in)._control.L == 0) ) )
        {
            l70: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((*in).Receiver.exp_ab != ((*in).Receiver.value & 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( ((*in)._control.Receiver == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                ((*out).Receiver.exp_ab) = ((1 - (*out).Receiver.exp_ab));
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
        }
    }
    l72: if (  ( system_in_deadlock ) )
    {
    }
    l73: return 0;
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
