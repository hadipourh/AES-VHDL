
-- VHDL Instantiation Created from source file mix_columns.vhd -- 21:54:53 10/16/2019
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT mix_columns
	PORT(
		input_data : IN std_logic_vector(127 downto 0);          
		output_data : OUT std_logic_vector(127 downto 0)
		);
	END COMPONENT;

	Inst_mix_columns: mix_columns PORT MAP(
		input_data => ,
		output_data => 
	);


