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
architecture Behavioral of exp5_q1 is
    component SOMADOR is
        port (
            A : in std_logic;
            B : in std_logic;
            Cin : in std_logic;
            S : out std_logic;
            Cout : out std_logic
        );
    end component;
signal carryaux : in std_logic_vector(2 downto 0) :="000";
begin
    soma0: somador port map (a=>a(0), b=>b(0), Cin=>'0', s=>s(0), cout=>carryaux(0));
    soma1: somador port map (a=>a(1), b=>b(1), Cin=>carryaux(0), s=>s(1), cout=>carryaux(1));
    soma2: somador port map (a=>a(2), b=>b(2), Cin=>carryaux(1), s=>s(2), cout=>carryaux(1));
    soma3: somador port map (a=>a(3), b=>b(3), Cin=>carryaux(2), s=>s(3), cout=>s(4));
    end Behavioral;


