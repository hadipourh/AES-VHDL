library ieee;
use ieee.std_logic_1164.all;

entity aes_enc is 
	port (
		clk : in std_logic;
		rst : in std_logic;
		key : in std_logic_vector(127 downto 0);
		plaintext : in std_logic_vector(127 downto 0);
		ciphertext : out std_logic_vector(127 downto 0);
		done : out std_logic		
	);
end aes_enc;

architecture behavioral of aes_enc is
	signal reg_input : std_logic_vector(127 downto 0);
	signal reg_output : std_logic_vector(127 downto 0);
	signal subbox_input : std_logic_vector(127 downto 0);
	signal subbox_output : std_logic_vector(127 downto 0);
	signal shiftrows_output : std_logic_vector(127 downto 0);
	signal mixcol_output : std_logic_vector(127 downto 0);
	signal feedback : std_logic_vector(127 downto 0);
	signal round_key : std_logic_vector(127 downto 0);
	signal round_const : std_logic_vector(7 downto 0);	
	signal sel : std_logic;	 
begin
	-- Encryption body
	reg_input <= plaintext when rst = '0' else feedback;
	reg_inst : entity work.reg
		generic map(
			size => 128
		)
		port map(
			clk => clk,
			d   => reg_input,
			q   => reg_output
		);
	add_round_key_inst : entity work.add_round_key
		port map(
			input1 => reg_output,
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
	feedback <= mixcol_output when sel = '0' else shiftrows_output;
	-- Controller
	controller_inst : entity work.controller
		port map(
			clk            => clk,
			rst            => rst,
			rconst         => round_const,
			is_final_round => sel,
			done           => done
		);
	-- Keyschedule
	key_schedule_inst : entity work.key_schedule
		port map(
			clk         => clk,
			rst         => rst,
			key         => key,
			round_const => round_const,
			round_key   => round_key
		);
	ciphertext <= subbox_input;	
end architecture behavioral;
