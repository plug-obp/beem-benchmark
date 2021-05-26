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



const int16_t DELAY = 2;
const int16_t TXW_SIZE = 4;
const int16_t RXW_SIZE = 4;

struct state_struct_t
{
    struct
    {
        uint16_t sender:4;
        uint16_t clock:1;
        uint16_t element:4;
        uint16_t receiver:4;
        uint16_t SN:3;
        uint16_t NS:2;
        uint16_t NR:3;
        uint16_t RN:2;
    }
    __attribute__((__packed__)) _control;
    uint8_t SN_time[7];
    uint8_t SN_size;
    uint8_t NS_time[7];
    uint8_t NS_size;
    uint8_t NR_time[7];
    uint8_t NR_size;
    uint8_t RN_time[7];
    uint8_t RN_size;
    uint8_t x;
    uint8_t sqn;
    uint8_t c;
    uint8_t packet;
    uint8_t close;
    uint8_t TXW_TRAIL;
    uint8_t TXW_LEAD;
    uint8_t RXW_LEAD;
    uint8_t RXW_TRAIL;
    struct
    {
        uint8_t packet;
        uint8_t nloss;
        uint8_t i;
        uint8_t rs_len;
        uint8_t rs[2];
        uint8_t seq;
        uint8_t trail;
    }
    __attribute__((__packed__)) element;
    struct
    {
        uint8_t packet;
        uint8_t sqn;
        uint8_t trail;
        uint8_t outloss;
        uint8_t outdata;
        uint8_t RXW[4];
    }
    __attribute__((__packed__)) receiver;
    struct
    {
        uint8_t buf_0[7];
        uint8_t buf_1[7];
        uint8_t buf_2[7];
    }
    __attribute__((__packed__)) SN;
    struct
    {
        uint8_t buf_0[7];
    }
    __attribute__((__packed__)) NS;
    struct
    {
        uint8_t buf_0[7];
        uint8_t buf_1[7];
        uint8_t buf_2[7];
    }
    __attribute__((__packed__)) NR;
    struct
    {
        uint8_t buf_0[7];
    }
    __attribute__((__packed__)) RN;
}
__attribute__((__packed__));
int state_size = sizeof(state_struct_t);

