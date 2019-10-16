library ieee;
use ieee.std_logic_1164.all;

entity column_calculator is
	port (
		input_data : in std_logic_vector(31 downto 0);
		output_data : out std_logic_vector(31 downto 0)
	);
end column_calculator;

architecture rtl of column_calculator is
	signal temp0 : std_logic_vector(31 downto 0);
	signal temp1 : std_logic_vector(31 downto 0);
	signal temp2 : std_logic_vector(31 downto 0);
	signal temp3 : std_logic_vector(31 downto 0);	
begin
	-- temp0 calculations
	gfmult_by2_inst0 : entity work.gfmult_by2
		port map(
			input_byte  => input_data(7 downto 0),
			output_byte => temp0(7 downto 0)
		);
	temp0(15 downto 8) <= input_data(7 downto 0);
	temp0(23 downto 16) <= 	input_data(7 downto 0);
	gfmult_by3_inst0 : entity work.gfmult_by3
		port map(
			input_byte  => input_data(7 downto 0),
			output_byte => temp0(31 downto 24)
		);
		
	-- temp1 calculations
	gfmult_by3_inst1 : entity work.gfmult_by3
		port map(
			input_byte  => input_data(15 downto 8),
			output_byte => temp1(7 downto 0)
		);
	gfmult_by2_inst1 : entity work.gfmult_by2
		port map(
			input_byte  => input_data(15 downto 8),
			output_byte => temp1(15 downto 8)
		);
	temp1(23 downto 16) <= input_data(15 downto 8);
	temp1(31 downto 24) <= input_data(15 downto 8);
	
	-- temp2 calculations
	temp2(7 downto 0) <= input_data(23 downto 16);
	gfmult_by3_inst2 : entity work.gfmult_by3
		port map(
			input_byte  => input_data(23 downto 16),
			output_byte => temp2(15 downto 8)
		);
	gfmult_by2_inst2 : entity work.gfmult_by2
		port map(
			input_byte  => input_data(23 downto 16),
			output_byte => temp2(23 downto 16)
		);
	temp2(31 downto 24) <= input_data(23 downto 16);
	
	-- temp3 calculations
	temp3(7 downto 0) <= input_data(31 downto 24);
	temp3(15 downto 8) <= input_data(31 downto 24);
	gfmult_by3_inst : entity work.gfmult_by3
		port map(
			input_byte  => input_data(31 downto 24),
			output_byte => temp3(23 downto 16)
		);
	gfmult_by2_inst : entity work.gfmult_by2
		port map(
			input_byte  => input_data(31 downto 24),
			output_byte => temp3(31 downto 24)
		);
	xor4_inst : entity work.xor4
		generic map(
			size => 32
		)
		port map(
			input1 => temp0,
			input2 => temp1,
			input3 => temp2,
			input4 => temp3,
			output => output_data
		);	
	
end architecture rtl;
