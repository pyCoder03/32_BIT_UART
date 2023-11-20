/*
 * Generated by Bluespec Compiler, version 2021.12.1 (build fd501401)
 * 
 * On Fri Oct 27 19:55:38 IST 2023
 * 
 */
#include "bluesim_primitives.h"
#include "mkUART.h"


/* Constructor */
MOD_mkUART::MOD_mkUART(tSimStateHdl simHdl, char const *name, Module *parent)
  : Module(simHdl, name, parent),
    __clk_handle_0(BAD_CLOCK_HANDLE),
    INST_bit_cnt(simHdl, "bit_cnt", this, 4u, (tUInt8)0u, (tUInt8)0u),
    INST_parity(simHdl, "parity", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_sbuf(simHdl, "sbuf", this, 8u, (tUInt8)255u, (tUInt8)0u),
    INST_tx(simHdl, "tx", this, 1u, (tUInt8)0u, (tUInt8)0u),
    INST_tx_line(simHdl, "tx_line", this, 1u, (tUInt8)1u, (tUInt8)0u),
    PORT_RST_N((tUInt8)1u)
{
  symbol_count = 6u;
  symbols = new tSym[symbol_count];
  init_symbols_0();
}


/* Symbol init fns */

void MOD_mkUART::init_symbols_0()
{
  init_symbol(&symbols[0u], "bit_cnt", SYM_MODULE, &INST_bit_cnt);
  init_symbol(&symbols[1u], "parity", SYM_MODULE, &INST_parity);
  init_symbol(&symbols[2u], "RL_shift_out", SYM_RULE);
  init_symbol(&symbols[3u], "sbuf", SYM_MODULE, &INST_sbuf);
  init_symbol(&symbols[4u], "tx", SYM_MODULE, &INST_tx);
  init_symbol(&symbols[5u], "tx_line", SYM_MODULE, &INST_tx_line);
}


/* Rule actions */

void MOD_mkUART::RL_shift_out()
{
  tUInt8 DEF_NOT_bit_cnt_EQ_8_2_AND_NOT_bit_cnt_EQ_9___d13;
  tUInt8 DEF_x__h320;
  tUInt8 DEF_bit_cnt_EQ_8___d6;
  tUInt8 DEF_IF_bit_cnt_EQ_8_THEN_parity_ELSE_bit_cnt_EQ_9__ETC___d11;
  tUInt8 DEF_x__h423;
  tUInt8 DEF_x__h341;
  tUInt8 DEF_x__h267;
  tUInt8 DEF_x__h270;
  tUInt8 DEF_sbuf__h447;
  tUInt8 DEF_bit_cnt_EQ_9___d3;
  tUInt8 DEF__dfoo1;
  tUInt8 DEF_x__h234;
  tUInt8 DEF_NOT_bit_cnt_EQ_9___d4;
  tUInt8 DEF__dfoo2;
  DEF_sbuf__h447 = INST_sbuf.METH_read();
  DEF_x__h270 = INST_bit_cnt.METH_read();
  DEF_x__h234 = (tUInt8)15u & (DEF_x__h270 + (tUInt8)1u);
  DEF_bit_cnt_EQ_9___d3 = DEF_x__h270 == (tUInt8)9u;
  DEF_NOT_bit_cnt_EQ_9___d4 = !DEF_bit_cnt_EQ_9___d3;
  DEF__dfoo2 = DEF_NOT_bit_cnt_EQ_9___d4 ? DEF_x__h234 : (tUInt8)0u;
  DEF__dfoo1 = DEF_NOT_bit_cnt_EQ_9___d4 || DEF_bit_cnt_EQ_9___d3;
  DEF_x__h267 = INST_parity.METH_read();
  DEF_x__h341 = (tUInt8)(DEF_sbuf__h447 >> 1u);
  DEF_x__h423 = (tUInt8)((tUInt8)1u & DEF_sbuf__h447);
  DEF_bit_cnt_EQ_8___d6 = DEF_x__h270 == (tUInt8)8u;
  DEF_IF_bit_cnt_EQ_8_THEN_parity_ELSE_bit_cnt_EQ_9__ETC___d11 = DEF_bit_cnt_EQ_8___d6 ? DEF_x__h267 : DEF_bit_cnt_EQ_9___d3 || DEF_x__h423;
  DEF_x__h320 = (tUInt8)255u & DEF_x__h341;
  DEF_NOT_bit_cnt_EQ_8_2_AND_NOT_bit_cnt_EQ_9___d13 = !DEF_bit_cnt_EQ_8___d6 && DEF_NOT_bit_cnt_EQ_9___d4;
  if (DEF__dfoo1)
    INST_bit_cnt.METH_write(DEF__dfoo2);
  INST_tx_line.METH_write(DEF_IF_bit_cnt_EQ_8_THEN_parity_ELSE_bit_cnt_EQ_9__ETC___d11);
  if (DEF_bit_cnt_EQ_9___d3)
    INST_tx.METH_write((tUInt8)0u);
  if (DEF_NOT_bit_cnt_EQ_8_2_AND_NOT_bit_cnt_EQ_9___d13)
    INST_sbuf.METH_write(DEF_x__h320);
}


/* Methods */

void MOD_mkUART::METH_par_in(tUInt8 ARG_par_in_par_input)
{
  tUInt8 DEF_x__h569;
  tUInt8 DEF_x__h567;
  tUInt8 DEF_x__h565;
  tUInt8 DEF_x__h563;
  tUInt8 DEF_x__h561;
  tUInt8 DEF_x__h559;
  tUInt8 DEF_x__h530;
  tUInt8 DEF_y__h560;
  tUInt8 DEF_y__h562;
  tUInt8 DEF_y__h564;
  tUInt8 DEF_y__h566;
  tUInt8 DEF_y__h568;
  tUInt8 DEF_y__h570;
  tUInt8 DEF_y__h572;
  tUInt8 DEF_x__h571;
  DEF_tx___d1 = INST_tx.METH_read();
  DEF_NOT_tx___d16 = !DEF_tx___d1;
  DEF_x__h571 = (tUInt8)(ARG_par_in_par_input >> 7u);
  DEF_y__h572 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 6u));
  DEF_y__h570 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 5u));
  DEF_y__h568 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 4u));
  DEF_y__h566 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 3u));
  DEF_y__h564 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 2u));
  DEF_y__h562 = (tUInt8)((tUInt8)1u & (ARG_par_in_par_input >> 1u));
  DEF_y__h560 = (tUInt8)((tUInt8)1u & ARG_par_in_par_input);
  DEF_x__h569 = DEF_x__h571 ^ DEF_y__h572;
  DEF_x__h567 = DEF_x__h569 ^ DEF_y__h570;
  DEF_x__h565 = DEF_x__h567 ^ DEF_y__h568;
  DEF_x__h563 = DEF_x__h565 ^ DEF_y__h566;
  DEF_x__h561 = DEF_x__h563 ^ DEF_y__h564;
  DEF_x__h559 = DEF_x__h561 ^ DEF_y__h562;
  DEF_x__h530 = DEF_x__h559 ^ DEF_y__h560;
  if (DEF_NOT_tx___d16)
    INST_sbuf.METH_write(ARG_par_in_par_input);
  if (DEF_NOT_tx___d16)
    INST_parity.METH_write(DEF_x__h530);
}

