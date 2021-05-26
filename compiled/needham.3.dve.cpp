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
        uint16_t initiator_0:3;
        uint16_t initiator_1:3;
        uint16_t initiator_2:3;
        uint16_t responder_0:3;
        uint16_t responder_1:3;
        uint16_t intruder:4;
    }
    __attribute__((__packed__)) _control;
    struct
    {
        int16_t m;
        int16_t party_nonce;
    }
    __attribute__((__packed__)) initiator_0;
    struct
    {
        int16_t m;
        int16_t party_nonce;
    }
    __attribute__((__packed__)) initiator_1;
    struct
    {
        int16_t m;
        int16_t party_nonce;
    }
    __attribute__((__packed__)) initiator_2;
    struct
    {
        int16_t m;
        int16_t party;
        int16_t party_nonce;
    }
    __attribute__((__packed__)) responder_0;
    struct
    {
        int16_t m;
        int16_t party;
        int16_t party_nonce;
    }
    __attribute__((__packed__)) responder_1;
    struct
    {
        uint8_t kNa;
        uint8_t kNb;
        uint8_t k_Na_Nb__A;
        uint8_t k_Na_A__B;
        uint8_t k_Nb__B;
        int16_t m;
    }
    __attribute__((__packed__)) intruder;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out._control.initiator_0 = 0;
    _out._control.initiator_1 = 0;
    _out._control.initiator_2 = 0;
    _out._control.responder_0 = 0;
    _out._control.responder_1 = 0;
    _out.intruder.kNa = 0;
    _out.intruder.kNb = 0;
    _out.intruder.k_Na_Nb__A = 0;
    _out.intruder.k_Na_A__B = 0;
    _out.intruder.k_Nb__B = 0;
    _out._control.intruder = 0;
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
        l3: if (  ( ((*in)._control.initiator_0 == 2) ) )
        {
            l4: if (  ( (((((*in).initiator_0.m % 15) == 1) && (((*in).initiator_0.m / (15 * 15)) == 7))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_0 = 3;
                ((*out).initiator_0.party_nonce) = ((((*out).initiator_0.m % (15 * 15)) / 15));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( (!(((((*in).initiator_0.m % 15) == 1) && (((*in).initiator_0.m / (15 * 15)) == 7)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_0 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
        }
        l6: if (  ( ((*in)._control.initiator_0 == 1) ) )
        {
            l7: if (  ( ((*in)._control.responder_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_0.m) = (((*in).responder_0.party_nonce + ((4 * 15) + ((*in).responder_0.party * (15 * 15)))));
                (*out)._control.initiator_0 = 2;
                (*out)._control.responder_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((*in)._control.responder_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_0.m) = (((*in).responder_1.party_nonce + ((5 * 15) + ((*in).responder_1.party * (15 * 15)))));
                (*out)._control.initiator_0 = 2;
                (*out)._control.responder_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_0.m) = ((1 + ((1 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_0 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNa == 1) && (((*in).intruder.kNb == 1) || ((*in).intruder.k_Na_Nb__A == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_0.m) = ((1 + ((4 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_0 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_0.m) = ((1 + ((13 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_0 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
        }
        l12: if (  ( ((*in)._control.initiator_1 == 2) ) )
        {
            l13: if (  ( (((((*in).initiator_1.m % 15) == 2) && (((*in).initiator_1.m / (15 * 15)) == 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_1 = 3;
                ((*out).initiator_1.party_nonce) = ((((*out).initiator_1.m % (15 * 15)) / 15));
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( (!(((((*in).initiator_1.m % 15) == 2) && (((*in).initiator_1.m / (15 * 15)) == 8)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_1 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
        l15: if (  ( ((*in)._control.initiator_1 == 1) ) )
        {
            l16: if (  ( ((*in)._control.responder_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_1.m) = (((*in).responder_0.party_nonce + ((4 * 15) + ((*in).responder_0.party * (15 * 15)))));
                (*out)._control.initiator_1 = 2;
                (*out)._control.responder_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.responder_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_1.m) = (((*in).responder_1.party_nonce + ((5 * 15) + ((*in).responder_1.party * (15 * 15)))));
                (*out)._control.initiator_1 = 2;
                (*out)._control.responder_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_1.m) = ((1 + ((1 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_1 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNa == 1) && (((*in).intruder.kNb == 1) || ((*in).intruder.k_Na_Nb__A == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_1.m) = ((1 + ((4 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_1 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_1.m) = ((1 + ((13 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_1 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
        }
        l21: if (  ( ((*in)._control.initiator_2 == 2) ) )
        {
            l22: if (  ( (((((*in).initiator_2.m % 15) == 3) && (((*in).initiator_2.m / (15 * 15)) == 9))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_2 = 3;
                ((*out).initiator_2.party_nonce) = ((((*out).initiator_2.m % (15 * 15)) / 15));
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( (!(((((*in).initiator_2.m % 15) == 3) && (((*in).initiator_2.m / (15 * 15)) == 9)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.initiator_2 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
        }
        l24: if (  ( ((*in)._control.initiator_2 == 1) ) )
        {
            l25: if (  ( ((*in)._control.responder_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_2.m) = (((*in).responder_0.party_nonce + ((4 * 15) + ((*in).responder_0.party * (15 * 15)))));
                (*out)._control.initiator_2 = 2;
                (*out)._control.responder_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((*in)._control.responder_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_2.m) = (((*in).responder_1.party_nonce + ((5 * 15) + ((*in).responder_1.party * (15 * 15)))));
                (*out)._control.initiator_2 = 2;
                (*out)._control.responder_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_2.m) = ((1 + ((1 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_2 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNa == 1) && (((*in).intruder.kNb == 1) || ((*in).intruder.k_Na_Nb__A == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_2.m) = ((1 + ((4 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_2 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).initiator_2.m) = ((1 + ((13 * 15) + (7 * (15 * 15)))));
                (*out)._control.initiator_2 = 2;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.responder_0 == 1) ) )
        {
            l31: if (  ( ((((*in).responder_0.m / (15 * 15)) == 10)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_0 = 2;
                ((*out).responder_0.party) = ((((*out).responder_0.m % (15 * 15)) / 15));
                ((*out).responder_0.party_nonce) = (((*out).responder_0.m % 15));
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( (!((((*in).responder_0.m / (15 * 15)) == 10) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
        }
        l33: if (  ( ((*in)._control.responder_0 == 4) ) )
        {
            l34: if (  ( (!(((((*in).responder_0.m % 15) == 4) && ((((*in).responder_0.m % (15 * 15)) / 15) == 10)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_0 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( (((((*in).responder_0.m % 15) == 4) && ((((*in).responder_0.m % (15 * 15)) / 15) == 10))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_0 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
        }
        l36: if (  ( ((*in)._control.responder_0 == 0) ) )
        {
            l37: if (  ( ((*in)._control.initiator_0 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.initiator_0 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( ((*in)._control.initiator_1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((2 + ((8 * 15) + (11 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.initiator_1 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( ((*in)._control.initiator_2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((3 + ((9 * 15) + (12 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.initiator_2 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((13 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((13 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((13 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((7 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((7 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((7 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((10 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((10 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((10 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
            l49: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((3 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((3 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((3 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((7 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((10 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((3 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNa == 1) || (*in).intruder.k_Na_A__B)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((1 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((4 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((4 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((4 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_0 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
        }
        l61: if (  ( ((*in)._control.responder_0 == 3) ) )
        {
            l62: if (  ( ((*in)._control.initiator_0 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = (((*in).initiator_0.party_nonce + ((10 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_0 = 4;
                (*out)._control.initiator_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( ((*in)._control.initiator_1 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = (((*in).initiator_1.party_nonce + ((11 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_0 = 4;
                (*out)._control.initiator_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( ((*in)._control.initiator_2 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = (((*in).initiator_2.party_nonce + ((12 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_0 = 4;
                (*out)._control.initiator_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNb == 1) || ((*in).intruder.k_Nb__B == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_0.m) = ((4 + ((10 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_0 = 4;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
        }
        l66: if (  ( ((*in)._control.responder_1 == 1) ) )
        {
            l67: if (  ( ((((*in).responder_1.m / (15 * 15)) == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_1 = 2;
                ((*out).responder_1.party) = ((((*out).responder_1.m % (15 * 15)) / 15));
                ((*out).responder_1.party_nonce) = (((*out).responder_1.m % 15));
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( (!((((*in).responder_1.m / (15 * 15)) == 11) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
        }
        l69: if (  ( ((*in)._control.responder_1 == 4) ) )
        {
            l70: if (  ( (!(((((*in).responder_1.m % 15) == 5) && ((((*in).responder_1.m % (15 * 15)) / 15) == 11)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_1 = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( (((((*in).responder_1.m % 15) == 5) && ((((*in).responder_1.m % (15 * 15)) / 15) == 11))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.responder_1 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
        }
        l72: if (  ( ((*in)._control.responder_1 == 0) ) )
        {
            l73: if (  ( ((*in)._control.initiator_0 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.initiator_0 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( ((*in)._control.initiator_1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((2 + ((8 * 15) + (11 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.initiator_1 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
            l75: if (  ( ((*in)._control.initiator_2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((3 + ((9 * 15) + (12 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.initiator_2 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((13 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((13 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((13 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((7 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((7 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
            l81: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((7 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((10 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((10 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((10 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((3 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((3 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
            l87: if (  ( ((*in)._control.intruder == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((3 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
            l88: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((7 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((10 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
            l90: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((3 * 15) + (7 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
            l91: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNa == 1) || (*in).intruder.k_Na_A__B)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNa == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((1 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
            l94: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((4 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
            l95: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((4 + ((10 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( ((*in)._control.intruder == 0) )  &&  ( (((*in).intruder.kNb == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((4 + ((3 * 15) + (10 * (15 * 15)))));
                (*out)._control.responder_1 = 1;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
        }
        l97: if (  ( ((*in)._control.responder_1 == 3) ) )
        {
            l98: if (  ( ((*in)._control.initiator_0 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = (((*in).initiator_0.party_nonce + ((10 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_1 = 4;
                (*out)._control.initiator_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
            l99: if (  ( ((*in)._control.initiator_1 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = (((*in).initiator_1.party_nonce + ((11 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_1 = 4;
                (*out)._control.initiator_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
            l100: if (  ( ((*in)._control.initiator_2 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = (((*in).initiator_2.party_nonce + ((12 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_1 = 4;
                (*out)._control.initiator_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
            l101: if (  ( ((*in)._control.intruder == 0) )  &&  ( ((((*in).intruder.kNb == 1) || ((*in).intruder.k_Nb__B == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).responder_1.m) = ((4 + ((10 * 15) + (0 * (15 * 15)))));
                (*out)._control.responder_1 = 4;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
        }
        l102: if (  ( ((*in)._control.intruder == 2) ) )
        {
            l103: if (  ( ((((*in).intruder.m % 15) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 3;
                ((*out).intruder.kNa) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( ((((*in).intruder.m % 15) == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 3;
                ((*out).intruder.kNb) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if (  ( (((((*in).intruder.m % 15) != 1) && (((*in).intruder.m % 15) != 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
        }
        l106: if (  ( ((*in)._control.intruder == 3) ) )
        {
            l107: if (  ( (((((*in).intruder.m % 15) == 4) && ((((*in).intruder.m % (15 * 15)) / 15) == 10))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.k_Nb__B) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 108;
            }
            l108: if (  ( (!(((((*in).intruder.m % 15) == 4) && ((((*in).intruder.m % (15 * 15)) / 15) == 10)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
        }
        l109: if (  ( ((*in)._control.intruder == 4) ) )
        {
            l110: if (  ( (((((*in).intruder.m % 15) == 1) && (((((*in).intruder.m % (15 * 15)) / 15) == 7) && (((*in).intruder.m / (15 * 15)) == 10)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.k_Na_A__B) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
            l111: if (  ( (((((*in).intruder.m % 15) == 1) && (((((*in).intruder.m % (15 * 15)) / 15) == 4) && (((*in).intruder.m / (15 * 15)) == 7)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.k_Na_Nb__A) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 112;
            }
            l112: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
        }
        l113: if (  ( ((*in)._control.intruder == 6) ) )
        {
            l114: if (  ( ((((*in).intruder.m % 15) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.kNa) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
            l115: if (  ( ((((*in).intruder.m % 15) == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.kNb) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
            l116: if (  ( (((((*in).intruder.m % 15) != 1) && (((*in).intruder.m % 15) != 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.intruder == 7) ) )
        {
            l118: if (  ( (((((*in).intruder.m % 15) == 4) && ((((*in).intruder.m % (15 * 15)) / 15) == 10))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                ((*out).intruder.k_Nb__B) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
            l119: if (  ( (!(((((*in).intruder.m % 15) == 4) && ((((*in).intruder.m % (15 * 15)) / 15) == 10)) )) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
        }
        l120: if (  ( ((*in)._control.intruder == 5) ) )
        {
            l121: if (  ( (((((*in).intruder.m % (15 * 15)) / 15) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
            l122: if (  ( (((((*in).intruder.m % (15 * 15)) / 15) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
        }
        l123: if (  ( ((*in)._control.intruder == 1) ) )
        {
            l124: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
            l125: if (  ( ((((*in).intruder.m / (15 * 15)) == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
            l126: if (  ( ((((*in).intruder.m / (15 * 15)) != 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.intruder = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
        }
        l127: if (  ( ((*in)._control.intruder == 0) ) )
        {
            l128: if (  ( ((*in)._control.responder_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = (((*in).responder_0.party_nonce + ((4 * 15) + ((*in).responder_0.party * (15 * 15)))));
                (*out)._control.intruder = 1;
                (*out)._control.responder_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
            l129: if (  ( ((*in)._control.responder_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = (((*in).responder_1.party_nonce + ((5 * 15) + ((*in).responder_1.party * (15 * 15)))));
                (*out)._control.intruder = 1;
                (*out)._control.responder_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
            l130: if (  ( ((*in)._control.initiator_0 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = ((1 + ((7 * 15) + (10 * (15 * 15)))));
                (*out)._control.intruder = 1;
                (*out)._control.initiator_0 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
            l131: if (  ( ((*in)._control.initiator_1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = ((2 + ((8 * 15) + (11 * (15 * 15)))));
                (*out)._control.intruder = 1;
                (*out)._control.initiator_1 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((*in)._control.initiator_2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = ((3 + ((9 * 15) + (12 * (15 * 15)))));
                (*out)._control.intruder = 1;
                (*out)._control.initiator_2 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((*in)._control.initiator_0 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = (((*in).initiator_0.party_nonce + ((10 * 15) + (0 * (15 * 15)))));
                (*out)._control.intruder = 5;
                (*out)._control.initiator_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
            l134: if (  ( ((*in)._control.initiator_1 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = (((*in).initiator_1.party_nonce + ((11 * 15) + (0 * (15 * 15)))));
                (*out)._control.intruder = 5;
                (*out)._control.initiator_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( ((*in)._control.initiator_2 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).intruder.m) = (((*in).initiator_2.party_nonce + ((12 * 15) + (0 * (15 * 15)))));
                (*out)._control.intruder = 5;
                (*out)._control.initiator_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
        }
    }
    l136: if (  ( system_in_deadlock ) )
    {
    }
    l137: return 0;
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
