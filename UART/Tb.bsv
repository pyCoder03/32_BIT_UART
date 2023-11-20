package Tb;

import UART::*;

(*synthesize*)
module mkTb();
	Reg#(Bit#(1)) flag<-mkReg(0);
	UART uut<-mkUART;
	
	rule update_cnt;
		// $dumpfile("dump.vcd");
		cnt<=cnt+1;
	endrule
	
	rule transmit_uart;
		if(cnt==3)
			uut.par_in(8'hCA);	// Here it doesn't matter whether you give it as 16543 or 32'd16543
		else if(cnt==10)			// 32'd16543 <=> 32'h0000409F
			uut.start_tx;
		else if(cnt==25)
			uut.par_in(8'hAB);	// Here it doesn't matter whether you give it as 16543 or 32'd16543
		else if(cnt==30)			// 32'd16543 <=> 32'h0000409F
			uut.start_tx;
		else if(cnt==45)
			uut.par_in(8'h4B);
		else if(cnt==50)
			uut.start_tx;
		if(cnt==63)
			$finish();
	endrule
	
	//rule send_num(cnt==0);
	//	uut.transmit(16543);
	rule get_output;
		$display("Cnt: %d, Output: %d",cnt,uut.uart_tx);
	endrule
endmodule
	
endpackage	