tUInt8 MOD_mkUART::METH_RDY_par_in()
{
  tUInt8 DEF_CAN_FIRE_par_in;
  tUInt8 PORT_RDY_par_in;
  DEF_tx___d1 = INST_tx.METH_read();
  DEF_NOT_tx___d16 = !DEF_tx___d1;
  DEF_CAN_FIRE_par_in = DEF_NOT_tx___d16;
  PORT_RDY_par_in = DEF_CAN_FIRE_par_in;
  return PORT_RDY_par_in;
}

void MOD_mkUART::METH_start_tx()
{
  DEF_tx___d1 = INST_tx.METH_read();
  DEF_NOT_tx___d16 = !DEF_tx___d1;
  if (DEF_NOT_tx___d16)
    INST_tx_line.METH_write((tUInt8)0u);
  if (DEF_NOT_tx___d16)
    INST_tx.METH_write((tUInt8)1u);
}

tUInt8 MOD_mkUART::METH_RDY_start_tx()
{
  tUInt8 DEF_CAN_FIRE_start_tx;
  tUInt8 PORT_RDY_start_tx;
  DEF_tx___d1 = INST_tx.METH_read();
  DEF_NOT_tx___d16 = !DEF_tx___d1;
  DEF_CAN_FIRE_start_tx = DEF_NOT_tx___d16;
  PORT_RDY_start_tx = DEF_CAN_FIRE_start_tx;
  return PORT_RDY_start_tx;
}

tUInt8 MOD_mkUART::METH_uart_tx()
{
  tUInt8 PORT_uart_tx;
  PORT_uart_tx = INST_tx_line.METH_read();
  return PORT_uart_tx;
}

tUInt8 MOD_mkUART::METH_RDY_uart_tx()
{
  tUInt8 PORT_RDY_uart_tx;
  tUInt8 DEF_CAN_FIRE_uart_tx;
  DEF_CAN_FIRE_uart_tx = (tUInt8)1u;
  PORT_RDY_uart_tx = DEF_CAN_FIRE_uart_tx;
  return PORT_RDY_uart_tx;
}


/* Reset routines */

