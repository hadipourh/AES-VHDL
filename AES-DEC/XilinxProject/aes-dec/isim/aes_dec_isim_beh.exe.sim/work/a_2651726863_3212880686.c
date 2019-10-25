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
static const char *ng0 = "C:/Users/Hosein/Documents/MyUniverse/Mathematics/E-Books/Cryptography/Alim/AES-VHDL/AES-DEC/RTL/gfmult_by2.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_1697423399_503743352(char *, char *, char *, char *, char *, char *);


static void work_a_2651726863_3212880686_p_0(char *t0)
{
    char t9[16];
    char t11[16];
    char t16[16];
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t8;
    char *t10;
    char *t12;
    char *t13;
    int t14;
    unsigned int t15;
    char *t17;
    int t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:    xsi_set_current_line(31, ng0);

LAB3:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = (7 - 6);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 6148);
    t10 = ((IEEE_P_2592010699) + 4024);
    t12 = (t11 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 6;
    t13 = (t12 + 4U);
    *((int *)t13) = 0;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t14 = (0 - 6);
    t15 = (t14 * -1);
    t15 = (t15 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t15;
    t13 = (t16 + 0U);
    t17 = (t13 + 0U);
    *((int *)t17) = 0;
    t17 = (t13 + 4U);
    *((int *)t17) = 0;
    t17 = (t13 + 8U);
    *((int *)t17) = 1;
    t18 = (0 - 0);
    t15 = (t18 * 1);
    t15 = (t15 + 1);
    t17 = (t13 + 12U);
    *((unsigned int *)t17) = t15;
    t8 = xsi_base_array_concat(t8, t9, t10, (char)97, t1, t11, (char)97, t6, t16, (char)101);
    t15 = (7U + 1U);
    t19 = (8U != t15);
    if (t19 == 1)
        goto LAB5;

LAB6:    t17 = (t0 + 3600);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t8, 8U);
    xsi_driver_first_trans_fast(t17);

LAB2:    t24 = (t0 + 3488);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t15, 0);
    goto LAB6;

}

static void work_a_2651726863_3212880686_p_1(char *t0)
{
    char t11[16];
    char t13[16];
    char t24[16];
    char t29[16];
    char t31[16];
    char t42[16];
    char t52[16];
    char *t1;
    char *t3;
    char *t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t12;
    char *t14;
    char *t15;
    int t16;
    unsigned int t17;
    char *t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    char *t23;
    char *t25;
    char *t26;
    char *t28;
    char *t30;
    char *t32;
    char *t33;
    int t34;
    unsigned int t35;
    char *t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned char t40;
    char *t41;
    char *t43;
    char *t44;
    char *t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned char t50;
    char *t51;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned char t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;

LAB0:    xsi_set_current_line(32, ng0);

LAB3:    t1 = (t0 + 6149);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = (7 - 7);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t12 = ((IEEE_P_2592010699) + 4024);
    t14 = (t13 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 0;
    t15 = (t14 + 4U);
    *((int *)t15) = 2;
    t15 = (t14 + 8U);
    *((int *)t15) = 1;
    t16 = (2 - 0);
    t17 = (t16 * 1);
    t17 = (t17 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t17;
    t10 = xsi_base_array_concat(t10, t11, t12, (char)97, t1, t13, (char)99, t9, (char)101);
    t15 = (t0 + 1032U);
    t18 = *((char **)t15);
    t19 = (7 - 7);
    t17 = (t19 * -1);
    t20 = (1U * t17);
    t21 = (0 + t20);
    t15 = (t18 + t21);
    t22 = *((unsigned char *)t15);
    t25 = ((IEEE_P_2592010699) + 4024);
    t23 = xsi_base_array_concat(t23, t24, t25, (char)97, t10, t11, (char)99, t22, (char)101);
    t26 = (t0 + 6152);
    t30 = ((IEEE_P_2592010699) + 4024);
    t32 = (t31 + 0U);
    t33 = (t32 + 0U);
    *((int *)t33) = 0;
    t33 = (t32 + 4U);
    *((int *)t33) = 0;
    t33 = (t32 + 8U);
    *((int *)t33) = 1;
    t34 = (0 - 0);
    t35 = (t34 * 1);
    t35 = (t35 + 1);
    t33 = (t32 + 12U);
    *((unsigned int *)t33) = t35;
    t28 = xsi_base_array_concat(t28, t29, t30, (char)97, t23, t24, (char)97, t26, t31, (char)101);
    t33 = (t0 + 1032U);
    t36 = *((char **)t33);
    t37 = (7 - 7);
    t35 = (t37 * -1);
    t38 = (1U * t35);
    t39 = (0 + t38);
    t33 = (t36 + t39);
    t40 = *((unsigned char *)t33);
    t43 = ((IEEE_P_2592010699) + 4024);
    t41 = xsi_base_array_concat(t41, t42, t43, (char)97, t28, t29, (char)99, t40, (char)101);
    t44 = (t0 + 1032U);
    t45 = *((char **)t44);
    t46 = (7 - 7);
    t47 = (t46 * -1);
    t48 = (1U * t47);
    t49 = (0 + t48);
    t44 = (t45 + t49);
    t50 = *((unsigned char *)t44);
    t53 = ((IEEE_P_2592010699) + 4024);
    t51 = xsi_base_array_concat(t51, t52, t53, (char)97, t41, t42, (char)99, t50, (char)101);
    t54 = (3U + 1U);
    t55 = (t54 + 1U);
    t56 = (t55 + 1U);
    t57 = (t56 + 1U);
    t58 = (t57 + 1U);
    t59 = (8U != t58);
    if (t59 == 1)
        goto LAB5;

LAB6:    t60 = (t0 + 3664);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    t63 = (t62 + 56U);
    t64 = *((char **)t63);
    memcpy(t64, t51, 8U);
    xsi_driver_first_trans_fast(t60);

LAB2:    t65 = (t0 + 3504);
    *((int *)t65) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t58, 0);
    goto LAB6;

}

static void work_a_2651726863_3212880686_p_2(char *t0)
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

LAB0:    xsi_set_current_line(33, ng0);

LAB3:    t2 = (t0 + 1352U);
    t3 = *((char **)t2);
    t2 = (t0 + 6084U);
    t4 = (t0 + 1512U);
    t5 = *((char **)t4);
    t4 = (t0 + 6100U);
    t6 = ieee_p_2592010699_sub_1697423399_503743352(IEEE_P_2592010699, t1, t3, t2, t5, t4);
    t7 = (t1 + 12U);
    t8 = *((unsigned int *)t7);
    t9 = (1U * t8);
    t10 = (8U != t9);
    if (t10 == 1)
        goto LAB5;

LAB6:    t11 = (t0 + 3728);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 8U);
    xsi_driver_first_trans_fast_port(t11);

LAB2:    t16 = (t0 + 3520);
    *((int *)t16) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(8U, t9, 0);
    goto LAB6;

}


extern void work_a_2651726863_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2651726863_3212880686_p_0,(void *)work_a_2651726863_3212880686_p_1,(void *)work_a_2651726863_3212880686_p_2};
	xsi_register_didat("work_a_2651726863_3212880686", "isim/aes_dec_isim_beh.exe.sim/work/a_2651726863_3212880686.didat");
	xsi_register_executes(pe);
}
