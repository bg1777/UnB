-- Universidade de Brasília
-- Laboratório de Sistemas Digitais
-- Autor : Bernardo Gomes Rodrigues 
-- Matrícula: 231034190
-- Data : 25/04/2024

-- Implementação de um somador de palavras de 4 bits utilizando somadores completos

-- ****************************************** 
--  Circuito: Somador de palavras de 4 bits:
--                A Entrada 1
--                B Entrada 2
--                S Saida
-- ******************************************

library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity exp5_q1 is

    port (
        A : in std_logic_vector(3 downto 0);
        B : in std_logic_vector(3 downto 0);
        S : out std_logic_vector(4 downto 0)
    );

end exp5_q1;

architecture Behavioral of exp5-q1 is

    component SOMADOR is

        port (
            A : in std_logic;
            B : in std_logic;
            Cin : in std_logic;
            S : out std_logic;
            Cout : out std_logic
        );
    end component;

signal carry : in std_logic_vector(4 downto 0);

begin

    carry(0) <= '0';

    for i in 0 to 3 generate
        u0 : SOMADOR port map (A(i), B(i), carry(i), S(i), carry(i+1));
    end generate;

    S(4) <= carry(4);

    end Behavioral;