void MOD_mkUART::reset_RST_N(tUInt8 ARG_rst_in)
{
  PORT_RST_N = ARG_rst_in;
  INST_tx_line.reset_RST(ARG_rst_in);
  INST_tx.reset_RST(ARG_rst_in);
  INST_sbuf.reset_RST(ARG_rst_in);
  INST_parity.reset_RST(ARG_rst_in);
  INST_bit_cnt.reset_RST(ARG_rst_in);
}


/* Static handles to reset routines */


/* Functions for the parent module to register its reset fns */


/* Functions to set the elaborated clock id */

void MOD_mkUART::set_clk_0(char const *s)
{
  __clk_handle_0 = bk_get_or_define_clock(sim_hdl, s);
}


/* State dumping routine */
void MOD_mkUART::dump_state(unsigned int indent)
{
  printf("%*s%s:\n", indent, "", inst_name);
  INST_bit_cnt.dump_state(indent + 2u);
  INST_parity.dump_state(indent + 2u);
  INST_sbuf.dump_state(indent + 2u);
  INST_tx.dump_state(indent + 2u);
  INST_tx_line.dump_state(indent + 2u);
}


/* VCD dumping routines */

unsigned int MOD_mkUART::dump_VCD_defs(unsigned int levels)
{
  vcd_write_scope_start(sim_hdl, inst_name);
  vcd_num = vcd_reserve_ids(sim_hdl, 8u);
  unsigned int num = vcd_num;
  for (unsigned int clk = 0u; clk < bk_num_clocks(sim_hdl); ++clk)
    vcd_add_clock_def(sim_hdl, this, bk_clock_name(sim_hdl, clk), bk_clock_vcd_num(sim_hdl, clk));
  vcd_write_def(sim_hdl, bk_clock_vcd_num(sim_hdl, __clk_handle_0), "CLK", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "NOT_tx___d16", 1u);
  vcd_write_def(sim_hdl, num++, "RST_N", 1u);
  vcd_set_clock(sim_hdl, num, __clk_handle_0);
  vcd_write_def(sim_hdl, num++, "tx___d1", 1u);
  num = INST_bit_cnt.dump_VCD_defs(num);
  num = INST_parity.dump_VCD_defs(num);
  num = INST_sbuf.dump_VCD_defs(num);
  num = INST_tx.dump_VCD_defs(num);
  num = INST_tx_line.dump_VCD_defs(num);
  vcd_write_scope_end(sim_hdl);
  return num;
}

void MOD_mkUART::dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkUART &backing)
{
  vcd_defs(dt, backing);
  vcd_prims(dt, backing);
}

void MOD_mkUART::vcd_defs(tVCDDumpType dt, MOD_mkUART &backing)
{
  unsigned int num = vcd_num;
  if (dt == VCD_DUMP_XS)
  {
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
    vcd_write_x(sim_hdl, num++, 1u);
  }
  else
    if (dt == VCD_DUMP_CHANGES)
    {
      if ((backing.DEF_NOT_tx___d16) != DEF_NOT_tx___d16)
      {
	vcd_write_val(sim_hdl, num, DEF_NOT_tx___d16, 1u);
	backing.DEF_NOT_tx___d16 = DEF_NOT_tx___d16;
      }
      ++num;
      if ((backing.PORT_RST_N) != PORT_RST_N)
      {
	vcd_write_val(sim_hdl, num, PORT_RST_N, 1u);
	backing.PORT_RST_N = PORT_RST_N;
      }
      ++num;
      if ((backing.DEF_tx___d1) != DEF_tx___d1)
      {
	vcd_write_val(sim_hdl, num, DEF_tx___d1, 1u);
	backing.DEF_tx___d1 = DEF_tx___d1;
      }
      ++num;
    }
    else
    {
      vcd_write_val(sim_hdl, num++, DEF_NOT_tx___d16, 1u);
      backing.DEF_NOT_tx___d16 = DEF_NOT_tx___d16;
      vcd_write_val(sim_hdl, num++, PORT_RST_N, 1u);
      backing.PORT_RST_N = PORT_RST_N;
      vcd_write_val(sim_hdl, num++, DEF_tx___d1, 1u);
      backing.DEF_tx___d1 = DEF_tx___d1;
    }
}

void MOD_mkUART::vcd_prims(tVCDDumpType dt, MOD_mkUART &backing)
{
  INST_bit_cnt.dump_VCD(dt, backing.INST_bit_cnt);
  INST_parity.dump_VCD(dt, backing.INST_parity);
  INST_sbuf.dump_VCD(dt, backing.INST_sbuf);
  INST_tx.dump_VCD(dt, backing.INST_tx);
  INST_tx_line.dump_VCD(dt, backing.INST_tx_line);
}
