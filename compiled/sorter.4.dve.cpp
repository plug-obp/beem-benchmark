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
        uint16_t ButtonControler:1;
        uint16_t ArmControler:2;
        uint16_t Belt2Controler:2;
        uint16_t LightControler:2;
        uint16_t TimerStep:1;
        uint16_t User:2;
        uint16_t ShortBrick1:1;
        uint16_t LongBrick2:1;
    }
    __attribute__((__packed__)) _control;
    uint8_t token;
    uint8_t belt1_moving;
    uint8_t belt2_moving;
    uint8_t arm_kicking;
    uint8_t light_sensor_level;
    uint8_t button_pressed;
    uint8_t put_short_brick;
    uint8_t put_long_brick;
    uint8_t requests;
    uint8_t timer;
    uint8_t brick;
    struct
    {
        uint8_t t1;
    }
    __attribute__((__packed__)) Belt2Controler;
    struct
    {
        uint8_t x;
    }
    __attribute__((__packed__)) LightControler;
    struct
    {
        uint8_t t2;
    }
    __attribute__((__packed__)) User;
    struct
    {
        uint8_t location;
        uint8_t position;
    }
    __attribute__((__packed__)) ShortBrick1;
    struct
    {
        uint8_t location;
        uint8_t position;
    }
    __attribute__((__packed__)) LongBrick2;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.token = 0;
    _out.belt1_moving = 1;
    _out.belt2_moving = 0;
    _out.arm_kicking = 0;
    _out.light_sensor_level = 0;
    _out.button_pressed = 0;
    _out.put_short_brick = 0;
    _out.put_long_brick = 0;
    _out.requests = 0;
    _out.timer = 0;
    _out.brick = 0;
    _out._control.ButtonControler = 0;
    _out._control.ArmControler = 0;
    _out.Belt2Controler.t1 = 0;
    _out._control.Belt2Controler = 0;
    _out._control.LightControler = 0;
    _out._control.TimerStep = 0;
    _out._control.User = 0;
    _out.ShortBrick1.location = 0;
    _out.ShortBrick1.position = 0;
    _out._control.ShortBrick1 = 0;
    _out.LongBrick2.location = 0;
    _out.LongBrick2.position = 0;
    _out._control.LongBrick2 = 0;
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
        l3: if (  ( ((*in)._control.ButtonControler == 0) ) )
        {
            l4: if (  ( ((((*in).token == 0) && ((*in).button_pressed == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ButtonControler = 0;
                ((*out).token) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((((*in).token == 0) && (((*in).button_pressed == 1) && ((*in).requests < 5)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ButtonControler = 0;
                ((*out).button_pressed) = (0);
                ((*out).requests) = (((*out).requests + 1));
                ((*out).token) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((((*in).token == 0) && (((*in).button_pressed == 1) && ((*in).requests == 5)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ButtonControler = 0;
                ((*out).button_pressed) = (0);
                ((*out).token) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
        }
        l7: if (  ( ((*in)._control.ArmControler == 0) ) )
        {
            l8: if (  ( ((((*in).token == 1) && !((((*in).brick == 4) && ((*in).timer > 3)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ArmControler = 0;
                ((*out).token) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 9;
            }
            l9: if (  ( ((((*in).token == 1) && (((*in).brick == 4) && ((*in).timer > 3)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ArmControler = 1;
                ((*out).brick) = (0);
                ((*out).arm_kicking) = (1);
                ((*out).belt1_moving) = (0);
                ((*out).token) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
        }
        l10: if (  ( ((*in)._control.ArmControler == 1) ) )
        {
            l11: if (  ( (((*in).token == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ArmControler = 0;
                ((*out).arm_kicking) = (0);
                ((*out).belt1_moving) = (1);
                ((*out).token) = (2);
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
        }
        l12: if (  ( ((*in)._control.Belt2Controler == 0) ) )
        {
            l13: if (  ( ((((*in).token == 2) && !((((*in).brick == 3) && ((*in).timer > 7)) ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 0;
                ((*out).token) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((((*in).token == 2) && (((*in).brick == 3) && ((*in).timer > 7)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 1;
                ((*out).Belt2Controler.t1) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
        }
        l15: if (  ( ((*in)._control.Belt2Controler == 2) ) )
        {
            l16: if (  ( ((((*in).token == 2) && ((*in).Belt2Controler.t1 < 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 2;
                ((*out).Belt2Controler.t1) = (((*out).Belt2Controler.t1 + 1));
                ((*out).token) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
            l17: if (  ( ((((*in).token == 2) && ((*in).Belt2Controler.t1 == 4))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 0;
                ((*out).token) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 18;
            }
        }
        l18: if (  ( ((*in)._control.Belt2Controler == 1) ) )
        {
            l19: if (  ( (((*in).requests > 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 2;
                ((*out).belt2_moving) = (2);
                ((*out).token) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( (((*in).requests == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.Belt2Controler = 2;
                ((*out).belt2_moving) = (1);
                ((*out).token) = (3);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
        }
        l21: if (  ( ((*in)._control.LightControler == 0) ) )
        {
            l22: if (  ( ((((*in).token == 3) && ((*in).light_sensor_level == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 0;
                ((*out).token) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((((*in).token == 3) && ((*in).light_sensor_level == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 2;
                ((*out).LightControler.x) = (1);
                ((*out).token) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
        }
        l24: if (  ( ((*in)._control.LightControler == 2) ) )
        {
            l25: if (  ( ((((*in).token == 3) && ((*in).light_sensor_level == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 2;
                ((*out).LightControler.x) = (((*out).LightControler.x + 1));
                ((*out).token) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
            l26: if (  ( ((((*in).token == 3) && ((*in).light_sensor_level == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 1;
                ((*out).timer) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
        }
        l27: if (  ( ((*in)._control.LightControler == 1) ) )
        {
            l28: if (  ( (((*in).LightControler.x <= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 0;
                ((*out).brick) = (3);
                ((*out).token) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
            l29: if (  ( (((*in).LightControler.x > 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LightControler = 0;
                ((*out).brick) = (4);
                ((*out).token) = (4);
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
        }
        l30: if (  ( ((*in)._control.TimerStep == 0) ) )
        {
            l31: if (  ( ((((*in).token == 4) && ((*in).timer < 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.TimerStep = 0;
                ((*out).timer) = (((*out).timer + 1));
                ((*out).token) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
            l32: if (  ( ((((*in).token == 4) && ((*in).timer == 8))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.TimerStep = 0;
                ((*out).token) = (5);
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
        }
        l33: if (  ( ((*in)._control.User == 0) ) )
        {
            l34: if (  ( (((*in).token == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 0;
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
            l35: if (  ( (((*in).token == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 0;
                ((*out).button_pressed) = (1);
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( (((*in).token == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 1;
                ((*out).put_short_brick) = (1);
                ((*out).User.t2) = (1);
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( (((*in).token == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 1;
                ((*out).put_long_brick) = (1);
                ((*out).User.t2) = (3);
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.User == 1) ) )
        {
            l39: if (  ( ((((*in).token == 5) && ((*in).User.t2 > 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 1;
                ((*out).User.t2) = (((*out).User.t2 - 1));
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
            l40: if (  ( ((((*in).token == 5) && ((*in).User.t2 == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User = 0;
                ((*out).token) = (6);
                system_in_deadlock = false;
                *to = blob_out;
                return 41;
            }
        }
        l41: if (  ( ((*in)._control.ShortBrick1 == 0) ) )
        {
            l42: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 0) && ((*in).put_short_brick == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 0) && ((*in).put_short_brick == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).put_short_brick) = (0);
                ((*out).ShortBrick1.location) = (1);
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && ((((*in).ShortBrick1.position < 3) || (((*in).ShortBrick1.position == 4) || (((*in).ShortBrick1.position > 5) && ((*in).ShortBrick1.position < 10)))) && ((*in).belt1_moving == 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position + 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
            l45: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).belt1_moving == 1) && ((*in).ShortBrick1.position == 3))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).light_sensor_level) = (1);
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position + 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 46;
            }
            l46: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).belt1_moving == 1) && ((*in).ShortBrick1.position == 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).light_sensor_level) = (0);
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position + 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).ShortBrick1.position == 10) && (((*in).arm_kicking == 0) && ((*in).belt1_moving == 1)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position + 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).ShortBrick1.position == 11) && (((*in).arm_kicking == 0) && ((*in).belt1_moving == 1)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.location) = (2);
                ((*out).ShortBrick1.position) = (3);
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
            l49: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).belt1_moving == 0) && ((*in).ShortBrick1.position < 10))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && (((*in).belt1_moving == 0) && ((((*in).ShortBrick1.position == 10) || ((*in).ShortBrick1.position == 11)) && ((*in).arm_kicking == 0)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 1) && ((((*in).ShortBrick1.position == 10) || ((*in).ShortBrick1.position == 11)) && ((*in).arm_kicking == 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.location) = (3);
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 2) && (((*in).belt2_moving == 1) && ((*in).ShortBrick1.position < 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position + 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 2) && (((*in).belt2_moving == 2) && ((*in).ShortBrick1.position > 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.position) = (((*out).ShortBrick1.position - 1));
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
            l54: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 2) && ((*in).belt2_moving == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 2) && (((*in).belt2_moving == 1) && ((*in).ShortBrick1.position == 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.location) = (4);
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( ((((*in).token == 6) && (((*in).ShortBrick1.location == 2) && (((*in).belt2_moving == 2) && ((*in).ShortBrick1.position == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).ShortBrick1.location) = (5);
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((((*in).ShortBrick1.location == 5) || (((*in).ShortBrick1.location == 4) || ((*in).ShortBrick1.location == 3)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.ShortBrick1 = 0;
                ((*out).token) = (7);
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
        }
        l58: if (  ( ((*in)._control.LongBrick2 == 0) ) )
        {
            l59: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 0) && ((*in).put_long_brick == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 0) && ((*in).put_long_brick == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).put_long_brick) = (0);
                ((*out).LongBrick2.location) = (1);
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).belt1_moving == 1) && (((*in).LongBrick2.position == 0) || ((((*in).LongBrick2.position > 1) && ((*in).LongBrick2.position < 5)) || (((*in).LongBrick2.position > 5) && ((*in).LongBrick2.position < 8)))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position + 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).belt1_moving == 1) && ((*in).LongBrick2.position == 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).light_sensor_level) = (1);
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position + 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
            l63: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).belt1_moving == 1) && ((*in).LongBrick2.position == 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).light_sensor_level) = (0);
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position + 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && ((((*in).LongBrick2.position >= 8) && ((*in).LongBrick2.position <= 10)) && (((*in).arm_kicking == 0) && ((*in).belt1_moving == 1)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position + 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
            l65: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).LongBrick2.position == 11) && (((*in).arm_kicking == 0) && ((*in).belt1_moving == 1)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.location) = (2);
                ((*out).LongBrick2.position) = (3);
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 66;
            }
            l66: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).belt1_moving == 0) && ((*in).LongBrick2.position < 8))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).belt1_moving == 0) && ((((*in).LongBrick2.position >= 8) || ((*in).LongBrick2.position == 11)) && ((*in).arm_kicking == 0)))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
            l68: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 1) && (((*in).LongBrick2.position >= 8) && ((*in).arm_kicking == 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.location) = (3);
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 2) && (((*in).belt2_moving == 1) && ((*in).LongBrick2.position < 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position + 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 2) && (((*in).belt2_moving == 2) && ((*in).LongBrick2.position > 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.position) = (((*out).LongBrick2.position - 1));
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 2) && ((*in).belt2_moving == 0)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 2) && (((*in).belt2_moving == 1) && ((*in).LongBrick2.position == 5))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.location) = (4);
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( ((((*in).token == 7) && (((*in).LongBrick2.location == 2) && (((*in).belt2_moving == 2) && ((*in).LongBrick2.position == 0))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).LongBrick2.location) = (5);
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( ((((*in).LongBrick2.location == 5) || (((*in).LongBrick2.location == 4) || ((*in).LongBrick2.location == 3)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.LongBrick2 = 0;
                ((*out).token) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
        }
    }
    l75: if (  ( system_in_deadlock ) )
    {
    }
    l76: return 0;
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
