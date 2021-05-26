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
        uint16_t Elevator:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t person[5];
    uint8_t conflictA[5];
    uint8_t conflictB[5];
    uint8_t not_alone[5];
    uint8_t at;
    uint8_t inA;
    uint8_t inB;
    uint8_t in;
    uint8_t alone;
    uint8_t i;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.person[0] = 0;
    _out.person[1] = 1;
    _out.person[2] = 2;
    _out.person[3] = 3;
    _out.person[4] = 4;
    _out.conflictA[0] = 1;
    _out.conflictA[1] = 0;
    _out.conflictA[2] = 0;
    _out.conflictA[3] = 1;
    _out.conflictA[4] = 1;
    _out.conflictB[0] = 0;
    _out.conflictB[1] = 1;
    _out.conflictB[2] = 1;
    _out.not_alone[0] = 1;
    _out.not_alone[1] = 1;
    _out.not_alone[2] = 0;
    _out.not_alone[3] = 0;
    _out.not_alone[4] = 0;
    _out.at = 0;
    _out.inA = 0;
    _out.inB = 0;
    _out.in = 0;
    _out.alone = 0;
    _out.i = 0;
    _out._control.Elevator = 0;
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
        l3: if (  ( ((*in)._control.Elevator == 0) ) )
        {
            l4: if (  ( ((((*in).person[ 0 ] == 0) && (((*in).person[ 1 ] == 0) && (((*in).person[ 2 ] == 0) && (((*in).person[ 3 ] == 0) && ((*in).person[ 4 ] == 0)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).person[ 0 ] == (*in).at) && (((*in).in < 3) && ((((*in).conflictA[ 0 ] == 0) || ((*in).inB == 0)) && ((((*in).conflictB[ 0 ] == 0) || ((*in).inA == 0)) && (((*in).not_alone[ 0 ] == 0) || ((*in).in > 0))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 0 ]) = (255);
                ((*out).in) = (((*out).in + 1));
                ((*out).inA) = (((*out).inA + (*out).conflictA[ 0 ]));
                ((*out).inB) = (((*out).inB + (*out).conflictB[ 0 ]));
                ((*out).alone) = (((*out).alone + (*out).not_alone[ 0 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((((*in).person[ 1 ] == (*in).at) && (((*in).in < 3) && ((((*in).conflictA[ 1 ] == 0) || ((*in).inB == 0)) && ((((*in).conflictB[ 1 ] == 0) || ((*in).inA == 0)) && (((*in).not_alone[ 1 ] == 0) || ((*in).in > 0))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 1 ]) = (255);
                ((*out).in) = (((*out).in + 1));
                ((*out).inA) = (((*out).inA + (*out).conflictA[ 1 ]));
                ((*out).inB) = (((*out).inB + (*out).conflictB[ 1 ]));
                ((*out).alone) = (((*out).alone + (*out).not_alone[ 1 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((((*in).person[ 2 ] == (*in).at) && (((*in).in < 3) && ((((*in).conflictA[ 2 ] == 0) || ((*in).inB == 0)) && ((((*in).conflictB[ 2 ] == 0) || ((*in).inA == 0)) && (((*in).not_alone[ 2 ] == 0) || ((*in).in > 0))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 2 ]) = (255);
                ((*out).in) = (((*out).in + 1));
                ((*out).inA) = (((*out).inA + (*out).conflictA[ 2 ]));
                ((*out).inB) = (((*out).inB + (*out).conflictB[ 2 ]));
                ((*out).alone) = (((*out).alone + (*out).not_alone[ 2 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((((*in).person[ 3 ] == (*in).at) && (((*in).in < 3) && ((((*in).conflictA[ 3 ] == 0) || ((*in).inB == 0)) && ((((*in).conflictB[ 3 ] == 0) || ((*in).inA == 0)) && (((*in).not_alone[ 3 ] == 0) || ((*in).in > 0))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 3 ]) = (255);
                ((*out).in) = (((*out).in + 1));
                ((*out).inA) = (((*out).inA + (*out).conflictA[ 3 ]));
                ((*out).inB) = (((*out).inB + (*out).conflictB[ 3 ]));
                ((*out).alone) = (((*out).alone + (*out).not_alone[ 3 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((((*in).person[ 4 ] == (*in).at) && (((*in).in < 3) && ((((*in).conflictA[ 4 ] == 0) || ((*in).inB == 0)) && ((((*in).conflictB[ 4 ] == 0) || ((*in).inA == 0)) && (((*in).not_alone[ 4 ] == 0) || ((*in).in > 0))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 4 ]) = (255);
                ((*out).in) = (((*out).in + 1));
                ((*out).inA) = (((*out).inA + (*out).conflictA[ 4 ]));
                ((*out).inB) = (((*out).inB + (*out).conflictB[ 4 ]));
                ((*out).alone) = (((*out).alone + (*out).not_alone[ 4 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((((*in).person[ 0 ] == 255) && (((*in).in > 2) || (((*in).alone - (*in).not_alone[ 0 ]) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 0 ]) = ((*out).at);
                ((*out).in) = (((*out).in - 1));
                ((*out).inA) = (((*out).inA - (*out).conflictA[ 0 ]));
                ((*out).inB) = (((*out).inB - (*out).conflictB[ 0 ]));
                ((*out).alone) = (((*out).alone - (*out).not_alone[ 0 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((((*in).person[ 1 ] == 255) && (((*in).in > 2) || (((*in).alone - (*in).not_alone[ 1 ]) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 1 ]) = ((*out).at);
                ((*out).in) = (((*out).in - 1));
                ((*out).inA) = (((*out).inA - (*out).conflictA[ 1 ]));
                ((*out).inB) = (((*out).inB - (*out).conflictB[ 1 ]));
                ((*out).alone) = (((*out).alone - (*out).not_alone[ 1 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((((*in).person[ 2 ] == 255) && (((*in).in > 2) || (((*in).alone - (*in).not_alone[ 2 ]) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 2 ]) = ((*out).at);
                ((*out).in) = (((*out).in - 1));
                ((*out).inA) = (((*out).inA - (*out).conflictA[ 2 ]));
                ((*out).inB) = (((*out).inB - (*out).conflictB[ 2 ]));
                ((*out).alone) = (((*out).alone - (*out).not_alone[ 2 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((((*in).person[ 3 ] == 255) && (((*in).in > 2) || (((*in).alone - (*in).not_alone[ 3 ]) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 3 ]) = ((*out).at);
                ((*out).in) = (((*out).in - 1));
                ((*out).inA) = (((*out).inA - (*out).conflictA[ 3 ]));
                ((*out).inB) = (((*out).inB - (*out).conflictB[ 3 ]));
                ((*out).alone) = (((*out).alone - (*out).not_alone[ 3 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((((*in).person[ 4 ] == 255) && (((*in).in > 2) || (((*in).alone - (*in).not_alone[ 4 ]) == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).person[ 4 ]) = ((*out).at);
                ((*out).in) = (((*out).in - 1));
                ((*out).inA) = (((*out).inA - (*out).conflictA[ 4 ]));
                ((*out).inB) = (((*out).inB - (*out).conflictB[ 4 ]));
                ((*out).alone) = (((*out).alone - (*out).not_alone[ 4 ]));
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).at) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).at) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).at) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).at) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Elevator = 0;
                ((*out).at) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
        }
    }
    l20: if (  ( system_in_deadlock ) )
    {
    }
    l21: return 0;
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