int get_initial( const cesmi_setup *setup, int handle, cesmi_node *out ){
    if ( handle != 1 ) return 0;
    *out = setup->make_node( setup, state_size );
    memset( out->memory, 0, state_size );
    state_struct_t &_out = *reinterpret_cast< state_struct_t * >( out->memory );
    _out.SN_size = 0;
    _out.NS_size = 0;
    _out.NR_size = 0;
    _out.RN_size = 0;
    _out.x = 0;
    _out.sqn = 1;
    _out.c = 0;
    _out.close = 1;
    _out.TXW_TRAIL = 1;
    _out.TXW_LEAD = 0;
    _out.RXW_LEAD = 0;
    _out.RXW_TRAIL = 1;
    _out._control.sender = 0;
    _out._control.clock = 0;
    _out.element.nloss = 0;
    _out.element.rs_len = 0;
    _out._control.element = 0;
    _out.receiver.outloss = 0;
    _out.receiver.outdata = 0;
    _out._control.receiver = 0;
    _out._control.SN = 6;
    _out._control.NS = 2;
    _out._control.NR = 6;
    _out._control.RN = 2;
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
        l3: if (  ( ((*in)._control.sender == 0) ) )
        {
            l4: if (  ( (((((*in).TXW_LEAD - ((*in).TXW_TRAIL + 1)) <= 4) && (((*in).TXW_LEAD < 6) && ((*in).x >= 9)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.sender = 0;
                ((*out).TXW_TRAIL) = (((*out).TXW_TRAIL + (((*out).TXW_LEAD + (1 - (*out).TXW_TRAIL)) == 4)));
                ((*out).TXW_LEAD) = (((*out).TXW_LEAD + 1));
                ((*out).c) = (((*out).c + 1));
                ((*out).x) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 5;
            }
            l5: if (  ( ((!((*in).close ) && ((*in).x >= 9))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.sender = 0;
                ((*out).x) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 6;
            }
            l6: if (  ( ((!(((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1)))) ) && (!(((*in).sqn <= (*in).TXW_LEAD) ) && (!(((*in).c >= 3) ) && (!(((((*in).TXW_LEAD - ((*in).TXW_TRAIL + 1)) <= 4) && (((*in).TXW_LEAD < 6) && ((*in).x >= 9))) ) && (((*in).TXW_TRAIL < ((*in).TXW_LEAD + 1)) && (((*in).TXW_LEAD == 6) && ((*in).x >= 9)))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.sender = 0;
                ((*out).TXW_TRAIL) = (((*out).TXW_TRAIL + 1));
                ((*out).x) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 7;
            }
            l7: if (  ( ((!(((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1)))) ) && (!(((*in).sqn <= (*in).TXW_LEAD) ) && (!(((*in).c >= 3) ) && !(((((*in).TXW_LEAD - ((*in).TXW_TRAIL + 1)) <= 4) && (((*in).TXW_LEAD < 6) && ((*in).x >= 9))) ))))) )  &&  ( ((*in)._control.NS == 2) )  &&  ( ((!(((*in).NS_size == 0) ) && ((*in).NS_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).packet) = ((*in).NS.buf_0[ 0 ]);
                (*out)._control.sender = 1;
                (*out)._control.NS = 1;
                ((*out).NS.buf_0[ 0 ]) = ((*out).NS.buf_0[ 1 ]);
                ((*out).NS.buf_0[ 1 ]) = ((*out).NS.buf_0[ 2 ]);
                ((*out).NS.buf_0[ 2 ]) = ((*out).NS.buf_0[ 3 ]);
                ((*out).NS.buf_0[ 3 ]) = ((*out).NS.buf_0[ 4 ]);
                ((*out).NS.buf_0[ 4 ]) = ((*out).NS.buf_0[ 5 ]);
                ((*out).NS.buf_0[ 5 ]) = ((*out).NS.buf_0[ 6 ]);
                ((*out).NS.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 8;
            }
        }
        l8: if (  ( ((*in)._control.sender == 1) ) )
        {
            l9: if (  ( ((((*in).packet > (*in).TXW_LEAD) || ((*in).packet < (*in).TXW_TRAIL))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 10;
            }
        }
        l10: if (  ( ((*in)._control.clock == 0) ) )
        {
            l11: if (  ( ((((*in).x < 9) && (!(((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1)))) ) && (!(((*in).sqn <= (*in).TXW_LEAD) ) && (!(((*in).c >= 3) ) && (!(((((*in).TXW_LEAD - ((*in).TXW_TRAIL + 1)) <= 4) && (((*in).TXW_LEAD < 6) && ((*in).x >= 9))) ) && ((((*in)._control.sender == 0)) && ((((*in)._control.element == 0)) && ((((*in)._control.receiver == 0)) && ((((*in).SN_size < 1) || ((*in).SN_time[ 0 ] > 0)) && ((((*in).SN_size < 2) || ((*in).SN_time[ 1 ] > 0)) && ((((*in).SN_size < 3) || ((*in).SN_time[ 2 ] > 0)) && ((((*in).SN_size < 4) || ((*in).SN_time[ 3 ] > 0)) && ((((*in).SN_size < 5) || ((*in).SN_time[ 4 ] > 0)) && ((((*in).SN_size < 6) || ((*in).SN_time[ 5 ] > 0)) && ((((*in).SN_size < 7) || ((*in).SN_time[ 6 ] > 0)) && ((((*in).NS_size < 1) || ((*in).NS_time[ 0 ] > 0)) && ((((*in).NS_size < 2) || ((*in).NS_time[ 1 ] > 0)) && ((((*in).NS_size < 3) || ((*in).NS_time[ 2 ] > 0)) && ((((*in).NS_size < 4) || ((*in).NS_time[ 3 ] > 0)) && ((((*in).NS_size < 5) || ((*in).NS_time[ 4 ] > 0)) && ((((*in).NS_size < 6) || ((*in).NS_time[ 5 ] > 0)) && ((((*in).NS_size < 7) || ((*in).NS_time[ 6 ] > 0)) && ((((*in).RN_size < 1) || ((*in).RN_time[ 0 ] > 0)) && ((((*in).RN_size < 2) || ((*in).RN_time[ 1 ] > 0)) && ((((*in).RN_size < 3) || ((*in).RN_time[ 2 ] > 0)) && ((((*in).RN_size < 4) || ((*in).RN_time[ 3 ] > 0)) && ((((*in).RN_size < 5) || ((*in).RN_time[ 4 ] > 0)) && ((((*in).RN_size < 6) || ((*in).RN_time[ 5 ] > 0)) && ((((*in).RN_size < 7) || ((*in).RN_time[ 6 ] > 0)) && ((((*in).NR_size < 1) || ((*in).NR_time[ 0 ] > 0)) && ((((*in).NR_size < 2) || ((*in).NR_time[ 1 ] > 0)) && ((((*in).NR_size < 3) || ((*in).NR_time[ 2 ] > 0)) && ((((*in).NR_size < 4) || ((*in).NR_time[ 3 ] > 0)) && ((((*in).NR_size < 5) || ((*in).NR_time[ 4 ] > 0)) && ((((*in).NR_size < 6) || ((*in).NR_time[ 5 ] > 0)) && ((((*in).NR_size < 7) || ((*in).NR_time[ 6 ] > 0)) && ((((*in)._control.SN == 6)) && ((((*in)._control.NS == 2)) && ((((*in)._control.RN == 2)) && (((*in)._control.NR == 6)))))))))))))))))))))))))))))))))))))))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.clock = 0;
                ((*out).SN_time[ 0 ]) = (((*out).SN_time[ 0 ] - ((*out).SN_size > 0)));
                ((*out).SN_time[ 1 ]) = (((*out).SN_time[ 1 ] - ((*out).SN_size > 1)));
                ((*out).SN_time[ 2 ]) = (((*out).SN_time[ 2 ] - ((*out).SN_size > 2)));
                ((*out).SN_time[ 3 ]) = (((*out).SN_time[ 3 ] - ((*out).SN_size > 3)));
                ((*out).SN_time[ 4 ]) = (((*out).SN_time[ 4 ] - ((*out).SN_size > 4)));
                ((*out).SN_time[ 5 ]) = (((*out).SN_time[ 5 ] - ((*out).SN_size > 5)));
                ((*out).SN_time[ 6 ]) = (((*out).SN_time[ 6 ] - ((*out).SN_size > 6)));
                ((*out).NS_time[ 0 ]) = (((*out).NS_time[ 0 ] - ((*out).NS_size > 0)));
                ((*out).NS_time[ 1 ]) = (((*out).NS_time[ 1 ] - ((*out).NS_size > 1)));
                ((*out).NS_time[ 2 ]) = (((*out).NS_time[ 2 ] - ((*out).NS_size > 2)));
                ((*out).NS_time[ 3 ]) = (((*out).NS_time[ 3 ] - ((*out).NS_size > 3)));
                ((*out).NS_time[ 4 ]) = (((*out).NS_time[ 4 ] - ((*out).NS_size > 4)));
                ((*out).NS_time[ 5 ]) = (((*out).NS_time[ 5 ] - ((*out).NS_size > 5)));
                ((*out).NS_time[ 6 ]) = (((*out).NS_time[ 6 ] - ((*out).NS_size > 6)));
                ((*out).NR_time[ 0 ]) = (((*out).NR_time[ 0 ] - ((*out).NR_size > 0)));
                ((*out).NR_time[ 1 ]) = (((*out).NR_time[ 1 ] - ((*out).NR_size > 1)));
                ((*out).NR_time[ 2 ]) = (((*out).NR_time[ 2 ] - ((*out).NR_size > 2)));
                ((*out).NR_time[ 3 ]) = (((*out).NR_time[ 3 ] - ((*out).NR_size > 3)));
                ((*out).NR_time[ 4 ]) = (((*out).NR_time[ 4 ] - ((*out).NR_size > 4)));
                ((*out).NR_time[ 5 ]) = (((*out).NR_time[ 5 ] - ((*out).NR_size > 5)));
                ((*out).NR_time[ 6 ]) = (((*out).NR_time[ 6 ] - ((*out).NR_size > 6)));
                ((*out).RN_time[ 0 ]) = (((*out).RN_time[ 0 ] - ((*out).RN_size > 0)));
                ((*out).RN_time[ 1 ]) = (((*out).RN_time[ 1 ] - ((*out).RN_size > 1)));
                ((*out).RN_time[ 2 ]) = (((*out).RN_time[ 2 ] - ((*out).RN_size > 2)));
                ((*out).RN_time[ 3 ]) = (((*out).RN_time[ 3 ] - ((*out).RN_size > 3)));
                ((*out).RN_time[ 4 ]) = (((*out).RN_time[ 4 ] - ((*out).RN_size > 4)));
                ((*out).RN_time[ 5 ]) = (((*out).RN_time[ 5 ] - ((*out).RN_size > 5)));
                ((*out).RN_time[ 6 ]) = (((*out).RN_time[ 6 ] - ((*out).RN_size > 6)));
                ((*out).x) = (((*out).x + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 12;
            }
        }
        l12: if (  ( ((*in)._control.element == 0) ) )
        {
            l13: if (  ( ((*in)._control.SN == 6) )  &&  ( ((!(((*in).SN_size == 0) ) && ((*in).SN_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.packet) = ((*in).SN.buf_0[ 0 ]);
                (*out)._control.element = 1;
                (*out)._control.SN = 1;
                ((*out).SN.buf_0[ 0 ]) = ((*out).SN.buf_0[ 1 ]);
                ((*out).SN.buf_0[ 1 ]) = ((*out).SN.buf_0[ 2 ]);
                ((*out).SN.buf_0[ 2 ]) = ((*out).SN.buf_0[ 3 ]);
                ((*out).SN.buf_0[ 3 ]) = ((*out).SN.buf_0[ 4 ]);
                ((*out).SN.buf_0[ 4 ]) = ((*out).SN.buf_0[ 5 ]);
                ((*out).SN.buf_0[ 5 ]) = ((*out).SN.buf_0[ 6 ]);
                ((*out).SN.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 14;
            }
            l14: if (  ( ((*in)._control.SN == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.packet) = ((*in).SN.buf_1[ 0 ]);
                (*out)._control.element = 1;
                (*out)._control.SN = 3;
                ((*out).SN.buf_1[ 0 ]) = ((*out).SN.buf_1[ 1 ]);
                ((*out).SN.buf_1[ 1 ]) = ((*out).SN.buf_1[ 2 ]);
                ((*out).SN.buf_1[ 2 ]) = ((*out).SN.buf_1[ 3 ]);
                ((*out).SN.buf_1[ 3 ]) = ((*out).SN.buf_1[ 4 ]);
                ((*out).SN.buf_1[ 4 ]) = ((*out).SN.buf_1[ 5 ]);
                ((*out).SN.buf_1[ 5 ]) = ((*out).SN.buf_1[ 6 ]);
                ((*out).SN.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 15;
            }
            l15: if (  ( ((*in)._control.SN == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.packet) = ((*in).SN.buf_2[ 0 ]);
                (*out)._control.element = 1;
                (*out)._control.SN = 5;
                ((*out).SN.buf_2[ 0 ]) = ((*out).SN.buf_2[ 1 ]);
                ((*out).SN.buf_2[ 1 ]) = ((*out).SN.buf_2[ 2 ]);
                ((*out).SN.buf_2[ 2 ]) = ((*out).SN.buf_2[ 3 ]);
                ((*out).SN.buf_2[ 3 ]) = ((*out).SN.buf_2[ 4 ]);
                ((*out).SN.buf_2[ 4 ]) = ((*out).SN.buf_2[ 5 ]);
                ((*out).SN.buf_2[ 5 ]) = ((*out).SN.buf_2[ 6 ]);
                ((*out).SN.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 16;
            }
            l16: if (  ( ((*in)._control.RN == 2) )  &&  ( ((!(((*in).RN_size == 0) ) && ((*in).RN_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.packet) = ((*in).RN.buf_0[ 0 ]);
                (*out)._control.element = 10;
                ((*out).element.i) = (0);
                (*out)._control.RN = 1;
                ((*out).RN.buf_0[ 0 ]) = ((*out).RN.buf_0[ 1 ]);
                ((*out).RN.buf_0[ 1 ]) = ((*out).RN.buf_0[ 2 ]);
                ((*out).RN.buf_0[ 2 ]) = ((*out).RN.buf_0[ 3 ]);
                ((*out).RN.buf_0[ 3 ]) = ((*out).RN.buf_0[ 4 ]);
                ((*out).RN.buf_0[ 4 ]) = ((*out).RN.buf_0[ 5 ]);
                ((*out).RN.buf_0[ 5 ]) = ((*out).RN.buf_0[ 6 ]);
                ((*out).RN.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 17;
            }
        }
        l17: if (  ( ((*in)._control.element == 1) ) )
        {
            l18: if (  ( ((*in)._control.SN == 6) )  &&  ( ((!(((*in).SN_size == 0) ) && ((*in).SN_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.seq) = ((*in).SN.buf_0[ 0 ]);
                (*out)._control.element = 2;
                (*out)._control.SN = 1;
                ((*out).SN.buf_0[ 0 ]) = ((*out).SN.buf_0[ 1 ]);
                ((*out).SN.buf_0[ 1 ]) = ((*out).SN.buf_0[ 2 ]);
                ((*out).SN.buf_0[ 2 ]) = ((*out).SN.buf_0[ 3 ]);
                ((*out).SN.buf_0[ 3 ]) = ((*out).SN.buf_0[ 4 ]);
                ((*out).SN.buf_0[ 4 ]) = ((*out).SN.buf_0[ 5 ]);
                ((*out).SN.buf_0[ 5 ]) = ((*out).SN.buf_0[ 6 ]);
                ((*out).SN.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 19;
            }
            l19: if (  ( ((*in)._control.SN == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.seq) = ((*in).SN.buf_1[ 0 ]);
                (*out)._control.element = 2;
                (*out)._control.SN = 3;
                ((*out).SN.buf_1[ 0 ]) = ((*out).SN.buf_1[ 1 ]);
                ((*out).SN.buf_1[ 1 ]) = ((*out).SN.buf_1[ 2 ]);
                ((*out).SN.buf_1[ 2 ]) = ((*out).SN.buf_1[ 3 ]);
                ((*out).SN.buf_1[ 3 ]) = ((*out).SN.buf_1[ 4 ]);
                ((*out).SN.buf_1[ 4 ]) = ((*out).SN.buf_1[ 5 ]);
                ((*out).SN.buf_1[ 5 ]) = ((*out).SN.buf_1[ 6 ]);
                ((*out).SN.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 20;
            }
            l20: if (  ( ((*in)._control.SN == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.seq) = ((*in).SN.buf_2[ 0 ]);
                (*out)._control.element = 2;
                (*out)._control.SN = 5;
                ((*out).SN.buf_2[ 0 ]) = ((*out).SN.buf_2[ 1 ]);
                ((*out).SN.buf_2[ 1 ]) = ((*out).SN.buf_2[ 2 ]);
                ((*out).SN.buf_2[ 2 ]) = ((*out).SN.buf_2[ 3 ]);
                ((*out).SN.buf_2[ 3 ]) = ((*out).SN.buf_2[ 4 ]);
                ((*out).SN.buf_2[ 4 ]) = ((*out).SN.buf_2[ 5 ]);
                ((*out).SN.buf_2[ 5 ]) = ((*out).SN.buf_2[ 6 ]);
                ((*out).SN.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 21;
            }
        }
        l21: if (  ( ((*in)._control.element == 2) ) )
        {
            l22: if (  ( ((*in)._control.SN == 6) )  &&  ( ((!(((*in).SN_size == 0) ) && ((*in).SN_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.trail) = ((*in).SN.buf_0[ 0 ]);
                (*out)._control.element = 3;
                (*out)._control.SN = 1;
                ((*out).SN.buf_0[ 0 ]) = ((*out).SN.buf_0[ 1 ]);
                ((*out).SN.buf_0[ 1 ]) = ((*out).SN.buf_0[ 2 ]);
                ((*out).SN.buf_0[ 2 ]) = ((*out).SN.buf_0[ 3 ]);
                ((*out).SN.buf_0[ 3 ]) = ((*out).SN.buf_0[ 4 ]);
                ((*out).SN.buf_0[ 4 ]) = ((*out).SN.buf_0[ 5 ]);
                ((*out).SN.buf_0[ 5 ]) = ((*out).SN.buf_0[ 6 ]);
                ((*out).SN.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 23;
            }
            l23: if (  ( ((*in)._control.SN == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.trail) = ((*in).SN.buf_1[ 0 ]);
                (*out)._control.element = 3;
                (*out)._control.SN = 3;
                ((*out).SN.buf_1[ 0 ]) = ((*out).SN.buf_1[ 1 ]);
                ((*out).SN.buf_1[ 1 ]) = ((*out).SN.buf_1[ 2 ]);
                ((*out).SN.buf_1[ 2 ]) = ((*out).SN.buf_1[ 3 ]);
                ((*out).SN.buf_1[ 3 ]) = ((*out).SN.buf_1[ 4 ]);
                ((*out).SN.buf_1[ 4 ]) = ((*out).SN.buf_1[ 5 ]);
                ((*out).SN.buf_1[ 5 ]) = ((*out).SN.buf_1[ 6 ]);
                ((*out).SN.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 24;
            }
            l24: if (  ( ((*in)._control.SN == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).element.trail) = ((*in).SN.buf_2[ 0 ]);
                (*out)._control.element = 3;
                (*out)._control.SN = 5;
                ((*out).SN.buf_2[ 0 ]) = ((*out).SN.buf_2[ 1 ]);
                ((*out).SN.buf_2[ 1 ]) = ((*out).SN.buf_2[ 2 ]);
                ((*out).SN.buf_2[ 2 ]) = ((*out).SN.buf_2[ 3 ]);
                ((*out).SN.buf_2[ 3 ]) = ((*out).SN.buf_2[ 4 ]);
                ((*out).SN.buf_2[ 4 ]) = ((*out).SN.buf_2[ 5 ]);
                ((*out).SN.buf_2[ 5 ]) = ((*out).SN.buf_2[ 6 ]);
                ((*out).SN.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 25;
            }
        }
        l25: if (  ( ((*in)._control.element == 3) ) )
        {
            l26: if (  ( (((*in).element.packet == 6)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 27;
            }
            l27: if (  ( (((*in).element.packet == 9)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 7;
                ((*out).element.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 28;
            }
            l28: if (  ( (((*in).element.packet == 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 11;
                ((*out).element.i) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 29;
            }
        }
        l29: if (  ( ((*in)._control.element == 10) ) )
        {
            l30: if (  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] != (*in).element.packet))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 10;
                ((*out).element.i) = (((*out).element.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 31;
            }
            l31: if (  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] == (*in).element.packet))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 32;
            }
        }
        l32: if (  ( ((*in)._control.element == 4) ) )
        {
            l33: if (  ( (((*in).element.nloss < 1)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 0;
                ((*out).element.nloss) = (((*out).element.nloss + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 34;
            }
        }
        l34: if (  ( ((*in)._control.element == 7) ) )
        {
            l35: if (  ( (((*in).element.i == (*in).element.rs_len)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 36;
            }
            l36: if (  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] != (*in).element.seq))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 7;
                ((*out).element.i) = (((*out).element.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 37;
            }
        }
        l37: if (  ( ((*in)._control.element == 11) ) )
        {
            l38: if (  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] >= (*in).element.trail))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 11;
                ((*out).element.i) = (((*out).element.i + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 39;
            }
            l39: if (  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] < (*in).element.trail))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.element = 11;
                ((*out).element.rs[ (*out).element.i ]) = ((*out).element.rs[ ((*out).element.rs_len - 1) ]);
                ((*out).element.rs_len) = (((*out).element.rs_len - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 40;
            }
        }
        l40: if (  ( ((*in)._control.receiver == 0) ) )
        {
            l41: if (  ( ((*in)._control.NR == 6) )  &&  ( ((!(((*in).NR_size == 0) ) && ((*in).NR_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.packet) = ((*in).NR.buf_0[ 0 ]);
                (*out)._control.receiver = 2;
                (*out)._control.NR = 1;
                ((*out).NR.buf_0[ 0 ]) = ((*out).NR.buf_0[ 1 ]);
                ((*out).NR.buf_0[ 1 ]) = ((*out).NR.buf_0[ 2 ]);
                ((*out).NR.buf_0[ 2 ]) = ((*out).NR.buf_0[ 3 ]);
                ((*out).NR.buf_0[ 3 ]) = ((*out).NR.buf_0[ 4 ]);
                ((*out).NR.buf_0[ 4 ]) = ((*out).NR.buf_0[ 5 ]);
                ((*out).NR.buf_0[ 5 ]) = ((*out).NR.buf_0[ 6 ]);
                ((*out).NR.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 42;
            }
            l42: if (  ( ((*in)._control.NR == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.packet) = ((*in).NR.buf_1[ 0 ]);
                (*out)._control.receiver = 2;
                (*out)._control.NR = 3;
                ((*out).NR.buf_1[ 0 ]) = ((*out).NR.buf_1[ 1 ]);
                ((*out).NR.buf_1[ 1 ]) = ((*out).NR.buf_1[ 2 ]);
                ((*out).NR.buf_1[ 2 ]) = ((*out).NR.buf_1[ 3 ]);
                ((*out).NR.buf_1[ 3 ]) = ((*out).NR.buf_1[ 4 ]);
                ((*out).NR.buf_1[ 4 ]) = ((*out).NR.buf_1[ 5 ]);
                ((*out).NR.buf_1[ 5 ]) = ((*out).NR.buf_1[ 6 ]);
                ((*out).NR.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 43;
            }
            l43: if (  ( ((*in)._control.NR == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.packet) = ((*in).NR.buf_2[ 0 ]);
                (*out)._control.receiver = 2;
                (*out)._control.NR = 5;
                ((*out).NR.buf_2[ 0 ]) = ((*out).NR.buf_2[ 1 ]);
                ((*out).NR.buf_2[ 1 ]) = ((*out).NR.buf_2[ 2 ]);
                ((*out).NR.buf_2[ 2 ]) = ((*out).NR.buf_2[ 3 ]);
                ((*out).NR.buf_2[ 3 ]) = ((*out).NR.buf_2[ 4 ]);
                ((*out).NR.buf_2[ 4 ]) = ((*out).NR.buf_2[ 5 ]);
                ((*out).NR.buf_2[ 5 ]) = ((*out).NR.buf_2[ 6 ]);
                ((*out).NR.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 44;
            }
            l44: if (  ( ((((*in).RXW_TRAIL <= (*in).RXW_LEAD) && (*in).receiver.RXW[ ((*in).RXW_TRAIL % 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 0;
                ((*out).receiver.RXW[ ((*out).RXW_TRAIL % 4) ]) = (0);
                ((*out).RXW_TRAIL) = (((*out).RXW_TRAIL + 1));
                ((*out).receiver.outdata) = (((*out).receiver.outdata + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 45;
            }
        }
        l45: if (  ( ((*in)._control.receiver == 2) ) )
        {
            l46: if (  ( ((*in)._control.NR == 6) )  &&  ( ((!(((*in).NR_size == 0) ) && ((*in).NR_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.sqn) = ((*in).NR.buf_0[ 0 ]);
                (*out)._control.receiver = 3;
                (*out)._control.NR = 1;
                ((*out).NR.buf_0[ 0 ]) = ((*out).NR.buf_0[ 1 ]);
                ((*out).NR.buf_0[ 1 ]) = ((*out).NR.buf_0[ 2 ]);
                ((*out).NR.buf_0[ 2 ]) = ((*out).NR.buf_0[ 3 ]);
                ((*out).NR.buf_0[ 3 ]) = ((*out).NR.buf_0[ 4 ]);
                ((*out).NR.buf_0[ 4 ]) = ((*out).NR.buf_0[ 5 ]);
                ((*out).NR.buf_0[ 5 ]) = ((*out).NR.buf_0[ 6 ]);
                ((*out).NR.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 47;
            }
            l47: if (  ( ((*in)._control.NR == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.sqn) = ((*in).NR.buf_1[ 0 ]);
                (*out)._control.receiver = 3;
                (*out)._control.NR = 3;
                ((*out).NR.buf_1[ 0 ]) = ((*out).NR.buf_1[ 1 ]);
                ((*out).NR.buf_1[ 1 ]) = ((*out).NR.buf_1[ 2 ]);
                ((*out).NR.buf_1[ 2 ]) = ((*out).NR.buf_1[ 3 ]);
                ((*out).NR.buf_1[ 3 ]) = ((*out).NR.buf_1[ 4 ]);
                ((*out).NR.buf_1[ 4 ]) = ((*out).NR.buf_1[ 5 ]);
                ((*out).NR.buf_1[ 5 ]) = ((*out).NR.buf_1[ 6 ]);
                ((*out).NR.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 48;
            }
            l48: if (  ( ((*in)._control.NR == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.sqn) = ((*in).NR.buf_2[ 0 ]);
                (*out)._control.receiver = 3;
                (*out)._control.NR = 5;
                ((*out).NR.buf_2[ 0 ]) = ((*out).NR.buf_2[ 1 ]);
                ((*out).NR.buf_2[ 1 ]) = ((*out).NR.buf_2[ 2 ]);
                ((*out).NR.buf_2[ 2 ]) = ((*out).NR.buf_2[ 3 ]);
                ((*out).NR.buf_2[ 3 ]) = ((*out).NR.buf_2[ 4 ]);
                ((*out).NR.buf_2[ 4 ]) = ((*out).NR.buf_2[ 5 ]);
                ((*out).NR.buf_2[ 5 ]) = ((*out).NR.buf_2[ 6 ]);
                ((*out).NR.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 49;
            }
        }
        l49: if (  ( ((*in)._control.receiver == 3) ) )
        {
            l50: if (  ( ((*in)._control.NR == 6) )  &&  ( ((!(((*in).NR_size == 0) ) && ((*in).NR_time[ 0 ] == 0))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.trail) = ((*in).NR.buf_0[ 0 ]);
                (*out)._control.receiver = 7;
                (*out)._control.NR = 1;
                ((*out).NR.buf_0[ 0 ]) = ((*out).NR.buf_0[ 1 ]);
                ((*out).NR.buf_0[ 1 ]) = ((*out).NR.buf_0[ 2 ]);
                ((*out).NR.buf_0[ 2 ]) = ((*out).NR.buf_0[ 3 ]);
                ((*out).NR.buf_0[ 3 ]) = ((*out).NR.buf_0[ 4 ]);
                ((*out).NR.buf_0[ 4 ]) = ((*out).NR.buf_0[ 5 ]);
                ((*out).NR.buf_0[ 5 ]) = ((*out).NR.buf_0[ 6 ]);
                ((*out).NR.buf_0[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 51;
            }
            l51: if (  ( ((*in)._control.NR == 1) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.trail) = ((*in).NR.buf_1[ 0 ]);
                (*out)._control.receiver = 7;
                (*out)._control.NR = 3;
                ((*out).NR.buf_1[ 0 ]) = ((*out).NR.buf_1[ 1 ]);
                ((*out).NR.buf_1[ 1 ]) = ((*out).NR.buf_1[ 2 ]);
                ((*out).NR.buf_1[ 2 ]) = ((*out).NR.buf_1[ 3 ]);
                ((*out).NR.buf_1[ 3 ]) = ((*out).NR.buf_1[ 4 ]);
                ((*out).NR.buf_1[ 4 ]) = ((*out).NR.buf_1[ 5 ]);
                ((*out).NR.buf_1[ 5 ]) = ((*out).NR.buf_1[ 6 ]);
                ((*out).NR.buf_1[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 52;
            }
            l52: if (  ( ((*in)._control.NR == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).receiver.trail) = ((*in).NR.buf_2[ 0 ]);
                (*out)._control.receiver = 7;
                (*out)._control.NR = 5;
                ((*out).NR.buf_2[ 0 ]) = ((*out).NR.buf_2[ 1 ]);
                ((*out).NR.buf_2[ 1 ]) = ((*out).NR.buf_2[ 2 ]);
                ((*out).NR.buf_2[ 2 ]) = ((*out).NR.buf_2[ 3 ]);
                ((*out).NR.buf_2[ 3 ]) = ((*out).NR.buf_2[ 4 ]);
                ((*out).NR.buf_2[ 4 ]) = ((*out).NR.buf_2[ 5 ]);
                ((*out).NR.buf_2[ 5 ]) = ((*out).NR.buf_2[ 6 ]);
                ((*out).NR.buf_2[ 6 ]) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 53;
            }
        }
        l53: if (  ( ((*in)._control.receiver == 5) ) )
        {
            l54: if (  ( ((((((*in).receiver.packet == 6) || ((*in).receiver.packet == 9)) && ((*in).receiver.sqn > ((*in).RXW_LEAD + 1))) || (((*in).receiver.packet == 3) && ((*in).receiver.sqn > (*in).RXW_LEAD)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 55;
            }
            l55: if (  ( ((((*in).receiver.packet == 3) && ((*in).receiver.sqn <= (*in).RXW_LEAD))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 56;
            }
            l56: if (  ( (((((*in).receiver.packet == 6) || ((*in).receiver.packet == 9)) && (((*in).RXW_TRAIL <= (*in).receiver.sqn) && ((*in).receiver.sqn <= (*in).RXW_LEAD)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 0;
                ((*out).receiver.RXW[ ((*out).receiver.sqn % 4) ]) = (1);
                system_in_deadlock = false;
                *to = blob_out;
                return 57;
            }
            l57: if (  ( (((*in).receiver.sqn < (*in).RXW_TRAIL)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 58;
            }
            l58: if (  ( (((((*in).receiver.packet == 6) || ((*in).receiver.packet == 9)) && ((*in).receiver.sqn == ((*in).RXW_LEAD + 1)))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 0;
                ((*out).receiver.RXW[ ((*out).receiver.sqn % 4) ]) = (1);
                ((*out).RXW_LEAD) = (((*out).RXW_LEAD + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 59;
            }
        }
        l59: if (  ( ((*in)._control.receiver == 8) ) )
        {
            l60: if (  ( ((((*in).RXW_TRAIL <= (*in).RXW_LEAD) && (*in).receiver.RXW[ ((*in).RXW_TRAIL % 4) ])) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 9;
                ((*out).receiver.outdata) = (((*out).receiver.outdata + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 61;
            }
            l61: if (  ( ((((*in).RXW_TRAIL <= (*in).RXW_LEAD) && !((*in).receiver.RXW[ ((*in).RXW_TRAIL % 4) ] ))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 9;
                ((*out).receiver.outloss) = (((*out).receiver.outloss + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 62;
            }
            l62: if (  ( (((*in).RXW_TRAIL > (*in).RXW_LEAD)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 9;
                ((*out).receiver.outloss) = (((*out).receiver.outloss + 1));
                ((*out).RXW_LEAD) = (((*out).RXW_LEAD + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 63;
            }
        }
        l63: if (  ( ((*in)._control.receiver == 9) ) )
        {
            l64: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 7;
                ((*out).receiver.RXW[ ((*out).RXW_TRAIL % 4) ]) = (0);
                ((*out).RXW_TRAIL) = (((*out).RXW_TRAIL + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 65;
            }
        }
        l65: if (  ( ((*in)._control.receiver == 7) ) )
        {
            l66: if (  ( (((*in).RXW_TRAIL < (*in).receiver.trail)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 67;
            }
            l67: if (  ( (((*in).RXW_TRAIL >= (*in).receiver.trail)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.receiver = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 68;
            }
        }
        l68: if (  ( ((*in)._control.SN == 6) ) )
        {
            l69: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 0) )  &&  ( (((*in).sqn <= (*in).TXW_LEAD)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = (6);
                (*out)._control.SN = 0;
                (*out)._control.sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 70;
            }
            l70: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).sqn);
                (*out)._control.SN = 0;
                (*out)._control.sender = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 71;
            }
            l71: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 0;
                (*out)._control.sender = 0;
                ((*out).sqn) = (((*out).sqn + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 72;
            }
            l72: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 0) )  &&  ( (((*in).c >= 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 0;
                (*out)._control.sender = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 73;
            }
            l73: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 0;
                (*out)._control.sender = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 74;
            }
            l74: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 0;
                (*out)._control.sender = 0;
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 75;
            }
            l75: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 0) )  &&  ( (((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 0;
                (*out)._control.sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 76;
            }
            l76: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 0;
                (*out)._control.sender = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 77;
            }
            l77: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 7) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 0;
                (*out)._control.sender = 0;
                ((*out).close) = (0);
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 78;
            }
            l78: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 1) )  &&  ( ((((*in).packet <= (*in).TXW_LEAD) && ((*in).packet >= (*in).TXW_TRAIL))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = (9);
                (*out)._control.SN = 0;
                (*out)._control.sender = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 79;
            }
            l79: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).packet);
                (*out)._control.SN = 0;
                (*out)._control.sender = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 80;
            }
            l80: if (  ( (!(((*in).SN_size == 7) )) )  &&  ( ((*in)._control.sender == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_0[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 0;
                (*out)._control.sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 81;
            }
        }
        l81: if (  ( ((*in)._control.SN == 0) ) )
        {
            l82: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).sqn <= (*in).TXW_LEAD)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = (6);
                (*out)._control.SN = 2;
                (*out)._control.sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 83;
            }
            l83: if (  ( ((*in)._control.sender == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).sqn);
                (*out)._control.SN = 2;
                (*out)._control.sender = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 84;
            }
            l84: if (  ( ((*in)._control.sender == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 2;
                (*out)._control.sender = 0;
                ((*out).sqn) = (((*out).sqn + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 85;
            }
            l85: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).c >= 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 2;
                (*out)._control.sender = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 86;
            }
            l86: if (  ( ((*in)._control.sender == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 2;
                (*out)._control.sender = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 87;
            }
            l87: if (  ( ((*in)._control.sender == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 2;
                (*out)._control.sender = 0;
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 88;
            }
            l88: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 2;
                (*out)._control.sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 89;
            }
            l89: if (  ( ((*in)._control.sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 2;
                (*out)._control.sender = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 90;
            }
            l90: if (  ( ((*in)._control.sender == 7) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 2;
                (*out)._control.sender = 0;
                ((*out).close) = (0);
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 91;
            }
            l91: if (  ( ((*in)._control.sender == 1) )  &&  ( ((((*in).packet <= (*in).TXW_LEAD) && ((*in).packet >= (*in).TXW_TRAIL))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = (9);
                (*out)._control.SN = 2;
                (*out)._control.sender = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 92;
            }
            l92: if (  ( ((*in)._control.sender == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).packet);
                (*out)._control.SN = 2;
                (*out)._control.sender = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 93;
            }
            l93: if (  ( ((*in)._control.sender == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_1[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 2;
                (*out)._control.sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 94;
            }
        }
        l94: if (  ( ((*in)._control.SN == 2) ) )
        {
            l95: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).sqn <= (*in).TXW_LEAD)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = (6);
                (*out)._control.SN = 4;
                (*out)._control.sender = 2;
                system_in_deadlock = false;
                *to = blob_out;
                return 96;
            }
            l96: if (  ( ((*in)._control.sender == 2) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).sqn);
                (*out)._control.SN = 4;
                (*out)._control.sender = 3;
                system_in_deadlock = false;
                *to = blob_out;
                return 97;
            }
            l97: if (  ( ((*in)._control.sender == 3) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 4;
                (*out)._control.sender = 0;
                ((*out).sqn) = (((*out).sqn + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 98;
            }
            l98: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).c >= 3)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 4;
                (*out)._control.sender = 4;
                system_in_deadlock = false;
                *to = blob_out;
                return 99;
            }
            l99: if (  ( ((*in)._control.sender == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 4;
                (*out)._control.sender = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 100;
            }
            l100: if (  ( ((*in)._control.sender == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 4;
                (*out)._control.sender = 0;
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 101;
            }
            l101: if (  ( ((*in)._control.sender == 0) )  &&  ( (((*in).close && (((*in).TXW_LEAD == 6) && ((*in).TXW_TRAIL == ((*in).TXW_LEAD + 1))))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = (3);
                (*out)._control.SN = 4;
                (*out)._control.sender = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 102;
            }
            l102: if (  ( ((*in)._control.sender == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_LEAD);
                (*out)._control.SN = 4;
                (*out)._control.sender = 7;
                system_in_deadlock = false;
                *to = blob_out;
                return 103;
            }
            l103: if (  ( ((*in)._control.sender == 7) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 4;
                (*out)._control.sender = 0;
                ((*out).close) = (0);
                ((*out).c) = (0);
                system_in_deadlock = false;
                *to = blob_out;
                return 104;
            }
            l104: if (  ( ((*in)._control.sender == 1) )  &&  ( ((((*in).packet <= (*in).TXW_LEAD) && ((*in).packet >= (*in).TXW_TRAIL))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = (9);
                (*out)._control.SN = 4;
                (*out)._control.sender = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 105;
            }
            l105: if (  ( ((*in)._control.sender == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).packet);
                (*out)._control.SN = 4;
                (*out)._control.sender = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 106;
            }
            l106: if (  ( ((*in)._control.sender == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).SN.buf_2[ (*out).SN_size ]) = ((*in).TXW_TRAIL);
                (*out)._control.SN = 4;
                (*out)._control.sender = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 107;
            }
        }
        l107: if (  ( ((*in)._control.SN == 4) ) )
        {
            l108: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.SN = 6;
                ((*out).SN_time[ (*out).SN_size ]) = (2);
                ((*out).SN_size) = (((*out).SN_size + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 109;
            }
        }
        l109: if (  ( ((*in)._control.SN == 5) ) )
        {
            l110: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.SN = 6;
                ((*out).SN_time[ 0 ]) = ((*out).SN_time[ 1 ]);
                ((*out).SN_time[ 1 ]) = ((*out).SN_time[ 2 ]);
                ((*out).SN_time[ 2 ]) = ((*out).SN_time[ 3 ]);
                ((*out).SN_time[ 3 ]) = ((*out).SN_time[ 4 ]);
                ((*out).SN_time[ 4 ]) = ((*out).SN_time[ 5 ]);
                ((*out).SN_time[ 5 ]) = ((*out).SN_time[ 6 ]);
                ((*out).SN_time[ 6 ]) = (0);
                ((*out).SN_size) = (((*out).SN_size - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 111;
            }
        }
        l111: if (  ( ((*in)._control.NS == 2) ) )
        {
            l112: if (  ( (!(((*in).NS_size == 7) )) )  &&  ( ((*in)._control.element == 10) )  &&  ( (((*in).element.i == (*in).element.rs_len)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NS.buf_0[ (*out).NS_size ]) = ((*in).element.packet);
                (*out)._control.NS = 0;
                (*out)._control.element = 0;
                ((*out).element.rs[ (*out).element.rs_len ]) = ((*out).element.packet);
                ((*out).element.rs_len) = (((*out).element.rs_len + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 113;
            }
        }
        l113: if (  ( ((*in)._control.NS == 0) ) )
        {
            l114: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.NS = 2;
                ((*out).NS_time[ (*out).NS_size ]) = (2);
                ((*out).NS_size) = (((*out).NS_size + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 115;
            }
        }
        l115: if (  ( ((*in)._control.NS == 1) ) )
        {
            l116: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.NS = 2;
                ((*out).NS_time[ 0 ]) = ((*out).NS_time[ 1 ]);
                ((*out).NS_time[ 1 ]) = ((*out).NS_time[ 2 ]);
                ((*out).NS_time[ 2 ]) = ((*out).NS_time[ 3 ]);
                ((*out).NS_time[ 3 ]) = ((*out).NS_time[ 4 ]);
                ((*out).NS_time[ 4 ]) = ((*out).NS_time[ 5 ]);
                ((*out).NS_time[ 5 ]) = ((*out).NS_time[ 6 ]);
                ((*out).NS_time[ 6 ]) = (0);
                ((*out).NS_size) = (((*out).NS_size - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 117;
            }
        }
        l117: if (  ( ((*in)._control.NR == 6) ) )
        {
            l118: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 0;
                (*out)._control.element = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 119;
            }
            l119: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 0;
                (*out)._control.element = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 120;
            }
            l120: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 0;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 121;
            }
            l121: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 7) )  &&  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] == (*in).element.seq))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = (9);
                (*out)._control.NR = 0;
                (*out)._control.element = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 122;
            }
            l122: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 0;
                (*out)._control.element = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 123;
            }
            l123: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 0;
                (*out)._control.element = 0;
                ((*out).element.rs[ (*out).element.i ]) = ((*out).element.rs[ ((*out).element.rs_len - 1) ]);
                ((*out).element.rs_len) = (((*out).element.rs_len - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 124;
            }
            l124: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 11) )  &&  ( (((*in).element.i == (*in).element.rs_len)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 0;
                (*out)._control.element = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 125;
            }
            l125: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 12) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 0;
                (*out)._control.element = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 126;
            }
            l126: if (  ( (!(((*in).NR_size == 7) )) )  &&  ( ((*in)._control.element == 13) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_0[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 0;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 127;
            }
        }
        l127: if (  ( ((*in)._control.NR == 0) ) )
        {
            l128: if (  ( ((*in)._control.element == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 2;
                (*out)._control.element = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 129;
            }
            l129: if (  ( ((*in)._control.element == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 2;
                (*out)._control.element = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 130;
            }
            l130: if (  ( ((*in)._control.element == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 2;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 131;
            }
            l131: if (  ( ((*in)._control.element == 7) )  &&  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] == (*in).element.seq))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = (9);
                (*out)._control.NR = 2;
                (*out)._control.element = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 132;
            }
            l132: if (  ( ((*in)._control.element == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 2;
                (*out)._control.element = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 133;
            }
            l133: if (  ( ((*in)._control.element == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 2;
                (*out)._control.element = 0;
                ((*out).element.rs[ (*out).element.i ]) = ((*out).element.rs[ ((*out).element.rs_len - 1) ]);
                ((*out).element.rs_len) = (((*out).element.rs_len - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 134;
            }
            l134: if (  ( ((*in)._control.element == 11) )  &&  ( (((*in).element.i == (*in).element.rs_len)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 2;
                (*out)._control.element = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 135;
            }
            l135: if (  ( ((*in)._control.element == 12) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 2;
                (*out)._control.element = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 136;
            }
            l136: if (  ( ((*in)._control.element == 13) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_1[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 2;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 137;
            }
        }
        l137: if (  ( ((*in)._control.NR == 2) ) )
        {
            l138: if (  ( ((*in)._control.element == 4) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 4;
                (*out)._control.element = 5;
                system_in_deadlock = false;
                *to = blob_out;
                return 139;
            }
            l139: if (  ( ((*in)._control.element == 5) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 4;
                (*out)._control.element = 6;
                system_in_deadlock = false;
                *to = blob_out;
                return 140;
            }
            l140: if (  ( ((*in)._control.element == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 4;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 141;
            }
            l141: if (  ( ((*in)._control.element == 7) )  &&  ( ((((*in).element.i < (*in).element.rs_len) && ((*in).element.rs[ (*in).element.i ] == (*in).element.seq))) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = (9);
                (*out)._control.NR = 4;
                (*out)._control.element = 8;
                system_in_deadlock = false;
                *to = blob_out;
                return 142;
            }
            l142: if (  ( ((*in)._control.element == 8) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 4;
                (*out)._control.element = 9;
                system_in_deadlock = false;
                *to = blob_out;
                return 143;
            }
            l143: if (  ( ((*in)._control.element == 9) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 4;
                (*out)._control.element = 0;
                ((*out).element.rs[ (*out).element.i ]) = ((*out).element.rs[ ((*out).element.rs_len - 1) ]);
                ((*out).element.rs_len) = (((*out).element.rs_len - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 144;
            }
            l144: if (  ( ((*in)._control.element == 11) )  &&  ( (((*in).element.i == (*in).element.rs_len)) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.packet);
                (*out)._control.NR = 4;
                (*out)._control.element = 12;
                system_in_deadlock = false;
                *to = blob_out;
                return 145;
            }
            l145: if (  ( ((*in)._control.element == 12) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.seq);
                (*out)._control.NR = 4;
                (*out)._control.element = 13;
                system_in_deadlock = false;
                *to = blob_out;
                return 146;
            }
            l146: if (  ( ((*in)._control.element == 13) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).NR.buf_2[ (*out).NR_size ]) = ((*in).element.trail);
                (*out)._control.NR = 4;
                (*out)._control.element = 0;
                system_in_deadlock = false;
                *to = blob_out;
                return 147;
            }
        }
        l147: if (  ( ((*in)._control.NR == 4) ) )
        {
            l148: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.NR = 6;
                ((*out).NR_time[ (*out).NR_size ]) = (2);
                ((*out).NR_size) = (((*out).NR_size + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 149;
            }
        }
        l149: if (  ( ((*in)._control.NR == 5) ) )
        {
            l150: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.NR = 6;
                ((*out).NR_time[ 0 ]) = ((*out).NR_time[ 1 ]);
                ((*out).NR_time[ 1 ]) = ((*out).NR_time[ 2 ]);
                ((*out).NR_time[ 2 ]) = ((*out).NR_time[ 3 ]);
                ((*out).NR_time[ 3 ]) = ((*out).NR_time[ 4 ]);
                ((*out).NR_time[ 4 ]) = ((*out).NR_time[ 5 ]);
                ((*out).NR_time[ 5 ]) = ((*out).NR_time[ 6 ]);
                ((*out).NR_time[ 6 ]) = (0);
                ((*out).NR_size) = (((*out).NR_size - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 151;
            }
        }
        l151: if (  ( ((*in)._control.RN == 2) ) )
        {
            l152: if (  ( (!(((*in).RN_size == 7) )) )  &&  ( ((*in)._control.receiver == 6) ) )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                ((*out).RN.buf_0[ (*out).RN_size ]) = (((*in).RXW_LEAD + 1));
                (*out)._control.RN = 0;
                (*out)._control.receiver = 5;
                ((*out).receiver.RXW[ (((*out).RXW_LEAD + 1) % 4) ]) = (0);
                ((*out).RXW_LEAD) = (((*out).RXW_LEAD + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 153;
            }
        }
        l153: if (  ( ((*in)._control.RN == 0) ) )
        {
            l154: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.RN = 2;
                ((*out).RN_time[ (*out).RN_size ]) = (2);
                ((*out).RN_size) = (((*out).RN_size + 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 155;
            }
        }
        l155: if (  ( ((*in)._control.RN == 1) ) )
        {
            l156: if ( true )
            {
                cesmi_node blob_out = setup->make_node( setup, state_size );
                state_struct_t *out = reinterpret_cast< state_struct_t * >( blob_out.memory );
                *out = *in;
                (*out)._control.RN = 2;
                ((*out).RN_time[ 0 ]) = ((*out).RN_time[ 1 ]);
                ((*out).RN_time[ 1 ]) = ((*out).RN_time[ 2 ]);
                ((*out).RN_time[ 2 ]) = ((*out).RN_time[ 3 ]);
                ((*out).RN_time[ 3 ]) = ((*out).RN_time[ 4 ]);
                ((*out).RN_time[ 4 ]) = ((*out).RN_time[ 5 ]);
                ((*out).RN_time[ 5 ]) = ((*out).RN_time[ 6 ]);
                ((*out).RN_time[ 6 ]) = (0);
                ((*out).RN_size) = (((*out).RN_size - 1));
                system_in_deadlock = false;
                *to = blob_out;
                return 157;
            }
        }
    }
    l157: if (  ( system_in_deadlock ) )
    {
    }
    l158: return 0;
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
