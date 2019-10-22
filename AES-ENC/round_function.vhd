library ieee;
use ieee.std_logic_1164.all;

entity round_function is
	port (
		input_state : in std_logic_vector(127 downto 0);
		round_key : in std_logic_vector(127 downto 0);
		sel : in std_logic;
		output_state : out std_logic_vector(127 downto 0)		
	);
end round_function;

architecture rtl of round_function is
	signal subbox_input : std_logic_vector(127 downto 0);
	signal subbox_output : std_logic_vector(127 downto 0);
	signal shiftrows_output : std_logic_vector(127 downto 0);
	signal mixcol_output : std_logic_vector(127 downto 0);		
begin
	add_round_key_inst : entity work.add_round_key
		port map(
			input1 => input_state,
			input2 => round_key,
			output => subbox_input
		);
	sub_byte_inst : entity work.sub_byte
		port map(
			input_data  => subbox_input,
			output_data => subbox_output
			
		);
	shift_rows_inst : entity work.shift_rows
		port map(
			input  => subbox_output,
			output => shiftrows_output
		);

	mix_columns_inst : entity work.mix_columns
		port map(
			input_data  => shiftrows_output,
			output_data => mixcol_output
		);
	output_state <= mixcol_output when sel = '0' else shiftrows_output;	
end architecture rtl;
