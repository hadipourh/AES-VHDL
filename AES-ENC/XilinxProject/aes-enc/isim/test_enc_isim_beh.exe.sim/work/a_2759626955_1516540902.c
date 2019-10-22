/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-ENC/add_round_key.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_1697423399_503743352(char *, char *, char *, char *, char *, char *);


static void work_a_2759626955_1516540902_p_0(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(15, ng0);

LAB3:    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t2 = (t0 + 4848U);
    t4 = (t0 + 1192U);
    t5 = *((char **)t4);
    t4 = (t0 + 4864U);
    t6 = ieee_p_2592010699_sub_1697423399_503743352(IEEE_P_2592010699, t1, t3, t2, t5, t4);
    t7 = (t1 + 12U);
    t8 = *((unsigned int *)t7);
    t9 = (1U * t8);
    t10 = (128U != t9);
    if (t10 == 1)
        goto LAB5;

LAB6:    t11 = (t0 + 2912);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 128U);
    xsi_driver_first_trans_fast_port(t11);

LAB2:    t16 = (t0 + 2832);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(128U, t9, 0);
    goto LAB6;

}


extern void work_a_2759626955_1516540902_init()
{
	static char *pe[] = {(void *)work_a_2759626955_1516540902_p_0};
	xsi_register_didat("work_a_2759626955_1516540902", "isim/test_enc_isim_beh.exe.sim/work/a_2759626955_1516540902.didat");
	xsi_register_executes(pe);
}
