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
        uint16_t User_0:3;
        uint16_t User_1:3;
        uint16_t UserAdmin_0:3;
        uint16_t UserAdmin_1:3;
        uint16_t CC:6;
        uint16_t Vault:2;
        uint16_t channel_ccToUser_0:2;
        uint16_t channel_ccToUser_1:2;
    }
    __attribute__((__packed__)) _control;
    struct
    {
        uint8_t cmd;
        uint8_t edit[1];
        uint8_t registered[1];
        uint8_t waitingForCheckedOut;
    }
    __attribute__((__packed__)) User_0;
    struct
    {
        uint8_t cmd;
        uint8_t edit[1];
        uint8_t registered[1];
        uint8_t waitingForCheckedOut;
    }
    __attribute__((__packed__)) User_1;
    struct
    {
        uint8_t cmd;
    }
    __attribute__((__packed__)) UserAdmin_0;
    struct
    {
        uint8_t cmd;
    }
    __attribute__((__packed__)) UserAdmin_1;
    struct
    {
        uint8_t cmd;
        uint8_t ID;
        uint8_t registered[2];
        uint8_t writeLock;
    }
    __attribute__((__packed__)) CC;
    struct
    {
        uint8_t cmd;
    }
    __attribute__((__packed__)) Vault;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ccToUser_0;
    struct
    {
        uint8_t v;
    }
    __attribute__((__packed__)) channel_ccToUser_1;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.User_0.waitingForCheckedOut = 0;
    _out._control.User_0 = 0;
    _out.User_1.waitingForCheckedOut = 0;
    _out._control.User_1 = 0;
    _out._control.UserAdmin_0 = 0;
    _out._control.UserAdmin_1 = 0;
    _out.CC.writeLock = 0;
    _out._control.CC = 0;
    _out._control.Vault = 0;
    _out._control.channel_ccToUser_0 = 0;
    _out._control.channel_ccToUser_1 = 0;
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
        l3: if (  ( ((*in)._control.User_0 == 6) ) )
        {
            l4: if (  ( (((*in).User_0.cmd == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.edit[ 0 ]) = (1);
                ((*out).User_0.waitingForCheckedOut) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( (((*in).User_0.cmd == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.waitingForCheckedOut) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
        }
        l6: if (  ( ((*in)._control.User_0 == 1) ) )
        {
            l7: if (  ( ((*in)._control.channel_ccToUser_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User_0.cmd) = ((*in).channel_ccToUser_0.v);
                (*out)._control.User_0 = 2;
                (*out)._control.channel_ccToUser_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
        }
        l8: if (  ( ((*in)._control.User_0 == 3) ) )
        {
            l9: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
        }
        l10: if (  ( ((*in)._control.User_0 == 4) ) )
        {
            l11: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
        }
        l12: if (  ( ((*in)._control.User_0 == 2) ) )
        {
            l13: if (  ( (((*in).User_0.cmd == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 0;
                ((*out).User_0.registered[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
        }
        l14: if (  ( ((*in)._control.User_0 == 0) ) )
        {
            l15: if (  ( (((*in).User_0.edit[ 0 ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_0 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.channel_ccToUser_0 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User_0.cmd) = ((*in).channel_ccToUser_0.v);
                (*out)._control.User_0 = 6;
                (*out)._control.channel_ccToUser_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
        }
        l17: if (  ( ((*in)._control.User_1 == 6) ) )
        {
            l18: if (  ( (((*in).User_1.cmd == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.edit[ 0 ]) = (1);
                ((*out).User_1.waitingForCheckedOut) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( (((*in).User_1.cmd == 4)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.waitingForCheckedOut) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
        }
        l20: if (  ( ((*in)._control.User_1 == 1) ) )
        {
            l21: if (  ( ((*in)._control.channel_ccToUser_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User_1.cmd) = ((*in).channel_ccToUser_1.v);
                (*out)._control.User_1 = 2;
                (*out)._control.channel_ccToUser_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 22;
            }
        }
        l22: if (  ( ((*in)._control.User_1 == 3) ) )
        {
            l23: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
        }
        l24: if (  ( ((*in)._control.User_1 == 4) ) )
        {
            l25: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 26;
            }
        }
        l26: if (  ( ((*in)._control.User_1 == 2) ) )
        {
            l27: if (  ( (((*in).User_1.cmd == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 0;
                ((*out).User_1.registered[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
        }
        l28: if (  ( ((*in)._control.User_1 == 0) ) )
        {
            l29: if (  ( (((*in).User_1.edit[ 0 ] == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.User_1 = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 30;
            }
            l30: if (  ( ((*in)._control.channel_ccToUser_1 == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).User_1.cmd) = ((*in).channel_ccToUser_1.v);
                (*out)._control.User_1 = 6;
                (*out)._control.channel_ccToUser_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
        }
        l31: if (  ( ((*in)._control.UserAdmin_0 == 2) ) )
        {
            l32: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.UserAdmin_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 33;
            }
        }
        l33: if (  ( ((*in)._control.UserAdmin_0 == 3) ) )
        {
            l34: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.UserAdmin_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 35;
            }
        }
        l35: if (  ( ((*in)._control.UserAdmin_0 == 0) ) )
        {
            l36: if (  ( ((*in)._control.CC == 32) )  &&  ( ((((*in).CC.ID == 0) && (((*in).CC.ID != ((*in).CC.cmd % 16)) && ((*in).CC.registered[ (*in).CC.ID ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).UserAdmin_0.cmd) = (12);
                (*out)._control.UserAdmin_0 = 1;
                (*out)._control.CC = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
            l37: if (  ( ((*in)._control.CC == 46) )  &&  ( ((((*in).CC.ID == 0) && (((*in).CC.ID != ((*in).CC.cmd % 16)) && ((*in).CC.registered[ (*in).CC.ID ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).UserAdmin_0.cmd) = (11);
                (*out)._control.UserAdmin_0 = 1;
                (*out)._control.CC = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 38;
            }
        }
        l38: if (  ( ((*in)._control.UserAdmin_1 == 2) ) )
        {
            l39: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.UserAdmin_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
        }
        l40: if (  ( ((*in)._control.UserAdmin_1 == 3) ) )
        {
            l41: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.UserAdmin_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
        }
        l42: if (  ( ((*in)._control.UserAdmin_1 == 0) ) )
        {
            l43: if (  ( ((*in)._control.CC == 32) )  &&  ( ((((*in).CC.ID == 1) && (((*in).CC.ID != ((*in).CC.cmd % 16)) && ((*in).CC.registered[ (*in).CC.ID ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).UserAdmin_1.cmd) = (12);
                (*out)._control.UserAdmin_1 = 1;
                (*out)._control.CC = 18;
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((*in)._control.CC == 46) )  &&  ( ((((*in).CC.ID == 1) && (((*in).CC.ID != ((*in).CC.cmd % 16)) && ((*in).CC.registered[ (*in).CC.ID ] == 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).UserAdmin_1.cmd) = (11);
                (*out)._control.UserAdmin_1 = 1;
                (*out)._control.CC = 19;
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
        }
        l45: if (  ( ((*in)._control.CC == 42) ) )
        {
            l46: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 45;
                ((*out).CC.ID) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
        }
        l47: if (  ( ((*in)._control.CC == 40) ) )
        {
            l48: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((1 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 41;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
            l49: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((3 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 41;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 50;
            }
            l50: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 7)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((7 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 41;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
        }
        l51: if (  ( ((*in)._control.CC == 41) ) )
        {
            l52: if (  ( (((((*in).CC.cmd / 16) == 11) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 11;
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
            l53: if (  ( (((((*in).CC.cmd / 16) == 11) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 22;
                system_in_deadlock = false;
                *to = blob_out;
                return 54;
            }
        }
        l54: if (  ( ((*in)._control.CC == 37) ) )
        {
        }
        l55: if (  ( ((*in)._control.CC == 38) ) )
        {
            l56: if (  ( ((((*in).CC.cmd % 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( ((((*in).CC.cmd % 16) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 20;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
        }
        l58: if (  ( ((*in)._control.CC == 29) ) )
        {
            l59: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((1 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 30;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 60;
            }
            l60: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((3 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 30;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 7)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((7 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 30;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
        }
        l62: if (  ( ((*in)._control.CC == 31) ) )
        {
            l63: if (  ( (((*in).CC.ID < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 32;
                system_in_deadlock = false;
                *to = blob_out;
                return 64;
            }
            l64: if (  ( (((*in).CC.ID >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.CC == 32) ) )
        {
            l66: if (  ( ((((*in).CC.ID == ((*in).CC.cmd % 16)) || ((*in).CC.registered[ (*in).CC.ID ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 31;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
        }
        l67: if (  ( ((*in)._control.CC == 44) ) )
        {
            l68: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 69;
            }
            l69: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
        }
        l70: if (  ( ((*in)._control.CC == 43) ) )
        {
            l71: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
        }
        l73: if (  ( ((*in)._control.CC == 1) ) )
        {
            l74: if (  ( (((((*in).CC.cmd / 16) == 0) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
            l75: if (  ( (((((*in).CC.cmd / 16) == 0) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( (((((*in).CC.cmd / 16) == 9) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if (  ( (((((*in).CC.cmd / 16) == 9) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 14;
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( (((((*in).CC.cmd / 16) == 10) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( (((((*in).CC.cmd / 16) == 10) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 15;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( ((((*in).CC.cmd / 16) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 27;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
            l81: if (  ( ((((*in).CC.cmd / 16) == 5)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 35;
                system_in_deadlock = false;
                *to = blob_out;
                return 82;
            }
            l82: if (  ( ((((*in).CC.cmd / 16) == 7)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 36;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( ((((*in).CC.cmd / 16) == 8)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 39;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
        }
        l84: if (  ( ((*in)._control.CC == 11) ) )
        {
            l85: if (  ( (((*in).CC.writeLock == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 43;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( (((*in).CC.writeLock == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 44;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
        }
        l87: if (  ( ((*in)._control.CC == 22) ) )
        {
            l88: if (  ( (((*in).CC.writeLock == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 43;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( (((*in).CC.writeLock == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 44;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
        }
        l90: if (  ( ((*in)._control.CC == 27) ) )
        {
            l91: if (  ( (((*in).CC.writeLock == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 28;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
        }
        l92: if (  ( ((*in)._control.CC == 34) ) )
        {
            l93: if (  ( ((((*in).CC.cmd % 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
            l94: if (  ( ((((*in).CC.cmd % 16) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 16;
                system_in_deadlock = false;
                *to = blob_out;
                return 95;
            }
        }
        l95: if (  ( ((*in)._control.CC == 5) ) )
        {
            l96: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 31;
                ((*out).CC.ID) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
        }
        l97: if (  ( ((*in)._control.CC == 16) ) )
        {
            l98: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 31;
                ((*out).CC.ID) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
        }
        l99: if (  ( ((*in)._control.CC == 2) ) )
        {
            l100: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 24;
                ((*out).CC.registered[ ((*out).CC.cmd % 16) ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
        }
        l101: if (  ( ((*in)._control.CC == 13) ) )
        {
            l102: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 24;
                ((*out).CC.registered[ ((*out).CC.cmd % 16) ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
        }
        l103: if (  ( ((*in)._control.CC == 33) ) )
        {
            l104: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
        }
        l105: if (  ( ((*in)._control.CC == 6) ) )
        {
            l106: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 31;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
        }
        l107: if (  ( ((*in)._control.CC == 17) ) )
        {
            l108: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 31;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
        }
        l109: if (  ( ((*in)._control.CC == 3) ) )
        {
            l110: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                ((*out).CC.registered[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
        }
        l111: if (  ( ((*in)._control.CC == 14) ) )
        {
            l112: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                ((*out).CC.registered[ 1 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
        }
        l113: if (  ( ((*in)._control.CC == 35) ) )
        {
            l114: if (  ( ((((*in).CC.cmd % 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
            l115: if (  ( ((((*in).CC.cmd % 16) == 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 20;
                system_in_deadlock = false;
                *to = blob_out;
                return 116;
            }
        }
        l116: if (  ( ((*in)._control.CC == 9) ) )
        {
            l117: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                ((*out).CC.writeLock) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 118;
            }
            l118: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
        }
        l119: if (  ( ((*in)._control.CC == 20) ) )
        {
            l120: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                ((*out).CC.writeLock) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
            l121: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 42;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
        }
        l122: if (  ( ((*in)._control.CC == 4) ) )
        {
            l123: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                ((*out).CC.registered[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
        }
        l124: if (  ( ((*in)._control.CC == 15) ) )
        {
            l125: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                ((*out).CC.registered[ 1 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
        }
        l126: if (  ( ((*in)._control.CC == 12) ) )
        {
            l127: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 45;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 128;
            }
        }
        l128: if (  ( ((*in)._control.CC == 23) ) )
        {
            l129: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 45;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
        }
        l130: if (  ( ((*in)._control.CC == 25) ) )
        {
            l131: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((1 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 26;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((3 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 26;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((*in)._control.Vault == 1) )  &&  ( ((((*in).Vault.cmd / 16) == 7)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((7 * 16) + ((*in).Vault.cmd % 16)));
                (*out)._control.CC = 26;
                (*out)._control.Vault = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
        }
        l134: if (  ( ((*in)._control.CC == 7) ) )
        {
            l135: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 6;
                (*out)._control.UserAdmin_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
            l136: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 6;
                (*out)._control.UserAdmin_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 137;
            }
            l137: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 6;
                (*out)._control.UserAdmin_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 138;
            }
            l138: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 6;
                (*out)._control.UserAdmin_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
        }
        l139: if (  ( ((*in)._control.CC == 18) ) )
        {
            l140: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 17;
                (*out)._control.UserAdmin_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
            l141: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 17;
                (*out)._control.UserAdmin_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
            l142: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 17;
                (*out)._control.UserAdmin_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
            l143: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 17;
                (*out)._control.UserAdmin_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
        }
        l144: if (  ( ((*in)._control.CC == 0) ) )
        {
            l145: if (  ( ((*in)._control.User_0 == 0) )  &&  ( (((*in).User_0.waitingForCheckedOut == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((0 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
            l146: if (  ( ((*in)._control.User_0 == 0) )  &&  ( ((((*in).User_0.registered[ 0 ] == 0) && ((*in).User_0.edit[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((9 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 3;
                ((*out).User_0.registered[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
            l147: if (  ( ((*in)._control.User_0 == 0) )  &&  ( ((((*in).User_0.registered[ 0 ] == 1) && ((*in).User_0.edit[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((10 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 4;
                ((*out).User_0.registered[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 148;
            }
            l148: if (  ( ((*in)._control.User_0 == 0) )  &&  ( ((((*in).User_0.edit[ 0 ] == 0) && ((*in).User_0.waitingForCheckedOut == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((2 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 0;
                ((*out).User_0.waitingForCheckedOut) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 149;
            }
            l149: if (  ( ((*in)._control.User_0 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((5 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 0;
                ((*out).User_0.edit[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 150;
            }
            l150: if (  ( ((*in)._control.User_0 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((7 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 0;
                ((*out).User_0.edit[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
            l151: if (  ( ((*in)._control.User_0 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((8 * 16) + 0));
                (*out)._control.CC = 1;
                (*out)._control.User_0 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 152;
            }
            l152: if (  ( ((*in)._control.User_1 == 0) )  &&  ( (((*in).User_1.waitingForCheckedOut == 0)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((0 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 1;
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
            l153: if (  ( ((*in)._control.User_1 == 0) )  &&  ( ((((*in).User_1.registered[ 0 ] == 0) && ((*in).User_1.edit[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((9 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 3;
                ((*out).User_1.registered[ 0 ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 154;
            }
            l154: if (  ( ((*in)._control.User_1 == 0) )  &&  ( ((((*in).User_1.registered[ 0 ] == 1) && ((*in).User_1.edit[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((10 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 4;
                ((*out).User_1.registered[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
            l155: if (  ( ((*in)._control.User_1 == 0) )  &&  ( ((((*in).User_1.edit[ 0 ] == 0) && ((*in).User_1.waitingForCheckedOut == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((2 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 0;
                ((*out).User_1.waitingForCheckedOut) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 156;
            }
            l156: if (  ( ((*in)._control.User_1 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((5 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 0;
                ((*out).User_1.edit[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
            l157: if (  ( ((*in)._control.User_1 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((7 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 0;
                ((*out).User_1.edit[ 0 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 158;
            }
            l158: if (  ( ((*in)._control.User_1 == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).CC.cmd) = (((8 * 16) + 1));
                (*out)._control.CC = 1;
                (*out)._control.User_1 = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 159;
            }
        }
        l159: if (  ( ((*in)._control.CC == 8) ) )
        {
            l160: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 12;
                (*out)._control.UserAdmin_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 161;
            }
            l161: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 12;
                (*out)._control.UserAdmin_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 162;
            }
            l162: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 12;
                (*out)._control.UserAdmin_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 163;
            }
            l163: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 12;
                (*out)._control.UserAdmin_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 164;
            }
        }
        l164: if (  ( ((*in)._control.CC == 19) ) )
        {
            l165: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 23;
                (*out)._control.UserAdmin_0 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 166;
            }
            l166: if (  ( ((*in)._control.UserAdmin_0 == 1) )  &&  ( (((*in).UserAdmin_0.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 23;
                (*out)._control.UserAdmin_0 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 167;
            }
            l167: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 12)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 23;
                (*out)._control.UserAdmin_1 = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 168;
            }
            l168: if (  ( ((*in)._control.UserAdmin_1 == 1) )  &&  ( (((*in).UserAdmin_1.cmd == 11)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 23;
                (*out)._control.UserAdmin_1 = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 169;
            }
        }
        l169: if (  ( ((*in)._control.CC == 45) ) )
        {
            l170: if (  ( (((*in).CC.ID < 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 46;
                system_in_deadlock = false;
                *to = blob_out;
                return 171;
            }
            l171: if (  ( (((*in).CC.ID >= 2)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 172;
            }
        }
        l172: if (  ( ((*in)._control.CC == 46) ) )
        {
            l173: if (  ( ((((*in).CC.ID == ((*in).CC.cmd % 16)) || ((*in).CC.registered[ (*in).CC.ID ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.CC = 45;
                ((*out).CC.ID) = (((*out).CC.ID + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 174;
            }
        }
        l174: if (  ( ((*in)._control.Vault == 0) ) )
        {
            l175: if (  ( ((*in)._control.CC == 24) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Vault.cmd) = ((*in).CC.cmd);
                (*out)._control.Vault = 1;
                (*out)._control.CC = 25;
                system_in_deadlock = false;
                *to = blob_out;
                return 176;
            }
            l176: if (  ( ((*in)._control.CC == 28) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Vault.cmd) = ((*in).CC.cmd);
                (*out)._control.Vault = 1;
                (*out)._control.CC = 29;
                ((*out).CC.writeLock) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 177;
            }
            l177: if (  ( ((*in)._control.CC == 36) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Vault.cmd) = ((*in).CC.cmd);
                (*out)._control.Vault = 1;
                (*out)._control.CC = 37;
                ((*out).CC.writeLock) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 178;
            }
            l178: if (  ( ((*in)._control.CC == 39) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).Vault.cmd) = (((7 * 16) + ((*in).CC.cmd % 16)));
                (*out)._control.Vault = 1;
                (*out)._control.CC = 40;
                system_in_deadlock = false;
                *to = blob_out;
                return 179;
            }
        }
        l179: if (  ( ((*in)._control.channel_ccToUser_0 == 0) ) )
        {
            l180: if (  ( ((*in)._control.CC == 26) )  &&  ( (((((*in).CC.cmd / 16) == 1) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_0.v) = (1);
                (*out)._control.channel_ccToUser_0 = 1;
                (*out)._control.CC = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 181;
            }
            l181: if (  ( ((*in)._control.CC == 30) )  &&  ( (((((*in).CC.cmd / 16) == 3) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_0.v) = (3);
                (*out)._control.channel_ccToUser_0 = 1;
                (*out)._control.CC = 34;
                system_in_deadlock = false;
                *to = blob_out;
                return 182;
            }
            l182: if (  ( ((*in)._control.CC == 27) )  &&  ( ((((*in).CC.writeLock == 1) && (((*in).CC.cmd % 16) == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_0.v) = (4);
                (*out)._control.channel_ccToUser_0 = 1;
                (*out)._control.CC = 33;
                system_in_deadlock = false;
                *to = blob_out;
                return 183;
            }
        }
        l183: if (  ( ((*in)._control.channel_ccToUser_1 == 0) ) )
        {
            l184: if (  ( ((*in)._control.CC == 26) )  &&  ( (((((*in).CC.cmd / 16) == 1) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_1.v) = (1);
                (*out)._control.channel_ccToUser_1 = 1;
                (*out)._control.CC = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 185;
            }
            l185: if (  ( ((*in)._control.CC == 30) )  &&  ( (((((*in).CC.cmd / 16) == 3) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_1.v) = (3);
                (*out)._control.channel_ccToUser_1 = 1;
                (*out)._control.CC = 34;
                system_in_deadlock = false;
                *to = blob_out;
                return 186;
            }
            l186: if (  ( ((*in)._control.CC == 27) )  &&  ( ((((*in).CC.writeLock == 1) && (((*in).CC.cmd % 16) == 1))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).channel_ccToUser_1.v) = (4);
                (*out)._control.channel_ccToUser_1 = 1;
                (*out)._control.CC = 33;
                system_in_deadlock = false;
                *to = blob_out;
                return 187;
            }
        }
    }
    l187: if (  ( system_in_deadlock ) )
    {
    }
    l188: return 0;
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
        case 153: goto l153;
        case 154: goto l154;
        case 155: goto l155;
        case 156: goto l156;
        case 157: goto l157;
        case 158: goto l158;
        case 159: goto l159;
        case 160: goto l160;
        case 161: goto l161;
        case 162: goto l162;
        case 163: goto l163;
        case 164: goto l164;
        case 165: goto l165;
        case 166: goto l166;
        case 167: goto l167;
        case 168: goto l168;
        case 169: goto l169;
        case 170: goto l170;
        case 171: goto l171;
        case 172: goto l172;
        case 173: goto l173;
        case 174: goto l174;
        case 175: goto l175;
        case 176: goto l176;
        case 177: goto l177;
        case 178: goto l178;
        case 179: goto l179;
        case 180: goto l180;
        case 181: goto l181;
        case 182: goto l182;
        case 183: goto l183;
        case 184: goto l184;
        case 185: goto l185;
        case 186: goto l186;
        case 187: goto l187;
        case 188: goto l188;
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
