library ieee;
use ieee.std_logic_1164.all;

entity test_enc is 
end test_enc;

architecture behavior of test_enc is
	component aes_enc
		port(
			clk        : in  std_logic;
			rst        : in  std_logic;
			key        : in  std_logic_vector(127 downto 0);
			plaintext  : in  std_logic_vector(127 downto 0);
			ciphertext : out std_logic_vector(127 downto 0);
			done       : out std_logic
		);		
	end component aes_enc;
	component controller
		port(
			clk            : in  std_logic;
			rst            : in  std_logic;
			rconst         : out std_logic_vector(7 downto 0);
			is_final_round : out std_logic;
			done           : out std_logic
		);
	end component controller;	
	-- Input signals
	signal clk : std_logic := '0';
	signal rst : std_logic := '0';
	signal plaintext : std_logic_vector(127 downto 0);
	signal key : std_logic_vector(127 downto 0);	
	
	-- Output signals
	signal done : std_logic;
	signal ciphertext : std_logic_vector(127 downto 0);
	signal rconst : std_logic_vector(7 downto 0);
	signal is_final_round : std_logic;	
	
	-- Clock period definition
	constant clk_period : time := 10 ns;
	
begin
	enc_inst : aes_enc
		port map(
			clk        => clk,
			rst        => rst,
			key        => key,
			plaintext  => plaintext,
			ciphertext => ciphertext,
			done       => done
		);
	controller_inst : component controller
		port map(
			clk            => clk,
			rst            => rst,
			rconst         => rconst,
			is_final_round => is_final_round,
			done           => done
		);
	-- clock process definitions
	clk_process : process is
	begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
	end process clk_process;
	
	-- Simulation process
	sim_proc : process is
	begin
		-- Some test vectors taken from pages 215, and 216 of the main AES specification		
		--p = 3243f6a8885a308d313198a2e0370734
		--k = 2b7e151628aed2a6abf7158809cf4f3c		
		--c = 3925841d02dc09fbdc118597196a0b32
		-- Initialize Inputs
		plaintext <= x"340737e0a29831318d305a88a8f64332";
		key <= x"3c4fcf098815f7aba6d2ae2816157e2b";
		rst <= '0';
		-- Hold reset state for 16 ns		
		wait for 30 ns;
		rst <= '1';
		wait until done = '1';
		wait for clk_period/2;			
		if (ciphertext = x"320b6a19978511dcfb09dc021d842539") then
			report "---------- Passed ----------";
		else
			report "---------- Failed ----------";
		end if;
		report "---------- Output must be: -------";
		report "320b6a19978511dcfb09dc021d842539";		
		--------------------------------------------
		-- Initialize Inputs
		--p = 00000000000000000000000000000000
		--k = 00000000000000000000000000000000
		--c = 66E94BD4EF8A2C3B884CFA59CA342B2E		
		plaintext <= x"00000000000000000000000000000000";
		key <= x"00000000000000000000000000000000";
		rst <= '0';
		-- Hold reset state for 16 ns		
		wait for 30 ns;
		rst <= '1';
		wait until done = '1';
		wait for clk_period/2;			
		if (ciphertext = x"2e2b34ca59fa4c883b2c8aefd44be966") then
			report "---------- Passed ----------";
		else
			report "---------- Failed ----------";
		end if;
		report "---------- Output must be: -------";
		report "2e2b34ca59fa4c883b2c8aefd44be966";
		wait;
	end process sim_proc;
	
end architecture behavior;

