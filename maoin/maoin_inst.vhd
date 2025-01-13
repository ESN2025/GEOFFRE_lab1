	component maoin is
		port (
			btn0_i_export : in  std_logic                    := 'X'; -- export
			clk_clk       : in  std_logic                    := 'X'; -- clk
			led0_o_export : out std_logic_vector(7 downto 0);        -- export
			reset_reset_n : in  std_logic                    := 'X'  -- reset_n
		);
	end component maoin;

	u0 : component maoin
		port map (
			btn0_i_export => CONNECTED_TO_btn0_i_export, -- btn0_i.export
			clk_clk       => CONNECTED_TO_clk_clk,       --    clk.clk
			led0_o_export => CONNECTED_TO_led0_o_export, -- led0_o.export
			reset_reset_n => CONNECTED_TO_reset_reset_n  --  reset.reset_n
		);

