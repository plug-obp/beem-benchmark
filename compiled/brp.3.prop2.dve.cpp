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
        uint16_t LTL_property:2;
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
        }
        l16: if (  ( ((*in)._control.Producer == 2) ) )
        {
            l17: if (  ( ((*in)._control.Sender == 4) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (1);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i < (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (2);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (3);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
        }
        l20: if (  ( ((*in)._control.Consumer == 2) ) )
        {
            l21: if (  ( (((*in).Consumer.n == (*in).prod_n)) )  &&  ( ((*in)._control.Producer == 3) )  &&  ( (((*in).Producer.result == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.Producer = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( (((*in).Consumer.n != (*in).prod_n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
        }
        l23: if (  ( ((*in)._control.Consumer == 1) ) )
        {
            l24: if (  ( ((((*in).Consumer.m == 4) || ((*in).Consumer.m == 5))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( (((*in).Consumer.m == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                ((*out).Consumer.n) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( (((*in).Consumer.m == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.Consumer == 0) ) )
        {
            l28: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && (((*in).Receiver.value & 2) == 2))) ) )
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
                return 29;
            }
            l29: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 0)))) ) )
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
                return 30;
            }
            l30: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 4)))) ) )
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
                return 31;
            }
            l31: if (  ( ((*in)._control.Receiver == 0) ) )
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
                return 32;
            }
        }
        l32: if (  ( ((*in)._control.Sender == 0) ) )
        {
            l33: if (  ( ((*in)._control.Producer == 1) ) )
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
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.Sender == 1) ) )
        {
            l35: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
        }
        l36: if (  ( ((*in)._control.Sender == 4) ) )
        {
            l37: if (  ( (((*in).Sender.i < (*in).Sender.n)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (((*out).Sender.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.Sender == 2) ) )
        {
            l39: if (  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 4;
                ((*out).Sender.ab) = ((1 - (*out).Sender.ab));
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.L == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.L = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
        }
        l44: if (  ( ((*in)._control.Receiver == 4) ) )
        {
            l45: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 2;
                ((*out).Receiver.exp_ab) = (((*out).Receiver.value & 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
        }
        l46: if (  ( ((*in)._control.Receiver == 0) ) )
        {
            l47: if (  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 2;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((((*in).Receiver.value & 2) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.Receiver == 1) ) )
        {
            l50: if (  ( ((*in)._control.K == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 4;
                (*out)._control.K = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((*in)._control.Sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
        }
        l52: if (  ( ((*in)._control.Receiver == 5) ) )
        {
            l53: if (  ( ((*in)._control.Sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.K == 0) ) )
        {
            l55: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i == (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (2 + (*in).Sender.ab)));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i == (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((2 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i < (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i < (*in).Sender.n))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((*in).Sender.ab);
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
        }
        l59: if (  ( ((*in)._control.L == 0) ) )
        {
            l60: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((*in).Receiver.exp_ab != ((*in).Receiver.value & 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( ((*in)._control.Receiver == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                ((*out).Receiver.exp_ab) = ((1 - (*out).Receiver.exp_ab));
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
    }
    l62: if (  ( system_in_deadlock ) )
    {
    }
    l63: return 0;
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
        l3: if (  ( ((*in)._control.Producer == 3) ) )
        {
            l4: if (  ( ((((*in).Producer.result == 2) || ((*in).Producer.result == 3))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).Producer.result == 2) || ((*in).Producer.result == 3))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((((*in).Producer.result == 2) || ((*in).Producer.result == 3))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.Producer == 0) ) )
        {
            l8: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (1);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (1);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (2);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (2);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (2);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (3);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (3);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (3);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (4);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (4);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (4);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (5);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (5);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (5);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (6);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (6);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (6);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (7);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (7);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (7);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (8);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (8);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (8);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (9);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (9);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (9);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (10);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (10);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Producer = 1;
                ((*out).prod_n) = (10);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.Producer == 2) ) )
        {
            l39: if (  ( ((*in)._control.Sender == 4) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (1);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((*in)._control.Sender == 4) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (1);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( ((*in)._control.Sender == 4) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (1);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (2);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (2);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (2);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (3);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (3);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( ((*in)._control.Sender == 5) )  &&  ( (((*in).Sender.i == (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Producer.result) = (3);
                (*out)._control.Producer = 3;
                (*out)._control.Sender = 6;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
        }
        l48: if (  ( ((*in)._control.Consumer == 2) ) )
        {
            l49: if (  ( (((*in).Consumer.n == (*in).prod_n)) )  &&  ( ((*in)._control.Producer == 3) )  &&  ( (((*in).Producer.result == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.Producer = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( (((*in).Consumer.n == (*in).prod_n)) )  &&  ( ((*in)._control.Producer == 3) )  &&  ( (((*in).Producer.result == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.Producer = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( (((*in).Consumer.n == (*in).prod_n)) )  &&  ( ((*in)._control.Producer == 3) )  &&  ( (((*in).Producer.result == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.Producer = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( (((*in).Consumer.n != (*in).prod_n)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( (((*in).Consumer.n != (*in).prod_n)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( (((*in).Consumer.n != (*in).prod_n)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
        }
        l55: if (  ( ((*in)._control.Consumer == 1) ) )
        {
            l56: if (  ( ((((*in).Consumer.m == 4) || ((*in).Consumer.m == 5))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((((*in).Consumer.m == 4) || ((*in).Consumer.m == 5))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( ((((*in).Consumer.m == 4) || ((*in).Consumer.m == 5))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( (((*in).Consumer.m == 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                ((*out).Consumer.n) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( (((*in).Consumer.m == 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                ((*out).Consumer.n) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( (((*in).Consumer.m == 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 0;
                ((*out).Consumer.n) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( (((*in).Consumer.m == 1)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( (((*in).Consumer.m == 1)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( (((*in).Consumer.m == 1)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Consumer = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.Consumer == 0) ) )
        {
            l66: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && (((*in).Receiver.value & 2) == 2))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (1);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && (((*in).Receiver.value & 2) == 2))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (1);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && (((*in).Receiver.value & 2) == 2))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (1);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 0)))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (5);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 0)))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (5);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 0)))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (5);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 4)))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (4);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 4)))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (4);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((((*in).Receiver.value & 1) == (*in).Receiver.exp_ab) && ((((*in).Receiver.value & 2) == 0) && (((*in).Receiver.value & 4) == 4)))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (4);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 3;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
            l75: if (  ( ((*in)._control.Receiver == 0) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (2);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( ((*in)._control.Receiver == 0) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (2);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if (  ( ((*in)._control.Receiver == 0) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Consumer.m) = (2);
                (*out)._control.Consumer = 1;
                ((*out).Consumer.n) = (((*out).Consumer.n + 1));
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
        }
        l78: if (  ( ((*in)._control.Sender == 0) ) )
        {
            l79: if (  ( ((*in)._control.Producer == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Sender.n) = ((*in).prod_n);
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (1);
                (*out)._control.Producer = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( ((*in)._control.Producer == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Sender.n) = ((*in).prod_n);
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (1);
                (*out)._control.Producer = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
            l81: if (  ( ((*in)._control.Producer == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Sender.n) = ((*in).prod_n);
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (1);
                (*out)._control.Producer = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
        }
        l82: if (  ( ((*in)._control.Sender == 1) ) )
        {
            l83: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (0);
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (0);
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
        }
        l86: if (  ( ((*in)._control.Sender == 4) ) )
        {
            l87: if (  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (((*out).Sender.i + 1));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
            l88: if (  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (((*out).Sender.i + 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( (((*in).Sender.i < (*in).Sender.n)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 1;
                ((*out).Sender.i) = (((*out).Sender.i + 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
        }
        l90: if (  ( ((*in)._control.Sender == 2) ) )
        {
            l91: if (  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 4;
                ((*out).Sender.ab) = ((1 - (*out).Sender.ab));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 4;
                ((*out).Sender.ab) = ((1 - (*out).Sender.ab));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if (  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 4;
                ((*out).Sender.ab) = ((1 - (*out).Sender.ab));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
            l94: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
            l95: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
            l97: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 98;
            }
            l98: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
            l99: if (  ( (((*in).Sender.counter == 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 5;
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
            l100: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
            l101: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
            l102: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
            l103: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if (  ( (((*in).Sender.counter < 10)) )  &&  ( ((*in)._control.L == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sender = 3;
                ((*out).Sender.counter) = (((*out).Sender.counter + 1));
                (*out)._control.L = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
        }
        l106: if (  ( ((*in)._control.Receiver == 4) ) )
        {
            l107: if (  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 2;
                ((*out).Receiver.exp_ab) = (((*out).Receiver.value & 1));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
            l108: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 2;
                ((*out).Receiver.exp_ab) = (((*out).Receiver.value & 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
            l109: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 2;
                ((*out).Receiver.exp_ab) = (((*out).Receiver.value & 1));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 110;
            }
        }
        l110: if (  ( ((*in)._control.Receiver == 0) ) )
        {
            l111: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 2;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
            l112: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 2;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
            l113: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 2;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 114;
            }
            l114: if (  ( ((((*in).Receiver.value & 2) == 2)) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
            l115: if (  ( ((((*in).Receiver.value & 2) == 2)) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
            l116: if (  ( ((((*in).Receiver.value & 2) == 2)) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 5;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.Receiver == 1) ) )
        {
            l118: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 4;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
            l119: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 4;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
            l120: if (  ( ((*in)._control.K == 1) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Receiver.value) = ((*in).K.value);
                (*out)._control.Receiver = 4;
                (*out)._control.K = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
            l121: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
            l122: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
            l123: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
        }
        l124: if (  ( ((*in)._control.Receiver == 5) ) )
        {
            l125: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
            l126: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
            l127: if (  ( ((*in)._control.Sender == 6) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Receiver = 1;
                (*out)._control.Sender = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
        }
        l128: if (  ( ((*in)._control.K == 0) ) )
        {
            l129: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (2 + (*in).Sender.ab)));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
            l130: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (2 + (*in).Sender.ab)));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
            l131: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (2 + (*in).Sender.ab)));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((2 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((2 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
            l134: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i == (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((2 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
            l136: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 137;
            }
            l137: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i == 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((4 + (*in).Sender.ab));
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
            l138: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((*in).Sender.ab);
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
            l139: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((*in).Sender.ab);
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 140;
            }
            l140: if (  ( ((*in)._control.Sender == 3) )  &&  ( ((((*in).Sender.i > 1) && ((*in).Sender.i < (*in).Sender.n))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).K.value) = ((*in).Sender.ab);
                (*out)._control.K = 1;
                (*out)._control.Sender = 2;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
        }
        l141: if (  ( ((*in)._control.L == 0) ) )
        {
            l142: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((*in).Receiver.exp_ab != ((*in).Receiver.value & 1))) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
            l143: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((*in).Receiver.exp_ab != ((*in).Receiver.value & 1))) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( ((*in)._control.Receiver == 2) )  &&  ( (((*in).Receiver.exp_ab != ((*in).Receiver.value & 1))) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
            l145: if (  ( ((*in)._control.Receiver == 3) )  &&  ( ((*in)._control.LTL_property == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                ((*out).Receiver.exp_ab) = ((1 - (*out).Receiver.exp_ab));
                (*out)._control.LTL_property = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
            l146: if (  ( ((*in)._control.Receiver == 3) )  &&  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                ((*out).Receiver.exp_ab) = ((1 - (*out).Receiver.exp_ab));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
            l147: if (  ( ((*in)._control.Receiver == 3) )  &&  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.L = 1;
                (*out)._control.Receiver = 0;
                ((*out).Receiver.exp_ab) = ((1 - (*out).Receiver.exp_ab));
                (*out)._control.LTL_property = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
        }
    }
    l148: if (  ( system_in_deadlock ) )
    {
        l149: if (  ( ((*in)._control.LTL_property == 0) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 0;
            *to = blob_out;
            return 150;
        }
        l150: if (  ( ((*in)._control.LTL_property == 0) )  &&  ( (((((*in)._control.Producer == 2)) && !((((*in)._control.Producer == 3)) ))) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 1;
            *to = blob_out;
            return 151;
        }
        l151: if (  ( ((*in)._control.LTL_property == 1) )  &&  ( (!((((*in)._control.Producer == 3)) )) ) )
        {
            cesmi_node blob_out = setup->make_node( setup, state_size );
            state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
            *out = *in;
            (*out)._control.LTL_property = 1;
            *to = blob_out;
            return 152;
        }
    }
    l152: return 0;
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
