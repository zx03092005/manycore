#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <systemc>
using namespace sc_core;

#include "Testbench.h"
#ifndef NATIVE_SYSTEMC
#include "SobelFilter_wrap.h"
#include "SobelFilter2_wrap.h"
#else
#include "SobelFilter.h"
#include "SobelFilter2.h"
#endif

class System: public sc_module
{
public:
	SC_HAS_PROCESS( System );
	System( sc_module_name n, std::string input_bmp, std::string output_bmp );
	~System();
private:
  Testbench tb;
#ifndef NATIVE_SYSTEMC
	SobelFilter_wrapper sobel_filter;
	SobelFilter2_wrapper sobel_filter2;
#else
	SobelFilter sobel_filter;
	SobelFilter2 sobel_filter2;
#endif
	sc_clock clk;
	sc_signal<bool> rst;

#ifndef NATIVE_SYSTEMC
	cynw_p2p< sc_dt::sc_uint<24> > rgb;
	cynw_p2p< sc_dt::sc_uint<32> > result;
	cynw_p2p< sc_dt::sc_uint<24> > rgb2;
	cynw_p2p< sc_dt::sc_uint<32> > result2;
#else
	sc_fifo< sc_dt::sc_uint<24> > rgb;
	sc_fifo< sc_dt::sc_uint<32> > result;
	sc_fifo< sc_dt::sc_uint<24> > rgb2;
	sc_fifo< sc_dt::sc_uint<32> > result2;
#endif

	std::string _output_bmp;
};
#endif
