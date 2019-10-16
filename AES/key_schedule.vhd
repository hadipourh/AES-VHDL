library ieee;
use ieee.std_logic_1164.all;

entity key_schedule is
	port (
		clk : in std_logic;
		rst : in std_logic;
		key : in std_logic_vector(127 downto 0);
		round_const : in std_logic_vector(7 downto 0);
		round_key : out std_logic_vector(127 downto 0)
	);
end key_schedule;

architecture behavioral of key_schedule is
	signal feedback : std_logic_vector(127 downto 0);
	signal reg_input : std_logic_vector(127 downto 0);
	signal reg_output : std_logic_vector(127 downto 0);
begin
	reg_input <= key when rst = '0' else feedback;
	reg_inst : entity work.reg
		generic map(
			size => 128
		)
		port map(
			clk => clk,
			d   => reg_input,
			q   => reg_output
		);	
	key_sch_round_function_inst : entity work.key_sch_round_function
		port map(
			subkey      => reg_output,
			round_const => round_const,
			next_subkey => feedback
		);
	round_key <= feedback;
end architecture behavioral;
