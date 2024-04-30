-- Universidade de Brasília
-- Laboratório de Sistemas Digitais
-- Autor : Bernardo Gomes Rodrigues
-- Data : 25/04/2024

-- Implementação de um Somador Completo com 3 bits de entrada e 2 de saída

-- ****************************************** 
--  Circuito: Somador de 3 entradas: 
--                A Entrada 1
--                B Entrada 2
--                Cin Entrada 3
--                S Saida 1
--                Cout  Saida2
-- ******************************************

library IEEE;
use IEEE.std_logic_1164.all;
entity SOMADOR is port (
        A      :in std_logic; 
        B      :in std_logic; 
        Cin    :in std_logic; 
        s      :out std_logic; 
        COUT   :out std_logic 
    );
end SOMADOR;
architecture Behavioral of SOMADOR is
begin
S <= A xor B xor Cin;
Cout <= (A and B) or (A and Cin) or (B and Cin);
end Behavioral;