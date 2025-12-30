with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Long_Long_Integer_Text_IO; use Ada.Long_Long_Integer_Text_IO;
with Ada.Unchecked_Deallocation;
with Ada.Command_Line; use Ada.Command_Line;

procedure Main is
    type Primes_Array is array (Integer range <>) of Long_Long_Integer;

    type Primes_Array_Access is access Primes_Array;

    procedure Free is
        new Ada.Unchecked_Deallocation(Primes_Array, Primes_Array_Access);

    function Nth_Prime(N: Integer) return Long_Long_Integer is
        Primes: Primes_Array_Access;
        I : Long_Long_Integer;
        J, Count, Flag : Integer;
    begin

        if N <= 0 then
            Put_Line("Wrong arguments, n has to be greater than 0");
            return -1;
        end if;

        if N = 1 then
            return 2;
        end if;


        Primes := new Primes_Array(1 .. N);

        Count := 1;
        Primes(1) := 2;

        I := 3;
        Flag := 1;

        while True loop
            Flag := 1;
            J := 0;

            for J in 1 .. Count loop
                if I mod Primes(J) = 0 then
                    Flag := 0;
                    exit;
                end if;
            end loop;

            if Flag = 1 then

                Count := Count + 1;
                Primes(Count) := I;
            end if;

            if Count = N then
                   Free(Primes);
                   return I;
            end if;

            I := I + 2;

        end loop;
    end Nth_Prime;


    N: Integer;

begin
     N := Integer'Value(Argument(1));

     Put(Long_Long_Integer'Image(Nth_Prime(N)));
     New_Line;
end Main;