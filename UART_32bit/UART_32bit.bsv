package UART_32bit;

interface UART_32bit;
	method Action par_in(Int#(32) par_input);
	method Action start_tx;
	(*always_ready,always_enabled*) method Bit#(1) uart32bit_tx;
endinterface

(*synthesize*)
module mkUART_32bit(UART_32bit);
	Reg#(Int#(32)) num_reg<-mkReg(0);
	
	Reg#(Bit#(2)) s_cnt<-mkReg(3);
	Reg#(Bit#(4)) bit_cnt<-mkReg(0);
	
	Reg#(Bit#(8)) sbuf<-mkReg(8'hFF);
	Reg#(Bit#(1)) parity<-mkReg(0);
	Reg#(Bit#(1)) tx_line<-mkReg(1);	// By default mark state
	Reg#(Bit#(1)) tx<-mkReg(0);		// FLag to indicate an ongoing transmission
	Wire#(Bit#(1)) tx_frag<-mkDWire(0);	// Flag to indicate the start of transmission of an 8-bit fragment
	
	Wire#(Bit#(8)) sbuf_din<-mkDWire(0);	// DWire for floating the 8-bit fragment at the start
	
	// (*fire_when_enabled*)
	rule tx_8bit(tx_frag==1);
		if(s_cnt==3)
			sbuf_din<=pack(num_reg)[7:0];	// pack(num_reg[7:0]) won't work here.. First convert this Int#(32) into Bit#(32) and then perform slicing
		else if(s_cnt==0)
			sbuf_din<=pack(num_reg)[15:8];
		else if(s_cnt==1)
			sbuf_din<=pack(num_reg)[23:16];
		else
			sbuf_din<=pack(num_reg)[31:24];
	endrule
	
	(*fire_when_enabled*)
	rule update_sbuf(tx_frag==1);
		sbuf<=sbuf_din;
		parity<=(sbuf_din[7]^sbuf_din[6]^sbuf_din[5]^sbuf_din[4]^sbuf_din[3]^sbuf_din[2]^sbuf_din[1]^sbuf_din[0]);
	endrule
	
	(*fire_when_enabled*)
	rule update_cnt(tx==1);
		if(bit_cnt==9)
			s_cnt<=s_cnt+1;
		if(bit_cnt!=10)	
			bit_cnt<=bit_cnt+1;
		else begin
			if(s_cnt==3)
				tx<=0;
			bit_cnt<=0;
			// if(bit_cnt==8)
			//	tx_frag<=1;
		end
	endrule
	
	(*fire_when_enabled*)
	rule shift_out(tx==1);			// t
		if(bit_cnt==8)
			tx_line<=parity;
		else if(bit_cnt==9) begin
			tx_line<=1;	// Stop bit for the current fragment
			// tx<=0;
		end
		else if(bit_cnt==10) begin	// If the condition is (bit_cnt==10 && s_cnt!=3) then the else condition next will be executed after the last fragment has been transmitted
			if(s_cnt!=3) begin	
				tx_line<=0;	// Start bit for next fragment
				tx_frag<=1;
			end
		end
		else begin
			// {sbuf,tx_line}<={1'b0,sbuf};
			sbuf<=extend(sbuf[7:1]);
			tx_line<=sbuf[0];
		end
	endrule
	// function Action transmit_8bit(Int#(8) n);
	//	return(
	//		action
			
				
				
	method Action start_tx if(tx==0);
		action
			// if(tx==0 && tx_frag==0) begin
				tx<=1;
				tx_frag<=1;
				tx_line<=0;		// Start bit for first fragment
			// end
		endaction
	endmethod
	
	method Action par_in(Int#(32) par_input) if(tx==0);	// RDY signals are getting generated, but don't seem to be used anywhere to control actions when RDY is not actually HIGH
		action
			// if(tx==0 && tx_frag==0)
				num_reg<=par_input;
		endaction
	endmethod
	
	method Bit#(1) uart32bit_tx;
		return tx_line;
	endmethod
endmodule

endpackage	
