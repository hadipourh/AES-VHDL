-- VHDL implementation of AES
-- Copyright (C) 2019  Hosein Hadipour

-- This program is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.

-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.

-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.

library ieee;
use ieee.std_logic_1164.all;

entity reg is
	generic (size : positive);
	port (
		clk : in std_logic;
		d : in std_logic_vector(size - 1 downto 0);
		q : out std_logic_vector(size - 1 downto 0)
	);
end reg;

architecture behavioral of reg is
	signal reg_data : std_logic_vector(Size -1 downto 0);
begin
	-- output interface
	q <= reg_data;
	--*** seq proc ***--
	flop_data : process(clk) is		
	begin
		if (rising_edge(clk) then
			reg_data <= d;
	    end if;
	end process flop_data;
end architecture behavioral;


