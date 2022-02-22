
module our( input _y, input _a, output _x );
    NAND_2_gate_level _nand( _x, _y, _a );
    always begin
        if( _x == 0 )
            $finish;
    end
endmodule

/* verilator lint_off DECLFILENAME */
module NAND_2_gate_level(output Y, input A, B);
    wire Yd;
    and(Yd, A, B);
    not(Y, Yd);
endmodule
