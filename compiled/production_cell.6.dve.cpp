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
        uint16_t Plate_0:3;
        uint16_t Plate_1:3;
        uint16_t Plate_2:3;
        uint16_t Plate_3:3;
        uint16_t Plate_4:3;
        uint16_t Plate_5:3;
        uint16_t Plate_6:3;
        uint16_t Plate_7:3;
        uint16_t Plate_8:3;
        uint16_t Plate_9:3;
        uint16_t Belt:3;
        uint16_t Sensor:1;
        uint16_t Table:3;
        uint16_t Press:2;
        uint16_t Deposit:2;
        uint16_t Robot:3;
    }
    __attribute__((__packed__)) _control;
    uint8_t done;
    struct
    {
        uint8_t k;
    }
    __attribute__((__packed__)) Belt;
    struct
    {
        uint8_t count;
    }
    __attribute__((__packed__)) Sensor;
    struct
    {
        uint8_t k;
    }
    __attribute__((__packed__)) Table;
    struct
    {
        uint8_t k;
    }
    __attribute__((__packed__)) Press;
    struct
    {
        uint8_t k;
    }
    __attribute__((__packed__)) Deposit;
    struct
    {
        uint8_t at_press;
        uint8_t at_table;
        uint8_t A;
        uint8_t B;
    }
    __attribute__((__packed__)) Robot;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.done = 0;
    _out._control.Plate_0 = 0;
    _out._control.Plate_1 = 0;
    _out._control.Plate_2 = 0;
    _out._control.Plate_3 = 0;
    _out._control.Plate_4 = 0;
    _out._control.Plate_5 = 0;
    _out._control.Plate_6 = 0;
    _out._control.Plate_7 = 0;
    _out._control.Plate_8 = 0;
    _out._control.Plate_9 = 0;
    _out._control.Belt = 0;
    _out.Sensor.count = 0;
    _out._control.Sensor = 0;
    _out._control.Table = 0;
    _out._control.Press = 0;
    _out._control.Deposit = 0;
    _out.Robot.at_press = 0;
    _out.Robot.at_table = 0;
    _out.Robot.A = 255;
    _out.Robot.B = 255;
    _out._control.Robot = 2;
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
        l3: if (  ( ((*in)._control.Belt == 2) ) )
        {
            l4: if (  ( (((*in).Belt.k == 0)) )  &&  ( ((*in)._control.Plate_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( (((*in).Belt.k == 1)) )  &&  ( ((*in)._control.Plate_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( (((*in).Belt.k == 2)) )  &&  ( ((*in)._control.Plate_2 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_2 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( (((*in).Belt.k == 3)) )  &&  ( ((*in)._control.Plate_3 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_3 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
            l8: if (  ( (((*in).Belt.k == 4)) )  &&  ( ((*in)._control.Plate_4 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_4 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( (((*in).Belt.k == 5)) )  &&  ( ((*in)._control.Plate_5 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_5 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( (((*in).Belt.k == 6)) )  &&  ( ((*in)._control.Plate_6 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_6 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
            l11: if (  ( (((*in).Belt.k == 7)) )  &&  ( ((*in)._control.Plate_7 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_7 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( (((*in).Belt.k == 8)) )  &&  ( ((*in)._control.Plate_8 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_8 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
            l13: if (  ( (((*in).Belt.k == 9)) )  &&  ( ((*in)._control.Plate_9 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt = 3;
                (*out)._control.Plate_9 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
        }
        l14: if (  ( ((*in)._control.Belt == 0) ) )
        {
            l15: if (  ( ((*in)._control.Plate_0 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (0);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_0 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.Plate_1 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (1);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_1 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.Plate_2 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (2);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_2 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( ((*in)._control.Plate_3 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (3);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_3 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.Plate_4 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (4);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_4 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.Plate_5 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (5);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_5 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.Plate_6 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (6);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_6 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
            l22: if (  ( ((*in)._control.Plate_7 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (7);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_7 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.Plate_8 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (8);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_8 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((*in)._control.Plate_9 == 0) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Belt.k) = (9);
                (*out)._control.Belt = 1;
                (*out)._control.Plate_9 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
        }
        l25: if (  ( ((*in)._control.Sensor == 0) ) )
        {
            l26: if (  ( ((*in)._control.Belt == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Sensor = 0;
                ((*out).Sensor.count) = (((*out).Sensor.count + 1));
                (*out)._control.Belt = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.Table == 0) ) )
        {
            l28: if (  ( ((*in)._control.Belt == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Table.k) = ((*in).Belt.k);
                (*out)._control.Table = 1;
                (*out)._control.Belt = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
        }
        l29: if (  ( ((*in)._control.Table == 1) ) )
        {
            l30: if (  ( (((*in).Table.k == 0)) )  &&  ( ((*in)._control.Plate_0 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( (((*in).Table.k == 1)) )  &&  ( ((*in)._control.Plate_1 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( (((*in).Table.k == 2)) )  &&  ( ((*in)._control.Plate_2 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_2 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( (((*in).Table.k == 3)) )  &&  ( ((*in)._control.Plate_3 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_3 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
            l34: if (  ( (((*in).Table.k == 4)) )  &&  ( ((*in)._control.Plate_4 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_4 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( (((*in).Table.k == 5)) )  &&  ( ((*in)._control.Plate_5 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_5 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( (((*in).Table.k == 6)) )  &&  ( ((*in)._control.Plate_6 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_6 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( (((*in).Table.k == 7)) )  &&  ( ((*in)._control.Plate_7 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_7 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( (((*in).Table.k == 8)) )  &&  ( ((*in)._control.Plate_8 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_8 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( (((*in).Table.k == 9)) )  &&  ( ((*in)._control.Plate_9 == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 3;
                (*out)._control.Plate_9 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
        }
        l40: if (  ( ((*in)._control.Table == 2) ) )
        {
            l41: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Table = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
        }
        l42: if (  ( ((*in)._control.Press == 1) ) )
        {
            l43: if (  ( (((*in).Press.k == 0)) )  &&  ( ((*in)._control.Plate_0 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_0 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( (((*in).Press.k == 1)) )  &&  ( ((*in)._control.Plate_1 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_1 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( (((*in).Press.k == 2)) )  &&  ( ((*in)._control.Plate_2 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_2 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( (((*in).Press.k == 3)) )  &&  ( ((*in)._control.Plate_3 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_3 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( (((*in).Press.k == 4)) )  &&  ( ((*in)._control.Plate_4 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_4 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( (((*in).Press.k == 5)) )  &&  ( ((*in)._control.Plate_5 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_5 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
            l49: if (  ( (((*in).Press.k == 6)) )  &&  ( ((*in)._control.Plate_6 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_6 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( (((*in).Press.k == 7)) )  &&  ( ((*in)._control.Plate_7 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_7 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( (((*in).Press.k == 8)) )  &&  ( ((*in)._control.Plate_8 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_8 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( (((*in).Press.k == 9)) )  &&  ( ((*in)._control.Plate_9 == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Press = 2;
                (*out)._control.Plate_9 = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
        }
        l53: if (  ( ((*in)._control.Press == 0) ) )
        {
            l54: if (  ( ((*in)._control.Robot == 3) )  &&  ( ((((*in).Robot.A != 255) && ((*in).Robot.at_press == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Press.k) = ((*in).Robot.A);
                (*out)._control.Press = 1;
                (*out)._control.Robot = 3;
                ((*out).Robot.A) = (255);
                ((*out).Robot.at_press) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
        }
        l55: if (  ( ((*in)._control.Deposit == 1) ) )
        {
            l56: if (  ( (((*in).Deposit.k == 0)) )  &&  ( ((*in)._control.Plate_0 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( (((*in).Deposit.k == 1)) )  &&  ( ((*in)._control.Plate_1 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( (((*in).Deposit.k == 2)) )  &&  ( ((*in)._control.Plate_2 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_2 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( (((*in).Deposit.k == 3)) )  &&  ( ((*in)._control.Plate_3 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_3 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( (((*in).Deposit.k == 4)) )  &&  ( ((*in)._control.Plate_4 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_4 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( (((*in).Deposit.k == 5)) )  &&  ( ((*in)._control.Plate_5 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_5 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( (((*in).Deposit.k == 6)) )  &&  ( ((*in)._control.Plate_6 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_6 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( (((*in).Deposit.k == 7)) )  &&  ( ((*in)._control.Plate_7 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_7 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( (((*in).Deposit.k == 8)) )  &&  ( ((*in)._control.Plate_8 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_8 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( (((*in).Deposit.k == 9)) )  &&  ( ((*in)._control.Plate_9 == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Deposit = 0;
                (*out)._control.Plate_9 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
        }
        l66: if (  ( ((*in)._control.Deposit == 0) ) )
        {
            l67: if (  ( ((*in)._control.Robot == 4) )  &&  ( (((*in).Robot.B != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Deposit.k) = ((*in).Robot.B);
                (*out)._control.Deposit = 1;
                (*out)._control.Robot = 4;
                ((*out).Robot.B) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
        }
        l68: if (  ( ((*in)._control.Robot == 3) ) )
        {
            l69: if (  ( (((*in).Robot.B != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if (  ( (((((*in).Robot.A == 255) || ((*in).Robot.at_press == 1)) && ((*in).Robot.B == 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
        }
        l71: if (  ( ((*in)._control.Robot == 0) ) )
        {
            l72: if (  ( ((((*in).Robot.at_table == 1) && ((*in).Robot.A == 255))) )  &&  ( ((*in)._control.Table == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Robot.A) = ((*in).Table.k);
                (*out)._control.Robot = 0;
                ((*out).Robot.at_table) = (0);
                (*out)._control.Table = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( (((*in).Robot.A != 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
        }
        l74: if (  ( ((*in)._control.Robot == 4) ) )
        {
            l75: if (  ( (((*in).Robot.B == 255)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
        }
        l76: if (  ( ((*in)._control.Robot == 1) ) )
        {
            l77: if (  ( ((((*in).Robot.B == 255) && ((*in).Robot.at_press == 1))) )  &&  ( ((*in)._control.Press == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Robot.B) = ((*in).Press.k);
                (*out)._control.Robot = 1;
                ((*out).Robot.at_press) = (0);
                (*out)._control.Press = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( ((((*in).Robot.A == 255) && ((*in).Robot.at_table == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( (((((*in).Robot.A != 255) && ((*in).Robot.at_press == 0)) || (((*in).Robot.B != 255) && (((*in).Robot.A != 255) || ((*in).Robot.at_table == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
        }
        l80: if (  ( ((*in)._control.Robot == 2) ) )
        {
            l81: if (  ( (((((*in).Robot.B == 255) && ((*in).Robot.at_press == 1)) || (((*in).Robot.A == 255) && ((*in).Robot.at_table == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( (((*in).Robot.at_table == 0)) )  &&  ( ((*in)._control.Sensor == 0) )  &&  ( (((*in).Sensor.count > 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 2;
                ((*out).Robot.at_table) = (1);
                (*out)._control.Sensor = 0;
                ((*out).Sensor.count) = (((*out).Sensor.count - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( (((((*in).Robot.A != 255) && ((*in).Robot.at_press == 0)) || ((*in).Robot.B != 255))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Robot = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
        }
    }
    l84: if (  ( system_in_deadlock ) )
    {
    }
    l85: return 0;
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
