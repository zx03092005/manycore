#include "System.h"
System::System( sc_module_name n, string input_bmp, string output_bmp ): sc_module( n ), 
	tb("tb"), sobel_filter("sobel_filter"), sobel_filter2("sobel_filter2"), clk("clk", CLOCK_PERIOD, SC_NS), rst("rst"), _output_bmp(output_bmp)
{
	tb.i_clk(clk);
	tb.o_rst(rst);
	sobel_filter.i_clk(clk);
	sobel_filter.i_rst(rst);
	sobel_filter2.i_clk(clk);
	sobel_filter2.i_rst(rst);

	tb.o_rgb(rgb);
	tb.i_result(result);
	sobel_filter.i_rgb(rgb);
	sobel_filter.o_result(result);
	
	tb.o_rgb2(rgb2);	
	tb.i_result2(result2);
	sobel_filter2.i_rgb(rgb2);
	sobel_filter2.o_result(result2);
  tb.read_bmp(input_bmp);
}

System::~System() {
  tb.write_bmp(_output_bmp);
}
