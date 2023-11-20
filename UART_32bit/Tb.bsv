package Tb;

import UART_32bit::*;

(*synthesize*)
module mkTb();
	Reg#(Bit#(8)) cnt<-mkReg(0);
	UART_32bit uut<-mkUART_32bit;
	
	rule update_cnt;
		// $dumpfile("dump.vcd");
		cnt<=cnt+1;
	endrule
	
	rule transmit_uart;
		if(cnt==3)
			uut.par_in(32'hABCDBCDA);	// Here it doesn't matter whether you give it as 16543 or 32'd16543
		else if(cnt==10)			// 32'd16543 <=> 32'h0000409F
			uut.start_tx;
		else if(cnt==50)
			uut.par_in(32'h1234DCBA);	// Here it doesn't matter whether you give it as 16543 or 32'd16543
		else if(cnt==60)			// 32'd16543 <=> 32'h0000409F
			uut.start_tx;
		else if(cnt==150)
			uut.par_in(32'h5148218);
		else if(cnt==200)
			uut.start_tx;
		if(cnt==250)
			$finish();
	endrule
	
	//rule send_num(cnt==0);
	//	uut.transmit(16543);
	rule get_output;
		$display("Cnt: %d, Output: %d",cnt,uut.uart32bit_tx);
	endrule
endmodule
	
endpackage	
