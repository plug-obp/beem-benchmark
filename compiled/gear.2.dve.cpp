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
        uint16_t Clutch:3;
        uint16_t GearBox:3;
        uint16_t Engine:4;
        uint16_t Interface:2;
        uint16_t GearControl:5;
        uint16_t Timer:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t tGB;
    uint8_t tC;
    uint8_t tE;
    uint8_t tGC;
    int16_t toGear;
    int16_t currentGear;
    struct
    {
        int16_t dir;
    }
    __attribute__((__packed__)) GearControl;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.tGB = 255;
    _out.tC = 255;
    _out.tE = 255;
    _out.tGC = 255;
    _out.toGear = 0;
    _out.currentGear = 0;
    _out._control.Clutch = 0;
    _out._control.GearBox = 0;
    _out._control.Engine = 4;
    _out._control.Interface = 0;
    _out._control.GearControl = 0;
    _out._control.Timer = 0;
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
        l3: if (  ( ((*in)._control.Clutch == 0) ) )
        {
            l4: if (  ( ((*in)._control.GearControl == 12) )  &&  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 1;
                ((*out).tC) = (3);
                (*out)._control.GearControl = 10;
                ((*out).tGC) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((*in)._control.GearControl == 2) )  &&  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 1;
                ((*out).tC) = (3);
                (*out)._control.GearControl = 23;
                ((*out).tGC) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
        }
        l6: if (  ( ((*in)._control.Clutch == 3) ) )
        {
            l7: if (  ( (((*in).tC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 5;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
        }
        l8: if (  ( ((*in)._control.Clutch == 2) ) )
        {
            l9: if (  ( ((*in)._control.GearControl == 11) )  &&  ( (((*in).toGear == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 3;
                ((*out).tC) = (3);
                (*out)._control.GearControl = 22;
                ((*out).tGC) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
            l10: if (  ( ((*in)._control.GearControl == 20) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 3;
                ((*out).tC) = (3);
                (*out)._control.GearControl = 19;
                ((*out).tGC) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 11;
            }
        }
        l11: if (  ( ((*in)._control.Clutch == 1) ) )
        {
            l12: if (  ( (((*in).tC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Clutch = 4;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 13;
            }
        }
        l13: if (  ( ((*in)._control.GearBox == 1) ) )
        {
            l14: if (  ( (((*in).tGB == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 4;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
        l15: if (  ( ((*in)._control.GearBox == 2) ) )
        {
            l16: if (  ( ((*in)._control.GearControl == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 3;
                ((*out).tGB) = (4);
                (*out)._control.GearControl = 4;
                ((*out).tGC) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((*in)._control.GearControl == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 3;
                ((*out).tGB) = (4);
                (*out)._control.GearControl = 8;
                ((*out).tGC) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
        }
        l18: if (  ( ((*in)._control.GearBox == 0) ) )
        {
            l19: if (  ( ((*in)._control.GearControl == 13) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 1;
                ((*out).tGB) = (6);
                (*out)._control.GearControl = 15;
                ((*out).tGC) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.GearControl == 11) )  &&  ( (((*in).toGear != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 1;
                ((*out).tGB) = (6);
                (*out)._control.GearControl = 17;
                ((*out).tGC) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
            l21: if (  ( ((*in)._control.GearControl == 14) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 1;
                ((*out).tGB) = (6);
                (*out)._control.GearControl = 17;
                ((*out).tGC) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
        }
        l22: if (  ( ((*in)._control.GearBox == 3) ) )
        {
            l23: if (  ( (((*in).tGB == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearBox = 5;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
        }
        l24: if (  ( ((*in)._control.Engine == 2) ) )
        {
            l25: if (  ( (((*in).tE == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 6;
                ((*out).tE) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( (((*in).tE < 17)) )  &&  ( ((*in)._control.GearControl == 18) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 0;
                ((*out).tE) = (255);
                (*out)._control.GearControl = 21;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.Engine == 3) ) )
        {
            l28: if (  ( (((*in).toGear == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( (((*in).toGear != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 2;
                ((*out).tE) = (18);
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.Engine == 1) ) )
        {
            l31: if (  ( (((*in).tE == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
        }
        l32: if (  ( ((*in)._control.Engine == 7) ) )
        {
            l33: if (  ( (((*in).tE == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.Engine == 4) ) )
        {
            l35: if (  ( ((*in)._control.GearControl == 9) )  &&  ( (((*in).toGear != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 7;
                ((*out).tE) = (4);
                (*out)._control.GearControl = 12;
                ((*out).tGC) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
        }
        l36: if (  ( ((*in)._control.Engine == 5) ) )
        {
            l37: if (  ( (((*in).tE == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 6;
                ((*out).tE) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
            l38: if (  ( (((*in).tE > 0)) )  &&  ( ((*in)._control.GearControl == 18) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 0;
                ((*out).tE) = (255);
                (*out)._control.GearControl = 21;
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
        }
        l39: if (  ( ((*in)._control.Engine == 0) ) )
        {
            l40: if (  ( ((*in)._control.GearControl == 1) )  &&  ( (((*in).currentGear != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 1;
                ((*out).tE) = (8);
                (*out)._control.GearControl = 2;
                ((*out).tGC) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.Engine == 8) ) )
        {
            l42: if (  ( (((*in).toGear == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( (((*in).toGear != 0)) )  &&  ( ((*in)._control.GearControl == 9) )  &&  ( (((*in).toGear != 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Engine = 7;
                ((*out).tE) = (4);
                (*out)._control.GearControl = 12;
                ((*out).tGC) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
        }
        l44: if (  ( ((*in)._control.Interface == 2) ) )
        {
            l45: if (  ( ((*in)._control.GearControl == 21) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Interface = 0;
                ((*out).currentGear) = (((*out).currentGear - 1));
                (*out)._control.GearControl = 0;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
        }
        l46: if (  ( ((*in)._control.Interface == 1) ) )
        {
            l47: if (  ( ((*in)._control.GearControl == 21) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Interface = 0;
                ((*out).currentGear) = (((*out).currentGear + 1));
                (*out)._control.GearControl = 0;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
        }
        l48: if (  ( ((*in)._control.GearControl == 10) ) )
        {
            l49: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( ((*in)._control.Clutch == 1) )  &&  ( (((*in).tC <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 14;
                ((*out).tGC) = (0);
                (*out)._control.Clutch = 2;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
        }
        l51: if (  ( ((*in)._control.GearControl == 23) ) )
        {
            l52: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 5;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( ((*in)._control.Clutch == 1) )  &&  ( (((*in).tC <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 6;
                ((*out).tGC) = (0);
                (*out)._control.Clutch = 2;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.GearControl == 19) ) )
        {
            l55: if (  ( ((*in)._control.Clutch == 3) )  &&  ( (((*in).tC <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 18;
                ((*out).tGC) = (0);
                (*out)._control.Clutch = 0;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 24;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
        }
        l57: if (  ( ((*in)._control.GearControl == 22) ) )
        {
            l58: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 24;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
            l59: if (  ( ((*in)._control.Clutch == 3) )  &&  ( (((*in).tC <= 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 21;
                ((*out).tGC) = (0);
                (*out)._control.Clutch = 0;
                ((*out).tC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
        }
        l60: if (  ( ((*in)._control.GearControl == 4) ) )
        {
            l61: if (  ( ((*in)._control.GearBox == 3) )  &&  ( (((*in).tGB <= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 9;
                (*out)._control.GearBox = 0;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 7;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
        }
        l63: if (  ( ((*in)._control.GearControl == 8) ) )
        {
            l64: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 7;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( ((*in)._control.GearBox == 3) )  &&  ( (((*in).tGB <= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 11;
                ((*out).tGC) = (0);
                (*out)._control.GearBox = 0;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
        }
        l66: if (  ( ((*in)._control.GearControl == 15) ) )
        {
            l67: if (  ( ((*in)._control.GearBox == 1) )  &&  ( (((*in).tGB <= 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 18;
                ((*out).tGC) = (0);
                (*out)._control.GearBox = 2;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 16;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
        }
        l69: if (  ( ((*in)._control.GearControl == 17) ) )
        {
            l70: if (  ( (((*in).tGC == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 16;
                ((*out).tGC) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( ((*in)._control.GearBox == 1) )  &&  ( (((*in).tGB <= 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 20;
                ((*out).tGC) = (0);
                (*out)._control.GearBox = 2;
                ((*out).tGB) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
        }
        l72: if (  ( ((*in)._control.GearControl == 12) ) )
        {
            l73: if (  ( (((*in).tGC > 0)) )  &&  ( ((*in)._control.Engine == 7) )  &&  ( (((*in).tE <= 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 13;
                (*out)._control.Engine = 5;
                ((*out).tE) = (10);
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
        }
        l74: if (  ( ((*in)._control.GearControl == 2) ) )
        {
            l75: if (  ( (((*in).tGC > 0)) )  &&  ( ((*in)._control.Engine == 1) )  &&  ( (((*in).tE <= 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 3;
                (*out)._control.Engine = 8;
                ((*out).tE) = (255);
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
        }
        l76: if (  ( ((*in)._control.GearControl == 0) ) )
        {
            l77: if (  ( ((*in)._control.Interface == 0) )  &&  ( (((*in).currentGear < 30)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).GearControl.dir) = (1);
                (*out)._control.GearControl = 1;
                ((*out).toGear) = (((*out).toGear + (*out).GearControl.dir));
                (*out)._control.Interface = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( ((*in)._control.Interface == 0) )  &&  ( (((*in).currentGear > -1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).GearControl.dir) = (-1);
                (*out)._control.GearControl = 1;
                ((*out).toGear) = (((*out).toGear + (*out).GearControl.dir));
                (*out)._control.Interface = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
        }
        l79: if (  ( ((*in)._control.GearControl == 1) ) )
        {
            l80: if (  ( (((*in).currentGear == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
        }
        l81: if (  ( ((*in)._control.GearControl == 9) ) )
        {
            l82: if (  ( (((*in).toGear == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.GearControl = 21;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
        }
        l83: if (  ( ((*in)._control.Timer == 0) ) )
        {
            l84: if (  ( ((((*in).tGB != 0) && (((*in).tC != 0) && (((*in).tE != 0) && ((*in).tGC != 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Timer = 0;
                ((*out).tGB) = ((((*out).tGB - 1) | (((*out).tGB == 255) * 255)));
                ((*out).tC) = ((((*out).tC - 1) | (((*out).tC == 255) * 255)));
                ((*out).tE) = ((((*out).tE - 1) | (((*out).tE == 255) * 255)));
                ((*out).tGC) = ((((*out).tGC - 1) | (((*out).tGC == 255) * 255)));
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
        }
    }
    l85: if (  ( system_in_deadlock ) )
    {
    }
    l86: return 0;
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
