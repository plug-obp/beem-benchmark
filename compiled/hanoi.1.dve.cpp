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
        uint16_t AtoB:1;
        uint16_t AtoC:1;
        uint16_t BtoA:1;
        uint16_t BtoC:1;
        uint16_t CtoA:1;
        uint16_t CtoB:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t a[9];
    uint8_t a_act;
    uint8_t b[9];
    uint8_t b_act;
    uint8_t c[9];
    uint8_t c_act;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.a[0] = 100;
    _out.a[1] = 8;
    _out.a[2] = 7;
    _out.a[3] = 6;
    _out.a[4] = 5;
    _out.a[5] = 4;
    _out.a[6] = 3;
    _out.a[7] = 2;
    _out.a[8] = 1;
    _out.a_act = 9;
    _out.b[0] = 100;
    _out.b[1] = 0;
    _out.b[2] = 0;
    _out.b[3] = 0;
    _out.b[4] = 0;
    _out.b[5] = 0;
    _out.b[6] = 0;
    _out.b[7] = 0;
    _out.b[8] = 0;
    _out.b_act = 1;
    _out.c[0] = 100;
    _out.c[1] = 0;
    _out.c[2] = 0;
    _out.c[3] = 0;
    _out.c[4] = 0;
    _out.c[5] = 0;
    _out.c[6] = 0;
    _out.c[7] = 0;
    _out.c[8] = 0;
    _out.c_act = 1;
    _out._control.AtoB = 0;
    _out._control.AtoC = 0;
    _out._control.BtoA = 0;
    _out._control.BtoC = 0;
    _out._control.CtoA = 0;
    _out._control.CtoB = 0;
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
        l3: if (  ( ((*in)._control.AtoB == 0) ) )
        {
            l4: if (  ( (((*in).a[ ((*in).a_act - 1) ] < (*in).b[ ((*in).b_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.AtoB = 0;
                ((*out).b[ (*out).b_act ]) = ((*out).a[ ((*out).a_act - 1) ]);
                ((*out).b_act) = (((*out).b_act + 1));
                ((*out).a[ ((*out).a_act - 1) ]) = (0);
                ((*out).a_act) = (((*out).a_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
        }
        l5: if (  ( ((*in)._control.AtoC == 0) ) )
        {
            l6: if (  ( (((*in).a[ ((*in).a_act - 1) ] < (*in).c[ ((*in).c_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.AtoC = 0;
                ((*out).c[ (*out).c_act ]) = ((*out).a[ ((*out).a_act - 1) ]);
                ((*out).c_act) = (((*out).c_act + 1));
                ((*out).a[ ((*out).a_act - 1) ]) = (0);
                ((*out).a_act) = (((*out).a_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.BtoA == 0) ) )
        {
            l8: if (  ( (((*in).b[ ((*in).b_act - 1) ] < (*in).a[ ((*in).a_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.BtoA = 0;
                ((*out).a[ (*out).a_act ]) = ((*out).b[ ((*out).b_act - 1) ]);
                ((*out).a_act) = (((*out).a_act + 1));
                ((*out).b[ ((*out).b_act - 1) ]) = (0);
                ((*out).b_act) = (((*out).b_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
        }
        l9: if (  ( ((*in)._control.BtoC == 0) ) )
        {
            l10: if (  ( (((*in).b[ ((*in).b_act - 1) ] < (*in).c[ ((*in).c_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.BtoC = 0;
                ((*out).c[ (*out).c_act ]) = ((*out).b[ ((*out).b_act - 1) ]);
                ((*out).c_act) = (((*out).c_act + 1));
                ((*out).b[ ((*out).b_act - 1) ]) = (0);
                ((*out).b_act) = (((*out).b_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
        }
        l11: if (  ( ((*in)._control.CtoA == 0) ) )
        {
            l12: if (  ( (((*in).c[ ((*in).c_act - 1) ] < (*in).a[ ((*in).a_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CtoA = 0;
                ((*out).a[ (*out).a_act ]) = ((*out).c[ ((*out).c_act - 1) ]);
                ((*out).a_act) = (((*out).a_act + 1));
                ((*out).c[ ((*out).c_act - 1) ]) = (0);
                ((*out).c_act) = (((*out).c_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
        }
        l13: if (  ( ((*in)._control.CtoB == 0) ) )
        {
            l14: if (  ( (((*in).c[ ((*in).c_act - 1) ] < (*in).b[ ((*in).b_act - 1) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CtoB = 0;
                ((*out).b[ (*out).b_act ]) = ((*out).c[ ((*out).c_act - 1) ]);
                ((*out).b_act) = (((*out).b_act + 1));
                ((*out).c[ ((*out).c_act - 1) ]) = (0);
                ((*out).c_act) = (((*out).c_act - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
    }
    l15: if (  ( system_in_deadlock ) )
    {
    }
    l16: return 0;
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
