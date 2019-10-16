library ieee;
use ieee.std_logic_1164.all;

entity controller is
	port (
		clk : in std_logic;
		rst : in std_logic;		
		rconst : out std_logic_vector(7 downto 0);
		is_final_round : out std_logic;
		done : out std_logic
	);
end controller;

architecture behavioral of controller is
	signal reg_input : std_logic_vector(7 downto 0);
	signal reg_output : std_logic_vector(7 downto 0);
	signal feedback : std_logic_vector(7 downto 0);
begin
	reg_input <= x"01" when rst = '0' else feedback;	
	reg_inst : entity work.reg
		generic map(
			size => 8
		)
		port map(
			clk => clk,
			d   => reg_input,
			q   => reg_output
		);
	gfmult_by2_inst : entity work.gfmult_by2
		port map(
			input_byte  => reg_output,
			output_byte => feedback
		);
	is_final_round <= '1' when feedback = x"36" else '0';
	done <= '1' when feedback = x"6c" else '0';
	rconst <= reg_output;
end architecture behavioral;
