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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *STD_STANDARD;
char *IEEE_P_2592010699;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    work_a_2637877683_3212880686_init();
    work_a_2759626955_1516540902_init();
    work_a_3351589255_3212880686_init();
    work_a_1015002545_3212880686_init();
    work_a_3766061276_1516540902_init();
    work_a_2651726863_3212880686_init();
    work_a_2306158668_3212880686_init();
    work_a_2901959303_1516540902_init();
    work_a_4189251213_1516540902_init();
    work_a_1208337864_3212880686_init();
    work_a_1437420904_3212880686_init();
    work_a_3643414621_3212880686_init();
    work_a_2543183094_3212880686_init();
    work_a_1361231369_2372691052_init();


    xsi_register_tops("work_a_1361231369_2372691052");

    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);

    return xsi_run_simulation(argc, argv);

}
