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
static const char *ng0 = "C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-DEC/Testbench/dec_tb.vhd";



static void work_a_3004435957_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 3776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 2920);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3776);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 2920);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3004435957_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int64 t9;
    int64 t10;
    unsigned char t11;
    unsigned char t12;
    unsigned int t13;

LAB0:    t1 = (t0 + 3360U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 7312);
    t4 = (t0 + 3840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 128U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 7440);
    t4 = (t0 + 3904);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 128U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 3968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t10 = (t9 * 1);
    t2 = (t0 + 3168);
    xsi_process_wait(t2, t10);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 3968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(64, ng0);

LAB10:    t2 = (t0 + 3680);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    t3 = (t0 + 3680);
    *((int *)t3) = 0;
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t10 = (t9 / 2);
    t2 = (t0 + 3168);
    xsi_process_wait(t2, t10);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 1)
        goto LAB8;
    else
        goto LAB10;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t2 = (t0 + 7568);
    t11 = 1;
    if (128U == 128U)
        goto LAB19;

LAB20:    t11 = 0;

LAB21:    if (t11 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 7724);
    xsi_report(t2, 28U, 0);

LAB17:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 7752);
    xsi_report(t2, 34U, 0);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 7786);
    xsi_report(t2, 32U, 0);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 7818);
    t4 = (t0 + 3840);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 128U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 7946);
    t4 = (t0 + 3904);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 128U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t10 = (t9 * 1);
    t2 = (t0 + 3168);
    xsi_process_wait(t2, t10);

LAB27:    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(67, ng0);
    t7 = (t0 + 7696);
    xsi_report(t7, 28U, 0);
    goto LAB17;

LAB19:    t13 = 0;

LAB22:    if (t13 < 128U)
        goto LAB23;
    else
        goto LAB21;

LAB23:    t5 = (t3 + t13);
    t6 = (t2 + t13);
    if (*((unsigned char *)t5) != *((unsigned char *)t6))
        goto LAB20;

LAB24:    t13 = (t13 + 1);
    goto LAB22;

LAB25:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3968);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(84, ng0);

LAB31:    t2 = (t0 + 3696);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB32;
    goto LAB1;

LAB26:    goto LAB25;

LAB28:    goto LAB26;

LAB29:    t3 = (t0 + 3696);
    *((int *)t3) = 0;
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t9 = *((int64 *)t3);
    t10 = (t9 / 2);
    t2 = (t0 + 3168);
    xsi_process_wait(t2, t10);

LAB35:    *((char **)t1) = &&LAB36;
    goto LAB1;

LAB30:    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 1)
        goto LAB29;
    else
        goto LAB31;

LAB32:    goto LAB30;

LAB33:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t2 = (t0 + 8074);
    t11 = 1;
    if (128U == 128U)
        goto LAB40;

LAB41:    t11 = 0;

LAB42:    if (t11 != 0)
        goto LAB37;

LAB39:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 8230);
    xsi_report(t2, 28U, 0);

LAB38:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 8258);
    xsi_report(t2, 34U, 0);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 8292);
    xsi_report(t2, 32U, 0);
    xsi_set_current_line(93, ng0);

LAB48:    *((char **)t1) = &&LAB49;
    goto LAB1;

LAB34:    goto LAB33;

LAB36:    goto LAB34;

LAB37:    xsi_set_current_line(87, ng0);
    t7 = (t0 + 8202);
    xsi_report(t7, 28U, 0);
    goto LAB38;

LAB40:    t13 = 0;

LAB43:    if (t13 < 128U)
        goto LAB44;
    else
        goto LAB42;

LAB44:    t5 = (t3 + t13);
    t6 = (t2 + t13);
    if (*((unsigned char *)t5) != *((unsigned char *)t6))
        goto LAB41;

LAB45:    t13 = (t13 + 1);
    goto LAB43;

LAB46:    goto LAB2;

LAB47:    goto LAB46;

LAB49:    goto LAB47;

}


extern void work_a_3004435957_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3004435957_2372691052_p_0,(void *)work_a_3004435957_2372691052_p_1};
	xsi_register_didat("work_a_3004435957_2372691052", "isim/test_dec_isim_beh.exe.sim/work/a_3004435957_2372691052.didat");
	xsi_register_executes(pe);
}
