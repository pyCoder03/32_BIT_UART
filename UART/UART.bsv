package UART;

interface UART;
	method Action par_in(Bit#(8) par_input);
	method Action start_tx;
	(*always_ready,always_enabled*) method Bit#(1) uart_tx;
endinterface

(*synthesize*)
module mkUART(UART);
	Reg#(Bit#(4)) bit_cnt<-mkReg(0);	// bit_cnt is 4 bits wide as there are 8 data bits + parity + stop bit to be generated
	
	Reg#(Bit#(8)) sbuf<-mkReg(8'hFF);
	Reg#(Bit#(1)) parity<-mkReg(0);
	Reg#(Bit#(1)) tx_line<-mkReg(1);	// By default mark state
	Reg#(Bit#(1)) tx<-mkReg(0);		// FLag to indicate an ongoing transmission
	
	(*fire_when_enabled*)
	rule shift_out(tx==1);			// t
		if(bit_cnt!=9)
			bit_cnt<=bit_cnt+1;
		if(bit_cnt==8)
			tx_line<=parity;
		else if(bit_cnt==9) begin
			tx_line<=1;
			tx<=0;
			bit_cnt<=0;
		end
		else begin
			// {sbuf,tx_line}<={1'b0,sbuf};
			sbuf<=extend(sbuf[7:1]);
			tx_line<=sbuf[0];
		end
	endrule
	
	method Action par_in(Bit#(8) par_input)	if(tx==0);	// Setting the implicit conditions posed some problems, have to study about them
		action
			if(tx==0) begin		
				sbuf<=par_input;
				parity<=(par_input[7]^par_input[6]^par_input[5]^par_input[4]^par_input[3]^par_input[2]^par_input[1]^par_input[0]);
			end
		endaction
	endmethod
	
	method Action start_tx if(tx==0);
		action
			if(tx==0) begin		
				tx_line<=0;			// Start bit
				tx<=1;
			end
		endaction
	endmethod
	
	method Bit#(1) uart_tx;
		return tx_line;
	endmethod
endmodule

endpackage
	
	
