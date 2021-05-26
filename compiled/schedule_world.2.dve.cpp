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
        uint16_t P:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t temperature[3];
    uint8_t surface[3];
    uint8_t shape[3];
    uint8_t painted[3];
    uint8_t hashole[3];
    uint8_t busy[8];
    uint8_t scheduled[3];
    uint8_t objscheduled;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.temperature[0] = 0;
    _out.temperature[1] = 0;
    _out.temperature[2] = 0;
    _out.surface[0] = 0;
    _out.surface[1] = 1;
    _out.surface[2] = 2;
    _out.shape[0] = 0;
    _out.shape[1] = 1;
    _out.shape[2] = 1;
    _out.painted[0] = 0;
    _out.painted[1] = 1;
    _out.painted[2] = 1;
    _out.hashole[0] = 1;
    _out.hashole[1] = 1;
    _out.hashole[2] = 0;
    _out.busy[0] = 0;
    _out.busy[1] = 0;
    _out.busy[2] = 0;
    _out.busy[3] = 0;
    _out.busy[4] = 0;
    _out.busy[5] = 0;
    _out.busy[6] = 0;
    _out.busy[7] = 0;
    _out.scheduled[0] = 0;
    _out.scheduled[1] = 0;
    _out.scheduled[2] = 0;
    _out.objscheduled = 0;
    _out._control.P = 0;
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
        l3: if (  ( ((*in)._control.P == 0) ) )
        {
            l4: if (  ( ((((*in).shape[ 1 ] == 1) && (((*in).surface[ 0 ] == 0) && (((*in).surface[ 1 ] == 0) && (((*in).hashole[ 1 ] == 1) && ((*in).shape[ 0 ] == 0)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).busy[ 0 ] == 0) && (((*in).scheduled[ 0 ] == 0) && ((*in).temperature[ 0 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 0 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).surface[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((((*in).busy[ 0 ] == 0) && (((*in).scheduled[ 1 ] == 0) && ((*in).temperature[ 1 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 0 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).surface[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((((*in).busy[ 0 ] == 0) && (((*in).scheduled[ 2 ] == 0) && ((*in).temperature[ 2 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 0 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).surface[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( ((((*in).busy[ 1 ] == 0) && ((*in).scheduled[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 1 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).shape[ 0 ]) = (0);
                ((*out).temperature[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (255);
                ((*out).hashole[ 0 ]) = (255);
                ((*out).surface[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((((*in).busy[ 1 ] == 0) && ((*in).scheduled[ 1 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 1 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).shape[ 1 ]) = (0);
                ((*out).temperature[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (255);
                ((*out).hashole[ 1 ]) = (255);
                ((*out).surface[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((((*in).busy[ 1 ] == 0) && ((*in).scheduled[ 2 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 1 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).shape[ 2 ]) = (0);
                ((*out).temperature[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (255);
                ((*out).hashole[ 2 ]) = (255);
                ((*out).surface[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( ((((*in).busy[ 2 ] == 0) && ((*in).scheduled[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 2 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).surface[ 0 ]) = (2);
                ((*out).shape[ 0 ]) = (0);
                ((*out).painted[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( ((((*in).busy[ 2 ] == 0) && ((*in).scheduled[ 1 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 2 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).surface[ 1 ]) = (2);
                ((*out).shape[ 1 ]) = (0);
                ((*out).painted[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( ((((*in).busy[ 2 ] == 0) && ((*in).scheduled[ 2 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 2 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).surface[ 2 ]) = (2);
                ((*out).shape[ 2 ]) = (0);
                ((*out).painted[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((((*in).busy[ 3 ] == 0) && ((*in).scheduled[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 3 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).surface[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((((*in).busy[ 3 ] == 0) && ((*in).scheduled[ 1 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 3 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).surface[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((((*in).busy[ 3 ] == 0) && ((*in).scheduled[ 2 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 3 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).surface[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 0 ] == 0) && (((*in).temperature[ 0 ] == 0) && ((*in).hashole[ 0 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).surface[ 0 ]) = (2);
                ((*out).hashole[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 1 ] == 0) && (((*in).temperature[ 1 ] == 0) && ((*in).hashole[ 1 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).surface[ 1 ]) = (2);
                ((*out).hashole[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 2 ] == 0) && (((*in).temperature[ 2 ] == 0) && ((*in).hashole[ 2 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).surface[ 2 ]) = (2);
                ((*out).hashole[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 0 ] == 0) && (((*in).temperature[ 0 ] == 0) && ((*in).hashole[ 0 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).surface[ 0 ]) = (2);
                ((*out).hashole[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 1 ] == 0) && (((*in).temperature[ 1 ] == 0) && ((*in).hashole[ 1 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).surface[ 1 ]) = (2);
                ((*out).hashole[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((((*in).busy[ 4 ] == 0) && (((*in).scheduled[ 2 ] == 0) && (((*in).temperature[ 2 ] == 0) && ((*in).hashole[ 2 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 4 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).surface[ 2 ]) = (2);
                ((*out).hashole[ 2 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 0 ] == 0) && (((*in).temperature[ 0 ] == 0) && ((*in).hashole[ 0 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).hashole[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 1 ] == 0) && (((*in).temperature[ 1 ] == 0) && ((*in).hashole[ 1 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).hashole[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
            l25: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 2 ] == 0) && (((*in).temperature[ 2 ] == 0) && ((*in).hashole[ 2 ] != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).hashole[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 0 ] == 0) && (((*in).temperature[ 0 ] == 0) && ((*in).hashole[ 0 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).hashole[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 1 ] == 0) && (((*in).temperature[ 1 ] == 0) && ((*in).hashole[ 1 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).hashole[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( ((((*in).busy[ 5 ] == 0) && (((*in).scheduled[ 2 ] == 0) && (((*in).temperature[ 2 ] == 0) && ((*in).hashole[ 2 ] != 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 5 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).hashole[ 2 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 0 ] == 0) && ((*in).temperature[ 0 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 1 ] == 0) && ((*in).temperature[ 1 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 2 ] == 0) && ((*in).temperature[ 2 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 0 ] == 0) && ((*in).temperature[ 0 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 1 ] == 0) && ((*in).temperature[ 1 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( ((((*in).busy[ 6 ] == 0) && (((*in).scheduled[ 2 ] == 0) && ((*in).temperature[ 2 ] == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 6 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 1 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 2 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 0 ]) = (1);
                ((*out).painted[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 1 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 1 ]) = (1);
                ((*out).painted[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((((*in).busy[ 7 ] == 0) && ((*in).scheduled[ 2 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).objscheduled) = (1);
                ((*out).busy[ 7 ]) = (1);
                ((*out).scheduled[ 2 ]) = (1);
                ((*out).painted[ 2 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
            l41: if (  ( (((*in).objscheduled == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.P = 0;
                ((*out).scheduled[ 0 ]) = (0);
                ((*out).scheduled[ 1 ]) = (0);
                ((*out).scheduled[ 2 ]) = (0);
                ((*out).busy[ 0 ]) = (0);
                ((*out).busy[ 1 ]) = (0);
                ((*out).busy[ 2 ]) = (0);
                ((*out).busy[ 3 ]) = (0);
                ((*out).busy[ 4 ]) = (0);
                ((*out).busy[ 5 ]) = (0);
                ((*out).busy[ 6 ]) = (0);
                ((*out).busy[ 7 ]) = (0);
                ((*out).objscheduled) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
        }
    }
    l42: if (  ( system_in_deadlock ) )
    {
    }
    l43: return 0;
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
