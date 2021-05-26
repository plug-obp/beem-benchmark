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
        uint16_t Red_car:2;
        uint16_t Car_hor_1:1;
        uint16_t Car_hor_2:1;
        uint16_t Car_hor_3:1;
        uint16_t Car_hor_4:1;
        uint16_t Car_ver_1:1;
        uint16_t Car_ver_2:1;
        uint16_t Car_ver_3:1;
        uint16_t Car_ver_4:1;
        uint16_t Car_ver_5:1;
        uint16_t Car_ver_6:1;
        uint16_t Car_ver_7:1;
        uint16_t Car_ver_8:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t A[49];
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Red_car;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_hor_1;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_hor_2;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_hor_3;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_hor_4;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_1;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_2;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_3;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_4;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_5;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_6;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_7;
    struct
    {
        uint8_t x;
        uint8_t y;
        uint8_t length;
    }
    __attribute__((__packed__)) Car_ver_8;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.A[0] = 0;
    _out.A[1] = 0;
    _out.A[2] = 1;
    _out.A[3] = 0;
    _out.A[4] = 1;
    _out.A[5] = 1;
    _out.A[6] = 0;
    _out.A[7] = 1;
    _out.A[8] = 0;
    _out.A[9] = 1;
    _out.A[10] = 1;
    _out.A[11] = 1;
    _out.A[12] = 1;
    _out.A[13] = 1;
    _out.A[14] = 1;
    _out.A[15] = 1;
    _out.A[16] = 1;
    _out.A[17] = 1;
    _out.A[18] = 1;
    _out.A[19] = 1;
    _out.A[20] = 1;
    _out.A[21] = 0;
    _out.A[22] = 0;
    _out.A[23] = 0;
    _out.A[24] = 1;
    _out.A[25] = 0;
    _out.A[26] = 1;
    _out.A[27] = 0;
    _out.A[28] = 1;
    _out.A[29] = 1;
    _out.A[30] = 1;
    _out.A[31] = 0;
    _out.A[32] = 1;
    _out.A[33] = 1;
    _out.A[34] = 0;
    _out.A[35] = 1;
    _out.A[36] = 1;
    _out.A[37] = 1;
    _out.A[38] = 1;
    _out.A[39] = 1;
    _out.A[40] = 0;
    _out.A[41] = 1;
    _out.A[42] = 0;
    _out.A[43] = 0;
    _out.A[44] = 0;
    _out.A[45] = 0;
    _out.A[46] = 0;
    _out.A[47] = 0;
    _out.A[48] = 1;
    _out.Red_car.x = 1;
    _out.Red_car.y = 2;
    _out.Red_car.length = 2;
    _out._control.Red_car = 0;
    _out.Car_hor_1.x = 4;
    _out.Car_hor_1.y = 0;
    _out.Car_hor_1.length = 2;
    _out._control.Car_hor_1 = 0;
    _out.Car_hor_2.x = 1;
    _out.Car_hor_2.y = 4;
    _out.Car_hor_2.length = 2;
    _out._control.Car_hor_2 = 0;
    _out.Car_hor_3.x = 4;
    _out.Car_hor_3.y = 4;
    _out.Car_hor_3.length = 2;
    _out._control.Car_hor_3 = 0;
    _out.Car_hor_4.x = 1;
    _out.Car_hor_4.y = 5;
    _out.Car_hor_4.length = 4;
    _out._control.Car_hor_4 = 0;
    _out.Car_ver_1.x = 0;
    _out.Car_ver_1.y = 1;
    _out.Car_ver_1.length = 2;
    _out._control.Car_ver_1 = 0;
    _out.Car_ver_2.x = 0;
    _out.Car_ver_2.y = 4;
    _out.Car_ver_2.length = 2;
    _out._control.Car_ver_2 = 0;
    _out.Car_ver_3.x = 2;
    _out.Car_ver_3.y = 0;
    _out.Car_ver_3.length = 2;
    _out._control.Car_ver_3 = 0;
    _out.Car_ver_4.x = 3;
    _out.Car_ver_4.y = 1;
    _out.Car_ver_4.length = 3;
    _out._control.Car_ver_4 = 0;
    _out.Car_ver_5.x = 4;
    _out.Car_ver_5.y = 1;
    _out.Car_ver_5.length = 2;
    _out._control.Car_ver_5 = 0;
    _out.Car_ver_6.x = 5;
    _out.Car_ver_6.y = 1;
    _out.Car_ver_6.length = 3;
    _out._control.Car_ver_6 = 0;
    _out.Car_ver_7.x = 6;
    _out.Car_ver_7.y = 1;
    _out.Car_ver_7.length = 2;
    _out._control.Car_ver_7 = 0;
    _out.Car_ver_8.x = 6;
    _out.Car_ver_8.y = 5;
    _out.Car_ver_8.length = 2;
    _out._control.Car_ver_8 = 0;
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
        l3: if (  ( ((*in)._control.Red_car == 0) ) )
        {
            l4: if (  ( ((((*in).Red_car.x > 0) && ((*in).A[ (((*in).Red_car.y * 7) + ((*in).Red_car.x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Red_car = 0;
                ((*out).A[ (((*out).Red_car.y * 7) + ((*out).Red_car.x + ((*out).Red_car.length - 1))) ]) = (0);
                ((*out).A[ (((*out).Red_car.y * 7) + ((*out).Red_car.x - 1)) ]) = (1);
                ((*out).Red_car.x) = (((*out).Red_car.x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( (((((*in).Red_car.x + (*in).Red_car.length) < 7) && ((*in).A[ (((*in).Red_car.y * 7) + ((*in).Red_car.x + (*in).Red_car.length)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Red_car = 0;
                ((*out).A[ (((*out).Red_car.y * 7) + (*out).Red_car.x) ]) = (0);
                ((*out).A[ (((*out).Red_car.y * 7) + ((*out).Red_car.x + (*out).Red_car.length)) ]) = (1);
                ((*out).Red_car.x) = (((*out).Red_car.x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( (((*in).Red_car.x == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Red_car = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.Car_hor_1 == 0) ) )
        {
            l8: if (  ( ((((*in).Car_hor_1.x > 0) && ((*in).A[ (((*in).Car_hor_1.y * 7) + ((*in).Car_hor_1.x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_1 = 0;
                ((*out).A[ (((*out).Car_hor_1.y * 7) + ((*out).Car_hor_1.x + ((*out).Car_hor_1.length - 1))) ]) = (0);
                ((*out).A[ (((*out).Car_hor_1.y * 7) + ((*out).Car_hor_1.x - 1)) ]) = (1);
                ((*out).Car_hor_1.x) = (((*out).Car_hor_1.x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( (((((*in).Car_hor_1.x + (*in).Car_hor_1.length) < 7) && ((*in).A[ (((*in).Car_hor_1.y * 7) + ((*in).Car_hor_1.x + (*in).Car_hor_1.length)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_1 = 0;
                ((*out).A[ (((*out).Car_hor_1.y * 7) + (*out).Car_hor_1.x) ]) = (0);
                ((*out).A[ (((*out).Car_hor_1.y * 7) + ((*out).Car_hor_1.x + (*out).Car_hor_1.length)) ]) = (1);
                ((*out).Car_hor_1.x) = (((*out).Car_hor_1.x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
        }
        l10: if (  ( ((*in)._control.Car_hor_2 == 0) ) )
        {
            l11: if (  ( ((((*in).Car_hor_2.x > 0) && ((*in).A[ (((*in).Car_hor_2.y * 7) + ((*in).Car_hor_2.x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_2 = 0;
                ((*out).A[ (((*out).Car_hor_2.y * 7) + ((*out).Car_hor_2.x + ((*out).Car_hor_2.length - 1))) ]) = (0);
                ((*out).A[ (((*out).Car_hor_2.y * 7) + ((*out).Car_hor_2.x - 1)) ]) = (1);
                ((*out).Car_hor_2.x) = (((*out).Car_hor_2.x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
            l12: if (  ( (((((*in).Car_hor_2.x + (*in).Car_hor_2.length) < 7) && ((*in).A[ (((*in).Car_hor_2.y * 7) + ((*in).Car_hor_2.x + (*in).Car_hor_2.length)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_2 = 0;
                ((*out).A[ (((*out).Car_hor_2.y * 7) + (*out).Car_hor_2.x) ]) = (0);
                ((*out).A[ (((*out).Car_hor_2.y * 7) + ((*out).Car_hor_2.x + (*out).Car_hor_2.length)) ]) = (1);
                ((*out).Car_hor_2.x) = (((*out).Car_hor_2.x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
        }
        l13: if (  ( ((*in)._control.Car_hor_3 == 0) ) )
        {
            l14: if (  ( ((((*in).Car_hor_3.x > 0) && ((*in).A[ (((*in).Car_hor_3.y * 7) + ((*in).Car_hor_3.x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_3 = 0;
                ((*out).A[ (((*out).Car_hor_3.y * 7) + ((*out).Car_hor_3.x + ((*out).Car_hor_3.length - 1))) ]) = (0);
                ((*out).A[ (((*out).Car_hor_3.y * 7) + ((*out).Car_hor_3.x - 1)) ]) = (1);
                ((*out).Car_hor_3.x) = (((*out).Car_hor_3.x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( (((((*in).Car_hor_3.x + (*in).Car_hor_3.length) < 7) && ((*in).A[ (((*in).Car_hor_3.y * 7) + ((*in).Car_hor_3.x + (*in).Car_hor_3.length)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_3 = 0;
                ((*out).A[ (((*out).Car_hor_3.y * 7) + (*out).Car_hor_3.x) ]) = (0);
                ((*out).A[ (((*out).Car_hor_3.y * 7) + ((*out).Car_hor_3.x + (*out).Car_hor_3.length)) ]) = (1);
                ((*out).Car_hor_3.x) = (((*out).Car_hor_3.x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
        }
        l16: if (  ( ((*in)._control.Car_hor_4 == 0) ) )
        {
            l17: if (  ( ((((*in).Car_hor_4.x > 0) && ((*in).A[ (((*in).Car_hor_4.y * 7) + ((*in).Car_hor_4.x - 1)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_4 = 0;
                ((*out).A[ (((*out).Car_hor_4.y * 7) + ((*out).Car_hor_4.x + ((*out).Car_hor_4.length - 1))) ]) = (0);
                ((*out).A[ (((*out).Car_hor_4.y * 7) + ((*out).Car_hor_4.x - 1)) ]) = (1);
                ((*out).Car_hor_4.x) = (((*out).Car_hor_4.x - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
            l18: if (  ( (((((*in).Car_hor_4.x + (*in).Car_hor_4.length) < 7) && ((*in).A[ (((*in).Car_hor_4.y * 7) + ((*in).Car_hor_4.x + (*in).Car_hor_4.length)) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_hor_4 = 0;
                ((*out).A[ (((*out).Car_hor_4.y * 7) + (*out).Car_hor_4.x) ]) = (0);
                ((*out).A[ (((*out).Car_hor_4.y * 7) + ((*out).Car_hor_4.x + (*out).Car_hor_4.length)) ]) = (1);
                ((*out).Car_hor_4.x) = (((*out).Car_hor_4.x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
        }
        l19: if (  ( ((*in)._control.Car_ver_1 == 0) ) )
        {
            l20: if (  ( ((((*in).Car_ver_1.y > 0) && ((*in).A[ ((((*in).Car_ver_1.y - 1) * 7) + (*in).Car_ver_1.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_1 = 0;
                ((*out).A[ ((((*out).Car_ver_1.y + ((*out).Car_ver_1.length - 1)) * 7) + (*out).Car_ver_1.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_1.y - 1) * 7) + (*out).Car_ver_1.x) ]) = (1);
                ((*out).Car_ver_1.y) = (((*out).Car_ver_1.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( (((((*in).Car_ver_1.y + (*in).Car_ver_1.length) < 7) && ((*in).A[ ((((*in).Car_ver_1.y + (*in).Car_ver_1.length) * 7) + (*in).Car_ver_1.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_1 = 0;
                ((*out).A[ (((*out).Car_ver_1.y * 7) + (*out).Car_ver_1.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_1.y + (*out).Car_ver_1.length) * 7) + (*out).Car_ver_1.x) ]) = (1);
                ((*out).Car_ver_1.y) = (((*out).Car_ver_1.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
        }
        l22: if (  ( ((*in)._control.Car_ver_2 == 0) ) )
        {
            l23: if (  ( ((((*in).Car_ver_2.y > 0) && ((*in).A[ ((((*in).Car_ver_2.y - 1) * 7) + (*in).Car_ver_2.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_2 = 0;
                ((*out).A[ ((((*out).Car_ver_2.y + ((*out).Car_ver_2.length - 1)) * 7) + (*out).Car_ver_2.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_2.y - 1) * 7) + (*out).Car_ver_2.x) ]) = (1);
                ((*out).Car_ver_2.y) = (((*out).Car_ver_2.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( (((((*in).Car_ver_2.y + (*in).Car_ver_2.length) < 7) && ((*in).A[ ((((*in).Car_ver_2.y + (*in).Car_ver_2.length) * 7) + (*in).Car_ver_2.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_2 = 0;
                ((*out).A[ (((*out).Car_ver_2.y * 7) + (*out).Car_ver_2.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_2.y + (*out).Car_ver_2.length) * 7) + (*out).Car_ver_2.x) ]) = (1);
                ((*out).Car_ver_2.y) = (((*out).Car_ver_2.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
        }
        l25: if (  ( ((*in)._control.Car_ver_3 == 0) ) )
        {
            l26: if (  ( ((((*in).Car_ver_3.y > 0) && ((*in).A[ ((((*in).Car_ver_3.y - 1) * 7) + (*in).Car_ver_3.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_3 = 0;
                ((*out).A[ ((((*out).Car_ver_3.y + ((*out).Car_ver_3.length - 1)) * 7) + (*out).Car_ver_3.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_3.y - 1) * 7) + (*out).Car_ver_3.x) ]) = (1);
                ((*out).Car_ver_3.y) = (((*out).Car_ver_3.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( (((((*in).Car_ver_3.y + (*in).Car_ver_3.length) < 7) && ((*in).A[ ((((*in).Car_ver_3.y + (*in).Car_ver_3.length) * 7) + (*in).Car_ver_3.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_3 = 0;
                ((*out).A[ (((*out).Car_ver_3.y * 7) + (*out).Car_ver_3.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_3.y + (*out).Car_ver_3.length) * 7) + (*out).Car_ver_3.x) ]) = (1);
                ((*out).Car_ver_3.y) = (((*out).Car_ver_3.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
        }
        l28: if (  ( ((*in)._control.Car_ver_4 == 0) ) )
        {
            l29: if (  ( ((((*in).Car_ver_4.y > 0) && ((*in).A[ ((((*in).Car_ver_4.y - 1) * 7) + (*in).Car_ver_4.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_4 = 0;
                ((*out).A[ ((((*out).Car_ver_4.y + ((*out).Car_ver_4.length - 1)) * 7) + (*out).Car_ver_4.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_4.y - 1) * 7) + (*out).Car_ver_4.x) ]) = (1);
                ((*out).Car_ver_4.y) = (((*out).Car_ver_4.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if (  ( (((((*in).Car_ver_4.y + (*in).Car_ver_4.length) < 7) && ((*in).A[ ((((*in).Car_ver_4.y + (*in).Car_ver_4.length) * 7) + (*in).Car_ver_4.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_4 = 0;
                ((*out).A[ (((*out).Car_ver_4.y * 7) + (*out).Car_ver_4.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_4.y + (*out).Car_ver_4.length) * 7) + (*out).Car_ver_4.x) ]) = (1);
                ((*out).Car_ver_4.y) = (((*out).Car_ver_4.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
        }
        l31: if (  ( ((*in)._control.Car_ver_5 == 0) ) )
        {
            l32: if (  ( ((((*in).Car_ver_5.y > 0) && ((*in).A[ ((((*in).Car_ver_5.y - 1) * 7) + (*in).Car_ver_5.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_5 = 0;
                ((*out).A[ ((((*out).Car_ver_5.y + ((*out).Car_ver_5.length - 1)) * 7) + (*out).Car_ver_5.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_5.y - 1) * 7) + (*out).Car_ver_5.x) ]) = (1);
                ((*out).Car_ver_5.y) = (((*out).Car_ver_5.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
            l33: if (  ( (((((*in).Car_ver_5.y + (*in).Car_ver_5.length) < 7) && ((*in).A[ ((((*in).Car_ver_5.y + (*in).Car_ver_5.length) * 7) + (*in).Car_ver_5.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_5 = 0;
                ((*out).A[ (((*out).Car_ver_5.y * 7) + (*out).Car_ver_5.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_5.y + (*out).Car_ver_5.length) * 7) + (*out).Car_ver_5.x) ]) = (1);
                ((*out).Car_ver_5.y) = (((*out).Car_ver_5.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.Car_ver_6 == 0) ) )
        {
            l35: if (  ( ((((*in).Car_ver_6.y > 0) && ((*in).A[ ((((*in).Car_ver_6.y - 1) * 7) + (*in).Car_ver_6.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_6 = 0;
                ((*out).A[ ((((*out).Car_ver_6.y + ((*out).Car_ver_6.length - 1)) * 7) + (*out).Car_ver_6.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_6.y - 1) * 7) + (*out).Car_ver_6.x) ]) = (1);
                ((*out).Car_ver_6.y) = (((*out).Car_ver_6.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( (((((*in).Car_ver_6.y + (*in).Car_ver_6.length) < 7) && ((*in).A[ ((((*in).Car_ver_6.y + (*in).Car_ver_6.length) * 7) + (*in).Car_ver_6.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_6 = 0;
                ((*out).A[ (((*out).Car_ver_6.y * 7) + (*out).Car_ver_6.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_6.y + (*out).Car_ver_6.length) * 7) + (*out).Car_ver_6.x) ]) = (1);
                ((*out).Car_ver_6.y) = (((*out).Car_ver_6.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
        }
        l37: if (  ( ((*in)._control.Car_ver_7 == 0) ) )
        {
            l38: if (  ( ((((*in).Car_ver_7.y > 0) && ((*in).A[ ((((*in).Car_ver_7.y - 1) * 7) + (*in).Car_ver_7.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_7 = 0;
                ((*out).A[ ((((*out).Car_ver_7.y + ((*out).Car_ver_7.length - 1)) * 7) + (*out).Car_ver_7.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_7.y - 1) * 7) + (*out).Car_ver_7.x) ]) = (1);
                ((*out).Car_ver_7.y) = (((*out).Car_ver_7.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( (((((*in).Car_ver_7.y + (*in).Car_ver_7.length) < 7) && ((*in).A[ ((((*in).Car_ver_7.y + (*in).Car_ver_7.length) * 7) + (*in).Car_ver_7.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_7 = 0;
                ((*out).A[ (((*out).Car_ver_7.y * 7) + (*out).Car_ver_7.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_7.y + (*out).Car_ver_7.length) * 7) + (*out).Car_ver_7.x) ]) = (1);
                ((*out).Car_ver_7.y) = (((*out).Car_ver_7.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
        }
        l40: if (  ( ((*in)._control.Car_ver_8 == 0) ) )
        {
            l41: if (  ( ((((*in).Car_ver_8.y > 0) && ((*in).A[ ((((*in).Car_ver_8.y - 1) * 7) + (*in).Car_ver_8.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_8 = 0;
                ((*out).A[ ((((*out).Car_ver_8.y + ((*out).Car_ver_8.length - 1)) * 7) + (*out).Car_ver_8.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_8.y - 1) * 7) + (*out).Car_ver_8.x) ]) = (1);
                ((*out).Car_ver_8.y) = (((*out).Car_ver_8.y - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( (((((*in).Car_ver_8.y + (*in).Car_ver_8.length) < 7) && ((*in).A[ ((((*in).Car_ver_8.y + (*in).Car_ver_8.length) * 7) + (*in).Car_ver_8.x) ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Car_ver_8 = 0;
                ((*out).A[ (((*out).Car_ver_8.y * 7) + (*out).Car_ver_8.x) ]) = (0);
                ((*out).A[ ((((*out).Car_ver_8.y + (*out).Car_ver_8.length) * 7) + (*out).Car_ver_8.x) ]) = (1);
                ((*out).Car_ver_8.y) = (((*out).Car_ver_8.y + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
        }
    }
    l43: if (  ( system_in_deadlock ) )
    {
    }
    l44: return 0;
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
