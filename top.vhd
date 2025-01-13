library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity top is
    Port (
        CLK_50M : in STD_LOGIC;
		  led_o : out STD_LOGIC_VECTOR(7 downto 0);
		  btn_a : in  std_logic;
		  btn_rst : in  std_logic;
		  sw_i : in std_logic_vector(3 downto 0)
		  );
end top;

architecture Archon of top is
    component maoin is
        port (
            btn0_i_export : in  std_logic                    := '0';
            clk_clk       : in  std_logic                    := 'X';
            led0_o_export : out std_logic_vector(7 downto 0);
            reset_reset_n : in  std_logic                    := '0'
        );
    end component maoin;

begin
    u0 : component maoin port map (not btn_a, CLK_50M, led_o, btn_rst);
end Archon;