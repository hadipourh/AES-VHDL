library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity controller is
	port (
		clk : in std_logic;
		rst : in std_logic;
		rconst : out std_logic_vector(7 downto 0);
		is_first_round : out std_logic;
		done : out std_logic
	);
end controller;

architecture behavioral of controller is	
	constant rcon_table : std_logic_vector(87 downto 0) := x"0001020408102040801b36";
	signal round_constant : std_logic_vector(7 downto 0);
begin
	counter : process(clk) is
		variable i : integer range 0 to (2**4) - 1 := 0;
	begin
		if rising_edge(clk) then 
			if (rst = '0') then
				i := 0;
			else
				i := i + 1;
			end if;
		end if;
		round_constant <= rcon_table((i + 1)*8  - 1 downto 8*i);
	end process counter;
	rconst <= round_constant;
	done <= '1' when round_constant = x"00" else '0';
	is_first_round <= '1' when round_constant = x"36" else '0';
end architecture behavioral;
